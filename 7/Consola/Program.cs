using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Calculadora1;
namespace Consola
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Class1 evaluador = new Class1();
            string entrada;

            Console.WriteLine("Bienvenido a la Calculadora de Expresiones");
            Console.WriteLine("Seleccione el tipo de expresión: ");
            Console.WriteLine("1. Infix (normal)");
            Console.WriteLine("2. Prefix (prefija)");
            Console.WriteLine("Escriba 'exit' para salir.");

            while (true)
            {
                entrada = Console.ReadLine();
                if (entrada.ToLower() == "exit")
                    break;

                int tipoExpresion;
                if (!int.TryParse(entrada, out tipoExpresion) || (tipoExpresion != 1 && tipoExpresion != 2))
                {
                    Console.WriteLine("Seleccione 1 o 2 para el tipo de expresión.");
                    continue;
                }

                Console.WriteLine("Ingrese la expresión:");
                string expresion = Console.ReadLine();

                try
                {
                    double resultado = tipoExpresion == 1 ? evaluador.EvaluarInfix(expresion) : evaluador.EvaluarPrefix(expresion);
                    Console.WriteLine($"Resultado: {resultado}");
                }
                catch (ArgumentException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (Exception e)
                {
                    Console.WriteLine("Error al evaluar la expresión: " + e.Message);
                }
            }
        }
    }
}

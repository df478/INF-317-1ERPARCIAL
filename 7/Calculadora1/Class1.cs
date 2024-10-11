using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;

namespace Calculadora1
{
    public class Class1
    {
        public double EvaluarInfix(string expresion)
        {
            try
            {
                return Convert.ToDouble(new System.Data.DataTable().Compute(expresion, null));
            }
            catch (Exception ex)
            {
                throw new ArgumentException("Expresión no válida.", ex);
            }
        }

        public double EvaluarPrefix(string expresion)
        {
            var tokens = expresion.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            Stack<double> stack = new Stack<double>();

            for (int i = tokens.Length - 1; i >= 0; i--)
            {
                string token = tokens[i];

                if (double.TryParse(token, out double number))
                {
                    stack.Push(number);
                }
                else
                {
                    double operand1 = stack.Pop();
                    double operand2 = stack.Pop();
                    double resultado = AplicarOperador(token, operand1, operand2);
                    stack.Push(resultado);
                }
            }

            return stack.Pop();
        }

        private double AplicarOperador(string operador, double operand1, double operand2)
        {
            switch (operador)
            {
                case "+":
                    return operand1 + operand2;
                case "-":
                    return operand1 - operand2;
                case "*":
                    return operand1 * operand2;
                case "/":
                    if (operand2 == 0) throw new DivideByZeroException();
                    return operand1 / operand2;
                default:
                    throw new ArgumentException("Operador no válido.");
            }
        }
    }
}

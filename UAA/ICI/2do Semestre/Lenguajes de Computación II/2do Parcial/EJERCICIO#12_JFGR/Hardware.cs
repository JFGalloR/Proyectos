using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EJERCICIO_JFGR
{
    internal class Hardware
    {
        public static void CenterText(string texto)
        {
            int posicionCentrada = (Console.WindowWidth - texto.Length) / 2;

            Console.SetCursorPosition(posicionCentrada, Console.CursorTop);
            Console.WriteLine(texto);
        }
        public void centerText(string texto)
        {
            int posicionCentrada = (Console.WindowWidth - texto.Length) / 2;

            Console.SetCursorPosition(posicionCentrada, Console.CursorTop);
            Console.WriteLine(texto);
        }
    }
}

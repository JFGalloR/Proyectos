using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Banco
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int opt, aux;
            Client[] client = new Client [3];
           
            for(int i = 0; i < client.Length; i++)
            {
                client[i] = new Client();
            }
            client[0].Name = "mi tio";
            client[1].Name = "Cliente 2";
            client[2].Name = "Cliente 3";
            do
            {
                Console.Clear ();
                Console.WriteLine("==================== BANCO ====================\n");
                Console.WriteLine("\t1. Ingresar a cuenta.");
                Console.WriteLine("\t2. Retirar de cuenta.");
                Console.WriteLine("\t3. <- Salir.\n");
                Console.WriteLine("===============================================\n");
                Console.Write(" > Ingresa una opción: ");
                opt = Convert.ToInt16(Console.ReadLine());
                switch (opt)
                {
                    case 1:
                        aux = index(client);
                        client[aux].ingresar();
                        break;
                    case 2:
                        aux = index(client);
                        client[aux].retirar();
                        break;
                    case 3:
                        Console.WriteLine("\n + + + EJECUCIÓN FINALIZADA + + + ");
                        break;
                    default:
                        Console.WriteLine("putp");
                        break;
                }
            } while (opt != 3);
        }
        static int index(Client[] client)
        {
            int idx=0;
            bool error = false;          
            string aux;

            do
            {
                error = false;
                Console.Clear();
                Console.WriteLine("==================== BANCO ====================\n");
                Console.Write(" > Ingresa el cliente: ");
                aux = Console.ReadLine();
                if (aux == client[0].Name)
                {
                    idx = 0;
                }
                else
                if (aux == client[1].Name)
                {
                    idx = 1;
                }
                else
                if (aux == client[2].Name)
                {
                    idx = 2;
                }
                else
                {
                    Console.WriteLine("\n- - - USUARIO NO EXISTENTE - - -\n");
                    error= true;
                    Console.ReadKey();
                }
            } while (error);
            Console.WriteLine("\n- - - INGRESANDO A USUARIO - - -\n");
            return idx;
        }
    }
}

// EJERCICIO #1 CON ARCHIVOS TXT
// I.C.I. UAA
// 23 de Mayo de 2023
//  - Luis Pablo Esparza Terrones
//  - Luis Manuel Flores Jiménesz
//  - Adrián de Jesús Frausto Pérez
//  - Juan Francisco Gallo Ramírez

using System;
using System.IO;

class Program
{
    static string filePath = "vehiculos.txt"; // Ruta del archivo de texto donde se guardarán los datos

    static void Main()
    {
        Console.Title = "Sistema de Registro de Vehículos";

        // Colores de título
        Console.ForegroundColor = ConsoleColor.Yellow;
        Console.WriteLine("===========================================");
        Console.WriteLine("      SISTEMA DE REGISTRO DE VEHÍCULOS     ");
        Console.WriteLine("===========================================");
        Console.ResetColor();

        while (true)
        {
            MostrarMenu(); // Mostrar el menú principal

            Console.WriteLine("\nSeleccione una opción:");
            string? opcion = Console.ReadLine();

            switch (opcion)
            {
                case "1":
                    LimpiarPantalla();
                    AgregarDatos(); // Opción para agregar datos
                    break;
                case "2":
                    LimpiarPantalla();
                    BorrarDatos(); // Opción para borrar datos
                    break;
                case "3":
                    LimpiarPantalla();
                    CambiarDatos(); // Opción para cambiar datos
                    break;
                case "4":
                    LimpiarPantalla();
                    ConsultarDatos(); // Opción para consultar datos
                    break;
                case "5":
                    return;
                default:
                    LimpiarPantalla();
                    Console.WriteLine("Opción no válida");
                    break;
            }

            Console.WriteLine();
            Console.WriteLine("Presione cualquier tecla para volver al menú principal...");
            Console.ReadKey();
            LimpiarPantalla();
        }
    }

    // Método para mostrar el menú principal
    static void MostrarMenu()
    {
        // Colores del menú principal
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine("===========================================");
        Console.WriteLine("               MENÚ PRINCIPAL             ");
        Console.WriteLine("===========================================");
        Console.ResetColor();

        // Opciones del menú principal
        Console.WriteLine("   1. Agregar datos");
        Console.WriteLine("   2. Borrar datos");
        Console.WriteLine("   3. Cambiar datos");
        Console.WriteLine("   4. Consultar datos");
        Console.WriteLine("   5. Salir");
    }

    // Método para limpiar la pantalla y mostrar el título
    static void LimpiarPantalla()
    {
        Console.Clear();
        Console.Title = "Sistema de Registro de Vehículos";

        // Colores del título
        Console.ForegroundColor = ConsoleColor.Yellow;
        Console.WriteLine("===========================================");
        Console.WriteLine("      SISTEMA DE REGISTRO DE VEHÍCULOS     ");
        Console.WriteLine("===========================================");
        Console.ResetColor();
    }

    // Método para agregar datos de un vehículo
    static void AgregarDatos()
    {
        Console.WriteLine("Ingrese los datos del vehículo:");
        Console.WriteLine("Marca:");
        string? marca = Console.ReadLine();

        Console.WriteLine("Modelo:");
        string? modelo = Console.ReadLine();

        Console.WriteLine("Placa:");
        string? placa = Console.ReadLine();

        // Validación de datos de entrada
        if (string.IsNullOrWhiteSpace(marca) || string.IsNullOrWhiteSpace(modelo) || string.IsNullOrWhiteSpace(placa))
        {
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error: Debe ingresar todos los datos del vehículo.");
            Console.ResetColor();
            return;
        }

        try
        {
            using (StreamWriter writer = new StreamWriter(filePath, true))
            {
                writer.WriteLine($"Marca: {marca}, Modelo: {modelo}, Placa: {placa}");
            }

            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Datos agregados correctamente.");
            Console.ResetColor();
        }
        catch (IOException ex)
        {
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error al agregar datos: " + ex.Message);
            Console.ResetColor();
        }
    }

    // Método para borrar datos de un vehículo
    static void BorrarDatos()
    {
        Console.WriteLine("Ingrese la placa del vehículo a borrar:");
        string? placa = Console.ReadLine();

        // Validación de la placa
        if (string.IsNullOrWhiteSpace(placa))
        {
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error: Debe ingresar la placa del vehículo a borrar.");
            Console.ResetColor();
            return;
        }

        string[]? lines = null;
        try
        {
            lines = File.ReadAllLines(filePath);

            bool datosBorrados = false;
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                foreach (string line in lines)
                {
                    if (!line.Contains($"Placa: {placa}"))
                    {
                        writer.WriteLine(line);
                    }
                    else
                    {
                        datosBorrados = true;
                    }
                }
            }

            if (datosBorrados)
            {
                Console.WriteLine();
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Datos borrados correctamente.");
                Console.ResetColor();
            }
            else
            {
                Console.WriteLine();
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("No se encontraron datos con la placa especificada.");
                Console.ResetColor();
            }
        }
        catch (IOException ex)
        {
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error al borrar datos: " + ex.Message);
            Console.ResetColor();
        }
        finally
        {
            if (lines != null)
            {
                Array.Clear(lines, 0, lines.Length);
            }
        }
    }

    // Método para cambiar datos de un vehículo
    static void CambiarDatos()
    {
        Console.WriteLine("Ingrese la placa del vehículo a cambiar:");
        string? placa = Console.ReadLine();

        Console.WriteLine("Ingrese los nuevos datos del vehículo:");
        Console.WriteLine("Marca:");
        string? marca = Console.ReadLine();

        Console.WriteLine("Modelo:");
        string? modelo = Console.ReadLine();

        Console.WriteLine("Placa:");
        string? nuevaPlaca = Console.ReadLine();

        // Validación de los datos de entrada
        if (string.IsNullOrWhiteSpace(placa) || (string.IsNullOrWhiteSpace(marca) && string.IsNullOrWhiteSpace(modelo) && string.IsNullOrWhiteSpace(nuevaPlaca)))
        {
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error: Debe ingresar la placa del vehículo y al menos un dato nuevo.");
            Console.ResetColor();
            return;
        }

        string[]? lines = null;
        try
        {
            lines = File.ReadAllLines(filePath);

            bool datosCambiados = false;
            using (StreamWriter writer = new StreamWriter(filePath))
            {
                foreach (string line in lines)
                {
                    if (line.Contains($"Placa: {placa}"))
                    {
                        string newLine = line;
                        if (!string.IsNullOrWhiteSpace(marca))
                        {
                            newLine = newLine.Replace("Marca:", $"Marca: {marca}");
                        }
                        if (!string.IsNullOrWhiteSpace(modelo))
                        {
                            newLine = newLine.Replace("Modelo:", $"Modelo: {modelo}");
                        }
                        if (!string.IsNullOrWhiteSpace(nuevaPlaca))
                        {
                            newLine = newLine.Replace($"Placa: {placa}", $"Placa: {nuevaPlaca}");
                        }

                        writer.WriteLine(newLine);
                        datosCambiados = true;
                    }
                    else
                    {
                        writer.WriteLine(line);
                    }
                }
            }

            if (datosCambiados)
            {
                Console.WriteLine();
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Datos cambiados correctamente.");
                Console.ResetColor();
            }
            else
            {
                Console.WriteLine();
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("No se encontraron datos con la placa especificada.");
                Console.ResetColor();
            }
        }
        catch (IOException ex)
        {
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error al cambiar datos: " + ex.Message);
            Console.ResetColor();
        }
        finally
        {
            if (lines != null)
            {
                Array.Clear(lines, 0, lines.Length);
            }
        }
    }

    // Método para consultar todos los datos de los vehículos
    static void ConsultarDatos()
    {
        try
        {
            string[] lines = File.ReadAllLines(filePath);

            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("===========================================");
            Console.WriteLine("           DATOS DE LOS VEHÍCULOS           ");
            Console.WriteLine("===========================================");
            Console.ResetColor();

            Console.WriteLine();
            foreach (string line in lines)
            {
                Console.WriteLine(line);
            }
        }
        catch (IOException ex)
        {
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error al consultar datos: " + ex.Message);
            Console.ResetColor();
        }
    }
}

// EJERCICIO #2 CON ARCHIVOS TXT
// I.C.I. UAA
// 23 de Mayo de 2023
//  - Luis Pablo Esparza Terrones
//  - Luis Manuel Flores Jiménesz
//  - Adrián de Jesús Frausto Pérez
//  - Juan Francisco Gallo Ramírez

using System.IO;

class Program
{
    static string filePath = "pacientes.txt"; // Ruta del archivo de texto

    static void Main(string[] args)
    {
        Console.ForegroundColor = ConsoleColor.White;
        Console.WriteLine("=== SISTEMA DE REGISTRO DE PACIENTES ===");
        Console.ResetColor();
        Console.WriteLine();

        bool salir = false;

        while (!salir)
        {
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("MENU PRINCIPAL");
            Console.WriteLine("========================\n");
            Console.ResetColor();
            Console.WriteLine("    1. Agregar paciente");
            Console.WriteLine("    2. Borrar paciente");
            Console.WriteLine("    3. Cambiar datos de paciente");
            Console.WriteLine("    4. Consultar pacientes");
            Console.WriteLine("    5. Salir");
            Console.WriteLine();

            Console.Write("Ingrese la opción deseada: ");
            string opcion = Console.ReadLine();

            Console.Clear(); // Limpiar la pantalla

            switch (opcion)
            {
                case "1":
                    AgregarPaciente();
                    break;
                case "2":
                    BorrarPaciente();
                    break;
                case "3":
                    CambiarDatosPaciente();
                    break;
                case "4":
                    ConsultarPacientes();
                    break;
                case "5":
                    salir = true;
                    break;
                default:
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("Opción inválida. Por favor, ingrese una opción válida del menú.");
                    Console.ResetColor();
                    break;
            }

            Console.WriteLine();
            Console.WriteLine("Presione cualquier tecla para continuar...");
            Console.ReadKey();
            Console.Clear(); // Limpiar la pantalla
        }
    }

    // Método para agregar un paciente
    static void AgregarPaciente()
    {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine("AGREGAR PACIENTE");
        Console.WriteLine("========================");
        Console.ResetColor();
        Console.WriteLine();

        // Solicitar los datos del paciente
        Console.Write("Nombre: ");
        string nombre = Console.ReadLine();

        Console.Write("Ciudad: ");
        string ciudad = Console.ReadLine();

        Console.Write("Edad: ");
        string edadStr = Console.ReadLine();

        int edad;
        bool edadValida = int.TryParse(edadStr, out edad);

        Console.Write("Género (M/F): ");
        string genero = Console.ReadLine();

        Console.Write("Descripción de enfermedad o padecimiento: ");
        string descripcion = Console.ReadLine();

        // Validar los datos ingresados
        if (string.IsNullOrWhiteSpace(nombre) || string.IsNullOrWhiteSpace(ciudad) || string.IsNullOrWhiteSpace(edadStr) || !edadValida || string.IsNullOrWhiteSpace(genero) || string.IsNullOrWhiteSpace(descripcion))
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error: Los datos ingresados son inválidos. Por favor, asegúrese de completar todos los campos correctamente.");
            Console.ResetColor();
            return;
        }

        try
        {
            using (StreamWriter writer = new StreamWriter(filePath, true))
            {
                // Escribir los datos del paciente en el archivo de texto
                writer.WriteLine("Nombre: " + nombre);
                writer.WriteLine("Ciudad: " + ciudad);
                writer.WriteLine("Edad: " + edad);
                writer.WriteLine("Género: " + genero);
                writer.WriteLine("Descripción: " + descripcion);
                writer.WriteLine("----------------------------------");
            }

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Paciente agregado correctamente.");
            Console.ResetColor();
        }
        catch (IOException ex)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error al agregar paciente: " + ex.Message);
            Console.ResetColor();
        }
    }


    // Método para borrar un paciente
    static void BorrarPaciente()
    {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine("BORRAR PACIENTE");
        Console.WriteLine("========================");
        Console.ResetColor();
        Console.WriteLine();

        Console.Write("Ingrese el nombre del paciente a borrar: ");
        string nombreABorrar = Console.ReadLine();

        if (string.IsNullOrWhiteSpace(nombreABorrar))
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error: El nombre ingresado es inválido. Por favor, ingrese un nombre válido.");
            Console.ResetColor();
            return;
        }

        bool pacienteEncontrado = false;
        string[] lines = null;

        try
        {
            // Leer todas las líneas del archivo
            lines = File.ReadAllLines(filePath);

            using (StreamWriter writer = new StreamWriter(filePath))
            {
                // Recorrer todas las líneas del archivo
                for (int i = 0; i < lines.Length; i += 6)
                {
                    // Obtener el nombre del paciente actual
                    string nombre = lines[i].Replace("Nombre: ", "");

                    if (nombre == nombreABorrar)
                    {
                        // Si se encuentra el paciente, marcar como encontrado y continuar con la siguiente línea
                        pacienteEncontrado = true;
                        continue;
                    }

                    // Escribir las líneas del paciente en el archivo de texto (excepto las del paciente a borrar)
                    writer.WriteLine(lines[i]);
                    writer.WriteLine(lines[i + 1]);
                    writer.WriteLine(lines[i + 2]);
                    writer.WriteLine(lines[i + 3]);
                    writer.WriteLine(lines[i + 4]);
                    writer.WriteLine(lines[i + 5]);
                }
            }

            if (pacienteEncontrado)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Paciente borrado correctamente.");
                Console.ResetColor();
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("No se encontró ningún paciente con el nombre especificado.");
                Console.ResetColor();
            }
        }
        catch (IOException ex)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error al borrar paciente: " + ex.Message);
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

    // Método para cambiar los datos de un paciente
    static void CambiarDatosPaciente()
    {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine("CAMBIAR DATOS DE PACIENTE");
        Console.WriteLine("========================");
        Console.ResetColor();
        Console.WriteLine();

        Console.Write("Ingrese el nombre del paciente: ");
        string nombreBusqueda = Console.ReadLine();

        if (string.IsNullOrWhiteSpace(nombreBusqueda))
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error: El nombre ingresado es inválido. Por favor, ingrese un nombre válido.");
            Console.ResetColor();
            return;
        }

        Console.WriteLine();
        Console.WriteLine("NUEVOS DATOS DEL PACIENTE");

        Console.Write("Nuevo nombre (?): ");
        string nuevoNombre = Console.ReadLine();

        Console.Write("Nueva ciudad (?): ");
        string nuevaCiudad = Console.ReadLine();

        Console.Write("Nueva edad (?): ");
        string nuevaEdadStr = Console.ReadLine();

        int nuevaEdad;
        bool nuevaEdadValida = int.TryParse(nuevaEdadStr, out nuevaEdad);

        Console.Write("Nuevo género (M/F) (?): ");
        string nuevoGenero = Console.ReadLine();

        Console.Write("Nueva descripción de enfermedad o padecimiento (?): ");
        string nuevaDescripcion = Console.ReadLine();

        if (string.IsNullOrWhiteSpace(nuevoNombre) && string.IsNullOrWhiteSpace(nuevaCiudad) && string.IsNullOrWhiteSpace(nuevaEdadStr) && string.IsNullOrWhiteSpace(nuevoGenero) && string.IsNullOrWhiteSpace(nuevaDescripcion))
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error: No se especificaron nuevos datos. Por favor, ingrese al menos un nuevo dato para actualizar.");
            Console.ResetColor();
            return;
        }

        bool pacienteEncontrado = false;
        string[] lines = null;

        try
        {
            // Leer todas las líneas del archivo
            lines = File.ReadAllLines(filePath);

            using (StreamWriter writer = new StreamWriter(filePath))
            {
                // Recorrer todas las líneas del archivo
                for (int i = 0; i < lines.Length; i += 6)
                {
                    // Obtener el nombre del paciente actual
                    string nombre = lines[i].Replace("Nombre: ", "");

                    if (nombre == nombreBusqueda)
                    {
                        // Si se encuentra el paciente, marcar como encontrado y actualizar los datos
                        pacienteEncontrado = true;

                        if (!string.IsNullOrWhiteSpace(nuevoNombre))
                        {
                            lines[i] = "Nombre: " + nuevoNombre;
                        }
                        if (!string.IsNullOrWhiteSpace(nuevaCiudad))
                        {
                            lines[i + 1] = "Ciudad: " + nuevaCiudad;
                        }
                        if (!string.IsNullOrWhiteSpace(nuevaEdadStr) && nuevaEdadValida)
                        {
                            lines[i + 2] = "Edad: " + nuevaEdad;
                        }
                        if (!string.IsNullOrWhiteSpace(nuevoGenero))
                        {
                            lines[i + 3] = "Género: " + nuevoGenero;
                        }
                        if (!string.IsNullOrWhiteSpace(nuevaDescripcion))
                        {
                            lines[i + 4] = "Descripción: " + nuevaDescripcion;
                        }
                    }

                    // Escribir las líneas del paciente en el archivo de texto
                    writer.WriteLine(lines[i]);
                    writer.WriteLine(lines[i + 1]);
                    writer.WriteLine(lines[i + 2]);
                    writer.WriteLine(lines[i + 3]);
                    writer.WriteLine(lines[i + 4]);
                    writer.WriteLine(lines[i + 5]);
                }
            }

            if (pacienteEncontrado)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Datos del paciente actualizados correctamente.");
                Console.ResetColor();
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("No se encontró ningún paciente con el nombre especificado.");
                Console.ResetColor();
            }
        }
        catch (IOException ex)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error al cambiar datos de paciente: " + ex.Message);
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

    // Método para consultar los pacientes registrados
    static void ConsultarPacientes()
    {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine("CONSULTAR PACIENTES");
        Console.WriteLine("========================");
        Console.ResetColor();
        Console.WriteLine();

        try
        {
            // Leer todas las líneas del archivo
            string[] lines = File.ReadAllLines(filePath);

            if (lines.Length == 0)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("No hay pacientes registrados.");
                Console.ResetColor();
            }
            else
            {
                Console.WriteLine("LISTA DE PACIENTES\n");

                for (int i = 0; i < lines.Length; i += 6)
                {
                    Console.WriteLine(lines[i]);
                    Console.WriteLine(lines[i + 1]);
                    Console.WriteLine(lines[i + 2]);
                    Console.WriteLine(lines[i + 3]);
                    Console.WriteLine(lines[i + 4]);
                    Console.WriteLine(lines[i + 5]);
                    Console.WriteLine();
                }
            }
        }
        catch (IOException ex)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Error al consultar pacientes: " + ex.Message);
            Console.ResetColor();
        }
    }
}

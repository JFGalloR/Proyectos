using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace EJERCICIO_ArchivosTxt
{
    internal class Archivo
    {
        // Método que agrega los datos al archivo .txt
        public bool Agregar(string id, string nombre, string centro, string carrera)
        {
            try
            {
                using (StreamWriter sw = new StreamWriter("Alumnos_UAA.txt", true))
                {
                    sw.WriteLine(id);
                    sw.WriteLine(nombre);
                    sw.WriteLine(centro);
                    sw.WriteLine(carrera);
                    sw.WriteLine("=============================");
                    return true;
                }
            }
            catch (IOException) 
            {
                MessageBox.Show("No se pudo añadir el alumno.", "Agregar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
        }
        // Método que elimina los datos al archivo .txt
        public bool Eliminar(string id)
        {
            bool encontrado = false;
            try
            {
                string[] lineas = File.ReadAllLines("Alumnos_UAA.txt");

                using (StreamWriter sw = new StreamWriter("Alumnos_UAA.txt"))
                {

                    for (int i = 0; i < lineas.Length; i+=5) 
                    {
                        if(id == lineas[i])
                        {
                            encontrado = true;
                        }
                        else
                        {
                            sw.WriteLine(lineas[i]);
                            sw.WriteLine(lineas[i+1]);
                            sw.WriteLine(lineas[i+2]);
                            sw.WriteLine(lineas[i+3]);
                            sw.WriteLine(lineas[i+4]);

                        }
                    }
                    if(encontrado)
                    {
                        return true;
                    }
                    else
                    {
                        MessageBox.Show("Alumno no encontrado.", "Eliminar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return false;
                    }
                }
            }
            catch (IOException)
            {
                MessageBox.Show("No se pudo eliminar el alumno.", "Eliminar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
        }
        // Método que busca los datos al archivo .txt
        public bool Buscar(string id)
        {
            bool encontrado = false;
            try
            {
                string[] lineas = File.ReadAllLines("Alumnos_UAA.txt");

                using (StreamWriter sw = new StreamWriter("Alumnos_UAA.txt"))
                {

                    for (int i = 0; i < lineas.Length; i += 5)
                    {
                        if (id == lineas[i])
                        {
                            MessageBox.Show("Alumno encontrado. Continue con el registro.", "Modificar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                            encontrado = true;
                        }
                        sw.WriteLine(lineas[i]);
                        sw.WriteLine(lineas[i + 1]);
                        sw.WriteLine(lineas[i + 2]);
                        sw.WriteLine(lineas[i + 3]);
                        sw.WriteLine(lineas[i + 4]);
                    }
                    if (encontrado)
                    {
                        return true;
                    }
                    else
                    {
                        MessageBox.Show("Alumno no encontrado.", "Modificar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return false;
                    }
                }
            }
            catch (IOException)
            {
                MessageBox.Show("No se pudo encontrar el alumno.", "Modificar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
        }
        // Método que modificar los datos al archivo .txt
        public bool Modificar(string id, params string[] dato)
        {
            try
            {
                string[] lineas = File.ReadAllLines("Alumnos_UAA.txt");

                using (StreamWriter sw = new StreamWriter("Alumnos_UAA.txt"))
                {

                    for (int i = 0; i < lineas.Length; i += 5)
                    {
                        if (id == lineas[i])
                        {
                            sw.WriteLine(dato[0]);
                            sw.WriteLine(dato[1]);
                            sw.WriteLine(dato[2]);
                            sw.WriteLine(dato[3]);
                            sw.WriteLine(lineas[i + 4]);
                        }
                        else
                        {
                            sw.WriteLine(lineas[i]);
                            sw.WriteLine(lineas[i + 1]);
                            sw.WriteLine(lineas[i + 2]);
                            sw.WriteLine(lineas[i + 3]);
                            sw.WriteLine(lineas[i + 4]);

                        }
                    }
                    return true;
                }
            }
            catch (IOException)
            {
                MessageBox.Show("No se pudo modificar el alumno.", "Modificar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
        }
    }
}

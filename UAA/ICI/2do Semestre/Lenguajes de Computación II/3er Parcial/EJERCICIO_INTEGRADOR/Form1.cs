/*======================================================================
    EJERCICIO INTEGRADOR. Calculo de Nómina.
  --------------------------------------------------------------------
    OBJETIVO:
    Codificar un programa en C# con Windows Forms, como aplicación de 
    clases, objetos y métodos, que permita a través de un método 
    calcular el valor devengado del salario de un trabajador.

    Los datos requeridos son:
        - Nombre
        - Identificación
        - Asignación del salario por dia
        - Días trabajados
  --------------------------------------------------------------------
    ELABORADORES:
        > Luis pablo Esparza Terrones
        > Juan Francisco Gallo Ramírez
  --------------------------------------------------------------------
    21 de Mayo de 2023.
    UAA. I.C.I.
======================================================================*/
namespace EJERCICIO_INTEGRADOR
{
    public partial class Form1 : Form
    {
        // Objetos de las clases empleado y nómina.
        Empleado emp = new Empleado();
        Nomina nmn = new Nomina();
        public Form1()
        {
            InitializeComponent();
        }

        // Función para validar la entrada de datos.
        private bool validar()
        {
            // Variable del tipo "bool" para validar que no haya errores.
            bool valid = true;

            // Validación del textbox de días.
            if (!Decimal.TryParse(textBoxDays.Text, out decimal Dias))
            {
                // Se evalúa que se ingresen solo números en el textbox.
                errorProvider1.SetError(textBoxDays, "Ingresa Números");
                textBoxDays.Focus();
                valid = false;
            }
            else
            {
                // Se establece que no hay error.
                errorProvider1.SetError(textBoxDays, string.Empty);
            }

            // Validación de textbox de salario diario.
            if (!Decimal.TryParse(textBoxSalary.Text, out decimal AsigDia))
            {
                // Se evalúa que se ingresen solo números en el textbox.
                errorProvider1.SetError(textBoxSalary, "Ingresa Números");
                textBoxSalary.Focus();
                valid = false;
            }
            else
            {
                // Se establece que no hay error.
                errorProvider1.SetError(textBoxSalary, string.Empty);
            }

            // Validación de textbox identificación.
            if (textBoxIden.Text == string.Empty)
            {
                // Se evalúa que ingresen datos en el textbox.
                errorProvider1.SetError(textBoxIden, "Ingresa Identificación");
                textBoxIden.Focus();
                valid = false;
            }
            else
            {
                // Se establece que no hay error.
                errorProvider1.SetError(textBoxIden, string.Empty);
            }

            // Validación de textbox de nombre.
            if (textBoxName.Text == string.Empty)
            {
                // Se evalúa que ingresen datos en el textbox.
                errorProvider1.SetError(textBoxName, "Ingresa Nombre");
                textBoxName.Focus();
                valid = false;
            }
            else
            {
                // Se establece que no hay error.
                errorProvider1.SetError(textBoxName, string.Empty);
            }

            // Se retorna el valor obtenido por las evaluaciones.
            return valid;

        }

        private void buttonExit_Click(object sender, EventArgs e)
        {
            // Salimos de la aplicación.
            Application.Exit();
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            // Se evalúa si no hay errores al ingresar datos.
            if (validar())
            {
                // Se asignan los valores obtenidos por la entrada de datos.
                emp.Nombre = textBoxName.Text;
                emp.Iden = textBoxIden.Text;
                emp.AsigDia = Convert.ToDecimal(textBoxSalary.Text);
                nmn.DiasLab = Convert.ToInt32(textBoxDays.Text);
                // Se muestra un mensaje.
                MessageBox.Show("Regristro Guardado Correctamente", "GUARDAR REGISTRO", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
        }

        private void buttonCalculate_Click(object sender, EventArgs e)
        {
            // Se asignan los valores obtenidos por la entrada de datos.
            if (validar())
            {
                // Se hace el cálculo de la nómina.
                textBoxTotal.Text = "$" + nmn.CalcularNomina(nmn.DiasLab, emp.AsigDia).ToString();
            }
            else
            {
                textBoxTotal.Text = string.Empty;
                // Se muestra un mensaje.
                MessageBox.Show("Ingresa los datos correctamente.", "CÁLCULO DE NÓMINA", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void buttonNew_Click(object sender, EventArgs e)
        {
            // Limpiamos todos los textBox.
            textBoxName.Clear();
            textBoxIden.Clear();
            textBoxSalary.Clear();
            textBoxDays.Clear();
            textBoxTotal.Clear();
        }
    }
}
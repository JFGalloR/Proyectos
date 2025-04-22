/*======================================================================
    EJERCICIO INTEGRADOR. Calculo de N�mina.
  --------------------------------------------------------------------
    OBJETIVO:
    Codificar un programa en C# con Windows Forms, como aplicaci�n de 
    clases, objetos y m�todos, que permita a trav�s de un m�todo 
    calcular el valor devengado del salario de un trabajador.

    Los datos requeridos son:
        - Nombre
        - Identificaci�n
        - Asignaci�n del salario por dia
        - D�as trabajados
  --------------------------------------------------------------------
    ELABORADORES:
        > Luis pablo Esparza Terrones
        > Juan Francisco Gallo Ram�rez
  --------------------------------------------------------------------
    21 de Mayo de 2023.
    UAA. I.C.I.
======================================================================*/
namespace EJERCICIO_INTEGRADOR
{
    public partial class Form1 : Form
    {
        // Objetos de las clases empleado y n�mina.
        Empleado emp = new Empleado();
        Nomina nmn = new Nomina();
        public Form1()
        {
            InitializeComponent();
        }

        // Funci�n para validar la entrada de datos.
        private bool validar()
        {
            // Variable del tipo "bool" para validar que no haya errores.
            bool valid = true;

            // Validaci�n del textbox de d�as.
            if (!Decimal.TryParse(textBoxDays.Text, out decimal Dias))
            {
                // Se eval�a que se ingresen solo n�meros en el textbox.
                errorProvider1.SetError(textBoxDays, "Ingresa N�meros");
                textBoxDays.Focus();
                valid = false;
            }
            else
            {
                // Se establece que no hay error.
                errorProvider1.SetError(textBoxDays, string.Empty);
            }

            // Validaci�n de textbox de salario diario.
            if (!Decimal.TryParse(textBoxSalary.Text, out decimal AsigDia))
            {
                // Se eval�a que se ingresen solo n�meros en el textbox.
                errorProvider1.SetError(textBoxSalary, "Ingresa N�meros");
                textBoxSalary.Focus();
                valid = false;
            }
            else
            {
                // Se establece que no hay error.
                errorProvider1.SetError(textBoxSalary, string.Empty);
            }

            // Validaci�n de textbox identificaci�n.
            if (textBoxIden.Text == string.Empty)
            {
                // Se eval�a que ingresen datos en el textbox.
                errorProvider1.SetError(textBoxIden, "Ingresa Identificaci�n");
                textBoxIden.Focus();
                valid = false;
            }
            else
            {
                // Se establece que no hay error.
                errorProvider1.SetError(textBoxIden, string.Empty);
            }

            // Validaci�n de textbox de nombre.
            if (textBoxName.Text == string.Empty)
            {
                // Se eval�a que ingresen datos en el textbox.
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
            // Salimos de la aplicaci�n.
            Application.Exit();
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            // Se eval�a si no hay errores al ingresar datos.
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
                // Se hace el c�lculo de la n�mina.
                textBoxTotal.Text = "$" + nmn.CalcularNomina(nmn.DiasLab, emp.AsigDia).ToString();
            }
            else
            {
                textBoxTotal.Text = string.Empty;
                // Se muestra un mensaje.
                MessageBox.Show("Ingresa los datos correctamente.", "C�LCULO DE N�MINA", MessageBoxButtons.OK, MessageBoxIcon.Warning);
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
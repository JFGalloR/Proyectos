using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EJERCICIO_JFGR
{
    public partial class Ejercicio1 : Form
    {
        public Ejercicio1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Lunes_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            label1.ForeColor = Lunes.FlatAppearance.MouseOverBackColor;
            label1.Text = Lunes.Text;
        }

        private void Martes_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            label1.ForeColor = Martes.FlatAppearance.MouseOverBackColor;
            label1.Text = Martes.Text;
        }

        private void Miercoles_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            label1.ForeColor = Miercoles.FlatAppearance.MouseOverBackColor;
            label1.Text = Miercoles.Text;
        }

        private void Jueves_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            label1.ForeColor = Jueves.FlatAppearance.MouseOverBackColor;
            label1.Text = Jueves.Text;
        }

        private void Viernes_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            label1.ForeColor = Viernes.FlatAppearance.MouseOverBackColor;
            label1.Text = Viernes.Text;
        }

        private void Sabado_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            label1.ForeColor = Sabado.FlatAppearance.MouseOverBackColor;
            label1.Text = Sabado.Text;
        }

        private void Domingo_Click(object sender, EventArgs e)
        {
            label1.Visible = true;
            label1.ForeColor = Domingo.FlatAppearance.MouseOverBackColor;
            label1.Text = Domingo.Text;
        }

        private void Regresar_Click(object sender, EventArgs e)
        {
            Menu menu = new Menu();
            this.Hide();
            menu.Show();
        }

        private void Regresar_MouseMove(object sender, MouseEventArgs e)
        {
            Regresar.ForeColor = Color.Black;
        }

        private void Regresar_MouseLeave(object sender, EventArgs e)
        {
            Regresar.ForeColor = Color.White;
        }

        private void Ejercicio1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}

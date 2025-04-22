using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace ExtractorFirma
{
    public partial class VentanaExtraccion : Form
    {
        Bitmap imagen;
        public VentanaExtraccion(Bitmap imagen)
        {
            this.imagen = imagen;
            InitializeComponent();
            pictureBox1.Image = imagen;
        }

        private void guardar_Click(object sender, EventArgs e)
        {
            if (imagen != null)
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Filter = "Archivos de imagen|*.jpg;*.jpeg;*.png;*.bmp|Todos los archivos (*.*)|*.*";

                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    string filePath = saveFileDialog.FileName;
                    imagen.Save(filePath, ImageFormat.Jpeg);
                    MessageBox.Show("Imagen guardada exitosamente.", "Guardar imagen", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    MessageBox.Show("Imagen no guardada.", "Guardar imagen", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            else
            {
                MessageBox.Show("Imagen no cargada.", "Guardar imagen", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }
    }
}

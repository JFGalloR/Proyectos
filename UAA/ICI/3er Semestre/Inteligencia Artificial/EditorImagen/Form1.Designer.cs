using System.Drawing;
using System.Windows.Forms;

namespace EditorImagen
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.splitter1 = new System.Windows.Forms.Splitter();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBox4 = new System.Windows.Forms.PictureBox();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.button1 = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.archivoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.abrirToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.guardarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.salirToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.preprocesamientoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.originalToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.grisesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.negativosToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.potenciaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.binarizaciónToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.filtrosBásicosToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.recuperarColorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.gammaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pixelHomogéneoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.colorearImágenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.histogramasToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rojoRToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.verdeGToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.azulBToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.splitContainer1.Panel1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("splitContainer1.Panel1.BackgroundImage")));
            this.splitContainer1.Panel1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.splitContainer1.Panel1.Controls.Add(this.splitter1);
            this.splitContainer1.Panel1.Controls.Add(this.pictureBox1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(60)))), ((int)(((byte)(60)))), ((int)(((byte)(60)))));
            this.splitContainer1.Panel2.Controls.Add(this.panel1);
            this.splitContainer1.Panel2.Controls.Add(this.progressBar1);
            this.splitContainer1.Panel2.Controls.Add(this.button1);
            this.splitContainer1.Panel2.Controls.Add(this.panel2);
            this.splitContainer1.Panel2.Controls.Add(this.menuStrip1);
            this.splitContainer1.Panel2.ForeColor = System.Drawing.SystemColors.AppWorkspace;
            this.splitContainer1.Size = new System.Drawing.Size(738, 391);
            this.splitContainer1.SplitterDistance = 530;
            this.splitContainer1.SplitterWidth = 3;
            this.splitContainer1.TabIndex = 0;
            // 
            // splitter1
            // 
            this.splitter1.Location = new System.Drawing.Point(0, 0);
            this.splitter1.Name = "splitter1";
            this.splitter1.Size = new System.Drawing.Size(3, 391);
            this.splitter1.TabIndex = 1;
            this.splitter1.TabStop = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.pictureBox1.Location = new System.Drawing.Point(10, 11);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(517, 368);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.Controls.Add(this.pictureBox4);
            this.panel1.Controls.Add(this.pictureBox3);
            this.panel1.Controls.Add(this.trackBar1);
            this.panel1.Location = new System.Drawing.Point(8, 84);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(189, 47);
            this.panel1.TabIndex = 2;
            // 
            // pictureBox4
            // 
            this.pictureBox4.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox4.Image")));
            this.pictureBox4.Location = new System.Drawing.Point(0, 19);
            this.pictureBox4.Name = "pictureBox4";
            this.pictureBox4.Size = new System.Drawing.Size(20, 22);
            this.pictureBox4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox4.TabIndex = 11;
            this.pictureBox4.TabStop = false;
            // 
            // pictureBox3
            // 
            this.pictureBox3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox3.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox3.Image")));
            this.pictureBox3.Location = new System.Drawing.Point(169, 19);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(20, 22);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox3.TabIndex = 2;
            this.pictureBox3.TabStop = false;
            // 
            // trackBar1
            // 
            this.trackBar1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.trackBar1.AutoSize = false;
            this.trackBar1.LargeChange = 25;
            this.trackBar1.Location = new System.Drawing.Point(0, 0);
            this.trackBar1.Maximum = 200;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(189, 25);
            this.trackBar1.SmallChange = 5;
            this.trackBar1.TabIndex = 10;
            this.trackBar1.TickStyle = System.Windows.Forms.TickStyle.None;
            this.trackBar1.Value = 100;
            this.trackBar1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.trackBar1_MouseUp);
            // 
            // progressBar1
            // 
            this.progressBar1.AccessibleRole = System.Windows.Forms.AccessibleRole.Grip;
            this.progressBar1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.progressBar1.BackColor = System.Drawing.Color.Black;
            this.progressBar1.Enabled = false;
            this.progressBar1.Location = new System.Drawing.Point(8, 340);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(189, 9);
            this.progressBar1.Step = 1;
            this.progressBar1.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.progressBar1.TabIndex = 1;
            this.progressBar1.Visible = false;
            // 
            // button1
            // 
            this.button1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.button1.BackColor = System.Drawing.Color.Silver;
            this.button1.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DimGray;
            this.button1.FlatAppearance.MouseOverBackColor = System.Drawing.Color.White;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Microsoft YaHei", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.SystemColors.Desktop;
            this.button1.Location = new System.Drawing.Point(8, 355);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(189, 25);
            this.button1.TabIndex = 2;
            this.button1.Text = "Aplicar";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // panel2
            // 
            this.panel2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(20)))));
            this.panel2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.panel2.Controls.Add(this.pictureBox2);
            this.panel2.Location = new System.Drawing.Point(8, 135);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(187, 192);
            this.panel2.TabIndex = 1;
            // 
            // pictureBox2
            // 
            this.pictureBox2.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox2.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pictureBox2.BackgroundImage")));
            this.pictureBox2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBox2.Location = new System.Drawing.Point(0, 0);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(187, 192);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox2.TabIndex = 0;
            this.pictureBox2.TabStop = false;
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.menuStrip1.Font = new System.Drawing.Font("Microsoft YaHei", 9F, System.Drawing.FontStyle.Bold);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.archivoToolStripMenuItem,
            this.preprocesamientoToolStripMenuItem,
            this.filtrosBásicosToolStripMenuItem,
            this.histogramasToolStripMenuItem});
            this.menuStrip1.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.Flow;
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(5, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(205, 46);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // archivoToolStripMenuItem
            // 
            this.archivoToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.abrirToolStripMenuItem,
            this.guardarToolStripMenuItem,
            this.salirToolStripMenuItem});
            this.archivoToolStripMenuItem.Name = "archivoToolStripMenuItem";
            this.archivoToolStripMenuItem.Size = new System.Drawing.Size(67, 21);
            this.archivoToolStripMenuItem.Text = "Archivo";
            // 
            // abrirToolStripMenuItem
            // 
            this.abrirToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F);
            this.abrirToolStripMenuItem.Name = "abrirToolStripMenuItem";
            this.abrirToolStripMenuItem.Size = new System.Drawing.Size(125, 22);
            this.abrirToolStripMenuItem.Text = "Abrir";
            this.abrirToolStripMenuItem.Click += new System.EventHandler(this.abrirToolStripMenuItem_Click);
            // 
            // guardarToolStripMenuItem
            // 
            this.guardarToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F, System.Drawing.FontStyle.Bold);
            this.guardarToolStripMenuItem.Name = "guardarToolStripMenuItem";
            this.guardarToolStripMenuItem.Size = new System.Drawing.Size(125, 22);
            this.guardarToolStripMenuItem.Text = "Guardar";
            this.guardarToolStripMenuItem.Click += new System.EventHandler(this.guardarToolStripMenuItem_Click);
            // 
            // salirToolStripMenuItem
            // 
            this.salirToolStripMenuItem.ForeColor = System.Drawing.Color.Red;
            this.salirToolStripMenuItem.Name = "salirToolStripMenuItem";
            this.salirToolStripMenuItem.Size = new System.Drawing.Size(125, 22);
            this.salirToolStripMenuItem.Text = "Salir";
            this.salirToolStripMenuItem.Click += new System.EventHandler(this.salirToolStripMenuItem_Click);
            // 
            // preprocesamientoToolStripMenuItem
            // 
            this.preprocesamientoToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.originalToolStripMenuItem,
            this.grisesToolStripMenuItem,
            this.negativosToolStripMenuItem,
            this.potenciaToolStripMenuItem,
            this.binarizaciónToolStripMenuItem});
            this.preprocesamientoToolStripMenuItem.Name = "preprocesamientoToolStripMenuItem";
            this.preprocesamientoToolStripMenuItem.Size = new System.Drawing.Size(131, 21);
            this.preprocesamientoToolStripMenuItem.Text = "Preprocesamiento";
            // 
            // originalToolStripMenuItem
            // 
            this.originalToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.originalToolStripMenuItem.Name = "originalToolStripMenuItem";
            this.originalToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
            this.originalToolStripMenuItem.Text = "Original";
            this.originalToolStripMenuItem.Click += new System.EventHandler(this.originalToolStripMenuItem_Click);
            // 
            // grisesToolStripMenuItem
            // 
            this.grisesToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F);
            this.grisesToolStripMenuItem.Name = "grisesToolStripMenuItem";
            this.grisesToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
            this.grisesToolStripMenuItem.Text = "Grises";
            this.grisesToolStripMenuItem.Click += new System.EventHandler(this.grisesToolStripMenuItem_Click);
            // 
            // negativosToolStripMenuItem
            // 
            this.negativosToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F);
            this.negativosToolStripMenuItem.Name = "negativosToolStripMenuItem";
            this.negativosToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
            this.negativosToolStripMenuItem.Text = "Negativos";
            this.negativosToolStripMenuItem.Click += new System.EventHandler(this.negativosToolStripMenuItem_Click);
            // 
            // potenciaToolStripMenuItem
            // 
            this.potenciaToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F);
            this.potenciaToolStripMenuItem.Name = "potenciaToolStripMenuItem";
            this.potenciaToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
            this.potenciaToolStripMenuItem.Text = "Potencia";
            this.potenciaToolStripMenuItem.Click += new System.EventHandler(this.potenciaToolStripMenuItem_Click);
            // 
            // binarizaciónToolStripMenuItem
            // 
            this.binarizaciónToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F);
            this.binarizaciónToolStripMenuItem.Name = "binarizaciónToolStripMenuItem";
            this.binarizaciónToolStripMenuItem.Size = new System.Drawing.Size(146, 22);
            this.binarizaciónToolStripMenuItem.Text = "Binarización";
            this.binarizaciónToolStripMenuItem.Click += new System.EventHandler(this.binarizaciónToolStripMenuItem_Click);
            // 
            // filtrosBásicosToolStripMenuItem
            // 
            this.filtrosBásicosToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.recuperarColorToolStripMenuItem,
            this.gammaToolStripMenuItem,
            this.pixelHomogéneoToolStripMenuItem,
            this.colorearImágenToolStripMenuItem});
            this.filtrosBásicosToolStripMenuItem.Name = "filtrosBásicosToolStripMenuItem";
            this.filtrosBásicosToolStripMenuItem.Size = new System.Drawing.Size(108, 21);
            this.filtrosBásicosToolStripMenuItem.Text = "Filtros Básicos";
            // 
            // recuperarColorToolStripMenuItem
            // 
            this.recuperarColorToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.recuperarColorToolStripMenuItem.Name = "recuperarColorToolStripMenuItem";
            this.recuperarColorToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.recuperarColorToolStripMenuItem.Text = "Recuperar Color";
            this.recuperarColorToolStripMenuItem.Click += new System.EventHandler(this.recuperarColorToolStripMenuItem_Click);
            // 
            // gammaToolStripMenuItem
            // 
            this.gammaToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gammaToolStripMenuItem.Name = "gammaToolStripMenuItem";
            this.gammaToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.gammaToolStripMenuItem.Text = "Gamma";
            this.gammaToolStripMenuItem.Click += new System.EventHandler(this.gammaToolStripMenuItem_Click);
            // 
            // pixelHomogéneoToolStripMenuItem
            // 
            this.pixelHomogéneoToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.pixelHomogéneoToolStripMenuItem.Name = "pixelHomogéneoToolStripMenuItem";
            this.pixelHomogéneoToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.pixelHomogéneoToolStripMenuItem.Text = "Pixel Homogéneo";
            this.pixelHomogéneoToolStripMenuItem.Click += new System.EventHandler(this.pixelHomogéneoToolStripMenuItem_Click);
            // 
            // colorearImágenToolStripMenuItem
            // 
            this.colorearImágenToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.colorearImágenToolStripMenuItem.Name = "colorearImágenToolStripMenuItem";
            this.colorearImágenToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.colorearImágenToolStripMenuItem.Text = "Colorear Imágen";
            this.colorearImágenToolStripMenuItem.Click += new System.EventHandler(this.colorearImágenToolStripMenuItem_Click);
            // 
            // histogramasToolStripMenuItem
            // 
            this.histogramasToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.rojoRToolStripMenuItem,
            this.verdeGToolStripMenuItem,
            this.azulBToolStripMenuItem});
            this.histogramasToolStripMenuItem.Name = "histogramasToolStripMenuItem";
            this.histogramasToolStripMenuItem.Size = new System.Drawing.Size(92, 21);
            this.histogramasToolStripMenuItem.Text = "Histograma";
            // 
            // rojoRToolStripMenuItem
            // 
            this.rojoRToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F);
            this.rojoRToolStripMenuItem.ForeColor = System.Drawing.Color.Red;
            this.rojoRToolStripMenuItem.Name = "rojoRToolStripMenuItem";
            this.rojoRToolStripMenuItem.Size = new System.Drawing.Size(168, 22);
            this.rojoRToolStripMenuItem.Text = "Color Rojo (R)";
            this.rojoRToolStripMenuItem.Click += new System.EventHandler(this.rojoRToolStripMenuItem_Click);
            // 
            // verdeGToolStripMenuItem
            // 
            this.verdeGToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F);
            this.verdeGToolStripMenuItem.ForeColor = System.Drawing.Color.Green;
            this.verdeGToolStripMenuItem.Name = "verdeGToolStripMenuItem";
            this.verdeGToolStripMenuItem.Size = new System.Drawing.Size(168, 22);
            this.verdeGToolStripMenuItem.Text = "Color Verde (G)";
            this.verdeGToolStripMenuItem.Click += new System.EventHandler(this.verdeGToolStripMenuItem_Click);
            // 
            // azulBToolStripMenuItem
            // 
            this.azulBToolStripMenuItem.Font = new System.Drawing.Font("Microsoft YaHei", 9F);
            this.azulBToolStripMenuItem.ForeColor = System.Drawing.Color.Blue;
            this.azulBToolStripMenuItem.Name = "azulBToolStripMenuItem";
            this.azulBToolStripMenuItem.Size = new System.Drawing.Size(168, 22);
            this.azulBToolStripMenuItem.Text = "Color Azul (B)";
            this.azulBToolStripMenuItem.Click += new System.EventHandler(this.azulBToolStripMenuItem_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // colorDialog1
            // 
            this.colorDialog1.FullOpen = true;
            this.colorDialog1.SolidColorOnly = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(738, 391);
            this.Controls.Add(this.splitContainer1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.MinimumSize = new System.Drawing.Size(700, 430);
            this.Name = "Form1";
            this.Text = "Editor de Imagen";
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private SplitContainer splitContainer1;
        private PictureBox pictureBox1;
        private Panel panel2;
        private Button button1;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem archivoToolStripMenuItem;
        private ToolStripMenuItem abrirToolStripMenuItem;
        private ToolStripMenuItem guardarToolStripMenuItem;
        private ToolStripMenuItem preprocesamientoToolStripMenuItem;
        private ToolStripMenuItem salirToolStripMenuItem;
        private ToolStripMenuItem grisesToolStripMenuItem;
        private ToolStripMenuItem negativosToolStripMenuItem;
        private ToolStripMenuItem potenciaToolStripMenuItem;
        private ToolStripMenuItem binarizaciónToolStripMenuItem;
        private Splitter splitter1;
        private TrackBar trackBar1;
        private OpenFileDialog openFileDialog1;
        private PictureBox pictureBox2;
        private ToolStripMenuItem originalToolStripMenuItem;
        private ProgressBar progressBar1;
        private ToolStripMenuItem histogramasToolStripMenuItem;
        private ToolStripMenuItem rojoRToolStripMenuItem;
        private ToolStripMenuItem verdeGToolStripMenuItem;
        private ToolStripMenuItem azulBToolStripMenuItem;
        private Panel panel1;
        private PictureBox pictureBox4;
        private PictureBox pictureBox3;
        private ToolStripMenuItem filtrosBásicosToolStripMenuItem;
        private ToolStripMenuItem recuperarColorToolStripMenuItem;
        private ToolStripMenuItem gammaToolStripMenuItem;
        private ToolStripMenuItem pixelHomogéneoToolStripMenuItem;
        private ToolStripMenuItem colorearImágenToolStripMenuItem;
        private ColorDialog colorDialog1;
    }
}


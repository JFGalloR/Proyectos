namespace EJERCICIO_ArchivosTxt
{
    partial class Agregar
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Agregar));
            panel2 = new Panel();
            pictureBox2 = new PictureBox();
            panel1 = new Panel();
            pictureBox1 = new PictureBox();
            label1 = new Label();
            id = new TextBox();
            nombre = new TextBox();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            centroA = new ComboBox();
            carrera = new ComboBox();
            button1 = new Button();
            errorProvider1 = new ErrorProvider(components);
            errorProvider2 = new ErrorProvider(components);
            errorProvider3 = new ErrorProvider(components);
            errorProvider4 = new ErrorProvider(components);
            panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).BeginInit();
            panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider3).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider4).BeginInit();
            SuspendLayout();
            // 
            // panel2
            // 
            panel2.BackColor = Color.FromArgb(36, 44, 88);
            panel2.Controls.Add(pictureBox2);
            panel2.Dock = DockStyle.Bottom;
            panel2.Location = new Point(0, 559);
            panel2.Name = "panel2";
            panel2.Size = new Size(434, 52);
            panel2.TabIndex = 3;
            // 
            // pictureBox2
            // 
            pictureBox2.Image = (Image)resources.GetObject("pictureBox2.Image");
            pictureBox2.Location = new Point(12, 10);
            pictureBox2.Name = "pictureBox2";
            pictureBox2.Size = new Size(32, 32);
            pictureBox2.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox2.TabIndex = 9;
            pictureBox2.TabStop = false;
            pictureBox2.Click += pictureBox2_Click;
            pictureBox2.MouseLeave += pictureBox2_MouseLeave;
            pictureBox2.MouseMove += pictureBox2_MouseMove;
            // 
            // panel1
            // 
            panel1.Controls.Add(pictureBox1);
            panel1.Dock = DockStyle.Top;
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(434, 199);
            panel1.TabIndex = 4;
            // 
            // pictureBox1
            // 
            pictureBox1.Anchor = AnchorStyles.None;
            pictureBox1.BackgroundImageLayout = ImageLayout.None;
            pictureBox1.Image = (Image)resources.GetObject("pictureBox1.Image");
            pictureBox1.Location = new Point(155, 50);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(135, 135);
            pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox1.TabIndex = 0;
            pictureBox1.TabStop = false;
            // 
            // label1
            // 
            label1.Anchor = AnchorStyles.None;
            label1.AutoSize = true;
            label1.Font = new Font("Leelawadee", 21.75F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.FromArgb(36, 44, 88);
            label1.Location = new Point(103, 219);
            label1.Name = "label1";
            label1.Size = new Size(245, 35);
            label1.TabIndex = 5;
            label1.Text = "Agregar Alumno";
            // 
            // id
            // 
            id.Anchor = AnchorStyles.None;
            id.Font = new Font("Leelawadee", 12F, FontStyle.Regular, GraphicsUnit.Point);
            id.ForeColor = SystemColors.WindowText;
            id.Location = new Point(103, 308);
            id.MaxLength = 6;
            id.Name = "id";
            id.Size = new Size(245, 27);
            id.TabIndex = 6;
            id.KeyPress += id_KeyPress;
            // 
            // nombre
            // 
            nombre.Anchor = AnchorStyles.None;
            nombre.CharacterCasing = CharacterCasing.Upper;
            nombre.Font = new Font("Leelawadee", 12F, FontStyle.Regular, GraphicsUnit.Point);
            nombre.Location = new Point(103, 360);
            nombre.MaxLength = 40;
            nombre.Name = "nombre";
            nombre.Size = new Size(245, 27);
            nombre.TabIndex = 7;
            // 
            // label2
            // 
            label2.Anchor = AnchorStyles.None;
            label2.AutoSize = true;
            label2.Font = new Font("Leelawadee", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.Black;
            label2.Location = new Point(103, 286);
            label2.Name = "label2";
            label2.Size = new Size(26, 19);
            label2.TabIndex = 8;
            label2.Text = "ID";
            // 
            // label3
            // 
            label3.Anchor = AnchorStyles.None;
            label3.AutoSize = true;
            label3.Font = new Font("Leelawadee", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.Black;
            label3.Location = new Point(103, 338);
            label3.Name = "label3";
            label3.Size = new Size(72, 19);
            label3.TabIndex = 9;
            label3.Text = "Nombre";
            // 
            // label4
            // 
            label4.Anchor = AnchorStyles.None;
            label4.AutoSize = true;
            label4.Font = new Font("Leelawadee", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.Black;
            label4.Location = new Point(103, 390);
            label4.Name = "label4";
            label4.Size = new Size(149, 19);
            label4.TabIndex = 10;
            label4.Text = "Centro Académico";
            // 
            // label5
            // 
            label5.Anchor = AnchorStyles.None;
            label5.AutoSize = true;
            label5.Font = new Font("Leelawadee", 12F, FontStyle.Bold, GraphicsUnit.Point);
            label5.ForeColor = Color.Black;
            label5.Location = new Point(103, 438);
            label5.Name = "label5";
            label5.Size = new Size(64, 19);
            label5.TabIndex = 11;
            label5.Text = "Carrera";
            // 
            // centroA
            // 
            centroA.Anchor = AnchorStyles.None;
            centroA.DropDownStyle = ComboBoxStyle.DropDownList;
            centroA.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            centroA.FormattingEnabled = true;
            centroA.Items.AddRange(new object[] { "Ciencias Agropecuarias", "Ciencias Básicas", "Ciencias de la Ingeniería", "Ciencias de la Salud", "Ciencias del Diseño y de la Construcción", "Ciencias Económicas y Administrativas", "Ciencias Empresariales", "Ciencias Sociales y Humanidades", "Artes y la Cultura" });
            centroA.Location = new Point(103, 412);
            centroA.Name = "centroA";
            centroA.Size = new Size(245, 23);
            centroA.TabIndex = 12;
            centroA.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            // 
            // carrera
            // 
            carrera.Anchor = AnchorStyles.None;
            carrera.DropDownStyle = ComboBoxStyle.DropDownList;
            carrera.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            carrera.FormattingEnabled = true;
            carrera.Location = new Point(103, 460);
            carrera.Name = "carrera";
            carrera.Size = new Size(245, 23);
            carrera.TabIndex = 13;
            // 
            // button1
            // 
            button1.Anchor = AnchorStyles.None;
            button1.BackColor = Color.FromArgb(36, 44, 88);
            button1.FlatAppearance.BorderColor = SystemColors.ActiveBorder;
            button1.FlatAppearance.BorderSize = 2;
            button1.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            button1.ForeColor = SystemColors.ButtonHighlight;
            button1.Location = new Point(175, 496);
            button1.Name = "button1";
            button1.Size = new Size(100, 30);
            button1.TabIndex = 14;
            button1.Text = "Agregar";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // errorProvider1
            // 
            errorProvider1.ContainerControl = this;
            // 
            // errorProvider2
            // 
            errorProvider2.ContainerControl = this;
            // 
            // errorProvider3
            // 
            errorProvider3.ContainerControl = this;
            // 
            // errorProvider4
            // 
            errorProvider4.ContainerControl = this;
            // 
            // Agregar
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(434, 611);
            Controls.Add(button1);
            Controls.Add(carrera);
            Controls.Add(centroA);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(nombre);
            Controls.Add(id);
            Controls.Add(label1);
            Controls.Add(panel1);
            Controls.Add(panel2);
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            MaximumSize = new Size(600, 800);
            MinimumSize = new Size(450, 650);
            Name = "Agregar";
            StartPosition = FormStartPosition.CenterParent;
            Text = "Agregar Alumno";
            FormClosed += Agregar_FormClosed;
            panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)pictureBox2).EndInit();
            panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider2).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider3).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider4).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Panel panel2;
        private PictureBox pictureBox2;
        private Panel panel1;
        private PictureBox pictureBox1;
        private Label label1;
        private TextBox id;
        private TextBox nombre;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private ComboBox centroA;
        private ComboBox carrera;
        private Button button1;
        private ErrorProvider errorProvider1;
        private ErrorProvider errorProvider2;
        private ErrorProvider errorProvider3;
        private ErrorProvider errorProvider4;
    }
}
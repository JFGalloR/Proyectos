namespace EJERCICIO_ArchivosTxt
{
    partial class Modificar
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Modificar));
            panel2 = new Panel();
            pictureBox2 = new PictureBox();
            panel1 = new Panel();
            pictureBox1 = new PictureBox();
            label1 = new Label();
            id = new TextBox();
            label2 = new Label();
            button1 = new Button();
            errorProvider1 = new ErrorProvider(components);
            button2 = new Button();
            tabControl1 = new TabControl();
            tabPage1 = new TabPage();
            textBox1 = new TextBox();
            label3 = new Label();
            tabPage2 = new TabPage();
            textBox2 = new TextBox();
            label4 = new Label();
            tabPage3 = new TabPage();
            comboBox1 = new ComboBox();
            label5 = new Label();
            tabPage4 = new TabPage();
            comboBox2 = new ComboBox();
            label6 = new Label();
            errorProvider2 = new ErrorProvider(components);
            errorProvider3 = new ErrorProvider(components);
            errorProvider4 = new ErrorProvider(components);
            errorProvider5 = new ErrorProvider(components);
            panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).BeginInit();
            panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).BeginInit();
            tabControl1.SuspendLayout();
            tabPage1.SuspendLayout();
            tabPage2.SuspendLayout();
            tabPage3.SuspendLayout();
            tabPage4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)errorProvider2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider3).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider4).BeginInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider5).BeginInit();
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
            label1.Location = new Point(93, 219);
            label1.Name = "label1";
            label1.Size = new Size(265, 35);
            label1.TabIndex = 5;
            label1.Text = "Modificar Alumno";
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
            // button1
            // 
            button1.Anchor = AnchorStyles.None;
            button1.BackColor = Color.FromArgb(36, 44, 88);
            button1.FlatAppearance.BorderColor = SystemColors.ActiveBorder;
            button1.FlatAppearance.BorderSize = 2;
            button1.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            button1.ForeColor = SystemColors.ButtonHighlight;
            button1.Location = new Point(175, 346);
            button1.Name = "button1";
            button1.Size = new Size(100, 30);
            button1.TabIndex = 14;
            button1.Text = "Buscar";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // errorProvider1
            // 
            errorProvider1.ContainerControl = this;
            // 
            // button2
            // 
            button2.Anchor = AnchorStyles.None;
            button2.BackColor = Color.FromArgb(36, 44, 88);
            button2.FlatAppearance.BorderColor = SystemColors.ActiveBorder;
            button2.FlatAppearance.BorderSize = 2;
            button2.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            button2.ForeColor = SystemColors.ButtonHighlight;
            button2.Location = new Point(175, 489);
            button2.Name = "button2";
            button2.Size = new Size(100, 30);
            button2.TabIndex = 20;
            button2.Text = "Modificar";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Controls.Add(tabPage2);
            tabControl1.Controls.Add(tabPage3);
            tabControl1.Controls.Add(tabPage4);
            tabControl1.Font = new Font("Leelawadee", 9.75F, FontStyle.Bold, GraphicsUnit.Point);
            tabControl1.Location = new Point(103, 393);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(245, 90);
            tabControl1.TabIndex = 19;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(textBox1);
            tabPage1.Controls.Add(label3);
            tabPage1.Location = new Point(4, 24);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(237, 62);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "ID";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // textBox1
            // 
            textBox1.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            textBox1.Location = new Point(3, 33);
            textBox1.MaxLength = 6;
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(195, 23);
            textBox1.TabIndex = 1;
            textBox1.KeyPress += textBox1_KeyPress;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(6, 15);
            label3.Name = "label3";
            label3.Size = new Size(107, 15);
            label3.TabIndex = 0;
            label3.Text = "Ingresa nueva ID:";
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(textBox2);
            tabPage2.Controls.Add(label4);
            tabPage2.Location = new Point(4, 24);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(237, 62);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "Nombre";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // textBox2
            // 
            textBox2.CharacterCasing = CharacterCasing.Upper;
            textBox2.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            textBox2.Location = new Point(3, 33);
            textBox2.MaxLength = 40;
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(195, 23);
            textBox2.TabIndex = 17;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(6, 15);
            label4.Name = "label4";
            label4.Size = new Size(142, 15);
            label4.TabIndex = 17;
            label4.Text = "Ingresa nuevo nombre:";
            // 
            // tabPage3
            // 
            tabPage3.Controls.Add(comboBox1);
            tabPage3.Controls.Add(label5);
            tabPage3.Location = new Point(4, 24);
            tabPage3.Name = "tabPage3";
            tabPage3.Padding = new Padding(3);
            tabPage3.Size = new Size(237, 62);
            tabPage3.TabIndex = 2;
            tabPage3.Text = "Centro";
            tabPage3.UseVisualStyleBackColor = true;
            // 
            // comboBox1
            // 
            comboBox1.Font = new Font("Leelawadee", 8.25F, FontStyle.Regular, GraphicsUnit.Point);
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { "Ciencias Agropecuarias", "Ciencias Básicas", "Ciencias de la Ingeniería", "Ciencias de la Salud", "Ciencias del Diseño y de la Construcción", "Ciencias Económicas y Administrativas", "Ciencias Empresariales", "Ciencias Sociales y Humanidades", "Artes y la Cultura" });
            comboBox1.Location = new Point(6, 33);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(195, 22);
            comboBox1.TabIndex = 18;
            comboBox1.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            label5.Location = new Point(6, 15);
            label5.Name = "label5";
            label5.Size = new Size(133, 15);
            label5.TabIndex = 17;
            label5.Text = "Ingresa nuevo centro:";
            // 
            // tabPage4
            // 
            tabPage4.Controls.Add(comboBox2);
            tabPage4.Controls.Add(label6);
            tabPage4.Location = new Point(4, 24);
            tabPage4.Name = "tabPage4";
            tabPage4.Padding = new Padding(3);
            tabPage4.Size = new Size(237, 62);
            tabPage4.TabIndex = 3;
            tabPage4.Text = "Carrera";
            tabPage4.UseVisualStyleBackColor = true;
            // 
            // comboBox2
            // 
            comboBox2.Font = new Font("Leelawadee", 8.25F, FontStyle.Regular, GraphicsUnit.Point);
            comboBox2.FormattingEnabled = true;
            comboBox2.Location = new Point(6, 33);
            comboBox2.Name = "comboBox2";
            comboBox2.Size = new Size(195, 22);
            comboBox2.TabIndex = 19;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Leelawadee", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            label6.Location = new Point(6, 15);
            label6.Name = "label6";
            label6.Size = new Size(137, 15);
            label6.TabIndex = 17;
            label6.Text = "Ingresa nueva carrera:";
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
            // errorProvider5
            // 
            errorProvider5.ContainerControl = this;
            // 
            // Modificar
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(434, 611);
            Controls.Add(button2);
            Controls.Add(tabControl1);
            Controls.Add(button1);
            Controls.Add(label2);
            Controls.Add(id);
            Controls.Add(label1);
            Controls.Add(panel1);
            Controls.Add(panel2);
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            MaximumSize = new Size(600, 800);
            MinimumSize = new Size(450, 650);
            Name = "Modificar";
            StartPosition = FormStartPosition.CenterParent;
            Text = "Modificar Alumno";
            FormClosed += Eliminar_FormClosed;
            panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)pictureBox2).EndInit();
            panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).EndInit();
            tabControl1.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            tabPage1.PerformLayout();
            tabPage2.ResumeLayout(false);
            tabPage2.PerformLayout();
            tabPage3.ResumeLayout(false);
            tabPage3.PerformLayout();
            tabPage4.ResumeLayout(false);
            tabPage4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)errorProvider2).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider3).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider4).EndInit();
            ((System.ComponentModel.ISupportInitialize)errorProvider5).EndInit();
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
        private Label label2;
        private Button button1;
        private ErrorProvider errorProvider1;
        private Button button2;
        private TabControl tabControl1;
        private TabPage tabPage1;
        private TextBox textBox1;
        private Label label3;
        private TabPage tabPage2;
        private TextBox textBox2;
        private Label label4;
        private TabPage tabPage3;
        private ComboBox comboBox1;
        private Label label5;
        private TabPage tabPage4;
        private ComboBox comboBox2;
        private Label label6;
        private ErrorProvider errorProvider2;
        private ErrorProvider errorProvider3;
        private ErrorProvider errorProvider4;
        private ErrorProvider errorProvider5;
    }
}
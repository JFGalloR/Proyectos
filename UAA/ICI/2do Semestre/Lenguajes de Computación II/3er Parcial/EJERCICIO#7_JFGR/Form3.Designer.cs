namespace EJERCICIO_ComboBox
{
    partial class Form3
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form3));
            button1 = new Button();
            button2 = new Button();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            comboBox1 = new ComboBox();
            comboBox2 = new ComboBox();
            comboBox3 = new ComboBox();
            panel1 = new Panel();
            panel3 = new Panel();
            panel2 = new Panel();
            panel2.SuspendLayout();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(117, 225);
            button1.Name = "button1";
            button1.Size = new Size(198, 31);
            button1.TabIndex = 0;
            button1.Text = "Actualizar";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.BackColor = Color.Silver;
            button2.FlatAppearance.BorderSize = 0;
            button2.Font = new Font("Segoe UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(12, 270);
            button2.Name = "button2";
            button2.Size = new Size(90, 29);
            button2.TabIndex = 8;
            button2.Text = "Regresar";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = SystemColors.Control;
            label1.Font = new Font("Cascadia Code", 36F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = SystemColors.ActiveCaptionText;
            label1.ImeMode = ImeMode.NoControl;
            label1.Location = new Point(24, 0);
            label1.Name = "label1";
            label1.Size = new Size(363, 63);
            label1.TabIndex = 9;
            label1.Text = "Pintar Fondo";
            label1.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.FromArgb(192, 0, 0);
            label2.Font = new Font("Cascadia Code", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(117, 106);
            label2.Name = "label2";
            label2.Size = new Size(55, 21);
            label2.TabIndex = 10;
            label2.Text = "Rojo ";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.FromArgb(0, 192, 0);
            label3.Font = new Font("Cascadia Code", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label3.Location = new Point(189, 106);
            label3.Name = "label3";
            label3.Size = new Size(55, 21);
            label3.TabIndex = 11;
            label3.Text = "Verde";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.BackColor = Color.DodgerBlue;
            label4.Font = new Font("Cascadia Code", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(260, 106);
            label4.Name = "label4";
            label4.Size = new Size(55, 21);
            label4.TabIndex = 12;
            label4.Text = "Azul ";
            // 
            // comboBox1
            // 
            comboBox1.Font = new Font("Cascadia Code", 9F, FontStyle.Regular, GraphicsUnit.Point);
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(117, 130);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(55, 24);
            comboBox1.TabIndex = 13;
            comboBox1.SelectedIndexChanged += Cambio_ComboBox;
            // 
            // comboBox2
            // 
            comboBox2.Font = new Font("Cascadia Code", 9F, FontStyle.Regular, GraphicsUnit.Point);
            comboBox2.FormattingEnabled = true;
            comboBox2.Location = new Point(189, 130);
            comboBox2.Name = "comboBox2";
            comboBox2.Size = new Size(55, 24);
            comboBox2.TabIndex = 14;
            comboBox2.SelectedIndexChanged += Cambio_ComboBox;
            // 
            // comboBox3
            // 
            comboBox3.Font = new Font("Cascadia Code", 9F, FontStyle.Regular, GraphicsUnit.Point);
            comboBox3.FormattingEnabled = true;
            comboBox3.Location = new Point(260, 130);
            comboBox3.Name = "comboBox3";
            comboBox3.Size = new Size(55, 24);
            comboBox3.TabIndex = 15;
            comboBox3.SelectedIndexChanged += Cambio_ComboBox;
            // 
            // panel1
            // 
            panel1.Location = new Point(117, 174);
            panel1.Name = "panel1";
            panel1.Size = new Size(198, 30);
            panel1.TabIndex = 16;
            // 
            // panel3
            // 
            panel3.BackColor = SystemColors.ActiveCaptionText;
            panel3.Location = new Point(114, 171);
            panel3.Name = "panel3";
            panel3.Size = new Size(204, 36);
            panel3.TabIndex = 17;
            // 
            // panel2
            // 
            panel2.BackColor = SystemColors.Control;
            panel2.Controls.Add(label1);
            panel2.ForeColor = SystemColors.ButtonHighlight;
            panel2.Location = new Point(12, 30);
            panel2.Name = "panel2";
            panel2.Size = new Size(410, 63);
            panel2.TabIndex = 17;
            // 
            // Form3
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(434, 311);
            Controls.Add(panel1);
            Controls.Add(comboBox3);
            Controls.Add(comboBox2);
            Controls.Add(comboBox1);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(panel2);
            Controls.Add(panel3);
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            Name = "Form3";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Ejercicio #2";
            Load += Form3_Load;
            panel2.ResumeLayout(false);
            panel2.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private Button button2;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private ComboBox comboBox1;
        private ComboBox comboBox2;
        private ComboBox comboBox3;
        private Panel panel1;
        private Panel panel2;
        private Panel panel3;
    }
}
namespace EJERCICIO_INTEGRADOR
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
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            panel1 = new Panel();
            label1 = new Label();
            panel2 = new Panel();
            panel3 = new Panel();
            buttonSave = new Button();
            buttonCalculate = new Button();
            panel4 = new Panel();
            buttonExit = new Button();
            buttonNew = new Button();
            label6 = new Label();
            textBoxTotal = new TextBox();
            textBoxName = new TextBox();
            textBoxIden = new TextBox();
            label5 = new Label();
            textBoxDays = new TextBox();
            label4 = new Label();
            textBoxSalary = new TextBox();
            label3 = new Label();
            label2 = new Label();
            errorProvider1 = new ErrorProvider(components);
            panel3.SuspendLayout();
            panel4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).BeginInit();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.BackColor = Color.Maroon;
            panel1.Location = new Point(0, 44);
            panel1.Name = "panel1";
            panel1.Size = new Size(116, 140);
            panel1.TabIndex = 2;
            // 
            // label1
            // 
            label1.Anchor = AnchorStyles.Top;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.Maroon;
            label1.Location = new Point(113, 44);
            label1.Name = "label1";
            label1.Size = new Size(557, 140);
            label1.TabIndex = 0;
            label1.Text = "CALCULO DE NÓMINA \r\nDEL TRABAJADOR";
            label1.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // panel2
            // 
            panel2.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            panel2.BackColor = Color.Maroon;
            panel2.Location = new Point(668, 44);
            panel2.Name = "panel2";
            panel2.Size = new Size(116, 140);
            panel2.TabIndex = 3;
            // 
            // panel3
            // 
            panel3.BackColor = Color.WhiteSmoke;
            panel3.Controls.Add(label1);
            panel3.Controls.Add(panel2);
            panel3.Controls.Add(panel1);
            panel3.Dock = DockStyle.Top;
            panel3.Location = new Point(0, 0);
            panel3.Name = "panel3";
            panel3.Size = new Size(784, 215);
            panel3.TabIndex = 12;
            // 
            // buttonSave
            // 
            buttonSave.Anchor = AnchorStyles.None;
            buttonSave.BackColor = Color.Silver;
            buttonSave.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point);
            buttonSave.Location = new Point(230, 12);
            buttonSave.Name = "buttonSave";
            buttonSave.Size = new Size(340, 40);
            buttonSave.TabIndex = 13;
            buttonSave.Text = "Guardar el Registro del Empleado";
            buttonSave.UseVisualStyleBackColor = false;
            buttonSave.Click += buttonSave_Click;
            // 
            // buttonCalculate
            // 
            buttonCalculate.Anchor = AnchorStyles.None;
            buttonCalculate.BackColor = Color.RosyBrown;
            buttonCalculate.Font = new Font("Segoe UI", 14.25F, FontStyle.Bold, GraphicsUnit.Point);
            buttonCalculate.ForeColor = Color.Maroon;
            buttonCalculate.Location = new Point(230, 58);
            buttonCalculate.Name = "buttonCalculate";
            buttonCalculate.Size = new Size(340, 40);
            buttonCalculate.TabIndex = 14;
            buttonCalculate.Text = "Calcular Salario";
            buttonCalculate.UseVisualStyleBackColor = false;
            buttonCalculate.Click += buttonCalculate_Click;
            // 
            // panel4
            // 
            panel4.Anchor = AnchorStyles.Left | AnchorStyles.Right;
            panel4.BackColor = SystemColors.ButtonFace;
            panel4.Controls.Add(buttonCalculate);
            panel4.Controls.Add(buttonSave);
            panel4.Location = new Point(0, 511);
            panel4.Name = "panel4";
            panel4.Size = new Size(784, 111);
            panel4.TabIndex = 15;
            // 
            // buttonExit
            // 
            buttonExit.Anchor = AnchorStyles.None;
            buttonExit.BackColor = Color.Maroon;
            buttonExit.Font = new Font("Segoe UI", 14.25F, FontStyle.Bold, GraphicsUnit.Point);
            buttonExit.ForeColor = SystemColors.ButtonFace;
            buttonExit.Location = new Point(12, 709);
            buttonExit.Name = "buttonExit";
            buttonExit.Size = new Size(380, 40);
            buttonExit.TabIndex = 15;
            buttonExit.Text = "Salir";
            buttonExit.UseVisualStyleBackColor = false;
            buttonExit.Click += buttonExit_Click;
            // 
            // buttonNew
            // 
            buttonNew.Anchor = AnchorStyles.None;
            buttonNew.BackColor = Color.Silver;
            buttonNew.Font = new Font("Segoe UI", 14.25F, FontStyle.Bold, GraphicsUnit.Point);
            buttonNew.ForeColor = SystemColors.ActiveCaptionText;
            buttonNew.Location = new Point(392, 709);
            buttonNew.Name = "buttonNew";
            buttonNew.Size = new Size(380, 40);
            buttonNew.TabIndex = 16;
            buttonNew.Text = "Nuevo";
            buttonNew.UseVisualStyleBackColor = false;
            buttonNew.Click += buttonNew_Click;
            // 
            // label6
            // 
            label6.Anchor = AnchorStyles.None;
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label6.ForeColor = Color.Black;
            label6.Location = new Point(101, 650);
            label6.Name = "label6";
            label6.Size = new Size(236, 30);
            label6.TabIndex = 19;
            label6.Text = "Valor total devengado:";
            // 
            // textBoxTotal
            // 
            textBoxTotal.Anchor = AnchorStyles.None;
            textBoxTotal.Font = new Font("Segoe UI", 14.25F, FontStyle.Bold, GraphicsUnit.Point);
            textBoxTotal.ForeColor = Color.Maroon;
            textBoxTotal.Location = new Point(343, 651);
            textBoxTotal.Name = "textBoxTotal";
            textBoxTotal.ReadOnly = true;
            textBoxTotal.Size = new Size(318, 33);
            textBoxTotal.TabIndex = 20;
            // 
            // textBoxName
            // 
            textBoxName.Anchor = AnchorStyles.Top;
            textBoxName.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point);
            textBoxName.Location = new Point(343, 256);
            textBoxName.MaxLength = 50;
            textBoxName.Name = "textBoxName";
            textBoxName.Size = new Size(318, 33);
            textBoxName.TabIndex = 25;
            // 
            // textBoxIden
            // 
            textBoxIden.Anchor = AnchorStyles.Top;
            textBoxIden.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point);
            textBoxIden.Location = new Point(343, 316);
            textBoxIden.MaxLength = 15;
            textBoxIden.Name = "textBoxIden";
            textBoxIden.Size = new Size(318, 33);
            textBoxIden.TabIndex = 26;
            // 
            // label5
            // 
            label5.Anchor = AnchorStyles.Top;
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label5.ForeColor = Color.Black;
            label5.Location = new Point(174, 438);
            label5.Name = "label5";
            label5.Size = new Size(163, 30);
            label5.TabIndex = 24;
            label5.Text = "Días laborados:";
            // 
            // textBoxDays
            // 
            textBoxDays.Anchor = AnchorStyles.Top;
            textBoxDays.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point);
            textBoxDays.Location = new Point(343, 439);
            textBoxDays.MaxLength = 5;
            textBoxDays.Name = "textBoxDays";
            textBoxDays.Size = new Size(318, 33);
            textBoxDays.TabIndex = 28;
            // 
            // label4
            // 
            label4.Anchor = AnchorStyles.Top;
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.Black;
            label4.Location = new Point(103, 375);
            label4.Name = "label4";
            label4.Size = new Size(234, 30);
            label4.TabIndex = 23;
            label4.Text = "Asignación salario día:";
            // 
            // textBoxSalary
            // 
            textBoxSalary.Anchor = AnchorStyles.Top;
            textBoxSalary.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point);
            textBoxSalary.Location = new Point(343, 376);
            textBoxSalary.MaxLength = 10;
            textBoxSalary.Name = "textBoxSalary";
            textBoxSalary.Size = new Size(318, 33);
            textBoxSalary.TabIndex = 27;
            // 
            // label3
            // 
            label3.Anchor = AnchorStyles.Top;
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.Black;
            label3.Location = new Point(183, 315);
            label3.Name = "label3";
            label3.Size = new Size(154, 30);
            label3.TabIndex = 22;
            label3.Text = "Identificación:";
            // 
            // label2
            // 
            label2.Anchor = AnchorStyles.Top;
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 15.75F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.Black;
            label2.Location = new Point(237, 255);
            label2.Name = "label2";
            label2.Size = new Size(100, 30);
            label2.TabIndex = 21;
            label2.Text = "Nombre:";
            // 
            // errorProvider1
            // 
            errorProvider1.ContainerControl = this;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.Gainsboro;
            ClientSize = new Size(784, 761);
            Controls.Add(textBoxName);
            Controls.Add(textBoxIden);
            Controls.Add(label5);
            Controls.Add(textBoxDays);
            Controls.Add(label4);
            Controls.Add(textBoxSalary);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label6);
            Controls.Add(textBoxTotal);
            Controls.Add(buttonNew);
            Controls.Add(buttonExit);
            Controls.Add(panel3);
            Controls.Add(panel4);
            Icon = (Icon)resources.GetObject("$this.Icon");
            MinimumSize = new Size(800, 800);
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Nómina del Trabajador";
            panel3.ResumeLayout(false);
            panel4.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)errorProvider1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Panel panel1;
        private Label label1;
        private Panel panel2;
        private Panel panel3;
        private Button buttonSave;
        private Button buttonCalculate;
        private Panel panel4;
        private Button buttonExit;
        private Button buttonNew;
        private Label label6;
        private TextBox textBoxTotal;
        private TextBox textBoxName;
        private TextBox textBoxIden;
        private Label label5;
        private TextBox textBoxDays;
        private Label label4;
        private TextBox textBoxSalary;
        private Label label3;
        private Label label2;
        private ErrorProvider errorProvider1;
    }
}
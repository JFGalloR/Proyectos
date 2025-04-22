namespace EJERCICIO_JFGR
{
    partial class Ejercicio3
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Ejercicio3));
            Regresar = new Button();
            button3 = new Button();
            button2 = new Button();
            button1 = new Button();
            SuspendLayout();
            // 
            // Regresar
            // 
            Regresar.BackColor = Color.Black;
            Regresar.FlatAppearance.BorderSize = 0;
            Regresar.FlatAppearance.MouseOverBackColor = Color.DimGray;
            Regresar.FlatStyle = FlatStyle.Flat;
            Regresar.Font = new Font("Cascadia Code", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            Regresar.ForeColor = SystemColors.ButtonHighlight;
            Regresar.Location = new Point(12, 435);
            Regresar.Name = "Regresar";
            Regresar.Size = new Size(98, 32);
            Regresar.TabIndex = 11;
            Regresar.Text = "Regresar";
            Regresar.UseVisualStyleBackColor = false;
            Regresar.Click += Regresar_Click;
            // 
            // button3
            // 
            button3.BackColor = Color.DarkSeaGreen;
            button3.FlatAppearance.BorderSize = 0;
            button3.FlatAppearance.MouseDownBackColor = Color.Silver;
            button3.FlatAppearance.MouseOverBackColor = Color.White;
            button3.FlatStyle = FlatStyle.Flat;
            button3.Font = new Font("Cascadia Code", 99.75F, FontStyle.Bold, GraphicsUnit.Point);
            button3.ForeColor = Color.Green;
            button3.Location = new Point(593, 40);
            button3.Name = "button3";
            button3.Size = new Size(239, 355);
            button3.TabIndex = 17;
            button3.Text = "3";
            button3.TextAlign = ContentAlignment.BottomLeft;
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // button2
            // 
            button2.BackColor = Color.LightBlue;
            button2.FlatAppearance.BorderSize = 0;
            button2.FlatAppearance.MouseDownBackColor = Color.Silver;
            button2.FlatAppearance.MouseOverBackColor = Color.White;
            button2.FlatStyle = FlatStyle.Flat;
            button2.Font = new Font("Cascadia Code", 99.75F, FontStyle.Bold, GraphicsUnit.Point);
            button2.ForeColor = Color.DodgerBlue;
            button2.Location = new Point(318, 40);
            button2.Name = "button2";
            button2.Size = new Size(239, 355);
            button2.TabIndex = 16;
            button2.Text = "2";
            button2.TextAlign = ContentAlignment.BottomLeft;
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // button1
            // 
            button1.BackColor = Color.RosyBrown;
            button1.FlatAppearance.BorderSize = 0;
            button1.FlatAppearance.MouseDownBackColor = Color.Silver;
            button1.FlatAppearance.MouseOverBackColor = Color.White;
            button1.FlatStyle = FlatStyle.Flat;
            button1.Font = new Font("Cascadia Code", 99.75F, FontStyle.Bold, GraphicsUnit.Point);
            button1.ForeColor = Color.Firebrick;
            button1.Location = new Point(43, 40);
            button1.Name = "button1";
            button1.Size = new Size(239, 355);
            button1.TabIndex = 15;
            button1.Text = "1";
            button1.TextAlign = ContentAlignment.BottomLeft;
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // Ejercicio3
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.Gainsboro;
            ClientSize = new Size(876, 479);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(Regresar);
            Icon = (Icon)resources.GetObject("$this.Icon");
            Name = "Ejercicio3";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Ejercicio 3";
            FormClosed += Ejercicio3_FormClosed;
            ResumeLayout(false);
        }

        #endregion

        private Button Regresar;
        private Button button3;
        private Button button2;
        private Button button1;
    }
}
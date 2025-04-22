namespace Práctica_Archivos_Txt
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
            label1 = new Label();
            textBox1 = new TextBox();
            button1 = new Button();
            button2 = new Button();
            button3 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            label1.BackColor = Color.Firebrick;
            label1.Font = new Font("Cascadia Code", 20.25F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.Transparent;
            label1.Location = new Point(-1, 11);
            label1.Name = "label1";
            label1.Size = new Size(585, 102);
            label1.TabIndex = 0;
            label1.Text = "PROGRAMA GENERADOR DE \r\nARCHIVOS TEXT";
            label1.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // textBox1
            // 
            textBox1.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            textBox1.BackColor = Color.RosyBrown;
            textBox1.BorderStyle = BorderStyle.None;
            textBox1.Font = new Font("Segoe UI Semibold", 12F, FontStyle.Bold, GraphicsUnit.Point);
            textBox1.ForeColor = Color.Black;
            textBox1.Location = new Point(12, 123);
            textBox1.Multiline = true;
            textBox1.Name = "textBox1";
            textBox1.RightToLeft = RightToLeft.No;
            textBox1.ScrollBars = ScrollBars.Vertical;
            textBox1.Size = new Size(560, 385);
            textBox1.TabIndex = 1;
            textBox1.KeyPress += textBox1_KeyPress;
            // 
            // button1
            // 
            button1.Anchor = AnchorStyles.Bottom;
            button1.BackColor = Color.IndianRed;
            button1.FlatAppearance.BorderColor = Color.DarkRed;
            button1.FlatAppearance.BorderSize = 3;
            button1.FlatAppearance.MouseDownBackColor = Color.RosyBrown;
            button1.FlatAppearance.MouseOverBackColor = Color.Gainsboro;
            button1.FlatStyle = FlatStyle.Flat;
            button1.Font = new Font("Cascadia Code", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            button1.ForeColor = Color.DarkRed;
            button1.Location = new Point(12, 518);
            button1.Name = "button1";
            button1.Size = new Size(185, 32);
            button1.TabIndex = 2;
            button1.Text = "Agregar Info.";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.Anchor = AnchorStyles.Bottom;
            button2.BackColor = Color.IndianRed;
            button2.FlatAppearance.BorderColor = Color.DarkRed;
            button2.FlatAppearance.BorderSize = 3;
            button2.FlatAppearance.MouseDownBackColor = Color.RosyBrown;
            button2.FlatAppearance.MouseOverBackColor = Color.Gainsboro;
            button2.FlatStyle = FlatStyle.Flat;
            button2.Font = new Font("Cascadia Code", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            button2.ForeColor = Color.DarkRed;
            button2.Location = new Point(200, 518);
            button2.Name = "button2";
            button2.Size = new Size(185, 32);
            button2.TabIndex = 3;
            button2.Text = "Eliminar Txt";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Anchor = AnchorStyles.Bottom;
            button3.BackColor = Color.IndianRed;
            button3.FlatAppearance.BorderColor = Color.DarkRed;
            button3.FlatAppearance.BorderSize = 3;
            button3.FlatAppearance.MouseDownBackColor = Color.RosyBrown;
            button3.FlatAppearance.MouseOverBackColor = Color.Gainsboro;
            button3.FlatStyle = FlatStyle.Flat;
            button3.Font = new Font("Cascadia Code", 9.75F, FontStyle.Regular, GraphicsUnit.Point);
            button3.ForeColor = Color.DarkRed;
            button3.Location = new Point(387, 518);
            button3.Name = "button3";
            button3.Size = new Size(185, 32);
            button3.TabIndex = 4;
            button3.Text = "Mostrar Txt";
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(64, 0, 0);
            ClientSize = new Size(584, 561);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(textBox1);
            Controls.Add(label1);
            Icon = (Icon)resources.GetObject("$this.Icon");
            MinimumSize = new Size(600, 600);
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Archivos TXT";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private TextBox textBox1;
        private Button button1;
        private Button button2;
        private Button button3;
    }
}
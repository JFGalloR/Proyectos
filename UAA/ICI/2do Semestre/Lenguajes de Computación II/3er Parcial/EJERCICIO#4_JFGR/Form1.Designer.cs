namespace EJUERCICIO_JFGR
{
    partial class Calculadora
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Calculadora));
            textBox1 = new TextBox();
            Num_1 = new Button();
            Ce_btn = new Button();
            C_btn = new Button();
            Num_2 = new Button();
            Num_3 = new Button();
            Num_4 = new Button();
            Num_7 = new Button();
            Num_5 = new Button();
            Num_6 = new Button();
            Num_8 = new Button();
            Num_9 = new Button();
            div = new Button();
            mult = new Button();
            res = new Button();
            sum = new Button();
            igual = new Button();
            label1 = new Label();
            Num_0 = new Button();
            point = new Button();
            SuspendLayout();
            // 
            // textBox1
            // 
            textBox1.BackColor = Color.FromArgb(10, 10, 10);
            textBox1.BorderStyle = BorderStyle.None;
            textBox1.Font = new Font("Cascadia Code", 50.25F, FontStyle.Bold, GraphicsUnit.Point);
            textBox1.ForeColor = Color.White;
            textBox1.Location = new Point(12, 63);
            textBox1.MaxLength = 12;
            textBox1.Multiline = true;
            textBox1.Name = "textBox1";
            textBox1.RightToLeft = RightToLeft.No;
            textBox1.Size = new Size(335, 91);
            textBox1.TabIndex = 0;
            textBox1.Text = "0";
            textBox1.TextChanged += textBox1_TextChanged;
            textBox1.KeyPress += textBox1_KeyPress;
            // 
            // Num_1
            // 
            Num_1.BackColor = Color.White;
            Num_1.FlatAppearance.BorderSize = 0;
            Num_1.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_1.FlatStyle = FlatStyle.Flat;
            Num_1.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_1.Location = new Point(12, 363);
            Num_1.Name = "Num_1";
            Num_1.Size = new Size(70, 70);
            Num_1.TabIndex = 1;
            Num_1.Text = "1";
            Num_1.UseVisualStyleBackColor = false;
            Num_1.Click += ButtonNumero_Click;
            // 
            // Ce_btn
            // 
            Ce_btn.BackColor = Color.Gainsboro;
            Ce_btn.FlatAppearance.BorderSize = 0;
            Ce_btn.FlatAppearance.MouseOverBackColor = Color.Gray;
            Ce_btn.FlatStyle = FlatStyle.Flat;
            Ce_btn.Font = new Font("Cascadia Code", 18F, FontStyle.Bold, GraphicsUnit.Point);
            Ce_btn.Location = new Point(12, 160);
            Ce_btn.Name = "Ce_btn";
            Ce_btn.Size = new Size(108, 45);
            Ce_btn.TabIndex = 11;
            Ce_btn.Text = "CE";
            Ce_btn.UseVisualStyleBackColor = false;
            Ce_btn.Click += Ce_btn_Click;
            // 
            // C_btn
            // 
            C_btn.BackColor = Color.Gainsboro;
            C_btn.FlatAppearance.BorderSize = 0;
            C_btn.FlatAppearance.MouseOverBackColor = Color.Gray;
            C_btn.FlatStyle = FlatStyle.Flat;
            C_btn.Font = new Font("Cascadia Code", 18F, FontStyle.Bold, GraphicsUnit.Point);
            C_btn.Location = new Point(126, 160);
            C_btn.Name = "C_btn";
            C_btn.Size = new Size(108, 45);
            C_btn.TabIndex = 12;
            C_btn.Text = "C";
            C_btn.UseVisualStyleBackColor = false;
            C_btn.Click += C_btn_Click;
            // 
            // Num_2
            // 
            Num_2.BackColor = Color.White;
            Num_2.FlatAppearance.BorderSize = 0;
            Num_2.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_2.FlatStyle = FlatStyle.Flat;
            Num_2.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_2.Location = new Point(88, 363);
            Num_2.Name = "Num_2";
            Num_2.Size = new Size(70, 70);
            Num_2.TabIndex = 19;
            Num_2.Text = "2";
            Num_2.UseVisualStyleBackColor = false;
            Num_2.Click += ButtonNumero_Click;
            // 
            // Num_3
            // 
            Num_3.BackColor = Color.White;
            Num_3.FlatAppearance.BorderSize = 0;
            Num_3.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_3.FlatStyle = FlatStyle.Flat;
            Num_3.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_3.Location = new Point(164, 363);
            Num_3.Name = "Num_3";
            Num_3.Size = new Size(70, 70);
            Num_3.TabIndex = 20;
            Num_3.Text = "3";
            Num_3.UseVisualStyleBackColor = false;
            Num_3.Click += ButtonNumero_Click;
            // 
            // Num_4
            // 
            Num_4.BackColor = Color.White;
            Num_4.FlatAppearance.BorderSize = 0;
            Num_4.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_4.FlatStyle = FlatStyle.Flat;
            Num_4.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_4.Location = new Point(12, 287);
            Num_4.Name = "Num_4";
            Num_4.Size = new Size(70, 70);
            Num_4.TabIndex = 21;
            Num_4.Text = "4";
            Num_4.UseVisualStyleBackColor = false;
            Num_4.Click += ButtonNumero_Click;
            // 
            // Num_7
            // 
            Num_7.BackColor = Color.White;
            Num_7.FlatAppearance.BorderSize = 0;
            Num_7.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_7.FlatStyle = FlatStyle.Flat;
            Num_7.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_7.Location = new Point(12, 211);
            Num_7.Name = "Num_7";
            Num_7.Size = new Size(70, 70);
            Num_7.TabIndex = 22;
            Num_7.Text = "7";
            Num_7.UseVisualStyleBackColor = false;
            Num_7.Click += ButtonNumero_Click;
            // 
            // Num_5
            // 
            Num_5.BackColor = Color.White;
            Num_5.FlatAppearance.BorderSize = 0;
            Num_5.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_5.FlatStyle = FlatStyle.Flat;
            Num_5.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_5.Location = new Point(88, 287);
            Num_5.Name = "Num_5";
            Num_5.Size = new Size(70, 70);
            Num_5.TabIndex = 23;
            Num_5.Text = "5";
            Num_5.UseVisualStyleBackColor = false;
            Num_5.Click += ButtonNumero_Click;
            // 
            // Num_6
            // 
            Num_6.BackColor = Color.White;
            Num_6.FlatAppearance.BorderSize = 0;
            Num_6.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_6.FlatStyle = FlatStyle.Flat;
            Num_6.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_6.Location = new Point(164, 287);
            Num_6.Name = "Num_6";
            Num_6.Size = new Size(70, 70);
            Num_6.TabIndex = 24;
            Num_6.Text = "6";
            Num_6.UseVisualStyleBackColor = false;
            Num_6.Click += ButtonNumero_Click;
            // 
            // Num_8
            // 
            Num_8.BackColor = Color.White;
            Num_8.FlatAppearance.BorderSize = 0;
            Num_8.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_8.FlatStyle = FlatStyle.Flat;
            Num_8.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_8.Location = new Point(88, 211);
            Num_8.Name = "Num_8";
            Num_8.Size = new Size(70, 70);
            Num_8.TabIndex = 25;
            Num_8.Text = "8";
            Num_8.UseVisualStyleBackColor = false;
            Num_8.Click += ButtonNumero_Click;
            // 
            // Num_9
            // 
            Num_9.BackColor = Color.White;
            Num_9.FlatAppearance.BorderSize = 0;
            Num_9.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_9.FlatStyle = FlatStyle.Flat;
            Num_9.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_9.Location = new Point(164, 211);
            Num_9.Name = "Num_9";
            Num_9.Size = new Size(70, 70);
            Num_9.TabIndex = 26;
            Num_9.Text = "9";
            Num_9.UseVisualStyleBackColor = false;
            Num_9.Click += ButtonNumero_Click;
            // 
            // div
            // 
            div.BackColor = Color.Gainsboro;
            div.FlatAppearance.BorderSize = 0;
            div.FlatAppearance.MouseOverBackColor = Color.Gray;
            div.FlatStyle = FlatStyle.Flat;
            div.Font = new Font("Cascadia Code", 18F, FontStyle.Bold, GraphicsUnit.Point);
            div.Location = new Point(240, 160);
            div.Name = "div";
            div.Size = new Size(107, 45);
            div.TabIndex = 14;
            div.Text = "/";
            div.UseVisualStyleBackColor = false;
            div.Click += ButtonOperador_Click;
            // 
            // mult
            // 
            mult.BackColor = Color.Gainsboro;
            mult.FlatAppearance.BorderSize = 0;
            mult.FlatAppearance.MouseOverBackColor = Color.Gray;
            mult.FlatStyle = FlatStyle.Flat;
            mult.Font = new Font("Cascadia Code", 18F, FontStyle.Bold, GraphicsUnit.Point);
            mult.Location = new Point(240, 211);
            mult.Name = "mult";
            mult.Size = new Size(107, 45);
            mult.TabIndex = 27;
            mult.Text = "*";
            mult.UseVisualStyleBackColor = false;
            mult.Click += ButtonOperador_Click;
            // 
            // res
            // 
            res.BackColor = Color.Gainsboro;
            res.FlatAppearance.BorderSize = 0;
            res.FlatAppearance.MouseOverBackColor = Color.Gray;
            res.FlatStyle = FlatStyle.Flat;
            res.Font = new Font("Cascadia Code", 18F, FontStyle.Bold, GraphicsUnit.Point);
            res.Location = new Point(240, 262);
            res.Name = "res";
            res.Size = new Size(107, 45);
            res.TabIndex = 28;
            res.Text = "-";
            res.UseVisualStyleBackColor = false;
            res.Click += ButtonOperador_Click;
            // 
            // sum
            // 
            sum.BackColor = Color.Gainsboro;
            sum.FlatAppearance.BorderSize = 0;
            sum.FlatAppearance.MouseOverBackColor = Color.Gray;
            sum.FlatStyle = FlatStyle.Flat;
            sum.Font = new Font("Cascadia Code", 18F, FontStyle.Bold, GraphicsUnit.Point);
            sum.Location = new Point(240, 313);
            sum.Name = "sum";
            sum.Size = new Size(107, 44);
            sum.TabIndex = 29;
            sum.Text = "+";
            sum.UseVisualStyleBackColor = false;
            sum.Click += ButtonOperador_Click;
            // 
            // igual
            // 
            igual.BackColor = Color.DarkGray;
            igual.FlatAppearance.BorderSize = 0;
            igual.FlatAppearance.MouseOverBackColor = Color.Gray;
            igual.FlatStyle = FlatStyle.Flat;
            igual.Font = new Font("Cascadia Code", 18F, FontStyle.Bold, GraphicsUnit.Point);
            igual.Location = new Point(240, 363);
            igual.Name = "igual";
            igual.Size = new Size(107, 146);
            igual.TabIndex = 30;
            igual.Text = "=";
            igual.UseVisualStyleBackColor = false;
            igual.Click += igual_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Cascadia Code SemiLight", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = SystemColors.ButtonShadow;
            label1.Location = new Point(12, 25);
            label1.Name = "label1";
            label1.RightToLeft = RightToLeft.No;
            label1.Size = new Size(0, 35);
            label1.TabIndex = 31;
            label1.TextAlign = ContentAlignment.MiddleLeft;
            // 
            // Num_0
            // 
            Num_0.BackColor = Color.White;
            Num_0.FlatAppearance.BorderSize = 0;
            Num_0.FlatAppearance.MouseOverBackColor = Color.Gray;
            Num_0.FlatStyle = FlatStyle.Flat;
            Num_0.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            Num_0.Location = new Point(12, 439);
            Num_0.Name = "Num_0";
            Num_0.Size = new Size(146, 70);
            Num_0.TabIndex = 32;
            Num_0.Text = "0";
            Num_0.UseVisualStyleBackColor = false;
            Num_0.Click += ButtonNumero_Click;
            // 
            // point
            // 
            point.BackColor = Color.White;
            point.FlatAppearance.BorderSize = 0;
            point.FlatAppearance.MouseOverBackColor = Color.Gray;
            point.FlatStyle = FlatStyle.Flat;
            point.Font = new Font("Cascadia Code", 20.25F, FontStyle.Regular, GraphicsUnit.Point);
            point.Location = new Point(164, 439);
            point.Name = "point";
            point.Size = new Size(70, 70);
            point.TabIndex = 33;
            point.Text = ".";
            point.UseVisualStyleBackColor = false;
            point.Click += ButtonNumero_Click;
            // 
            // Calculadora
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(10, 10, 10);
            ClientSize = new Size(359, 521);
            Controls.Add(point);
            Controls.Add(Num_0);
            Controls.Add(label1);
            Controls.Add(igual);
            Controls.Add(sum);
            Controls.Add(res);
            Controls.Add(mult);
            Controls.Add(Num_9);
            Controls.Add(Num_8);
            Controls.Add(Num_6);
            Controls.Add(Num_5);
            Controls.Add(Num_7);
            Controls.Add(Num_4);
            Controls.Add(Num_3);
            Controls.Add(Num_2);
            Controls.Add(div);
            Controls.Add(C_btn);
            Controls.Add(Ce_btn);
            Controls.Add(Num_1);
            Controls.Add(textBox1);
            Cursor = Cursors.Hand;
            Font = new Font("Segoe UI", 9F, FontStyle.Regular, GraphicsUnit.Point);
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximizeBox = false;
            MaximumSize = new Size(375, 560);
            MinimumSize = new Size(375, 560);
            Name = "Calculadora";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Calculadora";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox textBox1;
        private Label label1;
        private Button Ce_btn;
        private Button C_btn;
        private Button Num_0;
        private Button Num_1;
        private Button Num_2;
        private Button Num_3;
        private Button Num_4;
        private Button Num_7;
        private Button Num_5;
        private Button Num_6;
        private Button Num_8;
        private Button Num_9;
        private Button point;
        private Button sum;
        private Button res;
        private Button mult;
        private Button div;
        private Button igual;
    }
}
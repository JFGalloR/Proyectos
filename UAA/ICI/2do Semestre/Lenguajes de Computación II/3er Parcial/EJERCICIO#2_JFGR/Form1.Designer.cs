namespace EJERCICIO_JFGR
{
    partial class Menu
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Menu));
            label1 = new Label();
            Ejercicio_1 = new Button();
            Ejercicio_3 = new Button();
            Ejercicio_2 = new Button();
            label2 = new Label();
            SuspendLayout();
            // 
            // label1
            // 
            label1.Anchor = AnchorStyles.None;
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Cascadia Code", 48F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = SystemColors.ButtonHighlight;
            label1.Location = new Point(233, 45);
            label1.Name = "label1";
            label1.Size = new Size(417, 85);
            label1.TabIndex = 0;
            label1.Text = "EJERCICIOS";
            label1.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // Ejercicio_1
            // 
            Ejercicio_1.Anchor = AnchorStyles.None;
            Ejercicio_1.AutoSize = true;
            Ejercicio_1.BackColor = SystemColors.ButtonHighlight;
            Ejercicio_1.BackgroundImageLayout = ImageLayout.Center;
            Ejercicio_1.Cursor = Cursors.Hand;
            Ejercicio_1.FlatAppearance.BorderSize = 0;
            Ejercicio_1.FlatAppearance.MouseDownBackColor = SystemColors.ActiveBorder;
            Ejercicio_1.FlatAppearance.MouseOverBackColor = Color.Firebrick;
            Ejercicio_1.FlatStyle = FlatStyle.Flat;
            Ejercicio_1.Font = new Font("Cascadia Code", 14.25F, FontStyle.Regular, GraphicsUnit.Point);
            Ejercicio_1.ForeColor = SystemColors.ControlText;
            Ejercicio_1.Location = new Point(158, 170);
            Ejercicio_1.Name = "Ejercicio_1";
            Ejercicio_1.Size = new Size(566, 46);
            Ejercicio_1.TabIndex = 1;
            Ejercicio_1.Text = "Ejercicio #1";
            Ejercicio_1.UseVisualStyleBackColor = false;
            Ejercicio_1.Click += Ejercicio_1_Click;
            Ejercicio_1.MouseLeave += Ejercicio_1_MouseLeave;
            Ejercicio_1.MouseMove += Ejercicio_1_MouseMove;
            // 
            // Ejercicio_3
            // 
            Ejercicio_3.Anchor = AnchorStyles.None;
            Ejercicio_3.AutoSize = true;
            Ejercicio_3.BackColor = SystemColors.ButtonHighlight;
            Ejercicio_3.BackgroundImageLayout = ImageLayout.Center;
            Ejercicio_3.Cursor = Cursors.Hand;
            Ejercicio_3.FlatAppearance.BorderSize = 0;
            Ejercicio_3.FlatAppearance.MouseDownBackColor = SystemColors.ActiveBorder;
            Ejercicio_3.FlatAppearance.MouseOverBackColor = Color.Green;
            Ejercicio_3.FlatStyle = FlatStyle.Flat;
            Ejercicio_3.Font = new Font("Cascadia Code", 14.25F, FontStyle.Regular, GraphicsUnit.Point);
            Ejercicio_3.Location = new Point(158, 274);
            Ejercicio_3.Name = "Ejercicio_3";
            Ejercicio_3.Size = new Size(566, 46);
            Ejercicio_3.TabIndex = 3;
            Ejercicio_3.Text = "Ejercicio #3";
            Ejercicio_3.UseVisualStyleBackColor = false;
            Ejercicio_3.Click += Ejercicio_3_Click;
            Ejercicio_3.MouseLeave += Ejercicio_3_MouseLeave;
            Ejercicio_3.MouseMove += Ejercicio_3_MouseMove;
            // 
            // Ejercicio_2
            // 
            Ejercicio_2.Anchor = AnchorStyles.None;
            Ejercicio_2.AutoSize = true;
            Ejercicio_2.BackColor = SystemColors.ButtonHighlight;
            Ejercicio_2.BackgroundImageLayout = ImageLayout.Center;
            Ejercicio_2.Cursor = Cursors.Hand;
            Ejercicio_2.FlatAppearance.BorderSize = 0;
            Ejercicio_2.FlatAppearance.MouseDownBackColor = SystemColors.ActiveBorder;
            Ejercicio_2.FlatAppearance.MouseOverBackColor = Color.DodgerBlue;
            Ejercicio_2.FlatStyle = FlatStyle.Flat;
            Ejercicio_2.Font = new Font("Cascadia Code", 14.25F, FontStyle.Regular, GraphicsUnit.Point);
            Ejercicio_2.ForeColor = SystemColors.ControlText;
            Ejercicio_2.Location = new Point(158, 222);
            Ejercicio_2.Name = "Ejercicio_2";
            Ejercicio_2.Size = new Size(566, 46);
            Ejercicio_2.TabIndex = 4;
            Ejercicio_2.Text = "Ejercicio #2";
            Ejercicio_2.UseVisualStyleBackColor = false;
            Ejercicio_2.Click += Ejercicio_2_Click;
            Ejercicio_2.MouseLeave += Ejercicio_2_MouseLeave;
            Ejercicio_2.MouseMove += Ejercicio_2_MouseMove;
            // 
            // label2
            // 
            label2.BackColor = Color.Transparent;
            label2.Font = new Font("Cascadia Code", 9F, FontStyle.Italic, GraphicsUnit.Point);
            label2.ForeColor = SystemColors.ActiveBorder;
            label2.Location = new Point(158, 336);
            label2.Name = "label2";
            label2.Size = new Size(566, 76);
            label2.TabIndex = 5;
            label2.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // Menu
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            AutoSizeMode = AutoSizeMode.GrowAndShrink;
            BackColor = SystemColors.ActiveCaptionText;
            ClientSize = new Size(876, 479);
            Controls.Add(label2);
            Controls.Add(Ejercicio_2);
            Controls.Add(Ejercicio_3);
            Controls.Add(Ejercicio_1);
            Controls.Add(label1);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            HelpButton = true;
            Icon = (Icon)resources.GetObject("$this.Icon");
            MaximumSize = new Size(892, 518);
            MinimumSize = new Size(892, 518);
            Name = "Menu";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Ejercicios";
            FormClosed += Menu_FormClosed;
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Button Ejercicio_1;
        private Button Ejercicio_3;
        private Button Ejercicio_2;
        private Label label2;
    }
}
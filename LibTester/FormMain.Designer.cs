namespace TestCallingC
{
	partial class FormMain
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
			if(disposing && (components != null))
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
			this.panel1 = new System.Windows.Forms.Panel();
			this.label1 = new System.Windows.Forms.Label();
			this.panelButtons = new System.Windows.Forms.Panel();
			this.cbxRoutine = new System.Windows.Forms.ComboBox();
			this.btnTest = new LeerSoft.Tools.LeerButton();
			this.panel2 = new System.Windows.Forms.Panel();
			this.txtString = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.txtResult = new System.Windows.Forms.TextBox();
			this.leerSkin1 = new LeerSoft.Tools.LeerSkin();
			this.panel1.SuspendLayout();
			this.panelButtons.SuspendLayout();
			this.panel2.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.leerSkin1)).BeginInit();
			this.SuspendLayout();
			// 
			// panel1
			// 
			this.panel1.Controls.Add(this.label1);
			this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
			this.panel1.Location = new System.Drawing.Point(0, 0);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(934, 76);
			this.panel1.TabIndex = 0;
			// 
			// label1
			// 
			this.label1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.Location = new System.Drawing.Point(0, 0);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(934, 76);
			this.label1.TabIndex = 0;
			this.label1.Text = "Test App to Call C++ Code";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// panelButtons
			// 
			this.panelButtons.Controls.Add(this.cbxRoutine);
			this.panelButtons.Controls.Add(this.btnTest);
			this.panelButtons.Dock = System.Windows.Forms.DockStyle.Bottom;
			this.panelButtons.Location = new System.Drawing.Point(0, 524);
			this.panelButtons.Name = "panelButtons";
			this.panelButtons.Size = new System.Drawing.Size(934, 134);
			this.panelButtons.TabIndex = 1;
			// 
			// cbxRoutine
			// 
			this.cbxRoutine.BackColor = System.Drawing.Color.White;
			this.cbxRoutine.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbxRoutine.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.cbxRoutine.FormattingEnabled = true;
			this.cbxRoutine.Items.AddRange(new object[] {
            "DateTimeUtc"});
			this.cbxRoutine.Location = new System.Drawing.Point(89, 9);
			this.cbxRoutine.Name = "cbxRoutine";
			this.cbxRoutine.Size = new System.Drawing.Size(233, 28);
			this.cbxRoutine.TabIndex = 1;
			// 
			// btnTest
			// 
			this.btnTest.AccessibleRole = System.Windows.Forms.AccessibleRole.PushButton;
			this.btnTest.BackColor = System.Drawing.SystemColors.Control;
			this.btnTest.BorderColor = System.Drawing.Color.Black;
			this.btnTest.DisabledColor = System.Drawing.Color.FromArgb(((int)(((byte)(180)))), ((int)(((byte)(177)))), ((int)(((byte)(163)))));
			this.btnTest.DropArrowImage = ((System.Drawing.Image)(resources.GetObject("btnTest.DropArrowImage")));
			this.btnTest.FlatStyle = LeerSoft.Tools.LeerFlatStyle.ThreeD;
			this.btnTest.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnTest.HighlightColor = System.Drawing.Color.LightGray;
			this.btnTest.ImageAlign = System.Drawing.ContentAlignment.MiddleCenter;
			this.btnTest.LeerToolTip = null;
			this.btnTest.Location = new System.Drawing.Point(8, 6);
			this.btnTest.Name = "btnTest";
			this.btnTest.Orientation = LeerSoft.Tools.Orientation.Vertical;
			this.btnTest.Size = new System.Drawing.Size(66, 33);
			this.btnTest.Style = LeerSoft.Tools.LeerButtonStyle.PushButton;
			this.btnTest.TabIndex = 0;
			this.btnTest.Text = "Test";
			this.btnTest.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			this.btnTest.TextPadding.Bottom = 0;
			this.btnTest.TextPadding.Left = 0;
			this.btnTest.TextPadding.Right = 0;
			this.btnTest.TextPadding.Top = 0;
			this.btnTest.Click += new System.EventHandler(this.btnTest_Click);
			// 
			// panel2
			// 
			this.panel2.BackColor = System.Drawing.Color.White;
			this.panel2.Controls.Add(this.txtString);
			this.panel2.Controls.Add(this.label2);
			this.panel2.Controls.Add(this.txtResult);
			this.panel2.Dock = System.Windows.Forms.DockStyle.Fill;
			this.panel2.Location = new System.Drawing.Point(0, 76);
			this.panel2.Name = "panel2";
			this.panel2.Size = new System.Drawing.Size(934, 448);
			this.panel2.TabIndex = 2;
			// 
			// txtString
			// 
			this.txtString.Dock = System.Windows.Forms.DockStyle.Fill;
			this.txtString.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txtString.Location = new System.Drawing.Point(0, 25);
			this.txtString.Multiline = true;
			this.txtString.Name = "txtString";
			this.txtString.Size = new System.Drawing.Size(934, 170);
			this.txtString.TabIndex = 2;
			// 
			// label2
			// 
			this.label2.Dock = System.Windows.Forms.DockStyle.Top;
			this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.Location = new System.Drawing.Point(0, 0);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(934, 25);
			this.label2.TabIndex = 1;
			this.label2.Text = "Input data, if any:";
			// 
			// txtResult
			// 
			this.txtResult.Dock = System.Windows.Forms.DockStyle.Bottom;
			this.txtResult.Location = new System.Drawing.Point(0, 195);
			this.txtResult.Multiline = true;
			this.txtResult.Name = "txtResult";
			this.txtResult.Size = new System.Drawing.Size(934, 253);
			this.txtResult.TabIndex = 0;
			// 
			// leerSkin1
			// 
			this.leerSkin1.BackColor = System.Drawing.SystemColors.Control;
			this.leerSkin1.BorderColor = System.Drawing.Color.Black;
			this.leerSkin1.ButtonColor = System.Drawing.Color.SandyBrown;
			this.leerSkin1.ButtonDisabledColor = System.Drawing.Color.FromArgb(((int)(((byte)(180)))), ((int)(((byte)(177)))), ((int)(((byte)(163)))));
			this.leerSkin1.CustomButtonBackColor = System.Drawing.Color.Transparent;
			this.leerSkin1.CustomButtonDisabledImage = null;
			this.leerSkin1.CustomButtonFont = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Bold);
			this.leerSkin1.CustomButtonHiliteImage = null;
			this.leerSkin1.CustomButtonPressedImage = null;
			this.leerSkin1.CustomButtonTextColor = System.Drawing.SystemColors.Control;
			this.leerSkin1.CustomButtonUnpressedImage = null;
			this.leerSkin1.CustomColors = new System.Drawing.Color[] {
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White,
        System.Drawing.Color.White};
			this.leerSkin1.GridViewAltRowBackColor = System.Drawing.Color.White;
			this.leerSkin1.GridViewAltRowTextColor = System.Drawing.Color.Black;
			this.leerSkin1.GridViewHeaderBackColor = System.Drawing.Color.Gray;
			this.leerSkin1.GridViewHeaderFont = new System.Drawing.Font("Microsoft Sans Serif", 7.8F);
			this.leerSkin1.GridViewHeaderTextColor = System.Drawing.Color.Black;
			this.leerSkin1.GridViewHighlightColor = System.Drawing.Color.LightBlue;
			this.leerSkin1.GridViewRowBackColor = System.Drawing.Color.White;
			this.leerSkin1.GridViewRowTextColor = System.Drawing.Color.Black;
			this.leerSkin1.HighlightColor = System.Drawing.Color.LightGray;
			this.leerSkin1.ListViewBackColor = System.Drawing.Color.White;
			this.leerSkin1.ListViewTextColor = System.Drawing.Color.Black;
			this.leerSkin1.MenuBackColor = System.Drawing.Color.White;
			this.leerSkin1.MenuHighlightBackColor = System.Drawing.Color.LightGray;
			this.leerSkin1.MenuHighlightTextColor = System.Drawing.Color.Black;
			this.leerSkin1.MenuPopupBackColor = System.Drawing.Color.White;
			this.leerSkin1.MenuPopupTextColor = System.Drawing.Color.Black;
			this.leerSkin1.MenuSelectedBackColor = System.Drawing.Color.LightGray;
			this.leerSkin1.MenuSelectedTextColor = System.Drawing.Color.Black;
			this.leerSkin1.MenuTextColor = System.Drawing.Color.Black;
			this.leerSkin1.PictureBoxBackColor = System.Drawing.SystemColors.Control;
			this.leerSkin1.ProgressColor = System.Drawing.Color.Blue;
			this.leerSkin1.TabBackColor = System.Drawing.SystemColors.Control;
			this.leerSkin1.TabButtonDisabledColor = System.Drawing.Color.LightGray;
			this.leerSkin1.TabButtonEnabledColor = System.Drawing.Color.Black;
			this.leerSkin1.TabFont = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.leerSkin1.TabHighlightBackColor = System.Drawing.SystemColors.Control;
			this.leerSkin1.TabHighlightTextColor = System.Drawing.SystemColors.InactiveCaptionText;
			this.leerSkin1.TabInactiveBackColor = System.Drawing.SystemColors.Control;
			this.leerSkin1.TabInactiveTextColor = System.Drawing.SystemColors.InactiveCaptionText;
			this.leerSkin1.TabSelectedBackColor = System.Drawing.SystemColors.ControlDark;
			this.leerSkin1.TabSelectedTextColor = System.Drawing.SystemColors.ControlText;
			this.leerSkin1.TextColor = System.Drawing.Color.Black;
			this.leerSkin1.TextFont = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.leerSkin1.TreeViewBackColor = System.Drawing.Color.White;
			this.leerSkin1.TreeViewTextColor = System.Drawing.Color.Black;
			this.leerSkin1.UseDefaultFont = true;
			// 
			// FormMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.Linen;
			this.ClientSize = new System.Drawing.Size(934, 658);
			this.Controls.Add(this.panel2);
			this.Controls.Add(this.panelButtons);
			this.Controls.Add(this.panel1);
			this.Name = "FormMain";
			this.Text = "Test To Call C Library";
			this.Load += new System.EventHandler(this.FormMain_Load);
			this.panel1.ResumeLayout(false);
			this.panelButtons.ResumeLayout(false);
			this.panel2.ResumeLayout(false);
			this.panel2.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.leerSkin1)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Panel panel1;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Panel panelButtons;
		private LeerSoft.Tools.LeerButton btnTest;
		private System.Windows.Forms.Panel panel2;
		private System.Windows.Forms.TextBox txtString;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox txtResult;
		private LeerSoft.Tools.LeerSkin leerSkin1;
		private System.Windows.Forms.ComboBox cbxRoutine;
	}
}


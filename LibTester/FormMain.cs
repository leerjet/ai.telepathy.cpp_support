using System;
using System.Collections;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;
using LeerSoft.Tools;

namespace TestCallingC
{
	public partial class FormMain : Form
	{
		[DllImport("Support.dll", EntryPoint = "DateNowUtc", CallingConvention = CallingConvention.Cdecl)]
		public static extern void DateNowUtc(StringBuilder strDate, int nLen);

		[DllImport("Support.dll", EntryPoint = "DateToString", CallingConvention = CallingConvention.Cdecl)]
		public static extern void DateToString(StringBuilder strDate, int nLen);

		[DllImport("Support.dll", EntryPoint = "DateToStringUtc", CallingConvention = CallingConvention.Cdecl)]
		public static extern void DateToStringUtc(StringBuilder strDate, int nLen);

		[DllImport("Support.dll", EntryPoint = "JsonEscapeString", CallingConvention = CallingConvention.Cdecl)]
		public static extern void JsonEscapeString(StringBuilder strJson, int nLen);

		[DllImport("Support.dll", EntryPoint = "StepThroughTests", CallingConvention = CallingConvention.Cdecl)]
		public static extern void StepThroughTests(StringBuilder strDate, int nLen);

		[DllImport("Support.dll", EntryPoint = "StringBuilder", CallingConvention = CallingConvention.Cdecl)]
		public static extern void StringBuilderC(StringBuilder strDate, int nLen);

		[DllImport("Support.dll", EntryPoint = "StringReplace", CallingConvention = CallingConvention.Cdecl)]
		public static extern void StringReplace(StringBuilder strDate, int nLen, StringBuilder cOrig, StringBuilder cNew);

		[DllImport("Support.dll", EntryPoint = "StringReplaceStr", CallingConvention = CallingConvention.Cdecl)]
		public static extern void StringReplaceStr(StringBuilder strDate, int nLen, StringBuilder strOrig, StringBuilder strNew);

		[DllImport("Support.dll", EntryPoint = "StringReplaceUtf8", CallingConvention = CallingConvention.Cdecl)]
		public static extern void StringReplaceUtf8(StringBuilder strDate, int nLen, StringBuilder cOrig, StringBuilder cNew);

		public FormMain()
		{
			InitializeComponent();
		}

		private void btnTest_Click(object sender, EventArgs e)
		{
			String strResults = "";
			String strMethod = cbxRoutine.Text.Trim();
			int nIdx = strMethod.IndexOf(' ');
			if(nIdx >= 0)
			{
				strMethod = strMethod.Substring(0, nIdx);
			}
			StringBuilder sb;
			StringBuilder sbOrig;
			StringBuilder sbNew;

			switch(strMethod)
			{
				case "DateNowUtc":
					sb = new StringBuilder(20);
					DateNowUtc(sb, 20);
					strResults = sb.ToString();
					break;

				case "DateToString":
					sb = new StringBuilder(20);
					DateToString(sb, 20);
					strResults = sb.ToString();
					break;

				case "DateToStringUtc":
					sb = new StringBuilder(20);
					DateToStringUtc(sb, 20);
					strResults = sb.ToString();
					break;

				case "JsonEscapeString":
					sb = new StringBuilder(20);
					sb.Append("A\\B\\C\\D\\");
					txtString.Text = sb.ToString();
					JsonEscapeString(sb, 20);
					strResults = sb.ToString();
					break;

				case "StepThroughTests":
					sb = new StringBuilder(10000);
					StepThroughTests(sb, 10000);
					strResults = sb.ToString();
					break;

				case "StringBuilder":
					sb = new StringBuilder(10000);
					StringBuilderC(sb, 10000);
					strResults = sb.ToString();
					break;

				case "StringReplace":
					sb = new StringBuilder(40);
					sb.Append(txtString.Text);
					sbOrig = new StringBuilder("a");
					sbNew = new StringBuilder("z");
					StringReplace(sb, 40, sbOrig, sbNew);
					strResults = sb.ToString();
					break;

				case "StringReplaceStr":
					sb = new StringBuilder(40);
					sb.Append(txtString.Text);
					sbOrig = new StringBuilder("old");
					sbNew = new StringBuilder("new");
					StringReplaceStr(sb, 40, sbOrig, sbNew);
					strResults = sb.ToString();
					break;

				case "StringReplaceUtf8":
					sb = new StringBuilder(20);
					sb.Append(txtString.Text);
					sbOrig = new StringBuilder("a");
					sbNew = new StringBuilder("z");
					StringReplaceUtf8(sb, 20, sbOrig, sbNew);
					strResults = sb.ToString();
					break;
			}
			txtResult.Text = strResults;
		}

		/// <summary>
		/// Main form loaded
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void FormMain_Load(object sender, EventArgs e)
		{
			LeerSoft.Tools.Methods.PropogateSkin(this, leerSkin1);

			// Fill _alTests with strings matching Methods to call

			cbxRoutine.Items.Clear();
			cbxRoutine.Items.AddRange(new String[]{
								"DateNowUtc",
								"DateToString",
								"DateToStringUtc",
								"JsonEscapeString",
								"StepThroughTests",
								"StringBuilder",
								"StringReplace : a->z",
								"StringReplaceStr : old->new",
								"StringReplaceUtf8 : a->z"
							});
			cbxRoutine.SelectedIndex = 0;
		}
	}
}

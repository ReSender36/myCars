//---------------------------------------------------------------------------

#ifndef Refueling_UnitH
#define Refueling_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TRefueling_Form : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TEdit *Edit14;
	TEdit *Edit15;
	TEdit *Edit16;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TEdit *Edit3;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TDateTimePicker *DateTimePicker1;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label17;
	TADOQuery *ADOQuery1;
	TComboBox *ComboBox3;
	TComboBox *ComboBox4;
	TLabel *Label18;
	TLabel *Label19;
	TADOCommand *ADOCommand1;
	TCheckBox *CheckBox1;
	TEdit *Edit10;
	TLabel *Label21;
	TLabel *Label22;
	TEdit *Edit18;
	TEdit *Edit19;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	TCheckBox *CheckBox9;
	TCheckBox *CheckBox10;
	TCheckBox *CheckBox11;
	TEdit *Edit20;
	TEdit *Edit21;
	TEdit *Edit23;
	TEdit *Edit24;
	TEdit *Edit25;
	TEdit *Edit26;
	TEdit *Edit27;
	TEdit *Edit28;
	TEdit *Edit29;
	TEdit *Edit30;
	TLabel *Label23;
	TTimer *Timer1;
	TDateTimePicker *DateTimePicker2;
	TLabel *Label24;
	TEdit *Edit22;
	TLabel *Label25;
	TGroupBox *GroupBox2;
	TLabel *Label11;
	TEdit *Edit9;
	TLabel *Label26;
	TEdit *Edit31;
	TLabel *Label20;
	TEdit *Edit17;
	TLabel *Label6;
	TEdit *Edit4;
	TEdit *Edit32;
	TLabel *Label27;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall ComboBox2Select(TObject *Sender);
	void __fastcall ComboBox3Select(TObject *Sender);
	void __fastcall ComboBox4Select(TObject *Sender);
	void __fastcall Edit6Exit(TObject *Sender);
	void __fastcall Edit10Exit(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall DateTimePicker1Exit(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ComboBox1Select(TObject *Sender);
	void __fastcall Edit5Exit(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TRefueling_Form(TComponent* Owner);
TColor calc_proc(int d, int tr, int dist)
{
//	String col ;
	short proc = 0 ;
	double res = (100 * (d - tr)) / dist ;
//	Edit7->Text = String(100 * (d - tr) / dist) ;
	if (res < 70)
		return clGreen ; //proc = 1 ;
	if (res < 90)
		return clOlive ; //proc = 2 ;
	if (res > 90)
		return clRed ; //proc = 3 ;
	if (res > 100)
		return clMaroon ; //proc = 4 ;
/*
	switch (proc){
		case 1:
			return clGreen ;
			break ;
		case 2:
			return clYellow ;
			break ;
		case 3:
			return clRed ;
			break ;
		case 4:
			return clMaroon ;
			break ;
		default:
			return clBlack ;
			break ;
	}*/
}
};
//---------------------------------------------------------------------------
extern PACKAGE TRefueling_Form *Refueling_Form;
extern short curr_car ;
extern short acc_out ;
extern short acc_udw ;
extern int curr_ma ;
extern short kind_pay ;
//---------------------------------------------------------------------------
#endif

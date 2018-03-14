//---------------------------------------------------------------------------

#ifndef AddAcc_UnitH
#define AddAcc_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TAddAcc_Form : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TComboBox *ComboBox1;
	TBitBtn *BitBtn1;
	TADOQuery *ADOQuery1;
	TComboBox *ComboBox2;
	TLabel *Label1;
	TComboBox *ComboBox3;
	TBitBtn *BitBtn2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBox2Select(TObject *Sender);
	void __fastcall ComboBox2Exit(TObject *Sender);
	void __fastcall ComboBox2Click(TObject *Sender);
	void __fastcall ComboBox3Select(TObject *Sender);
	void __fastcall ComboBox1Select(TObject *Sender);
	void __fastcall ComboBox1Click(TObject *Sender);
	void __fastcall ComboBox1Exit(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAddAcc_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddAcc_Form *AddAcc_Form;
extern int acc = 0 ; //id счета оплаты
//---------------------------------------------------------------------------
#endif

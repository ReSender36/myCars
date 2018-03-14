//---------------------------------------------------------------------------

#ifndef AddSrv_Type_UnitH
#define AddSrv_Type_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TAddSrv_Type_Form : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TBitBtn *BitBtn1;
	TCheckBox *CheckBox6;
private:	// User declarations
public:		// User declarations
	__fastcall TAddSrv_Type_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddSrv_Type_Form *AddSrv_Type_Form;
//---------------------------------------------------------------------------
#endif

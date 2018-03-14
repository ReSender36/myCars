//---------------------------------------------------------------------------

#ifndef CarWrk_UnitH
#define CarWrk_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TWrks_Form : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar1;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TBitBtn *BitBtn1;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TWrks_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWrks_Form *Wrks_Form;
//---------------------------------------------------------------------------
#endif

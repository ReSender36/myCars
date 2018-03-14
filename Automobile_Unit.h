//---------------------------------------------------------------------------

#ifndef Automobile_UnitH
#define Automobile_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TAutomobile_Base_Form : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBox1;
	TEdit *Edit1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit2;
	TGroupBox *GroupBox1;
	TToolBar *ToolBar1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TBitBtn *BitBtn1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TEdit *Edit11;
	TLabel *Label12;
	TLabel *Label13;
	TEdit *Edit12;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TLabel *Label14;
	TEdit *Edit13;
	TLabel *Label15;
	TEdit *Edit14;
	TDBNavigator *DBNavigator1;
	TDataSource *DataSource1;
	TADODataSet *ADODataSet1;
	TGridPanel *GridPanel1;
	TToolBar *ToolBar2;
	TToolBar *ToolBar3;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TLabel *Label16;
	TLabel *Label17;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TGridPanel *GridPanel2;
	TToolBar *ToolBar4;
	TDBGrid *DBGrid3;
	TToolButton *ToolButton9;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBox1Select(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall ToolButton6Click(TObject *Sender);
	void __fastcall DBNavigator1Click(TObject *Sender, TNavigateBtn Button);
private:	// User declarations
public:		// User declarations
	__fastcall TAutomobile_Base_Form(TComponent* Owner);
	void __fastcall nbInsertClick(TObject *Sender) ;
};
//---------------------------------------------------------------------------
extern PACKAGE TAutomobile_Base_Form *Automobile_Base_Form;
//---------------------------------------------------------------------------
#endif

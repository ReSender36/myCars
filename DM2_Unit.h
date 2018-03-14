//---------------------------------------------------------------------------

#ifndef DM2_UnitH
#define DM2_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "IWImageList.hpp"
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
//---------------------------------------------------------------------------
class TDM2 : public TDataModule
{
__published:	// IDE-managed Components
//	TADOConnection *adoMainConn;
	TDataSource *ds_FirstReq;
	TADOQuery *adoQ_FirstReq;
	TADOQuery *adoDSeSelMnd;
	TADOQuery *adoQ_Automobile;
	TIWImageList *IWImageList1;
	TADOQuery *adoQ_AutoWrks;
	TADOQuery *adoQ_AZS;
	TADOQuery *adoQ_FuelTypes;
	TADOQuery *adoMainQ;
	TADOCommand *ADOCommand1;
	TOpenDialog *od1;
	TColorDialog *ColorDialog1;
	TADOConnection *adoMainConn;
	TADOQuery *ADOQuerySrv;
	TFDConnection *FDConnection1;
	TFDQuery *fdqSourceBook;
	TFDCommand *fdcSourceBooks;
	TFDQuery *FDQuery1;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
private:	// User declarations
//	bool db_connect() ;
public:		// User declarations

//---------------------------------------------------------------------------
short monTables(String table)
{
/*
ћонитор€щиес€ таблицы:
A - accounts
C - contragents
B - Bills
P - Payments
AF - AutoFuel
—начала провер€ем на добавление/удаление, затем на обновление ( ак???)
*/
String str_q ;
if ("A" == table)
{
ADOQuerySrv->Active = false ;
ADOQuerySrv->Filtered = false ;
str_q = String("select count(id) as c_id from accounts ;") ;
ADOQuerySrv->SQL->Text = str_q ;
ADOQuerySrv->Active = true ;
}
}
//---------------------------------------------------------------------------
String genBillNum(short contr)
{
ADOQuerySrv->Active = false ;
ADOQuerySrv->Filtered = false ;
ADOQuerySrv->SQL->Text = String("SELECT kb.billlength, kb.billprefix, LEN(kb.billprefix) as bp_lenth \
from contragents c \
left join kind_bills kb on kb.kind = c.kind_bills \
where c.id = " + String(contr) + " ;") ;
ADOQuerySrv->Active = true ;

short BillLength = ADOQuerySrv->FieldByName("billlength")->AsInteger ;
String BillPrefix = ADOQuerySrv->FieldByName("billprefix")->AsString ;
short BP_Length = ADOQuerySrv->FieldByName("bp_lenth")->AsInteger ;

ADOQuerySrv->Active = false ;
ADOQuerySrv->SQL->Text = String("select bs.bill_num, right(bs.bill_num,(" + String(BillLength) + "-" + String(BP_Length) + ")) as bn_num from bills bs where bs.id = (select max(bs1.id) from bills bs1 where bs1.contragent = " + String(contr) + ") ;") ;
ADOQuerySrv->Active = true ;
String bn_numStr = ADOQuerySrv->FieldByName("bn_num")->AsString ;
int bn_num = 0 ; short bln = 0 ;
String bn = "" ;
if ("" == bn_numStr) bn_num = 1 ;
else
{
	bn_num = StrToInt(bn_numStr) ;
	bn_num++ ;
}

bn = BillPrefix + IntToStr(bn_num) ;
ADOQuerySrv->Active = false ;
// тут фиктивный запрос. Ѕыло неважно, к какой таблице, главное, чтобы выдал одну строку
ADOQuerySrv->SQL->Text = String("select LEN('"+bn+"') as bill_num_len from bills bs where bs.id = (select min(bs1.id) from bills bs1) ;") ;
ADOQuerySrv->Active = true ;
bln = ADOQuerySrv->FieldByName("bill_num_len")->AsInteger ;
short blnDelta = BillLength - bln ;
bn = BillPrefix ;
for (short i = 0; i < blnDelta; i++)
{
	bn = bn + "0" ;
}
bn = bn + IntToStr(bn_num) ;
// String bn = ADOQuerySrv->FieldByName("bill_num")->AsString ;

return bn ;
}
//---------------------------------------------------------------------------
short incr_rating(String fType, short fRat_id, short fOld_rat)
{
/*
¬ этой функции мы добавл€м единицу к значению рейтинга дл€ счета и контрагента (операции)
переменна€ type - описывает тип обновл€емых данных: "C" - contragents и "A" - accounts
rat_id - идентификатор контрагента или счета, которому увеличиваем рейтинг
old_rat - старое значение рейтинга
*/

String fStr_wrk = "" ;

if ("C" == fType)
{
	fOld_rat++ ;
	fStr_wrk = String("update contragents set rating = " + String(fOld_rat) + " where id = " + String(fRat_id) + " ;") ;
	ADOCommand1->CommandText = fStr_wrk ;
	ADOCommand1->Execute() ;
	return 1 ;
}
if ("A" == fType)
{
	fOld_rat++ ;
	fStr_wrk = String("update accounts set ud_weight = " + String(fOld_rat) + " where id = " + String(fRat_id) + " ;") ;
	ADOCommand1->CommandText = fStr_wrk ;
	ADOCommand1->Execute() ;

	ADOQuerySrv->Active = false ;
	ADOQuerySrv->SQL->Text = String("select parent from accounts where id = " + String(fRat_id) + " ;") ;
	ADOQuerySrv->Active = true ;
	short parent = ADOQuerySrv->FieldByName("parent")->AsInteger ;
	if (0 != parent || NULL != parent)
	{
		ADOQuerySrv->Active = false ;
		ADOQuerySrv->SQL->Text = String("select id, ud_weight from accounts where id = " + String(parent) + " ;") ;
		ADOQuerySrv->Active = true ;
		int ud_weight = ADOQuerySrv->FieldByName("ud_weight")->AsInteger ;
		short id = ADOQuerySrv->FieldByName("id")->AsInteger ;
		ud_weight++ ;
		fStr_wrk = String("update accounts set ud_weight = " + IntToStr(ud_weight) + " where id = " + String(id) + " ;") ;
		ADOCommand1->CommandText = fStr_wrk ;
		ADOCommand1->Execute() ;
	}
	return 1 ;
}
}
//---------------------------------------------------------------------------
	__fastcall TDM2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM2 *DM2;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CarWrk_Unit.h"
#include "DM2_Unit.h"
#include "Refueling_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWrks_Form *Wrks_Form;
int car, w_type ;
//car = 0 ;
//---------------------------------------------------------------------------
__fastcall TWrks_Form::TWrks_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWrks_Form::BitBtn1Click(TObject *Sender)
{
Wrks_Form->Visible = false ;
Wrks_Form->Destroying() ;
}
//---------------------------------------------------------------------------
void __fastcall TWrks_Form::FormCreate(TObject *Sender)
{
if (0 == curr_car)
{
	ComboBox1->Text = "Выберите автомобиль" ;

	DM2->adoQ_Automobile->Active = false ;
String str = String("select (producer & ' ' & model) as mod_auto, id, Current_mileage, Avg_FuelExpense, \
Trip_GhgGRMbelt_ON, Trip_GhgGeneratorBelt_ON, Trip_GhgGURbelt_ON, Trip_ChgCondBelt_ON,\
Trip_GhgOil_ON, Trip_GhgSpPlug_ON, Trip_ChgHiVoltWires_ON, Trip_ChgOil_KPP_ON \
from t_CarModels c ;") ;
DM2->adoQ_Automobile->SQL->Text = str ;
DM2->adoQ_Automobile->Active = true ;
DM2->adoQ_Automobile->First() ;
	while(!DM2->adoQ_Automobile->Eof)
	{
		ComboBox1->AddItem(DM2->adoQ_Automobile->FieldByName("mod_auto")->AsString,
			(TObject*)DM2->adoQ_Automobile->FieldByName("id")->AsInteger) ;
		DM2->adoQ_Automobile->Next() ;
	}
//	cur_mileage = DM2->adoQ_Automobile->FieldByName("Current_mileage")->AsInteger ;
}
else
{
	ComboBox1->Enabled = false ;
    	DM2->adoQ_Automobile->Active = false ;
String str = String("select (producer & ' ' & model) as mod_auto, id, Current_mileage \
from t_CarModels c \
where c.id = " + String(curr_car) + " ;") ;
DM2->adoQ_Automobile->SQL->Text = str ;
DM2->adoQ_Automobile->Active = true ;
	ComboBox1->Text = DM2->adoQ_Automobile->FieldByName("mod_auto")->AsString ;
//	cur_mileage = DM2->adoQ_Automobile->FieldByName("Current_mileage")->AsInteger ;
}
	DM2->adoQ_AutoWrks->Active = false ;
String wrk_str = String("select ks.kind, ks.caption from kind_services ks where ks.parent = 0 ;") ;
	DM2->adoQ_AutoWrks->SQL->Text = wrk_str ;
	DM2->adoQ_AutoWrks->Active = true ;
		while(!DM2->adoQ_AutoWrks->Eof)
	{
		ComboBox2->AddItem(DM2->adoQ_AutoWrks->FieldByName("caption")->AsString,
			(TObject*)DM2->adoQ_AutoWrks->FieldByName("kind")->AsInteger) ;
		DM2->adoQ_AutoWrks->Next() ;
	}
	ADOQuery1->Active = false ;
String main_str = String("select * from t_autofuel af where af.Car = " + String(car)
 + " and af.Wrk_Type = " + String(w_type) + " ;") ;
	ADOQuery1->SQL->Text = main_str ;
	ADOQuery1->Active = true ;

}
//---------------------------------------------------------------------------

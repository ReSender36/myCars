/*---------------------------------------------------------------------------
Периодические работы с авто:
1. Замена масла (комплекта фильтров, масла в двигателе)
2. Замена свечей
3. Замена высоковольтных проводов
4. Замена передних тормозных колодок
5. Замена задних тормозных колодок
6. Замена ремня ГРМ
7. Замена ремня ГУР
8. Замена ремня кондиционера
9. Замена ремня генератора
10. Замена масла в КПП
11. Замена колодок ручного тормоза
//---------------------------------------------------------------------------
*/
#include <vcl.h>
#pragma hdrstop

#include <cmath>
#include <math.h>

#include "Automobile_Unit.h"
#include "Refueling_Unit.h"
#include "DM2_Unit.h"
#include "CarWrk_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAutomobile_Base_Form *Automobile_Base_Form;
short curr_car ;
int curr_ma ;
//---------------------------------------------------------------------------
float round(double res, short st)
{
	short pers1 = st + 1 ;
	double pt = 10 ;
	double pt1 = 5 ;
	double conv = pt1 / pow(pt,pers1) ;
	double ipart1, ipart2, fpart;
	fpart = modf(res,&ipart1);
	fpart = fpart + conv ;
	fpart = modf(fpart*pow(pt,st),&ipart2); //
	ipart1 += ipart2/pow(pt,st);
	return ipart1 ;
}
//---------------------------------------------------------------------------
void car_statistic(cc)
{
// Edit1->Text = DM2->adoQ_Automobile->FieldByName("Current_mileage")->AsInteger ;
DM2->adoQ_Automobile->Active = false ;
DM2->adoQ_Automobile->Filtered = false ;
DM2->adoQ_Automobile->SQL->Text = String("select Current_mileage, Avg_FuelExpense, \
Trip_GhgGRMbelt_ON, Trip_GhgGeneratorBelt_ON, Trip_GhgGURbelt_ON, Trip_ChgCondBelt_ON,\
Trip_GhgOil_ON, Trip_GhgSpPlug_ON, Trip_ChgHiVoltWires_ON, Trip_ChgOil_KPP_ON, \
Trip_ChgFrontBrakePad,Trip_ChgRearBrakePad, \
Dist_GhgGRMbelt, Dist_GhgGeneratorBelt, Dist_GhgGURbelt, Dist_ChgCondBelt, Dist_GhgOil, Dist_GhgSpPlug, \
Dist_ChgHiVoltWires, Dist_ChgOil_KPP, Dist_ChgFrontBrakePad, Dist_ChgRearBrakePad \
from t_CarModels c where c.id = " + String(cc) + ";") ;
DM2->adoQ_Automobile->Active = true ;

curr_ma = DM2->adoQ_Automobile->FieldByName("Current_mileage")->AsInteger ;
Automobile_Base_Form->Edit1->Text = curr_ma ;
Automobile_Base_Form->Edit2->Text = round(DM2->adoQ_Automobile->FieldByName("Avg_FuelExpense")->AsFloat,2) ;

int curr_Oil = DM2->adoQ_Automobile->FieldByName("Trip_GhgOil_ON")->AsInteger ;
int dst_Oil = DM2->adoQ_Automobile->FieldByName("Dist_GhgOil")->AsInteger ;
Automobile_Base_Form->Edit3->Text = curr_ma - curr_Oil ;
Automobile_Base_Form->Edit3->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_Oil, dst_Oil) ;

int curr_SpPlug = DM2->adoQ_Automobile->FieldByName("Trip_GhgSpPlug_ON")->AsInteger ;
int dst_SpPlug = DM2->adoQ_Automobile->FieldByName("Dist_GhgSpPlug")->AsInteger ;
Automobile_Base_Form->Edit4->Text = curr_ma - curr_SpPlug ;
Automobile_Base_Form->Edit4->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_SpPlug, dst_SpPlug) ;

int curr_HiVoltWires = DM2->adoQ_Automobile->FieldByName("Trip_ChgHiVoltWires_ON")->AsInteger ;
int dst_HiVoltWires = DM2->adoQ_Automobile->FieldByName("Dist_ChgHiVoltWires")->AsInteger ;
Automobile_Base_Form->Edit5->Text = curr_ma - curr_HiVoltWires ;
Automobile_Base_Form->Edit5->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_HiVoltWires, dst_HiVoltWires) ;

int curr_OilKPP = DM2->adoQ_Automobile->FieldByName("Trip_ChgOil_KPP_ON")->AsInteger ;
int dst_OilKPP = DM2->adoQ_Automobile->FieldByName("Dist_ChgOil_KPP")->AsInteger ;
Automobile_Base_Form->Edit6->Text = curr_ma - curr_OilKPP ;
Automobile_Base_Form->Edit6->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_OilKPP, dst_OilKPP) ;

int curr_GRMBelt = DM2->adoQ_Automobile->FieldByName("Trip_GhgGRMbelt_ON")->AsInteger ;
int dst_GRMBelt = DM2->adoQ_Automobile->FieldByName("Dist_GhgGRMbelt")->AsInteger ;
Automobile_Base_Form->Edit7->Text = curr_ma - curr_GRMBelt ;
Automobile_Base_Form->Edit7->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_GRMBelt, dst_GRMBelt) ;

int curr_GUR = DM2->adoQ_Automobile->FieldByName("Trip_GhgGURbelt_ON")->AsInteger ;
int dst_GUR = DM2->adoQ_Automobile->FieldByName("Dist_GhgGURbelt")->AsInteger ;
Automobile_Base_Form->Edit8->Text = curr_ma - curr_GUR ;
Automobile_Base_Form->Edit8->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_GUR, dst_GUR) ;

int curr_Gen = DM2->adoQ_Automobile->FieldByName("Trip_GhgGeneratorBelt_ON")->AsInteger ;
int dst_Gen = DM2->adoQ_Automobile->FieldByName("Dist_GhgGeneratorBelt")->AsInteger ;
Automobile_Base_Form->Edit9->Text = curr_ma - curr_Gen ;
Automobile_Base_Form->Edit9->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_Gen, dst_Gen) ;

int curr_Cond = DM2->adoQ_Automobile->FieldByName("Trip_ChgCondBelt_ON")->AsInteger ;
int dst_Cond = DM2->adoQ_Automobile->FieldByName("Dist_ChgCondBelt")->AsInteger ;
Automobile_Base_Form->Edit10->Text = curr_ma - curr_Cond ;
Automobile_Base_Form->Edit10->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_Cond, dst_Cond) ;

int curr_FrontBr = DM2->adoQ_Automobile->FieldByName("Trip_ChgFrontBrakePad")->AsInteger ;
int dst_FrontBr = DM2->adoQ_Automobile->FieldByName("Dist_ChgFrontBrakePad")->AsInteger ;
Automobile_Base_Form->Edit11->Text = curr_ma - curr_FrontBr ;
Automobile_Base_Form->Edit11->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_FrontBr, dst_FrontBr) ;

int curr_RearBr = DM2->adoQ_Automobile->FieldByName("Trip_ChgRearBrakePad")->AsInteger ;
int dst_RearBr = DM2->adoQ_Automobile->FieldByName("Dist_ChgRearBrakePad")->AsInteger ;
Automobile_Base_Form->Edit12->Text = curr_ma - curr_RearBr ;
Automobile_Base_Form->Edit12->Font->Color = Refueling_Form->calc_proc(curr_ma, curr_RearBr, dst_RearBr) ;
}
//---------------------------------------------------------------------------
__fastcall TAutomobile_Base_Form::TAutomobile_Base_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAutomobile_Base_Form::FormCreate(TObject *Sender)
{
DM2->adoQ_Automobile->Active = false ;
String str = String("select (producer & ' ' & model) as mod_auto, id from t_CarModels c ;") ;
DM2->adoQ_Automobile->SQL->Text = str ;
DM2->adoQ_Automobile->Active = true ;
DM2->adoQ_Automobile->First() ;
	while(!DM2->adoQ_Automobile->Eof)
	{
		ComboBox1->AddItem(DM2->adoQ_Automobile->FieldByName("mod_auto")->AsString,
			(TObject*)DM2->adoQ_Automobile->FieldByName("id")->AsInteger) ;
		DM2->adoQ_Automobile->Next() ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TAutomobile_Base_Form::ComboBox1Select(TObject *Sender)
{
curr_car = 0 ;
DM2->adoQ_Automobile->Filtered = false ;
String str = String("mod_auto = '" + ComboBox1->Text + "'") ;
String str_q = String("select (producer & ' ' & model) as mod_auto, id from t_CarModels c ;") ;
DM2->adoQ_Automobile->Active = false ;
DM2->adoQ_Automobile->SQL->Text = str_q ;
DM2->adoQ_Automobile->Filter = str ;
DM2->adoQ_Automobile->Filtered = true ;
DM2->adoQ_Automobile->Active = true ;
curr_car = DM2->adoQ_Automobile->FieldByName("id")->AsInteger ;
car_statistic(curr_car) ;
}
//---------------------------------------------------------------------------
void __fastcall TAutomobile_Base_Form::ToolButton1Click(TObject *Sender)
{
Application->CreateForm(__classid(TRefueling_Form), &Refueling_Form) ;
Refueling_Form->Visible = true ;
}
//---------------------------------------------------------------------------

void __fastcall TAutomobile_Base_Form::ToolButton3Click(TObject *Sender)
{
Application->CreateForm(__classid(TWrks_Form), &Wrks_Form) ;
Wrks_Form->Visible = true ;
}
//---------------------------------------------------------------------------
void __fastcall TAutomobile_Base_Form::ToolButton6Click(TObject *Sender)
{
car_statistic(curr_car) ;
}
//---------------------------------------------------------------------------


void __fastcall TAutomobile_Base_Form::DBNavigator1Click(TObject *Sender, TNavigateBtn Button)

{
//DBNavigator1->BtnClick(nbInsert) = nbInsertClick ;

}
//---------------------------------------------------------------------------
void __fastcall TAutomobile_Base_Form::nbInsertClick(TObject *Sender)
{
Edit14->Text = "3" ;
}


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <cmath>
#include <math.h>

#include "Automobile_Unit.h"
#include "Refueling_Unit.h"
#include "AddSrv_Type_Unit.h"
#include "AddAcc_Unit.h"
#include "DM2_Unit.h"

#include "Automobile.h"
#include "SourceBook_Unit.h"

//#include "NewPay_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRefueling_Form *Refueling_Form;

int dist_GhgGRMbelt = 0 ; // пробег на момент крайней замены ремня ГРМ
int dist_GhgGeneratorBelt = 0 ; // пробег на момент крайней замены генератора
int dist_GhgGURbelt = 0 ; // пробег на момент крайней замены ремня ГУР
int dist_ChgCondBelt = 0 ; // пробег на момент крайней замены ремня кондиционера
int dist_GhgOil = 0 ; // пробег на момент крайней замены масла в двигателе
int dist_GhgSpPlug = 0 ; // пробег на момент крайней замены свечей
int dist_ChgHiVoltWires = 0 ; // пробег на момент крайней замены высоковольтны проводов
int dist_ChgOil_KPP = 0 ; // пробег на момент крайней замены масла в КПП
int dist_ChgFrontBrakePad = 0 ; // пробег на момент крайней замены передних тормозных колодок
int dist_ChgRearBrakePad = 0 ; // пробег на момент крайней замены задних тормозных колодок

int cur_mileage = 0 ; // текущий актуальный пробег автомобиля
int planned_dist = 0 ; // палновый пробег авто на заправленноv на прошлой заправке топливе
int cur_GhgGRMbelt = 0 ; // пробег на момент крайней замены ремня ГРМ
int cur_GhgGeneratorBelt = 0 ; // пробег на момент крайней замены генератора
int cur_GhgGURbelt = 0 ; // пробег на момент крайней замены ремня ГУР
int cur_ChgCondBelt = 0 ; // пробег на момент крайней замены ремня кондиционера
int cur_GhgOil = 0 ; // пробег на момент крайней замены масла в двигателе
int cur_GhgSpPlug = 0 ; // пробег на момент крайней замены свечей
int cur_ChgHiVoltWires = 0 ; // пробег на момент крайней замены высоковольтны проводов
int cur_ChgOil_KPP = 0 ; // пробег на момент крайней замены масла в КПП
int cur_ChgFrontBrakePad = 0 ; // пробег на момент крайней замены передних тормозных колодок
int cur_ChgRearBrakePad = 0 ; // пробег на момент крайней замены задних тормозных колодок

int q1 = 0 ; // пробег при очередной работе с авто
//int q = 0 ; // пробег между однотипными сервисами
int ks = 0 ; // тип автоработы
short fs = 0 ; // уникальный ID АЗС
short rating = 0 ;
int kf = 0 ; // тип залитого бензина
double fv = 0 ; // кол-во бензина залитого на крайней заправке

SourceBook sbFuelType("KIND_FUEL") ;
Automobile am("kf") ;

//int curr_car ;
//int curr_ma ;
TDateTime date_service ; //дата текущего сервиса
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
float calc_primProbeg()
{
	float fRes = 0.0 ;
	return fRes ;
}
//---------------------------------------------------------------------------
void car_statistic(cc)
{
//	Edit1->Text = DM2->adoQ_Automobile->FieldByName("Current_mileage")->AsInteger ;
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

	int curr_Oil = DM2->adoQ_Automobile->FieldByName("Trip_GhgOil_ON")->AsInteger;
	int dst_Oil = DM2->adoQ_Automobile->FieldByName("Dist_GhgOil")->AsInteger;
	Automobile_Base_Form->Edit3->Text = curr_ma - curr_Oil;
	Automobile_Base_Form->Edit3->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_Oil, dst_Oil);

	int curr_SpPlug = DM2->adoQ_Automobile->FieldByName("Trip_GhgSpPlug_ON")
		->AsInteger;
	int dst_SpPlug = DM2->adoQ_Automobile->FieldByName("Dist_GhgSpPlug")
		->AsInteger;
	Automobile_Base_Form->Edit4->Text = curr_ma - curr_SpPlug;
	Automobile_Base_Form->Edit4->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_SpPlug, dst_SpPlug);

	int curr_HiVoltWires = DM2->adoQ_Automobile->FieldByName
		("Trip_ChgHiVoltWires_ON")->AsInteger;
	int dst_HiVoltWires = DM2->adoQ_Automobile->FieldByName
		("Dist_ChgHiVoltWires")->AsInteger;
	Automobile_Base_Form->Edit5->Text = curr_ma - curr_HiVoltWires;
	Automobile_Base_Form->Edit5->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_HiVoltWires, dst_HiVoltWires);

	int curr_OilKPP = DM2->adoQ_Automobile->FieldByName("Trip_ChgOil_KPP_ON")
		->AsInteger;
	int dst_OilKPP = DM2->adoQ_Automobile->FieldByName("Dist_ChgOil_KPP")
		->AsInteger;
	Automobile_Base_Form->Edit6->Text = curr_ma - curr_OilKPP;
	Automobile_Base_Form->Edit6->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_OilKPP, dst_OilKPP);

	int curr_GRMBelt = DM2->adoQ_Automobile->FieldByName("Trip_GhgGRMbelt_ON")
		->AsInteger;
	int dst_GRMBelt = DM2->adoQ_Automobile->FieldByName("Dist_GhgGRMbelt")
		->AsInteger;
	Automobile_Base_Form->Edit7->Text = curr_ma - curr_GRMBelt;
	Automobile_Base_Form->Edit7->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_GRMBelt, dst_GRMBelt);

	int curr_GUR = DM2->adoQ_Automobile->FieldByName("Trip_GhgGURbelt_ON")
		->AsInteger;
	int dst_GUR = DM2->adoQ_Automobile->FieldByName("Dist_GhgGURbelt")
		->AsInteger;
	Automobile_Base_Form->Edit8->Text = curr_ma - curr_GUR;
	Automobile_Base_Form->Edit8->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_GUR, dst_GUR);

	int curr_Gen = DM2->adoQ_Automobile->FieldByName("Trip_GhgGeneratorBelt_ON")
		->AsInteger;
	int dst_Gen = DM2->adoQ_Automobile->FieldByName("Dist_GhgGeneratorBelt")
		->AsInteger;
	Automobile_Base_Form->Edit9->Text = curr_ma - curr_Gen;
	Automobile_Base_Form->Edit9->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_Gen, dst_Gen);

	int curr_Cond = DM2->adoQ_Automobile->FieldByName("Trip_ChgCondBelt_ON")
		->AsInteger;
	int dst_Cond = DM2->adoQ_Automobile->FieldByName("Dist_ChgCondBelt")
		->AsInteger;
	Automobile_Base_Form->Edit10->Text = curr_ma - curr_Cond;
	Automobile_Base_Form->Edit10->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_Cond, dst_Cond);

	int curr_FrontBr = DM2->adoQ_Automobile->FieldByName
		("Trip_ChgFrontBrakePad")->AsInteger;
	int dst_FrontBr = DM2->adoQ_Automobile->FieldByName("Dist_ChgFrontBrakePad")
		->AsInteger;
	Automobile_Base_Form->Edit11->Text = curr_ma - curr_FrontBr;
	Automobile_Base_Form->Edit11->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_FrontBr, dst_FrontBr);

	int curr_RearBr = DM2->adoQ_Automobile->FieldByName("Trip_ChgRearBrakePad")
		->AsInteger;
	int dst_RearBr = DM2->adoQ_Automobile->FieldByName("Dist_ChgRearBrakePad")
		->AsInteger;
	Automobile_Base_Form->Edit12->Text = curr_ma - curr_RearBr;
	Automobile_Base_Form->Edit12->Font->Color =
		Refueling_Form->calc_proc(curr_ma, curr_RearBr, dst_RearBr);
}

// ---------------------------------------------------------------------------
float chk_balL(short acc) {
	// acc = 0 ;
	Refueling_Form->ADOQuery1->Active = false;
	String str_bal = String("select balance as bal from accounts where id = " +
		String(acc) + " ;");
	Refueling_Form->ADOQuery1->SQL->Text = str_bal;
	Refueling_Form->ADOQuery1->Active = true;
	return Refueling_Form->ADOQuery1->FieldByName("bal")->AsFloat;
}

// ---------------------------------------------------------------------------
TDateTime CalcFutureSrvDate(short f_days, int vProb, int dist_srv, int cur_prob,
	TDateTime date_srv, String next_srv_date = "") {
	double dst;
	int wd = dist_srv - (q1 - cur_prob);
	try {
		dst = vProb / f_days;
	}
	/* catch (EZeroDivide)
	 {
	 f_days = 1 ;
	 dst = vProb / f_days ;
	 } */
	catch (...) {
		f_days = 1;
		dst = vProb / f_days;
	}
	int ost_dst = wd / dst;

	Refueling_Form->ADOQuery1->Active = false;
	String str1 = String("select \
	DateAdd('d'," + String(ost_dst) + ",'" + DateToStr(date_srv) + "') as date_next_srv \
	from t_autofuel \
	where DateFuelling = (select max(DateFuelling) from t_autofuel where wrk_type = 1) \
	and car = " + String(curr_car) + " ;") ;
	Refueling_Form->ADOQuery1->SQL->Text = str1 ;
	Refueling_Form->ADOQuery1->Active = true ;
	next_srv_date = Refueling_Form->ADOQuery1->FieldByName("date_next_srv")->AsString ;
	if ("" == next_srv_date) next_srv_date = DateToStr(date_srv) ;
	return next_srv_date ;

/*
	int wd = dist_GhgOil - (q1 - cur_GhgOil) ;
	double dst = prob / df ;
	int ost_dst = wd / dst ;

	ADOQuery1->Active = false ;
	String str1 = String("select \
	DateAdd('d'," + String(ost_dst) + ",'" + DateToStr(date_service) + "') as date_next_srv \
	from t_autofuel \
	where DateFuelling = (select max(DateFuelling) from t_autofuel where wrk_type = 1) \
	and car = " + String(curr_car) + " ;") ;
	ADOQuery1->SQL->Text = str1 ;
	ADOQuery1->Active = true ;
	return next_srv_date = ADOQuery1->FieldByName("date_next_srv")->AsString ;
*/
}
//---------------------------------------------------------------------------
short select_f_station()
{
	short res = 0 ;
	String str = String("caption = '" + Refueling_Form->ComboBox3->Text + "'") ;
	DM2->adoQ_AZS->Active = false ;
	DM2->adoQ_AZS->Filter = str ;
	DM2->adoQ_AZS->Filtered = true ;
	DM2->adoQ_AZS->Active = true ;
	rating = DM2->adoQ_AZS->FieldByName("rating")->AsInteger ;
	res = DM2->adoQ_AZS->FieldByName("id")->AsInteger ;
	return res ;
}
//---------------------------------------------------------------------------
__fastcall TRefueling_Form::TRefueling_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRefueling_Form::FormCreate(TObject *Sender)
{
//	SourceBook sbFuelType = new SourceBook("KIND_FUEL") ;
//	sbFuelType("KIND_FUEL") ;

	if(DM2->FDQuery1->Active)
		DM2->FDQuery1->Active = false ;
	DM2->FDQuery1->Filtered = false ;
	String ft_str_q = sbFuelType.BASE_REQUEST ;
	int probeg = am.currOdometer ;
	String req = am.BASE_REQUEST ;
//    am.addNew("qwe") ;
	DM2->FDQuery1->SQL->Text = ft_str_q ;
	try {
		DM2->FDQuery1->Active = true ;
	} catch (...) {
	}

	while(!DM2->FDQuery1->Eof){
		ComboBox4->AddItem(DM2->FDQuery1->FieldByName("caption")->AsString,
			(TObject*)DM2->FDQuery1->FieldByName("kind")->AsInteger) ;
		DM2->FDQuery1->Next() ;
	}


return ;

if (0 == curr_car)
{
	ComboBox1->Text = "Выберите автомобиль" ;

	DM2->adoQ_Automobile->Active = false ;
	DM2->adoQ_Automobile->Filtered = false ;
String str = String("select (producer & ' ' & model) as mod_auto, id, Current_mileage, Avg_FuelExpense, \
Trip_GhgGRMbelt_ON, Trip_GhgGeneratorBelt_ON, Trip_GhgGURbelt_ON, Trip_ChgCondBelt_ON,\
Trip_GhgOil_ON, Trip_GhgSpPlug_ON, Trip_ChgHiVoltWires_ON, \
Trip_ChgOil_KPP_ON,Trip_ChgFrontBrakePad,Trip_ChgRearBrakePad, \
Dist_GhgGRMbelt, Dist_GhgGeneratorBelt, Dist_GhgGURbelt, Dist_ChgCondBelt, Dist_GhgOil, Dist_GhgSpPlug, \
Dist_ChgHiVoltWires, Dist_ChgOil_KPP, Dist_ChgFrontBrakePad, Dist_ChgRearBrakePad \
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
	curr_car = DM2->adoQ_Automobile->FieldByName("id")->AsInteger ;
	cur_mileage = DM2->adoQ_Automobile->FieldByName("Current_mileage")->AsInteger ;
	cur_GhgGRMbelt = DM2->adoQ_Automobile->FieldByName("Trip_GhgGRMbelt_ON")->AsInteger ;
	cur_GhgGeneratorBelt = DM2->adoQ_Automobile->FieldByName("Trip_GhgGeneratorBelt_ON")->AsInteger ;
	cur_GhgGURbelt = DM2->adoQ_Automobile->FieldByName("Trip_GhgGURbelt_ON")->AsInteger ;
	cur_ChgCondBelt = DM2->adoQ_Automobile->FieldByName("Trip_ChgCondBelt_ON")->AsInteger ;
	cur_GhgOil = DM2->adoQ_Automobile->FieldByName("Trip_GhgOil_ON")->AsInteger ;
	cur_GhgSpPlug = DM2->adoQ_Automobile->FieldByName("Trip_GhgSpPlug_ON")->AsInteger ;
	cur_ChgHiVoltWires = DM2->adoQ_Automobile->FieldByName("Trip_ChgHiVoltWires_ON")->AsInteger ;
	cur_ChgOil_KPP = DM2->adoQ_Automobile->FieldByName("Trip_ChgOil_KPP_ON")->AsInteger ;
	cur_ChgFrontBrakePad = DM2->adoQ_Automobile->FieldByName("Trip_ChgFrontBrakePad")->AsInteger ;
	cur_ChgRearBrakePad = DM2->adoQ_Automobile->FieldByName("Trip_ChgRearBrakePad")->AsInteger ;

	dist_GhgGRMbelt = DM2->adoQ_Automobile->FieldByName("Dist_GhgGRMbelt")->AsInteger ;
	dist_GhgGeneratorBelt = DM2->adoQ_Automobile->FieldByName("Dist_GhgGeneratorBelt")->AsInteger ;
	dist_GhgGURbelt = DM2->adoQ_Automobile->FieldByName("Dist_GhgGURbelt")->AsInteger ;
	dist_ChgCondBelt = DM2->adoQ_Automobile->FieldByName("Dist_ChgCondBelt")->AsInteger ;
	dist_GhgOil = DM2->adoQ_Automobile->FieldByName("Dist_GhgOil")->AsInteger ;
	dist_GhgSpPlug = DM2->adoQ_Automobile->FieldByName("Dist_GhgSpPlug")->AsInteger ;
	dist_ChgHiVoltWires = DM2->adoQ_Automobile->FieldByName("Dist_ChgHiVoltWires")->AsInteger ;
	dist_ChgOil_KPP = DM2->adoQ_Automobile->FieldByName("Dist_ChgOil_KPP")->AsInteger ;
	dist_ChgFrontBrakePad = DM2->adoQ_Automobile->FieldByName("Dist_ChgFrontBrakePad")->AsInteger ;
	dist_ChgRearBrakePad = DM2->adoQ_Automobile->FieldByName("Dist_ChgRearBrakePad")->AsInteger ;
}
else
{
	ComboBox1->Enabled = false ;
	DM2->adoQ_Automobile->Active = false ;
String str = String("select (producer & ' ' & model) as mod_auto, id, Current_mileage, Trip_GhgGRMbelt_ON,\
Trip_GhgGeneratorBelt_ON,Trip_GhgGURbelt_ON,Trip_ChgCondBelt_ON,Trip_GhgOil_ON,Trip_GhgSpPlug_ON,Trip_ChgHiVoltWires_ON,\
Trip_ChgOil_KPP_ON,Trip_ChgFrontBrakePad,Trip_ChgRearBrakePad, \
Dist_GhgGRMbelt, Dist_GhgGeneratorBelt, Dist_GhgGURbelt, Dist_ChgCondBelt, Dist_GhgOil, Dist_GhgSpPlug, \
Dist_ChgHiVoltWires, Dist_ChgOil_KPP, Dist_ChgFrontBrakePad, Dist_ChgRearBrakePad \
from t_CarModels c \
where c.id = " + String(curr_car) + " ;") ;
DM2->adoQ_Automobile->SQL->Text = str ;
DM2->adoQ_Automobile->Active = true ;
	ComboBox1->Text = DM2->adoQ_Automobile->FieldByName("mod_auto")->AsString ;
	cur_mileage = DM2->adoQ_Automobile->FieldByName("Current_mileage")->AsInteger ;
	cur_GhgGRMbelt = DM2->adoQ_Automobile->FieldByName("Trip_GhgGRMbelt_ON")->AsInteger ;
	cur_GhgGeneratorBelt = DM2->adoQ_Automobile->FieldByName("Trip_GhgGeneratorBelt_ON")->AsInteger ;
	cur_GhgGURbelt = DM2->adoQ_Automobile->FieldByName("Trip_GhgGURbelt_ON")->AsInteger ;
	cur_ChgCondBelt = DM2->adoQ_Automobile->FieldByName("Trip_ChgCondBelt_ON")->AsInteger ;
	cur_GhgOil = DM2->adoQ_Automobile->FieldByName("Trip_GhgOil_ON")->AsInteger ;
	cur_GhgSpPlug = DM2->adoQ_Automobile->FieldByName("Trip_GhgSpPlug_ON")->AsInteger ;
	cur_ChgHiVoltWires = DM2->adoQ_Automobile->FieldByName("Trip_ChgHiVoltWires_ON")->AsInteger ;
	cur_ChgOil_KPP = DM2->adoQ_Automobile->FieldByName("Trip_ChgOil_KPP_ON")->AsInteger ;
	cur_ChgFrontBrakePad = DM2->adoQ_Automobile->FieldByName("Trip_ChgFrontBrakePad")->AsInteger ;
	cur_ChgRearBrakePad = DM2->adoQ_Automobile->FieldByName("Trip_ChgRearBrakePad")->AsInteger ;

	dist_GhgGRMbelt = DM2->adoQ_Automobile->FieldByName("Dist_GhgGRMbelt")->AsInteger ;
	dist_GhgGeneratorBelt = DM2->adoQ_Automobile->FieldByName("Dist_GhgGeneratorBelt")->AsInteger ;
	dist_GhgGURbelt = DM2->adoQ_Automobile->FieldByName("Dist_GhgGURbelt")->AsInteger ;
	dist_ChgCondBelt = DM2->adoQ_Automobile->FieldByName("Dist_ChgCondBelt")->AsInteger ;
	dist_GhgOil = DM2->adoQ_Automobile->FieldByName("Dist_GhgOil")->AsInteger ;
	dist_GhgSpPlug = DM2->adoQ_Automobile->FieldByName("Dist_GhgSpPlug")->AsInteger ;
	dist_ChgHiVoltWires = DM2->adoQ_Automobile->FieldByName("Dist_ChgHiVoltWires")->AsInteger ;
	dist_ChgOil_KPP = DM2->adoQ_Automobile->FieldByName("Dist_ChgOil_KPP")->AsInteger ;
	dist_ChgFrontBrakePad = DM2->adoQ_Automobile->FieldByName("Dist_ChgFrontBrakePad")->AsInteger ;
	dist_ChgRearBrakePad = DM2->adoQ_Automobile->FieldByName("Dist_ChgRearBrakePad")->AsInteger ;
}
	TDateTime dt = TDateTime::CurrentTime() ;
	ADOQuery1->Active = false ;
	String str_paydate = String("select max(DateFuelling) as pd from t_AutoFuel where car = " + String(curr_car) + " ;") ;
	ADOQuery1->SQL->Text = str_paydate ;
	ADOQuery1->Active = true ;
	DateTimePicker1->Date = ADOQuery1->FieldByName("pd")->AsDateTime ;
	DateTimePicker2->Time = dt.TimeString() ;

	DM2->adoQ_AutoWrks->Active = false ;
	DM2->adoQ_AutoWrks->Filtered = false ;
String wrk_str = String("select ks.kind, ks.caption from kind_services ks where ks.parent = 0 ;") ;
	DM2->adoQ_AutoWrks->SQL->Text = wrk_str ;
	DM2->adoQ_AutoWrks->Active = true ;
		while(!DM2->adoQ_AutoWrks->Eof)
	{
		ComboBox2->AddItem(DM2->adoQ_AutoWrks->FieldByName("caption")->AsString,
			(TObject*)DM2->adoQ_AutoWrks->FieldByName("kind")->AsInteger) ;
		DM2->adoQ_AutoWrks->Next() ;
	}

	DM2->adoQ_AZS->Active = false ;
	DM2->adoQ_AZS->Filtered = false ;
	String fs_str = String("select fs.id, fs.caption, fs.rating from contragents fs order by fs.rating, fs.caption;") ;
	DM2->adoQ_AZS->SQL->Text = fs_str ;
	DM2->adoQ_AZS->Active = true ;
		while(!DM2->adoQ_AZS->Eof)
	{
		ComboBox3->AddItem(DM2->adoQ_AZS->FieldByName("caption")->AsString,
			(TObject*)DM2->adoQ_AZS->FieldByName("id")->AsInteger) ;
		DM2->adoQ_AZS->Next() ;
	}

	DM2->adoQ_FuelTypes->Active = false ;
	DM2->adoQ_FuelTypes->Filtered = false ;
	String ft_str = String("select kf.kind, kf.caption from kind_fuel kf ;") ;
	DM2->adoQ_FuelTypes->SQL->Text = ft_str ;
	DM2->adoQ_FuelTypes->Active = true ;
		while(!DM2->adoQ_FuelTypes->Eof)
	{
		ComboBox4->AddItem(DM2->adoQ_FuelTypes->FieldByName("caption")->AsString,
			(TObject*)DM2->adoQ_FuelTypes->FieldByName("kind")->AsInteger) ;
		DM2->adoQ_FuelTypes->Next() ;
	}

}
//---------------------------------------------------------------------------
void __fastcall TRefueling_Form::BitBtn2Click(TObject *Sender)
{
	Application->Terminate() ;
	return ;

Timer1->Enabled = true ;
ComboBox1->Clear() ;
ComboBox2->Clear() ;
ComboBox3->Clear() ;

Refueling_Form->Visible = false ;
Refueling_Form->Destroying() ;
}
//---------------------------------------------------------------------------

void __fastcall TRefueling_Form::Edit3Change(TObject *Sender)
{
String q = Edit3->Text ;
q1 = StrToInt(q) ;
//Edit4->Font->Style->fsBold = true ;
//Edit4->Font->Style = fsUnderline ;
int prob = q1 - cur_mileage ;
Edit4->Text = prob ;
Edit13->Text = q1 - cur_GhgGRMbelt ;
Edit15->Text = q1 - cur_GhgGeneratorBelt ;
Edit14->Text = q1 - cur_GhgGURbelt ;
Edit16->Text = q1 - cur_ChgCondBelt ;
Edit1->Text = q1 - cur_GhgOil ;
//Edit20->Text = wd ;
Edit2->Text = q1 - cur_GhgSpPlug ;
Edit11->Text = q1 - cur_ChgHiVoltWires ;
Edit12->Text = q1 - cur_ChgOil_KPP ;
Edit18->Text = q1 - cur_ChgFrontBrakePad ;
Edit19->Text = q1 - cur_ChgRearBrakePad ;
}
//---------------------------------------------------------------------------
void __fastcall TRefueling_Form::BitBtn1Click(TObject *Sender)
{
ADOQuery1->Active = false ;
String srv_str = String("select count(id) as cnt from contragents where caption = '" + String(ComboBox3->Text) + "' ;") ;
ADOQuery1->SQL->Text = srv_str ;
ADOQuery1->Active = true ;
short r = ADOQuery1->FieldByName("cnt")->AsInteger ;
if (0 == r)
{
int q_contr = Application->MessageBoxW(String("Контрагента нет в списке. Создать?").w_str(),String("Вопрос").w_str(),MB_YESNO + MB_ICONQUESTION) ;
switch(q_contr)
{
case IDYES:
	{
	String add_str = String("insert into contragents(caption, rating) values('" + String(ComboBox3->Text) + "',0) ;") ;
	ADOCommand1->CommandText = add_str ;
	ADOCommand1->Execute() ;

	Application->CreateForm(__classid(TAddSrv_Type_Form), &AddSrv_Type_Form) ;
//	AddSrv_Type_Form->Visible = true ;
	if (AddSrv_Type_Form->ShowModal() == bkOK)
	{
		String addsrv_type = String("update contragents \
set \
fuel = " + String(AddSrv_Type_Form->CheckBox1->State) + ", washing = " + String(AddSrv_Type_Form->CheckBox2->State) + ", \
service = " + String(AddSrv_Type_Form->CheckBox3->State) + ", repair = " + String(AddSrv_Type_Form->CheckBox4->State) + ", \
spares = " + String(AddSrv_Type_Form->CheckBox5->State) + ", market = " + String(AddSrv_Type_Form->CheckBox6->State) + " \
where caption = '" + String(ComboBox3->Text) + "' ; ") ;
		ADOCommand1->CommandText = addsrv_type ;
		ADOCommand1->Execute() ;
	break ;
	}
	}
	case IDNO: break ;
}
}

fs = select_f_station() ;

if (cur_mileage < q1)
	{
	if (1 == ks)
	{
		String miles_str = String("update t_CarModels \
		set \
		current_mileage = " + String(q1) + " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = miles_str ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox2->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_GhgOil_ON = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox3->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_GhgSpPlug_ON = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox4->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_ChgHiVoltWires_ON = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox5->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_ChgOil_KPP_ON = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox6->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_GhgGRMbelt_ON = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox7->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_GhgGURbelt_ON = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox8->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_GhgGeneratorBelt_ON = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox9->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_ChgCondBelt_ON = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox10->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_ChgFrontBrakePad = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	if (3 == ks && true == CheckBox11->Checked)
	{
		String str_Oil = String("update t_CarModels \
		set \
		Trip_ChgRearBrakePad = "  + String(q1) +  " \
		where id = " + String(curr_car) + " ;") ;
		ADOCommand1->CommandText = str_Oil ;
		ADOCommand1->Execute() ;
	}
	}
	if ("" == Edit6->Text) Edit6->Text = "0" ;
	if ("" == Edit5->Text) Edit5->Text = "0" ;
	if ("" == Edit9->Text) Edit9->Text = "0" ;
String main_str = String("insert into t_autofuel(DateFuelling, CurrDistance, DistanceBetween_c, FuelType, \
FuelLitreCost, FuelValue, FuellingCost_c, DopPurhase, DopPurchaseCost, TotalCost_c, PlaceFuelling, FuelConsumption_c, \
DistFromLastChgOil_c, DistFromLastChgGRMbelt_c, DistFromLastChgSpPlug_c, DistFromLastChgGenBelt_c, DistFromLastChgGURbelt_c, \
DistFromLastChgHiVoltWires, DistFromLastChgOil_KPP, DistFromLastChgCondBelt, DistFromLastChgFrontBrakePad, \
DistFromLastChgRearBrakePad, Car, Wrk_Type,Fuel_Left,Planning_Distance) values\
('" + DateToStr(DateTimePicker1->Date) + " " + TimeToStr(DateTimePicker2->Time) + "'," + String(Edit3->Text) + "," + String(Edit4->Text) + ",\
" + String(kf) + "," + String(Edit6->Text) + "," + String(Edit5->Text) + "," + String(Edit7->Text) + ",\
'" + String(Edit8->Text) + "'," + String(Edit10->Text) + "," + String(Edit17->Text) + "," + String(fs) + ",\
" + String(Edit9->Text) + "," + String(Edit1->Text) + "," + String(Edit13->Text) + "," + String(Edit2->Text) + ",\
" + String(Edit15->Text) + "," + String(Edit14->Text) + "," + String(Edit11->Text) + "," + String(Edit12->Text) + ",\
" + String(Edit16->Text) + "," + String(Edit18->Text) + "," + String(Edit19->Text) + ",\
" + String(curr_car) + "," + String(ks) + "," + String(Edit22->Text) + "," + String(Edit31->Text) + ") ;" ) ;
//Edit8->Text = main_str ;
	ADOCommand1->CommandText = main_str ;
	ADOCommand1->Execute() ;

/*
insert into t_autofuel(DateFuelling, CurrDistance, DistanceBetween_c, FuelType, FuelLitreCost, FuelValue, FuellingCost_c,
DopPurhase, DopPurchaseCost, TotalCost_c, PlaceFuelling, FuelConsumption_c, DistFromLastChgOil_c, DistFromLastChgGRMbelt_c,
DistFromLastChgSpPlug_c, DistFromLastChgGenBelt_c, DistFromLastChgGURbelt_c, DistFromLastChgHiVoltWires, DistFromLastChgOil_KPP,
DistFromLastChgCondBelt, DistFromLastChgFrontBrakePad, DistFromLastChgRearBrakePad, Car, Wrk_Type,Fuel_Left,Planning_Distance)
values('11.09.2013 19:02:19',229918,368,1,32,1,35,1123,5,'',0,1123,5,153,8,15,13468,29387,13468,29387,29387,23200,24469,29387,20164,44860,1,1,9,540) ;
*/

	if (1 == DM2->incr_rating("C", fs, rating)) {}

if (true == CheckBox1->Checked)
{
// создание платежа по какой-либо автоработе
Application->CreateForm(__classid(TAddAcc_Form), &AddAcc_Form) ;
	if (AddAcc_Form->ShowModal() == bkOK)
	{
	AddAcc_Form->Top = Refueling_Form->Top + 20 ;
	AddAcc_Form->Left = Refueling_Form->Left + 25 ;
String pay_str = String("insert into payments(auto, pay_date, pay_service,contragent,\
pay_category, account_out, expense,kind_payment,sp_payment) values(" + String(curr_car) + ",'\
" + DateToStr(DateTimePicker1->Date) + " " + TimeToStr(DateTimePicker2->Time) + "'," + String(ks) + ",\
" + String(fs) + ",1," + String(acc_out) + "," + String(Edit17->Text) + ",1," + String(kind_pay) + ") ;" ) ;
	ADOCommand1->CommandText = pay_str ;
	ADOCommand1->Execute() ;

	double bal_out =  chk_balL(acc_out) - StrToFloat(Edit17->Text) ;
	String upd_balance = String("update accounts set balance = " + String(bal_out) + " where id = " + String(acc_out) + " ;") ;
	ADOCommand1->CommandText = upd_balance ;
	ADOCommand1->Execute() ;

	if (1 == DM2->incr_rating("A", acc_out, acc_udw)) {}
	}
}
else
{
int res = Application->MessageBoxW(String("Вы не создали оплату. Создать?").w_str(),String("Вопрос").w_str(),MB_YESNOCANCEL + MB_ICONQUESTION) ;
switch(res)
{
case IDYES:
	{
Application->CreateForm(__classid(TAddAcc_Form), &AddAcc_Form) ;
	if (AddAcc_Form->ShowModal() == bkOK)
	{String pay_str = String("insert into payments(auto, pay_date, pay_service,contragent,\
pay_category, account_out, expense,kind_payment) values(" + String(curr_car) + ",'\
" + DateToStr(DateTimePicker1->Date) + " " + TimeToStr(DateTimePicker2->Time) + "'," + String(ks) + ",\
" + String(fs) + ",1," + String(acc_out) + "," + String(Edit17->Text) + ",1) ;" ) ;
	ADOCommand1->CommandText = pay_str ;
	ADOCommand1->Execute() ;

double bal_out =  chk_balL(acc_out) - StrToFloat(Edit1->Text) ;
String upd_balance = String("update accounts set balance = " + String(bal_out) + " where id = " + String(acc_out) + " ;") ;
ADOCommand1->CommandText = upd_balance ;
ADOCommand1->Execute() ;

if (1 == DM2->incr_rating("A", acc_out, acc_udw)) {}
	break ;
    }
	}
case IDNO: break ;
case IDCANCEL: break ; //прописать отмену закрытия формы
}
}

if (1 == ks)
{
ADOQuery1->Active = false ;
String exp_str = String("select ((100 * sum(FuelValue)) / sum(DistanceBetween_c)) as glob_exp_fu from t_autofuel where car = " + String(curr_car) + " and Wrk_Type = " + String(ks) + " ;") ;
ADOQuery1->SQL->Text = exp_str ;
ADOQuery1->Active = true ;
double glb_fu = ADOQuery1->FieldByName("glob_exp_fu")->AsFloat ;

	String exp_FGlob_str = String("update t_CarModels as c \
set \
c.Avg_FuelExpense = " + String(glb_fu) + " \
where c.id  = " + String(curr_car) + " ;") ;
	ADOCommand1->CommandText = exp_FGlob_str ;
	ADOCommand1->Execute() ;
}

ADOQuery1->Active = false ;
String mid_str = String("select max(id)as max_id from payments ;") ;
ADOQuery1->SQL->Text = mid_str ;
ADOQuery1->Active = true ;
short max_id_p = ADOQuery1->FieldByName("max_id")->AsInteger ;

ADOQuery1->Active = false ;
String mid_w_str = String("select max(id)as max_id from t_autofuel ;") ;
ADOQuery1->SQL->Text = mid_w_str ;
ADOQuery1->Active = true ;
short max_id_w = ADOQuery1->FieldByName("max_id")->AsInteger ;

String upd_auto_wrk = String("update t_autofuel set payment_id = " + String(max_id_p) + " where id = "+String(max_id_w)+" ;") ;
ADOCommand1->CommandText =upd_auto_wrk ;
ADOCommand1->Execute() ;

	ComboBox1->Clear() ;
	ComboBox2->Clear() ;
	ComboBox3->Clear() ;
	//Refueling_Form->DateTimePicker1->Date = current_date ;
    car_statistic(curr_car) ;
	Refueling_Form->Visible = false ;
//	Refueling_Form->Free() ;

}
//---------------------------------------------------------------------------

void __fastcall TRefueling_Form::ComboBox2Select(TObject *Sender)
{
String str = String("caption = '" + ComboBox2->Text + "'") ;
DM2->adoQ_AutoWrks->Active = false ;
DM2->adoQ_AutoWrks->Filter = str ;
DM2->adoQ_AutoWrks->Filtered = true ;
DM2->adoQ_AutoWrks->Active = true ;
ks = DM2->adoQ_AutoWrks->FieldByName("kind")->AsInteger ;
//Edit1->Text = ks ;
if (3 == ks)
{
CheckBox2->Enabled = true ;
CheckBox3->Enabled = true ;
CheckBox4->Enabled = true ;
CheckBox5->Enabled = true ;
CheckBox6->Enabled = true ;
CheckBox7->Enabled = true ;
CheckBox8->Enabled = true ;
CheckBox9->Enabled = true ;
CheckBox10->Enabled = true ;
CheckBox11->Enabled = true ;

ComboBox3->Clear() ;

	DM2->adoQ_AZS->Active = false ;
String fs_str = String("select fs.id, fs.caption, fs.rating from contragents fs where service <> 0 order by fs.rating, fs.caption ;") ;
	DM2->adoQ_AZS->SQL->Text = fs_str ;
	DM2->adoQ_AZS->Active = true ;
		while(!DM2->adoQ_AZS->Eof)
	{
		ComboBox3->AddItem(DM2->adoQ_AZS->FieldByName("caption")->AsString,
			(TObject*)DM2->adoQ_AZS->FieldByName("id")->AsInteger) ;
		DM2->adoQ_AZS->Next() ;
	}
Label9->Caption = "Итого обслуживание, руб." ;
Label6->Caption = "Пробег с последнего обслуживания, км (р)" ;
Label6->Enabled = true ;
Label19->Caption = "Сервис";
Label19->Left = 8 ;
Label7->Enabled = false ;
Label18->Enabled = false ;
ComboBox4->Enabled = false ;
ComboBox4->Color = clBtnFace ;
Edit5->Enabled = false ;
Edit5->Color = clBtnFace ;
Edit6->Enabled = false ;
Edit6->Color = clBtnFace ;
Label8->Enabled = false ;
Edit9->Enabled = false ;
Edit9->Color = clBtnFace ;
Label11->Enabled = false ;
}
if (1 == ks)
{
CheckBox2->Enabled = false ;
CheckBox2->Checked = false ;
CheckBox3->Enabled = false ;
CheckBox3->Checked = false ;
CheckBox4->Enabled = false ;
CheckBox4->Checked = false ;
CheckBox5->Enabled = false ;
CheckBox5->Checked = false ;
CheckBox6->Enabled = false ;
CheckBox6->Checked = false ;
CheckBox7->Enabled = false ;
CheckBox7->Checked = false ;
CheckBox8->Enabled = false ;
CheckBox8->Checked = false ;
CheckBox9->Enabled = false ;
CheckBox9->Checked = false ;
CheckBox10->Enabled = false ;
CheckBox10->Checked = false ;
CheckBox11->Enabled = false ;
CheckBox11->Checked = false ;
Label9->Caption = "Итого бензин, руб." ;
Label6->Caption = "Пробег с последней заправки, км (р)" ;
Label6->Enabled = true ;
Label19->Caption = "АЗС/Сервис";
Label19->Left = 8 ;
Label7->Enabled = true ;
Label18->Enabled = true ;
ComboBox4->Enabled = true ;
ComboBox4->Color = clWindow ;
Edit5->Enabled = true ;
Edit5->Color = clWindow ;
Edit6->Enabled = true ;
Edit6->Color = clWindow ;
Label8->Enabled = true ;
Edit9->Enabled = true ;
Edit9->Color = clWindow ;
Label11->Enabled = true ;

ComboBox3->Clear() ;
DM2->adoQ_AZS->Active = false ;
String fs_str = String("select fs.id, fs.caption, fs.rating from contragents fs where fuel <> 0 order by fs.rating, fs.caption ;") ;
DM2->adoQ_AZS->SQL->Text = fs_str ;
DM2->adoQ_AZS->Active = true ;
	while(!DM2->adoQ_AZS->Eof)
	{
		ComboBox3->AddItem(DM2->adoQ_AZS->FieldByName("caption")->AsString,
			(TObject*)DM2->adoQ_AZS->FieldByName("id")->AsInteger) ;
		DM2->adoQ_AZS->Next() ;
	}

}
if (2 == ks)
{
CheckBox2->Enabled = false ;
CheckBox2->Checked = false ;
CheckBox3->Enabled = false ;
CheckBox3->Checked = false ;
CheckBox4->Enabled = false ;
CheckBox4->Checked = false ;
CheckBox5->Enabled = false ;
CheckBox5->Checked = false ;
CheckBox6->Enabled = false ;
CheckBox6->Checked = false ;
CheckBox7->Enabled = false ;
CheckBox7->Checked = false ;
CheckBox8->Enabled = false ;
CheckBox8->Checked = false ;
CheckBox9->Enabled = false ;
CheckBox9->Checked = false ;
CheckBox10->Enabled = false ;
CheckBox10->Checked = false ;
CheckBox11->Enabled = false ;
CheckBox11->Checked = false ;

ComboBox3->Clear() ;
DM2->adoQ_AZS->Active = false ;
String fs_str = String("select fs.id, fs.caption,fs.rating from contragents fs where washing <> 0 order by fs.rating, fs.caption ;") ;
DM2->adoQ_AZS->SQL->Text = fs_str ;
DM2->adoQ_AZS->Active = true ;
	while(!DM2->adoQ_AZS->Eof){
		ComboBox3->AddItem(DM2->adoQ_AZS->FieldByName("caption")->AsString,
			(TObject*)DM2->adoQ_AZS->FieldByName("id")->AsInteger) ;
		DM2->adoQ_AZS->Next() ;
	}
	Label9->Caption = "Итого мойка, руб." ;
	Label6->Caption = "Пробег с последней мойки, км" ;
	Label6->Enabled = true ;
	Label19->Caption = "Автомойка";
	Label19->Left = 8 ;
	Label7->Enabled = false ;
Label18->Enabled = false ;
ComboBox4->Enabled = false ;
ComboBox4->Color = clBtnFace ;
Edit5->Enabled = false ;
Edit5->Color = clBtnFace ;
Edit6->Enabled = false ;
Edit6->Color = clBtnFace ;
Label8->Enabled = false ;
Edit9->Enabled = false ;
Edit9->Color = clBtnFace ;
Label11->Enabled = false ;

}
if (4 == ks){
	CheckBox2->Enabled = false ;
	CheckBox2->Checked = false ;
	CheckBox3->Enabled = false ;
	CheckBox3->Checked = false ;
	CheckBox4->Enabled = false ;
	CheckBox4->Checked = false ;
	CheckBox5->Enabled = false ;
	CheckBox5->Checked = false ;
	CheckBox6->Enabled = false ;
	CheckBox6->Checked = false ;
	CheckBox7->Enabled = false ;
	CheckBox7->Checked = false ;
	CheckBox8->Enabled = false ;
	CheckBox8->Checked = false ;
	CheckBox9->Enabled = false ;
	CheckBox9->Checked = false ;
	CheckBox10->Enabled = false ;
	CheckBox10->Checked = false ;
	CheckBox11->Enabled = false ;
	CheckBox11->Checked = false ;

	ComboBox3->Clear() ;
	DM2->adoQ_AZS->Active = false ;
	String fs_str = String("select fs.id, fs.caption, fs.rating from contragents fs where repair <> 0 order by fs.rating, fs.caption ;") ;
	DM2->adoQ_AZS->SQL->Text = fs_str ;
	DM2->adoQ_AZS->Active = true ;
		while(!DM2->adoQ_AZS->Eof){
			ComboBox3->AddItem(DM2->adoQ_AZS->FieldByName("caption")->AsString,
				(TObject*)DM2->adoQ_AZS->FieldByName("id")->AsInteger) ;
			DM2->adoQ_AZS->Next() ;
		}
	Label9->Caption = "Итого ремонт, руб." ;
	Label6->Caption = "Пробег с последнего ремонта, км. (р)" ;
	Label6->Enabled = true ;
	Label19->Caption = "Сервис";
	Label19->Left = 8 ;
	Label7->Enabled = false ;
	Label18->Enabled = false ;
	ComboBox4->Enabled = false ;
	ComboBox4->Color = clBtnFace ;
	Edit5->Enabled = false ;
	Edit5->Color = clBtnFace ;
	Edit6->Enabled = false ;
	Edit6->Color = clBtnFace ;
	Label8->Enabled = false ;
	Edit9->Enabled = false ;
	Edit9->Color = clBtnFace ;
	Label11->Enabled = false ;
}
if (16 == ks){
	CheckBox2->Enabled = false ;
	CheckBox2->Checked = false ;
	CheckBox3->Enabled = false ;
	CheckBox3->Checked = false ;
	CheckBox4->Enabled = false ;
	CheckBox4->Checked = false ;
	CheckBox5->Enabled = false ;
	CheckBox5->Checked = false ;
	CheckBox6->Enabled = false ;
	CheckBox6->Checked = false ;
	CheckBox7->Enabled = false ;
	CheckBox7->Checked = false ;
	CheckBox8->Enabled = false ;
	CheckBox8->Checked = false ;
	CheckBox9->Enabled = false ;
	CheckBox9->Checked = false ;
	CheckBox10->Enabled = false ;
	CheckBox10->Checked = false ;
	CheckBox11->Enabled = false ;
	CheckBox11->Checked = false ;

	ComboBox3->Clear() ;
	DM2->adoQ_AZS->Active = false ;
	String fs_str = String("select fs.id, fs.caption, fs.rating from contragents fs where spares <> 0 order by fs.rating, fs.caption ;") ;
	DM2->adoQ_AZS->SQL->Text = fs_str ;
	DM2->adoQ_AZS->Active = true ;
	while(!DM2->adoQ_AZS->Eof){
		ComboBox3->AddItem(DM2->adoQ_AZS->FieldByName("caption")->AsString,
			(TObject*)DM2->adoQ_AZS->FieldByName("id")->AsInteger) ;
		DM2->adoQ_AZS->Next() ;
	}
Label9->Caption = "Итого запчастей, руб." ;
Label6->Enabled = false ;
Label19->Caption = "Продавец" ;
Label19->Left = 8 ;
Label7->Enabled = false ;
Label18->Enabled = false ;
ComboBox4->Enabled = false ;
ComboBox4->Color = clBtnFace ;
Edit5->Enabled = false ;
Edit5->Color = clBtnFace ;
Edit6->Enabled = false ;
Edit6->Color = clBtnFace ;
Label8->Enabled = false ;
Edit9->Enabled = false ;
Edit9->Color = clBtnFace ;
Label11->Enabled = false ;
}
ADOQuery1->Active = false ;
String str1 = String("select CurrDistance, DistanceBetween_c, FuelValue, Planning_Distance \
from t_autofuel \
where DateFuelling = (select max(DateFuelling) from t_autofuel where wrk_type = " + String(ks) + " \
and car = " + String(curr_car) + ") ;") ;
ADOQuery1->SQL->Text = str1 ;
ADOQuery1->Active = true ;

cur_mileage = ADOQuery1->FieldByName("CurrDistance")->AsInteger ;

	if (1 == ks ){
		fv = ADOQuery1->FieldByName("FuelValue")->AsInteger ;
		Edit32->Text = ADOQuery1->FieldByName("Planning_Distance")->AsInteger ;
	}
	else{
		fv = 0 ;
		Edit9->Text = "" ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TRefueling_Form::ComboBox3Select(TObject *Sender)
{
fs = select_f_station() ;
}
//---------------------------------------------------------------------------


void __fastcall TRefueling_Form::ComboBox4Select(TObject *Sender)
{
//	String str = String("caption = '" + ComboBox4->Text + "'") ;
 /*	DM2->adoQ_FuelTypes->Active = false ;
	DM2->adoQ_FuelTypes->Filter = str ;
	DM2->adoQ_FuelTypes->Filtered = true ;
	DM2->adoQ_FuelTypes->Active = true ;
	kf = DM2->adoQ_FuelTypes->FieldByName("kind")->AsInteger ;
 */
	AnsiString str = ComboBox4->Text ;
	int fb = sbFuelType.findUnitByName(str.c_str()) ;
//	int rat = sbFuelType.updateRating(fb) ;
//	Edit8->Text = IntToStr(rat) ;
}
//---------------------------------------------------------------------------

/*
Из модуля ComboBox2Select - попытки создания, контроля наличия и удаления
программно создаваемых CheckBox на форме
if (3 == ks)
{
if (!FindComponent("c2"))
{
TCheckBox *c2 = new TCheckBox(this->GroupBox1) ;
c2->Parent = Refueling_Form->GroupBox1 ;
c2->Name = "cb2" ;
c2->Left = 223 ;
c2->Top = 37 ;
c2->Caption = "" ;
}
}
if(3 != ks)
{
if (FindComponent("c2"))
{
	CheckBox2->Hide() ;
	TComponent *c2 = FindComponent("cb2") ;
	c2->DestroyComponents() ;
}
}
}
*/
//---------------------------------------------------------------------------
void __fastcall TRefueling_Form::Edit6Exit(TObject *Sender)
{
double fuel_cost = round((Edit5->Text.ToDouble() * Edit6->Text.ToDouble()),2) ;
Edit7->Text = fuel_cost ;
}
//---------------------------------------------------------------------------

void __fastcall TRefueling_Form::Edit10Exit(TObject *Sender)
{
if ("" == Edit10->Text) Edit10->Text = 0 ;
Edit17->Text = Edit7->Text.ToDouble() + Edit10->Text.ToDouble() ;
}
//---------------------------------------------------------------------------

void __fastcall TRefueling_Form::Edit3Exit(TObject *Sender)
{
if (1 == ks){
ADOQuery1->Active = false ;
String str = String("select af.DistanceBetween_c, af.FuelValue, DateDiff('d',af.DateFuelling,'" + DateToStr(date_service) + "') as date_dif \
from t_autofuel as af \
where af.DateFuelling = (select max(DateFuelling) from t_autofuel where wrk_type = 1 and car = " + String(curr_car) + ") \
and af.car = " + String(curr_car) + " ;") ;
ADOQuery1->SQL->Text = str ;
ADOQuery1->Active = true ;
double fv = ADOQuery1->FieldByName("FuelValue")->AsInteger ;
double prob_if = Edit4->Text.ToDouble() ;
double expens = round(((100 * fv) / prob_if),2) ;
int df = ADOQuery1->FieldByName("date_dif")->AsInteger ;
if (1 > df) df = 1 ;

int prob = q1 - cur_mileage ;
String nsd ;

Edit20->Text = CalcFutureSrvDate(df, prob, dist_GhgOil, cur_GhgOil, date_service, nsd) ;
Edit21->Text = CalcFutureSrvDate(df, prob, dist_GhgSpPlug, cur_GhgSpPlug, date_service, nsd) ;
Edit23->Text = CalcFutureSrvDate(df, prob, dist_ChgHiVoltWires, cur_ChgHiVoltWires, date_service, nsd) ;
Edit24->Text = CalcFutureSrvDate(df, prob, dist_ChgOil_KPP, cur_ChgOil_KPP, date_service, nsd) ;
Edit25->Text = CalcFutureSrvDate(df, prob, dist_GhgGRMbelt, cur_GhgGRMbelt, date_service, nsd) ;
Edit26->Text = CalcFutureSrvDate(df, prob, dist_GhgGURbelt, cur_GhgGURbelt, date_service, nsd) ;
Edit27->Text = CalcFutureSrvDate(df, prob, dist_GhgGeneratorBelt, cur_GhgGeneratorBelt, date_service, nsd) ;
Edit28->Text = CalcFutureSrvDate(df, prob, dist_ChgCondBelt, cur_ChgCondBelt, date_service, nsd) ;
Edit29->Text = CalcFutureSrvDate(df, prob, dist_ChgFrontBrakePad, cur_ChgFrontBrakePad, date_service, nsd) ;
Edit30->Text = CalcFutureSrvDate(df, prob, dist_ChgRearBrakePad, cur_ChgRearBrakePad, date_service, nsd) ;

Edit9->Text = expens  ;

}
Edit13->Font->Color = calc_proc(q1, cur_GhgGRMbelt, dist_GhgGRMbelt) ;
Edit15->Font->Color = calc_proc(q1, cur_GhgGeneratorBelt, dist_GhgGeneratorBelt) ;
Edit14->Font->Color = calc_proc(q1, cur_GhgGURbelt, dist_GhgGURbelt) ;
Edit16->Font->Color = calc_proc(q1, cur_ChgCondBelt, dist_ChgCondBelt) ;
Edit1->Font->Color = calc_proc(q1, cur_GhgOil, dist_GhgOil) ;
Edit2->Font->Color = calc_proc(q1, cur_GhgSpPlug, dist_GhgSpPlug) ;
Edit11->Font->Color = calc_proc(q1, cur_ChgHiVoltWires, dist_ChgHiVoltWires) ;
Edit12->Font->Color = calc_proc(q1, cur_ChgOil_KPP, dist_ChgOil_KPP) ;
Edit18->Font->Color = calc_proc(q1, cur_ChgFrontBrakePad, dist_ChgFrontBrakePad) ;
Edit19->Font->Color = calc_proc(q1, cur_ChgRearBrakePad, dist_ChgRearBrakePad) ;
}
//---------------------------------------------------------------------------
void __fastcall TRefueling_Form::DateTimePicker1Exit(TObject *Sender)
{
	date_service = DateTimePicker1->Date ;
}
//---------------------------------------------------------------------------

void __fastcall TRefueling_Form::Timer1Timer(TObject *Sender)
{
BitBtn2->Cursor = crHourGlass ;
Timer1->Enabled = false ;
}
//---------------------------------------------------------------------------
void __fastcall TRefueling_Form::FormClose(TObject *Sender, TCloseAction &Action)

{
//car_statistic(curr_car) ;
}
//---------------------------------------------------------------------------

void __fastcall TRefueling_Form::ComboBox1Select(TObject *Sender)
{
// добавить отработку смены авто из формы
}
//---------------------------------------------------------------------------

void __fastcall TRefueling_Form::Edit5Exit(TObject *Sender)
{
	double tot_fuel = StrToInt(Edit22->Text) + (Edit5->Text).ToDouble() ;
	double stockMove = tot_fuel * 100 / StrToFloat(Edit9->Text) ;
	Edit31->Text = round(stockMove,0) ;
}
//---------------------------------------------------------------------------

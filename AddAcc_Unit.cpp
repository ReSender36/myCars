//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddAcc_Unit.h"
#include "DM2_Unit.h"
#include "Refueling_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddAcc_Form *AddAcc_Form;
short acc_parent = 0 ;
short acc_out = 0 ;
short kind_pay = 0 ;
short acc_udw = 0 ;
//---------------------------------------------------------------------------
__fastcall TAddAcc_Form::TAddAcc_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAddAcc_Form::FormCreate(TObject *Sender)
{

if ("" == ComboBox2->Text) ComboBox2->Text = "¬ведите банк-оператор счета" ;
if ("" == ComboBox1->Text) ComboBox1->Text = "”кажите счет" ;

ADOQuery1->Active = false ;
ADOQuery1->Filtered = false ;
String str = String("select id, account, cash from accounts where parent = 0 ;") ;
ADOQuery1->SQL->Text = str ;
ADOQuery1->Active = true ;
ADOQuery1->First() ;
	while(!ADOQuery1->Eof)
	{
		ComboBox2->AddItem(ADOQuery1->FieldByName("account")->AsString,
			(TObject*)ADOQuery1->FieldByName("id")->AsInteger) ;
		ADOQuery1->Next() ;
	}

ADOQuery1->Active = false ;
str = String("select kind, caption from kind_payments where type = 2 ;") ;
ADOQuery1->SQL->Text = str ;
ADOQuery1->Active = true ;
ADOQuery1->First() ;
	while(!ADOQuery1->Eof)
	{
		ComboBox3->AddItem(ADOQuery1->FieldByName("caption")->AsString,
			(TObject*)ADOQuery1->FieldByName("kind")->AsInteger) ;
		ADOQuery1->Next() ;
	}

}
//---------------------------------------------------------------------------
void __fastcall TAddAcc_Form::ComboBox2Select(TObject *Sender)
{
String str = String("account = '" + ComboBox2->Text + "'") ;
ADOQuery1->Active = false ;
ADOQuery1->Filter = str ;
String strQ = String("select id, account, ud_weight, cash from accounts where parent = 0 ;") ;
ADOQuery1->SQL->Text = strQ ;
ADOQuery1->Filtered = true ;
ADOQuery1->Active = true ;
acc_parent = ADOQuery1->FieldByName("id")->AsInteger ;
short cash = ADOQuery1->FieldByName("cash")->AsBoolean ;
acc_udw = ADOQuery1->FieldByName("ud_weight")->AsInteger ;
if (0 == cash) ComboBox1->Enabled = true ;
else
{
acc_out = acc_parent ;

}
ADOQuery1->Active = false ;
ADOQuery1->Filtered = false ;
String str_acc = String("select id, account, cash from accounts where parent = " + String(acc_parent) + " ;") ;
ADOQuery1->SQL->Text = str_acc ;
ADOQuery1->Active = true ;
ADOQuery1->First() ;
	while(!ADOQuery1->Eof)
	{
		ComboBox1->AddItem(ADOQuery1->FieldByName("account")->AsString,
			(TObject*)ADOQuery1->FieldByName("id")->AsInteger) ;
		ADOQuery1->Next() ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TAddAcc_Form::ComboBox2Exit(TObject *Sender)
{
if ("" == ComboBox2->Text) ComboBox2->Text = "”кажите банк-оператор счета" ;
}
//---------------------------------------------------------------------------

void __fastcall TAddAcc_Form::ComboBox2Click(TObject *Sender)
{
if ("”кажите банк-оператор счета" == ComboBox2->Text) ComboBox2->Text = "" ;

}
//---------------------------------------------------------------------------

void __fastcall TAddAcc_Form::ComboBox3Select(TObject *Sender)
{
String str_kp = String("caption = '" + ComboBox3->Text + "'") ;
String strQ = String("select kind, caption from kind_payments where type = 2 ;") ;
ADOQuery1->Active = false ;
ADOQuery1->Filter = str_kp ;
ADOQuery1->SQL->Text = strQ ;
ADOQuery1->Filtered = true ;
ADOQuery1->Active = true ;

kind_pay = ADOQuery1->FieldByName("kind")->AsInteger ;
}
//---------------------------------------------------------------------------

void __fastcall TAddAcc_Form::ComboBox1Select(TObject *Sender)
{
String str_acc = String("account = '" + ComboBox1->Text + "'") ;
String strQ = String("select id, account, cash, ud_weight from accounts where parent = " + String(acc_parent) + " ;") ;
ADOQuery1->SQL->Text = str_acc ;
ADOQuery1->Active = false ;
ADOQuery1->Filter = str_acc ;
ADOQuery1->SQL->Text = strQ ;
ADOQuery1->Filtered = true ;
ADOQuery1->Active = true ;

acc_out = ADOQuery1->FieldByName("id")->AsInteger ;
acc_udw = ADOQuery1->FieldByName("ud_weight")->AsInteger ;
}
//---------------------------------------------------------------------------

void __fastcall TAddAcc_Form::ComboBox1Click(TObject *Sender)
{
if ("”кажите счет" == ComboBox1->Text) ComboBox1->Text = "" ;
}
//---------------------------------------------------------------------------

void __fastcall TAddAcc_Form::ComboBox1Exit(TObject *Sender)
{
if ("" == ComboBox1->Text) ComboBox1->Text = "”кажите счет" ;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#pragma hdrstop

#include <string.h>
#include "DM2_Unit.h"
//#include "Automobile.h"
#include "SourceBook_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
SourceBook::SourceBook(){
}
//---------------------------------------------------------------------------
SourceBook::SourceBook(const char *Table){
	SourceBook::TABLE_NAME = Table ;
	AnsiString str = String("SELECT KIND, CAPTION, RATING FROM ") ;
	str = str + Table + " " ;
	str = str + String("ORDER BY RATING DESC") ;

	SourceBook::BASE_REQUEST = str.c_str() ;
	SourceBook::id = 0 ;
	SourceBook::rating = 0 ;
	SourceBook::name = "" ;
}
//---------------------------------------------------------------------------
SourceBook::SourceBook(String *Table, String *Name){
/*	String str = String("SELECT KIND, CAPTION, RATING FROM ") ;
	str = str + Table ;
	String str_par = String("caption = '" + name + "'") ;
	DM2->fdqSourceBook->SQL->Text = str ;
	DM2->fdqSourceBook->Params->Add(str_par) ;
	DM2->fdqSourceBook->Active = true ;
	SourceBook::id = DM2->fdqSourceBook->FieldByName("KIND")->AsInteger ;
	SourceBook::rating = DM2->fdqSourceBook->FieldByName("RATING")->AsInteger ;*/
}
//---------------------------------------------------------------------------
void SourceBook::addNew(String Name){
//	DM2->adoQ_FirstReq

}
//---------------------------------------------------------------------------
void SourceBook::addNew(SourceBook *sb){
//	sb->
}
//---------------------------------------------------------------------------
void SourceBook::updateRating(int id){
	int iNewRating = SourceBook::rating + 1 ;
	String str_command = String("UPDATE KIND_FUEL SET RATING = " + IntToStr(iNewRating) + " where KIND = " + IntToStr(id) + " ;") ;
	DM2->fdcSourceBooks->CommandText->Add(str_command) ;
	DM2->fdcSourceBooks->Execute() ;
}
//---------------------------------------------------------------------------
int SourceBook::findUnitByName(String Name){
	String str = String("SELECT KIND, CAPTION, RATING FROM ") ;
	str = str + SourceBook::TABLE_NAME ;
	String str_par = String("caption = '" + Name + "'") ;
	DM2->fdqSourceBook->SQL->Text = str ;
	DM2->fdqSourceBook->Filter = str_par ;
	DM2->fdqSourceBook->Filtered = true ;
	DM2->fdqSourceBook->Active = true ;

	SourceBook::id = DM2->fdqSourceBook->FieldByName("KIND")->AsInteger ;
	SourceBook::rating = DM2->fdqSourceBook->FieldByName("RATING")->AsInteger ;
	return SourceBook::id ;
}
//---------------------------------------------------------------------------
String SourceBook::findUnitById(int id){
	String str = String("SELECT KIND, CAPTION, RATING FROM ") ;
	str = str + SourceBook::TABLE_NAME ;
	String str_par = String("KIND = " + IntToStr(id) + "") ;
	DM2->fdqSourceBook->SQL->Text = str ;
	DM2->fdqSourceBook->Filter = str_par ;
	DM2->fdqSourceBook->Filtered = true ;
	DM2->fdqSourceBook->Active = true ;

	SourceBook::name = DM2->fdqSourceBook->FieldByName("CAPTION")->AsString ;
	SourceBook::rating = DM2->fdqSourceBook->FieldByName("RATING")->AsInteger ;
	return SourceBook::name ;
}

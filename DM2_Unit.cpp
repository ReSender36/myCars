//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "DM2_Unit.h"
//#include "SM1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IWImageList"
#pragma resource "*.dfm"
TDM2 *DM2;
//---------------------------------------------------------------------------
bool db_connect()
{
	bool bConnectState ;
	TIniFile *ini ;
	ini = new TIniFile("..\\sm.ini") ;
	String vSrv = ini->ReadString("SM","Server", 1) ;
	String vPort = ini->ReadString("SM","Port", 1) ;
	String vLogin = ini->ReadString("SM","Login","default") ;
	String vPassword = ini->ReadString("SM", "Password",1) ;
	String vDB = ini->ReadString("SM", "DB",1) ;
	String vCodepage = ini->ReadString("SM", "Codepage",1) ;
	ini->Free() ;

	DM2->FDConnection1->Params->UserName = vLogin ;
	DM2->FDConnection1->Params->Password = vPassword ;
	DM2->FDConnection1->Params->Add("Server = vSrv") ;
	DM2->FDConnection1->Params->Add("Port = vPort") ;
	DM2->FDConnection1->Params->Add("CharacterSet = vCodepage") ;
	DM2->FDConnection1->Params->Database = vDB ;

	try{
		if (!DM2->FDConnection1->Connected){
			DM2->FDConnection1->Connected = true ;

		if (DM2->FDConnection1->Connected)
			bConnectState = true ;
		else
			bConnectState = false ;
		}
	}
	catch(...){
		int q_conn = Application->MessageBox(String("БД не найдена по указанному пути. Укажите!").w_str(),String("Проблема").w_str(),MB_YESNO + MB_ICONQUESTION) ;
		switch(q_conn){
			case IDYES:{
//				if(DM2->od1->Execute()){
//					String fn = DM2->od1->FileName ;
//					TIniFile *ini ;
//					ini = new TIniFile("..\\sm.ini") ;
//					ini->WriteString("DB","DB_path",fn) ;
//					ini->Free() ;
//					String conn_str = String("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + fn + ";Persist Security Info=False;") ;
//					DM2->adoMainConn->ConnectionString = conn_str ;
//					if (!DM2->adoMainConn->Connected){
//						DM2->adoMainConn->Connected = true ;
//						if (DM2->adoMainConn->Connected)
//							return 1;
//					}
//				}
				break ;
			}
			case IDNO:
				break ;
		}
	}
	return bConnectState ;
}
//---------------------------------------------------------------------------
__fastcall TDM2::TDM2(TComponent* Owner)
	: TDataModule(Owner)
{

	short state ;
	if (db_connect()){
		state = 1 ;
		int q_conn = Application->MessageBox(String("Соединение установлено").w_str(),String("Ок.").w_str(),MB_YESNO + MB_ICONQUESTION) ;
		switch(q_conn){
			case IDYES:{
//				if(DM2->od1->Execute()){
//					String fn = DM2->od1->FileName ;
//					TIniFile *ini ;
//					ini = new TIniFile("..\\sm.ini") ;
//					ini->WriteString("DB","DB_path",fn) ;
//					ini->Free() ;
//					String conn_str = String("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + fn + ";Persist Security Info=False;") ;
//					DM2->adoMainConn->ConnectionString = conn_str ;
//					if (!DM2->adoMainConn->Connected){
//						DM2->adoMainConn->Connected = true ;
//						if (DM2->adoMainConn->Connected)
//							return 1;
//					}
//				}
				break ;
			}
			case IDNO:
				break ;
		}
//		SM->Label1->Caption = "@" ;
//		SM->Label1->Font->Color = clGreen ;
//		SM->Label1->Font->Size = 6 ;
	}
	else{
		state = 0 ;
//		SM->Label1->Caption = "@" ;
//		SM->Label1->Font->Color = clRed ;
	}
//	DM2->adoMainConn->Connected = false ;
//	DM2->adoMainConn->ConnectionString = String("FILE NAME=C:\Users\mdi\Documents\Access_ODBC.dsn") ;

//	DM2->adoMainConn->Connected = true ;
}
//---------------------------------------------------------------------------


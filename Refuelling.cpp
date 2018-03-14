//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Refueling_Unit.cpp", Refueling_Form);
USEFORM("DM2_Unit.cpp", DM2); /* TDataModule: File Type */
USEFORM("AddSrv_Type_Unit.cpp", AddSrv_Type_Form);
USEFORM("AddAcc_Unit.cpp", AddAcc_Form);
USEFORM("CarWrk_Unit.cpp", Wrks_Form);
USEFORM("Automobile_Unit.cpp", Automobile_Base_Form);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TDM2), &DM2);
		Application->CreateForm(__classid(TRefueling_Form), &Refueling_Form);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------

USEFORM("D:\\Crypto Wallet\\GUI Proj\\MainFormPage.cpp", MainForm);
USEFORM("D:\\Crypto Wallet\\GUI Proj\\CreateWalletPage.cpp", CreateWalletForm);
USEFORM("D:\\Crypto Wallet\\GUI Proj\\LoginPage.cpp", LoginForm);
USEFORM("D:\\Crypto Wallet\\GUI Proj\\DashBoardPage.cpp", DashBoardForm);
//---------------------------------------------------------------------------

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TCreateWalletForm), &CreateWalletForm);
		Application->CreateForm(__classid(TLoginForm), &LoginForm);
		Application->CreateForm(__classid(TDashBoardForm), &DashBoardForm);
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

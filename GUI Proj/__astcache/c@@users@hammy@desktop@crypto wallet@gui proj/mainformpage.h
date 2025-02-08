﻿//---------------------------------------------------------------------------

#ifndef MainFormPageH
#define MainFormPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *CryptoWallet;
	TButton *btnCreateWallet;
	TButton *btnLogin;
	TButton *btnExit;
	void __fastcall btnCreateWalletClick(TObject *Sender);
	void __fastcall btnLoginClick(TObject *Sender);
	void __fastcall btnExitClick(TObject *Sender);
//	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

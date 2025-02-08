//---------------------------------------------------------------------------

#ifndef CreateWalletPageH
#define CreateWalletPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CreateWalletPage.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>

String hashPassword(const String &password);


//---------------------------------------------------------------------------
class TCreateWalletForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *edtEmail;
	TEdit *edtPassword;
	TButton *btnCreate;
	TButton *btnCancel;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label1;
	TImage *Image2;
	void __fastcall btnCreateClick(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
//	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCreateWalletForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCreateWalletForm *CreateWalletForm;
//---------------------------------------------------------------------------
#endif

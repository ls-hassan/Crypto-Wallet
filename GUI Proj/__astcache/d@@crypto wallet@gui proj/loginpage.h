//---------------------------------------------------------------------------

#ifndef LoginPageH
#define LoginPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------


extern AnsiString currentLoggedInEmail;  // Declaration of the variable


class TLoginForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblEmail;
	TEdit *edtEmail;
	TEdit *edtPassword;
	TButton *btnLogin;
	TButton *btnCancel;
	TLabel *Label2;
	TLabel *Label1;
	TLabel *Label3;
	TImage *Image2;
	void __fastcall btnLoginClick(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLoginForm *LoginForm;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#ifndef MainFormPageH
#define MainFormPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *CryptoWallet;
	TButton *btnCreateWallet;
	TButton *btnLogin;
	TButton *btnExit;
	TLabel *Label1;
	TLabel *Label2;
	TImage *Image1;
	TImage *Image2;
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

//---------------------------------------------------------------------------

#ifndef DashBoardPageH
#define DashBoardPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TDashBoardForm : public TForm
{
__published:	// IDE-managed Components
	TButton *btnDeposit;
	TButton *btnWithDraw;
	TButton *btnCheckBalance;
	TButton *btnLogout;
	TLabel *lblEmail;
	TLabel *Amount;
	TEdit *edtAmount;
	TComboBox *cmbCoinType;
	TLabel *Label2;
	TLabel *Label3;
	TImage *Image2;
	void __fastcall cmbCoinTypeChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnWithDrawClick(TObject *Sender);
	void __fastcall btnDepositClick(TObject *Sender);
	void __fastcall btnCheckBalanceClick(TObject *Sender);
	void __fastcall btnLogoutClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDashBoardForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDashBoardForm *DashBoardForm;
//---------------------------------------------------------------------------
#endif

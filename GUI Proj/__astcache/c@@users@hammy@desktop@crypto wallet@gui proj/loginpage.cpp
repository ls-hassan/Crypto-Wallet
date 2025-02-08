﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<fstream>
//#include "CommonFunctions.h"
#include "LoginPage.h"
#include "CreateWalletPage.h" // Include the header where hashPassword is declared
#include "DashBoardPage.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginForm *LoginForm;

AnsiString currentLoggedInEmail;

//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::btnLoginClick(TObject *Sender)
{
    String email = edtEmail->Text.Trim();
    String password = edtPassword->Text;

    if (email.IsEmpty() || password.IsEmpty())
    {
        ShowMessage("Email and Password cannot be empty!");
        return;
    }

    // Check if email exists in the accounts file
    std::ifstream accountsFile("D:\\Crypto Wallet\\CLI Proj\\accounts.txt");
    std::string storedEmail, storedPassword, storedWalletFile;
    bool found = false;

    while (std::getline(accountsFile, storedEmail, ' ') &&
           std::getline(accountsFile, storedPassword, ' ') &&
           std::getline(accountsFile, storedWalletFile))
    {
        // Check if the entered email matches the stored email
        if (storedEmail == AnsiString(email).c_str())
        {
            found = true;
            // If email matches, check if the hashed password matches
			String hashedPassword = hashPassword(password);
            if (storedPassword == AnsiString(hashedPassword).c_str())
			{
                currentLoggedInEmail = edtEmail->Text;
				ShowMessage("Login successful!");

				// Proceed to the next form or action
				// For example, transitioning to the main wallet form:
				// MainForm->Show();
                Close(); // Close the login form
				 DashBoardForm = new TDashBoardForm(Application);  // Create the dashboard form
				 DashBoardForm->Show();

			}
            else
            {
				ShowMessage("Invalid password.");
                return;
            }
        }
	}

    if (!found)
    {
        ShowMessage("Email not registered.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::btnCancelClick(TObject *Sender)
{
	// Optionally clear the fields before closing (if required)
    edtEmail->Clear();
    edtPassword->Clear();

    // Close the login form
	Close();
}
//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include <direct.h>  // For _mkdir function (to create directory)
#include <sys/stat.h> // For stat() to check directory existence
#include <regex>      // For email validation
#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "CreateWalletPage.h"

__fastcall TCreateWalletForm::TCreateWalletForm(TComponent* Owner)
    : TForm(Owner) {}

TCreateWalletForm *CreateWalletForm;

// Convert UnicodeString (or String) to std::string using AnsiString
std::string StringToStdString(const String &str)
{
    AnsiString ansiStr = str;
    return std::string(ansiStr.c_str());
}

// Function to hash the password using a simple hashing algorithm
String hashPassword(const String &password)
{
    unsigned long hash = 5381;
    for (int i = 1; i <= password.Length(); ++i)
	{
		hash = ((hash << 5) + hash) + password[i];
	}
	return IntToStr(static_cast<int>(hash));
}

// Check if password is in the breached list
bool isPasswordBreached(const String &password)
{
	std::ifstream breachFile("D:\\Crypto Wallet\\CLI Proj\\pwd.txt");
    if (!breachFile.is_open())
    {
        ShowMessage("Password breach file could not be opened. Please check the file path.");
        return false; // Assume not breached if the file cannot be read
    }

    // Convert the password to std::string for comparison
    std::string inputPassword = StringToStdString(password);

    std::string breachedPassword;
    while (std::getline(breachFile, breachedPassword))
    {
        // Trim any trailing spaces or newline characters from the breached password
        breachedPassword.erase(breachedPassword.find_last_not_of(" \n\r\t") + 1);

        // Compare the passwords directly (no hashing)
        if (breachedPassword == inputPassword)
        {
            breachFile.close();
            return true; // Password is in the breached list
        }
    }

    breachFile.close();
    return false; // Password is not found in the breached list
}

// Function to check if a directory exists
bool directoryExists(const char* directory)
{
    struct stat info;
    return (stat(directory, &info) == 0 && (info.st_mode & S_IFDIR));
}

// Check if the email is already registered
bool isEmailRegistered(const String &email)
{
    std::ifstream accountsFile("D:\\Crypto Wallet\\CLI Proj\\accounts.txt");
    if (!accountsFile.is_open())
    {
        ShowMessage("Accounts file could not be opened. Please check the file path.");
        return false; // Assume not registered if file cannot be opened
    }

    std::string storedEmail, storedPassword, storedWalletFile;
    while (std::getline(accountsFile, storedEmail, ' ') &&
           std::getline(accountsFile, storedPassword, ' ') &&
		   std::getline(accountsFile, storedWalletFile))
    {
        if (storedEmail == AnsiString(email).c_str())
        {
            return true; // Email found
		}
    }

    return false; // Email not found
}

// Create the wallet file for the user
void createWalletFile(const String &email)
{
    String walletFile = email + "_wallet.txt";
    std::ofstream wallet(AnsiString("D:\\Crypto Wallet\\CLI Proj\\" + walletFile).c_str());

    if (wallet.is_open())
    {
        wallet << "BTC 0.00\n"
               << "ETH 0.00\n"
               << "SOL 0.00\n"
               << "TRX 0.00\n"
               << "USDT 0.00\n";
        wallet.close();
    }
    else
    {
        ShowMessage("Failed to create wallet file. Please check file permissions.");
    }
}

// Validate email format using a regular expression
bool isValidEmail(const String &email)
{
    std::string emailStr = StringToStdString(email);
    const std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(emailStr, emailPattern);
}

// On Create Wallet Button Click
void __fastcall TCreateWalletForm::btnCreateClick(TObject *Sender)
{
    String email = edtEmail->Text.Trim();
    String password = edtPassword->Text;

    // Input validation
    if (email.IsEmpty() || password.IsEmpty())
    {
        ShowMessage("Email and Password cannot be empty!");
        return;
    }

    // Validate email format
    if (!isValidEmail(email))
    {
        ShowMessage("Please enter a valid email address (e.g., example@domain.com).");
        return;
    }

    // Check if the password is breached
    if (isPasswordBreached(password))
    {
        ShowMessage("Password found in a breached! Please use a different password.");
        return; // Exit without proceeding further
    }

    // Check if the email is already registered
    if (isEmailRegistered(email))
    {
        ShowMessage("Email is already registered. Please use a different email.");
        return; // Exit without proceeding further
    }

    // Hash the password
    String hashedPassword = hashPassword(password);

    // Ensure the directory exists or create it
    const char* directory = "D:\\Crypto Wallet\\CLI Proj";
    if (!directoryExists(directory))
    {
        if (_mkdir(directory) != 0)
        {
            ShowMessage("Failed to create directory. Check if you have write permissions.");
            return;
        }
    }

    // Save user details to accounts.txt
    std::ofstream accountsFile("D:\\Crypto Wallet\\CLI Proj\\accounts.txt", std::ios::app);
    if (accountsFile.is_open())
    {
        String walletFile = email + "_wallet.txt";
        accountsFile << AnsiString(email).c_str() << " "
                     << AnsiString(hashedPassword).c_str() << " "
                     << AnsiString(walletFile).c_str() << std::endl;
        accountsFile.close();
    }
    else
    {
        ShowMessage("Failed to write to accounts file.");
        return;
    }

    // Create the wallet file
    createWalletFile(email);

    // Display success message
    ShowMessage("Account created successfully! Wallet file created and details saved.");
    Close();
}

// On Cancel Button Click
void __fastcall TCreateWalletForm::btnCancelClick(TObject *Sender)
{
	Close();
}

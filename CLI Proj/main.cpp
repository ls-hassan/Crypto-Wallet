#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Hash function for password (simple for demonstration purposes)
string hashPassword(const string& password)
{
    unsigned long hash = 5381;
    for (char c : password)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return to_string(hash);
}

// Function to check if a password is in the breached list
bool isPasswordBreached(const string& password)
{
    ifstream breachFile("pwd.txt");
    string breachedPassword;
    while (getline(breachFile, breachedPassword))
    {
        if (breachedPassword == password)
        {
            return true;
        }
    }
    return false;
}

// Function to convert a string to uppercase
string toUpperCase(const string& str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Function to create a wallet
void createWallet()
{
    string email, password, hashedPassword, walletFile;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> password;

    // Check if the password is breached
    if (isPasswordBreached(password))
    {
        cout << "Password found in breach. Please use another password.\n";
        return;
    }

    hashedPassword = hashPassword(password);
    walletFile = email + "_wallet.txt";

    // Store user details in accounts.txt
    ofstream accountsFile("accounts.txt", ios::app);
    accountsFile << email << " " << hashedPassword << " " << walletFile << endl;
    accountsFile.close();

    // Create an empty wallet file
    ofstream wallet(walletFile);
    wallet.close();

    cout << "Wallet created successfully!\n";
}

// Function to log in
bool login(string& walletFile)
{
    string email, password, hashedPassword;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> password;

    hashedPassword = hashPassword(password);

    ifstream accountsFile("accounts.txt");
    string storedEmail, storedPassword, storedWalletFile;
    while (accountsFile >> storedEmail >> storedPassword >> storedWalletFile)
    {
        if (email == storedEmail && hashedPassword == storedPassword)
        {
            walletFile = storedWalletFile;
            cout << "Logged in successfully!\n";
            return true;
        }
    }
    cout << "Invalid credentials. Please try again.\n";
    return false;
}

// Function to deposit cryptocurrency
void deposit(string& walletFile)
{
    string coinName;
    double amount;

    cout << "Enter the cryptocurrency you want to deposit (BTC, ETH, SOL, TRX, USDT): ";
    cin >> coinName;
    coinName = toUpperCase(coinName); // Convert to uppercase
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    unordered_map<string, double> wallet;
    ifstream walletFileIn(walletFile);
    string coin;
    double balance;
    while (walletFileIn >> coin >> balance)
    {
        wallet[coin] = balance;
    }
    walletFileIn.close();

    wallet[coinName] += amount;

    ofstream walletFileOut(walletFile);
    for (const auto& entry : wallet)
    {
        walletFileOut << entry.first << " " << fixed << setprecision(2) << entry.second << endl;
    }
    walletFileOut.close();

    cout << "Deposit successful!\n";
}

// Function to withdraw cryptocurrency
void withdraw(string& walletFile)
{
    string coinName;
    double amount;

    cout << "Enter the cryptocurrency you want to withdraw (BTC, ETH, SOL, TRX, USDT): ";
    cin >> coinName;
    coinName = toUpperCase(coinName); // Convert to uppercase
    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    unordered_map<string, double> wallet;
    ifstream walletFileIn(walletFile);
    string coin;
    double balance;
    while (walletFileIn >> coin >> balance)
    {
        wallet[coin] = balance;
    }
    walletFileIn.close();

    if (wallet[coinName] < amount)
    {
        cout << "Insufficient balance!\n";
        return;
    }

    wallet[coinName] -= amount;

    ofstream walletFileOut(walletFile);
    for (const auto& entry : wallet)
    {
        walletFileOut << entry.first << " " << fixed << setprecision(2) << entry.second << endl;
    }
    walletFileOut.close();

    cout << "Withdrawal successful!\n";
}

// Function to check balance
void checkBalance(string& walletFile)
{
    ifstream walletFileIn(walletFile);
    string coin;
    double balance;

    cout << "Your wallet balance:\n";
    while (walletFileIn >> coin >> balance)
    {
        cout << coin << ": " << fixed << setprecision(2) << balance << endl;
    }
    walletFileIn.close();
}

// Main function
int main()
{
    int choice;
    string walletFile;

    while (true)
    {
        cout << "Cryptocurrency Wallet Application\n";
        cout << "1. Create Wallet\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createWallet();
            break;
        case 2:
            if (login(walletFile))
            {
                int walletChoice;
                do
                {
                    cout << "1. Deposit Cryptocurrency\n";
                    cout << "2. Withdraw Cryptocurrency\n";
                    cout << "3. Check Balance\n";
                    cout << "4. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> walletChoice;

                    switch (walletChoice)
                    {
                    case 1:
                        deposit(walletFile);
                        break;
                    case 2:
                        withdraw(walletFile);
                        break;
                    case 3:
                        checkBalance(walletFile);
                        break;
                    case 4:
                        cout << "Logged out successfully!\n";
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                    }
                } while (walletChoice != 4);
            }
            break;
        case 3:
            cout << "Exiting the application. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
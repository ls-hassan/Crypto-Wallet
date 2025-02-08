# Crypto-Wallet
It's my fist semester project of programming fundamentals in C++

This project is a **GUI-based Cryptocurrency Wallet** developed using **RAD Studio**. The wallet allows users to securely store and manage cryptocurrency information with a simple and intuitive interface.

## Features

### Login Page (`loginpage.cpp`)
- **Password Hashing**: Ensures secure storage and validation of user credentials.
- **Dynamic Email Storage**: Captures the logged-in user's email during login and makes it accessible throughout the application by including `LoginPage.h`.
- **Credential Validation**: Checks user credentials against an `accounts` file.
- **Successful Login Transition**: Redirects the user to the **Dashboard GUI** upon successful login.

### Dashboard GUI (`dashboardpage.cpp`)
- A visually interactive interface with multiple action buttons for wallet operations.

### Wallet File Storage
- Wallet files are saved in the directory:
  ```
  D:\Crypto Wallet\CLI Proj
  ```
- The file name format is:
  ```
  <logged-in-email>_wallet.txt
  ```

## Technical Details
- **Language**: C++
- **Framework**: RAD Studio
- **Password Hashing**: Uses a secure algorithm to hash passwords before storage.
- **File Operations**: Reads from and writes to files for credential validation and wallet management.
- **Dynamic Email Handling**: The logged-in email is dynamically passed between forms, ensuring personalized operations.

## How to Use
1. **Login**:
   - Enter your email and password.
   - Credentials are validated against the stored accounts file.
   - On successful login, you will be redirected to the Dashboard.

2. **Dashboard**:
   - Interact with various wallet operations through the provided buttons.

3. **Wallet Management**:
   - Your wallet file will be stored in the specified directory with a unique name based on your email.

## Future Improvements
- Add support for multiple cryptocurrencies.
- Integrate encryption for wallet file storage.
- Develop a backup and restore feature for wallet files.
- Enhance the GUI for better user experience.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/crypto-wallet-project.git
   ```
2. Open the project in RAD Studio.
3. Compile and run the application.

## Contributions
Contributions are welcome! Feel free to fork the repository and submit pull requests.


# **Crypto-Wallet** 🚀  
*A Secure GUI-Based Cryptocurrency Wallet built with C++ and RAD Studio*  

## **Overview**  
Crypto-Wallet is my first-semester project for **Programming Fundamentals in C++**. This **Graphical User Interface (GUI)-based Cryptocurrency Wallet** is developed using **RAD Studio**, designed to securely store and manage cryptocurrency-related data.  

🔒 **Security is a top priority** – the wallet uses **password hashing and breach detection** to ensure user credentials are safe.  

---

## **Features**  

### 🔑 **Create Wallet Page (`createwallet.cpp`)**  
- **Secure Password Storage**: Uses the **djb2 hashing algorithm** to securely hash passwords before saving them.  
- **Breach Detection**:  
  - When a user creates a password, it is checked against a **breached passwords list (`pwd.txt`)**.  
  - If found in the list, the user is **prompted to create a stronger password** (with uppercase, lowercase, special characters, and at least 8 characters long).  
- **Account Creation Security**: Ensures **only strong and unique passwords** are used.  

### 🔑 **Login Page (`loginpage.cpp`)**  
- **Hashed Password Validation**: Compares hashed user credentials with stored values.  
- **Dynamic Email Storage**: Captures the logged-in user's email for session-based operations.  
- **Automatic Dashboard Redirection**: Upon successful login, the user is directed to the **Dashboard GUI**.  

### 📊 **Dashboard GUI (`dashboardpage.cpp`)**  
- **User-Friendly Interface**: Provides an intuitive design with action buttons for managing the wallet.  

### 📁 **Wallet File Storage**  
- **Secure File Management**: Each user’s wallet data is stored securely in a dedicated file.  
- **Storage Location**:  
  ```plaintext
  D:\Crypto Wallet\CLI Proj
  ```
- **File Naming Convention**:  
  ```plaintext
  <logged-in-email>_wallet.txt
  ```
  - This ensures **user-specific wallet storage** for better security and organization.  

---

## **Technical Details**  

| Feature            | Description |
|--------------------|-------------|
| **Language**       | C++ |
| **Framework**      | RAD Studio |
| **Password Hashing** | Uses **djb2 hashing algorithm** for secure password storage |
| **Breach Detection** | Checks new passwords against a breached list (`pwd.txt`) |
| **File Operations** | Reads from and writes to files for login validation and wallet storage |
| **Dynamic Email Handling** | Ensures seamless email access across different program components |

---

## **How to Use**  

1️⃣ **Create Wallet**  
   - Enter **email** and **password**.  
   - The password is **checked against breached passwords**.  
   - If safe, it is **hashed using djb2** and stored securely.  

2️⃣ **Login**  
   - Enter your **email** and **password**.  
   - The password is **hashed and compared** with the stored hash.  
   - Upon successful authentication, you will be redirected to the **Dashboard**.  

3️⃣ **Dashboard**  
   - Access different **wallet management features** using the available buttons.  

4️⃣ **Wallet Management**  
   - Your wallet file will be created and stored **securely** in the designated directory.  

---

## **Security Features 🔐**  

✔ **djb2 Hashing Algorithm** – A lightweight, **fast hashing function** to store passwords securely.  
✔ **Breach Detection System** – Prevents the use of weak passwords by checking them against `pwd.txt`.  
✔ **Password Strength Enforcement** – Requires **at least 8 characters**, including **uppercase, lowercase, and special characters**.  

---

## **Future Enhancements 🚀**  

🔹 **Multi-Currency Support** – Allowing users to manage multiple cryptocurrencies within the same wallet.  
🔹 **Encryption** – Enhancing security by **encrypting stored wallet files** to prevent unauthorized access.  
🔹 **Backup & Restore** – Implementing **automatic backup and recovery** for wallet data.  
🔹 **Enhanced GUI** – Improving user experience with a modernized and responsive design.  

---

## **Installation & Setup**  

1️⃣ **Clone the Repository**  
   ```bash
   git clone https://github.com/ls-hassan/Crypto-Wallet.git
   ```  
2️⃣ **Open the Project** in **RAD Studio**.  
3️⃣ **Compile & Run** the application.  

---

## **Contributing 🤝**  
Contributions are welcome! If you'd like to improve this project:  
1. **Fork the repository**  
2. **Create a new branch** (`feature-new-improvement`)  
3. **Commit your changes**  
4. **Open a Pull Request (PR)**  

💡 Feel free to **suggest enhancements, report issues, or optimize code**!  

---

## **License**  
📜 This project is for **educational purposes** and does not include real cryptocurrency transactions.  

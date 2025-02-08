//---------------------------------------------------------------------------

#include "CommonFunctions.h"  // Include the header file

// Define the constructor of TForm2




// Hash function for password
String hashPassword(const String &password)
{
    unsigned long hash = 5381;
    for (int i = 1; i <= password.Length(); ++i)
    {
		hash = ((hash << 5) + hash) + password[i];
    }
    return IntToStr(static_cast<int>(hash));
}


//---------------------------------------------------------------------------

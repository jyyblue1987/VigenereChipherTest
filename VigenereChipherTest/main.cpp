/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//Initialze libraries
#include <iostream>
#include <stdio.h> //fgets() , printf(0, stdin
#include <ctype.h> // isupper() , islower() , tolower(), toupper(), isalpha()
#include <algorithm>
#include <string> //strlen()


using namespace std;

//Declare vigenere cipher
string vigenereCipher(const char *key, const char *plain);
void vigenereDecipher(char* cipherText,char* k);

int main(){
	char choice = '0';
	string message = "";
	string secret = "";

    while(true)
	{
		cout << "Please make your choice:" << endl;
		cout << "1 - Encrypt the message" << endl;
		cout << "2 - Decrypt the message" << endl;
		cout << "Exit on any other input" << endl;

		cout << "Your choice: ";
		cin >> choice;
		if( choice == '1' )
		{
			cout << "Enter the message (3 + characters): ";
			getline(cin, message);
			getline(cin, message);
			cout << "Enter the secret (empty or English letters): ";
			getline(cin, secret);

			message.erase(std::remove(message.begin(), message.end(), '\n'), message.end());
			secret.erase(std::remove(secret.begin(), secret.end(), '\n'), secret.end());

			cout << endl;
			cout << "Original message: " << message << endl;
			cout << "The secret:       " << secret << endl;

			string cipher = vigenereCipher(secret.c_str(), message.c_str());
			cout << "Encrypted text:   " << cipher << endl;

		}
		if( choice == '2' )
		{

		}

	}
    
    return 0;
}

//C[i] = (p[i] + k[i mod klength] ) mod N, C = cipher, k = secret key (word), p = sentence or plainText or word, N = number of letters in the alphabet
//Di = (C[i] - Ki[i mod klength] + 26) mod 26

string vigenereCipher(const char *key, const char *plain)
{
	int key_len = strlen(key);
	int plain_len = strlen(plain);

	string result = "";

	int i = 0, j = 0;
	for(i = 0; i < plain_len; i++, j++)
	{
		if( j >= key_len )
			j = 0;
		int c = (plain[i] + key[j] - 'A');
		if( c > 'Z' )
			c = c - 'Z' - 1 + 'A';

		result += (char)c;		
	}

	return result;
}

void vigenereDecipher(char* cipherText, char* k){
    
    int i;
    char decipher;
    int decipherValue;
    int len = strlen(k);
    
    //Loop through the length of the plain text string
    for(i=0; i<strlen(cipherText); i++){
        
        //if the character is lowercase, where range is [97 -122]
        if(islower(cipherText[i]))
        {
            decipherValue = ( ((int)cipherText[i]+97 - (int)tolower(k[i % len])-97)+26 ) % 26 +97;
            decipher = (char)decipherValue;
        }
        else // Else it's upper case, where letter range is [65 - 90]
        {
            decipherValue = ( ((int)cipherText[i]+65 - (int)toupper(k[i % len])-65)+26 ) % 26 +65;
            decipher = (char)decipherValue;
        }
        
        //Print the ciphered character if it is alphanumeric (a letter)
        if(isalpha(cipherText[i]))
        {
            printf("%c", decipher);
        }
        else //if the character is not a letter then print the character (e.g. space)
        {
            printf("%c", cipherText[i]);
        }
    }
    
    
}


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
string vigenereDecipher(const char *key, const char *cipher);

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

			string decrpyted = vigenereDecipher(secret.c_str(), cipher.c_str());
			cout << "Decrypted text:   " << decrpyted << endl;

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
	char k = '0';

	for(i = 0; i < plain_len; i++, j++)
	{
		if( j >= key_len )
			j = 0;

		int c = plain[i];
		k = key[j];
		if( 'a' <= c && c <= 'z' )
		{
			
			if( 'A' <= k && k <= 'Z')
				k = k - 'A' + 'a';

			c = (c + k - 'a');
			if( c > 'z' )
				c = c - 'z' - 1 + 'a';
		}

		if( 'A' <= c && c <= 'Z' )
		{
			if( 'a' <= k && k <= 'z')
				k = k - 'a' + 'A';

			c = (c + k - 'A');
			if( c > 'Z' )
				c = c - 'Z' - 1 + 'A';
		}

		result += (char)c;		
	}

	return result;
}

string vigenereDecipher(const char *key, const char *cipher){
    
	int key_len = strlen(key);
	int cipher_len = strlen(cipher);

	string result = "";

	int i = 0, j = 0;
	char k = '0';
	for(i = 0; i < cipher_len; i++, j++)
	{
		if( j >= key_len )
			j = 0;

		int c = cipher[i];
		k = key[j];
		if( 'a' <= c && c <= 'z' )
		{
			if( 'A' <= k && k <= 'Z')
				k = k - 'A' + 'a';

			c = (c - k + 'a');
			if( c < 'a' )
				c = 'z' - 'a' + c  + 1;
		}

		if( 'A' <= c && c <= 'Z' )
		{
			if( 'a' <= k && k <= 'z')
				k = k - 'a' + 'A';

			c = (c - k + 'A');
			if( c < 'A' )
				c = 'Z' - 'A' + c  + 1;
		}		

		result += (char)c;		
	}

	return result;
    
    
}


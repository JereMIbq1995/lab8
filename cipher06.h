/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H
#include "cipher.h"
#define NUMCHARS 91
#define STARTCHAR ' '
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Sophia Pearson"; }
   virtual std::string getCipherName()  { return "Vigenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Sophia Pearson"; }
   virtual std::string getDecryptAuth() { return "Sophia Pearson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citations from which we learned about the cipher
    * Rather than implementing the 0-25 alphabetic-character-only
    * substitution, I included 0-90 for ' ' through 'z' in ASCII.
    * This is a slight difference between these citations and the
    * implementation.
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citations = "Britannica, Gustavus J. Simmons, Vigenere Cipher, Jul 22, 2009 - https://www.britannica.com/topic/Vigenere-cipher\n";
      citations += "GeeksforGeeks, Vigenere Cipher, Apr 21, 2020 - https://www.geeksforgeeks.org/vigenere-cipher/\n";

      return citations;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "Encryption psuedocode:\n";
      str +=  "loop through every character in the message;\n";
      str +=  "\tSET p = message[i] - ' '; //space is the first valid ASCII character\n";
      str +=  "\tSET k = keyStr[i] - ' '; //keyStr is the same length as the message\n";
      str +=  "\tSET c = ((p + k) % 91) + 'A'; //there can be 91 characters accepted\n";
      str +=  "\tSET cipher += c;\n";
      str +=  "RETURN cipher;\n\n";

      // The decrypt pseudocode
      str +=  "Decryption psuedocode:\n";
      str +=  "loop through every character in the cipher;\n";
      str +=  "\tSET c = cipher[i] - ' ';\n";
      str +=  "\tSET k = keyStr[i] - ' '; //keyStr is the same length as the cipher\n";
      str +=  "\tSET p = ((e - k + 91) % 91) + ' ';\n";
      str +=  "\tSET message += p;\n";
      str +=  "RETURN message;\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Convert plainText to cipher by shifting each character in
    * plainText by the corresponding character in password on
    * the ASCII chart (91 characters can be used: ' ' through 'z')
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";

      // TODO - Add your code here
      // make the password the same length as the plainText...
      // if the password length is greater than the plainText
      // length, the keyStr will remain longer
      std::string keyStr = password;
      const int x = keyStr.size();
  
      for (int i = 0; keyStr.size() < plainText.size(); i++)
      {
         if (x == i)
               i = 0;
         keyStr.push_back(keyStr[i]);
      }
      assert(keyStr.size() >= plainText.size()); //double check

      // convert plainText to the cipher
      for (int i = 0; i < plainText.size(); i++) {
         // convert to 0 - 90 for valid characters
         char p = plainText[i] - STARTCHAR;
         char k = keyStr[i] - STARTCHAR;

         // convert p to c using k
         char c = ((p + k) % NUMCHARS) + STARTCHAR;

         cipherText.push_back(c);
      }

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * Convert cipher to plainText by shifting each character in
    * the cipher by the corresponding character in password on
    * the ASCII chart (91 characters are valid: ' ' through 'z')
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = "";

      // TODO - Add your code here
      // make the password the same length as the cipherText...
      // if the password length is greater than the cipherText
      // length, the keyStr will remain longer
      std::string keyStr = password;
      const int x = keyStr.size();
  
      for (int i = 0; keyStr.size() < cipherText.size(); i++)
      {
         if (x == i)
               i = 0;
         keyStr.push_back(keyStr[i]);
      }

      // convert plainText to the cipher
      for (int i = 0; i < cipherText.length(); i++) {
         // convert to 0 - 90
         char c = cipherText[i] - STARTCHAR;
         char k = keyStr[i] - STARTCHAR;

         // convert p to c using k
         char p = ((c - k + NUMCHARS) % NUMCHARS) + STARTCHAR;

         plainText.push_back(p);
      }
      return plainText;
   }
};

#endif // CIPHER06_H
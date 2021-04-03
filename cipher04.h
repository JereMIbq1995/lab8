/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H
#include "cipher.h"
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Timothy Stephenson"; }
   virtual std::string getCipherName()  { return "XOR"; }
   virtual std::string getEncryptAuth() { return "Timothy Stephenson"; }
   virtual std::string getDecryptAuth() { return "Timothy Stephenson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("citation");
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
      str =  "encrypt plaintext(plainText, password)";
      str += "\n FOR i in size of plainText divided by size of password plus 1";
      str += "\n     FOR x in length of password";
      str += "\n        n = i * password length + x";
      str += "\n        cipherText at value of n = plainText at value n xor with password at value x";
      str += "\n return cipherText";

      // The decrypt pseudocode
      str +=  "decrypt ciphertext(cipherText, password)";
      str += "\n FOR i in size of cipherText divided by size of password + 1";
      str += "\n     FOR x in length of password";
      str += "\n        n = i * password length + x";
      str += "\n        plainText at value of n = cipherText at value n xor with password at value x";
      str += "\n return plainText";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      for (int i = 0; i < (plainText.length()/password.length() + 1); i++)
      {      
         for(int x = 0; x < password.length(); x++)
         {
            int n = i * password.length() + x;
            if(n > plainText.length())
               break;
            cipherText[n] = plainText[n] ^ password[x];
         }
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      for (int i = 0; i < (cipherText.length() / password.length() + 1); i++)
      {      
         for(int x = 0; x < password.length(); x++)
         {
            int n = i * password.length() + x;
            if(n > plainText.length())
               break;
            plainText[n] = cipherText[n] ^ password[x];
         }
      }
      return plainText;
   }
};

#endif // CIPHER04_H
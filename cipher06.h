/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H
#include "cipher.h"
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
    * Returns the citation from which we learned about the cipher
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
      str =  "insert the encryption pseudocode\n";

      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";

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
      // TODO - Add your code here
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
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER06_H
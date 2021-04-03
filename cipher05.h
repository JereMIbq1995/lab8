/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H
#include "cipher.h"
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Gabriel Sanahuano"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Gabriel Sanahuano"; }
   virtual std::string getDecryptAuth() { return "Gabriel Sanahuanog"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string myCitation;
      myCitation += "practicalcryptography.com, ";
      myCitation += "\"Affine Cipher\", \n  retrieved: ";
      myCitation += "http://practicalcryptography.com/ciphers/classical-era/affine/";
      return myCitation;
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

#endif // CIPHER05_H

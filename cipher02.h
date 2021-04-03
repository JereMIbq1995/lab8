/********************************************************************
* Header:
*   A simple One-Time Pad Cipher. This symmetric cipher is famous for its
*    reported use by KGB and American spies during the Cold War.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include "cipher.h"
#include <string>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Austin Lundberg"; }
   virtual std::string getCipherName()  { return "One-Time Pad"; }
   virtual std::string getEncryptAuth() { return "Austin Lundberg"; }
   virtual std::string getDecryptAuth() { return "Austin Lundberg"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
        std::string citationOne = "Contributor, TechTarget. \"One-Time Pad.\"";
        citationOne += "\n   SearchSecurity, 5 Apr. 2005,";
        citationOne += "\n   Retreived: searchsecurity.techtarget.com/definition/one-time-pad.\n";

        std::string citationTwo = "\nRijmenants, Dirk. \"One-Time-Pad.\"";
        citationTwo += "\n   Telnet, 2004,";
        citationTwo += "\n   Retreived: users.telenet.be/d.rijmenants/en/onetimepad.htm.";

        return std::string(citationOne + citationTwo);
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
      str = "encrypt(plainText, password)";
	   str += "\n  FOR i in size of plainText";
		str += "\n      value = plainText at i - value of a";
		str += "\n      passwordValue = password at i - value of a";
		str += "\n      newValue = value + passwordValue";
		str += "\n      if newValue > 26";
		str += "\n         newValue = newValue - 26";
		str += "\n      letter = newValue + value of a";
		str += "\n      temp = letter to string";
		str += "\n      append temp to ciphertext";
	   str += "\n  return ciphertext\n";

      // The decrypt pseudocode
      str += "\ndecrypt(cipherText, password)";
	   str += "\n  FOR i in size of cipherText";
		str += "\n      value = cipherText at i + value of a";
		str += "\n      passwordValue = password at i + value of a";
		str += "\n      newValue = value + passwordValue";
		str += "\n      if newValue < 0";
		str += "\n         newValue = newValue + 26";
		str += "\n      letter = newValue + value of a";
		str += "\n      temp = letter to string";
		str += "\n      append temp to plaintext";
	   str += "\n  return plaintext\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      std::string ciphertext = "";
      int value = 0;
      int passwordValue = 0;
      int newValue = 0;
      int j = 0;

      for(int i = 0; i < plainText.size(); i++){

         if(plainText.at(i) == ' '){
            std::string temp = " ";
            ciphertext.append(temp);
            continue;
         }
         else{
            value = (plainText.at(i)- 'a');
         }
         if (i < password.size()){
            passwordValue = (password.at(i) - 'a');
         }
         else{
            // used if the password is shorter than the actual message.
            if (j < password.size()){
               passwordValue = (password.at(j) - 'a');
               j++;
            }
            else{
               j = 0;
               passwordValue = (password.at(j) - 'a');
               j++;
            }
         }
         newValue = value + passwordValue;

         if(newValue >= 26){

            newValue = newValue - 26;
         }

         char letter = (newValue + 'a');
         std::string temp = std::string(1,letter);
         ciphertext.append(temp);
      }

      return ciphertext;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      std::string plaintext = "";
      int value = 0;
      int passwordValue = 0;
      int newValue = 0;
      int j = 0;

      for(int i = 0; i < cipherText.size(); i++){

         if(cipherText.at(i) == ' '){
            std::string temp = " ";
            plaintext.append(temp);
            continue;
         }
         else{
            value = (cipherText.at(i) + 'a');
         }

         if (i < password.size()){
            passwordValue = (password.at(i) + 'a');
         }
         else{
            // used if the password is shorter than the actual message.
            if (j < password.size()){
               passwordValue = (password.at(j) + 'a');
               j++;
            }
            else{
               j = 0;
               passwordValue = (password.at(j) + 'a');
               j++;
            }
         }
         newValue = value - passwordValue;

         if(newValue < 0){

            newValue = newValue + 26;
         }

         char letter = (newValue + 'a');
         std::string temp = std::string(1,letter);
         plaintext.append(temp);
      }

      return plaintext;
   }
};

#endif // CIPHER02_H
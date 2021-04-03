/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H
#include "cipher.h"
#include <vector>
const int S_ARRAY_SIZE = 256; //
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jeremy Duong"; }
   virtual std::string getCipherName()  { return "RC4 (Rivest Cipher 4)"; }
   virtual std::string getEncryptAuth() { return "Jeremy Duong"; }
   virtual std::string getDecryptAuth() { return "Jeremy Duong"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string str = "GeeksForGeeks.org (2019), \"RC4 Encryption Algorithm\"\n";
      str += "\tretrieved: https://www.geeksforgeeks.org/rc4-encryption-algorithm/";
      return str;
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
      str =  "ENCRYPTION pseudocode:\n";
      str += "S = {0, 1, 2, 3, ...., 255}\n";
      str += "K = array of ASCII representations of all characters of the password in order\n";
      str += "KeyStream = integer array with the same number of elements as plainText\n\n";

      str += "j = 0\n";
      str += "for i = 0 to (S_size - 1):\n";
      str += "   j = (j + S[i] + K[i % K_size]) % S_size\n";
      str += "   swap S[i] and S[j]\n\n";

      str += "sIndex1 = 0\n";
      str += "sIndex2 = 0\n";
      str += "for i = 1 to cipherText size:\n";
      str += "   sIndex1 = i % S_size\n";
      str += "   sIndex2 = (sIndex2 + S[sIndex1]) % S_size\n";
      str += "   swap S[sIndex1] and S[sIndex2]\n";
      str += "   indexT = (S[sIndex1] + S[sIndex2]) % S_size\n";
      str += "   KeyStream.push_back( S[indexT] )\n\n";

      str += "cipherText = KeyStream XOR plainText\n";
      str += "RETURN cipherText\n\n\n";

      // The decrypt pseudocode
      str += "DECRYPTION pseudocode:\n";
      str += "S = {0, 1, 2, 3, ...., 255}\n";
      str += "K = array of ASCII representations of all characters of the password in order\n";
      str += "KeyStream = integer array with the same number of elements as plainText\n\n";

      str += "j = 0\n";
      str += "for i = 0 to (S_size - 1):\n";
      str += "   j = (j + S[i] + K[i % K_size]) % S_size\n";
      str += "   swap S[i] and S[j]\n\n";

      str += "sIndex1 = 0\n";
      str += "sIndex2 = 0\n";
      str += "for i = 1 to cipherText size:\n";
      str += "   sIndex1 = i % S_size\n";
      str += "   sIndex2 = (sIndex2 + S[sIndex1]) % S_size\n";
      str += "   swap S[sIndex1] and S[sIndex2]\n";
      str += "   indexT = (S[sIndex1] + S[sIndex2]) % S_size\n";
      str += "   KeyStream.push_back( S[indexT] )\n\n";

      str += "plainText = KeyStream XOR cipherText\n";
      str += "RETURN plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      // TODO - Add your code here
      std::string cipherText;

      int textSize = plainText.size();

      // Generate key stream using text and password
      std::vector<int> keyStream = generateKeyStream(plainText, password);

      // XOR each character of plainText with the
      for (int i = 0; i < textSize; i++) {
         char c = plainText[i];
         c = (char)((int)c ^ keyStream[i]);
         cipherText.push_back(c);
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
      // TODO - Add your code here
      std::string plainText;

      int textSize = cipherText.size();

      // Generate key stream using text and password
      std::vector<int> keyStream = generateKeyStream(cipherText, password);

      // XOR each character of plainText with the
      for (int i = 0; i < textSize; i++) {
         char c = cipherText[i];
         c = (char)((int)c ^ keyStream[i]);
         plainText.push_back(c);
      }

      return plainText;
   }

private:
   std::vector<int> generateKeyStream(const std::string &text, const std::string & password) {
      std::vector<int> keyStream;
      
      std::vector<int> sArray;
      populateSArray(sArray, S_ARRAY_SIZE);

      std::vector<int> password_ascii;
      populatePasswordASCII(password_ascii, password);

      int passwordLength = password_ascii.size();
      int textSize = text.size();

      //Key Scheduling Algorithm:
      int j = 0;
      for (int i = 0; i < S_ARRAY_SIZE; i++) {
         j = (j + sArray[i] + password_ascii[i % passwordLength]) % S_ARRAY_SIZE;
         swap(sArray, i, j); // Swapping sArray[i] and sArray[j]
      }

      //Pseudo-random Algorithm:
      int index_1 = 0;
      int index_2 = 0;
      
      for (int i = 1; i <= textSize; i++) {
         index_1 = i % S_ARRAY_SIZE;
         index_2 = (index_2 + sArray[index_1]) % S_ARRAY_SIZE;
         swap(sArray, index_1, index_2);
         int t = (sArray[index_1] + sArray[index_2]) % S_ARRAY_SIZE;
         keyStream.push_back(sArray[t]);
      }
      
      return keyStream;
   }

   void swap(std::vector<int> &sArray, int i, int j) {
      int holder = sArray[j];
      sArray[j] = sArray[i];
      sArray[i] = holder;
   }

   void populateSArray(std::vector<int> &sArray, const int size) {
      for (int i = 0; i < size; i++) {
         sArray.push_back(i);
      }
   }

   void populatePasswordASCII(std::vector<int> &password_ascii, const std::string & password) {
      int size = password.size();
      for (int i = 0; i < size; i++) {
         char c = password[i];
         password_ascii.push_back((int)c);
      }
   }
};

#endif // CIPHER01_H
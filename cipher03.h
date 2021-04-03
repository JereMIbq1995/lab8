/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "David Headrick"; }
   virtual std::string getCipherName()  { return "Autokey Cipher"; }
   virtual std::string getEncryptAuth() { return "David Headrick"; }
   virtual std::string getDecryptAuth() { return "David Headrick"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s = "Crypto Corner, ";
      s += "\'Autokey Cipher\', \n    retrieved: ";
      s += "https://crypto.interactive-maths.com/autokey-cipher.html\n";

      s += "UCF.edu, ";
      s += "\'3.2 Autokey Cipher\', \n    retrieved: ";
      s += "http://www.cs.ucf.edu/~dmarino/ucf/cis3362/lectures/3-PolyAlpha.pdf\n";

      s += "GeeksforGeeks, ";
      s += "\'Autokey Cipher | Symmetric Ciphers\', \n    retrieved: ";
      s += "https://www.geeksforgeeks.org/autokey-cipher-symmetric-ciphers/\n";

      s += "OpenGenus.org, ";
      s += "\'Auto Key Cipher\', \n    retrieved: ";
      s += "https://iq.opengenus.org/auto-key-cipher/\n";

      return s;
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
      str =  "\n   encrypt(plainText, password)\n\n";
      str += "      FOR i in size of password\n";
      str += "         char <- password at i\n";
      str += "         accum <- (int)char\n";
      str += "      key <- (accum + length of password) mod 128\n";
      str += "      append key to keystream\n\n";

      str += "      FOR i in size of plaintext - 2\n";
      str += "         char <- plaintext[i]\n";
      str += "         append keystream with (int)char\n\n";

      str += "      FOR i in size of plaintext\n";
      str += "         char <- plaintext[i]\n";
      str += "         append cipherText with keystream and plaintext\n\n";

      str += "      RETURN cipherText\n";

      // The decrypt pseudocode
      str += "\n   decrypt(cipherText, password)\n\n";
      str += "      FOR i in length of password\n";
      str += "         char <- password[i]\n";
      str += "         accum <- (int)char\n\n";

      str += "      key <- (accum + length of password) mod 128\n";
      str += "      append keystream with key\n\n";
      
      str += "      FOR i in length of cipherText\n";
      str += "         char ((int)cipherText) - keystream at i + 128) mod 128\n";
      str += "         append char to plainText\n\n";

      str += "         IF size of keystream < size of cipherText\n";
      str += "           append char to keystream\n\n";
      
      str += "      RETURN plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: encrypt the plaintext using the password
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      std::string cipherText = "";
      std::vector<int> keystream;
      int accum = 0;

      // key maker function return a integer key
      for (int i = 0; i < password.length(); i++)
      {
         char c = password[i];
         accum += (int)c;
      }
      int key = ((accum + password.length()) % 128); // mod it by 128 ASCII size of table, could be const

// 1. push_back the key onto the vector
      keystream.push_back(key);

// 2. go from 0 to plaintext.length() - 2
//    turn into char c = plaintext[i]
//    keystream.push_back((int)c)
      for(int i = 0; i <= (plainText.length() - 2); i++)
      {
         char c = plainText[i];
         keystream.push_back((int)c); // create the keystream (integer version (ascii value) of the char on each element of the vector)
      }

// 3. loop thru plaintext, with every element of plaintext, add it to the same element of keystream, then mod it with 128
      for(int i = 0; i < plainText.length(); i++)
      {
         char c = plainText[i]; // turn element into char
         cipherText.push_back((char)((keystream[i] + ((int)c)) % 128));
      }

      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: decrypt the ciphertext using the password
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      // std::string plainText = cipherText;
      std::string plainText = "";
      std::vector<int> keystream;
      int accum = 0;

      // key maker function return a integer key
      for (int i = 0; i < password.length(); i++)
      {
         char c = password[i];
         accum += (int)c;
      }
      int key = ((accum + password.length()) % 128); // mod it by 128 ASCII size of table, could be const
      
      keystream.push_back(key); // represents the ciphertext and key

      for(int i = 0; i < cipherText.length(); i++)
      {
         // for every element turn it into a char, then turn into an int
         char c = ((int)(cipherText.c_str()[i]) - keystream[i] + 128) % 128;
         plainText.push_back(c); // then push_Back onto plaintext
         if (keystream.size() < cipherText.size())
            keystream.push_back((int)c); //then push_Back onto keystream
      }

      return plainText;
   }
};

#endif // CIPHER03_H
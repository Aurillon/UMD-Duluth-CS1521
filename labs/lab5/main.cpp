#include <iostream>
#include <string>
#include <vector>

#include "isPalindrome.cpp"
bool isPalindrom(const std::string&);

int main() {

   std::vector<std::string> strVec = { "",
                                       "a",
                                       "aba",
                                       "abba",
                                       "deleveled",
                                       "a man a plan a canal panama",
                                       "ab",
                                       "abbc" };

   for (const std::string& currStr : strVec) {
      // Initialize a 'clean' string to empty:
      std::string clean("");

      // Iterate over the string 'currStr' and remove all space
      // characters:
      for (char ch : currStr) {
         if (ch != ' ') {
            clean += ch;
         }
      }
      // Test and report whether the string 'clean' is a palindrome:
      if (isPalindrome(clean) ) {
         std::cout << "YES \""
                   << currStr
                   << "\" is a palindrome."
                   << std::endl;
      }
      else {
         std::cout << "NO \""
                   << currStr
                   << "\" is not a palindrome."
                   << std::endl;
      }
   }

   return EXIT_SUCCESS;
}

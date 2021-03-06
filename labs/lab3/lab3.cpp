/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2019
 *
 *  Testing the ArrayBag class template.
 *
 *  Adapted from pages 103-104, 110-111 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 05 Feb 2019
 *
 *  @version 7.0 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

#include "ArraySet.h"

void displayBag(ArraySet<std::string>& abag) {

   cout << "The bag contains "
        << abag.getCurrentSize()
        << " items:"
        << endl;

   std::vector<std::string> bagItems = abag.toVector();

   int numberOfEntries = (int)bagItems.size();

   for (int i(0); i < numberOfEntries; ++i) {
      cout << bagItems[i]
           << " ";
   }

   cout << endl
        << endl;
}

void bagTester(ArraySet<std::string>& bag, ArraySet<std::string>& bag2) {

   cout << "Difference Function Tests." << endl;
   std::string items1[] = { "a", "b", "c", "d" };
   std::string items2[] = { "e", "f", "g", "h" };

   //TEST
   cout <<"\nDosnt allow dups" << endl;
   bag.clear();
   bag2.clear();
   bag.add("a");
   bag.add("a");
   bag.add("b");
   bag.add("a");
   displayBag(bag);
   bag2.add("a");
   bag2.add("c");
   bag2 = bag.difference(bag2);
   cout << "should return a bag with 1 b"
        << endl;
   displayBag(bag2);

   //TEST
   cout << "left and right side both Empty." << endl;
   bag.clear();
   bag2.clear();
   bag2 = bag.difference(bag2);
   cout << "should return an empty bag"
        << endl;
   displayBag(bag2);

   //TEST
   cout << "left side empty, right side has items." << endl;
   bag.clear();
   bag2.clear();
   for(int i = 0; i < 4; i++) {
      bag2.add(items1[i]);
   }
   cout << "should return an empty bag" << endl;
   bag2 = bag.difference(bag2);
   displayBag(bag2);

   //TEST
   cout << "right side empty, left side has items." << endl;
   bag.clear();
   bag2.clear();
   for(int i = 0; i < 4; i++) {
      bag.add(items2[i]);
   }
   bag2 = bag.difference(bag2);
   cout << "should return bag with 4 items (e, f, g, h)" << endl;
   displayBag(bag2);


   //TEST
   cout << "right and left side have no items in common." << endl;
   bag.clear();
   bag2.clear();
   for(int i = 0; i < 4; i++) {
      bag.add(items1[i]);
      bag2.add(items2[i]);
   }
   bag2 = bag.difference(bag2);
   cout << "should return bag with (a, b, c, d)" << endl;
   displayBag(bag2);

   //TEST
   cout << "right and left side have all same items." << endl;
   bag.clear();
   bag2.clear();
   for(int i = 0; i < 4; i++) {
      bag.add(items1[i]);
      bag2.add(items1[i]);
   }
   bag2 = bag.difference(bag2);
   cout << "should return an empty bag" << endl;
   displayBag(bag2);
   bag.clear();
   bag2.clear();

}

int main() {

   ArraySet<std::string> bag;
   ArraySet<std::string> bag2;

   cout << "Testing the Array-Based Bag:"
        << endl
        << "The initial bag is empty."
        << endl;

   bagTester(bag, bag2);

   cout << "All done!"
        << endl;

   return EXIT_SUCCESS;
}

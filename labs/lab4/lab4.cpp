#include <iostream>
#include <cstdlib>

#include "ArrayList.h"

int getPosistion(ArrayList<int>& list, int& value);

int main() {
   ArrayList<int> list;

   list.insert(1,9);
   list.insert(2,5);
   list.insert(1,0);
   list.insert(2,3);
   list.insert(4,2);

   int posistion = 0;
   int value = 0;

   while(std::cin >> value) {
      if((posistion = getPosistion(list, value)) <= list.getLength() )
      {
         std::cout << "list["
                   << posistion
                   << "] = "
                   << value
                   << "."
                   << std::endl;
      }
      else {
         std::cout << "The list does NOT conatain "
                   << value
                   << "."
                   <<std::endl;
      }
   }
   return EXIT_SUCCESS;
}

int getPosistion(ArrayList<int>& list, int& value) {
   int max = list.getLength();
   int count = 0;
   for(; count < max && list.getEntry(count) != value; ++count) {
   }
   if(count < max) {
      return count;
   }
   else {
      return max +1;
   }
}

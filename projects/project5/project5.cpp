#include <iostream>
#include "DiscList.cpp"
#include "Track.cpp"
#include "Disc.cpp"

void printMenu();
void clear();
void addDisc(DiscList &System);
void removeDisc(DiscList &System);
void listDisc(DiscList &System);
void printSysDisc(DiscList &System);
char getOpt(char opt);

int main() {
   DiscList System;
   char opt = 'Z';
   clear();
   opt = getOpt(opt);
   std::cin.ignore(1000, '\n');

   while(opt != 'Q') {

      if(opt == 'A') {
         //Add new Disc
         clear();
         addDisc(System);
      }

      else if(opt == 'R') {
         //remove a dis
         clear();
         if(System.isEmpty()) {
            removeDisc(System);
         }
         else {
            std::cout << "The System is empty please add a disc first" << std::endl;
         }
      }

      else if(opt == 'P') {
         //print a disc
         clear();
         if(System.isEmpty()) {
            printSysDisc(System);
         }
         else {
            std::cout << "The System is empty please add a disc first" << std::endl;
         }
      }

      else if(opt == 'L') {
         //list discs
         clear();
         if(System.isEmpty()) {
            listDisc(System);
         }
         else {
            std::cout << "The System is empty please add a disc first"<< std::endl;
         }
      }
      else if(opt == 'Q') {
         //quits
      }

      else {
         clear();
         std::cout << "Plz enter a valid choice" << std::endl;
      }
      // getchar();
      //getchar();
      //clear();
      opt = getOpt(opt);
      std::cin.ignore(1000, '\n');
   }
}


void addDisc(DiscList &System) {
   auto aDisc = std::make_shared<Disc>();
   aDisc = aDisc->Disc::getDiscFromUser();
   if(System.insertDisc(aDisc) ) {
      std::cout << "Disc added to the System" << std::endl;
   }
   else {
      std::cout << "Disc not added to the System" <<std::endl;
   }
}

void listDisc(DiscList &System) {
   int length = System.getNumberOfDiscs();
   for(int i(1); i <= length; ++i) {
      std::weak_ptr<Disc> wp = System.retrieveDisc(i);
      std::cout << i << ") " <<"Disc Title: "
                << wp.lock()->getTitle()<< std::endl;
   }
}
void removeDisc(DiscList &System) {
   listDisc(System);
   int pick;
   int length = System.getNumberOfDiscs();
   std::cin >> pick;
   std::cin.ignore(1000, '\n');
   while(!(pick >= 1 && pick <= length)) {
      std::cout << "pick out of bounds please enter valid num" << std::endl;
      std::cin >> pick;
   }
   if(System.removeDisc(System.retrieveDisc(pick))) {
      std::cout << "Disc removed" << std::endl;
   }
}
void printSysDisc(DiscList &System) {
   listDisc(System);
   int pick;
   int length = System.getNumberOfDiscs();
   std::cin >> pick;
   std::cin.ignore(1000, '\n');
   while(!(pick >= 1 && pick <= length)) {
      std::cout << "pick out of bounds please enter valid num" << std::endl;
      std::cin >> pick;
   }
   System.retrieveDisc(pick).lock()->printDisc();
}

void clear() {
   std::cout << "\x1B[2J\x1B[H";
}
char getOpt(char opt) {
   printMenu();
   std::cout << "$ ";
   std::cin >> opt;
   return opt;
}

void printMenu() {
   std::cout << "  _______________________  \n"
             << "// Music Storage Program \\\\\n"
             << "||-----------------------||\n"
             << "||(A)dd a new disc.      ||\n"
             << "||(R)emove a disc.       ||\n"
             << "||(P)rint a disc.        ||\n"
             << "||(L)ist discs.          ||\n"
             << "||(Q)uit.                ||\n"
             << "\\\\-----------------------//" << std::endl;
}

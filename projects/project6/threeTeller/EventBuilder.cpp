#include <string>
#include <iostream>
#include "EventBuilder.h"


EventBuilder::EventBuilder() {
   std::string filename;
   std::cout << "Input file name: ";
   getline(std::cin, filename);
   inputFile.open("../"+filename);
   while(inputFile.fail()) {
      std::cout << "File not found. Please try again.";
      getline(std::cin, filename);
      inputFile.open("../"+filename);
   }
   std::cout << "Simulation of 1 Queue Begins..." << std::endl;
}

Event EventBuilder::createArrivalEvent(int number, int lineNumber) {
   EventType type = EventType::ARRIVAL;
   Time t,dur;

   if(( inputFile >> t >> dur) && t != -1) {
   }
   else {
      type = EventType::NONE;
   }
   Event Arrive(type, t, dur, number);
   Arrive.setLine(lineNumber);
   return Arrive;
}

Event EventBuilder::createDepartureEvent(const Time& currentEventTime,
                                         const Time& transactionLength,
                                         int number, int lineNumber) {
   Time currTime = (currentEventTime + transactionLength);
   EventType type = EventType::DEPARTURE;
   Event Leave(type, currTime, number);
   Leave.setLine(lineNumber);
   return Leave;
}

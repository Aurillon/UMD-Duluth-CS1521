#include <string>
#include <iostream>
#include "EventBuilder.h"


EventBuilder::EventBuilder() {
   std::string filename;
   std::cout << "Input file name: ";
   getline(std::cin, filename);
   inputFile.open("../../inputTests/"+filename);
   while(inputFile.fail()) {
      std::cout << "File not found. Please try again.";
      getline(std::cin, filename);
      inputFile.open("../oneTeller/"+filename);
   }
   std::cout << "Simulation of 1 Queue Begins..." << std::endl;
}

Event EventBuilder::createArrivalEvent(int number) {
   EventType type = EventType::ARRIVAL;
   Time t,dur;
   if((inputFile >> t >> dur) &&  t != -1) {
   }
   else {
      type = EventType::NONE;
   }
   Event Arrive(type, t, dur, number);
   return Arrive;
}

Event EventBuilder::createDepartureEvent(const Time& currentEventTime,
                                         const Time& transactionLength,
                                         int number) {
   Time currTime = (currentEventTime + transactionLength);
   EventType type = EventType::DEPARTURE;
   Event Leave(type, currTime, number);
   return Leave;
}

#ifndef SIMULATION_
#define SIMULATION_

#include "Event.h"
#include "EventBuilder.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"
#include "Statistics.cpp"

class Simulation {
private:
   Event currentEvent;
   EventBuilder eventBuilder;
   LinkedQueue<Event> line1;
   LinkedQueue<Event> line2;
   LinkedQueue<Event> line3;
   PriorityQueue<Event> events;
   Statistics stats;

   int nextLine();
   void processArrival();
   void processDeparture();

public:
   Simulation() = default;
   virtual ~Simulation() = default;

   void simulate();
};

#endif

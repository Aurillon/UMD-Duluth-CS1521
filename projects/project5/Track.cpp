#include "Track.h"

Track::Track(std::shared_ptr<Disc> aDiscPtr) {
   //std::cout << "Track constructor called" << std::endl;
   name = "";
   artist = "";
   playTime = -1;
   number = 0;
   location = "";
   discPtr = aDiscPtr;
}

Track::~Track() {
   std::cout << name << " Track deconstrctor called" << std::endl;
}

std::shared_ptr<Track> Track::getTrackFromUser(std::shared_ptr<Disc> aDisc) {
   auto aTrack = std::make_shared<Track>(aDisc);
   std::cin.ignore(1000, '\n');

   std::cout << "Name of Track: ";
   getline(std::cin, aTrack->name);

   aTrack->artist = aDisc->getArtist();
   if(aDisc->isMultiArtist()) {
      std::cout << "Name of Artist: ";
      getline(std::cin, aTrack->artist);
   }

   std::cout << "PlayTime of Track (min:sec): ";
   aTrack->playTime = aTrack->readPlayTime();
   //std::cout << aTrack->playTime << std::endl;

   std::cout << "Location of Track: ";
   getline(std::cin, aTrack->location);

   aTrack->number = aDisc->getNumberOfTracks() + 1;

   return aTrack;
}

void Track::printTrack() const {
   if(!discPtr.lock()->isMultiArtist()) {
      std::cout << " |-------------------------"
                << "\n |-->Track Number: " << number
                << "\n |-->Track Name: " << name
                << "\n |-->Track PlayTime: " << playTime/60
                << ":" <<playTime - (playTime/60)*60
                << "\n |-->Track Location: " << location
                <<  std::endl;
   }
   else {
      std::cout << " |-------------------------"
                << " |-->Track Number: " << number
                << "\n |-->Track Name: " << name
                << "\n |-->Track Artist: " << artist
                << "\n |-->Track PlayTime: " << playTime/60
                << ":" << playTime - (playTime/60)*60
                << "\n |-->Track Location: " << location
                <<  std::endl;
   }
}

bool Track::isLessThan(std::weak_ptr<Track> trackPtr) const {
   return !(number - trackPtr.lock()->getNumber());
}

int Track::getNumber() const {
   return number;
}

int Track::getPlayTime() const {
   return playTime;
}

int Track::readPlayTime() {
   std::string input;
   getline(std::cin, input);
   //std::cout << input << std::endl;
   //sec = std::stoi(input.substr(input.find(":") +1));
   //min = std::stoi(input);
   //std::cout << "(min:sec) " << std::stoi(input) << ":" <<
   //   std::stoi(input.substr(input.find(":") +1)) << std::endl;
   return (std::stoi(input) * 60 + std::stoi(input.substr(input.find(":") + 1, 2)));
}

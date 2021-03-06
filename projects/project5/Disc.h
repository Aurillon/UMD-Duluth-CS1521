#ifndef DISC_
#define DISC_

#include <memory>
#include <string>
#include "LinkedList.h"


class Track;
class Disc {
  public:
  Disc();
   ~Disc();
   bool isEmpty() const;
   int getNumberOfTracks() const;
   bool insertTrack(std::shared_ptr<Track> aTrack);
   std::weak_ptr<Track> retrieveTrackByNumber(int trackNumber) const;
   std::string getArtist() const;
   std::string getTitle() const;
   bool isMultiArtist() const;
   void printDisc() const;
   void addToTotalPlayTime(int time);
   bool isLessThan(std::weak_ptr<Disc> aDisc) const;
   bool isLessThanOrEqualTo(std::weak_ptr<Disc> aDisc) const;
   std::shared_ptr<Disc> getDiscFromUser();

  private:
   std::string title;
   std::string artist;
   std::string genre;
   int year;
   int totalPlayTime;
   bool multiArtist;
   std::unique_ptr<LinkedList<std::shared_ptr<Track>>> trackListPtr = std::make_unique<LinkedList<std::shared_ptr<Track>>>();
};

#endif

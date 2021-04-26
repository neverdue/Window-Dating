#ifndef STANDARD_H
#define STANDARD_H

#include "person.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvirtual-move-assign"

// inheriting abstract class Person
class Standard : public virtual Person {
private:
  // music genres
  std::vector<std::string> genres;
  std::string bio;
  std::string orientation;
  std::string description_standard;
public:
  void set_genres(std::vector<std::string> genres_param);
  std::vector<std::string> get_genres();
  void set_bio(std::string bio_param);
  std::string get_bio();
  void set_orientation(std::string orientation_param);
  std::string get_orientation();
  void set_description();
  std::string get_description();
};

#pragma GCC diagnostic pop

#endif

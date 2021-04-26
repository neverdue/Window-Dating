#include "standard.h"

using std::string;
using std::vector;

// getters and setters
void Standard::set_genres(vector<string> genres_param) {
  genres = genres_param;
}

vector<string> Standard::get_genres() {
  return genres;
}

void Standard::set_bio(string bio_param) {
  bio = bio_param;
}

string Standard::get_bio() {
  return bio;
}

void Standard::set_orientation(string orientation_param) {
  orientation = orientation_param;
}

string Standard::get_orientation() {
  return orientation;
}

// overloading the set_description function of Person class
void Standard::set_description() {
  description_standard = "NAME: " + this->get_first_name() + " " + this->get_last_name() + "\n";
  description_standard += "AGE: " + this->get_age() + "\n";
  description_standard += "GENDER: " + this->get_gender() + "\n";
  description_standard += "BIO: " + this->get_bio() + "\n";
  description_standard += "ORIENTATION: " + this->get_orientation() + "\n";
  std::vector<std::string> genres_music = this->get_genres();
  description_standard += "MUSIC GENRES: ";
  for (int i = 0; i < genres_music.size()-1; i++) {
    description_standard += genres_music[i] + ", ";
  }
  description_standard += genres_music[genres_music.size()-1] + "\n";
}

string Standard::get_description() {
  return description_standard;
}

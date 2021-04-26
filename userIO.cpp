#include "userIO.h"
#include <iomanip>
#include <limits>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

UserList UserIO::read_data_registrants() {
  ifstream input_file;
  // reading from registrants file
  input_file.open("registrants.txt");
  UserList list;
  std::stringstream ss;
  string line;
  std::vector<string> details;
  string name;
  std::vector<string> parameters;
  std::vector<string> music_genres;
  string fname, lname,  email, phone, genres, bio, orientation, major, schoolYear, school, type;
  int i = 0;
  if (input_file) {
    while(getline(input_file, line)) {
      parameters.clear();
      details.clear();
      music_genres.clear();
      ss.str(line);
      ss.clear();
      // reading each tab separated data
      while (getline(ss, line, '\t')) {
        // adding to parameters vector
        parameters.push_back(line);
        i++;
      }
      // using parameters vector to separate data as per our need for the constructor of User class and adding it to details vector
      for (i = 0; i < parameters.size(); i++) {
        // for name parameter
        if (i == 0) {
          fname = parameters[i].substr(0, parameters[i].find(" "));
          lname = parameters[i].substr(parameters[i].find(" ")+1);
          details.push_back(fname);
          details.push_back(lname);
        } else if (i == 5) {
          // for music genre parameter
          std::stringstream ss2(parameters[i]);
          while(ss2.good()) {
            string substr;
            getline(ss2, substr, ',');
            size_t first = substr.find_first_not_of(' ');
            size_t last = substr.find_last_not_of(' ');
            music_genres.push_back(substr.substr(first, (last-first+1)));
          }
        }
        else {
          // for every other parameter
          details.push_back(parameters[i]);
        }
      }
      if (details[details.size()-1] == "Standard") {
        // creating Standard user object
        User user(details[0], details[1], details[2], details[3], details[4], details[5], music_genres, details[6], details[7], details[8], details[9]);
        // adding to list
        list += user;
      } else if (details[details.size()-1] == "Student") {
        // creating Student user object
        User user(details[0], details[1], details[2], details[3], details[4], details[5], music_genres, details[6], details[7], details[8], details[9], details[10], details[11], details[12]);
        // adding to list
        list += user;
      }
    }
    // closing the file
    input_file.close();
  } else {
    // throwing error if file can't be opened
    throw std::runtime_error("Error! Unable to open file: registrants.txt");
  }
  return list;
}

void UserIO::write_data_registrants(UserList regList) {
  ofstream output_file;
  // opening the file to append to it
  output_file.open("registrants.txt", std::ios::app);
  int length = regList.get_size();
  string line;
  if (output_file) {
    for (int i = 0; i < length; i++) {
      // making a line of data for whatever type of user we get
      line = regList[i].get_first_name() + " " + regList[i].get_last_name() + "\t" + regList[i].get_email() + "\t" + regList[i].get_phone_no() + "\t" + regList[i].get_age() + "\t" + regList[i].get_gender() + "\t";
      for (int j = 0; j < regList[i].get_genres().size() - 1; j++) {
        line += regList[i].get_genres()[j] + ", ";
      }
      line += regList[i].get_genres()[regList[i].get_genres().size() - 1] + "\t" + regList[i].get_bio() + "\t" + regList[i].get_orientation() + "\t";
      if (regList[i].get_type() == "Standard") {
        line += regList[i].get_password() + "\t" + regList[i].get_type();
        output_file << line << std::endl;
      } else if (regList[i].get_type() == "Student") {
        line += regList[i].get_major() + "\t" + regList[i].get_school_year() + "\t" + regList[i].get_school() + "\t" + regList[i].get_password() + "\t" + regList[i].get_type();
        // writing to the file
        output_file << line << std::endl;
      }
    }
    // closing the file
    output_file.close();
  } else {
    throw std::runtime_error("Error! Unable to open file: registrants.txt");
  }
}

vector<pair<string, string> > UserIO::read_data_likes() {
  vector<pair<string, string> > emails;
  vector<string> parameters;
  ifstream input_file;
  string line;
  string emailUser, emailLiked;
  // opening the file to read from it
  input_file.open("likes.txt");
  std::stringstream ss;
  if (input_file) {
    while(getline(input_file, line)) {
      parameters.clear();
      ss.str(line);
      ss.clear();
      while(getline(ss, line, '\t')) {
        parameters.push_back(line);
      }
      // making pairs of likes and adding them to the emails vector
      emails.push_back(std::make_pair(parameters[0], parameters[1]));
    }
    // closing the file
    input_file.close();
  } else {
    throw std::runtime_error("Error! Unable to open file: likes.txt");
  }
  return emails;
}

void UserIO::write_data_likes(string emailUser, string emailLiked) {
  ofstream output_file;
  // opening the file to append to it
  output_file.open("likes.txt", std::ios::app);
  string line;
  if (output_file) {
    // making a line of the email pairs
    line = emailUser + "\t" + emailLiked;
    // writing to the file
    output_file << line << "\n";
    // closing the file
    output_file.close();
  } else {
    throw std::runtime_error("Error! Unable to open file: likes.txt");
  }
}

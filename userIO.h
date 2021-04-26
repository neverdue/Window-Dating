#ifndef USERIO_H
#define USERIO_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "userList.h"

class UserIO {
public:
  // uses UserList arguments
  static UserList read_data_registrants();
  static void write_data_registrants(UserList regList);
  static std::vector<std::pair<std::string, std::string> > read_data_likes();
  static void write_data_likes(std::string emailUser, std::string emailLiked);
};

#endif

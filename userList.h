#ifndef USERLIST_H
#define USERLIST_H

#include <vector>
#include "user.h"

// composed of user objects
class UserList {
private:
  std::vector<User> users;
  int count_student;
  int count_standard;
public:
  // operator overloading
  void operator+= (User user);
  User& operator[] (int index);
  int get_size() const { return users.size(); }
  int get_count_students() const { return count_student; }
  int get_count_standard() const { return count_standard; }
  // friend function to update the count of student and standard users
  friend void count(UserList&);
};

#endif

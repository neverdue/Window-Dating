#include "userList.h"

// operator overaloading definition
void UserList::operator+= (User user) {
  users.push_back(user);
}

User& UserList::operator[] (int index) {
  return users[index];
}

// friend function definition
void count(UserList& list) {
  list.count_student = 0;
  list.count_standard = 0;
  for (int i = 0; i < list.get_size(); i++) {
    if (list[i].get_type() == "Student") {
      list.count_student++;
    } else {
      list.count_standard++;
    }
  }
}

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "person.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvirtual-move-assign"

// inheriting abstract class Person
class Student : public virtual Person {
private:
  std::string major;
  std::string schoolYear;
  std::string school;
public:
  void set_major(std::string major_param);
  std::string get_major();
  void set_school(std::string school_param);
  std::string get_school();
  void set_school_year(std::string schoolYear_param);
  std::string get_school_year();
};

#pragma GCC diagnostic pop

#endif

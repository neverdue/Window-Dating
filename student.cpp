#include "student.h"

using std::string;
using std::vector;

// getters and setters
void Student::set_major(string major_param) {
  major = major_param;
}

string Student::get_major() {
  return major;
}

void Student::set_school_year(string schoolYear_param) {
  schoolYear = schoolYear_param;
}

string Student::get_school_year() {
  return schoolYear;
}

void Student::set_school(string school_param) {
  school = school_param;
}

string Student::get_school() {
  return school;
}

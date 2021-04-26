#include "person.h"

using std::string;

// getters and setters
void Person::set_first_name(string firstName_param) {
  firstName = firstName_param;
}

string Person::get_first_name() {
  return firstName;
}

void Person::set_last_name(string lastName_param) {
  lastName = lastName_param;
}

string Person::get_last_name() {
  return lastName;
}

void Person::set_email(string email_param) {
  email = email_param;
}

string Person::get_email() {
  return email;
}

void Person::set_phone_no(string phoneNo_param) {
  phoneNo = phoneNo_param;
}

string Person::get_phone_no() {
  return phoneNo;
}

void Person::set_age(string age_param) {
  age = age_param;
}

string Person::get_age() {
  return age;
}

void Person::set_gender(string gender_param) {
  gender = gender_param;
}

string Person::get_gender() {
  return gender;
}

#include "user.h"

using std::string;
using std::vector;

// constructor for standard user
User::User(std::string firstName_param, std::string lastName_param, std::string email_param, std::string phoneNo_param, std::string age_param, std::string gender_param, std::vector<std::string> genres_param, std::string bio_param, std::string orientation_param, std::string password_param, std::string type_param) {
  set_first_name(firstName_param);
  set_last_name(lastName_param);
  set_email(email_param);
  set_phone_no(phoneNo_param);
  set_age(age_param);
  set_gender(gender_param);
  set_genres(genres_param);
  set_bio(bio_param);
  set_orientation(orientation_param);
  set_password(password_param);
  set_type(type_param);
  set_description();
}

// constructor for student user
User::User(std::string firstName_param, std::string lastName_param, std::string email_param, std::string phoneNo_param, std::string age_param, std::string gender_param, std::vector<std::string> genres_param, std::string bio_param, std::string orientation_param, std::string major_param, std::string schoolYear_param, std::string school_param, std::string password_param, std::string type_param) {
  set_first_name(firstName_param);
  set_last_name(lastName_param);
  set_email(email_param);
  set_phone_no(phoneNo_param);
  set_age(age_param);
  set_gender(gender_param);
  set_genres(genres_param);
  set_bio(bio_param);
  set_orientation(orientation_param);
  set_major(major_param);
  set_school_year(schoolYear_param);
  set_school(school_param);
  set_password(password_param);
  set_type(type_param);
  set_description();
}

// getters and setters

void User::set_password(string password_param) {
  password = password_param;
}

string User::get_password() {
  return password;
}

void User::set_type(string type_param) {
  type = type_param;
}

string User::get_type() {
  return type;
}

// function overloading of Person
void User::set_description() {
  // calling funtion from standard class to get standard user description
  Standard::set_description();
  desc = Standard::get_description();
  // adding student details if user is a student.
  if (this->get_type() == "Student") {
    desc += "MAJOR: " + this->get_major() + "\n";
    desc += "SCHOOL AND YEAR: " + this->get_school() + " " + this->get_school_year() + "\n";
  }
}

string User::get_description() {
  return desc;
}

// operator overloading
std::ostream& operator<< (std::ostream& out, User& user) {
  out << user.get_description() << std::endl;
  return out;
}

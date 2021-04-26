#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include "person.h"
#include "standard.h"
#include "student.h"

// inheriting the Standard and Student classes
class User : public Standard, public Student{
private:
  std::string type;
  std::string password;
  // description
  std::string desc;
public:
  // constructor for standard user
  User(std::string firstName_param, std::string lastName_param, std::string email_param, std::string phoneNo_param, std::string age_param, std::string gender_param, std::vector<std::string> genres_param, std::string bio_param, std::string orientation_param, std::string password_param, std::string type_param);
  // constructor for student user
  User(std::string firstName_param, std::string lastName_param, std::string email_param, std::string phoneNo_param, std::string age_param, std::string gender_param, std::vector<std::string> genres_param, std::string bio_param, std::string orientation_param, std::string major_param, std::string schoolYear_param, std::string school_param, std::string password_param, std::string type_param);
  void set_type(std::string type_param);
  std::string get_type();
  void set_password(std::string password_param);
  std::string get_password();
  void set_description();
  std::string get_description();
  // operator overloading
  friend std::ostream& operator<< (std::ostream&, User&);
};

#endif

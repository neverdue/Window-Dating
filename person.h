#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <limits>

// class for Person
class Person {
private:
  std::string firstName;
  std::string lastName;
  std::string email;
  std::string phoneNo;
  std::string age;
  std::string gender;
public:
  void set_first_name(std::string firstName_param);
  std::string get_first_name();
  void set_last_name(std::string lastName_param);
  std::string get_last_name();
  void set_email(std::string email_param);
  std::string get_email();
  void set_phone_no(std::string phoneNo_param);
  std::string get_phone_no();
  void set_age(std::string age_param);
  std::string get_age();
  void set_gender(std::string gender_param);
  std::string get_gender();
  virtual void set_description() = 0;
};

#endif

#include "person.h"
#include "standard.h"
#include "student.h"
#include "user.h"
#include "userList.h"
#include "userIO.h"
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include <chrono>
#include <algorithm>
#include <regex>

using namespace std;

// method declarations
void appView(User curr_user);
vector<string> removeDupWord(string str);
bool validateString(const std::string& s);
bool validateNumber(const std::string& s, int mode);
bool validateStringWithSpaces(const std::string& s);
bool is_email_valid(const std::string& email);
bool validatePassword(const std::string& s);
bool valid_phone(std::string str);

// responsible for main menu
int main() {

  cout << "Window Dating" << endl << endl;

  char input;

  cout << "COMMANDS" << endl;
  cout << "r - register" << endl;
  cout << "l - login" << endl;
  cout << "x - exit" << endl << endl;

  // to check if the user entered x and wants to exit
  bool flag = true;
  // to check if the user with the email or phone number already exists.
  bool exists = false;

  UserList list;
  UserList users;

  while(true) {
      // variables for input
      string fname, lname, email, age, gender, password, phone, bio, orientation, major, schoolYear, school, type, musicStyle;
      cout << "Command: ";
      cin >> input;
      vector<string> genres;
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      users = UserIO::read_data_registrants(); // reading in from the registrants.txt file
      if (input == 'r') {
        // registering the user
        cout << endl << "Enter your details below: " << endl;
        cout << "First name: ";
        cin >> fname;
        // validating the data
        if (!validateString(fname)) {
          throw logic_error("Enter a valid first name");
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Last name: ";
        cin >> lname;
        if (!validateString(lname)) {
          throw logic_error("Enter a valid last name");
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Email: ";
        cin >> email;
        if (!is_email_valid(email)) {
          throw logic_error("Enter a valid email");
        }
        // checking if the user already exists with this email
        for (int i = 0; i < users.get_size(); i++) {
          if (users[i].get_email() == email) {
            cout << "A user with this email already exists!" << endl << endl;
            exists = true;
          }
        }
        if (exists) {
          exists = false;
          continue;
        }
        cout << "Password: ";
        cin >> password;
        if (!validatePassword(password)) {
          throw logic_error("Enter a valid password");
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Phone No (no dashes or spaces): ";
        cin >> phone;
        if (!valid_phone(phone)) {
          throw logic_error("Enter a valid phone number");
        }
        // checking if the user already exists with this phone no
        for (int i = 0; i < users.get_size(); i++) {
          if (users[i].get_phone_no() == phone) {
            cout << "A user with this phone number already exists!" << endl << endl;
            exists = true;
          }
        }
        if (exists) {
          exists = false;
          continue;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Age: ";
        cin >> age;
        if (!validateNumber(age, 1)) {
          throw logic_error("Enter a valid age");
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Gender: ";
        cin >> gender;
        if (!validateString(gender)) {
          throw logic_error("Enter a valid gender");
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Music genres (Use spaces for multiple entries): ";
        getline(cin, musicStyle);
        genres = removeDupWord(musicStyle);
        cout << "Bio: ";
        getline(cin, bio);
        cout << "Orientation: ";
        getline(cin, orientation);
        if (!validateStringWithSpaces(orientation)) {
          throw logic_error("Enter a valid orientation");
        }
        cout << "Are you a student? (y/n): ";
        cin >> type;
        if (type != "y" && type != "Y" && type != "n" && type != "N") {
          throw logic_error("Enter a valid response (y/n)");
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (type == "n" || type == "N") {
          // making a standard user object and adding it to the user list
          User user(fname, lname, email, phone, age, gender, genres, bio, orientation, password, "Standard");
          list += user;
        }
        else if (type == "y" || type == "Y") {
          cout << "Major: ";
          getline(cin, major);
          if (!validateStringWithSpaces(major)) {
            throw logic_error("Enter a valid major");
          }
          cout << "School Year (Expected/Graduated): ";
          cin >> schoolYear;
          if (!validateNumber(schoolYear, 0)) {
            throw logic_error("Enter a valid graduation year");
          }
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cout << "School: ";
          getline(cin, school);
          if (!validateStringWithSpaces(school)) {
            throw logic_error("Enter a valid school name");
          }
          // making a student user object and adding it to the user list.
          User user(fname, lname, email, phone, age, gender, genres, bio, orientation, major, schoolYear, school, password, "Student");
          list += user;
        }
        // writing the new user to the file.
        UserIO::write_data_registrants(list);
        cout << endl << "Succesfully Registered!" << endl << endl;
        break;
      } else if (input == 'l') {
        // logging in the user.
        cout << "Enter your email: ";
        cin >> email;
        if (!is_email_valid(email)) {
          throw logic_error("Enter a valid email");
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter your password: ";
        cin >> password;
        if (!validatePassword(password)) {
          throw logic_error("Enter a valid password");
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        UserList users;
        int check = 0;
        // checking if the email and password is correct and then logging them in.
        users = UserIO::read_data_registrants();
        for (int i = 0; i < users.get_size(); i++) {
          if (users[i].get_email() == email && users[i].get_password() == password) {
            check = 1;
            list += users[i];
            cout <<  endl << "Welcome!" << endl << endl;
            break;
          }
        }

        if (check == 0) {
          cout << "Invalid credentials" << endl << endl;
        } else {
          break;
        }

      } else if (input == 'x' || input == 'X') {
        flag = false;
        break;
      } else {
        throw runtime_error("Enter a valid input");
      }
  }

  // if they didn't enter x and have Succesfully registered or logged in
  if (flag == true) {
    // getting the latest list of all users
    users = UserIO::read_data_registrants();
    count(users); // counting the number of student and standard users using this friend function
    cout << "Total student users: " << users.get_count_students() << endl;
    cout << "Total standard users: " << users.get_count_standard() << endl << endl;
    appView(list[list.get_size()-1]); // calling the app view with the current user.
  }

  cout << endl << "Bye!" << endl;

  return 0;

}

// responsible for main menu
void appView(User curr_user) {
  UserList users;
  char input;
  int count = 0;
  int in = 0;
  int j = 0;
  bool ranOnce = false;
  bool initial = false;
  // getting list of users from the file.
  users = UserIO::read_data_registrants();
  // for storing the indexes of the users list and is then shuffled.
  vector<int> nums;
  // for storing indexes that are matched or liked already.
  vector<int> used;
  // for holding one user's used indexes
  vector<int> temp;
  // pair of likes for two users.
  vector<pair<string, string> > likesDataPairs = UserIO::read_data_likes();

  // finding used indexes for one user.
  for (int i = 0; i < users.get_size(); i++) {
    for (int j = 0; j < likesDataPairs.size(); j++) {
      if (likesDataPairs[j].first == curr_user.get_email() && likesDataPairs[j].second == users[i].get_email()) {
        temp.push_back(i);
      }
    }
  }

  // using temp to find common used indexes and adding it to used.
  for(int i = 0; i < temp.size(); i++) {
    if (curr_user.get_email() == users[i].get_email()) {
      continue;
    }
    for (int j = 0; j < likesDataPairs.size(); j++) {
      if (likesDataPairs[j].second == curr_user.get_email() && likesDataPairs[j].first == users[temp[i]].get_email()) {
        used.push_back(temp[i]);
      }
    }
  }

  // if we have used indexes then show the matches
  if (used.size() > 0) {
    cout << "Your matches so far: " << endl;
    for (int i = 0; i < used.size(); i++) {
      if (users[used[i]].get_email() != curr_user.get_email()) {
        cout << users[used[i]].get_first_name() + " " + users[used[i]].get_last_name() + " (email: " + users[used[i]].get_email() + ")" << endl;
      }
    }
    cout << endl;
  }

  // storing only those indexes that haven't been used.
  for (int i = 0; i < users.get_size(); i++) {
    initial = false;
    if (curr_user.get_email() == users[i].get_email()) {
      continue;
    }
    for (int num: used) {
      if (i == num) {
        initial = true;
        break;
      }
    }
    if (initial) {
      continue;
    } else {
      nums.push_back(i);
    }
  }

  // random shuffle of the indexes.
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle (nums.begin(), nums.end(), std::default_random_engine(seed));

  // displaying all user cards
  while (in < nums.size()) {
    bool flag = false;
    // getting the index to display the user at
    int index = nums[in];

    // if this user is liked already don't show it
    for (int j = 0; j < likesDataPairs.size(); j++) {
      if (likesDataPairs[j].first == curr_user.get_email() && likesDataPairs[j].second == users[index].get_email()) {
        flag = true;
      }
    }
    if (flag) {
      in++;
      continue;
    }

    // displaying user cards
    cout << "Here's someone you might like!" << endl;
    cout << users[index]; // using overloaded operators to access user at specified index and displaying it to the console.
    cout << "Hit or miss? (h/m): ";
    cin >> input;
    cout << endl;
    if (input == 'h' || input == 'H') {
      // reading in the latest like pairs.
      vector<pair<string, string> > likesDataPairs = UserIO::read_data_likes();
      for (int i = 0; i < likesDataPairs.size(); i++) {
        // checking if both parties have liked each other, if so then we have found a match.
        if (likesDataPairs[i].second == curr_user.get_email() && likesDataPairs[i].first == users[index].get_email()) {
          cout << "IT'S A MATCH" << endl;
          cout << "Here's their email: " << users[index].get_email() << endl;
          cout << "Have fun!" << endl << endl;
        }
      }
      // writing the like pair to the likes.txt file
      UserIO::write_data_likes(curr_user.get_email(), users[index].get_email());
    } else if (input == 'x' || input == 'X') {
      return;
    } else if (input != 'm' && input != 'M') {
      throw runtime_error("Enter a valid input (h/m)");
    }
    in++;
    ranOnce = true;
  }

  // if the user has already liked everyone or we ran out of users.
  if (!ranOnce) {
    if (users.get_size() >= 2) {
      cout << "You've already liked everyone! Come back later when we have more users!" << endl;
    }
  } else {
    cout << "Everything comes at a price! If you want to find your soulmate, buy the window dating pass!" << endl;
  }

}

// removes trailing spaces
vector<string> removeDupWord(string str) {
  // Used to split string around spaces.
  istringstream ss(str);

  string word; // for storing each word

  vector<string> temp;

  // Traverse through all words
  while (ss >> word) {
    // print the read word
    if (!validateString(word)) {
      throw logic_error("Enter a valid music genre");
    }
    temp.push_back(word);
  }

  return temp;
}

// validates strings
bool validateString(const std::string& s) {
  for (const char c : s) {
    if (!isalpha(c))
      return false;
  }

  return true;
}

// validates strings that accept spaces
bool validateStringWithSpaces(const std::string& s) {
  for (const char c : s) {
    if (!isalpha(c) && !isspace(c))
      return false;
  }

  return true;
}

// validates numbers and does special check for age.
bool validateNumber(const std::string& s, int mode=0) {
  for (const char c : s) {
    if (!isdigit(c))
      return false;
  }

  if (mode == 1) {
    int result = stoi(s);
    if (result > 100 || result <= 0) {
      return false;
    }
  }

  return true;
}

// uses regex to validate email
bool is_email_valid(const std::string& email) {
 // define a regular expression
 const std::regex pattern
    ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

 // try to match the string with the regular expression
 return std::regex_match(email, pattern);
}

// validates the password
bool validatePassword(const std::string& s) {
  for (const char c : s) {
    if (isspace(c))
      return false;
  }

  return true;
}

// validates the phone number.
bool valid_phone(std::string str) {
  if( str.size() != 10 )  {
    return false;
  }

  for( int i = 0; i < str.size(); i++ ) {
    if( !isdigit( str[i] ) ) {
      return false;
    }
  }

  return true;
}

/*
Problem link:
https://www.hackerrank.com/challenges/c-tutorial-class

Resources:
https://www.geeksforgeeks.org/stringstream-c-applications/
https://www.softwaretestinghelp.com/stringstream-class-in-cpp/
*/

#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
    public:
        int age;
        int standard;
        string firstName;
        string lastName;
        
        int get_age() {
            return this -> age;
        }
        void set_age(int _age) {
            this -> age = _age;
        }
        
        int get_standard() {
            return this -> standard;
        }
        void set_standard(int _standard) {
            this -> standard = _standard;
        }
        
        string get_first_name() {
            return this -> firstName;
        }
        void set_first_name(string _firstName) {
            this -> firstName = _firstName;
        }
        
        string get_last_name() {
            return this -> lastName;
        }
        void set_last_name(string _lastName) {
            this -> lastName = _lastName;
        }
        
        string to_string() {
            string output = "";
            string currentString = "";
            stringstream stream;
            
            //output += ::to_string(this -> age);
            stream << this -> age;  // inserting age into stream
            stream >> currentString;    // extracting saved string from stream and saving it into currentString
            output += currentString;
            
            output += ",";
            
            output += this -> firstName;
            
            output += ",";
            
            output += this -> lastName;
            
            output += ",";
            stream.clear();
            currentString = "";
            
            stream << this -> standard;
            stream >> currentString;
            output += currentString;
            
            return output;
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

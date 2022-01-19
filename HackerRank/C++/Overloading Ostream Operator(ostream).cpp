/*
Problem:
https://www.hackerrank.com/challenges/overloading-ostream-operator/problem

Resources:
https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
*/

#include <iostream>

using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
      return first_name_;
    }
    const string& get_last_name() const {
      return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};
// Enter your code here.
ostream &operator <<(ostream &out, const Person &currPerson)
{
    out << "first_name=" << currPerson.get_first_name() << ",last_name=" << currPerson.get_last_name();
    return out;
}

int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}

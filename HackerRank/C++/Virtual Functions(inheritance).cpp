/*
https://www.hackerrank.com/challenges/virtual-functions/problem?isFullScreen=true

Resources:
https://www.geeksforgeeks.org/virtual-function-cpp/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
    int age;
    string name;
    virtual void getdata () {
        cin >> this -> name >> this -> age;
    }
    virtual void putdata () {
        cout << this -> name << " " << this -> age <<endl;
    }
};

class Professor : public Person {
public:
    int publications;
    int cur_id;
    static int professorId;

    Professor () {
        cur_id = ++professorId;
    }
    void getdata () {
        // the name, age and publications of the professor.
        cin >> this -> name >> this -> age >> this -> publications;
    }
    void putdata () {
        // print the name, age, publications and the cur_id
        cout << this -> name << " " << this -> age << " " << this -> publications <<" " << this ->cur_id << endl;
    }
};

int Professor :: professorId = 0;

class Student : public Person {
#define TOTAL_SUBJECT 6
public:
    int marks[TOTAL_SUBJECT];
    int cur_id;
    static int studentId;

    Student () {
        cur_id = ++studentId;
    }
    void getdata () {
        // get the input from the user: the name, age, and the marks of the student in  subjects
        cin >> this -> name >> this -> age;
        for (int i = 0; i < TOTAL_SUBJECT; i++) {
            cin >> this -> marks[i];
        }
    }
    void putdata () {
        // print the name, age, sum of the marks and the cur_id of the student
        int sumOfMarks = 0;
        for (int i = 0; i < TOTAL_SUBJECT; i++) {
            sumOfMarks += this -> marks[i];
        }
        cout << this -> name << " " << this -> age << " " << sumOfMarks << " " << this ->cur_id << endl;
    }
};
int Student :: studentId = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

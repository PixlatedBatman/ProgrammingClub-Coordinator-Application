// Section 3 Question 1
// Stimulation of a Classroom Environment

// This code uses Classes to create ann Object Oriented setup 
// involving people, being either teachers or students. Here, 
// we are maintaing a database of marks of each student, which
// can only be updated by a teacher, and a student can only 
// access his marks.

// Resources Used :
// 1. w3schools : To learn how Classes in c++ are used (tutorials)
// 2. GeeksforGeeks : To learn how to create a vector of class objects
// 3. GeeksforGeeks : Idea about how to randomize the initial attributes

// The number of teachers, students, number of appends, etc are 
// hardcoded here, just as to provide an example, but can later be 
// made into inputs, as currently the Classes are what is important

// The output with the current hardcoded values are stored in a file
// named "Classroom_output.txt", which is attatched in this Repository
// https://github.com/PixlatedBatman/ProgrammingClub-Coordinator-Application

#include <bits/stdc++.h>
using namespace std;
#define llt long long int

class Person{                       //Class to define a Person
    public:
    string name;
    llt age;
    Person(string name, llt age) : name(name), age(age) {}
};

class Student; 
class Teacher : public Person{      // Class to define a Teacher
    public:
    string dept;
    Teacher(string name, llt age, string dept) : Person(name, age), dept(dept) {}

    void UpdateMarks(Student& student, llt NewMarks);   //Function to update marks of a student
};

class Student : public Person{      // Class to define a Student
    public:
    llt marks;

    Student(string name, llt age, llt marks) : Person(name, age), marks(marks) {}

    llt RetrieveMarks(Student& student);        // Function to retrieve marks of a student

};

void Teacher::UpdateMarks(Student& student, llt NewMarks){
    student.marks = NewMarks;           // Defining function for changing marks of a student
}                                       // Can only be called by a Teacher

llt Student::RetrieveMarks(Student& student){
    return student.marks;               // Defining function to retrieve marks of a student
}                                       // Can be called by a student

llt rand_num(llt start, llt range);
string rand_str(llt range);

int main(){
    // The hardcoded values here are num_of_teach, num_of_stud, num_of_changes
    // Also, the length of names, age ranges, etc. are hardcoded

    vector<Student> stud;
    vector<Teacher> teach;
    llt marks, age;
    llt num_of_teach=5, num_of_stud=16; // Can be changed for other numbers
    string name, dept;

    for(int i=0;i<num_of_teach;i++){    // Defining teachers
        name = rand_str(10);
        age = rand_num(30, 30);
        dept = rand_str(6);
        Teacher te(name, age, dept);
        teach.push_back(te);
    }

    for(int i=0;i<num_of_stud;i++){     // Defining students
        name = rand_str(10);
        age = rand_num(10, 10);
        marks = rand_num(0, 100);
        Student st(name, age, marks);
        stud.push_back(st);
    }

    cout << "Initial Datasheet :" << endl << "S.No.\tName\tAge\tMarks" << endl;
    for(int i=0;i<num_of_stud;i++){
        cout << i+1 << "\t" << stud[i].name << "\t" << stud[i].age << "\t" << stud[i].RetrieveMarks(stud[i]) << endl;
    }                                   // Output the details
    cout << endl;

    llt num_of_changes = 4;
    llt rand_teach, rand_stud;
    for(int i=0;i<num_of_changes;i++){  // The teachers changing the marks of selected students
        rand_teach = rand_num(0, num_of_teach);
        rand_stud = rand_num(0, num_of_stud);
        cout << "Updated Marks of roll no. " << rand_stud+1 << " from " << stud[rand_stud].marks;
        teach[rand_teach].UpdateMarks(stud[rand_stud], rand_num(0, 100));
        cout << " to " << stud[rand_stud].marks << endl;
    }
    cout << endl;

    cout << "Final Datasheet :" << endl << "S.No.\tName\tAge\tMarks" << endl;
    for(int i=0;i<num_of_stud;i++){
        cout << i+1 << "\t" << stud[i].name << "\t" << stud[i].age << "\t" << stud[i].RetrieveMarks(stud[i]) << endl;
    }                                   // Output the details
}

llt rand_num(llt start, llt range){     // Function to generate random numbers
    llt len = start + (rand()%range);
    return len;
}
string rand_str(llt range){             // Function to generate random string
    string s;
    char c;
    for(int i=0;i<range;i++){
        c = 'A' + rand_num(0, 26);
        s.push_back(c);
    }
    return s;
}
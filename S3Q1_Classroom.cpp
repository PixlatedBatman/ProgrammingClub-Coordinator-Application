// Section 3 Question 1
// Stimulation of a Classroom Environment

// This code uses Classes to create an Object Oriented setup 
// involving people, being either teachers or students. The School
// and the Teachers can make any necessary classes to their requirement
// and the Student can write his own class. The constraint is that the 
// student cannot access his marks or make changes to it, but the school
// and the teachers can. The necessary functions for it have been written

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

class Student : public Person{      // Class to define a Student
    public:
    llt roll_no;

    Student(string name, llt age, llt roll_no) : Person(name, age), roll_no(roll_no) {}
    
};

class Database : public Student{    // Class made by school to privately store marks of each student
    private:
    llt marks;

    public:
    Database(string name, llt age, llt roll_no, llt marks) : Student(name, age, roll_no), marks(marks) {}

    friend class Teacher;           // Making Teacher as friend class, so that Teachers can change marks of students
};

class Teacher : public Person{      // Class to define a Teacher
    public:
    string dept;
    Teacher(string name, llt age, string dept) : Person(name, age), dept(dept) {}

    void UpdateMarks(Database& database, llt NewMarks){     // Function to update marks of a student
        database.marks = NewMarks;
    }

    llt RetrieveMarks(Database& database){                  // Function to retrieve marks of a student      
        return database.marks;
    }
};


llt rand_num(llt start, llt range);
string rand_str(llt range);

int main(){                         // int main is to be analogous to the commands of "The School"

    // The hardcoded values here are num_of_teach, num_of_stud, num_of_changes
    // Also, the length of names, age ranges, etc. are hardcoded

    vector<Database> stud_db;
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
        Database db(name, age, i+1, marks);
        stud_db.push_back(db);
    }


    cout << "Initial Datasheet :" << endl << "RollNo.\tName\tAge\tMarks" << endl;
    for(int i=0;i<num_of_stud;i++){
        cout << stud_db[i].roll_no << "\t" << stud_db[i].name << "\t" << stud_db[i].age << "\t" << teach[0].RetrieveMarks(stud_db[i]) << endl;
    }                                   // Output the details
    cout << endl;

    llt num_of_changes = 4;
    llt rand_teach, rand_stud;
    for(int i=0;i<num_of_changes;i++){  // The teachers changing the marks of selected students
        rand_teach = rand_num(0, num_of_teach);
        rand_stud = rand_num(0, num_of_stud);
        cout << "Updated Marks of roll no. " << stud_db[rand_stud].roll_no << " from " << teach[rand_teach].RetrieveMarks(stud_db[rand_stud]);
        teach[rand_teach].UpdateMarks(stud_db[rand_stud], rand_num(0, 100));
        cout << " to " << teach[rand_teach].RetrieveMarks(stud_db[rand_stud]) << endl;
    }
    cout << endl;

    cout << "Final Datasheet :" << endl << "Roll No.\tName\tAge\tMarks" << endl;
    for(int i=0;i<num_of_stud;i++){
        cout << stud_db[i].roll_no << "\t" << stud_db[i].name << "\t" << stud_db[i].age << "\t" << teach[0].RetrieveMarks(stud_db[i]) << endl;
    }                                     // Output the details
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
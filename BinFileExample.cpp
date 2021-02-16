#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student 
{
    int id_num;
    string name;
    int total_courses;
    int failed_courses;
    int passed_courses;
    float pass_percentage;
};

int main()
{
    int N;

    cout << "Enter Amount of Students:\n";
    cin >> N;

    ofstream wf("student_list.bin", ios::out | ios::binary);
    if (!wf)
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }
    Student* StuArray; 
	StuArray = new (nothrow) Student[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Enter Student's ID:\n";
        cin >> StuArray[i].id_num;
        cout << "Enter Student's Name:\n";
        cin >> StuArray[i].name;
        cout << "Enter Student's Total Courses Number:\n";
        cin >> StuArray[i].total_courses;
        cout << "Enter Student's Failed Courses Number:\n";
        cin >> StuArray[i].failed_courses;
        cout << "Enter Student's Passed Courses Number:\n";
        cin >> StuArray[i].passed_courses;

        StuArray[i].pass_percentage = ((float)StuArray[i].passed_courses / (float)StuArray[i].total_courses) * 100;

        wf.write((char *) &StuArray[i], sizeof(Student));
    }
    wf.close();
    if (!wf.good())
    {
        cout << "Error writing to file!" << endl;
        return 1;
    }
    delete[] StuArray;

    ifstream rf("student_list.bin", ios::out | ios::binary);
    if (!rf)
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    Student* PrintArray;
	PrintArray = new (nothrow) Student[N];
    for (int i = 0;i < N;i++)
        rf.read((char *) &PrintArray[i], sizeof(Student));
    rf.close();
    if(!rf.good())
    {
        cout << "Error reading file!" << endl;
        return 1;
    }

    cout << "Student Details:\n" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Student ID: " << PrintArray[i].id_num << endl;
        cout << "Student Name: " << PrintArray[i].name << endl;
        cout << "Student Total Courses: " << PrintArray[i].total_courses << endl;
        cout << "Student Failed Courses: " << PrintArray[i].failed_courses << endl;
        cout << "Student Passed Courses: " << PrintArray[i].passed_courses << endl;
        cout << "Student Pass Percentage: " << PrintArray[i].pass_percentage << endl;
        cout << endl;
    }

    delete[] PrintArray;

    return 0;

}

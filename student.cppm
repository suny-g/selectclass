// Module
// File: student.cppm   Version: 1.0   License: AGPLv3
// Created:Ynag Guang
// Email: :2087167099@qq.com
// 2026-01-05 15:41:48
// Time: Description:
//
export module registrar : dn.student;
import registrar:dn.person;  // 改为点分隔
import std;

using std::string;
using std::vector;
using std::print;

export class Student : public Person
{
public:
    Student(int id, string name, double credit = 0, double grade = 0);  // 添加类型
    void selectcourse();
    void lookMyInformation();
    void lookCourseTask();
    void lookCourseMark();
    void cancelCourse();

private:
    double m_credit;
    double m_grade;
    vector<class Course*> _courses;
};

// 构造函数实现
Student::Student(int id, string name, double credit, double grade)
    : Person(id, name), m_credit(credit), m_grade(grade)
{
    print("Student created: ID={}, Name={}, Credit={}, Grade={}\n",
          id, name, credit, grade);
}

void Student::selectcourse()
{
    print("Student::selectcourse() called\n");
}

void Student::lookMyInformation()
{
    print("Credit: {}, Grade: {}\n", m_credit, m_grade);
}

void Student::lookCourseTask()
{
    print("Student::lookCourseTask() called\n");
}

void Student::lookCourseMark()
{
    print("Student::lookCourseMark() called\n");
}

void Student::cancelCourse()
{
    print("Student::cancelCourse() called\n");
}

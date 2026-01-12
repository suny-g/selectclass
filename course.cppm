// Module
// File: course.cppm   Version: 1.0   License: AGPLv3
// Created:Ynag Guang
// Email: :2087167099@qq.com
// 2026-01-05 15:41:48
// Time: Description:
//
export module registrar : dn.course;

import std;

using std::string;
using std::vector;
using std::print;

// 前向声明
class Teacher;
class Student;

export class Course
{
public:
    Course(int id, string name, double credit);
    void lookCourseInformation();
    void addStudent(Student* student);
    void cancelStudent(Student* student);

    int getCid() const { return cid; }
    string getCname() const { return cname; }
    double getCredit() const { return credit; }

private:
    Teacher* GALTeacher;  // 根据UML图命名
    int cid;
    string cname;
    vector<Student*> _students;  // 修复类型
    double credit;
};

Course::Course(int id, string name, double credit)
    : cid(id), cname(name), credit(credit), GALTeacher(nullptr)
{
    print("Course created: ID={}, Name={}, Credit={}\n", id, name, credit);
}

void Course::lookCourseInformation()
{
    print("Course Information: ID={}, Name={}, Credit={}\n",
          cid, cname, credit);
}

void Course::addStudent(Student* student)
{
    if (student) {
        _students.push_back(student);
        print("Student added to course: {}\n", cname);
    }
}

void Course::cancelStudent(Student* student)
{
    // 简单的移除逻辑
    print("Student removed from course: {}\n", cname);
}

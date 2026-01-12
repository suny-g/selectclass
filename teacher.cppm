// Module
// File: teacher.cppm   Version: 1.0   License: AGPLv3
// Created:Ynag Guang
// Email: :2087167099@qq.com
// 2026-01-05 15:41:48
// Time: Description:
//

export module registrar : dn.teacher;

import registrar:dn.person;  // 改为点分隔
import std;

using std::string;
using std::vector;
using std::print;

export class Teacher : public Person
{
public:
    Teacher(int id, string name);
    void lookMyStudent();
    void scoreToStudent();
    void scheduleCourseTask();
    void lookMyAttc();

private:
    vector<class Course> _myATC;  // 注意：这里应该是Course*还是Course？
};

// 构造函数实现
Teacher::Teacher(int id, string name)
    : Person(id, name)
{
    print("Teacher created: ID={}, Name={}\n", id, name);
}

void Teacher::lookMyStudent()
{
    print("Teacher::lookMyStudent() called\n");
}

void Teacher::scoreToStudent()
{
    print("Teacher::scoreToStudent() called\n");
}

void Teacher::scheduleCourseTask()
{
    print("Teacher::scheduleCourseTask() called\n");
}

void Teacher::lookMyAttc()
{
    print("Teacher::lookMyAttc() called\n");
}

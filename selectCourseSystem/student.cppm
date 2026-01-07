// Module
// File: person.cppm   Version: 1.0   License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:44:40
// Time: Description:
//
//Change log
//     [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:44:40
//         *
export module registrar : dn.student;

import :dn.person;
import std;

using std::string;
using std::vector;

export class Student : public Person
{
public:
    Student(int id, string name);
    void selectCourse(class Course* course); //选课
    void addMyGrades(double mark); //添加我的成绩
    void lookMyInformation(); //查看自己的信息
    void lookCourseInformation(class Course* course); //查看课程任务
    void lookCourseMark(class Course* course); //查看课程成绩
    void cancelCourse(class Course* course); //退课
private:
    double m_credit; //我的学分
    std::map<int,double>_grades; //前面用于放课程号，后面放对应的成绩
    vector<class Course*> _courses; //用于存放所选课程
};

Student::Student(int id, string name)
    :Person(id,name),m_credit(0)
{}


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
    Student(int id, string name, m_credit = 0, m_grade = 0);
    void selecteCourse();
    void lookMyInformation();
    void lookCourseTask();
    void lookCourseMark();
    void cancelCourse();
private:
    double m_credit;
    double m_grade;
    vector<class Course*> _courses;
};

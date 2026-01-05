// Module
// File: teacher.cppm   Version: 1.0   License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 16:02:13
// Time: Description:
//
//Change log
//     [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 16:02:13
//         *
export module registrar : dn.course;

import std;

export class Course
{
public:
    void lookCourseInformation();
    void addstudent();
    void cancelStduent();
private:
    class Teacher* GALTeacher;
    int cid;
    string cname;
    vector<class Student*>_students;
    double credit;
};

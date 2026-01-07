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
using std::vector;
using std::string;

export class Course
{
public:
    void lookCourseInformation(); //查看该课程的信息
    void addStudent(class Student* student); //增加课程学生
    void cancelStduent(class Student* student); //删除课程学生
    void scheduleCourse(string task); //课程任务
private:
    class Teacher* GALTeacher; //任教老师
    int cid; //课程号
    string cname; //课程名
    vector<class Student*>_students; //该课程的学生
    double credit; //课程的学分
    string task; //课程任务
};

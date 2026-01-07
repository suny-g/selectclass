// Module
// File: teacher.cppm   Version: 1.0   License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:56:48
// Time: Description:
//
//Change log
//     [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:56:48
//         *
export module registrar : dn.academicsecretary;

import :dn.person;
import std;

using std::string;
using std::vector;

export class AcademicSecretary : public Person
{
public:
    AcademicSecretary(int id, string name);
    class Course* findCourseId(int cid); //找到对应的课程
    class Student* findStudentId(int sid); //找到对应的学生
    class Teacher* findTeacherId(int tid); //找到对应的教师
    void addTeacherTAC(int tid, int cid); //添加老师的开课
    void cancelTeacherTAC(int tid, int cid); //取消老师的开课
    void courseInquiry(); //查询所有课程
    void addCourse(int cid); //添加新课程
    void cancelCourse(int cid); //删除课程
private:
    vector<class Course*>_courses;  //存放所有课程
    vector<class Student*>_students; //存放所有学生
    vector<class Teacher*>_teachers; //存放所有老师
};

AcademicSecretary::AcademicSecretary(int id, string name)
    :Person(id,name)
{}

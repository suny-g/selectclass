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
    void findCourseId();
    void findStudentId();
    void findTeacherId();
    void addTeacherTAC();
    void cancelTeacherTAC();
    void courseInquiry();
    void addCourse();
    void cancelCourse();
private:
    vector<class Course*>_courses;
    vector<class Student*>_students;
    vector<class Teacher*>_teachers;
};

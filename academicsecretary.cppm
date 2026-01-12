// Module
// File: academicsecretary.cppm   Version: 1.0   License: AGPLv3
// Created:Ynag Guang
// Email::2087167099@qq.com
// 2026-01-05 15:41:48
// Time: Description:
//
export module registrar : dn.academicsecretary;

import :dn.person;
import registrar.dn.person;  // 改为点分隔
import std;

using std::string;
using std::vector;
using std::print;

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
    vector<class Course*> courses;
    vector<class Student*> students;
    vector<class Teacher*> _teachers;  // 修复命名一致性问题
};

AcademicSecretary::AcademicSecretary(int id, string name)
    : Person(id, name)
{
    print("AcademicSecretary created: ID={}, Name={}\n", id, name);
}

void AcademicSecretary::findCourseId()
{
    print("AcademicSecretary::findCourseId() called\n");
}

void AcademicSecretary::findStudentId()
{
    print("AcademicSecretary::findStudentId() called\n");
}

void AcademicSecretary::findTeacherId()
{
    print("AcademicSecretary::findTeacherId() called\n");
}

void AcademicSecretary::addTeacherTAC()
{
    print("AcademicSecretary::addTeacherTAC() called\n");
}

void AcademicSecretary::cancelTeacherTAC()
{
    print("AcademicSecretary::cancelTeacherTAC() called\n");
}

void AcademicSecretary::courseInquiry()
{
    print("AcademicSecretary::courseInquiry() called\n");
}

void AcademicSecretary::addCourse()
{
    print("AcademicSecretary::addCourse() called\n");
}

void AcademicSecretary::cancelCourse()
{
    print("AcademicSecretary::cancelCourse() called\n");
}

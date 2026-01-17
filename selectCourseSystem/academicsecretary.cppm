// Module
// File: teacher.cppm Version: 1.0 License: AGPLv3
// Created: Luolianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:56:48
// Time: Description:
//
// Change log
// [v1.1] Luolianqiu 2024051604059@qq.com 2026-01-05 15:56:48
// *
export module registrar : dn.academicsecretary;

import :dn.person;
import :dn.teacher;
import std;
using std::string;
using std::vector;
using std::print;

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
    vector<class Course*> courses;
    vector<class Student*> students;
    vector<class Teacher*> teachers;
};

// 实现代码
AcademicSecretary::AcademicSecretary(int id, string name) : Person(id, name) {}

class Course* AcademicSecretary::findCourseId(int cid)
{
    // 实际中应该从数据库查询
    for (auto course : courses) {
        // 这里需要Course类有getId()方法
        // if (course->getId() == cid) return course;
    }
    return nullptr;
}

class Student* AcademicSecretary::findStudentId(int sid)
{
    // 实际中应该从数据库查询
    for (auto student : students) {
        // if (student->getId() == sid) return student;
    }
    return nullptr;
}

class Teacher* AcademicSecretary::findTeacherId(int tid)
{
    // 实际中应该从数据库查询
    for (auto teacher : teachers) {
        // if (teacher->getId() == tid) return teacher;
    }
    return nullptr;
}

void AcademicSecretary::addTeacherTAC(int tid, int cid)
{
    class Teacher* teacher = findTeacherId(tid);
    class Course* course = findCourseId(cid);

    if (teacher && course) {
        print("教师ID：{} 被分配到课程ID：{}\n", tid, cid);
        teacher->addMyATC(course);
    } else {
        print("错误：教师或课程不存在！\n");
    }
}

void AcademicSecretary::cancelTeacherTAC(int tid, int cid)
{
    print("取消教师ID：{} 的课程ID：{} 的授课\n", tid, cid);
    // 实际中需要从教师的课程列表中移除该课程
}

void AcademicSecretary::courseInquiry()
{
    print("=== 所有课程查询 ===\n");
    for (auto course : courses) {
        course->lookCourseInformation();
    }
}

void AcademicSecretary::addCourse(int cid)
{
    print("添加课程ID：{}\n", cid);
    // 实际中需要创建Course对象并添加到courses列表
}

void AcademicSecretary::cancelCourse(int cid)
{
    print("删除课程ID：{}\n", cid);
    // 实际中需要从courses列表中移除该课程
}

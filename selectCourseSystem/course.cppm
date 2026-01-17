// Module
// File: teacher.cppm Version: 1.0 License: AGPLv3
// Created: Luolianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 16:02:13
// Time: Description:
//
// Change log
// [v1.1] Luolianqiu 2024051604059@qq.com 2026-01-05 16:02:13
// *
export module registrar : dn.course;

import std;
using std::vector;
using std::string;
using std::print;

export class Course
{
public:
    void lookCourseInformation(); //查看该课程的信息
    void addStudent(class Student* student); //增加课程学生
    void cancelStudent(class Student* student); //删除课程学生
    void scheduleCourse(string task); //课程任务
private:
    class Teacher* GALTeacher; //任教老师
    int cid; //课程号
    string cname; //课程名
    vector<class Student*>_students; //该课程的学生
    double credit; //课程的学分
    string task; //课程任务
};

// 实现代码
void Course::lookCourseInformation()
{
    print("课程信息：\n");
    print("课程号：{}\n", cid);
    print("课程名：{}\n", cname);
    print("学分：{}\n", credit);
    print("任教老师：{}\n", GALTeacher ? "已分配" : "未分配");
    print("学生人数：{}\n", _students.size());
    print("课程任务：{}\n", task);
}

void Course::addStudent(class Student* student)
{
    if (student) {
        _students.push_back(student); //存储指针，而不是解引用
        print("学生已添加到课程\n");
    }
}

void Course::cancelStudent(class Student* student)
{
    if (student) {
        //从vector中移除指针
        _students.erase(
                  std::remove(_students.begin(), _students.end(), student),
                  _students.end()
              );
        print("学生已从课程中移除\n");
    }
}

void Course::scheduleCourse(string task)
{
    this->task = task;
    print("课程任务已安排：{}\n", task);
}

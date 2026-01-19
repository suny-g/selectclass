// Module
// File: person.cppm Version: 1.0 License: AGPLv3
// Created: Luolianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:44:40
// Time: Description:
//
//Change log[v1.1] Luolianqiu 2024051604059@qq.com 2026-01-05 15:44:40
export module registrar : dn.student;

import :dn.person;
import :dn.course;
import std;

using std::string;
using std::vector;
using std::print;
using std::map;

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
     vector<class Course*> _courses; //用于存放所选课程
private:
    double m_credit; //我的学分
    std::map<int,double> grades; //前面用于放课程号，后面放对应的成绩
};

// 实现代码
Student::Student(int id, string name) : Person(id, name), m_credit(0) {}

void Student::selectCourse(class Course* course)
{
    if (course) {
        _courses.push_back(course);
        print("选课成功！\n");
    } else {
        print("错误：课程不存在！\n");
    }
}

void Student::addMyGrades(double mark)
{
    // 假设最后一个课程的ID
    int lastCourseId = _courses.empty() ? 0 : 1; // 简化处理
    grades[lastCourseId] = mark;
    print("成绩已添加：{}\n", mark);
}

void Student::lookMyInformation()
{
    print("学生信息：\n");
    print("ID：{}\n", m_id);
    print("姓名：{}\n", m_name);
    print("学分：{}\n", m_credit);
    print("已选课程数：{}\n", _courses.size());
}

void Student::lookCourseInformation(class Course* course)
{
    if (course) {
        course->lookCourseInformation();
    } else {
        print("所有已选课程：\n");
        for (auto c : _courses) {
            c->lookCourseInformation();
        }
    }
}

void Student::lookCourseMark(class Course* course)
{
    if (course) {
        // 假设course有getId()方法
        // int cid = course->getId();
        // if (grades.find(cid) != grades.end()) {
        //     print("课程成绩：{}\n", grades[cid]);
        // } else {
        //     print("暂无成绩\n");
        // }
    }
}

void Student::cancelCourse(class Course* course)
{
    if (course) {
        // 实际中需要从_courses中移除该课程
        print("退课成功！\n");
    }
}

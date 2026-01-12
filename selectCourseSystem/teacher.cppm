// Module
// File: CMakelsits.txt Version: 1.0 License: AGPLv3
// Created: LuoJiangiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:51:28
// Time: Description:
//
//Change log
// [v1.1] LuoJiangiu 2024051604059@qq.com 2026-01-05 15:51:28
// *

export module registrar : dn.teacher;

import :dn.person;
import std;

using std::string;
using std::vector;

export class Teacher : public Person
{
public:
    Teacher(int id, string name);
    void lookMyStudent(); //查询自己开设课程的学生
    void scoreToStudent(class Course* course); //为学生成绩打分
    void scheduleCourseTask(string task,class Course* course); //安排教学任务；
    void lookMyATC(); //查看我开设的课程
    void addMyATC(class Course* course); //添加开设的课程
private:
    vector<class Course*> _myATC; //用于存放我开设的课程
};

// 实现代码
Teacher::Teacher(int id, string name) : Person(id, name) {}

void Teacher::lookMyStudent()
{
    print("我的学生：\n");
    for (auto course : _myATC) {
        // 实际中需要遍历course中的所有学生
        print("课程中的学生列表\n");
    }
}

void Teacher::scoreToStudent(class Course* course)
{
    if (course) {
        print("为课程评分\n");
        // 实际中需要具体的评分逻辑
    }
}

void Teacher::scheduleCourseTask(string task,class Course* course)
{
    if (course) {
        course->scheduleCourse(task);
        print("教学任务已安排\n");
    }
}

void Teacher::lookMyATC()
{
    print("我开设的课程：\n");
    for (auto course : _myATC) {
        course->lookCourseInformation();
    }
}

void Teacher::addMyATC(class Course* course)
{
    if (course) {
        _myATC.push_back(course);
        print("课程已添加到我的授课列表\n");
    }
}

// Module
// File: CMakeLists.txt   Version: 1.0   License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:51:28
// Time: Description:
//
//Change log
//     [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:51:28
//         *

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
    void scheduleCourseTask(string task,class Course* course); //安排教学任务;
    void lookMyATC(); //查看我开设的课程
    void addMyATC(class Course* course); //添加开设的课程
private:
    vector<class Course*> _myATC; //用于存放我开设的课程
};

Teacher::Teacher(int id, string name)
    :Person(id,name)
{}

// Module
// File: controller.cppm   Version: 1.0   License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:30:53
// Time: Description:
//
//Change log
//     [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:30:53
//         *
export module registrar : ctr.teachercontroller;

import std;
import :dn.teacher;

export class TeacherController
{
public:
    void menu(); //显示菜单
    void schedukeTask(class Teacher* teacher); //安排教学任务
    void score(class Teacher* teacher); //给学生评分
    void lookMyStudent(class Teacher* teacher); //查看我的学生
    void lookMyTAC(class Teacher* teacher); //查看我任教的课程
};

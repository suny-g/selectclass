// Module
// File: controller.cppm   Version: 1.0   License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:26:30
// Time: Description:
//
//Change log
//     [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:26:30
//         *

export module registrar : ctr.studentcontroller;

import std;
import :dn.student;

export class StudentController
{
public:
    void menu(); //显示菜单
    void courseInquiry(class Student* student); //控制学生查询自己的课程
    void selectCourse(class Student* student); //选课
    void cancelCourse(class Student* student); //退课
    void lookPersonInformation(class Student* student); //查看个人信息
};

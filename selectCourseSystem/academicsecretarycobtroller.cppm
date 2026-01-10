// Module
// File: teachercontroller.cpp   Version: 1.0   License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:34:48
// Time: Description:
//
//Change log
//     [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:34:48
//         *此模块为教学秘书的控制器
export module registrar : ctr.academicsecretarycontroller;

import std;
import :dn.academicsecretary;

export class AademicSecretaryController
{
public:
    void menu(); //显示菜单
    void addTeacherTAC(class AcademicSecretary *academicsecretary); //管理教师的授课
    void cancelTeacherTAC(class AcademicSecretary *academicsecretary); //删除教师的授课
    void courseInquiry(class AcademicSecretary *academicsecretary); //课程查询
    void addCourse(class AcademicSecretary *academicsecretary); //添加课程
    void cancelCourse(class AcademicSecretary *academicsecretary); //删除课程
};

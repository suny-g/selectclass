// Module
// File: controller.cppm Version: 1.0 License: AGPLv3
// Created: Luojiangju
// Email: 2024051604059@qq.com
// 2026-01-05 15:26:30
// Time: Description:
//
// Change log
// [v1.1] Luojiangju 2024051604059@qq.com 2026-01-05 15:26:30
// *
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

// 实现代码
void StudentController::menu()
{
    print("\n=== 学生管理系统 ===\n");
    print("1. 查询课程\n");
    print("2. 选课\n");
    print("3. 退课\n");
    print("4. 查看个人信息\n");
    print("0. 返回上级菜单\n");
}

void StudentController::courseInquiry(class Student* student)
{
    if (!student) {
        print("错误：学生对象为空！\n");
        return;
    }

    print("=== 查询课程 ===\n");
    student->lookCourseInformation(nullptr);
}

void StudentController::selectCourse(class Student* student)
{
    if (!student) {
        print("错误：学生对象为空！\n");
        return;
    }

    print("=== 选课 ===\n");
    print("请输入课程指针（实际中需要从数据库获取）：");
    // 这里需要具体的课程选择逻辑
    class Course* course = nullptr;
    student->selectCourse(course);
}

void StudentController::cancelCourse(class Student* student)
{
    if (!student) {
        print("错误：学生对象为空！\n");
        return;
    }

    print("=== 退课 ===\n");
    print("请输入要退出的课程指针：");
    class Course* course = nullptr;
    student->cancelCourse(course);
}

void StudentController::lookPersonInformation(class Student* student)
{
    if (!student) {
        print("错误：学生对象为空！\n");
        return;
    }

    print("=== 个人信息 ===\n");
    student->lookMyInformation();
}

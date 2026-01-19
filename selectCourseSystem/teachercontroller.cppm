// Module
// File: controller.cppm    Version: 1.0    License: AGPLv3
// Created: Luojiangju
// Email: 2024051604059@qq.com
// 2026-01-05 15:30:53
// Time: Description:
//
//Change log
// [v1.1] Luojiangju 2024051604059@qq.com 2026-01-05 15:30:53
//
export module registrar : ctr.teachercontroller;

import std;
import :dn.teacher;

export class TeacherController
{
public:
    void menu(); //显示菜单
    void scheduleTask(class Teacher* teacher); //安排教学任务
    void score(class Teacher* teacher); //给学生评分
    void lookMyStudent(class Teacher* teacher); //查看我的学生
    void lookMyTAC(class Teacher* teacher); //查看我任教的课程
};

// 实现代码
void TeacherController::menu()
{
    print("\n=== 教师管理系统 ===\n");
    print("1. 安排教学任务\n");
    print("2. 给学生评分\n");
    print("3. 查看我的学生\n");
    print("4. 查看我任教的课程\n");
    print("0. 返回上级菜单\n");
}

void TeacherController::scheduleTask(class Teacher* teacher)
{
    if (!teacher) {
        print("错误：教师对象为空！\n");
        return;
    }

    print("=== 安排教学任务 ===\n");
    print("请输入任务内容：");
    std::string task;
    std::cin.ignore();
    std::getline(std::cin, task);

    print("请输入课程指针：");
    class Course* course = nullptr;
    teacher->scheduleCourseTask(task, course);
}

void TeacherController::score(class Teacher* teacher)
{
    if (!teacher) {
        print("错误：教师对象为空！\n");
        return;
    }

    print("=== 给学生评分 ===\n");
    print("请输入课程指针：");
    class Course* course = nullptr;
    teacher->scoreToStudent(course);
}

void TeacherController::lookMyStudent(class Teacher* teacher)
{
    if (!teacher) {
        print("错误：教师对象为空！\n");
        return;
    }

    print("=== 我的学生 ===\n");
    teacher->lookMyStudent();
}

void TeacherController::lookMyTAC(class Teacher* teacher)
{
    if (!teacher) {
        print("错误：教师对象为空！\n");
        return;
    }

    print("=== 我任教的课程 ===\n");
    teacher->lookMyATC();
}

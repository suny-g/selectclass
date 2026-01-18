//Module    LuoJianqiu 2026-01-05
// File: main.cpp Version: 1.0 License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:09:54
// Time: Description:
//
//Change log
// [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:09:54
// *
module;
#include <cstddef>

export module registrar;
export import :ui;
export import :controller;
export import :domain;
export import :database;
import std;

export class Registrar
{
public:
    int exec();

private:
    void studentSystem();
    void teacherSystem();
    void academicSecretarySystem();

    // 模拟内存数据
    std::vector<class Student*> students;
    std::vector<class Teacher*> teachers;
    std::vector<class AcademicSecretary*> secretaries;
    std::vector<class Course*> courses;

    // 创建模拟数据
    void initializeMockData();
};

// 实现代码
int Registrar::exec()
{
    UI ui;
    ui.guide();

    // 初始化模拟数据
    initializeMockData();

    while (true) {
        ui.sign();

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            print("感谢使用，再见！\n");
            break;
        }

        switch (choice) {
            case 1:
                studentSystem();
                break;
            case 2:
                teacherSystem();
                break;
            case 3:
                academicSecretarySystem();
                break;
            default:
                print("无效选择，请重新输入！\n");
        }
    }

    return 0;
}

void Registrar::initializeMockData()
{
    print("\n=== 初始化模拟数据 ===\n");

    // 创建学生
    students.push_back(new Student(1001, "张三"));
    students.push_back(new Student(1002, "李四"));
    students.push_back(new Student(1003, "王五"));

    // 创建教师
    teachers.push_back(new Teacher(2001, "张老师"));
    teachers.push_back(new Teacher(2002, "李老师"));

    // 创建教学秘书
    secretaries.push_back(new AcademicSecretary(3001, "教学秘书"));

    // 创建课程
    courses.push_back(new Course());
    courses.push_back(new Course());
    courses.push_back(new Course());

    // 设置课程信息
    courses[0]->cid = 101;
    courses[0]->cname = "C++编程";
    courses[0]->credit = 3.0;

    courses[1]->cid = 102;
    courses[1]->cname = "数据结构";
    courses[1]->credit = 4.0;

    courses[2]->cid = 103;
    courses[2]->cname = "数据库原理";
    courses[2]->credit = 3.0;

    print("模拟数据创建完成！\n");
}

void Registrar::studentSystem()
{
    print("\n=== 学生系统 ===\n");
    print("请选择学生：\n");
    for (size_t i = 0; i < students.size(); ++i) {
        print("{}. {} (ID: {})\n", i + 1, students[i]->m_name, students[i]->m_id);
    }

    int studentChoice;
    std::cin >> studentChoice;

    if (studentChoice < 1 || studentChoice > static_cast<int>(students.size())) {
        print("选择无效！\n");
        return;
    }

    Student* currentStudent = students[studentChoice - 1];
    StudentController controller;

    int choice;
    do {
        controller.menu();
        std::cin >> choice;

        switch (choice) {
            case 1: // 查询课程
                controller.courseInquiry(currentStudent);
                break;
            case 2: // 选课
            {
                print("\n可选课程：\n");
                for (size_t i = 0; i < courses.size(); ++i) {
                    print("{}. {} (课程号: {})\n", i + 1, courses[i]->cname, courses[i]->cid);
                }
                print("请选择课程编号：");
                int courseChoice;
                std::cin >> courseChoice;

                if (courseChoice >= 1 && courseChoice <= static_cast<int>(courses.size())) {
                    currentStudent->selectCourse(courses[courseChoice - 1]);
                    courses[courseChoice - 1]->addStudent(currentStudent);
                } else {
                    print("选择无效！\n");
                }
                break;
            }
            case 3: // 退课
            {
                print("学生 {} 的已选课程：\n", currentStudent->m_name);
                // 这里需要显示学生已选课程，然后选择退课
                // 简化处理：直接退第一门课（如果存在）
                if (!currentStudent->_courses.empty()) {
                    Course* courseToDrop = currentStudent->_courses[0];
                    currentStudent->cancelCourse(courseToDrop);
                } else {
                    print("该学生没有选任何课程！\n");
                }
                break;
            }
            case 4: // 查看个人信息
                controller.lookPersonInformation(currentStudent);
                break;
            case 0: // 返回
                print("返回主菜单...\n");
                break;
            default:
                print("无效选择！\n");
        }

    } while (choice != 0);
}

void Registrar::teacherSystem()
{
    print("\n=== 教师系统 ===\n");
    print("请选择教师：\n");
    for (size_t i = 0; i < teachers.size(); ++i) {
        print("{}. {} (ID: {})\n", i + 1, teachers[i]->m_name, teachers[i]->m_id);
    }

    int teacherChoice;
    std::cin >> teacherChoice;

    if (teacherChoice < 1 || teacherChoice > static_cast<int>(teachers.size())) {
        print("选择无效！\n");
        return;
    }

    Teacher* currentTeacher = teachers[teacherChoice - 1];
    TeacherController controller;

    int choice;
    do {
        controller.menu();
        std::cin >> choice;

        switch (choice) {
            case 1: // 安排教学任务
            {
                print("请输入任务内容：");
                std::string task;
                std::cin.ignore();
                std::getline(std::cin, task);

                print("选择课程：\n");
                for (size_t i = 0; i < courses.size(); ++i) {
                    print("{}. {} (课程号: {})\n", i + 1, courses[i]->cname, courses[i]->cid);
                }
                int courseChoice;
                std::cin >> courseChoice;

                if (courseChoice >= 1 && courseChoice <= static_cast<int>(courses.size())) {
                    currentTeacher->scheduleCourseTask(task, courses[courseChoice - 1]);
                    currentTeacher->addMyATC(courses[courseChoice - 1]);
                } else {
                    print("选择无效！\n");
                }
                break;
            }
            case 2: // 给学生评分
                print("评分功能（简化版）\n");
                currentTeacher->scoreToStudent(nullptr);
                break;
            case 3: // 查看我的学生
                currentTeacher->lookMyStudent();
                break;
            case 4: // 查看我任教的课程
                currentTeacher->lookMyATC();
                break;
            case 0: // 返回
                print("返回主菜单...\n");
                break;
            default:
                print("无效选择！\n");
        }

    } while (choice != 0);
}

void Registrar::academicSecretarySystem()
{
    print("\n=== 教学秘书系统 ===\n");

    AcademicSecretary* secretary = secretaries[0]; // 只有一个秘书
    AademicSecretaryController controller;

    int choice;
    do {
        controller.menu();
        std::cin >> choice;

        switch (choice) {
            case 1: // 添加教师授课
                controller.addTeacherTAC(secretary);
                break;
            case 2: // 取消教师授课
                controller.cancelTeacherTAC(secretary);
                break;
            case 3: // 课程查询
                controller.courseInquiry(secretary);
                break;
            case 4: // 添加课程
                controller.addCourse(secretary);
                break;
            case 5: // 删除课程
                controller.cancelCourse(secretary);
                break;
            case 0: // 返回
                print("返回主菜单...\n");
                break;
            default:
                print("无效选择！\n");
        }

    } while (choice != 0);
}

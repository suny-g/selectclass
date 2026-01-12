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
export module registrar;
export import :ui;
export import :controller;
export import :domain;
export import :database;
import std;
export class Registrar
{
public:
    //控制整个程序的进行，以及反应状态
    int exec();
};

// 实现代码
int Registrar::exec()
{
    UI ui;
    ui.guide();

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
                print("学生功能\n");
                // 实际中需要创建StudentController并调用其menu()
                break;
            case 2:
                print("教师功能\n");
                // 实际中需要创建TeacherController并调用其menu()
                break;
            case 3:
                print("教学秘书功能\n");
                // 实际中需要创建AcademicSecretaryController并调用其menu()
                break;
            default:
                print("无效选择，请重新输入！\n");
        }
    }

    return 0;
}

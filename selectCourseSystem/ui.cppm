//Module
// File: registrar.cppm Version: 1.0 License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:21:23
// Time: Description:
//
//Change log
// [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:21:23
//

export module registrar : ui;

import std;
using std::print;


export class UI
{
public:
    void sign(); //系统的登陆函数
    void guide(); //引导用户操作的函数
};

// 实现代码
void UI::sign()
{
    print("=== 选课系统登录 ===\n");
    print("请选择身份：\n");
    print("1. 学生\n");
    print("2. 教师\n");
    print("3. 教学秘书\n");
    print("0. 退出系统\n");
}

void UI::guide()
{
    print("欢迎使用选课系统！\n");
    print("请根据菜单提示进行操作\n");
}

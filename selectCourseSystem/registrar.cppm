// Module
// File: main.cpp   Version: 1.0   License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:09:54
// Time: Description:
//
//Change log
//     [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:09:54
//         *

export module registrar;

export import :ui;
export import :controller;
export import :domain;

import std;

export class Registrar
{
public:
    //控制整个程序的进行，以及反应状态
    int exec();
};

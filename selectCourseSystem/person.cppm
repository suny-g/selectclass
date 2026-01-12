// Module
// File: domain.cpp Version: 1.0 License: AGPLv3
// Created: Luolianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:41:48
// Time: Description:
//
// Change log
// [v1.1] Luolianqiu 2024051604059@qq.com 2026-01-05 15:41:48
// *
export module registrar : dn.person;

import std;
using std::string;

export class Person
{
public:
    Person(int id, string name);
    bool hasId(int id);
    string info();
private:
    int m_id;
    string m_name;
};

// 实现代码
Person::Person(int id, string name) : m_id(id), m_name(name) {}

string Person::info()
{
    return std::format("{} {}", m_id, m_name);
}

bool Person::hasId(int id)
{
    return m_id == id;
}

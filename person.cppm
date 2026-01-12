// Module
// File: person.cppm   Version: 1.0   License: AGPLv3
// Created:Ynag Guang
// Email:2087167099@qq.com
// 2026-01-05 15:41:48
// Time: Description:
//
export module registrar : dn.person;
import std;

using std::string;
using std::print;

export class Person
{
public:
    Person(int id, string name);
    bool hasId();
    string info();

private:
    int m_id;
    string m_name;
};

// 构造函数实现
Person::Person(int id, string name)
    : m_id(id), m_name(name)
{
    print("Person created: ID={}, Name={}\n", id, name);
}

bool Person::hasId()
{
    return m_id > 0;
}

string Person::info()
{
    return "ID: " + std::to_string(m_id) + ", Name: " + m_name;
}

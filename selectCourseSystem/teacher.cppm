// Module
// File: CMakeLists.txt   Version: 1.0   License: AGPLv3
// Created: LuoJianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:51:28
// Time: Description:
//
//Change log
//     [v1.1] LuoJianqiu 2024051604059@qq.com 2026-01-05 15:51:28
//         *

export module registrar : dn.teacher;

import :dn.person;
import std;

using std::name;
using std::vector;

export class Teacher : public Person
{
public:
    Teacher(int id, string name);
    void lookMyStudent();
    void scoreToStudent();
    void scheduleCourseTask();
    void lookMyAtc();
private:
    vector<class Course*> _myATC;
}

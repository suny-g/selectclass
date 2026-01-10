// Module
// File: daStudent.cppm   Version: 0.1.0   License: AGPLv3
// Created:Luojianqiu       2026-01-11 01:47:50
// Description:
//

export module registrar : da.student;

#include <pqxx/pqxx>
import std;
import :da.databaseManager;
//import :dn.student;

export class DaStudent
{
public:
    DaStudent();
    void insertstudent(); //插入
    void deletestudent(); //删除
    void querystudent(); //查询
    void updatestudent(); //更新
};

DaStudent::DaStudent()
{
    DatabaseManager databasemanager;
}

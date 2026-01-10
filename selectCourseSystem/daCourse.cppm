// Module
// File: daCourse.cppm   Version: 0.1.0   License: AGPLv3
// Created:Luojianqiu       2026-01-11 01:48:08
// Description:
//

export module registrar : da.course;

#include <pqxx/pqxx>
import std;
import :da.databaseManager;
//import :dn.course;

export class DaCourse
{
public:
    DaCourse();
    void insertcourse(); //插入
    void deletecourse(); //删除
    void querycourse(); //查询
    void updatecourse(); //更新
};

DaCourse::DaCourse()
{
    DatabaseManager databasemanager;
}

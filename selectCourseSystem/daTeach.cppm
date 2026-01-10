// Module
// File: daTeach.cppm   Version: 0.1.0   License: AGPLv3
// Created:Luojianqiu       2026-01-11 01:48:34
// Description:
//

export module registrar : da.teach;

#include <pqxx/pqxx>
import std;
import :da.databaseManager;
//import :dn.teacher;

export class DaTeach
{
public:
    DaTeach();
    void insertteach(); //插入
    void deleteteach(); //删除
    void queryteach(); //查询
    void updateteach(); //更新
};

DaTeach::DaTeach()
{
    DatabaseManager databasemanager;
}

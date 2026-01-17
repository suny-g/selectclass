// Module
// File: DatabaseManger.cpp   Version: 0.1.0   License: AGPLv3
// Created: Luojianqiu      2026-01-10 21:47:42
// finished: tujunfeng      20226-01-15
// Description:管理数据库连接和基本操作
//
module;
#include <pqxx/pqxx>
export module registrar:da.databaseManager;
import std;

using std::print;
using std::string;
using std::exception;
using namespace pqxx;

const string DB_CONNECTION = "dbname=student_course_db user=postgres password=123456 host=localhost port=5432";

export class DatabaseManager
{
public:
        DatabaseManager(const string& connStr);

        bool isConnected() const;

        bool executeSQL(const string& sql);

        result query(const string& sql);

        void disconnect();

        ~DatabaseManager();

   private:
       //connection* conn = nullptr;
        std::unique_ptr<connection> conn;
        string connectionString;
   };

DatabaseManager::DatabaseManager(const string& connStr)
    : connectionString(connStr)
{
    try {
        conn = std::make_unique<connection>(connStr);
        if (conn->is_open()) {
            print("成功连接到 PostgreSQL 数据库\n");
            print("数据库名称: {}\n", conn->dbname());
        } else {
            print("无法连接到数据库\n");
        }
    } catch (const exception &e) {
        print("连接错误: {}\n", e.what());
    }
}
// 连接数据库
bool DatabaseManager::isConnected() const
{
    return conn && conn->is_open();
}

bool DatabaseManager::executeSQL(const string& sql)
{
    if (!isConnected()) {
        print("错误：数据库未连接\n");
        return false;
    }

    try {
        work txn(*conn);
        txn.exec(sql);
        txn.commit();
        print("SQL执行成功: ");
        // 只打印前100个字符
        if (sql.length() > 100) {
            print("{}...\n", sql.substr(0, 100));
        } else {
            print("{}\n", sql);
        }
        return true;
    } catch (const exception &e) {
        print("SQL执行错误: {}\n", e.what());
        return false;
    }
}

result DatabaseManager::query(const string& sql)
{
    if (!isConnected()) {
        print("错误：数据库未连接\n");
        return result();
    }

    try {
        work txn(*conn);
        result res = txn.exec(sql);
        txn.commit();
        print("查询成功，返回 {} 行数据\n", res.size());
        return res;
    } catch (const exception &e) {
        print("查询错误: {}\n", e.what());
        return result();
    }
}

void DatabaseManager::disconnect()
{
    if (conn) {
        conn->close();
        conn.reset();
        print("已断开数据库连接\n");
    }
}

DatabaseManager::~DatabaseManager()
{
    disconnect();
}

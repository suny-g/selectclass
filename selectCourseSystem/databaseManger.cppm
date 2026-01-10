// Module
// File: DatabaseManger.cpp   Version: 0.1.0   License: AGPLv3
// Created: Luojianqiu      2026-01-10 21:47:42
// Description:
//
export module registrar:da.databaseManager;

#include <pqxx/pqxx>
import std;

using std::print;
using std::string;
using namespace pqxx;

const string DB_CONNECTION = "dbname=student_course_db user=postgres password=123456 host=localhost port=5432";

export class DatabaseManager
{
public:
    bool connect();
    bool execteSQL(const string& sql);
    void disconnect();
    ~DatabaseManager();
};

// 连接数据库
bool DatabaseManager::connect() {
    string dbname,user,password,host,port;
    print("请输入您的dbname: ");
    std::cin >> dbname;
    print("请输入您的user: ");
    std::cin >> user;
    print("请输入您的password: ");
    std:: cin >> password;
    print("请输入您的host: ");
    std::cin >> host;
    print("请输入您的port: ");
    std::cin >> port;
    string DB_CONNECTION = std::format("{} {} {} {} {}",dbname,user,password,host,port);
    try {
        conn = new connection(DB_CONNECTION);
        if (conn->is_open()) {
            print("成功连接到 PostgreSQL 数据库\n");
            print("数据库名称: {}\n",conn->dbname);
            return true;
        } else {
            print("无法连接到数据库\n");
            return false;
        }
    } catch (const exception &e) {
        print("连接错误: {}\n"e.what);
        return false;
    }
}

bool DatabaseManager::executeSQL(const string& sql) {
    try {
        work txn(*conn);
        txn.exec(sql);
        txn.commit();
        print("SQL执行成功: ");
        std::cout << sql.substr(0, 100) << (sql.length() > 100 ? "..." : "") << std::endl;
        return true;
    } catch (const exception &e) {
        print("SQL执行错误: {}\n"e.what());
        return false;
    }
}

void DatabaseManager::disconnect() {
    if (conn) {
        conn->disconnect();
        delete conn;
        conn = nullptr;
        print("已断开数据库连接\n");
    }
}

DatabaseManager::~DatabaseManager() {
    disconnect();
}

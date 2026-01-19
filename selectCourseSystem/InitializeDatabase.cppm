// Module
// File: InitializeDatabase.cppm   Version: 0.1.0   License: AGPLv3
// Created:Luojianqiu       2026-01-11 01:28:50
// Description:数据库初始化
//
module;

#include <pqxx/pqxx>
#include <fstream>

export module registrar:da.initializeDatabase;

import :da.databaseManager;
import std;

using std::print;

export class InitializeDatabase
{
public:
    InitializeDatabase(DatabaseManager* db);
    bool createTables(); //创建表格
    bool importDataFromFiles(); //将文件中的数据读取到表格中
private:
    DatabaseManager* dbManager;
};

InitializeDatabase::InitializeDatabase(DatabaseManager* db)
    : dbManager(db) {}

bool InitializeDatabase::createTables()
{
    print("\n=== 开始创建数据表 ===\n");

    bool success = true;

    // 1. 创建学生表
    string createStudentTable =
        "CREATE TABLE IF NOT EXISTS students ("
        "student_id INTEGER PRIMARY KEY, "
        "student_name TEXT NOT NULL, "
        "total_credit REAL DEFAULT 0.0);";

    if (dbManager->executeSQL(createStudentTable)) {
        print("学生表创建成功\n");
    } else {
        print("学生表创建失败\n");
        success = false;
    }

    // 2. 创建课程表
    string createCourseTable =
        "CREATE TABLE IF NOT EXISTS courses ("
        "course_id INTEGER PRIMARY KEY, "
        "course_name TEXT NOT NULL, "
        "teacher_id INTEGER, "
        "credit REAL NOT NULL);";

    if (dbManager->executeSQL(createCourseTable)) {
        print("课程表创建成功\n");
    } else {
        print("课程表创建失败\n");
        success = false;
    }

    // 3. 创建教师表
    string createTeacherTable =
        "CREATE TABLE IF NOT EXISTS teachers ("
        "teacher_id INTEGER PRIMARY KEY, "
        "teacher_name TEXT NOT NULL);";

    if (dbManager->executeSQL(createTeacherTable)) {
        print("教师表创建成功\n");
    } else {
        print("教师表创建失败\n");
        success = false;
    }

    // 4. 创建选课表
    string createEnrollmentTable =
        "CREATE TABLE IF NOT EXISTS enrollments ("
        "student_id INTEGER, "
        "course_id INTEGER, "
        "grade REAL, "
        "PRIMARY KEY (student_id, course_id));";

    if (dbManager->executeSQL(createEnrollmentTable)) {
        print("选课表创建成功\n");
    } else {
        print("选课表创建失败\n");
        success = false;
    }

    if (success) {
        print("所有数据表创建完成\n");
    } else {
        print("数据表创建过程中出现错误\n");
    }

    return success;
}

bool InitializeDatabase::importDataFromFiles()
{
    print("\n=== 从文件导入数据 ===\n");

    if (!dbManager->isConnected()) {
        print("错误：数据库未连接\n");
        return false;
    }

    try {
        // 导入学生数据
        std::ifstream studentFile("student.dat");
        if (studentFile.is_open()) {
            string line;
            while (getline(studentFile, line)) {
                std::stringstream ss(line);
                int id;
                string name;

                if (ss >> id >> name) {
                    string sql = std::format(
                        "INSERT INTO students (student_id, student_name) "
                        "VALUES ({}, '{}');",
                        id, name
                    );
                    dbManager->executeSQL(sql);
                }
            }
            studentFile.close();
            print("学生数据导入完成\n");
        } else {
            print("警告: 无法打开 student.dat 文件\n");
        }

        // 导入教师数据
        std::ifstream teacherFile("teach.dat");
        if (teacherFile.is_open()) {
            string line;
            while (getline(teacherFile, line)) {
                std::stringstream ss(line);
                int id;
                string name;

                if (ss >> id >> name) {
                    string sql = std::format(
                        "INSERT INTO teachers (teacher_id, teacher_name) "
                        "VALUES ({}, '{}');",
                        id, name
                    );
                    dbManager->executeSQL(sql);
                }
            }
            teacherFile.close();
            print("教师数据导入完成\n");
        } else {
            print("警告: 无法打开 teach.dat 文件\n");
        }

        print("所有数据导入完成\n");
        return true;

    } catch (const std::exception &e) {
        print("数据导入错误: {}\n", e.what());
        return false;
    }
}

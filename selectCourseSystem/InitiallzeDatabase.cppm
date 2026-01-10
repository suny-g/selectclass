// Module
// File: InitiallzeDatabase.cppm   Version: 0.1.0   License: AGPLv3
// Created:Luojianqiu       2026-01-11 01:28:50
// Description:
//

export module registrar:da.initiallezDatabase;

#include <pqxx/pqxx>
#include <fstream>

import :da.databaseManager;
import std;

using std::print;

export class InitiallezDatabase
{
public:
    void createTables(class SimpleDatabaseManager& db); //创建表格
    void importDataFromFiles(class SimpleDatabaseManager& db); //将文件中的数据读取到表格中
};

void InitiallezDatabase::createTables(class SimpleDatabaseManager& db) {
    print("\n=== 开始创建数据表 ===");

    // 1. 创建课程表
    string createCourseTable =
        "CREATE TABLE IF NOT EXISTS courses ("
        "course_id INTEGER PRIMARY KEY, "
        "course_name TEXT NOT NULL, "
        "teacher TEXT NOT NULL, "
        "credit REAL NOT NULL);";

    if (db.executeSQL(createCourseTable)) {
        print("课程表创建成功!");
    }

    // 2. 创建学生表
    string createStudentTable =
        "CREATE TABLE IF NOT EXISTS students ("
        "student_id INTEGER PRIMARY KEY, "
        "student_name TEXT NOT NULL);";

    if (db.executeSQL(createStudentTable)) {
        print("学生表创建成功!");
    }

    // 3. 创建教师表
    string createTeacherTable =
        "CREATE TABLE IF NOT EXISTS teachers ("
        "teacher_id INTEGER PRIMARY KEY, "
        "teacher_name TEXT NOT NULL);";

    if (db.executeSQL(createTeacherTable)) {
        print("教师表创建成功!");
    }

    print("=== 所有数据表创建完成 ===");
}

void InitiallezDatabase::importDataFromFiles(class SimpleDatabaseManager& db) {
    print("\n=== 从文件导入数据 ===\n");

    try {
        work txn(*db.getConnection()); // 注意：这里需要修改访问权限

        // 导入课程数据
        ifstream courseFile("course.dat");
        if (courseFile.is_open()) {
            string line;
            while (getline(courseFile, line)) {
                int id;
                string name, teacher;
                double credit;

                stringstream ss(line);
                ss >> id >> name >> teacher >> credit;

                // 使用参数化查询插入数据
                string sql = "INSERT INTO courses (course_id, course_name, teacher, credit) "
                           "VALUES (" + to_string(id) + ", '" + name + "', '" + teacher + "', " + to_string(credit) + ");";

                txn.exec(sql);
            }
            courseFile.close();
            print("课程数据导入完成\n");
        } else {
            print("警告: 无法打开 course.dat 文件\n");
        }

        // 导入学生数据
        ifstream studentFile("student.dat");
        if (studentFile.is_open()) {
            string line;
            while (getline(studentFile, line)) {
                int id;
                string name;

                stringstream ss(line);
                ss >> id >> name;

                string sql = "INSERT INTO students (student_id, student_name) "
                           "VALUES (" + to_string(id) + ", '" + name + "');";

                txn.exec(sql);
            }
            studentFile.close();
            print("学生数据导入完成\n");
        } else {
            print("警告: 无法打开 student.dat 文件\n");
        }

        // 导入教师数据
        ifstream teacherFile("teach.dat");
        if (teacherFile.is_open()) {
            string line;
            while (getline(teacherFile, line)) {
                int id;
                string name;

                stringstream ss(line);
                ss >> id >> name;

                string sql = "INSERT INTO teachers (teacher_id, teacher_name) "
                           "VALUES (" + to_string(id) + ", '" + name + "');";

                txn.exec(sql);
            }
            teacherFile.close();
            print("教师数据导入完成\n");
        } else {
            print("警告: 无法打开 teach.dat 文件\n");
        }

        txn.commit();
        print("所有数据导入完成!\n");

    } catch (const exception &e) {
        print("数据导入错误: {}\n",e.what());
    }
}

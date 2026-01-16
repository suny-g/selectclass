// Module
// File: daStudent.cppm   Version: 0.1.0   License: AGPLv3
// Created:Luojianqiu       2026-01-11 01:47:50
// Description:学生数据访问对象
//

export module registrar : da.student;

#include <pqxx/pqxx>
import std;
import :da.databaseManager;
//import :dn.student;

export class DaStudent
{
public:
    DaStudent(DatabaseManager* db);

    // 插入学生
    bool insertStudent(int studentId, const string& name);

    // 删除学生
    bool deleteStudent(int studentId);

    // 查询学生
    result queryStudent(int studentId);

    // 更新学生信息
    bool updateStudent(int studentId, const string& newName);

    // 查询所有学生
    result queryAllStudents();

    // 学生选课
    bool enrollCourse(int studentId, int courseId);

    // 学生退课
    bool dropCourse(int studentId, int courseId);

private:
    DatabaseManager* dbManager;
};


DaStudent::DaStudent(DatabaseManager* db)
    : dbManager(db) {}

bool DaStudent::insertStudent(int studentId, const string& name)
{
    string sql = std::format(
        "INSERT INTO students (student_id, student_name) VALUES ({}, '{}');",
        studentId, name
    );
    return dbManager->executeSQL(sql);
}

bool DaStudent::deleteStudent(int studentId)
{
    string sql = std::format(
        "DELETE FROM students WHERE student_id = {};",
        studentId
    );
    return dbManager->executeSQL(sql);
}

result DaStudent::queryStudent(int studentId)
{
    string sql = std::format(
        "SELECT * FROM students WHERE student_id = {};",
        studentId
    );
    return dbManager->query(sql);
}

bool DaStudent::updateStudent(int studentId, const string& newName)
{
    string sql = std::format(
        "UPDATE students SET student_name = '{}' WHERE student_id = {};",
        newName, studentId
    );
    return dbManager->executeSQL(sql);
}

result DaStudent::queryAllStudents()
{
    string sql = "SELECT * FROM students ORDER BY student_id;";
    return dbManager->query(sql);
}

bool DaStudent::enrollCourse(int studentId, int courseId)
{
    string sql = std::format(
        "INSERT INTO enrollments (student_id, course_id) VALUES ({}, {});",
        studentId, courseId
    );
    return dbManager->executeSQL(sql);
}

bool DaStudent::dropCourse(int studentId, int courseId)
{
    string sql = std::format(
        "DELETE FROM enrollments WHERE student_id = {} AND course_id = {};",
        studentId, courseId
    );
    return dbManager->executeSQL(sql);
}

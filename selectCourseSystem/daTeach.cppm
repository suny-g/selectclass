// Module
// File: daTeach.cppm   Version: 0.1.0   License: AGPLv3
// Created:Luojianqiu       2026-01-11 01:48:34
// Description:
//
module;

#include <pqxx/pqxx>

export module registrar : da.teach;

import std;
import :da.databaseManager;
//import :dn.teacher;

using std::format;

export class DaTeacher
{
public:
    DaTeacher(DatabaseManager* db);

    // 插入教师
    bool insertTeacher(int teacherId, const string& name);

    // 删除教师
    bool deleteTeacher(int teacherId);

    // 查询教师
    result queryTeacher(int teacherId);

    // 更新教师信息
    bool updateTeacher(int teacherId, const string& newName);

    // 查询所有教师
    result queryAllTeachers();

    // 教师授课（关联课程）
    bool assignCourse(int teacherId, int courseId);

    // 取消教师授课
    bool unassignCourse(int teacherId, int courseId);

    // 查询教师的课程
    result queryTeacherCourses(int teacherId);

    // 查询教师的学生（通过课程）
    result queryTeacherStudents(int teacherId);

private:
    DatabaseManager* dbManager;
};

DaTeacher::DaTeacher(DatabaseManager* db)
    : dbManager(db) {}

bool DaTeacher::insertTeacher(int teacherId, const string& name)
{
    string sql = std::format(
        "INSERT INTO teachers (teacher_id, teacher_name) VALUES ({}, '{}');",
        teacherId, name
    );
    return dbManager->executeSQL(sql);
}

bool DaTeacher::deleteTeacher(int teacherId)
{
    string sql = std::format(
        "DELETE FROM teachers WHERE teacher_id = {};",
        teacherId
    );
    return dbManager->executeSQL(sql);
}

result DaTeacher::queryTeacher(int teacherId)
{
    string sql = std::format(
        "SELECT * FROM teachers WHERE teacher_id = {};",
        teacherId
    );
    return dbManager->query(sql);
}

bool DaTeacher::updateTeacher(int teacherId, const string& newName)
{
    string sql = std::format(
        "UPDATE teachers SET teacher_name = '{}' WHERE teacher_id = {};",
        newName, teacherId
    );
    return dbManager->executeSQL(sql);
}

result DaTeacher::queryAllTeachers()
{
    string sql = "SELECT * FROM teachers ORDER BY teacher_id;";
    return dbManager->query(sql);
}

bool DaTeacher::assignCourse(int teacherId, int courseId)
{
    // 先检查课程是否存在
    string checkCourse = std::format(
        "SELECT * FROM courses WHERE course_id = {};",
        courseId
    );
    result courseResult = dbManager->query(checkCourse);

    if (courseResult.empty()) {
        print("错误：课程ID {} 不存在\n", courseId);
        return false;
    }

    // 检查是否已分配
    string checkAssign = std::format(
        "SELECT * FROM courses WHERE course_id = {} AND teacher_id IS NOT NULL;",
        courseId
    );
    result assignResult = dbManager->query(checkAssign);

    if (!assignResult.empty()) {
        print("错误：课程 {} 已有教师\n", courseId);
        return false;
    }

    // 分配课程
    string sql = std::format(
        "UPDATE courses SET teacher_id = {} WHERE course_id = {};",
        teacherId, courseId
    );
    return dbManager->executeSQL(sql);
}

bool DaTeacher::unassignCourse(int teacherId, int courseId)
{
    string sql = std::format(
        "UPDATE courses SET teacher_id = NULL WHERE course_id = {} AND teacher_id = {};",
        courseId, teacherId
    );
    return dbManager->executeSQL(sql);
}

result DaTeacher::queryTeacherCourses(int teacherId)
{
    string sql = std::format(
        "SELECT * FROM courses WHERE teacher_id = {} ORDER BY course_id;",
        teacherId
    );
    return dbManager->query(sql);
}

result DaTeacher::queryTeacherStudents(int teacherId)
{
    string sql = std::format(
        "SELECT DISTINCT s.student_id, s.student_name "
        "FROM students s "
        "JOIN enrollments e ON s.student_id = e.student_id "
        "JOIN courses c ON e.course_id = c.course_id "
        "WHERE c.teacher_id = {} "
        "ORDER BY s.student_id;",
        teacherId
    );
    return dbManager->query(sql);
}

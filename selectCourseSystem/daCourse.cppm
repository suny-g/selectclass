// Module
// File: daCourse.cppm   Version: 0.1.0   License: AGPLv3
// Created:Luojianqiu       2026-01-11 01:48:08
// Description:课程数据访问对象
//
module;

#include <pqxx/pqxx>

export module registrar : da.course;

import std;
import :da.databaseManager;
//import :dn.course;

using std::format;
using std::string;
using namespace pqxx;

export class DaCourse
{
public:
    DaCourse(DatabaseManager* db);

    // 插入课程
    bool insertCourse(int courseId, const string& name, double credit);

    // 删除课程
    bool deleteCourse(int courseId);

    // 查询课程
    result queryCourse(int courseId);

    // 更新课程信息
    bool updateCourse(int courseId, const string& newName, double newCredit);

    // 查询所有课程
    result queryAllCourses();

    // 分配教师给课程
    bool assignTeacher(int courseId, int teacherId);

    // 查询课程的学生
    result queryCourseStudents(int courseId);

    // 更新课程成绩
    bool updateCourseGrade(int studentId, int courseId, double grade);

private:
    DatabaseManager* dbManager;
};


DaCourse::DaCourse(DatabaseManager* db)
    : dbManager(db) {}

bool DaCourse::insertCourse(int courseId, const string& name, double credit)
{
    string sql = std::format(
        "INSERT INTO courses (course_id, course_name, credit) "
        "VALUES ({}, '{}', {});",
        courseId, name, credit
    );
    return dbManager->executeSQL(sql);
}

bool DaCourse::deleteCourse(int courseId)
{
    string sql = std::format(
        "DELETE FROM courses WHERE course_id = {};",
        courseId
    );
    return dbManager->executeSQL(sql);
}

result DaCourse::queryCourse(int courseId)
{
    string sql = std::format(
        "SELECT * FROM courses WHERE course_id = {};",
        courseId
    );
    return dbManager->query(sql);
}

bool DaCourse::updateCourse(int courseId, const string& newName, double newCredit)
{
    string sql = std::format(
        "UPDATE courses SET course_name = '{}', credit = {} WHERE course_id = {};",
        newName, newCredit, courseId
    );
    return dbManager->executeSQL(sql);
}

result DaCourse::queryAllCourses()
{
    string sql = "SELECT * FROM courses ORDER BY course_id;";
    return dbManager->query(sql);
}

bool DaCourse::assignTeacher(int courseId, int teacherId)
{
    string sql = std::format(
        "UPDATE courses SET teacher_id = {} WHERE course_id = {};",
        teacherId, courseId
    );
    return dbManager->executeSQL(sql);
}

result DaCourse::queryCourseStudents(int courseId)
{
    string sql = std::format(
        "SELECT s.* FROM students s "
        "JOIN enrollments e ON s.student_id = e.student_id "
        "WHERE e.course_id = {};",
        courseId
    );
    return dbManager->query(sql);
}

bool DaCourse::updateCourseGrade(int studentId, int courseId, double grade)
{
    string sql = std::format(
        "UPDATE enrollments SET grade = {} WHERE student_id = {} AND course_id = {};",
        grade, studentId, courseId
    );
    return dbManager->executeSQL(sql);
}

// File: daEnrollment.cppm   Version: 0.1.0   License: AGPLv3
// Created: tujunfeng        2026-01-17
// Description: 选课数据访问对象
module;

#include <pqxx/pqxx>

export module registrar:da.enrollment;

import std;
import :da.databaseManager;

using std::format;

export class DaEnrollment
{
public:
    DaEnrollment(DatabaseManager* db);

    // 插入选课记录
    bool insertEnrollment(int studentId, int courseId, double grade = 0.0);

    // 删除选课记录
    bool deleteEnrollment(int studentId, int courseId);

    // 更新成绩
    bool updateGrade(int studentId, int courseId, double grade);

    // 查询学生所有选课
    result queryStudentEnrollments(int studentId);

    // 查询课程所有选课学生
    result queryCourseEnrollments(int courseId);

    // 查询成绩
    result queryGrade(int studentId, int courseId);

    // 查询学生平均成绩
    result queryStudentAverageGrade(int studentId);

    // 查询课程统计
    result queryCourseStatistics(int courseId);

private:
    DatabaseManager* dbManager;
};

DaEnrollment::DaEnrollment(DatabaseManager* db)
    : dbManager(db) {}

bool DaEnrollment::insertEnrollment(int studentId, int courseId, double grade)
{
    string sql = std::format(
        "INSERT INTO enrollments (student_id, course_id, grade) "
        "VALUES ({}, {}, {});",
        studentId, courseId, grade
    );
    return dbManager->executeSQL(sql);
}

bool DaEnrollment::deleteEnrollment(int studentId, int courseId)
{
    string sql = std::format(
        "DELETE FROM enrollments WHERE student_id = {} AND course_id = {};",
        studentId, courseId
    );
    return dbManager->executeSQL(sql);
}

bool DaEnrollment::updateGrade(int studentId, int courseId, double grade)
{
    string sql = std::format(
        "UPDATE enrollments SET grade = {} WHERE student_id = {} AND course_id = {};",
        grade, studentId, courseId
    );
    return dbManager->executeSQL(sql);
}

result DaEnrollment::queryStudentEnrollments(int studentId)
{
    string sql = std::format(
        "SELECT e.*, c.course_name, c.credit FROM enrollments e "
        "JOIN courses c ON e.course_id = c.course_id "
        "WHERE e.student_id = {} ORDER BY e.course_id;",
        studentId
    );
    return dbManager->query(sql);
}

result DaEnrollment::queryCourseEnrollments(int courseId)
{
    string sql = std::format(
        "SELECT e.*, s.student_name FROM enrollments e "
        "JOIN students s ON e.student_id = s.student_id "
        "WHERE e.course_id = {} ORDER BY e.student_id;",
        courseId
    );
    return dbManager->query(sql);
}

result DaEnrollment::queryGrade(int studentId, int courseId)
{
    string sql = std::format(
        "SELECT * FROM enrollments WHERE student_id = {} AND course_id = {};",
        studentId, courseId
    );
    return dbManager->query(sql);
}

result DaEnrollment::queryStudentAverageGrade(int studentId)
{
    string sql = std::format(
        "SELECT AVG(grade) as avg_grade FROM enrollments WHERE student_id = {} AND grade > 0;",
        studentId
    );
    return dbManager->query(sql);
}

result DaEnrollment::queryCourseStatistics(int courseId)
{
    string sql = std::format(
        "SELECT "
        "COUNT(*) as total_students, "
        "AVG(grade) as avg_grade, "
        "MAX(grade) as max_grade, "
        "MIN(grade) as min_grade "
        "FROM enrollments WHERE course_id = {};",
        courseId
    );
    return dbManager->query(sql);
}

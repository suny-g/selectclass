// Module
// File: academicsecretarycontroller.cppm.cpp Version: 1.0 License: AGPLv3
// Created: Luojianqiu
// Email: 2024051604059@qq.com
// 2026-01-05 15:34:48
// Time: Description:
//
// Change log
// [v1.1] Luojianqiu 2024051604059@qq.com 2026-01-05 15:34:48
// *此模块为数字秘书的控制器
export module registrar : ctr.academicsecretarycontroller;

import std;
import :dn.academicsecretary;

export class AademicSecretaryController
{
public:
    void menu(); //显示菜单
    void addTeacherTAC(class AcademicSecretary *academicsecretary); //管理教师的授课
    void cancelTeacherTAC(class AcademicSecretary *academicsecretary); //删除教师的授课
    void courseInquiry(class AcademicSecretary *academicsecretary); //课程查询
    void addCourse(class AcademicSecretary *academicsecretary); //添加课程
    void cancelCourse(class AcademicSecretary *academicsecretary); //删除课程
};

// 实现代码
void AademicSecretaryController::menu()
{
    print("\n=== 教学秘书管理系统 ===\n");
    print("1. 添加教师授课\n");
    print("2. 取消教师授课\n");
    print("3. 课程查询\n");
    print("4. 添加课程\n");
    print("5. 删除课程\n");
    print("0. 返回上级菜单\n");
}

void AademicSecretaryController::addTeacherTAC(class AcademicSecretary *academicsecretary)
{
    if (!academicsecretary) {
        print("错误：教学秘书对象为空！\n");
        return;
    }

    print("=== 添加教师授课 ===\n");
    print("请输入教师ID：");
    int tid;
    std::cin >> tid;

    print("请输入课程ID：");
    int cid;
    std::cin >> cid;

    academicsecretary->addTeacherTAC(tid, cid);
    print("教师授课添加成功！\n");
}

void AademicSecretaryController::cancelTeacherTAC(class AcademicSecretary *academicsecretary)
{
    if (!academicsecretary) {
        print("错误：教学秘书对象为空！\n");
        return;
    }

    print("=== 取消教师授课 ===\n");
    print("请输入教师ID：");
    int tid;
    std::cin >> tid;

    print("请输入课程ID：");
    int cid;
    std::cin >> cid;

    academicsecretary->cancelTeacherTAC(tid, cid);
    print("教师授课已取消！\n");
}

void AademicSecretaryController::courseInquiry(class AcademicSecretary *academicsecretary)
{
    if (!academicsecretary) {
        print("错误：教学秘书对象为空！\n");
        return;
    }

    print("=== 课程查询 ===\n");
    academicsecretary->courseInquiry();
}

void AademicSecretaryController::addCourse(class AcademicSecretary *academicsecretary)
{
    if (!academicsecretary) {
        print("错误：教学秘书对象为空！\n");
        return;
    }

    print("=== 添加课程 ===\n");
    print("请输入课程ID：");
    int cid;
    std::cin >> cid;

    academicsecretary->addCourse(cid);
    print("课程添加成功！\n");
}

void AademicSecretaryController::cancelCourse(class AcademicSecretary *academicsecretary)
{
    if (!academicsecretary) {
        print("错误：教学秘书对象为空！\n");
        return;
    }

    print("=== 删除课程 ===\n");
    print("请输入课程ID：");
    int cid;
    std::cin >> cid;

    academicsecretary->cancelCourse(cid);
    print("课程删除成功！\n");
}

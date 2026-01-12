//
//File: database_initializer.cppm
//Created:Yang Gaung        2026-01-12
//Version: 1.0      License: AGPLv3

export module database_initializer;

import database_manager;

export class InitializeDatabase {
public:
    static bool createTables(DataBaseManager& db) {
        // 创建所有表
        return true;
    }

    static bool importDataFromFile(DataBaseManager& db) {
        // 从文件导入数据
        return true;
    }
};

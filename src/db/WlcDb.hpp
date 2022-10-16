//
// Created by ender on 22-10-15.
//

#ifndef WLC_BACKEND_WLCDB_HPP
#define WLC_BACKEND_WLCDB_HPP
#include "oatpp-postgresql/orm.hpp"
#include OATPP_CODEGEN_BEGIN(DbClient)
using namespace oatpp;
class WlcDb : public oatpp::orm::DbClient{
public:
    explicit WlcDb(const std::shared_ptr<oatpp::orm::Executor> &executor)
            : oatpp::orm::DbClient(executor) {

        oatpp::orm::SchemaMigration migration(executor);
        migration.addFile(1, DATABASE_MIGRATIONS "/public/wlc_submits.sql");
        migration.addFile(2, DATABASE_MIGRATIONS "/public/wlc_tasks.sql");
        migration.addFile(3, DATABASE_MIGRATIONS "/public/wlc_users.sql");
        migration.migrate(); // <-- run migrations. This guy will throw on error.

        auto version = executor->getSchemaVersion();
        OATPP_LOGD("WlcDb", "Migration - OK. Version=%d.", version);
    }
    QUERY(getUserById, "SELECT * FROM wlc_users WHERE id = :id",
          PREPARE(true),
          PARAM(Int32, id))

    QUERY(insertSubmit, "INSERT INTO wlc_submits (type, user_id, create_time, content, task_id) VALUES (type, user_id, create_time, content, task_id) returning id",
          PREPARE(true),
          PARAM(String, type),
          PARAM(Int32, user_id),
          PARAM(Int64, create_time),
          PARAM(String, content),
          PARAM(Int32, task_id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif //WLC_BACKEND_WLCDB_HPP

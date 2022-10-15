//
// Created by ender on 22-10-15.
//

#ifndef WLC_BACKEND_WLCDB_HPP
#define WLC_BACKEND_WLCDB_HPP
#include "oatpp-postgresql/orm.hpp"

class WlcDb : public oatpp::orm::DbClient{
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
};


#endif //WLC_BACKEND_WLCDB_HPP

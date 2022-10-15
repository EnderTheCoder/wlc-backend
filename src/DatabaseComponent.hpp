
//
// Created by ender on 22-10-15.
//

#ifndef WLC_DATABASECOMPONENT_HPP
#define WLC_DATABASECOMPONENT_HPP

#include "db/WlcDb.hpp"

class DatabaseComponent {
    OATPP_CREATE_COMPONENT(std::shared_ptr<WlcDb>, db)([] {

        OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

        /* Create database-specific ConnectionProvider */
        auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->db);

        /* Create database-specific ConnectionPool */
        auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                              10000 /* max-connections */,
                                                                              std::chrono::seconds(60) /* connection TTL */);

        /* Create database-specific Executor */
        auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

        /* Create MyClient database client */
        return std::make_shared<WlcDb>(executor);

    }());
};
#endif //WLC_DATABASECOMPONENT_HPP

//
// Created by ender on 22-10-16.
//

#ifndef WLC_BACKEND_BASECLASS_HPP
#define WLC_BACKEND_BASECLASS_HPP

#include <oatpp/core/Types.hpp>
#include <oatpp/web/protocol/http/Http.hpp>
#include "db/WlcDb.hpp"
#include "oatpp/core/macro/component.hpp"
#include "util/time/Time.hpp"
namespace wlc::service {
        class BaseClass {
        public:
            typedef oatpp::web::protocol::http::Status Status;
            OATPP_COMPONENT(std::shared_ptr<WlcDb>, db);
        };
    } // service

#endif //WLC_BACKEND_BASECLASS_HPP

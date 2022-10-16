//
// Created by ender on 22-10-15.
//

#ifndef WLC_BACKEND_ADMINCONTROLLER_HPP
#define WLC_BACKEND_ADMINCONTROLLER_HPP


#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/component.hpp>
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "ErrorHandler.hpp"
#include "../service/AdminService.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AdminController {
private:

    explicit AdminController(OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) {
        this->setErrorHandler(std::make_shared<ErrorHandler>(objectMapper));
    }
    wlc::service::AdminService admin_service;
public:
    static std::shared_ptr<AdminController> createShared(OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper)) {
        return std::shared_ptr<AdminController>(new AdminController(objectMapper));
    }
public:

};
#include OATPP_CODEGEN_END(ApiController)

#endif //WLC_BACKEND_ADMINCONTROLLER_HPP


#ifndef EXAMPLE_POSTGRESQL_ERRORHANDLER_HPP
#define EXAMPLE_POSTGRESQL_ERRORHANDLER_HPP

#include "dto/response/StatusDto.hpp"

#include "oatpp/web/server/handler/ErrorHandler.hpp"
#include "oatpp/web/protocol/http/outgoing/ResponseFactory.hpp"

class ErrorHandler : public oatpp::web::server::handler::ErrorHandler {
private:
    typedef oatpp::web::protocol::http::outgoing::Response OutgoingResponse;
    typedef oatpp::web::protocol::http::Status Status;
    typedef oatpp::web::protocol::http::outgoing::ResponseFactory ResponseFactory;
private:
    std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_objectMapper;
public:

    explicit ErrorHandler(std::shared_ptr<oatpp::data::mapping::ObjectMapper> objectMapper)
            : m_objectMapper(std::move(objectMapper)) {}

    std::shared_ptr<OutgoingResponse>
    handleError(const Status &status, const oatpp::String &message, const Headers &headers) override {

        auto error = StatusDto::createShared();
        error->status = "ERROR";
        error->code = status.code;
        error->message = message;
        auto response = ResponseFactory::createResponse(status, error, m_objectMapper);
        for (const auto &pair: headers.getAll()) {
            response->putHeader(pair.first.toString(), pair.second.toString());
        }
        auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        auto json_string = jsonObjectMapper->writeToString(error);

        OATPP_LOGE("HTTP-ERROR-" + std::to_string(error->code), ("MESSAGE:" + error->message + "JSON:" + json_string)->c_str())
        return response;

    }

};


#endif //EXAMPLE_POSTGRESQL_ERRORHANDLER_HPP

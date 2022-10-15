//
// Created by ender on 22-8-25.
//

#ifndef VERIFY_SERVER_CONFIGDTO_HPP
#define VERIFY_SERVER_CONFIGDTO_HPP
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
class ConfigDto : public oatpp::DTO{
    DTO_INIT(ConfigDto, DTO)
    //主机
    DTO_FIELD(String, host);
    //端口
    DTO_FIELD(UInt16, port);
    //链接字符串
    DTO_FIELD(String, db);
    //微信的appid
    DTO_FIELD(String, appid);
    //微信的密钥
    DTO_FIELD(String, secret);
};

#include OATPP_CODEGEN_END(DTO)
#endif

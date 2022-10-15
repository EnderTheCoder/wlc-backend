#ifndef VX_DELIVERY_CPP_COMMONNODATADTO_HPP_HPP
#define VX_DELIVERY_CPP_COMMONNODATADTO_HPP_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

class CommonNoDataResponseDto : public oatpp::DTO {
    DTO_INIT(CommonNoDataResponseDto, DTO)

    DTO_FIELD(oatpp::Int16, code);

    DTO_FIELD_INFO(code) {
        info->description = "状态码,100代表成功";
    }
    DTO_FIELD(oatpp::String, message);

    DTO_FIELD_INFO(message) {
        info->description = "返回值描述信息";
    }
};

#include OATPP_CODEGEN_END(DTO)

#endif //VX_DELIVERY_CPP_COMMONNODATADTO_HPP_HPP
#ifndef VX_DELIVERY_CPP_COMMONSIMPLEDATADTO_HPP_HPP
#define VX_DELIVERY_CPP_COMMONSIMPLEDATADTO_HPP_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)
template<typename T>
class CommonSimpleDataResponseDto : public oatpp::DTO {
    DTO_INIT(CommonSimpleDataResponseDto, DTO)

    DTO_FIELD(oatpp::Int16, code);

    DTO_FIELD(oatpp::String, message);

    DTO_FIELD(oatpp::Object<T>, data);
};

#include OATPP_CODEGEN_END(DTO)

#endif //VX_DELIVERY_CPP_COMMONSIMPLEDATADTO_HPP_HPP
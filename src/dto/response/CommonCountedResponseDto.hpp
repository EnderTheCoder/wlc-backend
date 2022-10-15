#ifndef VX_DELIVERY_CPP_COMMONSEARCHRESULTDTO_HPP_HPP
#define VX_DELIVERY_CPP_COMMONSEARCHRESULTDTO_HPP_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)
template<typename T>
class CommonCountedResponseDto : public oatpp::DTO {
    DTO_INIT(CommonCountedResponseDto, DTO)
    DTO_FIELD(oatpp::Int16, code);

    DTO_FIELD(oatpp::String, message);

    DTO_FIELD(oatpp::Vector<oatpp::Object<T>>, data);

    DTO_FIELD(oatpp::Int64, data_count);
};

#include OATPP_CODEGEN_END(DTO)

#endif //VX_DELIVERY_CPP_COMMONSEARCHRESULTDTO_HPP_HPP
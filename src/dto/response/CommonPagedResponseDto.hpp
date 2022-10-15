#ifndef VX_DELIVERY_CPP_COMMONPAGEDRESPONSEDTO_HPP_HPP
#define VX_DELIVERY_CPP_COMMONPAGEDRESPONSEDTO_HPP_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

template<typename T>
class CommonPagedResponseDto : public oatpp::DTO {
    DTO_INIT(CommonPagedResponseDto, DTO)

    DTO_FIELD(oatpp::Int16, code);

    DTO_FIELD(oatpp::String, message);

    DTO_FIELD(oatpp::Vector<oatpp::Object<T>>, data);

    DTO_FIELD(oatpp::Int32, page_num);

    DTO_FIELD(oatpp::Int32, page_size);

    DTO_FIELD(oatpp::UInt64, page_total);
};

#include OATPP_CODEGEN_END(DTO)

#endif //VX_DELIVERY_CPP_COMMONPAGEDRESPONSEDTO_HPP_HPP
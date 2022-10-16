#ifndef VX_DELIVERY_CPP_ID32DTO_HPP
#define VX_DELIVERY_CPP_ID32DTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

class Id32Dto : public oatpp::DTO {
    DTO_INIT(Id32Dto, DTO)

    DTO_FIELD(Int32, id);
};

#include OATPP_CODEGEN_END(DTO)

#endif //VX_DELIVERY_CPP_ID32DTO_HPP
#ifndef VX_DELIVERY_CPP_ID64DTO_HPP
#define VX_DELIVERY_CPP_ID64DTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

class Id64Dto : public oatpp::DTO {
    DTO_INIT(Id64Dto, DTO)
    DTO_FIELD(Int64, id);
};

#include OATPP_CODEGEN_END(DTO)

#endif //VX_DELIVERY_CPP_ID64DTO_HPP
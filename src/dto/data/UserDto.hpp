#ifndef WLC_BACKEND_USERDTO_HPP
#define WLC_BACKEND_USERDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

class UserDto : public oatpp::DTO {
    DTO_INIT(UserDto, DTO)

    DTO_FIELD(Int32, id);

    DTO_FIELD(String, name);

    DTO_FIELD(Int32, level);

    DTO_FIELD(Int32, student_id);

    DTO_FIELD(String, password);
};

#include OATPP_CODEGEN_END(DTO)

#endif //WLC_BACKEND_USERDTO_HPP
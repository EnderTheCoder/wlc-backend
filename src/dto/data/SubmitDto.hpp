#ifndef WLC_BACKEND_SUBMITDTO_HPP
#define WLC_BACKEND_SUBMITDTO_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

class SubmitDto : public oatpp::DTO {
    DTO_INIT(SubmitDto, DTO)

    DTO_FIELD(Int32, id);

    DTO_FIELD(String, type);

    DTO_FIELD(Int32, user_id);

    DTO_FIELD(Int64, create_time);

    DTO_FIELD(String, content);

    DTO_FIELD(Int32, task_id);
};

#include OATPP_CODEGEN_END(DTO)

#endif //WLC_BACKEND_SUBMITDTO_HPP
//
// Created by ender on 22-10-16.
//

#ifndef WLC_BACKEND_SUBMIT_HPP
#define WLC_BACKEND_SUBMIT_HPP

#include <oatpp/core/Types.hpp>
#include "dto/data/SubmitDto.hpp"
#include "util/time/Time.hpp"
#include "BaseClass.hpp"
#include "dto/data/Id32Dto.hpp"

namespace wlc::service {
    class Submit : BaseClass{
    private:
        oatpp::Object<SubmitDto> submit;

    public:
        Submit() = default;

        explicit Submit(const oatpp::Object<SubmitDto> &submit) {
            this->submit = submit;
        }

        static std::shared_ptr<Submit> createShared() {
            return std::make_shared<Submit>();
        }

        static std::shared_ptr<Submit> createShared(const oatpp::Object<SubmitDto> &submit) {
            return std::make_shared<Submit>(Submit(submit));
        }

        static std::shared_ptr<Submit> createShared(const oatpp::String &type, const oatpp::Int32 &user_id, const oatpp::Int32 &task_id, const oatpp::String &content) {
            auto dto = SubmitDto::createShared();
            dto->create_time = util::time::Time::getCurrentTimestampInLong();
            dto->type = type;
            dto->user_id = user_id;
            dto->content = content;
            dto->task_id = task_id;
            return createShared(dto);
        }

        void write() {
            auto db_result = db->insertSubmit(this->submit->type, this->submit->user_id, this->submit->create_time, this->submit->content, this->submit->task_id);
            OATPP_ASSERT_HTTP(db_result->isSuccess(), Status::CODE_500, db_result->getErrorMessage())
            auto id_vector = db_result->fetch<oatpp::Vector<oatpp::Object<Id32Dto>>>();
            OATPP_ASSERT_HTTP(!id_vector->empty(), Status::CODE_500, "插入提交记录失败")
            this->submit->id = id_vector->at(0)->id;
        }

        oatpp::Object<SubmitDto> getDto() {
            return this->submit;
        }

    };

}

#endif //WLC_BACKEND_SUBMIT_HPP

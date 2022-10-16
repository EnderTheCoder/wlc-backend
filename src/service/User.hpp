//
// Created by ender on 22-10-16.
//

#ifndef WLC_BACKEND_USER_HPP
#define WLC_BACKEND_USER_HPP


#include <oatpp/web/protocol/http/Http.hpp>
#include <openssl/md5.h>
#include "dto/data/UserDto.hpp"
#include "db/WlcDb.hpp"
#include "oatpp/core/macro/component.hpp"
#include "util/time/Time.hpp"
namespace wlc::service {
    class User {
    private:
        oatpp::Object<UserDto> user;
        typedef oatpp::web::protocol::http::Status Status;
        OATPP_COMPONENT(std::shared_ptr<WlcDb>, db);
    public:
        User() = default;

        explicit User(const oatpp::Object<UserDto> &user) {
            this->user = user;
        }

        static std::shared_ptr<User> createShared() {
            return std::make_shared<User>();
        }

        static std::shared_ptr<User> createShared(const oatpp::Object<UserDto> &user) {
            return std::make_shared<User>(User(user));
        }

        oatpp::Boolean getByToken(const oatpp::String &token_val) {
            auto id = token->getByToken(token_val);
            if (id == nullptr) return false;
            return getById(id);
        }

        oatpp::Boolean getById(const oatpp::Int32 &id) {
            auto db_result = db->getUserById(id);
            OATPP_ASSERT_HTTP(db_result->isSuccess(), Status::CODE_500, db_result->getErrorMessage())
            auto user_vector = db_result->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
            if (user_vector->empty()) {
                return false;
            } else {
                this->user = user_vector->at(1);
                return true;
            }
        }

        oatpp::Object<UserDto> getDto() {
            return this->user;
        }

        class Token {
        private:
            std::unordered_map<oatpp::String, oatpp::Int32> token;
        private:
            static oatpp::String makeToken(const std::string& src) {
                MD5_CTX ctx;

                std::string md5_string;
                unsigned char md[16] = {0};
                char tmp[33] = {0};

                MD5_Init(&ctx);
                MD5_Update(&ctx, src.c_str(), src.size());
                MD5_Final(md, &ctx);

                for (int i = 0; i < 16; ++i) {
                    memset(tmp, 0x00, sizeof(tmp));
                    sprintf(tmp, "%02X", md[i]);
                    md5_string += tmp;
                }
                return md5_string;

            }

        public:
            oatpp::Int32 getByToken(const oatpp::String &token_val) {
                auto element = this->token.find(token_val);
                return element == token.end() ? nullptr : element->second;
            }

            static std::shared_ptr<Token> createShared() {
                return std::make_shared<Token>();
            }

            void put(const oatpp::Int32 &id) {
                this->token.insert(std::make_pair(makeToken(std::to_string(id + util::time::Time::getCurrentTimestampInLong() + 233)), id));
            }

        };

    private:
        OATPP_COMPONENT(std::shared_ptr<Token>, token);

    };
}

#endif //WLC_BACKEND_USER_HPP

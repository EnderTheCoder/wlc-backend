//
// Created by ender on 22-10-16.
//

#ifndef WLC_BACKEND_USER_HPP
#define WLC_BACKEND_USER_HPP


#include "dto/data/UserDto.hpp"

namespace wlc::service {
    class User {
    private:
        oatpp::Object<UserDto> user;
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

        oatpp::Object<UserDto> getDto() {
            return this->user;
        }
    };
}

#endif //WLC_BACKEND_USER_HPP

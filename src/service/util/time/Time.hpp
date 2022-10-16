//
// Created by ender on 22-9-21.
//

#ifndef VX_DELIVERY_CPP_TIME_HPP
#define VX_DELIVERY_CPP_TIME_HPP

#include <string>
#include <openssl/md5.h>
#include <memory>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/time_clock.hpp>
#include "oatpp/core/Types.hpp"

namespace wlc::service::util::time {
    class Time {
    public:
        /**
         * 用于获取当前时间
         * @return 返回一个UNIX时间戳，单位为秒
         * */
        static long getCurrentTimestampInLong() {
            boost::posix_time::ptime epoch(boost::gregorian::date(1970, boost::gregorian::Jan, 1));
            std::unique_ptr<boost::posix_time::time_duration> timestamp = std::make_unique<boost::posix_time::time_duration>(boost::posix_time::second_clock::universal_time() - epoch);
            return timestamp->total_seconds();
        }

    };
}
#endif //VX_DELIVERY_CPP_TIME_HPP

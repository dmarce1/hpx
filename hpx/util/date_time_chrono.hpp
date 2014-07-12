//  Copyright (c) 2007-2012 Hartmut Kaiser
//  Copyright (c) 2014 Agustin Berge
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPX_UTIL_DATE_TIME_CHRONO_APR_10_2012_0449PM)
#define HPX_UTIL_DATE_TIME_CHRONO_APR_10_2012_0449PM

#include <boost/chrono/chrono.hpp>

namespace hpx { namespace util
{
    ///////////////////////////////////////////////////////////////////////////
    inline boost::chrono::steady_clock::duration to_steady_clock_duration(
        boost::chrono::steady_clock::duration const& rel_time)
    {
        return rel_time;
    }

    template <typename Rep, typename Period>
    inline boost::chrono::steady_clock::duration to_steady_clock_duration(
        boost::chrono::duration<Rep, Period> const& rel_time)
    {
        typedef boost::chrono::steady_clock::duration duration;

        return boost::chrono::duration_cast<duration>(rel_time);
    }

    template <typename Clock, typename Duration>
    inline boost::chrono::steady_clock::duration to_steady_clock_duration(
        boost::chrono::time_point<Clock, Duration> const& abs_time)
    {
        return to_steady_clock_duration(abs_time - Clock::now());
    }

    ///////////////////////////////////////////////////////////////////////////
    template <typename Clock>
    struct chrono_traits
    {
        typedef typename Clock::duration duration_type;
        typedef typename Clock::time_point time_type;

        static time_type now()
        {
            return Clock::now();
        }

        static time_type add(time_type t, duration_type d)
        {
            return t + d;
        }

        static duration_type subtract(time_type t1, time_type t2)
        {
            return t1 - t2;
        }

        static bool less_than(time_type t1, time_type t2)
        {
            return t1 < t2;
        }

        static boost::posix_time::time_duration to_posix_duration(duration_type d)
        {
            return boost::posix_time::microseconds(
                boost::chrono::duration_cast<boost::chrono::microseconds>(d).count());
        }
    };

}}

#endif

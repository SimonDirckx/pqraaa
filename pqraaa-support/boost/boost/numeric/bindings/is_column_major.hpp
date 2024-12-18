//
// Copyright (c) 2009 by Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_NUMERIC_BINDINGS_IS_COLUMN_MAJOR_HPP
#define BOOST_NUMERIC_BINDINGS_IS_COLUMN_MAJOR_HPP

#include <boost/numeric/bindings/detail/property_map.hpp>
#include <boost/numeric/bindings/tag.hpp>
#include <utility>

namespace boost {
namespace numeric {
namespace bindings {

template< typename T >
struct is_column_major:
        std::conditional<
            detail::property_has_key< T, tag::data_order >::value,
            detail::is_same_at< T, tag::data_order, tag::column_major >,
            std::true_type
        >::type {};

} // namespace bindings
} // namespace numeric
} // namespace boost

#endif

//  (C) Copyright Karl Meerbergen 2014.
//  Use, modification and distribution are subject to the 
//  GLAS Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt)

#ifndef glas2_vector_algorithm_norm_inf_hpp
#define glas2_vector_algorithm_norm_inf_hpp

#include <glas2/vector/concept/dense_vector.hpp>
#include <glas2/vector/algorithm/max.hpp>
#include <glas2/vector/algorithm/abs.hpp>
#include <glas2/concept/is.hpp>
#include <type_traits>

namespace glas2 {

  template <typename X>
  typename std::enable_if< is<DenseVector,X>::value
                         , decltype( std::abs(typename X::value_type()) )
                         >::type norm_inf( X const& x ) {
    return norm_inf( current_backend(), x ) ;
  }

  template <typename X, typename B>
  typename std::enable_if< is<DenseVector,X>::value
                         , decltype( std::abs(typename X::value_type()) )
                         >::type norm_inf( B const& backend, X const& x ) {
    return max( backend, abs(x) ) ;
  }

} // namespace glas2

#endif

//  (C) Copyright Karl Meerbergen 2021.
//
//  Use, modification and distribution are subject to the CORK Software 
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt)

#ifndef cork_newton_hpp
#define cork_newton_hpp

#include <cork/vector.hpp>
#include <cork/basis/newton.hpp>
#include <cork/basis4cork/newton.hpp>
#include <cork/matrix_iterator/newton.hpp>

namespace CORK {

  template <typename T>
  using newton = basis::newton< CORK::vector<T> > ;

} // namespace CORK

#endif
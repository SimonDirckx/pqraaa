//
// Copyright (c) 2002--2010
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL1_ROTMG_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL1_ROTMG_HPP

#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <type_traits>

//
// The BLAS-backend is selected by defining a pre-processor variable,
//  which can be one of
// * for CBLAS, define BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
// * for CUBLAS, define BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
// * netlib-compatible BLAS is the default
//
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
#include <boost/numeric/bindings/blas/detail/cblas.h>
#include <boost/numeric/bindings/blas/detail/cblas_option.hpp>
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
#include <boost/numeric/bindings/blas/detail/cublas.h>
#include <boost/numeric/bindings/blas/detail/blas_option.hpp>
#else
#include <boost/numeric/bindings/blas/detail/blas.h>
#include <boost/numeric/bindings/blas/detail/blas_option.hpp>
#endif

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end BLAS-routine.
//
namespace detail {

#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
//
// Overloaded function for dispatching to
// * CBLAS backend, and
// * float value-type.
//
inline void rotmg( float& d1, float& d2, float& x1, const float y1,
        float* sparam ) {
    cblas_srotmg( &d1, &d2, &x1, y1, sparam );
}

//
// Overloaded function for dispatching to
// * CBLAS backend, and
// * double value-type.
//
inline void rotmg( double& d1, double& d2, double& x1, const double y1,
        double* dparam ) {
    cblas_drotmg( &d1, &d2, &x1, y1, dparam );
}

#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * float value-type.
//
inline void rotmg( float& d1, float& d2, float& x1, const float y1,
        float* sparam ) {
    cublasSrotmg( &d1, &d2, &x1, &y1, sparam );
}

//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * double value-type.
//
inline void rotmg( double& d1, double& d2, double& x1, const double y1,
        double* dparam ) {
    cublasDrotmg( &d1, &d2, &x1, &y1, dparam );
}

#else
//
// Overloaded function for dispatching to
// * netlib-compatible BLAS backend (the default), and
// * float value-type.
//
inline void rotmg( float& d1, float& d2, float& x1, const float y1,
        float* sparam ) {
    BLAS_SROTMG( &d1, &d2, &x1, &y1, sparam );
}

//
// Overloaded function for dispatching to
// * netlib-compatible BLAS backend (the default), and
// * double value-type.
//
inline void rotmg( double& d1, double& d2, double& x1, const double y1,
        double* dparam ) {
    BLAS_DROTMG( &d1, &d2, &x1, &y1, dparam );
}

#endif

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to rotmg.
//
template< typename Value >
struct rotmg_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef void return_type;

    //
    // Static member function that
    // * Deduces the required arguments for dispatching to BLAS, and
    // * Asserts that most arguments make sense.
    //
    template< typename VectorDPARAM >
    static return_type invoke( real_type& d1, real_type& d2, real_type& x1,
            const real_type y1, VectorDPARAM& dparam ) {
        namespace bindings = ::boost::numeric::bindings;
        static_assert( (bindings::is_mutable< VectorDPARAM >::value) );
        detail::rotmg( d1, d2, x1, y1, bindings::begin_value(dparam) );
    }
};

//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. Calls
// to these functions are passed to the rotmg_impl classes. In the 
// documentation, the const-overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for rotmg. Its overload differs for
// * VectorDPARAM&
//
template< typename VectorDPARAM >
inline typename rotmg_impl< typename bindings::value_type<
        VectorDPARAM >::type >::return_type
rotmg( typename remove_imaginary< typename bindings::value_type<
        VectorDPARAM >::type >::type& d1, typename remove_imaginary<
        typename bindings::value_type< VectorDPARAM >::type >::type& d2,
        typename remove_imaginary< typename bindings::value_type<
        VectorDPARAM >::type >::type& x1, const typename remove_imaginary<
        typename bindings::value_type< VectorDPARAM >::type >::type y1,
        VectorDPARAM& dparam ) {
    rotmg_impl< typename bindings::value_type<
            VectorDPARAM >::type >::invoke( d1, d2, x1, y1, dparam );
}

//
// Overloaded function for rotmg. Its overload differs for
// * const VectorDPARAM&
//
template< typename VectorDPARAM >
inline typename rotmg_impl< typename bindings::value_type<
        VectorDPARAM >::type >::return_type
rotmg( typename remove_imaginary< typename bindings::value_type<
        VectorDPARAM >::type >::type& d1, typename remove_imaginary<
        typename bindings::value_type< VectorDPARAM >::type >::type& d2,
        typename remove_imaginary< typename bindings::value_type<
        VectorDPARAM >::type >::type& x1, const typename remove_imaginary<
        typename bindings::value_type< VectorDPARAM >::type >::type y1,
        const VectorDPARAM& dparam ) {
    rotmg_impl< typename bindings::value_type<
            VectorDPARAM >::type >::invoke( d1, d2, x1, y1, dparam );
}

} // namespace blas
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif

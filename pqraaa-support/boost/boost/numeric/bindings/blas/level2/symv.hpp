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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_SYMV_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_SYMV_HPP

#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/data_order.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/uplo_tag.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <cassert>
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
template< typename Order, typename UpLo >
inline void symv( const Order order, const UpLo uplo, const int n,
        const float alpha, const float* a, const int lda, const float* x,
        const int incx, const float beta, float* y, const int incy ) {
    cblas_ssymv( cblas_option< Order >::value, cblas_option< UpLo >::value, n,
            alpha, a, lda, x, incx, beta, y, incy );
}

//
// Overloaded function for dispatching to
// * CBLAS backend, and
// * double value-type.
//
template< typename Order, typename UpLo >
inline void symv( const Order order, const UpLo uplo, const int n,
        const double alpha, const double* a, const int lda, const double* x,
        const int incx, const double beta, double* y, const int incy ) {
    cblas_dsymv( cblas_option< Order >::value, cblas_option< UpLo >::value, n,
            alpha, a, lda, x, incx, beta, y, incy );
}

#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * float value-type.
//
template< typename Order, typename UpLo >
inline void symv( const Order order, const UpLo uplo, const int n,
        const float alpha, const float* a, const int lda, const float* x,
        const int incx, const float beta, float* y, const int incy ) {
    static_assert( (std::is_same<Order, tag::column_major>::value) );
    cublasSsymv( blas_option< UpLo >::value, n, alpha, a, lda, x, incx, beta,
            y, incy );
}

//
// Overloaded function for dispatching to
// * CUBLAS backend, and
// * double value-type.
//
template< typename Order, typename UpLo >
inline void symv( const Order order, const UpLo uplo, const int n,
        const double alpha, const double* a, const int lda, const double* x,
        const int incx, const double beta, double* y, const int incy ) {
    static_assert( (std::is_same<Order, tag::column_major>::value) );
    // NOT FOUND();
}

#else
//
// Overloaded function for dispatching to
// * netlib-compatible BLAS backend (the default), and
// * float value-type.
//
template< typename Order, typename UpLo >
inline void symv( const Order order, const UpLo uplo, const fortran_int_t n,
        const float alpha, const float* a, const fortran_int_t lda,
        const float* x, const fortran_int_t incx, const float beta, float* y,
        const fortran_int_t incy ) {
    static_assert( (std::is_same<Order, tag::column_major>::value) );
    BLAS_SSYMV( &blas_option< UpLo >::value, &n, &alpha, a, &lda, x, &incx,
            &beta, y, &incy );
}

//
// Overloaded function for dispatching to
// * netlib-compatible BLAS backend (the default), and
// * double value-type.
//
template< typename Order, typename UpLo >
inline void symv( const Order order, const UpLo uplo, const fortran_int_t n,
        const double alpha, const double* a, const fortran_int_t lda,
        const double* x, const fortran_int_t incx, const double beta,
        double* y, const fortran_int_t incy ) {
    static_assert( (std::is_same<Order, tag::column_major>::value) );
    BLAS_DSYMV( &blas_option< UpLo >::value, &n, &alpha, a, &lda, x, &incx,
            &beta, y, &incy );
}

#endif

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to symv.
//
template< typename Value >
struct symv_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef void return_type;

    //
    // Static member function that
    // * Deduces the required arguments for dispatching to BLAS, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename VectorX, typename VectorY >
    static return_type invoke( const real_type alpha, const MatrixA& a,
            const VectorX& x, const real_type beta, VectorY& y ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::data_order< MatrixA >::type order;
        typedef typename result_of::uplo_tag< MatrixA >::type uplo;
        static_assert( (std::is_same< typename std::remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename std::remove_const< typename bindings::value_type<
                VectorX >::type >::type >::value) );
        static_assert( (std::is_same< typename std::remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename std::remove_const< typename bindings::value_type<
                VectorY >::type >::type >::value) );
        static_assert( (bindings::is_mutable< VectorY >::value) );
        assert( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        detail::symv( order(), uplo(), bindings::size_column(a), alpha,
                bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(x), bindings::stride(x), beta,
                bindings::begin_value(y), bindings::stride(y) );
    }
};

//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. Calls
// to these functions are passed to the symv_impl classes. In the 
// documentation, the const-overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for symv. Its overload differs for
// * VectorY&
//
template< typename MatrixA, typename VectorX, typename VectorY >
inline typename symv_impl< typename bindings::value_type<
        MatrixA >::type >::return_type
symv( const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type alpha, const MatrixA& a, const VectorX& x,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type beta, VectorY& y ) {
    symv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( alpha, a, x, beta, y );
}

//
// Overloaded function for symv. Its overload differs for
// * const VectorY&
//
template< typename MatrixA, typename VectorX, typename VectorY >
inline typename symv_impl< typename bindings::value_type<
        MatrixA >::type >::return_type
symv( const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type alpha, const MatrixA& a, const VectorX& x,
        const typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type beta, const VectorY& y ) {
    symv_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( alpha, a, x, beta, y );
}

} // namespace blas
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif

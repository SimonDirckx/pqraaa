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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_TRSYL_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_TRSYL_HPP

#include <cassert>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/is_column_major.hpp>
#include <boost/numeric/bindings/is_complex.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/is_real.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value_type.hpp>
#include <type_traits>

//
// The LAPACK-backend for trsyl is the netlib-compatible backend.
//
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end LAPACK-routine.
//
namespace detail {

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * float value-type.
//
inline std::ptrdiff_t trsyl( const char trana, const char tranb,
        const fortran_int_t isgn, const fortran_int_t m,
        const fortran_int_t n, const float* a, const fortran_int_t lda,
        const float* b, const fortran_int_t ldb, float* c,
        const fortran_int_t ldc, float& scale ) {
    fortran_int_t info(0);
#ifndef LAPACK_FORTRAN_STRLEN_END
    LAPACK_STRSYL( &trana, &tranb, &isgn, &m, &n, a, &lda, b, &ldb, c, &ldc,
            &scale, &info );
#else
    LAPACK_STRSYL( &trana, &tranb, &isgn, &m, &n, a, &lda, b, &ldb, c, &ldc,
            &scale, &info ,1 ,1 );
#endif
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
inline std::ptrdiff_t trsyl( const char trana, const char tranb,
        const fortran_int_t isgn, const fortran_int_t m,
        const fortran_int_t n, const double* a, const fortran_int_t lda,
        const double* b, const fortran_int_t ldb, double* c,
        const fortran_int_t ldc, double& scale ) {
    fortran_int_t info(0);
#ifndef LAPACK_FORTRAN_STRLEN_END
    LAPACK_DTRSYL( &trana, &tranb, &isgn, &m, &n, a, &lda, b, &ldb, c, &ldc,
            &scale, &info );
#else
    LAPACK_DTRSYL( &trana, &tranb, &isgn, &m, &n, a, &lda, b, &ldb, c, &ldc,
            &scale, &info ,1 ,1 );
#endif
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
inline std::ptrdiff_t trsyl( const char trana, const char tranb,
        const fortran_int_t isgn, const fortran_int_t m,
        const fortran_int_t n, const std::complex<float>* a,
        const fortran_int_t lda, const std::complex<float>* b,
        const fortran_int_t ldb, std::complex<float>* c,
        const fortran_int_t ldc, float& scale ) {
    fortran_int_t info(0);
#ifndef LAPACK_FORTRAN_STRLEN_END
    LAPACK_CTRSYL( &trana, &tranb, &isgn, &m, &n, a, &lda, b, &ldb, c, &ldc,
            &scale, &info );
#else
    LAPACK_CTRSYL( &trana, &tranb, &isgn, &m, &n, a, &lda, b, &ldb, c, &ldc,
            &scale, &info ,1 ,1 );
#endif
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
inline std::ptrdiff_t trsyl( const char trana, const char tranb,
        const fortran_int_t isgn, const fortran_int_t m,
        const fortran_int_t n, const std::complex<double>* a,
        const fortran_int_t lda, const std::complex<double>* b,
        const fortran_int_t ldb, std::complex<double>* c,
        const fortran_int_t ldc, double& scale ) {
    fortran_int_t info(0);
#ifndef LAPACK_FORTRAN_STRLEN_END
    LAPACK_ZTRSYL( &trana, &tranb, &isgn, &m, &n, a, &lda, b, &ldb, c, &ldc,
            &scale, &info );
#else
    LAPACK_ZTRSYL( &trana, &tranb, &isgn, &m, &n, a, &lda, b, &ldb, c, &ldc,
            &scale, &info ,1 ,1 );
#endif
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to trsyl.
//
template< typename Value, typename Enable = void >
struct trsyl_impl {};

//
// This implementation is enabled if Value is a real type.
//
template< typename Value >
struct trsyl_impl< Value, typename std::enable_if< is_real< Value >::value >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename MatrixB, typename MatrixC >
    static std::ptrdiff_t invoke( const char trana, const char tranb,
            const fortran_int_t isgn, const fortran_int_t m,
            const fortran_int_t n, const MatrixA& a, const MatrixB& b,
            MatrixC& c, real_type& scale ) {
        namespace bindings = ::boost::numeric::bindings;
        static_assert( (bindings::is_column_major< MatrixA >::value) );
        static_assert( (bindings::is_column_major< MatrixB >::value) );
        static_assert( (bindings::is_column_major< MatrixC >::value) );
        static_assert( (std::is_same< typename std::remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename std::remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        static_assert( (std::is_same< typename std::remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename std::remove_const< typename bindings::value_type<
                MatrixC >::type >::type >::value) );
        static_assert( (bindings::is_mutable< MatrixC >::value) );
        assert( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        assert( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        assert( bindings::size_minor(c) == 1 ||
                bindings::stride_minor(c) == 1 );
        assert( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                m) );
        assert( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                n) );
        assert( bindings::stride_major(c) >= std::max< std::ptrdiff_t >(1,
                m) );
        assert( m >= 0 );
        assert( n >= 0 );
        assert( trana == 'N' || trana == 'T' || trana == 'C' );
        assert( tranb == 'N' || tranb == 'T' || tranb == 'C' );
        return detail::trsyl( trana, tranb, isgn, m, n,
                bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(b), bindings::stride_major(b),
                bindings::begin_value(c), bindings::stride_major(c), scale );
    }

};

//
// This implementation is enabled if Value is a complex type.
//
template< typename Value >
struct trsyl_impl< Value, typename std::enable_if< is_complex< Value >::value >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;

    //
    // Static member function, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename MatrixB, typename MatrixC >
    static std::ptrdiff_t invoke( const char trana, const char tranb,
            const fortran_int_t isgn, const fortran_int_t m,
            const fortran_int_t n, const MatrixA& a, const MatrixB& b,
            MatrixC& c, real_type& scale ) {
        namespace bindings = ::boost::numeric::bindings;
        static_assert( (bindings::is_column_major< MatrixA >::value) );
        static_assert( (bindings::is_column_major< MatrixB >::value) );
        static_assert( (bindings::is_column_major< MatrixC >::value) );
        static_assert( (std::is_same< typename std::remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename std::remove_const< typename bindings::value_type<
                MatrixB >::type >::type >::value) );
        static_assert( (std::is_same< typename std::remove_const<
                typename bindings::value_type< MatrixA >::type >::type,
                typename std::remove_const< typename bindings::value_type<
                MatrixC >::type >::type >::value) );
        static_assert( (bindings::is_mutable< MatrixC >::value) );
        assert( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        assert( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        assert( bindings::size_minor(c) == 1 ||
                bindings::stride_minor(c) == 1 );
        assert( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                m) );
        assert( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                n) );
        assert( bindings::stride_major(c) >= std::max< std::ptrdiff_t >(1,
                m) );
        assert( m >= 0 );
        assert( n >= 0 );
        assert( trana == 'N' || trana == 'C' );
        assert( tranb == 'N' || tranb == 'C' );
        return detail::trsyl( trana, tranb, isgn, m, n,
                bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(b), bindings::stride_major(b),
                bindings::begin_value(c), bindings::stride_major(c), scale );
    }

};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the trsyl_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for trsyl. Its overload differs for
// * MatrixC&
//
template< typename MatrixA, typename MatrixB, typename MatrixC >
inline std::ptrdiff_t trsyl( const char trana, const char tranb,
        const fortran_int_t isgn, const fortran_int_t m,
        const fortran_int_t n, const MatrixA& a, const MatrixB& b,
        MatrixC& c, typename remove_imaginary< typename bindings::value_type<
        MatrixA >::type >::type& scale ) {
    return trsyl_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( trana, tranb, isgn, m, n, a, b, c,
            scale );
}

//
// Overloaded function for trsyl. Its overload differs for
// * const MatrixC&
//
template< typename MatrixA, typename MatrixB, typename MatrixC >
inline std::ptrdiff_t trsyl( const char trana, const char tranb,
        const fortran_int_t isgn, const fortran_int_t m,
        const fortran_int_t n, const MatrixA& a, const MatrixB& b,
        const MatrixC& c, typename remove_imaginary<
        typename bindings::value_type< MatrixA >::type >::type& scale ) {
    return trsyl_impl< typename bindings::value_type<
            MatrixA >::type >::invoke( trana, tranb, isgn, m, n, a, b, c,
            scale );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif

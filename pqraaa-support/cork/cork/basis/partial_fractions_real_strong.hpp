//  (C) Copyright Roel Van Beeumen, Wim Michiels & Karl Meerbergen 2016.
//
//  Use, modification and distribution are subject to the CORK Software 
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt)

#ifndef cork_basis_partial_fractions_real_hpp
#define cork_basis_partial_fractions_real_hpp

//#include <cork/basis/explicit_iterator.hpp>
#include <type_traits>
#include <cassert>
#include <complex>

namespace CORK { namespace basis {

  template <typename Poles, typename Weights, typename I=typename std::decay< Poles >::type::size_type>
  class partial_fractions_real
  {
    public:
      typedef typename std::decay< Poles >::type   poles_type ;
      typedef typename std::decay< Weights >::type weights_type ;
      typedef I                                    size_type ;

    public:
      explicit partial_fractions_real( Poles poles, Weights weights )
      : poles_( poles )
      , weights_( weights )
      {
        // Real poles come first
        bool already_complex = false ;
        assert( poles_.size()==weights_.size() ) ;
        for (size_type i=0; i<poles_.size(); ++i) {
          if (poles_(i).imag()!=0.0) {
            assert( poles_(i).real()==poles_(i+1).real() ) ;
            assert( weights_(i).real()==weights_(i+1).real() ) ;
            assert( poles_(i).imag()==-poles_(i+1).imag() ) ;
            assert( weights(i).imag()==-weights(i+1).imag() ) ;
            already_complex = true ;
            ++i ;
          } else {
            assert(!already_complex) ;
            assert( weights_(i).imag()==0.0 ) ;
          }
        }
      } // partial_fractions_real

    public:
      I num_terms() const {
        return 2*poles_.size()+1 ;
      } // num_terms()

      poles_type const&  poles() const { return poles_ ; } // poles()
      weights_type const&  weights() const { return weights_ ; } // weights()

      typename std::add_lvalue_reference< Poles >::type poles() { return poles_ ; } // poles()
      typename std::add_lvalue_reference< Weights >::type weights() { return weights_ ; } // weights()

    private:
      typedef typename poles_type::value_type inner_value_type ;

    public:
      template <typename ShiftValueType>
      using value_type = typename std::common_type< decltype(std::abs(inner_value_type())), ShiftValueType >::type ;

      template <typename ShiftValueType, typename FunctionValues>
      void evaluate( ShiftValueType const& arg, FunctionValues values ) const {
        static_assert( std::is_convertible< value_type<ShiftValueType>, typename std::decay<FunctionValues>::type::value_type >::value, "" ) ;
        assert( values.size() == num_terms() ) ;
        values(0) = 1.0 ;
        for (typename std::decay<FunctionValues>::type::size_type i=1; i<num_terms(); ++i) {
          assert( arg!=poles_(i-1) ) ;
          if (poles_(i-1).imag()==0.0) {
            values(i) = weights_(i-1) / (arg - poles_(i-1)) ;
          } else {
            assert( std::abs( weights_(i-1) - std::conj(weights_(i)))==0. ) ;
            assert( std::abs( poles_(i-1) - std::conj(poles_(i)))==0. ) ;
            typename FunctionValues::value_type denom = arg*arg - arg * 2.*std::real(poles_(i-1)) + std::norm(poles_(i-1)) ;
            /*typename FunctionValues::value_type val_1 = weights_(i-1)/(arg - poles_(i-1)) ;
            typename FunctionValues::value_type val_2 = weights_(i)/(arg - poles_(i)) ;
            values(i) = 0.5*(val_1+val_2) ;
            values(i+1) = inner_value_type(0.,0.5)*(val_2-val_1) ;*/
            values(i) = (std::real(weights_(i-1))*arg - std::real(weights_(i-1)*poles_(i))) / denom ;
            values(i+1) = (std::imag(weights_(i-1))*arg - std::imag(weights_(i-1)*poles_(i))) / denom ;
            ++i ;
          }
        }
      } // evaluate

/*    public:
      template <typename ShiftValueType>
      using iterator = explicit_iterator< value_type<ShiftValueType> > ;

      template <typename ShiftValueType>
      decltype (auto) evaluate_iterator( ShiftValueType const& arg ) const {
        return explicit_iterator<ShiftValueType>( *this, arg ) ;
      } // evaluate_iterator
*/
    private:
      Poles   poles_ ;
      Weights weights_ ;
  } ; // class partial_fractions_real


  template <typename Poles, typename Weights>
  partial_fractions_real<Poles&,Weights&> make_partial_fractions_real_lvalue( Poles& poles, Weights& weights ) {
    return partial_fractions_real<Poles&,Weights&>( poles, weights ) ;
  }

  template <typename Poles, typename Weights>
  decltype (auto) make_partial_fractions_real_rvalue( Poles&& poles, Weights&& weights ) {
    return partial_fractions_real<Poles&&, Weights&&>( poles, weights ) ;
  }

  template <typename Poles, typename Weights>
  partial_fractions_real<Poles, Weights> make_partial_fractions_real( Poles const& poles, Weights const& weights ) {
    return partial_fractions_real<Poles, Weights>( poles, weights ) ;
  }

} } // namespace CORK::basis

#endif
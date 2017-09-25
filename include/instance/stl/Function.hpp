#pragma once

#include <functional>
#include "typeclass/Functor.hpp"
#include "typeclass/Applicative.hpp"
#include "typeclass/Monad.hpp"
// ////////////////////////////////////////////////////////////////////////////
/** Functor instance */
// ////////////////////////////////////////////////////////////////////////////
template<typename A>
struct Functor<std::function, A(void)> 
{
   template<typename B>
   std::function<B()> fmap
     ( std::function<B(A)> f
     , std::function<A()> fA
     )
   {
      return [&]()
      {
         return f (fA());
      };
   };
   
   template<typename B>
   std::function<B()> replace
     ( B b
     , std::function<A()> fA
     )
   {
      return [&]()
      {
         return b;
      };
   };

};

// ////////////////////////////////////////////////////////////////////////////
/** Applicative Instance */
// ////////////////////////////////////////////////////////////////////////////
template<typename A>
struct Applicative<std::function, A(void)> 
   : public Functor<std::function, A(void)> 
{
   std::function<A()> pure
      ( A a
      )
   { 
      return [&]()
      {
         return a;
      };
   };
   
   template<typename B, typename C>
   static std::function<C()> ap
     ( std::function<C(A,B)> fn
     , std::function<A()> fA
     , std::function<B()> fB
     )
   {
      return[&]()
      {
         return fn(fA(), fB());
      };
   };
};


// ////////////////////////////////////////////////////////////////////////////
/** Monad Instance */
// ////////////////////////////////////////////////////////////////////////////
template<typename A>
struct Monad<std::function, A(void)> 
   : public Applicative<std::function, A(void)> 
{

   template<typename B>
   std::function<B()> bind
      ( std::function<A()> fA
      , std::function< std::function<B()>( A ) > aTofB
      )
   {
      return aTofB( fA() );
   };
};


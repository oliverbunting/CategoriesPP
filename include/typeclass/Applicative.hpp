#pragma once 

#include <functional>
#include "typeclass/Functor.hpp"

template<template <typename> typename F_, typename A>
struct Applicative : public Functor<F_,A> {

   static F_<A> pure
     ( A a 
     );

   template<typename B, typename C>
   static F_<C> ap
     ( std::function<C(A,B)> fn
     , F_<A> fA
     , F_<B> fB
     );
};


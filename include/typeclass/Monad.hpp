#pragma once

#include <functional>
#include "Applicative.hpp"

template<template <typename> typename M_, typename A>
struct Monad: public Applicative<M_,A> {

   template<typename B>
   static M_<B> bind
      ( M_<A>
      , std::function<M_<B>(A)> 
      );

};



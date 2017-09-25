#pragma once

#include <functional>

template<template <typename> typename F_, typename A>
struct Functor {

   template<typename B> 
   static F_<B> fmap
     ( std::function<B(A)>
     , F_<A>
     );

   template<typename B> 
   static F_<B> replace
     ( B
     , F_<A>
     );
};



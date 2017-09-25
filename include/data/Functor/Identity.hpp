#pragma once

#include <functional>
#include <typeclass/Functor.hpp>
#include <typeclass/Applicative.hpp>
#include <typeclass/Monad.hpp>

template<typename A>
struct Identity {
   Identity(A a) : a(a){};
   ~Identity(){};

   A& a;
};

#include "Identity.tpp"

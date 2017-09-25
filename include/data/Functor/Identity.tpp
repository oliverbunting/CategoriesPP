#pragma once

// ////////////////////////////////////////////////////////////////////////////
/** Functor instance */
// ////////////////////////////////////////////////////////////////////////////
template<typename A>
struct Functor<Identity, A>
{
   template<typename B>
   Identity<B> fmap
     ( std::function<B(A)> f
     , Identity<A> fA
     )
   {
      return Identity( f( fA.a ));
   };

};

// ////////////////////////////////////////////////////////////////////////////
/** Applicativie Instance */
// ////////////////////////////////////////////////////////////////////////////
template<typename A>
struct Applicative<Identity, A>
   : public Functor<Identity, A>
{
   Identity<A> pure(A a) { return Identity<A>(a); };

   template<typename B, typename C>
   Identity<C> ap
     ( std::function<C(A,B)> fn
     , Identity<A()> fA
     , Identity<B()> fB
     )
   {
      return Identity( fn(fA.a, fA.b) );
   };
};

// ////////////////////////////////////////////////////////////////////////////
/** Monad Instance */
// ////////////////////////////////////////////////////////////////////////////
template<typename A>
struct Monad<Identity, A>
   : public Applicative<Identity, A>
{

   template<typename B>
   Identity<B> bind
      ( Identity<A> fA
      , std::function< Identity<B>(A) > aTofB
      )
   {
      return Identity( aTofB( fA.a ) );
   };
};

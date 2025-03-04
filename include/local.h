#ifndef ELSIE_LOCAL_H
#define ELSIE_LOCAL_H
#if __has_include(<atcoder/modint>)
#include "atcoder/modint"
using namespace atcoder;
using mint=modint998244353;
using mint1=modint1000000007;
#endif
#include <limits>
#include <new>
#include <initializer_list>
#include <compare>
#include <concepts>
#include <utility>
#include <bitset>
#include <tuple>
#include <type_traits>
#include <functional>
#include <chrono>
#include <string>
#include <array>
#include <deque>
#include <list>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <ranges>
#include <algorithm>
#include <bit>
#include <random>
#include <numeric>
#include <numbers>
#include <iostream>
#include <ios>
#include <streambuf>
#include <iomanip>
#include <sstream>
#include <regex>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
using namespace chrono;
namespace nbl=numbers;
using std::cin;
using std::cout;
using sstream=stringstream;
#define RET return
#define fi first
#define se second
#define endl '\n'
#define sn(i,c) " \n"[i==c]
#define rsv(n) reserve(n)
#define pf(a) push_front(a)
#define pb(a) push_back(a)
#define eb(...) emplace_back(__VA_ARGS__)
#define ppf() pop_front()
#define ppb() pop_back()
#define pp() pop()
#define ins(a) insert(a)
#define emp(...) emplace(__VA_ARGS__)
#define ers(a) erase(a)
#define cont(a) contains(a)
#define mp(f,s) make_pair(f,s)
#define A(a) begin(a),end(a)
#define I(a,i) begin(a),begin(a)+(i)
#define elif(c) else if(c)
#define _SEL4(_1,_2,_3,_4,name,...) name
#define _SEL3(_1,_2,_3,name,...) name
#define _REP4(i,s,n,st) for(int i=(s);i<(n);i+=(st))
#define _REP3(i,s,n) _REP4(i,s,n,1)
#define _REP2(i,n) _REP3(i,0,n)
#define _REP1(n) _REP2(_,n)
#define _RREP4(i,n,t,s) for(int i=(n);i>=(t);i-=(s))
#define _RREP3(i,n,t) _RREP4(i,n,t,1)
#define _RREP2(i,n) _RREP3(i,n,0)
#define _ITER2(x,a) for(auto&x:a)
#define _ITER3(x,y,a) for(auto&[x,y]:a)
#define _CTER2(x,a) for(const auto&x:a)
#define _CTER3(x,y,a) for(const auto&[x,y]:a)
#define rep(...) _SEL4(__VA_ARGS__,_REP4,_REP3,_REP2,_REP1)(__VA_ARGS__)
#define rrep(...) _SEL4(__VA_ARGS__,_RREP4,_RREP3,_RREP2,_REP1)(__VA_ARGS__)
#define forif(c,...) rep(__VA_ARGS__)if(c)
#define iter(...) _SEL3(__VA_ARGS__,_ITER3,_ITER2)(__VA_ARGS__)
#define cter(...) _SEL3(__VA_ARGS__,_CTER3,_CTER2)(__VA_ARGS__)
#define _LB_BEX(b,e,x) lower_bound(b,e,x)
#define _LB_BEXG(b,e,x,g) lower_bound(b,e,x,g)
#define _UB_BEX(b,e,x) upper_bound(b,e,x)
#define _UB_BEXG(b,e,x,g) upper_bound(b,e,x,g)
#define lb(...) _SEL4(__VA_ARGS__,_LB_BEXG,_LB_BEX)(__VA_ARGS__)
#define ub(...) _SEL4(__VA_ARGS__,_UB_BEXG,_UB_BEX)(__VA_ARGS__)
#define rev(a) reverse(A(a))
#define minel(a) min_element(A(a))
#define maxel(a) max_element(A(a))
#define acm(a) accumulate(A(a),0ll)
#define nxpm(a) next_permutation(A(a))
#define Sort(a) sort(A(a))
#define uni(a) Sort(a);a.erase(unique(A(a)),a.end())
#define swapcase(a) a=(isalpha(a)?a^32:a)
#define NL cout<<'\n'
constexpr int64_t inf=1ll<<60,minf=-inf;
constexpr int32_t inf32=1ll<<30,minf32=-inf32;
constexpr char sep='\n';
constexpr array<pair<int32_t,int32_t>,8>dc={{{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}};
template<class T,class U>inline void chmax(T&a,const U&b){if(a<b)a=b;}
template<class T,class U>inline void chmin(T&a,const U&b){if(a>b)a=b;}
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define yn(c) (c)?yes:no
#if __cplusplus <= 202002L
#else
#define C const
namespace vies=std::views;
#define DR(i) views::drop(i)
#define TK(i) views::take(i)
#define RV views::reverse
#define IOTA vies::iota
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) str __VA_ARGS__;in(__VA_ARGS__)
#define VI(a,n) vi a(n);in(a)
#define VIT(a,n) vit a(n);in(a)
#define VS(a,n) vs a(n);in(a)
#define UV(u,v) INT(u,v);--u,--v
#define UVW(u,v,w) INT(u,v,w);--u,--v
template<class T,class U>concept LUBI= same_as<T,vector<U>>||same_as<T,deque<U>>||is_array_v<T>;
#define TP template<class T,class U,typename cp=less<U>>
#define RL requires LUBI<T,U>
TP size_t lbi(C T&v,C U&x,cp cmp=cp())RL{RET lb(A(v),x,cmp)-begin(v);}
TP size_t ubi(C T&v,C U&x,cp cmp=cp())RL{RET ub(A(v),x,cmp)-begin(v);}
TP size_t lbi(size_t i,C T&v,C U&x,cp cmp=cp())RL{RET lb(i+A(v),x,cmp)-begin(v);}
TP size_t ubi(size_t i,C T&v,C U&x,cp cmp=cp())RL{RET ub(i+A(v),x,cmp)-begin(v);}
TP size_t lbi(C T&v,size_t i,C U&x,cp cmp=cp())RL{RET lb(I(v,i),x,cmp)-begin(v);}
TP size_t ubi(C T&v,size_t i,C U&x,cp cmp=cp())RL{RET ub(I(v,i),x,cmp)-begin(v);}
TP size_t lbi(size_t i,C T&v,size_t e,C U&x,cp cmp=cp())RL{RET lb(i+I(v,e),x,cmp)-begin(v);}
TP size_t ubi(size_t i,C T&v,size_t e,C U&x,cp cmp=cp())RL{RET ub(i+I(v,e),x,cmp)-begin(v);}
#undef TP
#undef RL
#define TP template
#define MUT make_unsigned_t
TP<integral T>int32_t pcnt(T p){return popcount(MUT<T>(p));}
TP<integral T>int32_t lsb(T p){return countl_zero(MUT<T>(p));}
TP<integral T>int32_t msb(T p){return countr_zero(MUT<T>(p));}
TP<int32_t N,integral T>void putbit(T s){
	char buf[N+1]={0};
	for(char*itr=buf+N-1;itr>=buf;itr--,s>>=1)
		*itr='0'+(s&1);
	cout<<buf<<sep;
}
#undef MUT
#undef TP
#undef C
#include <misc/std_io.hpp>
#endif
#ifdef LOCAL
#define dput(...) dos=&cerr;out(__VA_ARGS__);dos=&cout
#else
#define dput(...)
#endif
#endif // include guard

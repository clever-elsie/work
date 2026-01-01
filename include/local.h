#if __has_include(<atcoder/modint>)
#include "atcoder/modint"
using namespace atcoder;
using mint=modint998244353;
using mint1=modint1000000007;
#endif
#include<limits>
#include<new>
#include<initializer_list>
#include<compare>
#include<concepts>
#include<utility>
#include<bitset>
#include<tuple>
#include<type_traits>
#include<functional>
#include<array>
#include<deque>
#include<list>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<iterator>
#include<ranges>
#include<algorithm>
#include<bit>
#include<random>
#include<numeric>
#include<numbers>
#include<iostream>
#include<ios>
#include<streambuf>
#include<iomanip>
#include<sstream>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdarg>
#include<cstddef>
#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
using std::cin;
using std::cout;
using sstream=stringstream;
template<class f>using vc=vector<f>;
template<class f>using vv=vc<vc<f>>;
template<class f>using v3=vv<vc<f>>;
template<class f>using v4=vv<vv<f>>;
template<class T>using twin=std::pair<T,T>;
template<class f>using gr=greater<f>;
template<class f>using pq=priority_queue<f>;
template<class f>using pqg=priority_queue<f, vc<f>, gr<f>>;
template<class Key, class Hash=std::hash<Key>, class Pred=std::equal_to<Key>, class Allocator= std::allocator<Key>>
using uset=unordered_set<Key,Hash,Pred,Allocator>;
template<class Key, class T, class Hash=std::hash<Key>, class Pred=std::equal_to<Key>, class Allocator= std::allocator<Key>>
using umap=unordered_map<Key,T,Hash,Pred,Allocator>;
using it=int32_t;
using i8=int8_t;   using u8=uint8_t;
using i16=int16_t; using u16=uint16_t;
using i32=int32_t; using u32=uint32_t;
using i64=int64_t; using u64=uint64_t;
using i128=__int128_t; using u128=__uint128_t;
using intw=__int128_t; using uintw=__uint128_t;
using f32=float;
using f64=double;
using f128=__float128;
using vi=vc<i64>;
using vit=vc<it>;
using vb=vc<bool>;
using pi=twin<i64>;
using pit=twin<it>;
using str=string;
using vs=vc<str>;
using pqgp=pqg<pi>;
#define int i64
#define itn i64
#define LL long long
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
#define _SEL4(_1,_2,_3,_4,name,...) name
#define _SEL3(_1,_2,_3,name,...) name
#define _REP4(i,s,n,st) for(long i=(s);i<(n);i+=(st))
#define _REP3(i,s,n) _REP4(i,s,n,1)
#define _REP2(i,n) _REP3(i,0,n)
#define _REP1(n) _REP2(_,n)
#define _RREP4(i,n,t,s) for(long i=(n);i>=(t);i-=(s))
#define _RREP3(i,n,t) _RREP4(i,n,t,1)
#define _RREP2(i,n) _RREP3(i,n,0)
#define _ITER2(x,a) for(auto&&x:a)
#define _ITER3(x,y,a) for(auto&&[x,y]:a)
#define _CTER2(x,a) for(const auto&x:a)
#define _CTER3(x,y,a) for(const auto&[x,y]:a)
#define rep(...) _SEL4(__VA_ARGS__,_REP4,_REP3,_REP2,_REP1)(__VA_ARGS__)
#define rrep(...) _SEL4(__VA_ARGS__,_RREP4,_RREP3,_RREP2,_REP1)(__VA_ARGS__)
#define iter(...) _SEL3(__VA_ARGS__,_ITER3,_ITER2)(__VA_ARGS__)
#define cter(...) _SEL3(__VA_ARGS__,_CTER3,_CTER2)(__VA_ARGS__)
#define NL cout<<'\n'
#define npi numbers::pi
constexpr i64 inf=1ll<<60,minf=-inf;
constexpr u32 inf32=1ll<<30,minf32=-inf32;
constexpr char sep='\n';
constexpr array<pit,8>dc={pit{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define yn(c) (c)?yes:no
#if __cplusplus > 202002L

namespace vies=std::views;
#define DR(i) views::drop(i)
#define TK(i) views::take(i)
#define RV views::reverse
#define IOTA views::iota

#define rev(a) reverse(A(a))
#define minel(a) min_element(A(a))
#define maxel(a) max_element(A(a))
#define acm(a) accumulate(A(a),0ll)
#define nxpm(a) next_permutation(A(a))
#define Sort(a) sort(A(a))
#define uni(a) Sort(a);a.erase(unique(A(a)),a.end())
#define swapcase(a) a=(isalpha(a)?a^32:a)

template<class T,class U>inline void chmax(T&a,const U&b){if(a<b)a=b;}
template<class T,class U>inline void chmin(T&a,const U&b){if(a>b)a=b;}

#define _BISECT4(_1,_2,_3,_4,name,...) name
#define _LB_BEX(b,e,x) lower_bound(b,e,x)
#define _LB_BEXG(b,e,x,g) lower_bound(b,e,x,g)
#define _UB_BEX(b,e,x) upper_bound(b,e,x)
#define _UB_BEXG(b,e,x,g) upper_bound(b,e,x,g)
#define lb(...) _BISECT4(__VA_ARGS__,_LB_BEXG,_LB_BEX)(__VA_ARGS__)
#define ub(...) _BISECT4(__VA_ARGS__,_UB_BEXG,_UB_BEX)(__VA_ARGS__)

#define TP template<class T,class U,typename cp=less<U>>
template<class T,class U>concept LUBI= same_as<T,vector<U>>||same_as<T,deque<U>>||is_array_v<T>;
#define RL requires LUBI<T,U>

TP size_t lbi(const T&v,const U&x,cp cmp=cp())RL{RET lb(A(v),x,cmp)-begin(v);}
TP size_t ubi(const T&v,const U&x,cp cmp=cp())RL{RET ub(A(v),x,cmp)-begin(v);}
TP size_t lbi(size_t i,const T&v,const U&x,cp cmp=cp())RL{RET lb(i+A(v),x,cmp)-begin(v);}
TP size_t ubi(size_t i,const T&v,const U&x,cp cmp=cp())RL{RET ub(i+A(v),x,cmp)-begin(v);}
TP size_t lbi(const T&v,size_t i,const U&x,cp cmp=cp())RL{RET lb(I(v,i),x,cmp)-begin(v);}
TP size_t ubi(const T&v,size_t i,const U&x,cp cmp=cp())RL{RET ub(I(v,i),x,cmp)-begin(v);}
TP size_t lbi(size_t i,const T&v,size_t e,const U&x,cp cmp=cp())RL{RET lb(i+I(v,e),x,cmp)-begin(v);}
TP size_t ubi(size_t i,const T&v,size_t e,const U&x,cp cmp=cp())RL{RET ub(i+I(v,e),x,cmp)-begin(v);}

#undef TP
#undef RL
#define TP template<integral T>
#define MT make_unsigned_t<T>

TP constexpr i32 pcnt(T p){return popcount(MT(p));}
TP constexpr i32 lsb(T p){return countr_zero(MT(p));}
TP constexpr i32 msb(T p){return sizeof(T)*8-1-countl_zero(MT(p));}

template<int32_t N,integral T>
void putbit(T s){
  char buf[N+1]={0};
  for(char*itr=buf+N-1;itr>=buf;itr--,s>>=1)
    *itr='0'+(s&1);
  cout<<buf<<sep;
}
#undef TP
#undef MT
#endif

#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) str __VA_ARGS__;in(__VA_ARGS__)
#define VI(a,n) vi a(n);in(a)
#define VIT(a,n) vit a(n);in(a)
#define VS(a,n) vs a(n);in(a)
#define UV(u,v) INT(u,v);--u,--v
#define UVW(u,v,w) INT(u,v,w);--u,--v
#ifdef LOCAL
#define dput(...) dos=&cerr;out(__VA_ARGS__);dos=&cout
#else
#define dput(...)
#endif

template<class T>concept Lint=same_as<T,__int128_t>||same_as<T,__uint128_t>;
template<class T>concept Itrabl=requires(const T&x){x.begin();x.end();}&&!std::is_same_v<T,string>;
template<class T>concept IItrabl=Itrabl<T>&&Itrabl<typename T::value_type>;
template<class T>concept ModInt=requires(const T&x){x.val();};
template<class T>concept NLobj=Itrabl<T>||std::is_same_v<T,string>;

istream&operator<<(istream&is,__float128&x){double y;is>>y;x=y;return is;}
ostream&operator<<(ostream&os,const __float128&x){return os<<static_cast<double>(x);}

template<Lint T>ostream&operator<<(ostream&dst,T val){
  ostream::sentry s(dst);
  if(!s)return dst;
  char _O128[64];
  char*d=end(_O128);
  bool vsign=val<0;
  __uint128_t v=val;
  if(vsign&&val!=numeric_limits<T>::min())v=1+~(__uint128_t)val;
  do{
    *(--d)="0123456789"[v%10];
    v/=10;
  }while(v!=0);
  if(vsign)*(--d)='-';
  ptrdiff_t len=end(_O128)-d;
  if(dst.rdbuf()->sputn(d,len)!=len)dst.setstate(ios_base::badbit);
  return dst;
}

template<Lint T>istream&operator>>(istream&src,T&val) {
  string s;src>>s;
  bool is_neg=numeric_limits<T>::is_signed&&s.size()>0&&s[0]=='-';
  for(val=0;const auto&x:s|views::drop(is_neg))val=10*val+x-'0';
  if(is_neg)val*=-1;
  return src;
}

template<ModInt T>istream&operator>>(istream&is,T&v){int64_t x;is>>x;v=x;return is;}
template<class T,class U>istream&operator>>(istream&is,pair<T,U>&v){return is>>v.first>>v.second;}
template<Itrabl T>istream&operator>>(istream&is,T&v){for(auto&&x:v)is>>x;return is;}

template<class T>void in(T&a){cin>>a;}
template<class T,class... Ts>void in(T&a,Ts&... b){in(a);in(b...);}

template<class T,class U>vector<pair<T,U>>zip(u64 n,u64 m){
  vector<pair<T,U>>r(min(n,m));
  iter(x,y,r)in(x);
  iter(x,y,r)in(y);
  return move(r);
}
template<class T,class U>vector<pair<T,U>>zip(u64 n){return move(zip<T,U>(n,n));}

template<ModInt T>ostream&operator<<(ostream&os,const T&v){return os<<v.val(); }
template<class T,class U>ostream&operator<<(ostream&os,const pair<T,U>&v){return os<<'('<<v.first<<','<<v.second<<')';}
template<Itrabl T>ostream&operator<<(ostream&os,const T&v){u64 cnt=0;cter(x,v)os<<x<<(++cnt<v.size()?" ":"");return os;}
template<IItrabl T>ostream&operator<<(ostream&os,const T&v){u64 cnt=0;cter(x,v)os<<x<<(++cnt<v.size()?"\n":"");return os;}
inline ostream*dos=&cout;
inline int32_t OFLG; // 0:first, 1:notNLobj, 2:NLobj
template<class T>void _out(const T&a){if(OFLG)(*dos)<<"0 \n"[OFLG]<<a;else(*dos)<<a;OFLG=1;}
template<NLobj T>void _out(const T&a){(*dos)<<(OFLG?"\n":"")<<a;OFLG=2;}
template<class T,class...Ts>void _out(const T&a,const Ts&... b){_out(a);_out(b...);}
template<class... Ts>void out(const Ts&... v){OFLG=0;_out(v...);(*dos)<<sep;}

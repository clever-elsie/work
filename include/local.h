#include <atcoder/modint>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
namespace vies=std::views;
using std::cin;
using std::cout;
using sstream=stringstream;
using namespace atcoder;
using mint=modint998244353;
using mint1=modint1000000007;
using namespace __gnu_pbds;
template<class s,class t>using __gnu_map=tree<s,t,less<s>,rb_tree_tag,tree_order_statistics_node_update>;
template<class s,class t>struct gnu_map:public __gnu_map<s,t>{
	using iterator=typename __gnu_map<s,t>::iterator;
	iterator get(size_t idx){return this->find_by_order(idx);}
	size_t ord(const s&key){return this->order_of_key(key);}
	// order_of_key(key)=>get N of (key is Nth);
};
template<class s>struct gnu_set:public gnu_map<s,null_type>{
	using iterator=typename __gnu_map<s,null_type>::iterator;
	template<integral T>iterator operator[](T i){return this->find_by_order(i);}
};
#define RET return
#define int long long
#define itn long long
#define fi first
#define se second
#define endl '\n'
#define sn(i,c) " \n"[i==c];
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
#define _REP1(n) for(int _=0;_<(n);_++)
#define _REP2(i,n) for(int i=0;i<(n);i++)
#define _REP3(i,s,n) for(int i=(s);i<(n);i++)
#define _REP4(i,s,n,step) for(int i=(s);i<(n);i+=(step))
#define _RREP2(i,n) for(int i=(n);i>=0;i--)
#define _RREP3(i,n,t) for(int i=(n);i>=(t);i--)
#define _RREP4(i,n,t,s) for(int i=(n);i>=(t);i-=(s))
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
#define uni(a) a.erase(unique(A(a)),a.end())
#define Sort(a) sort(A(a))
#define swapcase(a) a=(isalpha(a)?a^32:a)
#define DR(i) views::drop(i)
#define TK(i) views::take(i)
#define RV views::reverse
#define IOTA vies::iota
#define NL cout<<'\n'
template<class f>using gr=greater<f>;
template<class f>using vc=vector<f>;
template<class f>using vv=vc<vc<f>>;
template<class f>using v3=vv<vc<f>>;
template<class f>using v4=vv<vv<f>>;
template<class f>using pq=priority_queue<f>;
template<class f>using pqg=priority_queue<f, vc<f>, gr<f>>;
#define uset unordered_set
#define umap unordered_map
using i8=int8_t; using i16=int16_t; using i32=int32_t; using i64=int64_t; using i128=__int128_t;
using u8=uint8_t;using u16=uint16_t;using u32=uint32_t;using u64=uint64_t;using u128=__uint128_t;
using intw=__int128_t;using uintw=__uint128_t;
using f32=float;using f64=double;using f128=long double;
using vi=vc<int>;using vb=vc<bool>;
using pi=pair<int,int>;
using str=string;using vs=vc<str>;
using pqgp=pqg<pi>;
#define INT(...) int __VA_ARGS__;getv(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;getv(__VA_ARGS__)
#define STR(...) str __VA_ARGS__;getv(__VA_ARGS__)
#define VI(a,n) vi a(n);getv(a)
#define VS(a,n) vs a(n);getv(a)
#define UV(u,v) INT(u,v);u--,v--
#define UVW(u,v,w) INT(u,v,w);u--,v--
constexpr int inf=1ll<<60,minf=-inf;
constexpr array<pi,8>dc={{{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}};
constexpr array<u32,6> mods{998244353,998244853,1000000007,1000000009,1000000021,1000000033};
template<integral T,integral U>inline
auto ceil(const T a,const U b){return(a+b-1)/b;}
template<integral T,integral U>inline
auto floor(const T a,const U b){return a/b-(a%b&&(a^b)<0);}
template<class T,class U>inline void chmax(T&a,const U&b){if(a<b)a=b;}
template<class T,class U>inline void chmin(T&a,const U&b){if(a>b)a=b;}
template<class... T>inline auto min(T... a){return (std::min)(initializer_list<common_type_t<T...>>{a...});}
template<class... T>inline auto max(T... a){return (std::max)(initializer_list<common_type_t<T...>>{a...});}
template<class T,class U>concept LUBI= same_as<T,vc<U>>||same_as<T,deque<U>>||is_array_v<T>;
template<class T,class U,typename comp=less<U>>
	size_t lbi(const T&v,const U&x,comp cmp=comp()) requires LUBI<T,U>
		{ return lb(A(v),x,cmp)-v.begin(); }
template<class T,class U,typename comp=less<U>>
	size_t lbi(size_t i,const T&v,const U&x,comp cmp=comp()) requires LUBI<T,U>
		{ return lb(i+A(v),x,cmp)-v.begin(); }
template<class T,class U,typename comp=less<U>>
	size_t lbi(const T&v,size_t i,const U&x,comp cmp=comp()) requires LUBI<T,U>
		{ return lb(I(v,i),x,cmp)-v.begin(); }
template<class T,class U,typename comp=less<U>>
	size_t lbi(size_t i,const T&v,size_t e,const U&x,comp cmp=comp()) requires LUBI<T,U>
		{ return lb(i+I(v,e),x,cmp)-v.begin(); }
template<class T,class U,typename comp=less<U>>
	size_t ubi(const T&v,const U&x,comp cmp=comp()) requires LUBI<T,U>
		{ return ub(A(v),x,cmp)-v.begin(); }
template<class T,class U,typename comp=less<U>>
	size_t ubi(size_t i,const T&v,const U&x,comp cmp=comp()) requires LUBI<T,U>
		{ return ub(i+A(v),x,cmp)-v.begin(); }
template<class T,class U,typename comp=less<U>>
	size_t ubi(const T&v,size_t i,const U&x,comp cmp=comp()) requires LUBI<T,U>
		{ return ub(I(v,i),x,cmp)-v.begin(); }
template<class T,class U,typename comp=less<U>>
	size_t ubi(size_t i,const T&v,size_t e,const U&x,comp cmp=comp()) requires LUBI<T,U>
		{ return ub(i+I(v,e),x,cmp)-v.begin(); }
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define yn(c) (c)?yes:no
template<class T>concept Lint=is_integral_v<T>&&sizeof(T)>8;
template<Lint T>ostream&operator<<(ostream&dst,T val){
	ostream::sentry s(dst);
	if (!s)return dst;
	char _O128[64];
	bool vsign=val<0;
	if(vsign){
		if(val==numeric_limits<T>::min()) {
			const char*minVal="-170141183460469231731687303715884105728";
			if (dst.rdbuf()->sputn(minVal,40)!=40)dst.setstate(ios_base::badbit);
			return dst;
		}
		val=(~val)+1;
	}
	char*d=end(_O128);
	do{
		*(--d)="0123456789"[val%10];
		val/=10;
	}while(val!=0);
	if(vsign)*(--d)='-';
	size_t len=end(_O128)-d;
	if(dst.rdbuf()->sputn(d,len)!=len)dst.setstate(ios_base::badbit);
	return dst;
}
template<Lint T>istream&operator>>(istream&src,T&val) {
	str s;src>>s;
	bool is_neg=numeric_limits<T>::is_signed&&s.size()>0&&s[0]=='-';
	for(val=0;const auto&x:s|views::drop(is_neg))val=10*val+x-'0';
	if(is_neg)val*=-1;
	return src;
}
#define MUT make_unsigned_t
template<integral T>i32 pcnt(T p){return popcount(MUT<T>(p));}
template<integral T>i32 lsb(T p){return countl_zero(MUT<T>(p));}
template<integral T>i32 msb(T p){return countr_zero(MUT<T>(p));}
template<class T>concept Itrabl=requires(const T&x){x.begin();x.end();};
template<class T>concept IItrabl=Itrabl<T>&&Itrabl<typename T::value_type>;
template<class T>concept ModInt=requires(const T&x){x.val();};
void _getv(str&a){cin>>a;}
template<class T>void _getv(T&a){cin>>a;}
template<class T,class U>void _getv(pair<T,U>&a){_getv(a.fi);_getv(a.se);}
template<Itrabl T>void _getv(T&a){iter(x,a)_getv(x);}
template<class T>void getv(T&a){_getv(a);}
template<class T,class... Ts>void getv(T&a,Ts&... b){_getv(a);getv(b...);}
void _putv(const str&a){NL;cout<<a;NL;}
template<class T>void _putv(const T&a){cout<<a<<' ';}
template<ModInt T>void _putv(const T&a){cout<<a.val()<<' ';}
template<Itrabl T>void _putv(const T&a){NL;cter(x,a)_putv(x);NL;}
template<IItrabl T>void _putv(const T&a){NL;cter(y,a){cter(x,y)_putv(x);NL;}}
template<IItrabl T>void _putv(const T&a)requires same_as<typename T::value_type,str>{NL;cter(x,a)cout<<x<<'\n';}
template<class T>void putv(const T&a){_putv(a);NL;}
template<class T,class... Ts>void putv(const T&a,const Ts&... b){_putv(a);putv(b...);}
template<i32 N,integral T> void putbit(T s,char sep='\n'){
	char buf[N+1]={0};
	for(char*itr=buf+N-1;itr>=buf;itr--,s>>=1)
		*itr='0'+(s&1);
	cout<<buf<<sep;
}
#ifdef LOCAL
#define dput(...) putv(__VA_ARGS__)
#else
#define dput(...)
#endif


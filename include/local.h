#include <atcoder/modint>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// order_of_key(key)=>get N of (key is Nth);
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
template<class s,class t>struct gnu_map:public __gnu_map<s,t> {
	using iterator=typename __gnu_map<s, t>::iterator;
	template<integral T>iterator operator[](T i){return this->find_by_order(i);}
};
#define int long long
#define itn long long
#define fi first
#define se second
#define endl '\n'
#define sn(i,c) " \n"[i==c];
#define pf(a) push_front(a)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define ppf() pop_front()
#define ppb() pop_back()
#define pp() pop()
#define ins(a) insert(a)
#define emp(a) emplace(a)
#define cont(a) contains(a)
#define mp(f,s) make_pair(f,s)
#define A(a) begin(a),end(a)
#define I(a,i) begin(a),begin(a)+(i)
#define elif(c) else if(c)
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
#define _REP(_1,_2,_3,_4,name,...) name
#define rep(...) _REP(__VA_ARGS__,_REP4,_REP3,_REP2,_REP1)(__VA_ARGS__)
#define rrep(...) _REP(__VA_ARGS__,_RREP4,_RREP3,_RREP2,_REP1)(__VA_ARGS__)
#define forif(c,...) rep(__VA_ARGS__)if(c)
#define _ITER(_1,_2,_3,name,...) name
#define iter(...) _ITER(__VA_ARGS__,_ITER3,_ITER2)(__VA_ARGS__)
#define cter(...) _ITER(__VA_ARGS__,_CTER3,_CTER2)(__VA_ARGS__)
#define acm(a,s) accumulate(A(a),s)
#define nxpm(a) next_permutation(A(a))
#define uni(a) a.erase(unique(A(a)),a.end())
#define DR(i) views::drop(i)
#define TK(i) views::take(i)
#define RV views::reverse
#define IOTA vies::iota
#define NL cout<<'\n'
template<class s>using gnu_set=gnu_map<s,null_type>;
template<class f>using vc=vector<f>;
template<class f>using vv=vc<vc<f>>;
template<class f>using v3=vv<vc<f>>;
template<class f>using v4=vv<vv<f>>;
template<class f>using gr=greater<f>;
template<class f>using pq=priority_queue<f>;
template<class f>using pqg=priority_queue<f, vc<f>, gr<f>>;
#define uset unordered_set
#define umap unordered_map
using i8=int8_t; using i16=int16_t; using i32=int32_t; using i64=int64_t;
using u8=uint8_t;using u16=uint16_t;using u32=uint32_t;using u64=uint64_t;
using intw=__int128_t;using uintw=__uint128_t;
using f32=float;using f64=double;
using vi=vc<int>;using vb=vc<bool>;
using pi=pair<int,int>;
using str=string;using vs=vc<str>;
using pqgp=pqg<pi>;
constexpr int inf=1ll<<60,minf=-inf;
constexpr array<pi,8>dc={{{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}};
constexpr array<u32,6> mods{998244353,998244853,1000000007,1000000009,1000000021,1000000033};
template<integral T>inline T ceil(const T a,const T b){return(a+b-1)/b;}
template<integral T>inline T floor(const T a,const T b){return a/b-(a%b&&(a^b)<0);}
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
			if (dst.rdbuf()->sputn(minVal,40)!=40)dst.setstate(std::ios_base::badbit);
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
template<class T>void _getv(T&a){cin>>a;}
template<class T>void _getv(vc<T>&a){iter(x,a)cin>>x;}
template<class T>void _getv(vv<T>&a){iter(y,a)iter(x,y)cin>>x;}
template<class T>void getv(T&a){_getv(a);}
template<class T,class... Ts>void getv(T&a,Ts&... b){_getv(a);getv(b...);}
void _putv(const str&a){cout<<a<<endl;}
void _putv(const vc<str>&a){cter(x,a)cout<<x<<endl;}
template<class T>void _putv(const T&a){cout<<a;}
template<class T>void _putv(const vc<T>&a){cter(x,a)cout<<x<<' ';cout<<endl;}
template<class T>void _putv(const vv<T>&a){cter(y,a){cter(x,y)cout<<x<<' ';cout<<endl;}}
template<class T>void putv(const T&a){_putv(a);cout<<endl;}
template<class T,class... Ts>void putv(const T&a,const Ts&... b){_putv(a);cout<<' ';putv(b...);}
void _putv(const str&&a){_putv(static_cast<const str&>(a));}
void _putv(const vc<str>&&a){_putv(static_cast<const vc<str>&>(a));}
template<class T>void _putv(const T&&a){_putv(static_cast<const T&>(a));}
template<class T>void _putv(const vc<T>&&a){_putv(static_cast<const vc<T>&>(a));}
template<class T>void _putv(const vv<T>&&a){_putv(static_cast<const vv<T>&>(a));}
template<class T>void putv(const T&&a){putv(static_cast<const T&>(a));}
template<class... T>void putv(const T&&... a){(putv(static_cast<const T&>(a)),...);}
template<i32 N,integral T> void putbit(T s,char sep='\n'){
	char buf[N+1]={0};
	for(char*itr=buf+N-1;itr>=buf;itr--,s>>=1)
		*itr='0'+(s&1);
	cout<<buf<<sep;
}
void slv();
int32_t main(){
	cin.tie(0),cout.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(15);
	slv();
}


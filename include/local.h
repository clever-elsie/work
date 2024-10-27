#include <atcoder/modint>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// order_of_key(key)=>get N of (key is Nth);
#define _TP template
#define _CT const
#define _CC constexpr
#define _CS class
#define _NS namespace
#define _US using
#define _IG integral
_US _NS std;
_NS vies=std::views;
_US std::cin;
_US std::cout;
_US sstream=stringstream;
_US _NS atcoder;
_US mint=modint998244353;
_US mint1=modint1000000007;
_US _NS __gnu_pbds;
_TP<_CS s,_CS t>_US __gnu_map=tree<s,t,less<s>,rb_tree_tag,tree_order_statistics_node_update>;
_TP<_CS s,_CS t>struct gnu_map:public __gnu_map<s,t> {
	_US iterator=typename __gnu_map<s, t>::iterator;
	_TP<_IG T>iterator operator[](T i){return this->find_by_order(i);}
};
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
#define I(a,i) begin(a),begin(a)+i
#define elif(c) else if(c)
#define _REP(_1,_2,_3,_4,name,...) name
#define _ITER(_1,_2,_3,name,...) name
#define _REP1(n) while(n--)
#define _REP2(i,n) for(int i=0;i<n;i++)
#define _REP3(i,s,n) for(int i=s;i<n;i++)
#define _REP4(i,s,n,step) for(int i=s;i<n;i+=step)
#define _RREP2(i,n) for(int i=n;i>=0;i--)
#define _RREP3(i,n,t) for(int i=n;i>=t;i--)
#define _RREP4(i,n,t,s) for(int i=n;i>=t;i-=s)
#define _ITER2(x,a) for(auto&x:a)
#define _ITER3(x,y,a) for(auto&[x,y]:a)
#define _CTER2(x,a) for(_CT auto&x:a)
#define _CTER3(x,y,a) for(_CT auto&[x,y]:a)
#define rep(...) _REP(__VA_ARGS__,_REP4,_REP3,_REP2,_REP1)(__VA_ARGS__)
#define rrep(...) _REP(__VA_ARGS__,_RREP4,_RREP3,_RREP2)(_VA_ARGS__)
#define iter(...) _ITER(__VA_ARGS__,_ITER3,_ITER2)(__VA_ARGS__)
#define cter(...) _ITER(__VA_ARGS__,_CTER3,_CTER2)(__VA_ARGS__)
#define acm(a,s) accumulate(A(a),s)
#define uni(a) a.erase(unique(A(a)),a.end())
#define DR(i) views::drop(i)
#define TK(i) views::take(i)
#define RV views::reverse
#define NL cout<<'\n'
_TP<_CS s>_US gnu_set=gnu_map<s,null_type>;
_TP<_CS f>_US vc=vector<f>;
_TP<_CS f>_US vv=vc<vc<f>>;
_TP<_CS f>_US v3=vv<vc<f>>;
_TP<_CS f>_US v4=vv<vv<f>>;
_TP<_CS f>_US gr=greater<f>;
_TP<_CS f>_US pq=priority_queue<f>;
_TP<_CS f>_US pqg=priority_queue<f, vc<f>, gr<f>>;
#define int long long
#define itn long long
#define uset unordered_set
#define umap unordered_map
_US i8=int8_t;
_US u8=uint8_t;
_US i16=int16_t;
_US u16=uint16_t;
_US i32=int32_t;
_US u32=uint32_t;
_US i64=int64_t;
_US u64=uint64_t;
_US intw=__int128_t;
_US uintw=__uint128_t;
_US f32=float;
_US f64=double;
_US vi=vc<int>;
_US vb=vc<bool>;
_US pi=pair<int, int>;
_US str=string;
_US vs=vc<str>;
_US pqgp=pqg<pi>;
_CC int inf=1ll<<60;
_CC int minf=-inf;
_CC array<pi,8>dc={{{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}};
_CC array<u32,6> mods{998244353,998244853,1000000007,1000000009,1000000021,1000000033};
_TP<_IG T>inline T ceil(_CT T a,_CT T b){return(a+b-1)/b;}
_TP<_IG T>inline T floor(_CT T a,_CT T b){return a/b-(a%b&&(a^b)<0);}
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define yn(c) (c)?yes:no
_TP<_CS T>concept Lint=is_integral_v<T>&&sizeof(T)>8;
_TP<Lint T>ostream&operator<<(ostream&dst,T val){
	ostream::sentry s(dst);
	if (!s)return dst;
	char _O128[64];
	bool vsign=val<0;
	if(vsign){
		if(val==numeric_limits<T>::min()) {
			_CT char*minVal="-170141183460469231731687303715884105728";
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
_TP<Lint T>istream&operator>>(istream&src,T&val) {
	str s;src>>s;
	bool is_neg=numeric_limits<T>::is_signed&&s.size()>0&&s[0]=='-';
	for(val=0;_CT auto&x:s|views::drop(is_neg))val=10*val+x-'0';
	if(is_neg)val*=-1;
	return src;
}
#define MUT make_unsigned_t
_TP<_IG T>i32 pcnt(T p){return popcount(MUT<T>(p));}
_TP<_IG T>i32 lsb(T p){return countl_zero(MUT<T>(p));}
_TP<_IG T>i32 msb(T p){return countr_zero(MUT<T>(p));}
void IOset(){
	cin.tie(0),cout.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(15);
}
_TP<_CS T>void getv(vc<T>&a){iter(x,a)cin>>x;}
_TP<_CS T>void getvv(vv<T>&a){iter(y,a)iter(x,y)cin>>x;}
void putv(vc<str>&a){citer(x,a)cout<<x<<endl;}
_TP<_CS T> void putv(vc<T>&a){
	citer(x,a)cout<<x<<' ';
	cout<<endl;
}
_TP<_CS T>void putvv(vv<T>&a){
	citer(y,a){
		citer(x,y)cout<<x<<" ";
		cout<<endl;
	}
}
_TP<i32 N,_IG T> void putbit(T s,char sep='\n'){
	char buf[N+1]={0};
	for(char*itr=buf+N-1;itr>=buf;itr--,s>>=1)
		*itr='0'+(s&1);
	cout<<buf<<sep;
}
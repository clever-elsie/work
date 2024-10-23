#include <atcoder/modint>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// order_of_key(key)=>get N of (key is Nth);
#define _TP template
#define _CT const
#define _CC constexpr
#define _CS class
#define _US using
#define _IG integral
_US namespace std;
namespace vies = std::views;
_US std::cin;
_US std::cout;
_US sstream = stringstream;
_US namespace atcoder;
_US mint = modint998244353;
_US mint1 = modint1000000007;
_US namespace __gnu_pbds;
_TP<_CS s, _CS t> _US __gnu_map = tree<s, t, less<s>, rb_tree_tag, tree_order_statistics_node_update>;
_TP<_CS s, _CS t> struct gnu_map : public __gnu_map<s, t> {
	_US iterator = typename __gnu_map<s, t>::iterator;
	_TP<_IG T> iterator operator[](T i) { return this->find_by_order(i); }
};
#define fi first
#define se second
#define endl '\n'
#define sn(i, c) " \n"[i == c];
#define pf(a) push_front(a)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define ppf() pop_front()
#define ppb() pop_back()
#define pp() pop()
#define ins(a) insert(a)
#define emp(a) emplace(a)
#define mp(f, s) make_pair(f, s)
#define A(a) begin(a), end(a)
#define I(a, i) begin(a), begin(a) + i
#define elif(c) else if(c)
#define rp(i,f,n) for(int i=f;i<n;i++)
#define rps(i,f,n,s) for(int i=f;i<n;i+=s)
#define rrp(i,n,t) for(int i=n;i>=t;i--)
#define rrps(i,n,t,s) for(int i=n;i>=t;i-=s)
#define iter(i,a) for(auto&i:a)
#define citer(i,a) for(const auto&i:a)
_TP<_CS s> _US gnu_set = gnu_map<s, null_type>;
_TP<_CS f> _US vc = vector<f>;
_TP<_CS f> _US vv = vc<vc<f>>;
_TP<_CS f> _US v3 = vv<vc<f>>;
_TP<_CS f> _US v4 = vv<vv<f>>;
_TP<_CS f> _US gr = greater<f>;
_TP<_CS f> _US pq = priority_queue<f>;
_TP<_CS f> _US pqg = priority_queue<f, vc<f>, gr<f>>;
#define int long long
#define itn long long
#define uset unordered_set
#define umap unordered_map
_US i8 = int8_t;
_US u8 = uint8_t;
_US i16 = int16_t;
_US u16 = uint16_t;
_US i32 = int32_t;
_US u32 = uint32_t;
_US i64 = int64_t;
_US u64 = uint64_t;
_US intw = __int128_t;
_US uintw = __uint128_t;
_US f32 = float;
_US f64 = double;
_US vi = vc<int>;
_US vb = vc<bool>;
_US pi = pair<int, int>;
_US str = string;
_US vs = vc<str>;
_US VI = vv<int>;
_US VB = vv<bool>;
_US pqgp = pqg<pi>;
_CC int inf = 1ll << 60;
_CC int minf = -inf;
_CC array<pi, 8> dc = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}};
_CC array<u32, 6> mods{998244353,	998244853, 1000000007, 1000000009, 1000000021, 1000000033};
_TP<_IG T> inline T ceil(_CT T a,_CT T b) { return (a + b - 1) / b; }
_TP<_IG T> inline T floor(_CT T a,_CT T b) { return a / b - (a % b && (a ^ b) < 0); }
_CC void yes(){cout<<"Yes\n";}
_CC void no(){cout<<"No\n";}
void yn(bool c){ c?yes():no(); }
_TP<_CS T> concept Lint = is_integral_v<T> && sizeof(T)>8;
_TP<Lint T> ostream &operator<<(ostream &dst, T val) {
	ostream::sentry s(dst);
	if (!s) return dst;
	char _O128[48];
	bool vsign = val<0;
	if(vsign) val=-val;
	char*d=_O128+128;
	do {
		*(--d) = "0123456789"[val % 10];
		val /= 10;
	} while (val != 0);
	size_t len = _O128+128-d;
	if (vsign) *(--d) = '-', len++;
	if (dst.rdbuf()->sputn(d, len) != len)
		dst.setstate(ios_base::badbit);
	return dst;
}
_TP<Lint T> istream &operator>>(istream &src, T &val) {
	str s;src>>s;
	bool is_neg=numeric_limits<T>::is_signed&&s.size()>0&&s[0]=='-';
	for(val=0;_CT auto&x:s|views::drop(is_neg)){
		// assert('0'<=x&&x<='9');
		val=10*val+x-'0';
	}
	if (is_neg) val*=-1;
	return src;
}
#define MUT make_unsigned_t
_TP<_IG T> i32 pcnt(T p){ return popcount(MUT<T>(p)); }
_TP<_IG T> i32 lsb(T p){ return countl_zero(MUT<T>(p)); }
_TP<_IG T> i32 msb(T p){ return countr_zero(MUT<T>(p)); }
void IOset(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(15);
}
_TP<_CS T> void getv(vc<T> &a) { iter(x, a) cin >> x; }
_TP<_CS T> void getvv(vv<T> &a) { iter(y, a) iter(x, y) cin >> x; }
void putv(vc<str> &a) { citer(x, a) cout << x << endl; }
_TP<_CS T> void putv(vc<T> &a) {
	citer(x, a) cout << x << ' ';
	cout << endl;
}
_TP<_CS T> void putvv(vv<T> &a) {
	citer(y, a) {
		citer(x, y) cout << x << " ";
		cout << endl;
	}
}
_TP<i32 N,_IG T> void putbit(T s,char sep='\n'){
	char buf[N+1]={0};
	for(char*itr=buf+N-1;itr>=buf;itr--,s>>=1)
		*itr='0'+(s&1);
	cout<<buf<<sep;
}
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// order_of_key(key)=>get N of (key is Nth);
#define _TP template
#define _CT const
#define _CC constexpr
#define _US using
_US namespace std;
namespace vies = std::views;
_US std::cin;
_US std::cout;
_US sstream = stringstream;
_US namespace atcoder;
_US mint = modint998244353;
_US mint1 = modint1000000007;
_US namespace __gnu_pbds;
_TP<class s, class t> _US __gnu_map = tree<s, t, less<s>, rb_tree_tag, tree_order_statistics_node_update>;
_TP<class s, class t> struct gnu_map : public __gnu_map<s, t> {
	_US iterator = typename __gnu_map<s, t>::iterator;
	_TP<integral T> iterator operator[](T i) { return this->find_by_order(i); }
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
_TP<class s> _US gnu_set = gnu_map<s, null_type>;
_TP<class f> _US vc = vector<f>;
_TP<class f> _US vv = vc<vc<f>>;
_TP<class f> _US v3 = vv<vc<f>>;
_TP<class f> _US v4 = vv<vv<f>>;
_TP<class f> _US gr = greater<f>;
_TP<class f> _US pq = priority_queue<f>;
_TP<class f> _US pqg = priority_queue<f, vc<f>, gr<f>>;
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
_CC str yes{"Yes\n"};
_CC str no{"No\n"};
_CC int inf = 1ll << 60;
_CC int minf = -inf;
_CC array<pi, 8> dc = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}};
_CC array<unsigned, 6> mods{998244353,	998244853, 1000000007, 1000000009, 1000000021, 1000000033};
inline int ceil(_CT int a, const int b) { return (a + b - 1) / b; }
inline int floor(const int a, const int b) { return a / b - (a % b && (a ^ b) < 0); }
_TP<class T> concept Lint = is_integral_v<T> && sizeof(T)>8;
static char _O128B[128];
pair<char*, ssize_t> _O128(uintw tmp) {
	char*d=end(_O128B);
	do {
		*(--d) = "0123456789"[tmp % 10];
		tmp /= 10;
	} while (tmp != 0);
	return {d,end(_O128B) - d};
}
_TP<Lint T>
ostream &operator<<(ostream &dst, T val) {
	ostream::sentry s(dst);
	if (s) {
		auto [d, len] = _O128(val < 0 ? -val : val);
		if (val < 0)
			*(--d) = '-', len++;
		if (dst.rdbuf()->sputn(d, len) != len)
			dst.setstate(ios_base::badbit);
	}
	return dst;
}
_TP<Lint T>
istream &operator>>(istream &src, T &val) {
	str s;src>>s;
	bool is_neg=numeric_limits<T>::is_signed&&s.size()>0&&s[0]=='-';
	for(val=0;const auto&x:s|views::drop(is_neg)){
		// assert('0'<=x&&x<='9');
		val=10*val+x-'0';
	}
	if (is_neg) val*=-1;
	return src;
}

#define MUT make_unsigned_t
_TP<integral T> int pcnt(T p){ return popcount(MUT<T>(p)); }
_TP<integral T> int lsb(T p){ return countl_zero(MUT<T>(p)); }
_TP<integral T> int msb(T p){ return countr_zero(MUT<T>(p)); }

void IOset(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(15);
}
_TP<class T>void getv(vc<T>&a){ for(auto&x:a)cin>>x; }
void putv(vc<str>&a){ for(const auto&x:a) cout<<x<<endl; }
_TP<class T>void putv(vc<T>&a){ for(const auto&x:a)cout<<x<<" "; cout<<endl; }
_TP<class T>void putvv(vv<T>&a){
	for(const auto&row:a){
		for(const auto&el:row)
			cout<<el<<" ";
		cout<<endl;
	}
}
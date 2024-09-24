// include headers
// IO
#include<iostream> // cin, cout
#include<iomanip> // setprecision
#include<ios> // fixed, ios_base->sync_with_stdio
#include<sstream> // stringstream
// data structure
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<queue>
#include<stack>
#include<utility> // pair, make_pair, tuple, swap
#include<tuple>
// frequently uses
#include<algorithm>
#include<ranges> // sort, unique, reverse, lower_bound, upper_bound, min, max, next_permutation
#include<numbers> // pi, e, inv_pi
#include<numeric> // iota, gcd, lcm, midpoint, accumulate
#include<cmath> // sin, asin, sinh, exp, log, sqrt, abs, fma, 
#include<chrono> // chrono::high_resolution_clock::now(); chrono::duration_cast<chrono::milliseconds>(ed-st).count();
#include<random> // random_device seed; mt19937_64 gen(seed());
// needed def
#include<cstddef> // size_t
#include<cstdint> // intN_t, uintN_t
#include<atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
using mint1 = modint1000000007;
using namespace std;
namespace vies=std::views;
using std::cin;
using std::cout;
using sstream = stringstream;
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
#define mp(f,s) make_pair(f,s)
#define A(a) begin(a), end(a)
#define I(a,i) begin(a),begin(a)+i
#define int int64_t
// typo def
#define itn int64_t
#define strs str s
template <class f> using vc = vector<f>;
template <class f> using vv = vc<vc<f>>;
template <class f> using v3 = vv<vc<f>>;
template <class f> using v4 = vv<vv<f>>;
template <class f> using gr = greater<f>;
template <class f> using pq = priority_queue<f>;
template <class f> using pqg = priority_queue<f, vc<f>, gr<f>>;
template <class Key, class Hash = hash<Key>, class Pred = equal_to<Key>, class Allocator = allocator<Key>>
using uset = unordered_set<Key, Hash, Pred, Allocator>;
template <class Key, class T, class Hash = hash<Key>, class Pred = equal_to<Key>, class Allocator = allocator<pair<const Key, T>>>
using umap = unordered_map<Key, T, Hash, Pred, Allocator>;
using str = string;
using vi = vc<int>;
using vb = vc<bool>;
using pi = pair<int, int>;
using vs = vc<str>;
using si = set<int>;
using mi = map<int,int>;
using pqgp = pqg<pi>;
using VI = vv<int>;
using VB = vv<bool>;
using intw = __int128_t;
using uintw = __uint128_t;
constexpr str yes{"Yes\n"}, no{"No\n"};
constexpr int inf = 1ll<<60, minf = -inf;
const vc<pi>dc={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
inline int ceil(const int a,const int b){ return (a+b-1)/b; }
inline int floor(const int a,const int b){ return a/b-(a%b&&(a^b)<0); }

ostream& operator<<(ostream&dst,intw val){
	ostream::sentry s(dst);
	if(s){
		__int128_t tmp = val < 0 ? -val : val;
		char buf[128]={'\0'};
		char *d = std::end(buf);
		do{
			*(--d) = "0123456789"[tmp % 10];
			tmp /= 10;
		}while(tmp!=0);
		if(val<0) *(--d) = '-';
		int len = std::end(buf)-d;
		if(dst.rdbuf()->sputn(d,len)!=len)
			dst.setstate(ios_base::badbit);
	}
	return dst;
}
ostream& operator<<(ostream&dst,uintw val){
	ostream::sentry s(dst);
	if(s){
		char buf[128]={'\0'};
		char *d = std::end(buf);
		do{
			*(--d) = "0123456789"[val % 10];
			val /= 10;
		}while(val!=0);
		int len = std::end(buf)-d;
		if(dst.rdbuf()->sputn(d,len)!=len)
			dst.setstate(ios_base::badbit);
	}
	return dst;
}

istream& operator>>(istream&src,uintw&val){
	val=0;
	str s;cin>>s;
	for(size_t i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			val = 10*val + s[i]-'0';
		else {
			val = 0;
			break;
		}
	return src;
}

istream& operator>>(istream&src,intw&val){
	val=0;
	str s;cin>>s;
	bool is_neg = s.size() > 0 && s[0] == '-';
	for(size_t i=is_neg;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			val = 10*val + s[i]-'0';
		else {
			val = 0;
			break;
		}
	if(is_neg) val*=-1;
	return src;
}
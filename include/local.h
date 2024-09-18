#include<iostream>
#include<iomanip>
#include<sstream>
#include<ios>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<tuple>
#include<algorithm>
#include<ranges>
#include<numbers>
#include<numeric>
#include<cmath>
#include<cstddef>
#include<cstdint>
#include<chrono>
#include<random>
#include<atcoder/modint>
#include<atcoder/lazysegtree>
using namespace atcoder;
using mint = modint998244353;
using mint1 = modint1000000007;
template <class S> struct sum_lst { S val; size_t size; sum_lst(S a, size_t b) : val(a), size(b) {} };
template <class S, class F> using add_max_lst = lazy_segtree<S, [](S a, S b) { return (a > b ? a : b); }, []() -> S { return -(1ll << 62); }, F, [](F f, S x) { return x + f; }, [](F f, F g) { return g + f; }, []() -> F { return 0; }>;
template <class S, class F> using add_min_lst = lazy_segtree<S, [](S a, S b) { return (a < b ? a : b); }, []() -> S { return 1ll << 62; }, F, [](F f, S x) { return x + f; }, [](F f, F g) { return g + f; }, []() -> F { return 0; }>;
template <class S, class F> using add_sum_lst = lazy_segtree<sum_lst<S>, [](sum_lst<S> a, sum_lst<S> b) -> sum_lst<S> { return sum_lst<S>(a.val + b.val, a.size + b.size); }, []() -> sum_lst<S> { return sum_lst<S>((S)0, 0ull); }, F, [](F f, sum_lst<S> x) -> sum_lst<S> { return sum_lst<S>(x.val + f * x.size, x.size); }, [](F f, F g) { return g + f; }, []() -> F { return 0; }>;
template <class S, class F> using ch_max_lst = lazy_segtree<S, [](S a, S b) { return (a > b ? a : b); }, []() -> S { return -(1ll << 62); }, F, [](F f, S x) -> S { return (f == -(1ll << 62) ? x : f); }, [](F f, F g) -> F { return (f == -(1ll << 62) ? g : f); }, []() -> F { return -(1ll << 62); }>;
template <class S, class F> using ch_min_lst = lazy_segtree<S, [](S a, S b) { return (a < b ? a : b); }, []() -> S { return 1ll << 62; }, F, [](F f, S x) -> S { return (f == (1ll << 62) ? x : f); }, [](F f, F g) -> F { return (f == (1ll << 62) ? g : f); }, []() -> F { return 1ll << 62; }>;
template <class S, class F> using ch_sum_lst = lazy_segtree<sum_lst<S>, [](sum_lst<S> a, sum_lst<S> b) -> sum_lst<S> { return sum_lst<S>(a.val + b.val, a.size + b.size); }, []() -> sum_lst<S> { return sum_lst<S>((S)0, 0ull); }, F, [](F f, sum_lst<S> x) -> sum_lst<S> { if (f != (1ll << 62)) x.val = f * x.size; return x; }, [](F f, F g) { return (f == (1ll << 62) ? g : f); }, []() -> F { return 1ll << 62; }>;
using namespace std;
namespace vies=std::views;
using std::cin;
using std::cout;
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
template <class f> using vc = vector<f>;
template <class f> using vv = vc<vc<f>>;
template <class f> using v3 = vv<vc<f>>;
template <class f> using v4 = vv<vv<f>>;
template <class f> using gr = greater<f>;
template <class f> using pq = priority_queue<f>;
template <class f> using pqg = priority_queue<f, vc<f>, gr<f>>;
#define int long long
using str = string;
using vi = vc<int>;
using VI = vv<int>;
using vb = vc<bool>;
using VB = vv<bool>;
using pi = pair<int, int>;
using vs = vc<str>;
using si = set<int>;
using mi = map<int,int>;
using pqgp = pqg<pi>;
constexpr str yes{"Yes\n"}, no{"No\n"};
constexpr int inf = 1ll<<60, minf = -inf;
const vc<pi>dc={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
inline int ceil(const int a,const int b){ return (a+b-1)/b; }
inline int floor(const int a,const int b){ return a/b-(a%b&&(a^b)<0); }

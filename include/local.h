#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
namespace vies=std::views;
using std::cin;
using std::cout;
using namespace atcoder;
using mint = modint998244353;
using mint1 = modint1000000007;
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
template <class f> using uset = unordered_set<f>;
template <class f> using umultiset = unordered_multiset<f>;
template <class f,class t> using umap = unordered_map<f,t>;
template <class f,class t> using umultimap = unordered_multimap<f,t>;
#define int long long
using vi = vc<int>;
using vb = vc<bool>;
using pi = pair<int, int>;
using str = string;
using vs = vc<str>;
constexpr str yes{"Yes\n"}, no{"No\n"};
constexpr int inf = 1ll<<60, minf = -inf;
const vc<pi>dc={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
inline int ceil(int a,int b){ return (a+b-1)/b; }
inline int floor(int a,int b){ return a/b-(a%b&&(a^b)<0); }

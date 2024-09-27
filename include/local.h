#include<bits/stdc++.h>
using namespace std;
namespace vies=std::views;
using std::cin;
using std::cout;
using sstream = stringstream;
#include<atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
using mint1 = modint1000000007;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// random iteratorable
// order_of_key(key) -> get N of (key is Nth);
using namespace __gnu_pbds;
template <class s,class t>
using __gnu_map = tree<s,t,less<s>,rb_tree_tag,tree_order_statistics_node_update>;
template <class s,class t> struct gnu_map:public __gnu_map<s,t> {
	using iterator = typename __gnu_map<s,t>::iterator;
	template <integral T>
	iterator operator[](T i){ return this->find_by_order(i); }
};
template <class s> using __gnu_set = gnu_map<s,null_type>;
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
#define itn int64_t
#define uset unordered_set
#define umap unordered_map
template<class f>using vc=vector<f>;template<class f>using vv=vc<vc<f>>;template<class f>using v3=vv<vc<f>>;template<class f>using v4=vv<vv<f>>;template<class f>using gr=greater<f>;template<class f>using pq=priority_queue<f>;template<class f>using pqg=priority_queue<f,vc<f>,gr<f>>;using vi=vc<int>;using vb=vc<bool>;using pi=pair<int,int>;using str=string;using vs=vc<str>;using VI=vv<int>;using VB=vv<bool>;using pqgp=pqg<pi>;using intw=__int128_t;using uintw=__uint128_t;
constexpr str yes{"Yes\n"};
constexpr str no{"No\n"};
constexpr int inf=1ll<<60;
constexpr int minf=-inf;
constexpr array<pi,8>dc={{{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}};
constexpr array<unsigned,6> mods{998244353,998244853,1000000007,1000000009,1000000021,1000000033};
inline int ceil(const int a,const int b){ return (a+b-1)/b; }
inline int floor(const int a,const int b){ return a/b-(a%b&&(a^b)<0); }
char __ofs128_buf[128];
pair<char*,size_t>__set_ofs128(uintw tmp){char *d=std::end(__ofs128_buf);do{*(--d) = "0123456789"[tmp % 10];tmp /= 10;}while(tmp!=0);return {d,std::end(__ofs128_buf)-d};}
ostream&operator<<(ostream&dst,intw val){ostream::sentry s(dst);if(s){auto[d,len]=__set_ofs128(val<0?-val:val);if(val<0)*(--d)='-',len++;if(dst.rdbuf()->sputn(d,len)!=len)dst.setstate(ios_base::badbit);}return dst;}
ostream&operator<<(ostream&dst,uintw val){ostream::sentry s(dst);if(s){auto[d,len]=__set_ofs128(val);if(dst.rdbuf()->sputn(d,len)!=len)dst.setstate(ios_base::badbit);}return dst;}
template<integral T>void __get_ifs128(str&s,size_t i,T&val)requires(sizeof(T)>8){for(;i<s.size();i++)if('0'<=s[i]&&s[i]<='9')val=10*val+s[i]-'0';else{val=0;break;}}
istream&operator>>(istream&src,uintw&val){val=0;str s;cin>>s;__get_ifs128(s,0,val);return src;}
istream& operator>>(istream&src,intw&val){val=0;str s;cin>>s;bool is_neg=s.size()>0&&s[0]=='-';__get_ifs128(s,is_neg,val);if(is_neg)val*=-1;return src;}

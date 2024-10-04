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
_TP<class s> _US gnu_set = gnu_map<s, null_type>;
_TP<class f> _US vc = vector<f>;
_TP<class f> _US vv = vc<vc<f>>;
_TP<class f> _US v3 = vv<vc<f>>;
_TP<class f> _US v4 = vv<vv<f>>;
_TP<class f> _US gr = greater<f>;
_TP<class f> _US pq = priority_queue<f>;
_TP<class f> _US pqg = priority_queue<f, vc<f>, gr<f>>;
#define int int64_t
#define itn int64_t
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
static char _O128B[128];
pair<char*, size_t> _O128(uintw tmp) {
	char*d=end(_O128B);
	do {
		*(--d) = "0123456789"[tmp % 10];
		tmp /= 10;
	} while (tmp != 0);
	return {d,end(_O128B) - d};
}
ostream &operator<<(ostream &dst, intw val) {
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
ostream &operator<<(ostream &dst, uintw val) {
	ostream::sentry s(dst);
	if (s) {
		auto [d, len] = _O128(val);
		if (dst.rdbuf()->sputn(d, len) != len)
			dst.setstate(ios_base::badbit);
	}
	return dst;
}
_TP<integral T> void _I128(str &s, size_t i, T &val) requires(sizeof(T) > 8) {
	for(val=0;const auto&x:s|views::drop(i)){
		assert('0'<=x&&x<='9');
		val=10*val+x-'0';
	}
}
istream &operator>>(istream &src, uintw &val) {
	str s;cin>>s;
	_I128(s, 0, val);
	return src;
}
istream &operator>>(istream &src, intw &val) {
	str s;cin>>s;
	bool is_neg=s.size()>0&&s[0]=='-';
	_I128(s, is_neg, val);
	if (is_neg) val*=-1;
	return src;
}
#define UINT unsigned_integral
#define SINT signed_integral
#define MUT make_unsigned_t
#define PPCNT popcount
#define MSB countl_zero
#define LSB countr_zero
_TP<UINT T> int pcnt(T p){ return PPCNT(p); }
_TP<SINT T> int pcnt(T p){ return PPCNT(MUT<T>(p)); }
_TP<UINT T> int zcnt(T p){ return MSB(p); }
_TP<SINT T> int zcnt(T p){ return MSB(MUT<T>(p)); }
_TP<UINT T> int lsb(T p){ return LSB(p); }
_TP<SINT T> int lsb(T p){ return LSB(MUT<T>(p)); }

namespace elsie_IO{
	constexpr array<int32_t,5> ten_power{1,10,100,1000,10000};
	constexpr int32_t trans_IN[][10]={
		{0,1000,2000,3000,4000,5000,6000,7000,8000,9000},
		{0,100,200,300,400,500,600,700,800,900},
		{0,10,20,30,40,50,60,70,80,90},
		{0,1,2,3,4,5,6,7,8,9}
	};
	union flip{
		int32_t sig;
		uint32_t dat;
	};
	template <class T>
	concept signed_INT = signed_integral<T>&&!same_as<T, char>;
	template <class T>
	concept unsigned_INT = unsigned_integral<T>&&!same_as<T, char>;
	constexpr size_t bsize = 1024*1024*16;
	char ib[bsize];
	class CIO{
		private:
		ssize_t ic,oc,last;
		ssize_t readbuf(){
			last=read(STDIN_FILENO,ib,bsize);
			ic=0;
			if(last>0)ib[last]=127;
			return last;
		}
		public:
		CIO(){ ic=oc=last=0; }
		CIO&operator>>(char&v){
			do{
				if(ic==last)
				if((last=readbuf())<=0)
					return *this;
				v=ib[ic++];
			}while(v<=' ');
			return *this;
		}
		CIO&operator>>(string&v){
			v.clear();
			if(ic==last)
				if((last=readbuf())<=0)
					return *this;
			while(ib[ic]<=' '){
				ic++;
				if(ic==last)
					if((last=readbuf())<=0)
						return *this;
			}
			size_t L=ic;
			while(ib[ic]>' '){
				ic++;
				if(ic==last){
					v.insert(v.end(),ib+L,ib+last);
					if((last=readbuf())<=0)
						return *this;
					L=0;
				}
			}
			if(ic-L>1) v.insert(v.end(),ib+L,ib+ic);
			return *this;
		}
		template<unsigned_INT T>
		CIO&operator>>(T&v){
			flip s;
			v=0;
			int32_t buf[4];
			size_t cache=0;
			do{
				if(ic==last)
				if((last=readbuf())<=0)
					return*this;
				s.sig=ib[ic]-'0';
				if(s.dat<10)break;
			}while(++ic);
			do{
				if(ic==last)
				if((last=readbuf())<=0)
					return*this;
				s.sig=ib[ic]-'0';
				if(s.dat>9){
					if(cache){
						v*=ten_power[cache];
						for(int i=4-cache,j=0;i<4;i++,j++)
							v+=trans_IN[i][buf[j]];
					}
					break;
				}
				buf[cache++]=s.dat;
				if(cache==4){
					v*=10000;
					for(int i=0;i<4;i++)
						v+=trans_IN[i][buf[i]];
					cache=0;
				}
			}while(++ic);
			return *this;
		}
		template<signed_INT T>
		CIO&operator>>(T&v){
			flip s;
			bool minus=false;
			v=0;
			int32_t buf[4];
			size_t cache=0;
			do{
				if(ic==last)
				if((last=readbuf())<=0)
					return*this;
				if(ib[ic]=='-'){
					minus=true;
					ic++;
					break;
				}
				s.sig=ib[ic]-'0';
				if(s.dat<10)break;
			}while(++ic);
			do{
				if(ic==last)
				if((last=readbuf())<=0)
					return*this;
				s.sig=ib[ic]-'0';
				if(s.dat>9){
					if(cache){
						v*=ten_power[cache];
						for(int i=4-cache,j=0;i<4;i++,j++)
							v+=trans_IN[i][buf[j]];
						if(minus)v=-v;
					}
					break;
				}
				buf[cache++]=s.dat;
				if(cache==4){
					v*=10000;
					for(int i=0;i<4;i++)
						v+=trans_IN[i][buf[i]];
					cache=0;
				}
			}while(++ic);
			return *this;
		}
	};
}
elsie_IO::CIO cio;
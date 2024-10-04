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
	//constexpr char transOUT[][4]={"000","100","200","300","400","500","600","700","800","900","010","110","210","310","410","510","610","710","810","910","020","120","220","320","420","520","620","720","820","920","030","130","230","330","430","530","630","730","830","930","040","140","240","340","440","540","640","740","840","940","050","150","250","350","450","550","650","750","850","950","060","160","260","360","460","560","660","760","860","960","070","170","270","370","470","570","670","770","870","970","080","180","280","380","480","580","680","780","880","980","090","190","290","390","490","590","690","790","890","990","001","101","201","301","401","501","601","701","801","901","011","111","211","311","411","511","611","711","811","911","021","121","221","321","421","521","621","721","821","921","031","131","231","331","431","531","631","731","831","931","041","141","241","341","441","541","641","741","841","941","051","151","251","351","451","551","651","751","851","951","061","161","261","361","461","561","661","761","861","961","071","171","271","371","471","571","671","771","871","971","081","181","281","381","481","581","681","781","881","981","091","191","291","391","491","591","691","791","891","991","002","102","202","302","402","502","602","702","802","902","012","112","212","312","412","512","612","712","812","912","022","122","222","322","422","522","622","722","822","922","032","132","232","332","432","532","632","732","832","932","042","142","242","342","442","542","642","742","842","942","052","152","252","352","452","552","652","752","852","952","062","162","262","362","462","562","662","762","862","962","072","172","272","372","472","572","672","772","872","972","082","182","282","382","482","582","682","782","882","982","092","192","292","392","492","592","692","792","892","992","003","103","203","303","403","503","603","703","803","903","013","113","213","313","413","513","613","713","813","913","023","123","223","323","423","523","623","723","823","923","033","133","233","333","433","533","633","733","833","933","043","143","243","343","443","543","643","743","843","943","053","153","253","353","453","553","653","753","853","953","063","163","263","363","463","563","663","763","863","963","073","173","273","373","473","573","673","773","873","973","083","183","283","383","483","583","683","783","883","983","093","193","293","393","493","593","693","793","893","993","004","104","204","304","404","504","604","704","804","904","014","114","214","314","414","514","614","714","814","914","024","124","224","324","424","524","624","724","824","924","034","134","234","334","434","534","634","734","834","934","044","144","244","344","444","544","644","744","844","944","054","154","254","354","454","554","654","754","854","954","064","164","264","364","464","564","664","764","864","964","074","174","274","374","474","574","674","774","874","974","084","184","284","384","484","584","684","784","884","984","094","194","294","394","494","594","694","794","894","994","005","105","205","305","405","505","605","705","805","905","015","115","215","315","415","515","615","715","815","915","025","125","225","325","425","525","625","725","825","925","035","135","235","335","435","535","635","735","835","935","045","145","245","345","445","545","645","745","845","945","055","155","255","355","455","555","655","755","855","955","065","165","265","365","465","565","665","765","865","965","075","175","275","375","475","575","675","775","875","975","085","185","285","385","485","585","685","785","885","985","095","195","295","395","495","595","695","795","895","995","006","106","206","306","406","506","606","706","806","906","016","116","216","316","416","516","616","716","816","916","026","126","226","326","426","526","626","726","826","926","036","136","236","336","436","536","636","736","836","936","046","146","246","346","446","546","646","746","846","946","056","156","256","356","456","556","656","756","856","956","066","166","266","366","466","566","666","766","866","966","076","176","276","376","476","576","676","776","876","976","086","186","286","386","486","586","686","786","886","986","096","196","296","396","496","596","696","796","896","996","007","107","207","307","407","507","607","707","807","907","017","117","217","317","417","517","617","717","817","917","027","127","227","327","427","527","627","727","827","927","037","137","237","337","437","537","637","737","837","937","047","147","247","347","447","547","647","747","847","947","057","157","257","357","457","557","657","757","857","957","067","167","267","367","467","567","667","767","867","967","077","177","277","377","477","577","677","777","877","977","087","187","287","387","487","587","687","787","887","987","097","197","297","397","497","597","697","797","897","997","008","108","208","308","408","508","608","708","808","908","018","118","218","318","418","518","618","718","818","918","028","128","228","328","428","528","628","728","828","928","038","138","238","338","438","538","638","738","838","938","048","148","248","348","448","548","648","748","848","948","058","158","258","358","458","558","658","758","858","958","068","168","268","368","468","568","668","768","868","968","078","178","278","378","478","578","678","778","878","978","088","188","288","388","488","588","688","788","888","988","098","198","298","398","498","598","698","798","898","998","009","109","209","309","409","509","609","709","809","909","019","119","219","319","419","519","619","719","819","919","029","129","229","329","429","529","629","729","829","929","039","139","239","339","439","539","639","739","839","939","049","149","249","349","449","549","649","749","849","949","059","159","259","359","459","559","659","759","859","959","069","169","269","369","469","569","669","769","869","969","079","179","279","379","479","579","679","779","879","979","089","189","289","389","489","589","689","789","889","989","099","199","299","399","499","599","699","799","899","999"};
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
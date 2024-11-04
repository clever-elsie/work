# AtCoder用環境
## 前提条件
WSL2-Ubuntu22.04 or later
## 使い方
プログラムファイル`work/shm/a.cpp`  
テスト生成ファイル`work/shm/b.cpp`  
メインは`n,c,t`。  
`#include <local.h>`を`~/work/include/local.h`の中身で置き換える。半角スペースは必須。
`b.cpp`では出力ファイルを`shm/in`にすると`T`で時間を測れる。
コマンドリスト
```
	n   : a.cppをテンプレファイルに初期化
	e   : a.cppを開く(初期化しない)
	c   : a.cppをクリップボードにコピー
	m   : a.outを実行(コンパイルは必要なら自動で行う)
	g   : a.cppをデバッグコンパイルして実行
	t   : a.outですべての登録されているテストを実行(同上)
	r   : b.cppを開く
	gen : b.cppから入力生成する。
	s   : 手動でサンプル登録する。
	T   : 実行時間を計測する
	in  : 実行時間計測用の入力ファイルを開く
	out : 実行時間計測用の出力ファイルを開く
	acl : ACLをAtCoder以外でも使えるように展開する
```
## 環境構築
include/setup.shから必要な部分をコメント外しして、環境を構築する。  
- gcc, g++
- make  
	コマンドの省略に用いる
- nginx  
	テストケースを登録するサーバーに使う
- CrowCpp  
	サーバープログラムに必要なライブラリ  
	ビルドに以下が必要
	- libasio-dev
	- cmake
- ac-library  
	AtCoderで使えるライブラリ
- lib_Clever_Elsie  
	現在非公開  
	コードスニペットなので必要ない  

`tools`のmakeはサーバー以外のすべてのツールのビルドをする。  
`server`のmakeはCrowが正しくビルドされていないと失敗する。  
`ln -s /dev/shm/ ../shm`は確認した限り正しく動作しない。  
意図は伝わると思うが明示しておくと、work直下に`/dev/shm`へのシンボリックリンクを追加する。  
`echo`の部分は動作確認をしていない。  
`vim`などで直接記述したほうが良い。  
サーバーを使うために`include/tools/server`にある`default`の内容を`/etc/nginx/sites-available/default`に重複部分を除いてコピーする。  
そのために`default`には必要最小限のことのみを書いているが、`nginx`側の`default`の内容を削除する必要はない。  
`include/tools/server`にある`code_test.service`は`/etc/systemd/system`の中にコピーして`sudo systemctl enable code_test && sudo systemctl start code_test`とすると、サーバープログラムが有効になる。  
`~/.bashrc`に以下を記述し、`source ~/.bashrc`する。
```
export PS1="\[\e[1;32m\]\w \[\e[0m\]\$"
alias cls='clear'
alias n='make n;cls'
alias c='make c'
alias e='make e'
alias g='make g'
alias m='cls;make;'
alias r='make rand_gen_file'
alias gen='make gen'
alias t='cls;make test'
alias s='make sample_in'
alias in='make in'
alias out='make out'
alias T='time /dev/shm/a.out </dev/shm/in >/dev/shm/out'
alias acl='make acl'
```

## local.h
### 型エイリアス
|型|説明|
|-|-|
|int, itn|long long|
|str|string|
|pi|pair\<int,int\>|
|mint|modint998244353|
|mint1|modint1000000007|
|intw|__int128_t|
|uintw|__uint128_t|
|vc\<T\>|vector\<T\>|
|vv\<T\>|2重vector|
|v3\<T\>|3重vector|
|v4\<T\>|4重vector|
|vi|vector\<int\>|
|pq\<T\>|最大priority_queue<\T\>|
|pqg\<T\>|最小priority_queue\<T\>|
|pqgp|pi最小priority_queue|
|gr\<T\>|greater\<T\>|
|gnu_set\<T\>|乱択可能set(0-based operator[])|
|gnu_map\<T\>|乱択可能map(0-based operator[])|
|uset|unordered_set|
|umap|unordered_map|
|i[8-64]|signed integral|
|u[8-64]|unsigned integral|
|f[32,64]|floating-point|
|sstream|stringstream|

### 省略可能名前空間
+ std
+ atcoder
+ __gnu_pbds
+ vies = std::views
### define
|省略名|本体|
|-|-|
|fi|first : pair|
|se|second : pair|
|endl|'\n'|
|RV|views::reverse|
|IOTA|views::iota|
|NL|cout<<'\n'|

### define()
|省略名|本体|
|-|-|
|sn(2)|" \n"[1==2]|
|pf,pb(1)|push_(back,front)(1)|
|eb(1)|emplace_back(1)|
|ppf,ppb,pp|pop(_front,_back)()|
|ins(1)|insert(1)|
|emp(1)|emplace(1)|
|cont(1)|contains(1)|
|mp(2)|make_pair(1,2)|
|A(1)|[begin,end)|
|I(2)|[begin,+i)|
|elif(1)|else if(1)|
|rep(...)|次節|
|rrep(...)|次節|
|iter(...)|次節|
|cter(...)|次節|
|acm(2)|配列の総和|
|nxpm(1)|順列全探索|
|uni(1)|ソート済みから座圧|
|DR(1)|views::drop(1)|
|TK(1)|views::take(1)|
|yn(1)|1?yes:no|

### rep,rrep,iter,cter
#### rep
|n変数|内容|
|-|-|
|1|引数で与えられた数の繰り返し|
|2|_1の変数を[0,_2)で++イテレート|
|3|_1の変数を[_2,_3)で++イテレート|
|4|_1の変数を[_2,_3)で+=_4|
#### rrep
|n変数|内容|
|-|-|
|1|引数で与えられた数の繰り返し|
|2|_1の変数を[0,_2]で--イテレート|
|3|_1の変数を[_2,_3]で--イテレート|
|4|_1の変数を[_2,_3]で-=_4|
#### iter
|iter||
|-|-|
|2引数|for(auto&1:2) viewsのチェインは可能|
|3引数|for(auto&[1,2]:3)|
#### cter
iterのconst版

### 定義済み定数
|変数名|内容|
|-|-|
|inf|$2^{60}$|
|minf|$-2^{60}$|
|dc : vc\<pi\>|右下左上、右下、右上、左下、左上|
|mods : vc\<u32\>|998244353, 998244853, 1e9+7, 1e9+9, 1e9+21, 1e9+33|
|yes|cout<<"Yes\n"|
|no|cout<<"No\n"|

### 定義済み関数
|関数名|内容|
|-|-|
|main()|cin,coutを高速化してslv()をcall|
|slv()|ここに解答を書く|
|ceil(2)|_1/_2の天井関数|
|floor(2)|_1/_2の床関数|
|chmax(2)|_1に大きい方を代入|
|chmin(2)|_1に小さい方を代入|
|pcnt(1)|popcount|
|lsb(1)|最左ビット|
|msb(1)|最右ビット|
|getv(...)|前から順にstdinから受け取る。組込み型とstr,pair及びそれらのvc,vv|
|putv(...)|stdoutに空白区切りで出力。stringとvectorは出力後改行。組込み型とstr及び、それらのvc,vv,set(multi,gnu)|
|putbit\<N\>(1)|N桁のビットを出力|
|iostream operator<<,>>|128bit出力可能、速度は不明|

### 定義済み宣言
INT(...) intを宣言して入力を受け取る
STR(...) stringを宣言して入力を受け取る
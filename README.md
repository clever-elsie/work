# AtCoder用環境
## 前提条件
WSL2-Ubuntu22.04 or later
## 使い方
プログラムファイル`shm/a.cpp`  
テスト生成ファイル`shm/b.cpp`  
メインは`n,c,t`。  
`#include <local.h>`を`include/local.h`の中身で置き換える。  
事前に設定したライブラリのディレクトリに一致するファイル名が有れば，それを自動展開する．ただしACLを除く．  
このディレクトリからの相対パスをハードコーディングしているので，Makefileの`-I`の部分と，`include/tools/src/macro.cpp`の`library_dir`を書き換える必要がある．  
`b.cpp`では出力ファイルを`shm/in`にすると`T`で時間を測れる。  

コマンドリスト
```
	n   : a.cppをテンプレファイルに初期化
	e   : a.cppを開く(初期化しない)
	c   : a.cppをクリップボードにコピー．include/local.hに加えて，自分のライブラリを設定すると自動展開する．
	t   : cを実行後、a.outですべての登録されているテストを実行(同上)
	m   : a.outを実行(コンパイルは必要なら自動で行う)
	g   : a.cppをデバッグコンパイルして実行
	z   : コンパイル
	r   : b.cppを開く
	gen : b.cppから入力生成する。b.cppでcoutはshm/inにリダイレクトされる。
	s   : 手動でサンプル登録する。
	T   : 実行時間を計測する
	in  : 実行時間計測用の入力ファイルを開く
	out : 実行時間計測用の出力ファイルを開く
	acl : ACLをAtCoder以外でも使えるように展開する
	lib : `tools/src/precompile.cpp`で設定したライブラリの中にある`.hpp`ファイルをプリコンパイルする．`.cpp`の変更が`.hpp.gch`の作成より後に発生していれば実行される．エラーは`/dev/shm/out`に出力．
	ojt : online-judge-toolsを用いてtestを行うshm/testにテストファイルを配置する．venvをactivateする必要がある．
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
	https://github.com/clever-elsie/lib_Clever_Elsie.git
	コードスニペットなので必要ない  

`tools`のmakeはサーバー以外のすべてのツールのビルドをする。  
`server`のmakeはCrowが正しくビルドされていないと失敗する。  
`ln -s /dev/shm/ ../shm`は確認した限り正しく動作しない。  
意図は伝わると思うが明示しておくと、work直下に`/dev/shm`へのシンボリックリンクを追加する。  
`echo`の部分は動作確認をしていない。`vim`などで直接記述したほうが良い。  
サーバーを使うために`include/tools/server`にある`default`の内容を`/etc/nginx/sites-available/default`に重複部分を除いてコピーする。  
そのために`default`には必要最小限のことのみを書いているが、`nginx`側の`default`の内容を削除する必要はない。  
`include/tools/server`にある`code_test.service`は`/etc/systemd/system`の中にコピーして`sudo systemctl enable code_test && sudo systemctl start code_test`とすると、サーバープログラムが有効になる。  
`~/.bashrc`に`include/tools/resource/bash_append.txt`の内容を追記して、`source ~/.bashrc`する。

`include/server/tempermonkey_script_for_reg_sample.js`の中身は，tempermonkeyに新規スクリプトとしてコピペする．

## local.h
()内の数字は引数の数
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
|gnu_map\<T\>|乱択可能map(.get(idx)で乱択, .ord(key)でキーの順番)|
|uset|unordered_set|
|umap|unordered_map|
|i[8-128]|signed integral|
|u[8-128]|unsigned integral|
|f[32-128]|floating-point|
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
|RET|return|

### define()
|省略名|本体|
|-|-|
|sn(2)|" \n"[1==2]|
|rsv(1)|reserve(1)|
|pf,pb(1)|push_(back,front)(1)|
|eb(...)|emplace_back(__VA_ARGS__)|
|ppf,ppb,pp|pop(_front,_back)()|
|ins(1)|insert(1)|
|emp(...)|emplace(__VA_ARGS__)|
|cont(1)|contains(1)|
|mp(2)|make_pair(1,2)|
|A(1)|[begin,end)|
|I(2)|[begin,+i)|
|elif(1)|else if(1)|
|rep(...)|次節|
|rrep(...)|次節|
|iter(...)|次節|
|cter(...)|次節|
|lb(...)|lower_bound|
|ub(...)|upper_bound|
|rev(1)|reverse([begin,end))|
|minel(1)|min_element([begin,end))|
|maxel(1)|max_element([begin,end))|
|swapcase(1)|upper<->lowerアルファベット以外は不変|
|Sort(1)|sort(1.begin(),1.end())|
|acm(1)|配列の総和|
|nxpm(1)|順列全探索|
|uni(1)|ソートして座圧|
|DR(1)|views::drop(1)|
|TK(1)|views::take(1)|
|yn(1)|1?yes:no|
|dput(...)|putv(...)を使いローカルでのみ出力。AtCoderでは出力されない|

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
|sep|'\n'|
|dc : vc\<pi\>|右下左上、右下、右上、左下、左上|
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
|lbi(...)|lower_boundの位置を返す。詳しくは次節。|
|ubi(...)|upper_boundの位置を返す。使用法は同上|
|pcnt(1)|popcount|
|lsb(1)|最左ビット|
|msb(1)|最右ビット|
|in(...)|前から順にstdinから受け取る。組込み型とstr,pair及びそれらのvc,vv|
|zip<T,U>(n[,m])|2行の入力を`vc<pair<T,U>>`に詰める．サイズは`min(n,m)`で`m`省略可|
|out(...)|stdoutに空白区切りで出力。iterableは出力後改行。組込み型とpair,str,mint及び、それらの.begin().end()を持つコンテナ|
|putbit\<N\>(1)|N桁のビットを出力|
|iostream operator<<,>>|128bit出力可能、速度は不明．大体全部．pairはデバッグ用に()付きなので答えに使わないように．|

### lower_bound, upper_bound
以下では、 $v$ をvector,array,dequeのいずれかの配列オブジェクト、 $x$ を探索キーの値、 $i$ を開始オフセット、 $e$ を終了位置とする。  
さらに、 $n=|v|$ とする。  
$A(v),i+I(v,e)$で用いるのと同様に、 $i$ は0からの相対位置(絶対位置ではあるけれど使用方法はオフセット)、 $e$ は終了位置の絶対的な位置である。  


$lb,ub$は通常のlower_bound,upper_boundと同じく、開始と終了のイテレータとキー及び比較関数を渡すことで、使用することができる。  
したがって、 $A(v)$ や $I(v,e)$ を用いてイテレータの記述を省略する記法もそのまま使える。

引数を $v,x$ とすることで $[0,n)$ で探索を行う

$i,v,x$ならば、 $[i,n)$ で探索を行う。

$v,e,x$ならば、 $[0,e)$ で探索を行う。

$i,v,e,x$ならば、 $[i,e)$ で探索を行う。

それぞれについて、末尾にgreater<>などの比較関数を渡すことができる。  
これは関数やoperator()をオーバーロードしたクラスなどinvokableなら何でもよい(はず)

### 定義済み宣言
INT(...) intを宣言して入力を受け取る
CHR(...) charを宣言して入力を受け取る
STR(...) stringを宣言して入力を受け取る
VI(a,n) サイズnのint配列を宣言して入力を受け取る
VS(a,n) サイズnのstring配列を宣言して入力を受け取る
UV(u,v) グラフの辺を受け取るときに頂点番号を-1する
UVW(u,v,w) 重み付きバージョン

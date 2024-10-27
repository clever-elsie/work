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


# アルゴリズムとデータ構造

## 第4章 設計技法 (2) 再起と分割統治法

### 4.1 再帰とは

- 再帰呼び出し (recursive call) - 手続きの中で自分自身を呼び出すこと
- 再帰関数 (recursive function) - 再帰呼び出しを行う関数のこと

==1からNまでの総和を計算する再帰関数==

- code4.1

  ``` cpp
  if func(int N) {
      if (N == 0) return 0;
      return N + func(N - 1);
  }
  ```

  func(5) --> 5 + func(4)

  func(4) --> 4 + func(3)

  func(3) --> 3 + func(2)

  func(2) --> 2 + func(1)

  func(1) --> 1 + func(0)

  func(0) = 0

  の順番に呼び出される。値を返す順番は逆になる。

  code 4_2.cppを確認すること

  

==再帰関数のテンプレート== 

- ベースケース：再帰関数の中で再帰呼び出しを行わずに**return**するケースのこと。ベースケースの処理が適切に記述されていないと、再帰呼び出しを無限に繰り返すことになる。実際には再帰関数の引数がスタック領域に格納されるので、徐々にスタック領域のメモリを消費し、最終的にはスタックオーバーフローになる。

```cpp
(戻り値の型) func(引数) {
    if (ベースケース) {
        return ベースケースに対する値;
    }
    // 再帰呼び出しを行う
    func(次の引数);
    return 答え;
}
```

==再帰呼び出しが止まらない再帰関数==

- code4.3

  下のコードだと`func(5)`と呼び出した時、再帰呼び出し時の引数が6, 7, 8, ...と延々と増えてしまう為に、再帰呼び出しが止まらなくなってしまう。

  ```cpp
  int func(int N) {
      if (N == 0) {
          return 0;
      } else {
          return N + func(N + 1);
      }
  }
  ```

### 4.2 再帰の例（1）：ユークリッドの互除法

- ユークリッドの互除法

  ユークリッド(Euclid)の互除法とは、2つの整数$m, n$の最大公約数($\text{GCD}(m, n)$)を求めるアルゴリズムである。

  ==最大公約数の性質==

  $m$を$n$で割ったときのあまりを$r$とすると、
  $$
  \text{GCD}(m, n) = \text{GCD}(n, r)
  $$
  が成立する。この性質を活用する。

  1. $m$を$n$で割ったときのあまりを$r$とする
  2. $r = 0$であれば、この時点での$n$が求める最大公約数であり、これを出力して手続きを終了
  3. $r \neq 0$の場合には、$m \leftarrow n, n\leftarrow r$として1に戻る

- code4_4.cppを参照

### 4.3 再帰の例（2）：フィボナッチ数列

- 再帰関数内で再帰呼び出し複数回行う例
  $$
  \begin{eqnarray}
  F_{0} &=& 0 \\
  F_1 &=& 1 \\
  F_N &=& F_{N-1} + F_{N-2} (N = 2, 3, \cdots)
  \end{eqnarray}
  $$
  
- code4.5

  ```cpp
  int fit(int N) {
      if (N == 0) { // ベースケース1
          return 0;
      } else if (N == 1) { // ベースケース2
          return 1;
      } else { // 再帰呼び出し
          return fibo(N - 1) + fibo(N - 2);
      }
  }
  ```

- code4_6.cppを参照
  - このアルゴリズムは同じ計算を繰り返す効率の悪いもの。
  - 計算量は $O((\frac{1+\sqrt{5}}{2})^{N})$でNに関して指数的に計算時間が増大する

### 4.4 メモ化して動的計画法へ

==フィボナッチ数列をfor文による反復で求める==

code4_7.cpp参照

for文を用いたアルゴリズムの計算量は$O(N)$である。これは計算結果を再利用しているため、同じ計算をせずに住んでいる。従って、再帰処理に置いても計算の無駄を省くことを考える。その手段として同じ引数に対する答えを**メモ化**する方法が有効。

==再帰関数の同じ計算をする無駄を省くためのメモ化==

```cpp
memo[v] <-- fibo(v) の答えを格納 (未計算時は-1を格納)
```

計算済みの値については再帰呼び出しを行わずにメモ化した値を直接返すようにする。**キャッシュ**と呼ばれる考え方でもある。これによって計算量は$O(N)$になる。

code4_8.cpp参照

動的計画法と呼ばれるフレームワークを再帰関数を用いて実現したもの

### 4.5 再帰の例（3）：再帰関数を用いる全探索

#### 4.5.1 部分和問題

3.5では整数の二進法表現とビット演算を用いた。ここでは再帰関数を用いる全探索アルゴリズムを設計する。

- $a_{N-1}$を選ばない時
- $a_{N-1}$を選ぶ時

で場合わけすることができ、これらは結局次のように書き直すことが出来る。

- $N-1$個の整数$a_0,a_1, \cdots, a_{N-2}$から$W$を作れるかどうか
- $N-1$個の整数$a_0,a_1, \cdots, a_{N-2}$から$W - a_{N-1}$を作れるかどうか

これらの2つの小問題のうち、少なくとも1方が"Yes"であれば元の問題の答えも”Yes"となる。両方とも”No”であれば元の問題の答えも”No"となる。

これを繰り返すことで問題を再帰的に解くことが出来る。

### 4.6 分割統治法

- 分割統治法 (divide-and-conquer method)

  与えられた問題をいくつかの部分問題に分解し、各部分問題を再帰的に解き、そららの解を組み合わせて元の問題の解を構成するアルゴリズム技法

  既に多項式時間アルゴリズムが得られている問題に対して、より高速なアルゴリズムを設計するために用いられる(ことが多い)。

### 4.7 まとめ

- 動的計画法

  再帰的アルゴリズム似た逸するメモ化による高速化

- 分割倒置法

  再帰関数を用いる本来の目的である「問題をより小さな問題に分解して解く」という考え方に基づくフレームワーク
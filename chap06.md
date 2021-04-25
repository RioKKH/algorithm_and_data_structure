# アルゴリズムとデータ構造

## 第6章　設計技法(4)：二分探索法

### 6.1 配列の二分探索

ソート済み配列の中から目的のものを高速に探索するアルゴリズム。二分探索を行うためには配列がソートされている必要がある。$O(N\log{N})$の計算量で実行出来る。

### 6.2 C++のstd::lower_bound)()の仕様

### 6.3 一般化した二分探索法

#### 一般化した二分探索法

各整数$x$について$\text{true/false}$の2値で判定される条件$P$が与えられていて、ある整数$l, r (l < r)$が存在して、以下が成立しているとする。

- $P(l) = \text{false}$
- $P(r) = \text{true}$
- ある整数$M(l < M \leq r)$が存在して、$x < M$なる$x$に対して$P(x) = \text{false}$であり、$x \geq M$なる$x$に対して$P(x) = \text{true}$である

この時$D = r - l$として、二分探索法は$M$ を$O(\log{D})$の計算量で求めることが出来るアルゴリズムと言える。

実数上の探索問題に対しても二分探索法は適用可能。整数の場合と同様に、false/true境界を挟む形で探索範囲を狭めていく。整数の場合の探索の終了条件が探索範囲の長さが1、で与えられたのに対し、実数の場合は求めたい精度によって終了条件を規定することになる。

### 6.4 更に一般化した二分探索法

#### 一般化した実数上の二分探索法

本参照

### 6.5 応用例（1）：年齢当てゲーム

==年齢当てゲーム==

Aさんの年齢を当てたい。Aさんの年齢が20歳以上、36歳未満であることは分かっている。

4回前でYes/Noで答えられる質問をすることが出来る。

これを二分探索法に当てはめると、変数left, rightを用意しておいて、

- x = leftは「Aさんの年齢がx未満である」という条件を常に満たさない
- x = rightは「Aさんの年齢がx未満である」という条件を常に満たす

という状態を確保しながら探索範囲を狭める。



### 6.6 応用例（2）：std::lower_bound()の活用例

==ペア和のK以上の中での最小値==

$N$個の整数$a_0, a_1, \cdots, a_{N-1}$と、N個の整数$b_0, b_1, \cdots, b_{N-1}$が与えられる。2組の整数列からそれぞれ1個ずつ整数を選んで和を取る。その和として考えられる値のうち、整数K以上の範囲内での最小値を求める

### 6.7 応用例（3）：最適化問題を判定問題に

最適化問題を判定問題に読み替えるのは応用上重要。xが条件を満たすかどうかを判定する、と読み替える。これを二分探索法で解く。

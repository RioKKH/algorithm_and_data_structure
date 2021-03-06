# アルゴリズムとデータ構造

## 第3章 設計技法 (1) 全探索

### 3.2 全探索(1) : 線形探索法

==基本的な探索問題==

 N個の整数$a_0, a_1, \cdots, a_{N-1}$と整数値$v$が与えられる。$a_i = v$となるデータが存在するかどうかを判定する。

**線形探索法** (linear search method) 

`code3_1.cpp`参照

### 3.3 線形探索の応用

#### 3.3.1 条件を満たすものがある場所も知る

code3_2.cpp

#### 3.3.2 最小値を求める

code3_3.cpp 

### 3.4 全探索(2) : ペアの全探索

---

==ペア和のK以上の中での最小値==

$N$個の整数$a_0, a_1, \cdots, a_{N-1}$と$N$個の整数$b_0, b_1, \cdots, b_{N-1}$が与えられる。2組の正数列からそれぞれ1個ずつ整数を選んで和を取る。和として考えられる値のうち、整数$K$以上の範囲内での最小値を求める

---

線形の全探索をすると、2重のfor文で表現出来るので、計算量は$O(N)$となる。

二分探索法を用いることで$O(N{\log}N)$で解くことが出来る。

code3_4.cpp (線形全探索　2重for loop)

### 3.5 全探索(3) : 組み合わせの全探索

---

==部分和問題==

$N$個の正の整数$a_0, a_1, \cdots, a_{N-1}$と正の整数$W$が与えられる。$a_0, a_1, \cdots, a_{N-1}$の中から何個かの整数を選んで総和を$W$とすることが出来るかを判定する

---

$N$個の整数からなる集合の部分集合は$2^N$通りある。

ここでは整数の二進法表現とビット演算を用いる方法を採用する。

二進法表現で$N$桁以下となる整数は、通常の十進法で表すと0以上$2^N$未満の値となる。

`std::bitset`、`std::vecotr<bool>`を用いても良い。

```cpp
// bit の表す部分集合に i 番目の要素が含まれる場合
if (bit & (1 << i)) {
    //処理
} else { // 含まれない場合
    // 処理
}
```

ここではビットシフトをもちいて整数`bit`を二進数表現で表したときに、`bit`の$i$桁目が1になっているかどうかを判定している。$i$番目の桁の数が1になっており、`bit`も$i$番目の桁の数が1になっていれば&オペレーションの結果も非ゼロとなり、結果trueとなる。

| i    | 1 << i    | bit & (1 << i)                            |
| ---- | --------- | ----------------------------------------- |
| 0    | 0000,0001 | 0100,1101 & 0000,0001 = 0000,0001 (true)  |
| 1    | 0000,0010 | 0100,1101 & 0000,0010 = 0000,0000 (false) |
| 2    | 0000,0100 | 0100,1101 & 0000,0100 = 0000,0100 (true)  |
| 3    | 0000,1000 | 0100,1101 & 0000,1000 = 0000,1000 (true)  |
| 4    | 0001,0000 | 0100,1101 & 0001,0000 = 0000,0000 (false) |
| 5    | 0010,0000 | 0100,1101 & 0010,0000 = 0000,0000 (false) |
| 6    | 0100,0000 | 0100,1101 & 0100,0000 = 0100,0000 (true)  |
| 7    | 1000,0000 | 0100,1101 & 1000,0000 = 0000,0000 (false) |
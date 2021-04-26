# アルゴリズムとデータ構造

## 第8章　データ構造（1）：配列、連結リスト、ハッシュテーブル

### 8.1 データ構造を学ぶ意義

- データ構造(data structure)
  データの持ち方
- クエリ(query)
  データ構造に値を挿入して管理したり、データ構造から所望の値を取り出したりするような要求のこと

### 8.2 配列

- 配列(array)
  - インデックスを用いて要素にアクセスするのが容易。a[i]へのアクセスを$O(1)$の計算量で実行可能
  - その一方で以下の処理を苦手とする
    - 要素$x$を要素$y$の直後に挿入する。$O(N)$の計算量が必要
    - 要素$x$ を削除する。$O(N)$の計算量が必要

### 8.3 連結リスト

配列の弱点である挿入・削除クエリに強いデータ構造として連結リストがある(linked list)。

- 各要素をポインタで一列につないだもの

- 要素の先頭と終端には何も無い事を示す「番兵(sentinel)」が置かれる。`nil` とする。

- ==自己参照構造体(self-referencing structure)==
  各ノードがポインタで連結されるようなデータ構造を実装するのに用いられる

  ```cpp
  struct Node {
      Node *next; // 次がどのノードを指すか
      std::string name; // ノードに付随している値
      
      // コンストラクタを定義する
      // このコンストラクタは引数を持つが初期値も定義してあるので、
      // 引数無しのinstanciateも可能
      Node(string name_ = "") : next(NULL), name(name_) {}
  };
  ```

### 8.4 連結リストの挿入操作と削除操作

#### 8.4.1 連結リストの挿入操作

==単方向連結リスト==

```cpp
// ノードpの直後にノードvを挿入する
void insert(Node *v, Node *p)
{
    v->next = p->next;
    p->next = v;
}
```

#### 8.4.1 連結リストの削除操作

削除対象のノードの前後のノード間でポインタの繋ぎ変え処理が必要になる。そこで==双方向連結リスト(bidirectional linked list)==を導入する。

まずは双方向へと拡張した自己参照構造体を定義する

```cpp
struct Node {
    Node *prev, *next;
    std::string name; // ノードに付随している値
    
    // constructor
    Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
}
```

この双方向自己参照構造体をもちいた双方向連結リストは以下のように作成出来る

```cpp
// ノードpの直後にノードvを挿入する
void insert(Node *v, Node *p = nil)
{
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

// ノードvを削除する
void erase(Node *v)
{
    if (v == nil){
        return; // vが番兵の場合は何もしない
    }
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v; // メモリを解放
}
```

### 8.5 配列と連結リストの比較

- 配列
  - メリット
    - i番目の要素にアクセスする $O(1)$
  - デメリット
    - 特定の要素の直後に要素を追加する、要素を削除する $O(N)$
- 連結リスト
  - メリット
    - 特定の要素の直後に要素を追加する、要素を削除する $O(1)$
  - デメリット
    - i番目の要素にアクセスする $O(N)$

### 8.6 ハッシュテーブル

#### 8.6.1 ハッシュテーブルの考え方

- バケット(bucket)
- ハッシュテーブル(hash table)
- ハッシュ関数(hash function)
- キー(key): $x$とハッシュ値(hash value): $h(x)$

- 完全ハッシュ関数 (perfect hash function) : 任意の $x\in S$に対してハッシュ値$h(x)$が全て異なるようなハッシュ関数の事

#### 8.6.2 ハッシュの衝突対策

- ハッシュの衝突(collision): 異なる$x, y \in S$に対して$h(x) = h(y)$となる場合

ハッシュの衝突を解決する様々なアルゴリズムが存在する。

#### 8.6.3 ハッシュテーブルの計算量

- 単純一様ハッシュ(simple uniform hashing)
- 負荷率：播種テーブルの振る舞いを示す指標。

#### 8.6.4 C++やPythonにおけるハッシュテーブル

#### 8.6.5 連想配列

### 8.7 まとめ

|                                 | 配列   | 連結リスト | ハッシュテーブル | 平衡二分探索木 | ヒープ         |
| ------------------------------- | ------ | ---------- | ---------------- | -------------- | -------------- |
| C++での実現                     | vector | list       | unordered_set    | set            | priority_queue |
| Pythonでの実現                  | list   | -          | set              | -              | heapq          |
| i番目の要素へのアクセス         | $O(1)$ | $O(N)$     | -                | -              | -              |
| データ構造のサイズを取得        | $O(1)$ | $O(1)$     | $O(1)$           | $O(1)$         | $O(1)$         |
| 要素$x$を挿入                   | $O(1)$ | $O(1)$     | $O(1)$           | $O(\log{N})$   | $O(\log{N})$   |
| 要素$x$を特定の要素の直後に挿入 | $O(N)$ | $O(1)$     | -                | -              | -              |
| 要素$x$を削除                   | $O(N)$ | $O(1)$     | $O(1)$           | $O(\log{N})$   | $O(\log{N})$   |
| 要素$x$を検索                   | $O(N)$ | $O(N)$     | $O(1)$           | $O(\log{N})$   | -              |
| 最大値を取得                    | -      | -          | -                | $O(\log{N})$   | $O(1)$         |
| 最大値を削除                    | -      | -          | -                | $O(\log{N})$   | $O(\log{N})$   |
| $k$番目に小さな値を取得         | -      | -          | -                | $O(\log{N})$   | -              |

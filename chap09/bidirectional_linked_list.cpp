#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 連結リストの各ノードを表す構造体
struct Node {
    Node *prev, *next;
    string name;  // ノードに付随している値

    Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
};

// 番兵を表すノードをグローバル領域においておく
Node* nil;

// 初期化
void init() {
    nil = new Node();
    nil->prev = nil;
    nil->next = nil;
}

// 連結リストを出力する
void printList() { Node* }

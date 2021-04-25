#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 連結リストの各ノードを表す構造体
struct Node {
    Node *prev, *next;
    string name; // ノードに付随する値

    Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
}

// 番兵を表すノードをグローバル領域に置いておく
Node *nil;

// 初期化
void init()
{
    nil = new Node();
    nil->prev = nil;
    nil->next = nil;
}

// 連結リストを出力する
void printList()
{
    Node *cur = nil->next; // 先頭から出発
    for (; cur != nil; cur= cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

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
    if (v == nil) {
        return; // vが番兵の場合は何もしない
    }
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v; // メモリを解放
}

int main()
{
    // 初期化
    init();

    // 作りたいノードの名前の一覧



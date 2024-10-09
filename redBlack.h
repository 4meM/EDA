#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define FOR_LOOP(val,i, len) for (int i = val; i < len; ++i)
#define REVERSE_FOR_LOPP(i, start, end) for(int i = (end) - 1; i >= start; i--)
using namespace std;

struct nodo{
    string color;
    int data;
    nodo* left;
    nodo* right;
    nodo* parent;
    nodo(){
        string color = "RED";
        int data = 0;
        nodo* left;
        nodo* right;
        nodo*parent;
    }
    nodo(int data)
        : data(data)
        , color("RED")
        , left(nullptr)
        , right(nullptr)
        , parent(nullptr)
    {}
};

class redBlack{
    struct nodo* root;    
    struct nodo* NIL;
    nodo* reservar(int data);
    void leftRotate(nodo* x);
    void rightRotate(nodo* x);
    void fixInsert(nodo* z); 
    
    public:
        redBlack();
        nodo* getRoot();
        void insert(int data);
        void inorder(nodo* root);
};

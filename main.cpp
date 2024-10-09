#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "redBlack.cpp"
#define FOR_LOOP(val,i, len) for (int i = val; i < len; ++i)
#define REVERSE_FOR_LOPP(i, start, end) for(int i = (end) - 1; i >= start; i--)
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    redBlack arbol; 
    arbol.insert(10);
    arbol.insert(20);
    arbol.inorder(arbol.getRoot());
}
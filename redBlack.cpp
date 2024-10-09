#include "redBlack.h"

redBlack :: redBlack(){
    NIL -> color = "BLACK";
    root = NIL;
}


void redBlack::leftRotate(nodo* x){
    nodo* y = x -> right;
    x -> right = y -> left;
    if(y -> left != NIL){
        (y -> left)-> parent = x;
    }
    y -> parent = x -> parent;
    
    if(x -> parent == NIL){
        root = y;
    }

    else if(x == ((x -> parent) -> left)){
        (x -> parent) -> left = y;
    }

    else
        (x -> parent) -> right = y;
    
    y -> left = x;
    x -> parent = y;

}

void redBlack :: rightRotate (nodo * x){
    nodo*y = x -> left;
    x->left = y -> right;
    if(y -> right != NIL){
        (y -> right) -> parent = x;
    }
    y->parent = x->parent;

    if(x -> parent != NIL) 
        root = y;

    else if(x == (x -> parent) -> left)
        (x -> parent) -> left = y;

    else (x -> parent) -> right = y;

    y -> right = x;
    x -> parent = y;
}

void redBlack :: fixInsert (nodo* z){
    while((z -> parent) -> color == "RED"){
        if(z -> parent == ((z -> parent) -> parent) -> left){
            nodo* y = ((z -> parent) -> parent) -> right;
            if(y -> color == "RED"){
                (z -> parent) -> color =  "BLACK";
                (y -> color) = "BLACK";
                z = (z -> parent) ->  parent;
            }
            else{
                if(z == (z -> parent) -> right){
                    z = z -> parent;
                    leftRotate(z);
                }
                (z -> parent) -> color = "BLACK";
                ((z -> parent) -> parent) -> color = "RED";
                nodo *abuelo = (z ->parent) -> parent;
                rightRotate(abuelo);
            }
        }
        else{
            nodo* y = ((z -> parent) -> parent) -> left;
            if(y -> color == "RED"){
                (z -> parent) -> color =  "BLACK";
                (y -> color) = "BLACK";
                z = (z -> parent) ->  parent;
            }
            else{
                if(z == (z -> parent) -> left){
                    z = z -> parent;
                    leftRotate(z);
                }
                (z -> parent) -> color = "BLACK";
                ((z -> parent) -> parent) -> color = "RED";
                nodo *abuelo = (z ->parent) -> parent;
                leftRotate(abuelo);
            }
        }
    }
    root -> color = "BLACK";
}

nodo* redBlack :: reservar (int data){
    nodo* newNodo = new nodo(data);
    return newNodo;
}

void redBlack :: insert(int data){
    nodo *z = reservar(data);
    nodo* x = root;
    nodo* y = NIL;

    while(x != NIL){
        y = x;
        if(z -> data < x -> data){
            x = x -> left;
        }
        else x = x -> right;
    }

    z -> parent = y;
    if(y == NIL){
        root = z;
    }
    else if(z -> data < y -> data){
        y -> left = z;
    }
    else y -> right = z;

    z -> left = NIL;
    z -> right = NIL;
    z -> color = "RED";
    fixInsert(z);
}
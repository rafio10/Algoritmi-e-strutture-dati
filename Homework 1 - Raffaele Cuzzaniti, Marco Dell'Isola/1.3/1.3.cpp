// -----------------------------------------------------------------------------------------
/* Algoritmo implementato da:  Marco Dell'Isola, Raffaele Cuzzaniti */
// -----------------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct node { 
    int key;
    int priority;
    node *left, *right; 
}; 
typedef struct node node;
  
// Funzione per creare un nuovo nodo 
node* newNode(int item) { 
    node* temp = (node*)malloc( 
                  sizeof(node)); 
    temp->key = item; 
    temp->priority =  rand();
    temp->left = temp->right = NULL; 
    return temp; 
} 

// Viene preso il nodo radice che verrà spostato verso sinistra
node* leftRotate(node* y) {
    //Si salva il nodo di destra che diventerà la nuova radice
    node* x = y->right;
    //Collegamento dei figli del nodo che diventerà il nuovo nodo radice 
    y->right = x->left;
    //Il vecchio nodo radice diventa figlio sinistro della nuova radice
    x->left = y;
     //Restituzione del nodo radice
    return x;
}

//Viene preso il nodo radice che verrà spostato verso destra
node* rightRotate(node* x) {
    //Si salva il nodo di sinistra che diventerà la nuova radice
    node* y = x->left;
    //Collegamento dei figli del nodo che diventerà il nuovo nodo radice 
    x->left = y->right;
    //Il vecchio nodo radice diventa figlio destro della nuova radice
    y->right = x;
    //Restituzione del nodo radice
    return y;
}

node* treapInsert(node* root, int key) {
    //Verifica se il nodo passato alla funzione esiste, altrimenti lo crea
    if (!root) {
        return newNode(key);
    }

    //Inserimento dei nodi all'interno del BST valutando il valore della chiave 
    if (key <= root->key) {
        root->left = treapInsert(root->left, key);
        //Verifica dell'ulteriore condizione sulla priorità per mantenere la proprietà di min-heap
        if (root->left->priority < root->priority) {
            //Funzione che ristabilisce la struttura di min-heap
            root = rightRotate(root);
        }
    } else {
        root->right = treapInsert(root->right, key);
        //Verifica dell'ulteriore condizione sulla priorità per mantenere la proprietà di min-heap
        if (root->right->priority < root->priority) {
            //Funzione che ristabilisce la struttura di min-heap
            root = leftRotate(root);
        }
    }

    return root;
}

// Funzione per stampare il treap (inorder traversal)
void inorder(node* root) {
    if (root) {
        inorder(root->left);
        std::cout << "Key: " << root->key << " Priority: " << root->priority << std::endl;
        inorder(root->right);
    }
}

// Funzione per stampare il treap
void printTreap(node* root, int indent = 0) {
    if (root) {
        if (root->right) {
            printTreap(root->right, indent + 4);
        }
        if (indent > 0) {
            std::cout << setw(indent) << ' ';
        }
        std::cout << "Key: " << root->key << " Priority: " << root->priority << std::endl;
        if (root->left) {
            printTreap(root->left, indent + 4);
        }
    }
}

int main() {
    node* root = NULL;
    int keys[] = {4, 2, 6, 1, 3, 5, 7};

// Per ogni elemento di keys, assegna il valore a key ed esegui il for (equivalente a for each)
    for (int key : keys) {
        root = treapInsert(root, key);
    }

// Inserimento nodi all'interno del BST come da traccia
    treapInsert(root, 25);
    treapInsert(root, 9);

    cout << "\nBST: ";
    inorder(root);
    cout << "\nMin-Heap: " << endl;
    printTreap(root);

    return 0;
} 

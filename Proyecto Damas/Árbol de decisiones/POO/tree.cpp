#include "tree.h"
#define MAX_BRANCH 20

void tree::insert(int dato, int size, tree& nodo) {
	nodo.info_nodo = dato;
	for (int i = 0; i < size; i++) {
		vector_nodos[i] = new tree[MAX_BRANCH];
	}
}

void tree::new_root(int dato, int size, tree* root) {
	root->info_nodo = dato;
	for (int i = 0; i < size; i++) {
		root->vector_nodos[i] = new tree[MAX_BRANCH];
	}
}
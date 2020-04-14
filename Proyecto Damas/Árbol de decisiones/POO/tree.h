# define MAX_BRANCH 20

class tree{
private:
    int info_nodo;
    tree *vector_nodos[MAX_BRANCH];
public:
    //tree();
    void insert(int dato, int size, tree& nodo);
    void new_root(int dato, int size, tree* root);
    void erase(tree* nodo);
};

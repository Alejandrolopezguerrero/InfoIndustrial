#include <stdio.h>
#include <stdlib.h>

// The initial buffer length of a node's children
#define BUFFER_LENGTH   5
// How much to multiply with if an addition of a child goes over the buffer
#define MULTIPLIER 2

///Your node class
class A_Node
{
private:
    int value;
    unsigned int childrenN;
    A_Node** children;
    unsigned int bufferLength;

public:
    A_Node(int value, unsigned int childrenN = 0)
    {
        this->value = value;
        this->childrenN = childrenN;

        //allocate BUFFER_LENGTH children for the node at first or childrenN if the childrenN is not initially 0
        if (childrenN != 0)
        {
            this->children = (A_Node**)malloc(sizeof(A_Node*) * childrenN);
            this->bufferLength = childrenN;
        }
        else
        {
            this->children = (A_Node**)malloc(sizeof(A_Node*) * BUFFER_LENGTH);
            this->bufferLength = BUFFER_LENGTH;
        }
    }

    //in the destructor of a node it would need some special care
    ~A_Node()
    {
        //for every child call the destructor of each child
        for (int i = 0; i < this->childrenN; i++)
        {
            delete this->children[i];
        }

        //and only then free the buffer of the pointers to the children
        free(this->children);
    }

    //adds a child
    void addChild(A_Node* child)
    {
        //reallocate if needed
        if (childrenN >= this->bufferLength)
        {
            realloc(this->children, sizeof(A_Node*) * MULTIPLIER);
        }

        this->children[childrenN] = child;
        this->childrenN++;
    }

    A_Node* getChild(unsigned int i)
    {
        if (i >= this->childrenN)
        {
            return 0;
        }

        return this->children[i];
    }

    void printValue()
    {
        printf("%d\n", this->value);
    }

};

///Your tree class
class A_Tree
{
public:
    //constructor
    A_Tree(int rootValue)
    {
        root = new A_Node(rootValue);
    }
    //destructor
    ~A_Tree()
    {
        //recursively kills all the nodes due to the destructor of node
        delete root;
    }
    //your root node
    A_Node* root;
};


int main()
{
    A_Tree tree(16);

    tree.root->addChild(new A_Node(42));

    tree.root->printValue();

    (tree.root->getChild(0))->printValue();


    return 0;
}
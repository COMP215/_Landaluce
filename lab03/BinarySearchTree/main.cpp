#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        int count;
        Node* left_child;
        Node* right_child;
        Node();
        Node(int data);
        ~Node();
};

Node::Node()
{
    this->count       = 1;
    this->data        = NULL;
    this->left_child  = NULL;
    this->right_child = NULL;
}
Node::Node(int data)
{
    this->count       = 1;
    this->data        = data;
    this->left_child  = NULL;
    this->right_child = NULL;
}
Node::~Node()
{
    delete(this->left_child);
    delete(this->right_child);
}

class BinarySearchTree
{
    public:
        Node* head;
        Node buffer;

        BinarySearchTree();
        ~BinarySearchTree();
        void Insert(int data);
        void RecursiveInsert(int data, Node* leaf);
        Node* Search(int data);
        Node* RecursiveSearch(int data, Node* node);
        void DisplayTree();
        void RecursiveDisplay(Node* node,int count);
        void DestroyTree(Node* leaf);
        void DisplayNode(Node* node);
};

BinarySearchTree::BinarySearchTree()
{
    this->head              = &this->buffer;
    this->head->data        = NULL;
    this->head->left_child  = NULL;
    this->head->right_child = NULL;
}
BinarySearchTree::~BinarySearchTree()
{
    DestroyTree(this->head);
}
void BinarySearchTree::DestroyTree(Node* leaf)
{
    if(leaf)
    {
        DestroyTree(leaf->left_child);
        DestroyTree(leaf->right_child);
        delete(leaf);
    }
}
void BinarySearchTree::Insert(int data)
{
    Node* p = this->head;

    if(p)
    {
        RecursiveInsert(data, p);
    }
    else
    {
        p       = new Node;
        p->data = data;
    }
}
void BinarySearchTree::RecursiveInsert(int data, Node* leaf)
{
    if(data < leaf->data)
    {
        if(leaf->left_child)
        {
            RecursiveInsert(data, leaf->left_child);
        }
        else
        {
            leaf->left_child       = new Node;
            leaf->left_child->data = data;
        }
    }
    else if(data > leaf->data)
    {
        if(leaf->right_child)
        {
            RecursiveInsert(data,leaf->right_child);
        }
        else
        {
            leaf->right_child       = new Node;
            leaf->right_child->data = data;
        }
    }
    else
    {
        leaf->count++;
    }
}
Node* BinarySearchTree::Search(int data)
{
    return RecursiveSearch(data,this->head);
}
Node* BinarySearchTree::RecursiveSearch(int data, Node* node)
{
    if(node)
    {
        if(data == node->data)
        {
            return node;
        }
        else if(data < node->data)
        {
            return RecursiveSearch(data,node->left_child);
        }
        else
        {
            return RecursiveSearch(data,node->right_child);
        }
    }
    else
    {
        return NULL;
    }
}
void BinarySearchTree::DisplayTree()
{
    RecursiveDisplay(this->head,0);
}
void BinarySearchTree::RecursiveDisplay(Node* node,int count)
{
    if(node)
    {
        if(node == this->head)
            cout << "head: ";
        cout << node->data << "(" << node->count << ")" << endl;

        cout << endl << "[" << node->data << "]->left  child: ";
        RecursiveDisplay(node->left_child,count);
        cout << endl << "[" << node->data << "]->right child: ";
        RecursiveDisplay(node->right_child,count);
    }
    else
    {
        cout << "NULL";
    }
}
void BinarySearchTree::DisplayNode(Node* node)
{
    if(node)
    {
        Node* left_child  = new Node;
        Node* right_child = new Node;

        left_child  = node->left_child;
        right_child = node->right_child;

        cout << endl << "Node: " << node->data << "(" << node->count << ")" << endl;
        if(left_child)
        {
            cout << "[" << node->data << "]->left   child: " << left_child->data << endl;
        }
        else
        {
            cout << "[" << node->data << "]->left   child: " << "NULL" << endl;
        }
        if(right_child)
        {
            cout << "[" << node->data << "]->right  child: " << right_child->data << endl;
        }
        else
        {
            cout << "[" << node->data << "]->right  child: " << "NULL" << endl;
        }

    }
}

int main()
{
    BinarySearchTree my_tree;
    const int Lenght = 10;
    int numbers[Lenght] = {5,7,5,9,1,8,3,4,15,32};
    for(int i = 0;i < Lenght;i++)
    {
        my_tree.Insert(numbers[i]);
    }
    my_tree.DisplayTree();

    Node* search_result = new Node;
    search_result = my_tree.Search(7);
    cout << endl << "-----------------------";
    cout << endl << "Search result:";
    my_tree.DisplayNode(search_result);
    cout << "-----------------------" << endl;

    return 0;
}

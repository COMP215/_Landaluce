#include <iostream>

using namespace std;

class Node
{
    public:
        int data_;
        int count_;
        Node* left_child_;
        Node* right_child_;
        Node();
        Node(int data);
        ~Node();
};

Node::Node()
{
    this->count_       = 1;
    this->data_        = NULL;
    this->left_child_  = NULL;
    this->right_child_ = NULL;
}
Node::Node(int data)
{
    this->count_       = 1;
    this->data_        = data;
    this->left_child_  = NULL;
    this->right_child_ = NULL;
}
Node::~Node()
{
    delete(this->left_child_);
    delete(this->right_child_);
}

class BinarySearchTree
{
    public:
        Node* head_;
        Node buffer_;

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
    this->head_               = &this->buffer_;
    this->head_->data_        = NULL;
    this->head_->left_child_  = NULL;
    this->head_->right_child_ = NULL;
}
BinarySearchTree::~BinarySearchTree()
{
    DestroyTree(this->head_);
}
void BinarySearchTree::DestroyTree(Node* leaf)
{
    if(leaf)
    {
        DestroyTree(leaf->left_child_);
        DestroyTree(leaf->right_child_);
        delete(leaf);
    }
}
void BinarySearchTree::Insert(int data)
{
    Node* p = this->head_;

    if(p)
    {
        RecursiveInsert(data, p);
    }
    else
    {
        p       = new Node;
        p->data_ = data;
    }
}
void BinarySearchTree::RecursiveInsert(int data, Node* leaf)
{
    if(data < leaf->data_)
    {
        if(leaf->left_child_)
        {
            RecursiveInsert(data, leaf->left_child_);
        }
        else
        {
            leaf->left_child_        = new Node;
            leaf->left_child_->data_ = data;
        }
    }
    else if(data > leaf->data_)
    {
        if(leaf->right_child_)
        {
            RecursiveInsert(data,leaf->right_child_);
        }
        else
        {
            leaf->right_child_        = new Node;
            leaf->right_child_->data_ = data;
        }
    }
    else
    {
        leaf->count_++;
    }
}
Node* BinarySearchTree::Search(int data)
{
    return RecursiveSearch(data,this->head_);
}
Node* BinarySearchTree::RecursiveSearch(int data, Node* node)
{
    if(node)
    {
        if(data == node->data_)
        {
            return node;
        }
        else if(data < node->data_)
        {
            return RecursiveSearch(data,node->left_child_);
        }
        else
        {
            return RecursiveSearch(data,node->right_child_);
        }
    }
    else
    {
        return NULL;
    }
}
void BinarySearchTree::DisplayTree()
{
    RecursiveDisplay(this->head_,0);
}
void BinarySearchTree::RecursiveDisplay(Node* node,int count)
{
    if(node)
    {
        if(node == this->head_)
            cout << "head: ";
        cout << node->data_ << "(" << node->count_ << ")" << endl;

        cout << endl << "[" << node->data_ << "]->left  child: ";
        RecursiveDisplay(node->left_child_,count);
        cout << endl << "[" << node->data_ << "]->right child: ";
        RecursiveDisplay(node->right_child_,count);
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

        left_child  = node->left_child_;
        right_child = node->right_child_;

        cout << endl << "Node: " << node->data_ << "(" << node->count_ << ")" << endl;
        if(left_child)
        {
            cout << "[" << node->data_ << "]->left   child: " << left_child->data_ << endl;
        }
        else
        {
            cout << "[" << node->data_ << "]->left   child: " << "NULL" << endl;
        }
        if(right_child)
        {
            cout << "[" << node->data_ << "]->right  child: " << right_child->data_ << endl;
        }
        else
        {
            cout << "[" << node->data_ << "]->right  child: " << "NULL" << endl;
        }

    }
}

int main()
{
    BinarySearchTree my_tree;
    const int Lenght    = 10;
    int numbers[Lenght] = {5,7,5,9,1,8,3,4,15,32};
    for(int i = 0;i < Lenght;i++)
    {
        my_tree.Insert(numbers[i]);
    }
    my_tree.DisplayTree();

    cout << endl << "-----------------------";
    cout << endl << "Search result:";
    my_tree.DisplayNode(my_tree.Search(7));
    cout << "-----------------------" << endl;

    return 0;
}

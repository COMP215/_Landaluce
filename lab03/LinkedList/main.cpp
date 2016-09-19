#include <iostream>

using namespace std;

class Node
{
    public:
        string data_;
        Node* next_;

        Node();
        Node(string data);
        ~Node();
};
Node::Node()
{
    this->data_ = "";
    this->next_ = NULL;
}
Node::Node(string data)
{
    this->data_ = data;
    this->next_ = NULL;
}
Node::~Node()
{
    delete(this->next_);
}

class LinkedList
{
    public:
        Node* head_;
        Node  buffer_;
        Node* tail_;

        LinkedList();
        void Push(string data);
        void Delete(string data);
        void Pop();
        void Display();
        void EmptyList();


};
LinkedList::LinkedList()
{
    this->head_ = &buffer_;
    this->buffer_.data_ = "Buffer";
    this->tail_ = &buffer_;
}
void LinkedList::Push(string data)
{
    Node* new_node = new Node(data);
    this->tail_->next_ = new_node;
    this->tail_ = new_node;
}

void LinkedList::Pop()
{
    if(this->head_ != this->tail_)
    {
        Node* p1 = this->head_;
        Node* p2 = this->head_->next_;

        while(p2->next_)
        {
            p1 = p1->next_;
            p2 = p2->next_;
        }

        delete(p2);
        p1->next_ = NULL;
        this->tail_ = p1;
    }
    else
    {
        cout << "List already empty" << endl;
    }
}
void LinkedList::Delete(string data)
{
    Node* prev = this->head_;
    Node* p = prev->next_;
    bool found = false;
    if(p->next_)
    {
        Node* next = p->next_;
        while(next && !found)
        {
            if(p->data_.compare(data) == 0)
            {
                prev->next_ = next;
                if(next)
                {
                    next = next->next_;
                }
                else
                {
                    next = NULL;
                    this->tail_ = prev;
                }

                found = true;
            }
            if(!found)
            {
                prev = prev->next_;
                p = p->next_;
                next = next->next_;
            }
        }
    }
    if(!found && this->tail_->data_ == data)
    {
        this->tail_ = prev;
        prev->next_ = NULL;
    }
}
void LinkedList::EmptyList()
{
    while(this->head_ != this->tail_)
    {
        Pop();
    }
}
void LinkedList::Display()
{
    Node* p = this->head_;

    while(p)
    {
        cout << p->data_ << "->";
        p = p->next_;
    }
    cout << endl;
}
int main()
{
    LinkedList my_list;
    my_list.Display();
    my_list.Push("node1");
    my_list.Push("node2");
    my_list.Push("node3");
    my_list.Push("node4");
    my_list.Push("node5");
    my_list.Display();

    my_list.Delete("node1");
    my_list.Delete("node3");
    my_list.Delete("node5");
    my_list.Display();

    my_list.Push("node1");
    my_list.Display();

    my_list.EmptyList();
    my_list.Display();
    return 0;
}

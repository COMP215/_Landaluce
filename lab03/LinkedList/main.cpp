#include <iostream>

using namespace std;

class Node
{
    public:
        string data;
        Node* next;

        Node();
        Node(string data);
        ~Node();
};
Node::Node()
{
    this->data = "";
    this->next = NULL;
}
Node::Node(string data)
{
    this->data = data;
    this->next = NULL;
}
Node::~Node()
{
    delete(this->next);
}

class LinkedList
{
    public:
        Node* head;
        Node buffer;
        Node* tail;

        LinkedList();
        void Push(string data);
        void Delete(string data);
        void Pop();
        void Display();
        void EmptyList();


};
LinkedList::LinkedList()
{
    this->head = &buffer;
    this->buffer.data = "Buffer";
    this->tail = &buffer;
}
void LinkedList::Push(string data)
{
    Node* new_node = new Node(data);
    this->tail->next = new_node;
    this->tail = new_node;
}

void LinkedList::Pop()
{
    if(this->head != this->tail)
    {
        Node* p1 = this->head;
        Node* p2 = this->head->next;

        while(p2->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        delete(p2);
        p1->next = NULL;
        this->tail = p1;
    }
    else
    {
        cout << "List already empty" << endl;
    }
}
void LinkedList::Delete(string data)
{
    Node* prev = this->head;
    Node* p = prev->next;
    bool found = false;
    if(p->next)
    {
        Node* next = p->next;
        while(next && !found)
        {
            if(p->data.compare(data) == 0)
            {
                prev->next = next;
                if(next)
                {
                    next = next->next;
                }
                else
                {
                    next = NULL;
                    this->tail = prev;
                }

                found = true;
            }
            if(!found)
            {
                prev = prev->next;
                p = p->next;
                next = next->next;
            }
        }
    }
    if(!found && this->tail->data == data)
    {
        this->tail = prev;
        prev->next = NULL;
    }
}
void LinkedList::EmptyList()
{
    while(this->head != this->tail)
    {
        Pop();
    }
}
void LinkedList::Display()
{
    Node* p = this->head;

    while(p)
    {
        cout << p->data << "->";
        p = p->next;
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

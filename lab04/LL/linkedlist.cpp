//
//  linkedlist.cpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include "linkedlist.hpp"
#include <string>

using namespace std;

Node::Node(string data) {
    data_ = data;
    next_ = NULL;
}

LinkedList::LinkedList() {
    root_ = NULL;
    tail_ = root_;
}

bool LinkedList::Insert(string data) {
    Node* new_node = new Node(data);
    // Empty list, make first node
    if (root_ == NULL) {
        root_ = new_node;
        tail_ = root_;
    } else {
        //Non-empty list, push node
        tail_->next_ = new_node;
        tail_ = new_node;
    }
    return true;
}

bool LinkedList::Search(string data) {
    if (root_ != NULL) {
        Node* curr = root_;
        while (curr) { //Found
            if (curr->data_ == data) {
                return true;
            }
            curr = curr->next_;
        }
    }
    return false; //Not found or empty list
}

bool LinkedList::Delete(string data) {
    Node* prev = root_;
    Node* curr = prev->next_;
    if (root_ != NULL) {
        if (prev->data_ == data) {
            root_ = curr;
            delete(prev);
            return true; // Found in head
        }
        while (curr->next_ != NULL) {
            if (curr->data_ == data) {
                prev->next_ = curr->next_;
                delete(curr);
                return true; // Found between head and tail
            }
            prev = prev->next_;
            curr = curr->next_;
        }
        if (curr->data_ == data) {
            prev->next_ = NULL;
            delete(curr);
            return true; // Found in tail
        }
    }
    return false; // Not found or empty list
}

void LinkedList::Display() {
    Node* curr = root_;
    while (curr) {
        cout << curr->data_ << "->";
        curr = curr->next_;
    }
    cout << endl;
}

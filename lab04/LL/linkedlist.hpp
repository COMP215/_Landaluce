//
//  binarysearchtree.hpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Node {
public:
    std::string data_;
    Node* next_;

public:
    Node(std::string);
};


class LinkedList {
    Node* root_;
    Node* tail_;

public:
    LinkedList();
    bool Insert(std::string);
    bool Search(std::string);
    bool Delete(std::string);
    void Display();
};


#endif /* binarysearchtree_hpp */

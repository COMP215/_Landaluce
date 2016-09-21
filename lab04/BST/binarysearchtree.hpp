//
//  binarysearchtree.hpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#ifndef binarysearchtree_hpp
#define binarysearchtree_hpp

#include <stdio.h>
#include <string>

class Node {
public:
    std::string data_;
    Node* left_;
    Node* right_;

public:
    Node(std::string);
};


class BinarySearchTree {
    Node* root_;

public:
    BinarySearchTree();
    bool Insert(std::string);
    bool Search(std::string);
};


#endif /* binarysearchtree_hpp */

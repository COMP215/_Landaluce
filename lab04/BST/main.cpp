//
//  main.cpp
//  classbst
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include <iostream>
#include "binarysearchtree.hpp"


int main(int argc, const char * argv[]) {

    BinarySearchTree* people_names = new BinarySearchTree();
    people_names->Insert("gousie");
    people_names->Insert("bloch");
    people_names->Insert("armstrong");
    people_names->Insert("decoste");

    std::cout << people_names->Search("armstrong") << std::endl;
    std::cout << people_names->Search("alvaro") << std::endl;

    std::cout << "Hello, World!\n";
    return 0;
}

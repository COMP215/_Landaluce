//
//  main.cpp
//  classll
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include <iostream>
#include "linkedlist.hpp"


int main(int argc, const char * argv[]) {

    LinkedList* people_names = new LinkedList();
    people_names->Insert("gousie");
    people_names->Insert("bloch");
    people_names->Insert("armstrong");
    people_names->Insert("decoste");

    std::cout << people_names->Search("armstrong") << std::endl;
    std::cout << people_names->Search("alvaro") << std::endl;

    people_names->Display();
    people_names->Delete("gousie");
    people_names->Delete("armstrong");
    people_names->Delete("decoste");
    people_names->Display();


    std::cout << "Hello, World!\n";
    return 0;
}

//
//  main.cpp
//  LinkedListWithDummyNode
//
//  Created by Jonathan Raysor on 3/9/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//
#include "List.h"
#include <iostream>

using namespace std;

int main() {
    List<int> numbers;
    
    List<int> numbers2(10,5);
    cout << numbers2.size() << endl;
    
    // testing functions
    for (int i = 0; i < 10; i++)
        numbers.push_back(i);
    
    cout << numbers.size() << endl;
    
    for (int j = 0; j < 3; j++)
        numbers.pop_front();
    
    cout << numbers.size() << endl;
    
    for (int k = 0; k < 2; k ++)
        numbers.pop_back();
    
    cout << numbers.size() << endl;

}

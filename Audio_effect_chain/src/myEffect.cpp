//
//  myEffect.cpp
//
//  Created by Daniel Petry on 28/05/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//
//  Template class for an effect, derived from the abstract class defined in audioEffect.h

#include <iostream>
#include "myEffect.hpp"

using namespace std;

//====================================================================================
// myEffect()
//
// Template for an effect's constructor
//====================================================================================
myEffect::myEffect(){
    cout << "myEffect Constructor" << endl;
}

//====================================================================================
// void process(void)
//
// Template for an effect's processor
//====================================================================================
void myEffect::process(float* buf, size_t num){
    cout << "myEffect Processor" << endl;
}

//====================================================================================
// ~myEffect()
//
// Template for an effect's destructor
//====================================================================================
myEffect::~myEffect(){
    cout << "myEffect Destructor" << endl;
}


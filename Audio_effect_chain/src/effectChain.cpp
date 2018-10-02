//
//  effectChain.cpp
//
//  Created by Daniel Petry on 25/05/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//
//  This class is an effect chain to manage multiple effects. It currently manages effects in a singly linked
//  list type structure, with each node having ownership of the next node via a shared_ptr.

#include <iostream>
#include <memory>
#include "effectChain.hpp"

using namespace std;

//====================================================================================
// effectChain()
//
// Constructor. Currently empty.
//====================================================================================
effectChain::effectChain(){
    
}

//====================================================================================
// bool addEffect(std::shared_ptr<AudioEffect>)
//
// This function adds an effect to the end of the chain.
//====================================================================================
bool effectChain::addEffect(std::shared_ptr<AudioEffect> newEffect){
    
    //TODO: make it so this function adds effects at a given position, not just the end
    if (newEffect != nullptr){
        if (head == nullptr){
            head = newEffect;     //copy
            tail.swap(newEffect); //swap
        }else{ //TODO: could provide some protection for the case that head != nullptr but tail == nullptr, for whatever reason
            tail->next.swap(newEffect);
            auto temp = tail->next;
            tail.swap(temp);
        }
        return true;
    }
    
    return false;
    
}


// Implement a function that checks if there is a feedback loop
// in the effects chain.

//====================================================================================
// bool detect_feedback(void)
//
// This function detects feedback loops in the effect chain, returning true if such a
// loop exists. It assumes that the effect chain is a singly-linked list type structure
// with no branches in the direction of walking the list.
//====================================================================================
bool effectChain::detect_feedback()
{
    auto p1 = this->head;
    auto p2 = this->head;
    
    while(p1 != nullptr && p2 != nullptr && p2->next != nullptr){  /* Prevents dereferencing of a null pointer, and also, exits the loop if we come to the end of the chain */
        
        p1 = p1->next;         //p1 goes one step each loop
        p2 = p2->next->next;   //p2 goes two steps each loop
        
        /* If the pointers meet, then there's a cycle.  */
        if (p1 == p2) return true;
        
    }
    
    return false;
}

//====================================================================================
// ~effectChain()
//
// Destructor.
//====================================================================================
effectChain::~effectChain(){
    
    //TODO: make it so that the effect chain destructor destroys any objects it may contain in a controlled manner
    cout << "effectChain Destructor" << endl;
    
}

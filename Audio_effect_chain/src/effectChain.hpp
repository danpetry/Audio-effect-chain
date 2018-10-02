//
//  effectChain.hpp
//
//  Created by Daniel Petry on 25/05/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//
//  This class is an effect chain to manage multiple effects. It currently manages effects in a singly linked
//  list type structure, with each node having ownership of the next node via a shared_ptr.

#ifndef effectChain_hpp
#define effectChain_hpp

#include "audioEffect.h"
#include <memory>

class effectChain{
    
public:
    
    effectChain();
    std::shared_ptr<AudioEffect> head;
    std::shared_ptr<AudioEffect> tail;
    bool detect_feedback();
    bool addEffect(std::shared_ptr<AudioEffect> newEffect);
    ~effectChain();
    
private:
    
};



#endif /* effectChain_hpp */

//
//  audioEffect.h
//
//  Created by Daniel Petry on 28/05/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//
//  Abstract base class for an audio effect.

#ifndef audioEffect_h
#define audioEffect_h

#include <memory>

struct AudioEffect {
    
    /* NB all are public members because it's a struct not a class and the access modifiers are not explicitly provided (they would be private if it was a class) */
    /* A pointer to the previous node would make walking the list in reverse more efficient (at the expense of memory, but CPU cycles are often of more concern than RAM usage in audio plugins) */
    virtual ~AudioEffect() = default; /* if we want to force definition of a destructor in derived classes, declaring the destructor protected would prevent this default destructor being used. */
    virtual void process(float* buf, size_t num) = 0;
    std::shared_ptr<AudioEffect> next; /* If a shared_ptr is used for this, and feedback loops are allowable, then it's possible to have a cyclic reference where objects keep each other alive in a cyclic manner, which means that the smart pointers aren't managing memory as they should, and you will get leaks. Weak_ptrs could help as they do not define ownership. However, having nodes owned by other nodes in a situation where you can have arbitrary and complex graph topologies (e.g. in Reaktor) may get very difficult to manage. Instead, using two vectors of simple pointers in each node, one for inputs and one for outputs, and then having a managing class (effectChain in this case) which owns the nodes and manages the graph using an adjacency list or matrix, and handles adding/deleting nodes, detecting feedback loops, walking the graph, etc,  might lead to a cleaner and safer implementation. */
};


#endif /* audioEffect_h */

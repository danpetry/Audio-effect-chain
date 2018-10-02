//
//  myEffect.hpp
//
//  Created by Daniel Petry on 28/05/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//
//  Template class for an effect, derived from the abstract class defined in audioEffect.h

#ifndef myEffect_hpp
#define myEffect_hpp

#include <stdio.h>
#include "audioEffect.h"

class myEffect : public AudioEffect{
    
public:
    
    myEffect();
    void process(float* buf, size_t num);
    ~myEffect();
    
};

#endif /* myEffect_hpp */

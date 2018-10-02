//
//  effectChainTest.cpp
//
//  Created by Daniel Petry on 25/05/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//
//  This tests the detectFeedback function in the effectChain class, using the Google test library for unit testing,
//  and the Hayai library for benchmarking.

#include <memory>
#include <hayai.hpp>
#include <gtest/gtest.h>
#include "myEffect.hpp"
#include "effectChain.hpp"

//====================================================================================
// detectFeedbackUnitTest
//
// Unit test for effectChain::detect_feedback()
//====================================================================================
TEST(niEffectsChain, detectFeedbackUnitTest) {
    
    effectChain myEffectChain;
    
    //TODO: DRY this, and the code adding effects to the chain below
    auto headEffect = std::make_shared<myEffect>();
    auto midEffect = std::make_shared<myEffect>();
    auto tailEffect = std::make_shared<myEffect>();

    //TODO: the pointers to the effects have to be released from the created objects after assignment into the effects chain, otherwise there will be two pointers with ownership of the effect objects and the nodes won't properly own their children. Design a neater way to create and link together effects that may be of different types and may be defined outside the effects chain class. (See also notes in audioEffect.h - using a different ownership model would help avoid this.)
    myEffectChain.addEffect(headEffect);
    if (!headEffect.unique()) headEffect.reset();
    myEffectChain.addEffect(midEffect);
    if (!midEffect.unique()) midEffect.reset();
    myEffectChain.addEffect(tailEffect);
    if (!tailEffect.unique()) tailEffect.reset();
    
    EXPECT_EQ(false, myEffectChain.detect_feedback());
    
    myEffectChain.tail->next = myEffectChain.head;
    
    EXPECT_EQ(true, myEffectChain.detect_feedback());
    
    myEffectChain.tail->next.reset(); //We have to now break the loop manually to avoid a memory leak
    
}

//====================================================================================
// niEffectsChainFixture
//
// Fixture to set up benchmark for effectChain::detect_feedback() (below)
//====================================================================================
class niEffectsChainFixture
:   public ::hayai::Fixture
{
public:
    virtual void SetUp()
    {
        auto headEffect = std::make_shared<myEffect>();
        auto midEffect = std::make_shared<myEffect>();
        auto tailEffect = std::make_shared<myEffect>();
        
        myEffectChain.addEffect(headEffect);
        if (!headEffect.unique()) headEffect.reset();
        myEffectChain.addEffect(midEffect);
        if (!midEffect.unique()) midEffect.reset();
        myEffectChain.addEffect(tailEffect);
        if (!tailEffect.unique()) tailEffect.reset();

    }
    
    virtual void TearDown()
    {
        
    }
    
    effectChain myEffectChain;
};

//====================================================================================
// detectFeedbackBenchmark
//
// Benchmarking for effectChain::detect_feedback()
//====================================================================================
BENCHMARK_F(niEffectsChainFixture, detectFeedbackBenchmark, 10, 10)
{
    myEffectChain.detect_feedback();
}

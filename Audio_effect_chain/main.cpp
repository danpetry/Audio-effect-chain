//
//  main.cpp
//
//  Created by Daniel Petry on 25/05/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//
//  Runs Google tests and Hayai benchmarks defined in effectChainTest.cpp

#include "hayai.hpp"
#include "gtest/gtest.h"

int main(int argc, char * argv[]) {
    
    testing::InitGoogleTest(&argc, argv);
    int unitTestResult = RUN_ALL_TESTS();

    hayai::ConsoleOutputter consoleOutputter;
    hayai::Benchmarker::AddOutputter(consoleOutputter);
    hayai::Benchmarker::RunAllTests();

    return unitTestResult;

}

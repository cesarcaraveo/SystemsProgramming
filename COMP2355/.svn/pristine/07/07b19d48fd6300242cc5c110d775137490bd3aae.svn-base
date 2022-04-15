//
//  Timer.cpp
//  Lab14
//
//  Created by Cesar Caraveo on 2/23/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include "Timer.hpp"

Timer::Timer() { elapsedTime = 0; }

void Timer::StartTimer() {
    startTime = std::chrono::high_resolution_clock::now();
}

double Timer::EndTimer() {
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto difference = stopTime - startTime;
    std::chrono::duration<double> time_span =
    std::chrono::duration_cast<std::chrono::duration<double>>(difference);
    elapsedTime = time_span.count();
    
    return elapsedTime;
}

double Timer::GetElapsedTime() { return elapsedTime; }


//
//  Timer.hpp
//  Lab13
//
//  Created by Cesar Caraveo on 2/21/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <fstream>
#include <stdint.h>

class Timer {
public:
    Timer();
    
    void StartTimer();
    double EndTimer();
    double GetElapsedTime();
    
private:
    std::chrono::high_resolution_clock::time_point startTime;
    double elapsedTime;
};

#endif // TIMER_H


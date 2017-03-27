//
//  timer.cpp
//  speller
//
//  Created by Захар on 27.03.17.
//  Copyright © 2017 Захар. All rights reserved.
//

#include "timer.hpp"
#include <iostream>

using namespace std;

double Timer::calculate(const struct rusage *b, const struct rusage *a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                  (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                 ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                  (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}

void Timer::start_timer(){
    getrusage(RUSAGE_SELF, &before);
}

void Timer::finish_timer(){
    getrusage(RUSAGE_SELF, &after);
}

void Timer::calculate_check_time(){
    check_time = calculate(&before, &after);
}

void Timer::show_time(){
    cout << "Time of checking is :" << check_time << endl;
}

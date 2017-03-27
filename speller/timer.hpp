//
//  timer.hpp
//  speller
//
//  Created by Захар on 27.03.17.
//  Copyright © 2017 Захар. All rights reserved.
//

#ifndef timer_hpp
#define timer_hpp

#include <stdio.h>
#include <iostream>

class Timer{
private:
    
    double check_time;
    struct rusage before, after;
    double calculate(const struct rusage *b, const struct rusage *a);
    
    
public:
    
    Timer(){
        check_time = 0.0;
    }
    
    void start_timer();
    
    void finish_timer();
    
    void calculate_check_time();
    
    void show_time();
    
};


#endif /* timer_hpp */

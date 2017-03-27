//
//  checker.cpp
//  speller
//
//  Created by Захар on 27.03.17.
//  Copyright © 2017 Захар. All rights reserved.
//

#include "checker.hpp"
#include "timer.hpp"

void Checker::check_text(){
    Timer timer;
    timer.start_timer();
    Loader loader;
    FILE dict = loader.open_dictionary();
    loader.load_dictionary(&dict);
    FILE txt = loader.open_text();
    loader.check_text(&txt);
    timer.finish_timer();
    timer.calculate_check_time();
    timer.show_time();
}

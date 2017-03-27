//
//  loader.hpp
//  loader
//
//  Created by Захар on 25.03.17.
//  Copyright © 2017 Захар. All rights reserved.
//

#ifndef loader_hpp
#define loader_hpp

#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class Loader{
private:
    
    FILE* dictionary;
    FILE* text;
    
public:
    map<string, string> map;
    
    Loader(){
        dictionary = NULL;
        text = NULL;
    }
    ~Loader(){
        fclose(dictionary);
        fclose(text);
    }
    
    bool check_file(FILE* file);
    
    void check_text(FILE* txt);
    
    void load_dictionary(FILE* dict);
    
    FILE open_dictionary();
    
    FILE open_text();
    
};

#endif /* loader_hpp */

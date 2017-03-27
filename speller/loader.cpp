//
//  loader.cpp
//  loader
//
//  Created by Захар on 25.03.17.
//  Copyright © 2017 Захар. All rights reserved.
//

#include "loader.hpp"
#include <stdio.h>
#include <iostream>
#include <map>
#include <cctype>
#define DICTIONARY "/Users/konstantyn/Desktop/loader/loader/"
#define TEXT "/Users/konstantyn/Desktop/loader/loader/alice.txt"
#define MAX_LENGTH_OF_WORD 45

using namespace std;


bool Loader::check_file(FILE* file){
    return file != NULL;
}

FILE Loader::open_dictionary(){
    dictionary = fopen(DICTIONARY, "r");
    if(check_file(dictionary))
        return *dictionary;
    fprintf(stderr, "Could not open dictionary");
    return *dictionary;
}

void Loader::load_dictionary(FILE* dict){
    char word[MAX_LENGTH_OF_WORD] = {0};
    int index = 0;
    for(int c = fgetc(dict); c != EOF; c = fgetc(dict)){
        if(isalpha(c) || (c == '\'' && index > 0)){
            word[index] = c;
            index++;
        }
        // we must have found a whole word
        else if (index > 0)
        {
            // terminate current word
            word[index] = '\0';
            map[word] = "correct";
            // update counter
            index = 0;            
        }
    }
}

FILE Loader::open_text(){
    text = fopen(TEXT, "r");
    if(check_file(text))
        return *text;
    fprintf(stderr, "Could not open text");
    return *text;
}

//ой ой, тут loader проверяет текст
void Loader::check_text(FILE* txt){
    int index = 0, misspellings = 0, words = 0;
    char word[MAX_LENGTH_OF_WORD] = {0};
    for (int c = fgetc(txt); c != EOF; c = fgetc(txt)){
        
        if (isalpha(c) || (c == '\'' && index > 0)){
            word[index] = tolower(c);
            index++;
        }
        else if (index > MAX_LENGTH_OF_WORD){
            // consume remainder of alphabetical string
            while ((c = fgetc(txt)) != EOF && isalpha(c));
                
            // prepare for new word
            index = 0;
        }
        else if (isdigit(c)){
            // consume remainder of alphanumeric string
            while ((c = fgetc(txt)) != EOF && isalnum(c));
                
            // prepare for new word
            index = 0;
        }
        else if (index > 0){
            
            word[index] = '\0';
            words++;
            
            if(map[word] != "correct"){
                misspellings++;
            }
            // prepare for new word
            index = 0;
        }
    }
    cout << "Misspelled words : " << misspellings << endl << "Words in text : " <<words << endl;
}


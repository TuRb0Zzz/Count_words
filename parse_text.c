#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "parse_text.h"
using namespace std;


ParseText::ParseText(const std::string& fileName){
    FILE *f;
    f=fopen(fileName.c_str(),"r");
    parseFile(f);
    closeFile(f);
}

void ParseText::parseFile(FILE *f){
    char word[50];
    std::string word1;
    cout<<"good";
    while (!feof(f)){
            fscanf(f,"%s ",word);
            word1=word;
            words.push_back(word1);
    }
}

void ParseText::closeFile(FILE *f){
    cout<<"close";
    fclose(f);
}

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "parse_text.h"
using namespace std;


ParseText::ParseText(const std::string& fileName){
    //getFirstWord();
    FILE *f;
    f=fopen(fileName.c_str(),"r");
    parseFile(f);
    closeFile(f);
}

ParseText::ParseText(const std::string& fileName, unsigned long long int maxWords){
    FILE *f;
    f=fopen(fileName.c_str(),"r");
    parseFileOgr(f,maxWords);
    closeFile(f);
}

void ParseText::parseFile(FILE *f){
    char word[50];
    std::string word1;
    while (!feof(f)){
            fscanf(f,"%s ",word);
            word1=word;
            words.push_back(word1);
    }
}

void ParseText::closeFile(FILE *f){
    fclose(f);
}

std::list<string> ParseText::returnList() const{
    return words;
}

void ParseText::parseFileOgr(FILE *f, unsigned long long maxWords){
    char word[50];
    std::string word1;
    long long int count=0;
    while (!feof(f) and count<= maxWords){
            fscanf(f,"%s ",word);
            word1=word;
            words.push_back(word1);
            count+=1;
    }
}

//const string ParseText::getFirstWord(){
//    currentWord=0;
//    return ;
//}

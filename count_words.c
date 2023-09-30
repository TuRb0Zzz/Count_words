#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "count_words.h"
#include <map>
using namespace std;



int CountWords::addWord(const std::string& word){
    countWords[word]++;
    return countWords[word];
}

void CountWords::writeToFile(){
    FILE *f;
    f=fopen("result.txt","w");
    int i=1;
    for(const auto& [key, value] : countWords){
        fprintf(f,"%d) %s %d \n",i,key.c_str(),value);
        i+=1;
    }
    fclose(f);
}


int CountWords::getCountWord(const string &word) const{
    return countWords.at(word);
}

CountWords::~CountWords(){
    writeToFile();
}

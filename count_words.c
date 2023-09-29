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
    f=fopen("count.txt","w");
    for(const auto& [key, value] : countWords){
        fprintf(f,"%s = %d \n",key.c_str(),value);
    }
    fclose(f);
}


int CountWords::getCountWord(const string &word) const{
    return countWords.at(word);
}

CountWords::~CountWords(){
    writeToFile();
}

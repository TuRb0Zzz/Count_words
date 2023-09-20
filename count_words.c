#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "count_words.h"
#include <map>
using namespace std;



void CountWords::InsertMap(const std::list<string>& list){
    for(auto item: list){
        if(countWords.count(item)==0){
            addWord(item);
        }
        else{
            countWords[item]=countWords[item]+1;
        }
    }
}

int CountWords::addWord(const std::string& word){
    countWords[word]=1;
    return 0;
}

void CountWords::writeToFile(){
    FILE *f;
    f=fopen("count.txt","a");
    for(const auto& [key, value] : countWords){
        fprintf(f,"%s = %d \n",key.c_str(),value);
    }
    fclose(f);
}

void CountWords::readFromFile(){
    setlocale(LC_ALL, "Russian");
    cout<<"start"<<endl;
    FILE *r;
    r=fopen("count.txt","r");
    char word[50];
    int* count;
    while(!feof(r)){
        fscanf(r,"%s = %d",word,count);
        countWords[word]=*count;
    }
    fclose(r);
}

CountWords::CountWords(){
    readFromFile();
}

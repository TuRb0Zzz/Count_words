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
    getFirstWord();
}

ParseText::ParseText(const std::string& fileName, unsigned long long int maxWords){
    FILE *f;
    f=fopen(fileName.c_str(),"r");
    parseFileOgr(f,maxWords);
    closeFile(f);
    getFirstWord();
}

void ParseText::parseFile(FILE *f){
    char word[50];
    std::string word1;
    while (!feof(f)){
            fscanf(f,"%s ",word);
            word1=word;
            for (int i = 0, len = word1.size(); i < len; i++){
                   if (ispunct(word1[i])){
                       word1.erase(i--, 1);
                       len = word1.size();
                   }
            }
            words.push_back(word1);
    }
}

void ParseText::closeFile(FILE *f){
    fclose(f);
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

const string ParseText::getFirstWord(){
    ParseText::currentWord=0;
    return words.front();
}

const string ParseText::getWordAt(int index) const{
    std::list<string> work = words;
    if (index==0 or index<0){
        return work.front();
    }
    else{
        if(index>words.size()){
            return work.back();
        }
    }
    work.resize(index);
    return work.back();
}

const pair <std::string,bool> ParseText::getNextWord() const{
   if(currentWord == words.size()+1){
       const pair <string, bool> para (words.back(),true);
       return para;
   }
   const pair <string, bool> para (getWordAt(currentWord),false);
   currentWord+=1;
   return para;
}


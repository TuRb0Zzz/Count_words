#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "parse_text.h"
using namespace std;


ParseText::ParseText(const std::string& fileName){
    openFile(fileName);
    parseFile();
    closeFile();
    getFirstWord();
}

ParseText::ParseText(const std::string& fileName, unsigned long long int maxWords){
    openFile(fileName);
    parseFileOgr(maxWords);
    closeFile();
    getFirstWord();
}

void ParseText::parseFile(){
    char word[64];
    std::string word1;
    while (!feof(f)){
            fscanf(f,"%s ",word);
            word1=word;
            string s="";
            for(int i=0; i<word1.size();i++){
                if (!ispunct(word1[i])){
                    s+=tolower(word1[i]);
                }
                else{
                    if (s!=""){
                        words.push_back(s);
                    }
                    s="";
                }
            }
            if (s!=""){
                words.push_back(s);
            }
    }

}

void ParseText::closeFile(){
    fclose(f);
}

void ParseText::openFile(const string &fileName){
    f=fopen(fileName.c_str(),"r");
}


void ParseText::parseFileOgr(unsigned long long maxWords){
    char word[64];
    std::string word1;
    long long i=0;
    while (!feof(f) and i<maxWords){
            fscanf(f,"%s ",word);
            word1=word;
            string s="";
            for(int i=0; i<word1.size();i++){
                if (!ispunct(word1[i])){
                    s+=tolower(word1[i]);
                }
                else{
                    if (s!=""){
                        words.push_back(s);
                    }
                    s="";
                }
            }
            if (s!=""){
                words.push_back(s);
            }
    }
    i+=1;
}

const string ParseText::getFirstWord(){
    ParseText::currentWord=0;
    return words.front();
}

const string ParseText::getWordAt(int index) const{
    std::list<string> work = words;
    if (index<0 or index>words.size()){
        return "";
    }
    work.resize(index+1);
    return work.back();
}

const pair <std::string,bool> ParseText::getNextWord() const{
   if(currentWord == words.size()){
       const pair <string, bool> para (words.back(),true);
       return para;
   }
   const pair <string, bool> para (getWordAt(currentWord),false);
   currentWord+=1;
   return para;
}



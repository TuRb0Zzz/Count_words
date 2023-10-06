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
        fprintf(f,"%d\t%s\t%d\n",i,key.c_str(),value);
        i+=1;
    }
    fclose(f);
}


int CountWords::getCountWord(const string &word) const{
    return countWords.at(word);
}

std::list<std::pair<std::string, int >> CountWords::getMaxCountWord(){
    std::vector<std::pair<std::string, int>> countWords_vec;
    for(auto& i : countWords){
        countWords_vec.push_back(std::pair<std::string, int> {i.first, i.second});
    }
    std::sort(countWords_vec.begin(), countWords_vec.end(), [](std::pair<std::string, int> left, std::pair<std::string, int>right){
        return left.second > right.second;});
    std::list<std::pair<std::string, int>> ret_list;
    while(ret_list.size() < 10){
        ret_list.push_back(countWords_vec[ret_list.size()]);
    }
    return ret_list;
}

std::list<std::pair<std::string, int>> CountWords::getMinCountWord(){
    std::vector<std::pair<std::string, int>> countWords_vec;
    for(auto& i : countWords){
        countWords_vec.push_back(std::pair<std::string, int> {i.first, i.second});
    }
    std::sort(countWords_vec.begin(), countWords_vec.end(), [](std::pair<std::string, int> left, std::pair<std::string, int>right){
            return left.second < right.second;});
    std::list<std::pair<std::string, int>> ret_list;
    while(ret_list.size() < 10 && ret_list.size() < countWords_vec.size()){
        ret_list.push_back(countWords_vec[ret_list.size()]);
    }
    return ret_list;
}



CountWords::~CountWords(){
    writeToFile();
}

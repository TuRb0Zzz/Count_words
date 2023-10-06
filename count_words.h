#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#ifndef COUNT_WORDS_H
#define COUNT_WORDS_H


class CountWords {
    private :
        std::map<string,int> countWords;
    public :
        ~CountWords();
        void writeToFile();
        int getCountWord(const std::string& word) const;
        int addWord(const std::string& word);
        std::list<std::pair<string, int >> getMaxCountWord();
        std::list<std::pair<string, int >> getMinCountWord();
};




#endif

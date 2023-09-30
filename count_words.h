#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <map>
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
        //const std::list<std::pair<std::string, int >> getMaxCountWord() : const;
        //const std::list<std::pair<std::string, int >> getMinCountWord() : const;
};




#endif

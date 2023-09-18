#include <iostream>
#include <string>


#ifndef COUNT_WORDS_H
#define COUNT_WORDS_H

using namespace std;

class CountWords {
    private :
        std::map<string,int> countWords;
    public :
        CountWords();
        ~CountWords();
        int getCountWord(const std::string& word) const;
        int addWord(const std::string& word);
        const std::list<std::pair<std :string, int >>&
        getMaxCountWord() : const;
        const std::list<std::pair<std :string, int >>&
        getMinCountWord() : const;
};




#endif

#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;


#ifndef PARSE_TEXT_H
#define PARSE_TEXT_H


class ParseText {
    private :
        std::list<std::string> words;
        inline static int currentWord;
        void parseFile(FILE *f);
        void parseFileOgr(FILE *f, unsigned long long int maxWords);
        void closeFile(FILE *f);
    public :
        ParseText(const std::string& fileName);
        ParseText(const std::string& fileName, unsigned long long int maxWords);
        const string getFirstWord();
        const pair<std::string, bool> getNextWord() const;
        const string getWordAt(int index) const;
};


#endif

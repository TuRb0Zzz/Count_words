#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;


#ifndef PARSE_TEXT_H
#define PARSE_TEXT_H


class ParseText {
    private :
        FILE *f;
        std::list<std::string> words;
        inline static int currentWord;
        void parseFile();
        void openFile(const std::string& fileName);
        void parseFileOgr(unsigned long long int maxWords);
        void closeFile();
    public :
        ParseText(const std::string& fileName);
        ParseText(const std::string& fileName, unsigned long long int maxWords);
        const string getFirstWord();
        const pair<std::string, bool> getNextWord() const;
        const string getWordAt(int index) const;
};


#endif

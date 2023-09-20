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
        static int currentWord;
        void parseFile(FILE *f);
        void parseFileOgr(FILE *f, unsigned long long int maxWords);
        void closeFile(FILE *f);
    public :
        //ParseText() = delete;
        std::list<string> returnList() const;
        ParseText(const std::string& fileName);
        ParseText(const std::string& fileName, unsigned long long int maxWords);
        //~ParseText();
        //const string getFirstWord();
        //const pair<std::string, bool/*isLastWord? */>&
        //const string getWordAt(int index);
};


#endif

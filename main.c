#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "parse_text.h"
#include "count_words.h"
using namespace std;


int main(){
    //******************************
    CountWords words;
    const ParseText parseText("text.txt");
    //******************************

    while (true){
        const auto &[string,islast] = parseText.getNextWord();
        if (islast==true){
            break;
        }
        words.addWord(string);
    }
    return 0;
}

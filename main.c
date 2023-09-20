#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "parse_text.h"
#include "count_words.h"
using namespace std;


int main(){
    //setlocale(LC_ALL, "Russian");
    CountWords words;
    const ParseText parseText("text.txt");
    words.InsertMap(parseText.ParseText::returnList());
    words.writeToFile();
    return 0;
}

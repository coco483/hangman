/*
    Makes new file "selectedWordList.h" by copying long enough 
    words from "words.txt"
*/
#include <iostream>
#include <fstream>

#define MIN_LEN (7)

int main(){
    std::ofstream newWordFile("selectedWordList.h");
    std::ifstream prevWordFile("words.txt");
    std::string line;
    if (newWordFile.is_open()&&prevWordFile.is_open()){
        newWordFile << "#include <string>\n"
        "#include <vector>\n"
        "static std::vector<std::string> wordList = { ";
        do {
            if (line.size() >= MIN_LEN) {
                newWordFile << "\""<<line<<"\", ";
            }
        } while ( std::getline (prevWordFile, line) );
        newWordFile <<"\""<<line<<"\"};";
        newWordFile.close();
        prevWordFile.close();
    }
}
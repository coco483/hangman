//#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <random>
#include <cassert>
#include <ctime>
#include "selectedWordList.h"

#define MAX_LIVES 7; //shouldn't be bigger than 7

using std::cout; using std::cin; using std::endl;
using std::string; using std::set; using std::vector;

extern vector<string> wordList;
void startGame();
string randomWord();
void printHangman(int);


int main(void){
    //using namespace std;
    while (true){
        char ans;
        cout << "start game? (y/n): ";
        ans = getchar();
        while(getchar() != '\n'){}
        if (ans=='y') startGame();
        else if (ans == 'n') break;
    }
}
void startGame(void){
    cout << "\nlet's play!" << endl;
    string word = randomWord();
    int lives = MAX_LIVES;
    set<char> crossedOut;
    char ch;
    while (true){
        cout <<endl;
        printHangman(lives);
        int charLeft = 0;
        for (auto i :word){
            if (i == ' ') cout << ' ';
            else if (crossedOut.count(i)) cout << i;
            else {
                cout << '_';
                charLeft++;
            }
        }
        if (charLeft == 0){
            cout << "\nYou guessed the word! congrats!\n" <<endl;
            break;
        }
        cout << "\n\nEnter an alphabet: ";
        ch = getchar();
        while(getchar() != '\n'){}
        ch = tolower(ch);
        if (!isalpha(ch)){
            cout << "Please enter an alphabet" <<endl;
            continue;
        } else if (crossedOut.count(ch) == 1) {
            cout << "You already tried this alphabet" <<endl;
            continue;
        }
        crossedOut.insert(ch);
        if ((word.find(ch) != string::npos)) cout << "success!" << endl;
        else {
            if (--lives <= 0) {
                printHangman(0);
                cout << "Game over! The word was: "<<word<<"\n" << endl;
                break;
            }
            cout << "failed! " << lives << " lives left!" << endl;
        }
    }
}

void printHangman(int lives)
{
    assert((lives>=0) && (lives<=7));
    string hangmanImage = //9*7
        "   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "  /|\\  |\n"
        "  / \\  |\n"
        "       |\n"
        "========    ";
    int mask[] = {40, 38, 31, 30, 29, 21};
    for (int i=0; i <lives-1; i++){
        hangmanImage[mask[i]] = ' ';
    }
    if (lives==0) hangmanImage[mask[5]] = 'X';
    cout<<hangmanImage;
}

string randomWord(){
    static std::random_device rd;
    static std::mt19937_64 gen((unsigned int) std::time(NULL));
    static std::uniform_int_distribution<int> dist(0, wordList.size()-1);
    string word = wordList[dist(gen)];
    for (char ch : word){
        ch = tolower(ch);
    }
    return word;
}
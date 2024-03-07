//#include <stdio.h>
#include <iostream>
#include <string>
#include <set>

#define LIVES 5;

using std::cout, std::cin, std::string, std::endl, std::set;
void startGame();
string randomWord();

int main(void){
    //using namespace std;
    while (true){
        char ans;
        cout << "start game? (y/n): ";
        cin >> ans;
        if (ans=='y') startGame();
        else if (ans == 'n') break;
    }
}

void startGame(void){
    cout << "let's play!" << endl;
    string word = randomWord();
    int lives = LIVES;
    set<char> crossedOut;
    char ch;
    while (true){
        cout <<endl;
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
            cout << endl << "You guessed the word! congrats!" <<endl;
            break;
        }
        cout << endl << "Enter an alphabet: ";
        cin >> ch;
        if (!isalpha(ch)){
            cout << "Please enter an alphabet" <<endl;
            continue;
        } else if (crossedOut.count(ch)) {
            cout << "You already tried this alphabet" <<endl;
            continue;
        }
        crossedOut.insert(ch);
        if ((word.find(ch) != string::npos)) cout << "success!" << endl;
        else {
            if (--lives <= 0) {
                cout << "Game over!" << endl;
                break;
            }
            cout << "failed! " << lives << " lives left!" << endl;
        }
    }
}

string randomWord(){
    return "hello world";
}
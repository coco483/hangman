//#include <stdio.h>
#include <iostream>
#include <string>
#include <set>

#define MAX_LIVES 7;

using std::cout; using std::cin; using std::endl;
using std::string; using std::set;

void startGame();
string randomWord();
void printHangman(int);

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
            cout << "\n You guessed the word! congrats!" <<endl;
            break;
        }
        cout << endl << "Enter an alphabet: ";
        ch = getchar();
        while(getchar() != '\n'){}
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
                cout << "Game over!" << endl;
                break;
            }
            cout << "failed! " << lives << " lives left!" << endl;
        }
    }
}

void printHangman(int lives)
{
    string hangmanImage = //9*7
        "   +---+\n"
        "   |   |\n"
        "   O   |\n"
        "  /|\\  |\n"
        "  / \\  |\n"
        "       |\n"
        "========\n";
    int positions[] = {40, 38, 31, 30, 29, 21};
    for (int i=0; i <lives-1; i++){
        hangmanImage[positions[i]] = ' ';
    }
    cout<<hangmanImage<<endl;
}

string randomWord(){
    return "hello world";
}
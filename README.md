MoonJung Kim
lunatic2959@gmail.com

simple hangman game wrote by c++

"words.txt" file is from https://www.ef.com/wwen/english-resources/english-vocabulary/top-3000-words/

In this project, I use word list from "selectedWordList.h", a modified version of "words.txt" file by excluding too short words.



found bugs:

fixed bugs
 - 이미 입력한 알파벳을 다시 입력할 때 success로 처리됨 
 - when multiple characters are typed together, get the first character and flush the rest
 - 첫 시도에 무조건 Please enter an alphabet이 뜬다
 - random() returns the same value each execution
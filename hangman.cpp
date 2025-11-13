//starting
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <cctype>

using namespace std;


//gives instructions 
void instructions(){
    cout<<"\nYou need instructions. Haha, I haven't made them yet! =)";
}

//main function
int main(){
    //variables
    string answer, shownAnswer, wantRules, playAgain, letter, lowerLetter;
    char guess, letterGuessed;
    int guessNum, wrongMax, letterPlace, counter=0;
    vector <string> rights, wrongs;

    //intro
    cout<<"Hello and welcome to this two person game of hangman!";
    cout<<"\nIf you need instructions on how to play please enter 'y' otherwise enter 'n': ";
    cin>>wantRules;
    //going to instruction
    if (wantRules.find("y")<6){
        instructions();
    }

    //getting answer
    cout<<"\nPlease have the guesser look away, and enter the phrase you want them to guess.\n";
    cin>>ws;
    getline(cin, answer);

    //changing answer
    for (int i=0; i<answer.length(); i++){
        answer[i]=toupper(answer[i]);
    }
    shownAnswer=answer;
    for (int i='A'; i<='Z'; i++){
        do {
            letterPlace=shownAnswer.find(i);
            if (letterPlace!=-1){
                shownAnswer.replace(letterPlace, 1, "-");
                counter++;
            }
        } while (letterPlace!=-1);
    }
    cout<<shownAnswer;

    //game loop
    while (answer!=shownAnswer){
        cout<<"\nPlease guess a letter: ";
        cin>>letterGuessed;
        letter=toupper(letterGuessed);
        lowerLetter=tolower(letterGuessed);
        if (answer.find(letter)<answer.length()){
            do {
                letterPlace=answer.find(letter);
                if (letterPlace!=-1){
                    answer.replace(letterPlace, 1, lowerLetter);
                    shownAnswer[letterPlace]=toupper(letterGuessed);
                }
            } while (letterPlace!=-1);
            
            rights.push_back(letter);
        } else {
            wrongs.push_back(letter);
            cout<<"Sorry, that letter isn't in the word.";
        }
        cout<<shownAnswer;

    }
    return 0;
}
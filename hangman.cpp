//starting
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>

using namespace std;


//gives instructions 
void instructions(){
    cout<<"\nYou need instructions. Haha, I haven't made them yet! =)";
}

//main function
int main(){
    //variables
    string answer, shownAnswer, wantRules, playAgain, letterGuessed;
    char guess;
    int guessNum, wrongMax, letterPlace;
    vector <string> rights, wrongs;

    //intro
    cout<<"Hello and welcome to this two person game of hangman!";
    cout<<"\nIf you need instructions on how to play please enter 'y' otherwise enter 'n'";
    cin>>wantRules;
    //going to instruction
    if (wantRules.find("y")<6){
        instructions();
    }

    //getting answer
    cout<<"\nPlease have the guesser look away, and enter the phrase you want them to guess.";
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
            }
        } while (letterPlace!=-1);
    }
    cout<<shownAnswer;

    //game loop
    while (answer!=shownAnswer){
        cout<<"Please guess a letter: ";
        cin>>letterGuessed;
        cout<<answer.find(letterGuessed);
        if (answer.find(letterGuessed)<answer.length()){
            for (int i='A'; i<='Z'; i++){
                do {
                    letterPlace=answer.find('A');
                    shownAnswer[letterPlace]=i;
                } while (letterPlace!=-1);
            }
            rights.push_back(letterGuessed);
        } else {
            wrongs.push_back(letterGuessed);
            cout<<"Sorry, that letter isn't in the word.";
        }
        cout<<shownAnswer;

    }
    return 0;
}
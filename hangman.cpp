//starting
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>


using namespace std;

//getting the word oiptions for the one player game

set <string> getWords() {
    set <string> goodWords;       // Create empty set
    set <string> newWords;
    ifstream file("words.txt");    // Open file
    string word;                   // Variable to hold each word
    
    // Read each word from file and add to set
    while (file >> word) {
        goodWords.insert(word);             // Add word to set
    }

    //capitalizing
    for (const std::string& word : goodWords) {
        std::string upperWord = word; // Create a modifiable copy
        for (char& c : upperWord) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }
        newWords.insert(upperWord);
    }
    return newWords;                       // Return the complete set
}

//getting a random answer
string randomWord(set <string> wordleAnswers){
    auto it = wordleAnswers.begin();

    // Advance the iterator to the random spot
    advance(it, rand()%wordleAnswers.size()); 

    //returning answer
    return *it;
}

//gives instructions 
void instructions(){
    cout<<"\nThis is a one or two player game of hangman. In the two player game one person enters the sentence or word for the other. \nFor the one player game the answer will be a randomly generated weird English word. Becareful, you might never have even heard it before! \nIn both games the guesser then guesses letters to figure out the word. \nWhen a letter is wrong the hangman will get another body part. \nYou can only make 10 incorrect guesses so I'd be careful. \nGood luck!";
}

//having the hangman in a function to look better
string hungman(int wrongLeft){
    string guys[11]={
             "\n   |------|  "
             "\n   |         "
             "\n   |         "
             "\n   |         "
             "\n   |         "
             "\n   |         "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |         "
             "\n   |         "
             "\n   |         "
             "\n   |         "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |      O  "
             "\n   |         "
             "\n   |         "
             "\n   |         "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |      O  "
             "\n   |      |  "
             "\n   |         "
             "\n   |         "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |      O  "
             "\n   |      |- "
             "\n   |         "
             "\n   |         "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |      O  "
             "\n   |      |--"
             "\n   |         "
             "\n   |         "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |      O  "
             "\n   |     -|--"
             "\n   |         "
             "\n   |         "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |      O  "
             "\n   |    --|--"
             "\n   |         "
             "\n   |         "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |      O  "
             "\n   |    --|--"
             "\n   |      |  "
             "\n   |         "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |      O  "
             "\n   |    --|--"
             "\n   |      |  "
             "\n   |     /   "
             "\n___|___      ",
             "\n   |------|  "
             "\n   |      |  "
             "\n   |      O  "
             "\n   |    --|--"
             "\n   |      |  "
             "\n   |     / \\ "
             "\n___|___      ",
               };
    return(guys[10-wrongLeft]);
}

//main function
int main(){
    //variables
    string answer, shownAnswer, wantRules, playAgain="y", letter, lowerLetter, totalGuesses="", answerForChecking;
    char guess, letterGuessed;
    int guessNum=0, wrongMax=10, letterPlace, numPlayers, counter=0, wrongLeft=10, streak=0, maxStreak=0, wins=0;
    vector <string> rights, wrongs;
    set <string> onePlayerWords=getWords();

    //random
    srand(time(0));

    //intro
    cout<<"Hello and welcome to this game of hangman!";
    cout<<"\nIf you need instructions on how to play please enter 'y' otherwise enter 'n': ";
    cin>>wantRules;
    //going to instruction
    if (wantRules.find("y")<6){
        instructions();
    }

    //one or two players
    cout<<"Do you want to play the one or two player version? (enter 1 or 2)\nWarning that the one player version's words are unusual words: ";
    cin>>numPlayers;

    if (numPlayers!=1&&numPlayers!=2){
        cout<<"You didn't enter that correctly, sorry.\nPlease enter a 1 for one player or a 2 for two player: ";
        cin>>numPlayers;
    }

    while (numPlayers!=1&&numPlayers!=2){
        cout<<"You didn't enter that correctly again, sorry.\nA two player game requires somebody to choose the word/sentence and for the other person to guess it. \nOne person means that the answer is a fun sounding English word.\nPlease enter a 1 for one player or a 2 for two player: ";
        cin>>numPlayers;
    }


    while (playAgain.find("y")<playAgain.length()){
        system("clear");
        //getting answer for 2 player
        if (numPlayers==2){
            cout<<"\nPlease have the guesser look away, and enter the phrase you want them to guess.\n";
            cin>>ws;
            getline(cin, answer);
        }

        //getting word for 1 player
        answer=randomWord(onePlayerWords);
        //answer="Appleloosa";

        system("clear");

        //changing answer
        for (int i=0; i<answer.length(); i++){
            answer[i]=toupper(answer[i]);
        }
        answerForChecking=answer;
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
        while (answerForChecking!=shownAnswer&&wrongLeft>0){
            //making sure it isn't a repeat letter
            do {
                cout<<"\nPlease guess a new letter: ";
                cin>>letterGuessed;
                letter=toupper(letterGuessed);
            } while (totalGuesses.find(letter)<totalGuesses.length());

            //getting char and string weirdness to work
            totalGuesses.append(letter);
            lowerLetter=tolower(letterGuessed);

            //seeing if it is in the answer
            if (answer.find(letter)<answer.length()){
                //while there are multiple
                do {
                    letterPlace=answer.find(letter);
                    if (letterPlace!=-1){
                        answer.replace(letterPlace, 1, lowerLetter);
                        shownAnswer[letterPlace]=toupper(letterGuessed);
                    }
                } while (letterPlace!=-1);
                //adding to rights and wrongs
                rights.push_back(letter);
            } else {
                wrongs.push_back(letter);
                //showing hat it is wrong
                cout<<"Sorry, that letter isn't in the word.\n";
            }
            //clearing and showing answer
            system("clear");
            cout<<shownAnswer;
            wrongLeft=wrongMax-wrongs.size();
            cout<<hungman(wrongLeft);
            //showing wrong guesses
            if (wrongs.size()>0){
                cout<<"\nThe wrong letters so far are: \n";
            }
            for (int i=0; i<wrongs.size(); i++){
                cout<<wrongs[i]<<", ";
            }
            cout<<"\nYou have "<<wrongLeft<<" wrong guesses left. \n";
        }
        
        //showing output
        if (shownAnswer==answerForChecking){
            cout<<"\nYou won!\nGood Job.";
            streak+=1;
            //streaks
            if (streak>=maxStreak){
                maxStreak=streak;
            }

            //two players
            if (numPlayers==2){
                cout<<"\nBetter luck next time sentence maker.";
            }
            //streaks
            cout<<"Your curent streak is "<<streak;
        } else {
            cout<<"Ah well, you lost your streak. \nThe answer was "<<answerForChecking;
            if (numPlayers==2){
                cout<<"\nGood job sentence maker.";
            }
            streak=0;
        }

        //playing again
        cout<<"\nDo you want to play again? ";
        cin>>playAgain;


        //resetting
        wrongs.clear();
        rights.clear();
        totalGuesses="";
    }
    //results
    cout<<"You had a maximum streak of "<<maxStreak<<". \nAnd a current streak of "<<streak;
    cout<<"\nHave a good day!";

    //ending
    return 0;
}
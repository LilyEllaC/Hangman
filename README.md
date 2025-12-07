## C++ terminal Hangman game

## Includes

*   **1 or 2 players** allows for either someone to create the sentence that is guessed or a random word from the word bank
*   **ASCII art** an image slowly gets drawn everytime a wrong letter is guessed

## ⬇️ Installation and Setup

To play the game, you need to download and run the pre-compiled executable for your operating system.

### Prerequisites

*   A compatible operating system (Linux).

### How to Run the Game

1.  **Download:** Get the latest executable the [itch.io page](https://lilyec.itch.io/hangman).
2.  **Navigate:** Open your terminal or command prompt and go to the directory where you downloaded the executable.
3.  **Execute:** Run the game using the appropriate command for your system:

    ```bash
    .\hangman
    ```

## 🎮 How to Play

Follow the on-screen instructions to guess the hidden word.
*   Choose whether you want to play the 1 person or 2 person version
*   If you chose the 2 person version, the guesser will have to look away for the writer to input the phrase
*   If you chose the 1 person version the game will start
*   You will see a series of dashes - representing the letters in the word.
*   You have a 10 incorrect guesses at the start.
*   Type a single letter and press `Enter`.
*   If your guess is correct, the letter will be revealed in the word.
*   If your guess is incorrect, a part of the hangman will be drawn, and you will get closer to losing.
*   The game ends when you guess all of the correct letters or the hangman is fully drawn.

## 🛠️ Building from Source (For Developers)

If you wish to compile the game yourself (perhaps to contribute or run on an unsupported platform), you will need a C++ compiler (like g++ testing but others will likely work).

1.  **Clone the Repository:**

2.  **Build the Game and launch:**
    
    i.e. source launch
    
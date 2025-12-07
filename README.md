# Classic C++ Console Hangman

A simple, old-school terminal-based Hangman game built with C++. Download the executable and play a timeless word-guessing game right in your command prompt or terminal!

## 🚀 Features

*   **Classic Gameplay:** Guess the hidden word one letter at a time.
*   **ASCII Art:** Visual representation of the hangman updates with each incorrect guess. 
*   **Simple & Lightweight:** A pure C++ console application with no external dependencies.

## ⬇️ Installation and Setup

To play the game, you need to download and run the pre-compiled executable for your operating system.

### Prerequisites

*   A compatible operating system (Linux).
*   A terminal or command prompt application (e.g., Terminal).

### How to Run the Game

1.  **Download:** Get the latest executable from the [Releases page](https://github.com/LilyEllaC/Hangman) or download it directly from the [itch.io page](ADD_YOUR_ITCH_IO_URL_HERE).
2.  **Navigate:** Open your terminal or command prompt and go to the directory where you downloaded the executable.
3.  **Execute:** Run the game using the appropriate command for your system:

    *   **Windows:**
        ```bash
        .\hangman_win.exe
        ```
    *   **macOS / Linux:**
        ```bash
        ./hangman_linux
        # If necessary, first make it executable with: chmod +x hangman_linux
        ```

    *Note: The executable expects a dictionary file (e.g., `words.txt`) as an argument. Make sure this file is in the same directory or provide the correct path.*
    ```bash
    .\hangman_win.exe words.txt
    ```

## 🎮 How to Play

Follow the on-screen instructions to guess the hidden word.
*   You will see a series of dashes - representing the letters in the word.
*   You have a limited number of incorrect guesses (lives).
*   Type a single letter and press `Enter`.
*   If your guess is correct, the letter will be revealed in the word.
*   If your guess is incorrect, a part of the hangman will be drawn, and you lose a life.
*   The game ends when you guess the word correctly or the hangman is fully drawn.

## 🛠️ Building from Source (For Developers)

If you wish to compile the game yourself (perhaps to contribute or run on an unsupported platform), you will need a C++ compiler (like g++ or Clang) and Make.

1.  **Clone the Repository:**
    ```bash
    git clone github.com
    cd YOUR_REPO_NAME
    ```

2.  **Build the Game:**
    ```bash
    make
    ```


## 🧑‍💻 Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request if you find a bug or have a suggestion for improvement.


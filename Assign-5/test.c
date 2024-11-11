#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6 // Number of allowed incorrect attempts

void lowa(char stringo[]);
void displayHangman(int tries);
void initializeGuessedWord(char guessedWord[], int length);

struct WordandHint {
    char word[30];
    char hint[100];
};

int main() {
    srand(time(0)); // Initialize random seed

    char mode[10];
    printf("\n\n\t\t\t\t\t\t\tWelcome to the Hangman Game! \n\tThe rules of this game are - There is a given word with omitted characters and you need to guess the characters to win the game. \n\t  You get limited chances only, use them wisely, don't mess it up, cause you don't wanna murder an imaginary person do you? \n\t\t\t\t\t\t   Now enough talk let's start the game. \n\n\t\t\t\t   Now what mode do you wanna play this in Easy, Intermediate or Hard?"); 
    fgets(mode, sizeof(mode), stdin);
    lowa(mode);  // Convert input to lowercase
    strtok(mode, "\n");  // Remove newline character

    // Define word lists for each difficulty level
    struct WordandHint easyWords[] = {
        {"programming", "Implementation of logic"},
        {"pizza", "Popular Italian dish"},
        {"cheese burger", "American, 'Freedom'"},
        {"france", "Revolution"}
    };

    struct WordandHint intermediateWords[] = {
        {"despacito", "Spanish"},
        {"fahrenheit", "American unit"},
        {"saxophone", "Instrument"},
        {"lieutenant", "High post"}
    };

    struct WordandHint hardWords[] = {
        {"farhanitrate", "Chemical-sounding word"},
        {"prerajulisation", "Historical reformation"},
        {"megatron", "Fictional character"},
        {"quaff", "To drink heartily"}
    };

    struct WordandHint *selectedWords;
    int wordCount = 0;

    // Select word list based on mode
    if (strcmp(mode, "easy") == 0) {
        selectedWords = easyWords;
        wordCount = sizeof(easyWords) / sizeof(easyWords[0]);
    } else if (strcmp(mode, "intermediate") == 0) {
        selectedWords = intermediateWords;
        wordCount = sizeof(intermediateWords) / sizeof(intermediateWords[0]);
    } else if (strcmp(mode, "hard") == 0) {
        selectedWords = hardWords;
        wordCount = sizeof(hardWords) / sizeof(hardWords[0]);
    } else {
        printf("Invalid mode selected. Please restart and choose easy, intermediate, or hard.\n");
        return 1;
    }

    // Randomly select a word from the chosen difficulty level
    int wordsIndex = rand() % wordCount;
    const char* secretWord = selectedWords[wordsIndex].word;
    const char* hint = selectedWords[wordsIndex].hint;
    int wordLength = strlen(secretWord);

    // Initialize guessed word with underscores
    char guessedWord[wordLength + 1];
    initializeGuessedWord(guessedWord, wordLength);

    int tries = 0; // Incorrect attempts
    char guessedLetters[26] = {0}; // Array to track guessed letters
    int guessedLettersCount = 0;

    printf("\nHint: %s\n", hint);

    // Game loop
    while (tries < MAX_TRIES) {
        printf("\nCurrent word: %s\n", guessedWord);
        printf("Attempts left: %d\n", MAX_TRIES - tries);
        displayHangman(tries);

        printf("Guessed letters: ");
        for (int i = 0; i < guessedLettersCount; i++) {
            printf("%c ", guessedLetters[i]);
        }
        printf("\n");

        char guess;
        printf("Enter your guess (a single letter): ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if (!isalpha(guess)) {
            printf("Invalid input. Please enter a letter.\n");
            continue;
        }

        // Check if letter has already been guessed
        int alreadyGuessed = 0;
        for (int i = 0; i < guessedLettersCount; i++) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = 1;
                break;
            }
        }

        if (alreadyGuessed) {
            printf("You've already guessed that letter.\n");
            continue;
        }

        // Store the guessed letter
        guessedLetters[guessedLettersCount++] = guess;

        // Check if guess is in the word
        int correctGuess = 0;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = 1;
            }
        }

        // If no match found, increase the number of tries
        if (!correctGuess) {
            tries++;
            printf("Incorrect guess!\n");
        } else {
            printf("Good guess!\n");
        }

        // Check if the player has won
        if (strcmp(secretWord, guessedWord) == 0) {
            printf("\nCongratulations! You've guessed the word: %s\n", secretWord);
            displayHangman(tries);
            return 0;
        }
    }

    // If the player loses
    printf("\nSorry, you've been hanged! The word was: %s\n", secretWord);
    displayHangman(tries);
    return 0;
}

// Convert a string to lowercase
void lowa(char stringo[]) {
    for (int i = 0; stringo[i]; i++) {
        stringo[i] = tolower(stringo[i]);
    }
}

// Initialize guessed word with underscores
void initializeGuessedWord(char guessedWord[], int length) {
    for (int i = 0; i < length; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[length] = '\0';
}

// Display the current hangman state
void displayHangman(int tries) {
    switch (tries) {
        case 0:
            printf("  +---+\n      |\n      |\n      |\n     ===\n");
            break;
        case 1:
            printf("  +---+\n  O   |\n      |\n      |\n     ===\n");
            break;
        case 2:
            printf("  +---+\n  O   |\n  |   |\n      |\n     ===\n");
            break;
        case 3:
            printf("  +---+\n  O   |\n /|   |\n      |\n     ===\n");
            break;
        case 4:
            printf("  +---+\n  O   |\n /|\\  |\n      |\n     ===\n");
            break;
        case 5:
            printf("  +---+\n  O   |\n /|\\  |\n /    |\n     ===\n");
            break;
        case 6:
            printf("  +---+\n  O   |\n /|\\  |\n / \\  |\n     ===\n");
            break;
    }
}

// Natasha Johnson, CSC C++ class, July 15th 2021
// Keywords
// This is my text based game for the assignment C++ Building Code Breaker Training Simulation Program for CIA Recruits
// I tried to get the sleep function to work to "take a break" before the next line but it wouldn't work so I googled it and it said to use these preprocessors to make usleep work
// The Windows.h is saying for the program to run in windows... This was not working for me
#ifdef _WIN32
#include <Windows.h>
// The next lines tell the program to run unistd.h (linux) if the user is not using Windows
#else
#include <unistd.h>
#endif
/* The next line is a preprocessor directive, it is indicated with the # symbol. The preprocessor
runs before the compiler and substitutes text based on various directived. The # is telling the 
program to include the contents of the iostream and string, which are part of the standard library */
#include <iostream>
#include <cstdlib>
// The next line indicates that I want to use the standard namespace for the entire program
// It makes the text shorter and when you type a lot makes your code a little easier
using namespace std;

// The following lines of code are for the total number of correct, wrong, and total answers at the end of the game.
// Declare and intitalize the integer <correctAnswers> to 0
int correctAnswers = 0; 
// Declare and intitalize the integer <wrongAnswers> to 0
int wrongAnswers = 0; 
// Declare and intitalize the integer <totalAnswers> to 0
int totalAnswers = 0; 
string wordArray[3];

/* The next line is the header of a function of main(). Int indicates that the function will
return a value, in this case it indicates that the functions will return an integer value */
int main()
{
// An enumeration is a distinct type whose value is restricted to a range of values (see below for details), which may include several explicitly named constants ("enumerators"). 
// The values below in the {} are the enumerations I chose (my words to guess and their descritption).
// The enum fields states that the first part is the words to guess, the second is the hint.
	enum fields { WORD, HINT, NUM_FIELDS };
// This indicates that there are 10 words listed in the enumeration field.
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"steganography", "Method of hiding codes inside pictures."},
		{"encryption", "A method of scrambling the data so that it is unreadable without the key."},
		{"morse code", "Once used to transmit messages around the world, this system can still be used in certain situations to send messages effectively when alternate mediums are not available.."},
		{"language", "Speech or other forms of communication.."},
		{"codex", "A code, or body of laws."},
		{"cryptography", "The practice and study of techniques for secure communication in the presence of third parties called adversaries."},
		{"inscribe", "To write or carve words into something, or to write a message in a book.."},
		{"encipher", "To convert plain text into cipher; to encrypt."},
		{"transmission", "The process of sending and propagating an analogue or digital information signal."},
		{"decode", "The reverse process of encoding, converting code symbols back into a form that the recipient understand, such as English or Spanish."},
	};
/* As stated in my previus assignment, cout is an object, and is used to send data to the standart output string. The << says
to send the string to cout. At the end the endl string is being sent to the standard output with the << and is the same as saying 
"hit the enter button" It is used throughout the program as it is a text based game and outputs many strings*/		
	cout << "\t\tInstructions\n\n";
	cout << "Greetings. Please use your codebreaking skills to help our country.\n";
	cout << "I am going to give you 3 different keywords to unscramble." << endl;
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'pass' to pass on the current word.\n\n";
// If the total number of questions answered is less than 3 the game will continue. If it is 3 (or more, but that is not possible) then the game will go to the ending code and skip over more questions.	
	for (int i = 0; i < 3; ++i)
	{
// The following line makes use of the computer's internal clock to control the choice of the seed. Since time is continually changing, the seed is going to forever changing.
// The difference between this code and my last assignment, is instead of using a "time" this code is making the keyword called random out of my enumerated words.
		srand(time(0));
		int words = (rand() % NUM_WORDS);
// As long as they have answered less than three questions
		for (int c = 0; c < 3; ++c)
		{
			while (WORDS[words][WORD] == wordArray[c])
			{
				words = (rand() % NUM_WORDS);
			}
		}
		wordArray[i] = WORDS[words][WORD];
// Word to guess
		string theWord = WORDS[words][WORD];  
// Hint for the word
		string theHint = WORDS[words][HINT];  
// Mixed up (jumbled) version of the word
		string jumble = theWord;  
		int length = jumble.size();
		for (int j = 0; j < length; ++j)
		{
// Telling the program to call a random word and jumble it
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
// Cout is telling the program to print the string "The keyword is" and then print the jumbled word so the user can guess
		cout << "The keyword is: " << jumble;

		string guess;
		cout << "\n\nYour guess: ";
		cin >> guess;
// If the guess is not equal to the word or the pass option is not selected
		while ((guess != theWord) && (guess != "pass"))
		{
// If the string hint is typed
			if (guess == "hint")
			{
// Print the hint from the enum
				cout << theHint;
			}
			else
// If none of the previous cases were the guess, then they are wrong and the following string is printed along with total wrong answers and total answers given.
			{
				cout << "Sorry, that's not it.";
				wrongAnswers++;
				totalAnswers++;
			}

			cout << "\n\nYour guess: ";
			cin >> guess;
		}
// If the guess is equal to the word that was jumbled, then the following string is printed. 
		if (guess == theWord)
		{
			totalAnswers++;
			correctAnswers++;
			cout << "\nThat's it!  You guessed it!\n" << endl;
		}
	}
/* As stated in my previus assignment, cout is an object, and is used to send data to the standart output string. The << says
to send the string to cout. At the end the endl string is being sent to the standard output with the << and is the same as saying 
"hit the enter button" It is used throughout the program as it is a text based game and outputs many strings*/
	cout << "\n\t\tStats" << endl;
	cout << "-------------------------------" << endl;
	cout << "You guessed " << correctAnswers << " words correctly this simulation." << endl;
	cout << "You guessed " << wrongAnswers << " words incorrectly this simulation." << endl;
	cout << "You guessed a total of " << totalAnswers << " words this simulation." << endl;
// The following lines are asking the player if they want to restart the game. 
// The user needs to answer Y or N.
	string playAgain;
	cout << "Would you like to play again? Y/N" << endl;
	cin >> playAgain;
// If the answer to the question (playAgain) playAgain (input)	then the if statement applies. If anything else input the else statement applies. 	
	while (true) {
		if (playAgain == "Y") {
			system("cls");
			main();
		}
		else if (playAgain == "N") {
			cout << "Thanks for playing!" << endl;
			usleep(200000);
			exit(0);
		}
		else {
			cout << "Please input Y or N..." << endl;
			cin >> playAgain;
		}
	}
}

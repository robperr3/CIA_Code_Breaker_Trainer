// CIA_program.cpp : Defines the entry point for the console application.
//This is a Training Simulation program for the CIA to help recuits learn 
//how to decypher the enemy's coded messages

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;


int main()
{
	enum fields{WORD,HINT,NUM_FIELDS};
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel youre banging your head against something?"},
		{"rendezvous", "Why does this word sound French?"},
		{"treason", "Does Eric Snowden ring a bell?"},
		{"persistant", "If you cant guess this one just give up newb!"},
		{"jumble", "Its what this game is about"},
		{"spy", "Its what the you are, dummy!"},
		{"hell", "its where you are now!HAHAHA"},
		{"KIA", "Lets hope you dont end up as this, rookie!"},
		{"classified", "This means its above your paygrade"},
		{"KGB", "if you cant figure this one out, youre an idiot"}
	};
	enum difficulty { EASY, MEDIUM, HARD, NUM_DIFF_LEVELS };
	cout << "There are " << NUM_DIFF_LEVELS << "dificulty levels";
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];// word to guess
	string theHint = WORDS[choice][HINT];//hint for word
	string jumble = theWord; //jumble version of word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word\n";
	cout << "enter'hint' for a hint";
	cout << "Enter 'quit' to quit thew game\n\n";
	cout << "The jumnble is:" << jumble;
	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "sorry, thats not right";
		}
		cout << "\n\nyour guess: ";
		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "\nThats it!You guesed right!\n";
	}
	cout << "\nThanks for playing\n";

	system("pause");
    return 0;
}


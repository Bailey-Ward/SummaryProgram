

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct letter_only : ctype<char> //this structure filters out any non alphabetical characters when analysing word frequency
{
	letter_only() : ctype<char>(get_table()) {}

	static ctype_base::mask const* get_table()
	{
		static vector<ctype_base::mask>
			rc(ctype<char>::table_size, ctype_base::space);

		fill(&rc['A'], &rc['z' + 1], ctype_base::alpha);
		return &rc[0];
	}
};

int main()
{
	string filename = "textfile.txt"; //contains the name of the text document 
	string textFile; //the file is read to this string
	ifstream ReadFile(filename); //reads the file to memory

	char ch; //stores characters for when iterating through the vectors
	int numberOfWords{}; //int for storing the number of words in the .txt
	int numberOfSentences{}; //int for storing the number of sentences in the .txt
	int count{}; //int for storing the frequency of words in the .txt
	vector <string> unsortedList; //vector for holding the text file

	while (getline(ReadFile, textFile)) { //reads the file line by line and adds it to a vector

		unsortedList.push_back(textFile);
	}
	ReadFile.close(); //closes the file after the process is done

	for (string item : unsortedList) { //prints the vector to console
		cout << item << "\n";
	}

	for (string item : unsortedList) { //iterates through each character looking for sentence breakers
		for (int i = 0; i < item.length(); i++) {
			ch = item[i];
			if (ch == '.' || ch == '!') {
				numberOfSentences++; //increments number of sentences when it finds them
			}
		}
	}

	for (string item : unsortedList) { //iterates through each character and looks for punctuation 
		for (int i = 0; i < item.length(); i++) {
			ch = item[i];
			if (ch == ' '|| ch == ',' || ch == '.' || ch == '!') {
				numberOfWords++; //increments number of words when it finds punctuation 
			}
		}
	}

	cout << ("\nNumber of sentences:\t ");
	cout << numberOfSentences;
	cout << ("\nNumber of words:\t ");
	cout << numberOfWords << "\n";

	map<string, int> wordList; //creates the map wordlist which stores strings and ints
	ifstream input;
	input.imbue(locale(locale(), new letter_only())); //enable reading only letters
	input.open(filename); 
	string word; //opens the file and reads it to the string word
	while (input >> word)
	{
		++wordList[word]; //increments the counter
	}
	for (map<string, int>::iterator it = wordList.begin(); it != wordList.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl; //prints the map
	}
}







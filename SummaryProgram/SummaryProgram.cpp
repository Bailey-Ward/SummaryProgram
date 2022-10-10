

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	string filename = "textfile.txt"; //contains the name of the text document 
	string textFile;

	ifstream ReadFile(filename); //reads the file to memory
	char ch;
	int numberOfWords{}; //int for storing the number of words in the .txt
	int numberOfSentences{}; //int for storing the number of sentences in the .txt
	int wordCount = 0; //int for storing the frequency of words in the .txt
	vector <int> v; //vector for holding the text file

	while (getline(ReadFile, textFile)) {

		cout << textFile;

		for (int i = 0; i < textFile.length(); i++) {
			ch = textFile[i];
			if (ch == '.' || ch == '!')
			{
				numberOfSentences++;
			}
		}

		for (int i = 0; i < textFile.length(); i++) {
			ch = textFile[i];
			if (ch == ' ' || ch == ',' || ch == '.' || ch == '!')
			{
				numberOfWords++;
			}
		}
		

	}

	cout << numberOfSentences;
	cout << numberOfWords;


	ReadFile.close();
}


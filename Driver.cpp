#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

struct wordCount{
	string word;
	int count;
};

void insertionSort(wordCount *wordArray, int numWords);
void bubbleSortReverse(wordCount *wordArray, int numWords);
void quicksort(wordCount *wordArray, int low, int high);
int partition(wordCount *wordArray, int left, int right);

int main()
{
	wordCount* wordArray = new wordCount[150000];
	int numWords = 0;
	string temp;
	int num;
	
	ofstream outfile;
	ifstream infile;

	time_t start, end;
	char filename[50];
	cout << "\nWhich file are you opening?\n";
	cin >> filename;
	infile.open(filename);
	
	if(!infile)
	{
		cout << "\nSorry, I couldn't find that file.\n";
		return 1;
	}

	while(getline(infile, temp) && numWords != 150000)
	{
		wordArray[numWords].word = temp;
		infile >> num;
		infile.ignore();
		wordArray[numWords].count = num;
		numWords++;
	}
	cout << "you've read in " << numWords << " words.\n";

	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   

	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE

	end = getTime(); //Ends timer.
	outfile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 

	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE

	end = getTime(); //Ends timer.
	outfile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE

	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outfile.open("sortFileQuick.txt");
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();
	
	delete [] wordArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(wordCount *wordArray, int numWords) {
	int temp;

	for(int i =1; i < numWords; i++){
		wordCount temp = wordArray[i];
		int j = i -1;
		while (j >= 0 && wordArray[j].count > temp.count) {
			wordArray[j+1] = wordArray[j];
			j--;
		}
		wordArray[j+1] = temp;
	}
}


//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE

void bubbleSortReverse(wordCount *wordArray, int numWords) {
	for (int i = 0; i < numWords -1; i++){
		bool swapped = false;
		for (int j = 0; j < numWords -1; i++){
			if (wordArray[j].count < wordArray[j+1].count);
			swapped = true;
		}
		if(!swapped)
		break;
	}
}

//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE

void quicksort(wordCount *wordArray, int low, int high){
	if (low < high) {
		int pivot = partition(wordArray, low, high);
		quicksort(wordArray, low, pivot-1);
		quicksort(wordArray, pivot + 1, high);
	}
}

//LOOK!  WRITE YOUR PARTITION FUNCTION HERE

int partition(wordCount *wordArray, int left, int right) {
	int pivot = wordArray[right].count;
	int i = left - 1;

	for (int j = left; j < right; j++) {
		if (wordArray[j].count < pivot) {
			i++;
			swap(wordArray[i], wordArray[j]);
		}
	}
	swap(wordArray[i + 1], wordArray[right]);
	return i+1;
}
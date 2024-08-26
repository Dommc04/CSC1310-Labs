/*
	Title:  Lab2.cpp
	Author: Dominic McElroy
	Date:  9/16/2023
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>	
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int	multiply (int, int);


const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				
				num=sumOfNumbers(num);
				cout << "The result is: " << num;
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				
				isMember(myArray,num, ARRAY_SIZE);

				if(isMember(myArray,num,ARRAY_SIZE) !=1)
				cout << "\n\nNO!" << num << "is NOT in the array";
				else
					cout << "\n\nYES!" << num << "is in the array!";
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				
				stringReverser(userString, userString.size());
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				
				cout << "user modified string: ";
				for(int i = 0; i < userString.length(); i++) {
					cout << userString[i];
				}
				cout << endl;

				if(isPalindrome(userStrModified))
					cout << "Yes!" << userString << "IS a palindrome!";
					else
					cout << "NO!" << userString << "IS not a palindrome!";

				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here

				cout << "The value of " << num1 << "x" << num2 << "is" << multiply(num1,num2);
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!


int sumOfNumbers(int num) {
	if (num == 1)
	return 1;


	else
	return num + sumOfNumbers(num-1);
}

bool isMember(int* array, int val, int size) {
	if (size==0)
	return false;
	else if (array[size - 1]==val)
	return true;
	else
	return isMember(array, val, size -1);
}

void stringReverser(string str, int size) {
	if(size==0)
	return;
	else {
		stringReverser(str.substr(1), size-1);
		cout << str[0];
	}
}

bool isPalindrome(string str)
{
	if (str.length() <= 1)
		return true;
	// here you get start index and end index
	if (str.at(0) == str.at(str.length()-1))
		return isPalindrome(str.substr(1, str.length()-2));
}


	int	multiply (int times, int num) {
		if(times==1)
		return num;
		else
		return num + multiply(times-1,num);
	}



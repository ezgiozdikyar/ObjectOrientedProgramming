/**
* author: Ezgi OZDIKYAR
* date: 30/10/2020
*/
#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
using namespace std;
/**
* @brief	This function calculates sum of the integers in numbers array.
* @param	int* numbers - an array to store the values reading from dataFile
* @param    int size - size of numbers array
* @return   int sum - sum of the numbers in numbers array
*/
int sum(int* numbers, int size);
/**
* @brief	This function calculates product of the integers in numbers array.
* @param	int* numbers - an array to store the values reading from dataFile
* @param    int size - size of numbers array
* @return   int product - product of the numbers in numbers array
*/
int product(int* numbers, int size);
/**
* @brief	This function calculates average of the integers in numbers array.
* @param	int* numbers - an array to store the values reading from dataFile
* @param    int  size - size of numbers array
* @return   float average - average of the numbers in numbers array
*/
float average(int* numbers, int size);
/**
* @brief	 This function returns the smallest number in numbers array.
* @param     int* numbers - an array to store the values reading from dataFile
* @param     int  size - size of numbers array
* @return    int  smallest - the smallest number in numbers array
*/
int smallest(int* numbers, int size);
/**
* @brief	This function controls if dataFile exits or not.Also controls if dataFile is empty.
* @param	int  dataFile - file
*/
void isFileOpen(fstream& dataFile);
/**
* @brief	This function validates if size is valid integer. If size is invalid value it shows error.
* @param	int  dataFile - file
* @param    int* size - size of numbers array
*/
void sizeControl(fstream& dataFile, int* size);
/**
* @brief	This function validates datas in dataFile if it is valid integer. It puts integers into numbers array.
* @param	int  dataFile - file
* @param    int* numbers - an array to store the values reading from dataFile
* @param    int* size - size of numbers array
*/
void operationsAndValidations(fstream& dataFile, int* numbers, int* size);
/**
* @brief    This function calls the other functions for workflow.
*/
int main(void)
{
	fstream dataFile;
	int  size;
	int* numbers = 0;
	isFileOpen(dataFile);
	sizeControl(dataFile, &size);
	numbers = new int[size];
	operationsAndValidations(dataFile, numbers, &size);
	cout << "Sum: " << sum(numbers, size) << endl;
	cout << "Product: " << product(numbers, size) << endl;
	cout << "Average: " << average(numbers, size) << endl;
	cout << "Smallest: " << smallest(numbers, size) << endl;
	delete[] numbers;
	dataFile.close();
	system("pause");
	return 0;
}
int sum(int* numbers, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += numbers[i];
	return sum;
}
int product(int* numbers, int size)
{
	int product = 1;
	for (int i = 0; i < size; i++)
		product *= numbers[i];
	return product;
}
float average(int* numbers, int size)
{
	return ((float)sum(numbers, size) / (float)size);
}
int smallest(int* numbers, int size)
{
	int small = numbers[0];
	for (int i = 1; i < size; i++)
	{
		if (small > numbers[i])
			small = numbers[i];
	}
	return small;
}
void isFileOpen(fstream& dataFile)
{
	dataFile.open("input.txt", ios::in);
	if (!dataFile.is_open())
	{
		cout << "File is not found!" << endl;
		system("pause");
		exit(0);
	}
	if (dataFile.peek() == ifstream::traits_type::eof())
	{
		cout << "File is empty!" << endl;
		system("pause");
		exit(0);
	}
}
void sizeControl(fstream& dataFile, int* size)
{
	string tempStr;
	getline(dataFile, tempStr);
	try
	{
		int num = stoi(tempStr);
		if (num < 0)
			throw invalid_argument("");
		*size = num;
	}
	catch (invalid_argument& e)
	{
		cout << tempStr << " is not a valid size!" << endl;
		system("pause");
		exit(0);
	}
}
void operationsAndValidations(fstream& dataFile, int* numbers, int* size)
{
	string tempStr;
	int counter = 0;
	while (!dataFile.eof())
	{
		dataFile >> tempStr;
		try
		{
			int num = stoi(tempStr);
			numbers[counter] = num;
			counter++;
			if (counter > * size)
			{
				cout << "Numbers are more than size." << endl;
				system("pause");
				exit(0);
			}
			tempStr.erase();
		}
		catch (invalid_argument& e)
		{
			if (tempStr != "")
			{
				cout << tempStr << " is not a valid integer!" << endl;
				system("pause");
				exit(0);
			}
		}
	}
	if (counter < *size)
	{
		cout << "Numbers are less than size." << endl;
		system("pause");
		exit(0);
	}
}
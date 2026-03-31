/*Jose Ayestas
ENGR 1400
LAB 11
31/03/2026*/

/*This program asks the user for a file name and he program should read the contents of the file into an array then display the following data:

The lowest number in the array

The highest number in the array

The total of the numbers in the array

The average of the numbers in the array
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 100;

// The Function to read numbers from file into array
int readNumbers(string filename, double arr[], int maxSize)
{
    ifstream inputFile;
    inputFile.open(filename);

    if (!inputFile)
    {
        cout << "Error opening file.\n";
        return 0;
    }

    int count = 0;

    while (count < maxSize && inputFile >> arr[count])
    {
        count++;
    }

    inputFile.close();
    return count;
}

// The Function to calculate and display statistics
void calculateStats(double arr[], int size)
{
    if (size == 0)
    {
        cout << "No data to process.\n";
        return;
    }

    double min = arr[0];
    double max = arr[0];
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];

        sum += arr[i];
    }

    double average = sum / size;

    double varianceSum = 0;
    for (int i = 0; i < size; i++)
    {
        varianceSum += pow(arr[i] - average, 2);
    }

    double stdDeviation = sqrt(varianceSum / size);

    cout << "\nResults:\n";
    cout << "Lowest number: " << min << endl;
    cout << "Highest number: " << max << endl;
    cout << "Total: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Standard Deviation: " << stdDeviation << endl;
}

int main()
{
    double numbers[SIZE];
    string filename;

    // Greeting 
    cout << "This program reads up to 100 numbers from a file and calculates:\n";
    cout << "- The lowest number\n";
    cout << "- The highest number\n";
    cout << "- The total\n";
    cout << "- The average\n";
    cout << "- The standard deviation\n\n";

    cout << "Enter file name: ";
    cin >> filename;

    int count = readNumbers(filename, numbers, SIZE);

    calculateStats(numbers, count);

    return 0;
}
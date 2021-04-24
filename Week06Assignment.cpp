// Week06Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// declaring the arrays that we need at the top
string names[10];
int scores[10][4];
double averages[10];
const double numOfGames = 4;

// this is the GetBowlingData function that will read the data from the file and store it into two arrays
bool GetBowlingData(string fileName, string names[], int scores[][4]) {
    // first we need to open up the file
    ifstream file;
    file.open(fileName);
    // i declared an index to keep track of how many times we enter the loop
    int index = 0;
    // for each line of the file
    string line;
    // we should check to see if the file opened or not
    // if the file didn't open, we should return false
    if (!file) {
        cout << endl;
        cout << fileName << " could not be opened..." << endl;
        return false;
    }
    // if file opening was successful, we read the contents of the file and store the appropriate data into the arrays
    else {
        // while we aren't at the end of the file, we read in each line
        while (!file.eof()) {
            file >> names[index] >> scores[index][0] >> scores[index][1] >> scores[index][2] >> scores[index][3];
            index++;
        }
        // this code was just to test if the input into the arrays was successful, which it was
        // cout << names[9] << endl;
        // cout << scores[9][3] << endl;
        return true;
    }
}

// this is the GetAverageScore function that will take the two arrays as input and calculate the average score
double GetAverageScore(string names[], int scores[][4], double averages[]) {
    // i am going to use for loops to loop through the contents of the array
    double averageScore;
    for (int i = 0; i <= 9; i++) {
        // we don't need to loop through names[] since those are just string values, but we do need to loop through scores
        // second for loop is for the columns of the array, first is for the rows
        int sumScore = 0;
        for (int j = 0; j <= 3; j++) {
            sumScore = sumScore + scores[i][j];
        }
        averageScore = sumScore / numOfGames;
        // appending the value to the average array, but this is causing bugs for some reason
        // i did averageScore >> averages[i] instead of what i have below, which is why i had bugs. that syntax seems to work only for files.
        averages[i] = averageScore;
        // test to see if it was successful
        // cout << averages[i] << endl;
    } 
    return averageScore;
}

// this is the PrettyPrintResults function that will output the results to the console window
void PrettyPrintResults(string names[], int scores[][4], double averages[]) {
    // making it pretty
    cout << setw(10) << left << "Player Name" << "\t" << "Score 1" << "\t\t" << "Score 2" << "\t\t" << "Score 3" << "\t\t" << "Score 4" << "\t\t" << "Average Score" << endl;
    // we will once again need to use for loops to loop through the contents of the array
    for (int i = 0; i <= 9; i++) {
        cout << setw(10) << left << names[i] << "\t";
        // once again we need a second loop since we have a two dimensional array
        for (int j = 0; j <= 3; j++) {
            cout << scores[i][j] << "\t\t";
        }
        // i'm getting very large numbers with the averages and i'm not sure why
        // trouble passing in the value perhaps?
        // this worked when i added the averages array as a parameter to GetAverageScore
        cout << averages[i] << endl;
    }
}

int main() {
    // ask the user for input then call functions
    string names[10];
    int scores[10][4];
    double averages[10];
    string fileName;
    cout << "Please enter a file to be read: ";
    cin >> fileName;
    GetBowlingData(fileName, names, scores);
    GetAverageScore(names, scores, averages);
    PrettyPrintResults(names, scores, averages);
    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

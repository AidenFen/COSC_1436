/*
CONSOLE OUTPUT/TESTING RESULTS:

------------------------------------------------------------------------
ERROR: Scorecard file could not be read. Exiting program.
------------------------------------------------------------------------
Please enter the filename of the scorecard: Scorecard1.txt

Mirabella Jones's scorecard results:
7.50 8.80 7.00 8.10 8.00 9.80 9.30 8.90 9.10 9.00 7.50, 8.80, 7.00, 8.10, 8.00, 9.80, 9.30, 8.90, 9.10, 9.00
The highest score: 9.80, and the lowest score: 7.00, were dropped
Average score: 8.59

Ruth Mendez's scorecard results:
9.80 8.50 6.00 8.80 8.60 7.10 7.80 8.00 7.20 8.30 9.80, 8.50, 6.00, 8.80, 8.60, 7.10, 7.80, 8.00, 7.20, 8.30
The highest score: 9.80, and the lowest score: 6.00, were dropped
Average score: 8.04

Melvin Ingram's scorecard results:
9.90 7.30 6.30 7.00 6.80 6.20 8.90 9.50 6.50 6.00 9.90, 7.30, 6.30, 7.00, 6.80, 6.20, 8.90, 9.50, 6.50, 6.00
The highest score: 9.90, and the lowest score: 6.00, were dropped
Average score: 7.31

Tara Silva's scorecard results:
8.10 7.10 9.40 7.20 9.20 6.40 9.50 8.40 6.70 6.60 8.10, 7.10, 9.40, 7.20, 9.20, 6.40, 9.50, 8.40, 6.70, 6.60
The highest score: 9.50, and the lowest score: 6.40, were dropped
Average score: 7.84

Joann Gardner's scorecard results:
6.90 8.00 8.70 8.90 9.10 7.50 8.20 6.30 8.40 6.20 6.90, 8.00, 8.70, 8.90, 9.10, 7.50, 8.20, 6.30, 8.40, 6.20
The highest score: 9.10, and the lowest score: 6.20, were dropped
Average score: 7.86

Jeff Barnes's scorecard results:
6.40 7.20 8.30 8.60 7.90 6.00 7.10 6.70 9.50 9.90 6.40, 7.20, 8.30, 8.60, 7.90, 6.00, 7.10, 6.70, 9.50, 9.90
The highest score: 9.90, and the lowest score: 6.00, were dropped
Average score: 7.71

Lucille Dixon's scorecard results:
9.50 6.50 9.30 9.40 8.50 8.70 6.20 9.70 8.70 8.20 9.50, 6.50, 9.30, 9.40, 8.50, 8.70, 6.20, 9.70, 8.70, 8.20
The highest score: 9.70, and the lowest score: 6.20, were dropped
Average score: 8.60

Krista James's scorecard results:
8.40 9.40 8.10 6.30 6.10 8.60 9.60 9.10 9.90 8.80 8.40, 9.40, 8.10, 6.30, 6.10, 8.60, 9.60, 9.10, 9.90, 8.80
The highest score: 9.90, and the lowest score: 6.10, were dropped
Average score: 8.54

Naomi Sanders's scorecard results:
7.00 7.20 8.70 9.10 9.60 6.60 9.40 9.80 8.40 7.60 7.00, 7.20, 8.70, 9.10, 9.60, 6.60, 9.40, 9.80, 8.40, 7.60
The highest score: 9.80, and the lowest score: 6.60, were dropped
Average score: 8.38

Ricky McCarthy's scorecard results:
9.80 7.20 9.00 8.50 6.20 6.50 9.10 8.40 8.10 8.70 9.80, 7.20, 9.00, 8.50, 6.20, 6.50, 9.10, 8.40, 8.10, 8.70
The highest score: 9.80, and the lowest score: 6.20, were dropped
Average score: 8.19
------------------------------------------------------------------------

------------------------------------------------------------------------

------------------------------------------------------------------------
*/

// Source code:

/*
File name: COSC1436_Assignment7b.txt
Date: 11/17/2021
Name: Aiden Fenstermacher
Class: COSC-1436.006 | TR, 11:00 AM - 12:45 PM
Description: This program reads a scorecard file and extracts an athlete's name, and the athlete's 10 scores given by the judges.
             The program will determine if the athlete should be disqualified based on their scorecard. If the scorecard is valid,
             a report of the athlete's scores, their higest score, their lowest score, and their average score (without the highest
             or lowest score included) will be output to the console.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// function for reading

int readScoreCard(string); // takes the name of the file to be read. returns # of athletes read in the file
void printScores();
double getAverage(int);

//global consts
const int MAX_ATHLETE_COUNT = 10;
const int MAX_SCORES_AMOUNT = 10;
const int MAX_SCORE = 10;
const int MIN_SCORE = 0;

string errorArray[MAX_ATHLETE_COUNT];
string athleteNamesArray[MAX_ATHLETE_COUNT];
double scoreArray[MAX_ATHLETE_COUNT][MAX_SCORES_AMOUNT]; //max is a 10x10 array

int main() {
    // get the filename 
    cout << "Please enter the filename of the scorecard: ";
    string inputFileName;
    cin >> inputFileName;

    // Call Function 1 to read the scorecard and get the number of athletes 
    //  whose data was successfully read. (1 point) 
    int athleteCount = readScoreCard(inputFileName);

    //cout << "\nAthlete count: " << athleteCount << endl; //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //cout << "\n10x10 score array: " << endl;
    //printScores();
    cout << endl;

    // for each athlete:
    for (int i = 0; i < athleteCount; i++) {
        // display the athlete’s name
        cout << athleteNamesArray[i] << "'s scorecard results:" << endl;

        // check if there was an error validating the scores and display 
        if (errorArray[i] == "error") {
            cout << athleteNamesArray[i] << " was disqualified." << endl << endl;
        }
        else {
            // output athlete's name
            for (int j = 0; j < MAX_SCORES_AMOUNT; j++) {
                cout << left << fixed << setprecision(2);
                cout << setw(5) << scoreArray[i][j];
            }
            double average = getAverage(i);
            cout << "Average score: " << average << endl << endl;
        }
    }
}

int readScoreCard(string inputFileName) {

    ifstream inputFile;
    inputFile.open(inputFileName);

    if (inputFile) {
        int numAthletes = 0;
        for (int row = 0; row < MAX_ATHLETE_COUNT; row++) { // read up to 10 names.
            if (getline(inputFile, athleteNamesArray[row])) {

                // if contractor has been captured successfully, start reading their scores.
                bool hasInvalidScore = false; // sentinel value

                for (int column = 0; column < MAX_ATHLETE_COUNT && !hasInvalidScore; column++) {//&& !hasInvalidScore
                    if (inputFile >> scoreArray[row][column]) {

                        // if score exists, validate it
                        if (scoreArray[row][column] > MAX_SCORE || scoreArray[row][column] < MIN_SCORE) {
                            errorArray[row] = "error";
                            hasInvalidScore = true; // will break out of the closest for loop
                        }
                        else { errorArray[row] = ""; }
                    }

                    // move the file reading position to the next line (line with an athlete's name)
                    if (hasInvalidScore) {
                        string errorLine;
                        getline(inputFile, errorLine);
                    }
                    else { inputFile.ignore(); }
                }
                numAthletes++; // count of athletes read. disqualified athletes included
            }
        }
        inputFile.close();
        return numAthletes;
    }
    else {
        cout << "Scorecard file could not be read. Exiting program." << endl;
        exit(0);
        // return 0; // total athletes found would be 0
    }
}

double getAverage(int row) {
    // output the scores: 
    double scoreSum = 0;
    double highestScore = scoreArray[row][0];
    double lowestScore = scoreArray[row][0];

    for (int i = 0; i < MAX_SCORES_AMOUNT; i++) {
        // output the scores seperated by commmas
        cout << scoreArray[row][i] << ((i < MAX_SCORES_AMOUNT - 1) ? ", " : "");

        scoreSum += scoreArray[row][i];

        // find highest and lowest score
        if (scoreArray[row][i] > highestScore) {
            highestScore = scoreArray[row][i];
        }
        if (scoreArray[row][i] < lowestScore) {
            lowestScore = scoreArray[row][i];
        }
    }

    double scoreAverage = (scoreSum - highestScore - lowestScore) / (MAX_SCORES_AMOUNT - 2);
    cout << "\nThe highest score: " << highestScore << ", and the lowest score: " << lowestScore << ", were dropped" << endl;

    return scoreAverage;
}

void printScores() { // only prints the scoreArray right now.
    cout << "ScoreArray contents: " << endl;
    cout << left << fixed << setprecision(2);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(5) << scoreArray[i][j];
        }
        cout << endl;
    }
}
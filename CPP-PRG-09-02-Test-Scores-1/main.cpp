//
//  main.cpp
//  CPP-PRG-09-02-Test-Scores-1
//
//  Created by Keith Smith on 10/28/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that dynamically allocates an array large enough to hold a user-
//  defined number of test scores. Once all the scores are entered, the array should be
//  passed to a function that sorts them in ascending order. Another function should be
//  called that calculates the average score. The program should display the sorted list of
//  scores and averages with appropriate headings. Use pointer notation rather than array
//  notation whenever possible.
//  Input Validation: Do not accept negative numbers for test scores.

#include <iostream>
#include <iomanip>

using namespace std;

int *getNumberOfTestScores();
double *getTestScores(int);
double *sortScores(double *, int);
void swap(double *, double *);
double averageTestScore(double *, int);
void showOutputMessage(double *, int, double);


int main()
{
    int *intNumScores = nullptr;
    
    double *dblTestScores = nullptr;
    double dblAverageScore;
    
    intNumScores = getNumberOfTestScores();
    
    dblTestScores = getTestScores(*intNumScores);

//    Debug
//    for (int i = 0 ; i < intNumScores ; i++)
//    {
//        cout << *(dblTestScores + i) << endl;
//    }
    
    cout << endl << endl;
    
    dblTestScores = sortScores(dblTestScores, *intNumScores);

//    Debug
//    for (int i = 0 ; i < intNumScores ; i++)
//    {
//        cout << *(dblTestScores + i) << endl;
//    }
    
    dblAverageScore = averageTestScore(dblTestScores, *intNumScores);
    
    showOutputMessage(dblTestScores, *intNumScores, dblAverageScore);
    
    return 0;
}

int *getNumberOfTestScores()
{
    int *intNumScores = nullptr;
    
    intNumScores = new int;
    
    cout << "How many test scores would you like to average?\n";
    cin >> *intNumScores;
    while(!cin || *intNumScores <= 0 || *intNumScores > 10)
    {
        cout << "Please enter a number between 1 and 10.\n";
        cin.clear();
        cin.ignore();
        cin >> *intNumScores;
    }
    
    return intNumScores;
}

double *getTestScores(int intScores)
{
    double *dblArr = nullptr;
    
    dblArr = new double[intScores];
    
//    unique_ptr<double[]> dblArr (new double[intScores]);
    
    for (int i = 0 ; i < intScores ; i++)
    {
        cout << "Please enter your #" << i + 1 << " test score.\n";
        cin >> dblArr[i];
        while(!dblArr[i] || dblArr[i] < 0 || dblArr[i] > 100)
        {
            cout << "Please enter a test score between 0 and 100.\n";
            cin.clear();
            cin.ignore();
            cin >> dblArr[i];
        }
    }
    
    return dblArr;
    
//    HOW TO MAKE THIS WORK?!
//    delete [] dblArr;
//    dblArr = nullptr;
}

double *sortScores(double *dblScores, int INT_SCORES)
{
    int intMinIndex;
    int intStartScan;
    
    double *dblMinElement = nullptr;
    
    for(intStartScan = 0 ; intStartScan < (INT_SCORES - 1) ; intStartScan++)
    {
        intMinIndex = intStartScan;
        dblMinElement = &dblScores[intStartScan];

        for(int index = intStartScan + 1 ; index < INT_SCORES ; index++)
        {
            if(dblScores[index] < *dblMinElement)
            {
                dblMinElement = &dblScores[index];
                intMinIndex = index;
            }
        }
        swap(dblScores[intMinIndex], dblScores[intStartScan]);
    }
    
    return dblScores;
}

void swap(double *dblA, double *dblB)
{
    double *temp = nullptr;
    
    temp = dblA;
    dblA = dblB;
    dblB = temp;
}

double averageTestScore(double *dblScores, int INT_SCORES)
{
    double dblTotal = 0;
    double dblAverage;
    
    for(int i = 0 ; i < INT_SCORES ; i++)
    {
        dblTotal += *(dblScores + i);
    }
    
    dblAverage = dblTotal / INT_SCORES;
    
    return dblAverage;
}

void showOutputMessage(double *dblScores, int INT_SCORES, double dblAverage)
{
    cout << setprecision(1) << fixed << showpoint;
    cout << "Your test scores sorted in order are:\n";
    for(int i = 0 ; i < INT_SCORES ; i++)
    {
        cout << *(dblScores + i) << endl;
    }
    cout << "Your average score was " << dblAverage << endl;
}

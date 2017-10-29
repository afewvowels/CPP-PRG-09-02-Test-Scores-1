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

using namespace std;

void getNumberOfTestScores(int &);
double *getTestScores(int);
double *sortScores(double *, int);
void swap(double *, double *);


int main()
{
    int intNumScores;
    
    double *dblTestScores = nullptr;
    
    getNumberOfTestScores(intNumScores);
    
    dblTestScores = getTestScores(intNumScores);
    
    for (int i = 0 ; i < intNumScores ; i++)
    {
        cout << *(dblTestScores + i) << endl;
    }
    
    cout << endl << endl;
    
    dblTestScores = sortScores(dblTestScores, intNumScores);
    
    for (int i = 0 ; i < intNumScores ; i++)
    {
        cout << *(dblTestScores + i) << endl;
    }
    
    return 0;
}

void getNumberOfTestScores(int &refNumScores)
{
//    int intNumScores;
    
    cout << "How many test scores would you like to average?\n";
    cin >> refNumScores;
    while(!cin || refNumScores <= 0 || refNumScores > 10)
    {
        cout << "Please enter a number between 1 and 10.\n";
        cin.clear();
        cin.ignore();
        cin >> refNumScores;
    }
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
    double *dblTemp = nullptr;
    
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

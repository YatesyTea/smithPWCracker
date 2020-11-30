
/*
 * File:   main.cpp
 * Author: j4-smith
 *N-Queens example in C
 * First Created on 25 April 2014, 18:42
 * Modified in light of student progress
 
 * Rewritten Oct 2015 to use more generic solution structures
 * and functions with Password-specific names that call the functions that modify the
 */


#include <stdio.h>
#include <stdlib.h>
#include "StructureDefinitions.h"
#include "SolutionListOperations.h"
#include "PasswordChecker.h"

#pragma warning(disable:4996)

typedef int bool;
#define true  1
#define false 0

//Variables workingCandidate, openList, closedList
candidateSolution workingCandidate;// this one will hold the solution we are currently considering
candidateList  openList; // this list will store all the solution we;ve created but not examined yet
candidateList closedList; // this is where we will store all the ones we're done with

char validChars[NUM_VALID_CHARACTERS] = {'0','1','2','3','4','5','6','7','8','9',
                                         'a','b','c','d','e','f','g','h','i','j',
                                         'k','l','m','n','o','p','q','r','s','t',
                                         'u','v','w','x','y','z','A','B','C','D',
                                         'E','F','G','H','I','J','K','L','M','N',
                                         'O','P','Q','R','S','T','U','V','W','X',
                                         'Y','Z'};

//************************ don't edit anything above this line***********************//

void printCandidateValues () {
    for (int i = 0; i < workingCandidate.size; i++) {
        printf("%c", workingCandidate.variableValues[i]);
    }
    printf("\n");
}

int main (int argc, const char * argv[]) {
    
    /* the next set of variables get used within our main function
     * but aren't declared globally becuase we don't want the other functions to change them inadvertently *///
    int indexOfSolutionWeAreLookingAt=0; //index in list of current solution being examined
    bool goalReached = false; // used to indicate when to stop searching for new candidates
    int bestval = 0, bestindex = 0; //used to find best thing in openList
    char oldval;
    oldval = '0';
    indexOfSolutionWeAreLookingAt = bestindex=bestval=0;
    //start off by emptying the lists of candidate solutions
    CleanListsOfSolutionsToStart();
    CleanWorkingCandidate();
    
    
    SetNewChallenge();
    
    /* So now let's start by creating our first solution
     * which we do by filling the values into the variable we declared as the workingCandidate
     * We'll begin by putting in the string aaaaaaaa
     */
    for (int pos=0; pos<N; pos++) {
        ExtendWorkingCandidateByAddingValue('a');
    }
    
    /* This is an example of how to change a value in some position - and then I'm reversing it
     * ChangeGuessValueInPositiontoNewValue(5, 'Z');
     * ChangeGuessValueInPositiontoNewValue(5, 'a');
    */
    
    //this is the function that tests the working candidate
    ScoreWorkingCandidate(); //number of matches is written into workingCandidate.score
    
    if (workingCandidate.score == N) {
        goalReached = true;
    }
    //this shows you how to print the current working candidate if you need to for debugging
    //PrintWorkingCandidate();
   
    //and we can put this as our first item in the list to start the process
    AddWorkingCandidateToOpenList();

    
    
    
    ///**********DONT CHANGE ANYTHING ABOVE THIS LINE
    int count = 0, highScore = 0;

    while (goalReached == false && openList.size != 0) {
        int highPos = 0;
        // Go through list and find highest scored solution to set as working candidate.
        for (int i = 0; i < openList.size; i++) {
            if (openList.listEntries[i].score > highScore) {
                highScore = openList.listEntries[i].score;
                highPos = i;
            }
        }
        CopySolutionFromOpenListIntoWorkingCandidate(highPos);
        RemoveSolutionFromOpenList(highPos);
        printCandidateValues();

        if (workingCandidate.score == N) {
            PrintFinalSolutionAndExit();
        }

        // Generate all next generation solutions and add them to OpenList after Cleaning Previous List.
        CleanListsOfSolutionsToStart();
        for (int i = 0; i <= 61; i++) {
                ChangeGuessValueInPositiontoNewValue(count, validChars[i]);
                ScoreWorkingCandidate();
                AddWorkingCandidateToOpenList();
        }
        count++;
    }
    ///**** YOU MUST LEAVE IN THIS CALL TO PrintFinalSolutionAndExit() to get a mark from the system
    PrintFinalSolutionAndExit();
    return 0;
}


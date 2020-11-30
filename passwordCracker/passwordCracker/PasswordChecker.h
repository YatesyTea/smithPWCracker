/**
* file PasswordChecker.h
* declares the  password challenge - specific functions
*
* Author Jim Smith 16-10-14
*/


#include <stdio.h>
#include <stdlib.h>
#include "StructureDefinitions.h"
#include "SolutionListOperations.h"


/**
 @file PasswordChecker.h
 @brief the "various specific functions for Password Guessing Problem
 */

/**
 @brief The  function that sets a new password challenge .
 
 Assumes the presence of an array of chars called "challenge" - which should be local to the file Passwordchecker.c to stop the solver code 'cheating'.
 Creates a new random string and saves it to that array
 No return value as  errors are dealt with via calls to PrintThisMessageAndExit()
 */
void SetNewChallenge(void);


/**
 @brief The test function for Password.
 
 Assumes the presence of a variable: candidateSolution  workingCandidate.
 This functions tells us how many of the N characters are correct in the guess contained  in the current working candidate.
  No return value as the number is written into workingCandidate.score,
  and errors are dealt with via calls to PrintThisMessageAndExit()
 */
void ScoreWorkingCandidate(void);


/*!
 @brief  Problem-specific function to print candidate solution to screen.
 
 @param solution pointer to solution to be printed
 */
void PrintCandidateSolution (candidateSolution * solution);

/*!
 @brief check and printsout final solution and how long it took to find
*/
void PrintFinalSolutionAndExit(void);




/**
 @brief  function to change one character in a candidate solution ot a new value
 @param position   index of character to be changed
 @param newvalue   new value to write into this position
 
 Calls the generic function void ChangeWorkingCandidateByReplaceValueinPlaceParam1_WithValueParam2(int positionToChange, int newValue);
 Error Handling dealt with by printing message and exiting
 */
void ChangeGuessValueInPositiontoNewValue(int position, char newvalue);

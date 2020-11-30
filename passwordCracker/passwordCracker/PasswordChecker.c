
/*  file Passwordchecker.c
*
* Author Jim Smith 16-10-14
*/



#include "PasswordChecker.h"
#include "PasswordDefinitions.h"
#include <time.h>

int numberOfCallsMade =0;


char challenge[N];

void SetNewChallenge()
{
    int position, randindex;
    extern char validChars[NUM_VALID_CHARACTERS];
    srand((unsigned int)time(NULL));
    for(position=0;position < N; position++)
    {
        randindex = rand() % NUM_VALID_CHARACTERS;
        challenge[position] = validChars[randindex];
    }
    
    printf("Challenge is:\t %s\n",challenge );
}

/*
 * void CalculateNumberOfVulnerableQueensForWorkingCandidate()
 * this functions tells us how many vulnerable queens there are in the current working candidate
 * no return value as the number is written into the structure that holds our candidae solution
 */

void ScoreWorkingCandidate()
{
    int position=0,matches=0;
    
	extern candidateSolution workingCandidate;
 
#ifdef ONDEWIS
    extern void markingChecks1(void);
    markingChecks1();
#endif
    
    
    for (position=0;position<N;  position++)
    {
        
        if (workingCandidate.variableValues[position] == challenge[position])
        {
            matches++;
        }
    }
    workingCandidate.score = matches;
    
    
    //finally increment the numberof soltions that have bene tested
    numberOfCallsMade++;
}



/* void PrintCandidateSolution (candidateSolution *solution)
 * generic function to print to screen any candidate solution we choose
 *
 * first parameter is the address of the candidate
 * all the error handling happens within the function so there is no return
 */
void PrintCandidateSolution (candidateSolution * solution)
{
    //check it exists
    if (solution == (candidateSolution *) NULL )
        //exit if it does not
        PrintThisMessageAndExit("tried to print a solution %d which is a non-valid index\n ");
    
  //print out its details
    printf("  printing  partial solution of size %d:\t", solution->size);
        for(int i=0;i<N;i++)
            printf("%c",solution->variableValues[i]);
    printf("\t  score = %d\n",solution->score);
    
}




// simple wrappera to make the code clearer
void AddQueenToNextRowInColumn(int col)
{
    if(col< N)
        ExtendWorkingCandidateByAddingValue(col);
    else
        PrintThisMessageAndExit("tried to add a queen with column number too high");
    
}


void ChangeGuessValueInPositiontoNewValue(int position, char newvalue)
{
    
    if(position >= 0 && position <N)
        ChangeWorkingCandidateByReplaceValueinPlaceParam1_WithValueParam2(position, newvalue);
    else
           PrintThisMessageAndExit("tried to change an invalid aposition in the working candidate");
    
}


//this isthe function we call when the goal is found
void PrintFinalSolutionAndExit(void)
{
    //make sure we can access the proposed solution
    extern candidateSolution workingCandidate;
    int position;
    extern int numberOfSolutionsTested, callfreqs[];
    
#ifdef ONDEWIS
#include "DEWISmarking.h"
    ProvideFeedBackAndMarkThenExit();
    exit(0);
#endif
    
    if ( workingCandidate.size!=N)
        PrintThisMessageAndExit("Error, working candidate does not have every piece defined");
    else if(workingCandidate.score!=N)
       PrintThisMessageAndExit("error, working candidate does not match target in every position");
    else {
          //print the solution
          PrintWorkingCandidate();
        printf("success: after %d attempts \n", numberOfCallsMade);
        
       // printf("This is the frequency with which your code  pulled candidates  off the openList:\n");
       // printf("\t oldest %d\n\t youngest %d\n\t highest value of score %d\n\t lowest value of score %d\n\t other %d\n",
        //        callfreqs[OLDEST], callfreqs[YOUNGEST],callfreqs[HIGHESTSCORE],callfreqs[LOWESTSCORE], callfreqs[OTHER]);
        
        
        printf("pausing for a while to leave messages on screen for the benefit of visual studio users\n");
        for(position=0;position < 3200000; position++)
            ;
        exit(0);
    }

    
}



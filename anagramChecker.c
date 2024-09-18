#include <stdio.h>
#include <ctype.h>

/*
gcc -o anagramChecker anagramChecker.c
./anagramChecker
*/

// Prompt: Identify if phrase A contains the necessary characters to form phrase B
// Capitalization/punctiation irrelevant

void normalizePhrase(char *phrase);
void doesAContainB(char *phraseA, char *phraseB);

int main()
{
    // obtain phraseA and phraseB
    char phraseA[100];
    printf("Enter phraseA below:\n");
    fgets(phraseA, sizeof(phraseA), stdin);
    printf("You entered the phraseA: %s", phraseA);

    char phraseB[100];
    printf("Enter phraseB below:\n");
    fgets(phraseB, sizeof(phraseB), stdin);
    printf("You entered the phraseB: %s\n", phraseB);

    // normalize phrases
    normalizePhrase(phraseA);
    normalizePhrase(phraseB);

    printf("PhraseA has been normalized to: %s\n", phraseA);
    printf("PhraseB has been normalized to: %s\n", phraseB);

    // check if phraseA contains the necessary characters to form phraseB
    doesAContainB(phraseA, phraseB);

    return 0;
}

void normalizePhrase(char *phrase)
{
    int j = 0;

    for (int i = 0; phrase[i] != '\0'; i++)
    {
        if (isalnum(phrase[i]))
        {
            if (isupper(phrase[i]))
            {
                phrase[j++] = tolower(phrase[i]);
            }
            else
            {
                phrase[j++] = phrase[i];
            }
        }
    }
    phrase[j] = '\0';
}

void doesAContainB(char *phraseA, char *phraseB)
{
    int numOfMatches = 0;
    int neededMatches = sizeof(phraseB);

    for (int i = 0; phraseB[i] != '\0'; i++)
    {
        for (int i = 0; phraseA[i] != '\0'; i++)
        {
            if (phraseA[i] == phraseB[i])
            {
                phraseA[i] = "";
            }
        }
    }
}
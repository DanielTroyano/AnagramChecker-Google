#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
gcc -o anagramChecker anagramChecker.c
./anagramChecker
*/

// Prompt: Identify if phrase A contains the necessary characters to form phrase B (Capitalization/punctiation irrelevant)

void normalizePhrase(char *phrase);
int doesAContainB(char *phraseA, char *phraseB);
void remove_element(char *array, int index, int array_length);

int main()
{
    // obtain phraseA and phraseB
    char phraseA[10];
    printf("\nEnter phraseA below: (capitalization/punctuation is disreguarded)\n");
    fgets(phraseA, sizeof(phraseA) - 1, stdin);
    // phraseA[strlen(phraseA)] = '\0';
    printf("phraseA is: %s", phraseA);

    char phraseB[100];
    printf("\nEnter phraseB below:\n");
    fgets(phraseB, sizeof(phraseB), stdin);
    printf("phraseB is: %s", phraseB);

    // normalize phrases
    normalizePhrase(phraseA);
    normalizePhrase(phraseB);

    printf("\nPhraseA converted to: %s\n", phraseA);
    printf("PhraseB converted to: %s\n", phraseB);

    // check if phraseA contains the necessary characters to form phraseB
    int result = doesAContainB(phraseA, phraseB);

    if (result)
    {
        printf("PhraseA IS an anagram of PhraseB\n");
    }
    else
    {
        printf("PhraseA is NOT an anagram of PhraseB\n");
    }

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

int doesAContainB(char *phraseA, char *phraseB)
{
    int failedToFindValue = 0;

    for (int i = 0; phraseB[i] != '\0'; i++)
    {
        if (failedToFindValue)
        {
            return 0;
        }

        int loop2execution = 1;

        for (int j = 0; j < strlen(phraseA); j++)
        {
            printf("\n%dnd search for '%c' against '%c'\n", loop2execution++, phraseB[i], phraseA[j]);

            // printf("\nstring length of phraseA: %d\n", strlen(phraseA));

            if (phraseA[j] == phraseB[i])
            {
                // phraseA has a character from phraseB
                printf("\nFOUND\n");
                // remove it from phraseA so it is not used again later (incase there are duplicates in phraseB)
                remove_element(phraseA, j, strlen(phraseA));

                break;
            }

            if (j == strlen(phraseA) - 1)
            {
                printf("failed to find: '%c'\n", phraseB[i]);
                failedToFindValue = 1;
            }
        }
    }

    return 1;
}

void remove_element(char *array, int index, int array_length)
{
    char toBeRemoved = array[index];
    printf("\nPhraseA before removal of '%c': %s\n", toBeRemoved, array);
    int i;
    for (i = index; i < array_length; i++)
        array[i] = array[i + 1];

    printf("PhraseA after removal of '%c': %s\n", toBeRemoved, array);
}
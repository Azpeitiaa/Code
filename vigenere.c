#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c, int count);

int main(int argc, string argv[])
{         
    int key = 0;
    int k = 0;
    int count = strlen(argv[1]);
    int charArray[count];
    
    if (argc != 2)                            //Checks if there is only one string input ie; ||./caesar aa|| Not ||./caesar aa bb||
    {                                         //If not, stops program
        printf("Usage: ./caesar keyword\n");        
        return 1;
    }
        
    for (int i = 0; i < strlen(argv[1]); i++)    //Checks if the CipherKey is a valid number and shifts the keys
    {
        if (isalpha(argv[1][i]))
        {
            key = shift(argv[1][i], count);
            charArray[i] = key;                    //Adds each letter of the key to an array
        }
        else
        {
            printf("Usage: ./caesar keyword\n");     
            return 1;
        }
    }
    
    string plain = get_string("plaintext: ");                    //Gets plaintext to cipher
    printf("ciphertext: ");
    
    for (int j = 0; j < strlen(plain); j++)                    //For every letter it checks for a blank space, upper, or lower char
    {                                                          //Then scrambles and prints the letter               
        if (ispunct(plain[j]))                                 
        {
            printf("%c", plain[j]);
        }
        else if (isblank(plain[j]))
        {
            printf(" ");
        }
        else if (isupper(plain[j]))
        {
            printf("%c", ((plain[j] - 'A') + charArray[k]) % 26 + 'A');
            k++;                                                            //Advances the cipher key by one
        }
        else
        {
            printf("%c", ((plain[j] - 'a') + charArray[k]) % 26 + 'a');
            k++;
        }
        
        if (k == count)                                           //If the key gets to the max length of the array, it resets
        {
            k = 0;
        }
    }
    printf("\n");
}

int shift(char c, int count)                                    //Turns each letter of the key into 0-25
{                                                               //Then returns the results
    int key = 0;
    
    for (int i = 0; i < count; i++)
    {
        if (c > 96)
        {
            key = (c - 97);       
            return (key);  
        }
        else if (c > 64 && c < 97)
        {
            key = (c - 65);
            return (key);
        }
        else
        {
            return 1;
        }

    }
    return 0;
    
}

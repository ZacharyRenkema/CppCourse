#include <iostream>
#include <string>
#include <cstring>

//Determining if vowel or consonant
bool vowel_or_consonant(std::string word)
{  
    bool foundVowel;
    int wordLength = word.length(); //# iterations set for length of word

    for(int i = 0; i <= wordLength; i++)
    {
        if(word[i] == 'a' ||
        word[i] == 'A' ||
        word[i] == 'e' ||
        word[i] == 'E' ||
        word[i] == 'i' ||
        word[i] == 'O' ||
        word[i] == 'u' ||
        word[i] == 'U' ||
        word[i] == 'y' ||
        word[i] == 'Y')
        {
            foundVowel = true; //true if word is vowel
        }
        else
        {
            foundVowel = false; //false if word is consonant
        }

    }


    return foundVowel;
}
//Classify Amount of Points
int points_counter()
{
    int points = 0;
    
    

}


int main()
{
    std::string word1;
    std::string word2;

    std::cout << "Please enter your first word: " << '\n';
    std::cin >> word1;

    std::cout << "Please enter your second word: " << '\n';
    std::cin >> word2;

    vowel_or_consonant(word1);
    vowel_or_consonant(word2);

    return 0;
}
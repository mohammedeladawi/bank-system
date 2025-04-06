//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{
   
public:
    enum enCharType {
        SmallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int randomNumber(int from, int to)
    {
        //Function to generate a random number
        int randNum = rand() % (to - from + 1) + from;
        return randNum;
    }

    static char getRandomCharacter(enCharType charType)
    {

        //updated this method to accept mixchars
        if (charType == MixChars)
        {
            //Capital/Samll/Digits only
            charType = (enCharType)randomNumber(1, 3);
        }

        switch (charType)
        {

        case enCharType::SmallLetter:
        {
            return char(randomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(randomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(randomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(randomNumber(48, 57));
            break;
        }
        default:
        {
            return char(randomNumber(65, 90));
            break;
        }
        }
    }

    static  string generateWord(enCharType charType, short length)
    {
        string word;

        for (int i = 1; i <= length; i++)

        {

            word = word + getRandomCharacter(charType);

        }
        return word;
    }

    static string  generateKey(enCharType charType = CapitalLetter)
    {

        string key = "";

        key = generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4);


        return key;
    }

    static void generateKeys(short numberOfKeys, enCharType charType)
    {

        for (int i = 1; i <= numberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << generateKey(charType) << endl;
        }

    }

    static void fillArrayWithRandomNumbers(int arr[100], int arrLength, int from, int to)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = randomNumber(from, to);
    }

    static void fillArrayWithRandomWords(string arr[100], int arrLength, enCharType charType, short wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = generateWord(charType, wordlength);

    }

    static void fillArrayWithRandomKeys(string arr[100], int arrLength, enCharType charType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = generateKey(charType);
    }

    static  void swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void swap(clsDate& A, clsDate& B)
    {
        clsDate::swapDates(A, B);

    }

    static  void shuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
        }

    }

    static  void shuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
        }

    }

    static string  tabs(short numberOfTabs)
    {
        string t = "";

        for (int i = 1; i < numberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  encryptText(string text, short encryptionKey = 2)
    {

        for (int i = 0; i < text.length(); i++)
        {

            text[i] = char((int)text[i] + encryptionKey);

        }

        return text;

    }

    static string  decryptText(string text, short encryptionKey = 2)
    {

        for (int i = 0; i < text.length(); i++)
        {
            text[i] = char((int)text[i] - encryptionKey);
        }
        return text;

    }

    static string numberToText(long long number)
    {
        if (number >= 0 && number <= 19)
        {
            string arr[] = 
            { 
                "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                "Seventeen", "Eighteen", "Nineteen"
            };
            
            return arr[number];
        }
        else if (number >= 20 && number <= 99)
        {
            string arr[] = 
            {
                "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
            };

            return (arr[number / 10] + " " + numberToText(number % 10));
        }
        else if (number >= 100 && number <= 199)
        {
            return "One Hundred " + numberToText(number % 100);
        }
        else if (number >= 200 && number <= 999)
        {
            return numberToText(number / 100) + " Hundreds " + numberToText(number % 100);
        }
        else if (number >= 1000 && number <= 1999)
        {
            return "One Thousand " + numberToText(number % 1000);
        }
        else if (number >= 2000 && number <= 999999)
        {
            return numberToText(number / 1000) + " Thousands " + numberToText(number % 1000);
        }
        else if (number >= 1000000 && number <= 1999999)
        {
            return "One Million " + numberToText(number % 1000000);
        }
        else if (number >= 1000000 && number <= 999999999)
        {
            return numberToText(number / 1000000) + " Millions " + numberToText(number % 1000000);
        }
        else if (number >= 1000000000 && number <= 1999999999)
        {
            return "One Billion " + numberToText(number % 1000000000);
        }
        else
        {
            return numberToText(number / 1000000000) + " Billions " + numberToText(number % 1000000000);
        }
    }

};


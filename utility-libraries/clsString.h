
//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString 
{

private:
    string _value;

public:

    clsString()
    {
       _value = "";
    }

    clsString(string value)
    {
        _value = value;
    }

    void SetValue(string value) {
        _value = value;
    }

    string getValue() {
        return _value;
    }
   
    static short length(string s1)
    {
        return s1.length();
    };

    short length()
    {
        return _value.length();
    };

    static short countWords(string s1)
    {

        string delim = " "; // delimiter  
        short counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = s1.find(delim)) != std::string::npos)
        {
            sWord = s1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                counter++;
            }

            //erase() until positon and move to next word.
            s1.erase(0, pos + delim.length());
        }

        if (s1 != "")
        {
            counter++; // it counts the last word of the string.
        }

        return counter;

    }

    short countWords()
    {
        return countWords(_value);
    };

    static string  upperFirstLetterOfEachWord(string s1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < s1.length(); i++)
        {

            if (s1[i] != ' ' && isFirstLetter)
            {
                s1[i] = toupper(s1[i]);

            }

            isFirstLetter = (s1[i] == ' ' ? true : false);

        }

        return s1;
    }

    void  upperFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
       _value = upperFirstLetterOfEachWord(_value);
    }

    static string  lowerFirstLetterOfEachWord(string s1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < s1.length(); i++)
        {

            if (s1[i] != ' ' && isFirstLetter)
            {
                s1[i] = tolower(s1[i]);

            }

            isFirstLetter = (s1[i] == ' ' ? true : false);

        }

        return s1;
    }

    void  lowerFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
        _value = lowerFirstLetterOfEachWord(_value);
    }
    
    static string  upperAllString(string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = toupper(s1[i]);
        }
        return s1;
    }

    void  upperAllString()
   {
       _value = upperAllString(_value);
   }

    static string  lowerAllString(string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = tolower(s1[i]);
        }
        return s1;
    }

   void  lowerAllString()
    {
        _value = lowerAllString(_value);
    }

   static char  invertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

   static string  invertAllLettersCase(string s1)
   {
       for (short i = 0; i < s1.length(); i++)
       {
           s1[i] = invertLetterCase(s1[i]);
       }
       return s1;
   }

   void  invertAllLettersCase()
   {
       _value = invertAllLettersCase(_value);
   }

   enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

   static short countLetters(string s1, enWhatToCount WhatToCount = enWhatToCount::All)
   {
       if (WhatToCount == enWhatToCount::All)
       {
           return s1.length();
       }

       short counter = 0;

       for (short i = 0; i < s1.length(); i++)
       {

           if (WhatToCount == enWhatToCount::CapitalLetters && isupper(s1[i]))
               counter++;


           if (WhatToCount == enWhatToCount::SmallLetters && islower(s1[i]))
               counter++;


       }

       return counter;

   }
  
   static short  countCapitalLetters(string s1)
   {

       short counter = 0;

       for (short i = 0; i < s1.length(); i++)
       {

           if (isupper(s1[i]))
               counter++;

       }

       return counter;
   }

   short  countCapitalLetters()
   {
       return countCapitalLetters(_value);
   }

   static short  countSmallLetters(string s1)
   {

       short counter = 0;

       for (short i = 0; i < s1.length(); i++)
       {

           if (islower(s1[i]))
               counter++;

       }

       return counter;
   }

   short  countSmallLetters()
   {
       return countSmallLetters(_value);
   }
   
   static short  countSpecificLetter(string s1, char letter, bool matchCase = true)
   {

       short counter = 0;

       for (short i = 0; i < s1.length(); i++)
       {

           if (matchCase)
           {
               if (s1[i] == letter)
                   counter++;
           }
           else
           {
               if (tolower(s1[i]) == tolower(letter))
                   counter++;
           }

       }

       return counter;
   }

   short  countSpecificLetter( char letter, bool matchCase = true)
  {
      return countSpecificLetter(_value, letter, matchCase);
  }

   static bool isVowel(char Ch1)
  {
      Ch1 = tolower(Ch1);

      return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

  }

   static short  countVowels(string s1)
  {

      short counter = 0;

      for (short i = 0; i < s1.length(); i++)
      {

          if (isVowel(s1[i]))
              counter++;

      }

      return counter;
  }

   short  countVowels()
  {
      return countVowels(_value);
  }

   static vector<string> split(string s1, string delim)
  {

      vector<string> vString;

      short pos = 0;
      string sWord; // define a string variable  

      // use find() function to get the position of the delimiters  
      while ((pos = s1.find(delim)) != std::string::npos)
      {
          sWord = s1.substr(0, pos); // store the word   
          if (sWord != "")
          {
              vString.push_back(sWord);
          }

          s1.erase(0, pos + delim.length());  /* erase() until positon and move to next word. */
      }

      if (s1 != "")
      {
          vString.push_back(s1); // it adds last word of the string.
      }

      return vString;

  }

   vector<string> split( string delim)
  {
      return split(_value, delim);
  }

   static string trimLeft(string s1)
  {


      for (short i = 0; i < s1.length(); i++)
      {
          if (s1[i] != ' ')
          {
              return s1.substr(i, s1.length() - i);
          }
      }
      return "";
  }

   void trimLeft()
 {
     _value = trimLeft(_value);
 }

   static string trimRight(string s1)
  {


      for (short i = s1.length() - 1; i >= 0; i--)
      {
          if (s1[i] != ' ')
          {
              return s1.substr(0, i + 1);
          }
      }
      return "";
  }
 
   void trimRight()
  {
      _value = trimRight(_value);
  }

   static string trim(string s1)
  {
      return (trimLeft(trimRight(s1)));

  }

   void trim()
  {
      _value= trim(_value);
  }

   static string joinString(vector<string> vString, string delim)
  {

      string s1 = "";

      for (string& s : vString)
      {
          s1 = s1 + s + delim;
      }

      return s1.substr(0, s1.length() - delim.length());


  }

   static string joinString(string arrString[], short length, string delim)
  {

      string s1 = "";

      for (short i = 0; i < length; i++)
      {
          s1 = s1 + arrString[i] + delim;
      }

      return s1.substr(0, s1.length() - delim.length());

  }

   static string reverseWordsInString(string s1)
  {

      vector<string> vString;
      string s2 = "";

      vString = split(s1, " ");

      // declare iterator
      vector<string>::iterator iter = vString.end();

      while (iter != vString.begin())
      {

          --iter;
          s2 += *iter + " ";

      }

      s2 = s2.substr(0, s2.length() - 1); //remove last space.

      return s2;
  }

   void reverseWordsInString()
  {
      _value = reverseWordsInString(_value);
  }

   static string replaceWord(string s1, string stringToReplace, string sRepalceTo, bool matchCase = true)
  {

      vector<string> vString = split(s1, " ");

      for (string& s : vString)
      {
          if (matchCase)
          {
              if (s == stringToReplace)
              {
                  s = sRepalceTo;
              }
          }
          else
          {
              if (lowerAllString(s) == lowerAllString(stringToReplace))
              {
                  s = sRepalceTo;
              }
          }

      }

      return joinString(vString, " ");
  }

   string replaceWord(string stringToReplace, string sRepalceTo)
 {
     return replaceWord(_value, stringToReplace, sRepalceTo);
 }

   static string removePunctuations(string s1)
 {

     string S2 = "";

     for (short i = 0; i < s1.length(); i++)
     {
         if (!ispunct(s1[i]))
         {
             S2 += s1[i];
         }
     }

     return S2;

 }

   void removePunctuations()
 {
     _value = removePunctuations(_value);
 }
 
};


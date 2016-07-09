/*****************************************************************************/
/*!
\file main.cpp
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 26/06/2016
\brief
  Contains intitial code for the PhonetGenerator. This file is also currently
  responsible for reading in the phoneme and pronunciation data. This should
  eventually be segmented from this file.

\par
    Functions Include:
    - read_file
    - main
*/
/*****************************************************************************/

#include <iostream> // cout, endl
#include <fstream>  // ifstream
#include <vector>   // vector:c
#include <string>   // string:c
#include <ctime>    // time

#include "../header/Phoneme.h" // Phoneme:c
#include "../header/Phonet.h"  // Phonet:c

/*****************************************************************************/
/*!
\brief
  Reads in each line from a file into seperate elemnts of a provided vector.

\param vector
  A reference to the vector the file data will be pushed into.

\param file_name
  The name of the file being read into the vector reference.
*/
/*****************************************************************************/
void read_file(std::vector<std::string> & vector, const char * file_name)
{
  std::ifstream file(file_name);
  if(!file.is_open())
    std::cout << "File [" << file_name << "] Not Opened" << std::endl;
  else
  {
    std::string line;
    std::getline(file, line);
    while(!file.eof())
    {
      vector.push_back(line);
      std::getline(file, line);
    }
  }
}

void create_phonemes(std::vector<Phoneme> & phonemes,
                     std::vector<std::string> & sounds,
                     std::vector<std::string> & examples)
{

  std::vector<std::string>::iterator sound;
  std::vector<std::string>::iterator example;

  for(sound = sounds.begin(), example = examples.begin();
      sound != sounds.end() || example != examples.end();
      ++sound, ++example)
  {
    Phoneme phoneme(*sound, *example);
    phonemes.push_back(phoneme);
  }
}

/*****************************************************************************/
/*!
\brief
  Program start function. Currently responsible for reading in data and
  generating a phonet for printing.

\param argc
  The number of arguments provided on the command line (includes executable
  name)

\param argv
  An array of character arrays containing the strings provided on the command
  line.

\return Main Int
*/
/*****************************************************************************/

int main(int argc, char ** argv)
{
  std::vector<std::string> str_phoneme_consonant;
  std::vector<std::string> str_phoneme_vowel;
  std::vector<std::string> str_pronunciation_consonant;
  std::vector<std::string> str_pronunciation_vowel;

  read_file(str_phoneme_consonant, "../data/phoneme/consonant.txt");
  read_file(str_phoneme_vowel, "../data/phoneme/vowel.txt");
  read_file(str_pronunciation_consonant, "../data/pronunciation/consonant.txt");
  read_file(str_pronunciation_vowel, "../data/pronunciation/vowel.txt");

  std::vector<Phoneme> phonemes_consonants;
  std::vector<Phoneme> phonemes_vowels;

  create_phonemes(phonemes_consonants,
                  str_phoneme_consonant,
                  str_pronunciation_consonant);
  create_phonemes(phonemes_vowels,
                  str_phoneme_vowel,
                  str_pronunciation_vowel);

  Phonet phonet;
  phonet.generate(phonemes_consonants, phonemes_vowels, (unsigned)time(0));
  phonet.print();

  return 0;
}

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
#include <vector>   // vector:c
#include <string>   // string:c
#include <ctime>    // time

#include "../header/Phoneme.h"   // Phoneme:c
#include "../header/Phonet.h"    // Phonet:c
#include "../header/data_grab.h" // read_file, create_phonemes

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
  std::vector<std::string> str_vowels;
  std::vector<std::string> str_consonants;

  read_file(str_consonants, "../data/phoneme/consonant.txt");
  read_file(str_vowels, "../data/phoneme/vowel.txt");


  std::vector<Phoneme> phonemes_consonants;
  std::vector<Phoneme> phonemes_vowels;

  create_phonemes(phonemes_consonants,
                  str_consonants);
  create_phonemes(phonemes_vowels,
                  str_vowels);

  Phonet phonet;
  phonet.generate(phonemes_consonants, phonemes_vowels, (unsigned)time(0));
  std::cout << phonet << std::endl;
  phonet.print_pronunciation();
  std::cout << std::endl;
  phonet.print_spelling();
  std::cout << std::endl;

  return 0;
}

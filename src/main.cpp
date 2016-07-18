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
    - main

\bug
  Negative numbers for min and max lengths are not accounted for.
\bug
  Min length being greater than the max length is not accounted for.
\bug
  Program does not terminate on file error.
\bug
  Program does not terminate on switch error.
*/
/*****************************************************************************/

#include <iostream> // cout, endl
#include <vector>   // vector:c
#include <string>   // string:c
#include <cstdlib>  // srand
#include <ctime>    // time

#include "../header/Options.h"   // Options:c
#include "../header/Phoneme.h"   // Phoneme:c
#include "../header/Phonet.h"    // Phonet:c
#include "../header/data_grab.h" // read_file, create_phonemes

/*****************************************************************************/
/*!
\brief
  Program start function. Currently responsible for reading in data and
  generating a phonet for printing.

\param argc
  The number of arguments provided on the command line.
\param argv
  The strings of the arguments provided on the command line.

\return main int
*/
/*****************************************************************************/
int main(int argc, char ** argv)
{
  // Getting all data
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
  // Applying options
  Options options(argc, argv);
  srand(options.get_seed());
  // Printing Phonets
  for(unsigned i_phonet = 0; i_phonet < options.get_num_words(); ++i_phonet)
  {
    std::cout << "=========={Phonet}" << std::endl;
    Phonet phonet(phonemes_consonants, phonemes_vowels,
                  options.get_min_length(), options.get_max_length());
    std::cout << phonet << std::endl;
    if(options.get_pronunciation())
    {
      std::cout << "----------[Pronunciation]" << std::endl;
      phonet.print_pronunciation();
      std::cout << std::endl;
    }
    if(options.get_num_spellings() > 0)
    {
      std::cout << "----------[Spelling]" << std::endl;
      for(unsigned i_spelling = 0; i_spelling < options.get_num_spellings(); ++i_spelling)
      {
        phonet.print_spelling();
        std::cout << std::endl;
      }
    }
  }
  return 0;
}

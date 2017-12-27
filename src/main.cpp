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

#include "../header/Options.h"     // Options:c
#include "../header/Phoneme.h"     // Phoneme:c
#include "../header/Phonet.h"      // Phonet:c
#include "../header/PhonemePool.h" // PhonemePool:c

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
  // Applying options
  Options options(argc, argv);
  // Creating the pool of phonemes
  PhonemePool pool(options.get_phoneme_file().c_str());
  srand(options.get_seed());
  if(options.get_help())
    Options::print_help();
  // make sure the phoneme file was successfully read
  if(!pool.read_success())
    return 1;
  // Creating and Printing Phonets
  for(unsigned i_phonet = 0; i_phonet < options.get_num_words(); ++i_phonet)
  {
    std::cout << "=========={Phonet}" << std::endl;
    Phonet phonet(pool, options.get_min_length(), options.get_max_length());
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

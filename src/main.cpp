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

#include "../header/Phonet.h" // Phonet:c

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
  std::vector<std::string> phoneme_consonant;
  std::vector<std::string> phoneme_vowel;
  std::vector<std::string> pronunciation_consonant;
  std::vector<std::string> pronunciation_vowel;

  read_file(phoneme_consonant, "../data/phoneme/consonant.txt");
  read_file(phoneme_vowel, "../data/phoneme/vowel.txt");
  read_file(pronunciation_consonant, "../data/pronunciation/consonant.txt");
  read_file(pronunciation_vowel, "../data/pronunciation/vowel.txt");

  Phonet phonet;
  phonet.generate(phoneme_consonant, phoneme_vowel, (unsigned)time(0));
  phonet.print();

  return 0;
}

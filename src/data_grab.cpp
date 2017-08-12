/*****************************************************************************/
/*!
\file data_grab.cpp
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 13/07/2016
\brief
  This file contains helper functions for grabbing phoneme data from file and
  organizing that phoneme data into the Phoneme class so it can be used by the
  PhonetGenerator. The phoneme data files can be found in data/.

\par
    Functions Include:
    - read_file
    - parse
    - parse_phoneme_data
    - create_phonemes

\deprecated
    - create_phonemes parameters changed.
*/
/*****************************************************************************/

#include <iostream> // cout, endl
#include <fstream>  // ifstream
#include <vector>   // vector:c
#include <string>   // string:c

#include "../header/Phoneme.h" // Phoneme:c

#include "../header/data_grab.h"

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
                     const std::vector<std::string> & data)
{
  // the indicies that rules begin
  std::vector<size_t> rule_starts;
  extract_phoneme_data(phonemes, data, rule_starts);
  extract_rule_data(phonemes, data, rule_starts);
}

inline void extract_phoneme_data(std::vector<Phoneme> & phonemes,
                                const std::vector<std::string> & data,
                                std::vector<size_t> & rule_starts)
{
  std::vector<std::string>::const_iterator it = data.begin();
  std::vector<std::string>::const_iterator it_e = data.end();
  for(; it != it_e; ++it)
  {
    std::string phoneme;
    std::string example;
    std::string spellings;
    // start and end of a substring
    size_t start = 0;
    size_t end = 0;
    // getting phoneme string
    end = it->find((char)':', start);
    phoneme = it->substr(start, end - start);
    // getting example string
    start = end + 1;
    end = it->find((char)':', start);
    example = it->substr(start, end - start);
    // getting spellings string
    start = end + 1;
    end = it->find((char)':', start);
    spellings = it->substr(start, end - start);
    rule_starts.push_back(end + 1);
    // creating the new phoneme
    phonemes.push_back(Phoneme(phoneme, example, spellings));
  }
}

inline void extract_rule_data(std::vector<Phoneme> & phonemes,
                              const std::vector<std::string> & data,
                              std::vector<size_t> & rule_starts)
{
  unsigned current_phoneme = 0;
  while(current_phoneme < phonemes.size())
  {

    size_t start = rule_starts[current_phoneme];
    size_t end = rule_starts[current_phoneme];

    if(start >= data.size())
      continue;

    end = data[current_phoneme].find(',', start);
    while(end != std::string::npos)
    {
      // clean this up a little
      std::string new_rule_str = data[current_phoneme].substr(start, end - start);
      Phoneme * new_rule = find_phoneme(phonemes, new_rule_str);
      if(new_rule)
        phonemes[current_phoneme].add_rule(new_rule);

      start = end + 1;
      end = data[current_phoneme].find(',', start);
    }
    std::string new_rule_str = data[current_phoneme].substr(start, data.size() - start);
    Phoneme * new_rule = find_phoneme(phonemes, new_rule_str);
    if(new_rule)
      phonemes[current_phoneme].add_rule(new_rule);
    ++current_phoneme;
  }
}

Phoneme * find_phoneme(std::vector<Phoneme> & phonemes,
                       const std::string & phoneme_string)
{
  std::vector<Phoneme>::iterator it = phonemes.begin();
  std::vector<Phoneme>::iterator it_e = phonemes.end();
  for(; it != it_e; ++it)
  {
    if((*it) == phoneme_string)
      return &(*it);
  }
  // YOU SHOULD PROBABLY THROUGH AN EXCEPTION OR SOMEthing HERE
  return NULL;
}

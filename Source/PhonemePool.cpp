/*****************************************************************************/
/*!
\file PhonemePool.cpp
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 13/08/2017
\brief
  Contains the implementation for the PhonemePool.
*/
/*****************************************************************************/

#include <cstdlib>  // rand
#include <vector>   // vector:c
#include <string>   // string:c
#include <iostream> // cout
#include "../Header/utility.h" // read_file
#include "../Header/PhonemePool.h"

//! string null terminator
#define NUL '\0'

/*****************************************************************************/
/*!
\brief
  Constructor for the PhonemePool. This will create a pool of phonemes using
  an existing phoneme config file for the generator.

\param phoneme_file
  The path to the file which all the phoneme data will be read from.
*/
/*****************************************************************************/
PhonemePool::PhonemePool(const char * phoneme_file) : m_phonemes(),
  m_read_success(false)
{
  std::vector<std::string> phoneme_data;
  read_file(phoneme_data, phoneme_file);

  std::vector<size_t> rule_starts;
  try
  {
    extract_phoneme_data(phoneme_data, rule_starts);
    extract_rule_data(phoneme_data, rule_starts);
    m_read_success = true;
  }
  catch(const std::string & error)
  {
    std::cout << "Error | " << error << std::endl;
  }
}

/*****************************************************************************/
/*!
\brief
  Gets a randome Phoneme from the pool.

\return A random Phoneme from the pool.
*/
/*****************************************************************************/
const Phoneme * PhonemePool::get_phoneme() const
{
  long unsigned phoneme_index = rand() % m_phonemes.size();
  return &(m_phonemes[phoneme_index]);
}

/*****************************************************************************/
/*!
\brief
  Returns true if the phoneme file was successfully read.

\return Look at brief.
*/
/*****************************************************************************/
bool PhonemePool::read_success() const
{
  return m_read_success;
}

/*****************************************************************************/
/*!
\brief
  Extracts all the phoneme data from text into phoneme objects. This function
  does not handle the parsing of the rules.

\param data
  The data that was read in from the phoneme config file.
\param rule_starts
  A vector that contains the idicies at which the rules for the phonemes begin.
  These indices refer to positions in the strings within the data parameter.
  This is only really crucial for extract_rule_data.
*/
/*****************************************************************************/
inline
void PhonemePool::extract_phoneme_data(const std::vector<std::string> & data,
                                       std::vector<size_t> & rule_starts)
{
  unsigned current_line = 1;
  std::vector<std::string>::const_iterator it = data.begin();
  std::vector<std::string>::const_iterator it_e = data.end();

  for(; it != it_e; ++it)
  {
    // saving line number into a string for errors
    char line_num_buffer[10];
    sprintf(line_num_buffer, "%d", current_line);
    std::string line_number(line_num_buffer);
    // extracting phonemes
    std::string phoneme;
    std::string example;
    std::string spellings;
    // start and end of a substring
    size_t start = 0;
    size_t end = 0;
    size_t distance = 0;
    // getting phoneme string
    end = it->find((char)':', start);
    // make sure there is an ending colon for the identifier
    if(end == std::string::npos)
    {
      std::string error("Line : ");
      error.append(line_number);
      error.append(" | Ending ':' for phoneme identifier not found");
      throw(error);
    }
    distance = end - start;
    phoneme = it->substr(start, distance);
    // getting example pronunciation
    start = end + 1;
    end = it->find((char)':', start);
    // make sure there is an ending colon for the pronunciation
    if(end == std::string::npos)
    {
      std::string error("Line : ");
      error.append(line_number);
      error.append(" | Ending ':' for phoneme pronunciation not found");
      throw(error);
    }
    example = it->substr(start, end - start);
    // getting spellings string
    start = end + 1;
    end = it->find((char)':', start);
    // make sure there is an ending colon for the spellings
    if(end == std::string::npos)
    {
      std::string error("Line : ");
      error.append(line_number);
      error.append(" | Ending ':' for phoneme spellings not found");
      throw(error);
    }
    spellings = it->substr(start, end - start);
    rule_starts.push_back(end + 1);
    // creating the new phoneme
    m_phonemes.push_back(Phoneme(phoneme, example, spellings, current_line));
    ++current_line;
  }
}

/*****************************************************************************/
/*!
\brief
  Extracts to rule data for phonemes from the raw phoneme data.

\param data
  The raw phoneme data read from file.
\param rule_starts
  A vector that contains the idicies at which the rules for the phonemes begin.
  These indices refer to positions in the strings within the data parameter.
*/
/*****************************************************************************/
inline
void PhonemePool::extract_rule_data(const std::vector<std::string> & data,
                                    const std::vector<size_t> & rule_starts)
{
  unsigned current_phoneme = 0;
  while(current_phoneme < m_phonemes.size())
  {

    size_t start = rule_starts[current_phoneme];
    size_t end = rule_starts[current_phoneme];
    if(start >= data.size())
    {
      ++current_phoneme;
      continue;
    }

    end = data[current_phoneme].find(',', start);
    while(end != std::string::npos)
    {
      // clean this up a little
      std::string new_rule_str = data[current_phoneme].substr(start,
                                                              end - start);
      Phoneme * new_rule = find_phoneme(new_rule_str);
      if(new_rule)
        m_phonemes[current_phoneme].add_rule(new_rule);

      start = end + 1;
      end = data[current_phoneme].find(',', start);
    }
    std::string new_rule_str =
      data[current_phoneme].substr(start, data.size() - start);
    Phoneme * new_rule = find_phoneme(new_rule_str);
    if(new_rule)
      m_phonemes[current_phoneme].add_rule(new_rule);
    ++current_phoneme;
  }
}

/*****************************************************************************/
/*!
\brief
  Will find a phoneme that exists within the pool using a string that contains
  the phoneme name.

\param phoneme_string
  The string that contains the phoneme name.

\return If the Phoneme is found, a pointer to the Phoneme object is returned.
  If not, an exception will be thrown.
*/
/*****************************************************************************/
Phoneme * PhonemePool::find_phoneme(const std::string & phoneme_string)
{
  std::vector<Phoneme>::iterator it = m_phonemes.begin();
  std::vector<Phoneme>::iterator it_e = m_phonemes.end();
  for(; it != it_e; ++it)
  {
    if((*it) == phoneme_string)
      return &(*it);
  }
  // YOU SHOULD PROBABLY THROUGH AN EXCEPTION OR SOMEthing HERE
  return NULL;
}

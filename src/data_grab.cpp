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
  Parses a line of string data by putting each set of string data between a
  specified delimiter into a vector. If the delimiter does not appear in the
  string provided, the vector will contain one element consisting of the whole
  string.
\par
  Example
  If this was the data passed into the parse function (this/is/data), and the
  delimiter passed to the parse function was '/', the storage string vector
  would be filled with the follwing three elements.
  - this
  - is
  - data

\param storage
  The parsed string data will be stored in this provided vector.
\param data
  This is the string that will be parsed and processed to be stored in the
  storage vector.
\param delimiter
  This is the delimiter that will be used to separate one vector element from
  another in the data string.
*/
/*****************************************************************************/
void parse (std::vector<std::string> & storage, const std::string & data,
            const int delimiter)
{
  size_t start = 0;
  size_t end = 0;
  end = data.find(delimiter, start);

  while(end != std::string::npos)
  {
    storage.push_back(data.substr(start, end - start));
    start = end + 1;
    end = data.find(delimiter, start);
  }
  storage.push_back(data.substr(start, data.size()));
}

/*****************************************************************************/
/*!
\brief
  Given a line of phoneme file data, this function will seperate the different
  elemnts of the phoneme data in order to more easily create phonemes from the
  file data.

\param phoneme
  The actual phoneme will be stored here.
\param pronunciation
  The string specifying the sound of the phoneme will be stored here.
\param spellings
  The string containing all of the possible spellings for the phoneme will be
  stored here.
\param data
  This is the string that contains the data from file to be parsed and put into
  the other string containers.
*/
/*****************************************************************************/
void parse_phoneme_data(std::string & phoneme, std::string & pronunciation,
  std::string & spellings, const std::string & data)
  {
    size_t start = 0;
    size_t end = 0;

    end = data.find(':');
    phoneme = data.substr(start, end - start);

    start = end + 1;
    end = data.find(':',start);
    pronunciation = data.substr(start, end - start);

    start = end + 1;
    end = data.size();
    spellings = data.substr(start, end - start);
  }

/*****************************************************************************/
/*!
\brief
  A helper function that takes in the string data read from file and puts the
  data into Phonemes in order to use the Phonemes within a Phonet.

\param phonemes
  All the Phoneme data will be stored in this vector of Phonemes.
\param data
  A vector of strings containing the phoneme data that was read from file.
*/
/*****************************************************************************/
void create_phonemes(std::vector<Phoneme> & phonemes,
                     const std::vector<std::string> & data)
{
  std::vector<std::string>::const_iterator phoneme_data;

  for(phoneme_data = data.begin(); phoneme_data != data.end(); ++phoneme_data)
  {
    std::string phoneme;
    std::string pronunciation;
    std::string spellings_str;
    parse_phoneme_data(phoneme, pronunciation, spellings_str, (*phoneme_data));

    std::vector<std::string> spellings;
    parse(spellings, spellings_str, ',');

    Phoneme new_phoneme(phoneme, pronunciation, spellings);
    phonemes.push_back(new_phoneme);
  }
}

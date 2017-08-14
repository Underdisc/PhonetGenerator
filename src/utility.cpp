/*****************************************************************************/
/*!
\file utility.cpp
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 13/07/2016
\brief
  This file only contains utility functions. Currently only one.

\par
    Functions Include:
    - read_file
*/
/*****************************************************************************/

#include <iostream> // cout, endl
#include <fstream>  // ifstream
#include <vector>   // vector:c
#include <string>   // string:c

#include "../header/utility.h"

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

/*****************************************************************************/
/*!
\file Options.cpp
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 15/07/2016
\brief
  Contains the implementation of the Options class. For more information on the
  class, open the Options.h file.

\par
    Functions Include:
    - Parameterized constructor
    - Destructor
    - parse_options
    - get_min_length
    - get_max_length
    - get_num_words
    - get_num_spellings
    - get_pronunciation
*/
/*****************************************************************************/

#include <getopt.h> // getopt
#include <ctime>    // time
#include <cstdlib>  // srand, atoi
#include <iostream> // cout, endl

#include "../header/Options.h" //Options:h

/*****************************************************************************/
/*!
\brief
  Parameterized constructor for the Options class. This is the classes only
  constructor. This constructor will also set the defaults for the Options
  object's members.

\par
    Defautls
    - m_min_length = 2
    - m_max_length = 10
    - m_num_words = 1
    - m_num_spellings = 1
    - m_pronunciation = false
    - m_seed = time(0)

\param argc
  The argc from main.
\param argv
  The argv from main.
*/
/*****************************************************************************/
Options::Options(int argc, char ** argv): m_min_length(2), m_max_length(10),
m_num_words(1), m_num_spellings(1), m_pronunciation(false),
m_seed((unsigned)time(0))
{
  parse_options(argc, argv);
}

/*****************************************************************************/
/*!
\brief
  Destructor for the Options class.
*/
/*****************************************************************************/
Options::~Options()
{
}

/*****************************************************************************/
/*!
\brief
  This is responsible for parsing the functions from argc and argv
  and ajdusting the PhonetGenerator's configurations using getopt.

\param argc
  The argc from main.
\param argv
  The argv from main.
*/
/*****************************************************************************/
void Options::parse_options(int argc, char ** argv)
{
  bool error = false;
  int opt;
  while((opt = getopt(argc, argv, ":n:x:w:s:pr:")) != -1)
  {
    switch (opt)
    {
      case 'n':
        std::cout << "n (min_length) provided" << std::endl;
        m_min_length = atoi(optarg);
        break;
      case 'x':
        std::cout << "x (max_length) provided" << std::endl;
        m_max_length = atoi(optarg);
        break;
      case 'w':
        std::cout << "w (num_words) provided" << std::endl;
        m_num_words = atoi(optarg);
        break;
      case 's':
        std::cout << "s (num_spellings) provided" << std::endl;
        m_num_spellings = atoi(optarg);
        break;
      case 'p':
        std::cout << "p (pronunciation) provided" << std::endl;
        m_pronunciation = true;
        break;
      case 'r':
        std::cout << "r (seed) provided" << std::endl;
        m_seed = (unsigned)atoi(optarg);
        srand(m_seed);
        break;
      case '?':
        std::cout << "The provided option [" << (char)optopt
                  << "] is not an option." << std::endl;
        error = true;
        break;
      case ':':
        std::cout << "The provided option [" << (char)optopt
                  << "] requires an argument." << std::endl;
        error = true;
        break;
    }
  }
  // Use an exception
  // This exception should also handle invalid files
  if(error)
  {
    std::cout << "Use -h or --help to see all options "
              << "and how they are used." << std::endl;
  }
}

/*****************************************************************************/
/*!
\brief
  Gets the value of m_min_length.

\return
  The value of m_min_length.
*/
/*****************************************************************************/
size_t Options::get_min_length() { return m_min_length; }

/*****************************************************************************/
/*!
\brief
  Gets the value of m_max_length.

\return
  The value of m_max_length.
*/
/*****************************************************************************/
size_t Options::get_max_length() { return m_max_length; }

/*****************************************************************************/
/*!
\brief
  Gets the value of m_num_words.

\return
  The value of m_num_words.
*/
/*****************************************************************************/
unsigned Options::get_num_words()  { return m_num_words; }

/*****************************************************************************/
/*!
\brief
  Gets the value of m_num_spellings.

\return
  The value of m_num_spellings.
*/
/*****************************************************************************/
unsigned Options::get_num_spellings() { return m_num_spellings; }

/*****************************************************************************/
/*!
\brief
  Gets the value of m_pronunciation.

\return
  The value of m_pronunciation.
*/
/*****************************************************************************/
bool Options::get_pronunciation() { return m_pronunciation; }

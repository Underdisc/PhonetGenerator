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
    - print_help
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
    - m_num_spellings = 0
    - m_pronunciation = false
    - m_seed = time(0)
    - m_phoneme_file = "config/english_vcvc.phoneme"

\param argc
  The argc from main.
\param argv
  The argv from main.
*/
/*****************************************************************************/
Options::Options(int argc, char ** argv): m_min_length(2), m_max_length(10),
m_num_words(1), m_num_spellings(0), m_pronunciation(false),
m_phoneme_file("config/english_vcvc.phoneme")
{
  m_seed = (unsigned)time(0);
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
  while(1)
  {
    int opt_index = 0;
    static struct option long_options[] =
    {
      {"minimum-length", required_argument, NULL, 'n'},
      {"maximum-length", required_argument, NULL, 'x'},
      {"words",          required_argument, NULL, 'w'},
      {"spellings",      required_argument, NULL, 's'},
      {"pronunciation",  no_argument,       NULL, 'p'},
      {"seed",           required_argument, NULL, 'r'},
      {"file",           required_argument, NULL, 'f'},
      {"help",           no_argument,       NULL, 'h'}
    };

    opt = getopt_long(argc, argv, ":n:x:w:s:ps:r:f:h", long_options, &opt_index);
    if(opt == -1)
      break;
    switch (opt)
    {
      case 'n': m_min_length = atoi(optarg);     break;
      case 'x': m_max_length = atoi(optarg);     break;
      case 'w': m_num_words = atoi(optarg);      break;
      case 's': m_num_spellings = atoi(optarg);  break;
      case 'p': m_pronunciation = true;          break;
      case 'r': m_seed = (unsigned)atoi(optarg); break;
      case 'f': m_phoneme_file = optarg;         break;
      case 'h': print_help();                    break;
      case '?': std::cout << "The provided option [" << (char)optopt
                          << "] is not an option." << std::endl;
                error = true; break;
      case ':': std::cout << "The provided option [" << (char)optopt
                          << "] requires an argument." << std::endl;
                error = true; break;
    }
  }
  if(error)
    std::cout << "Use -h or --help to see all options and how they are used."
              << std::endl;
}

/*****************************************************************************/
/*!
\brief
  Prints out the help interface for the PhonetGenerator's switches.
*/
/*****************************************************************************/
void Options::print_help()
{
  std::cout << "--minimum-length [number] or -n [number]: "
            << "Decide the minimum number of phonemes in a phonet."
            << std::endl
            << "--maximum-length [number] or -x [number]: "
            << "Decide the maximum number of phonemes in a phonet."
            << std::endl
            << "--words [number] or -w [number]         : "
            << "Decide the number of phonets that are generated."
            << std::endl
            << "-s [number]                             : "
            << "Decide the number of spellings generated for each phonet."
            << std::endl
            << "-p                                      : "
            << "Print the pronunciation of the phonet."
            << std::endl
            << "--seed [number] or -r [number]          : "
            << "Provide the seed used for the randomization. "
            << "If a seed is not provided, the time is used as an alternative."
            << std::endl
            << "-h                                      : "
            << "Prints this." << std::endl;
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

/*****************************************************************************/
/*!
\brief
  Gets the value of the random seed.

\return The random seed value.
*/
/*****************************************************************************/
unsigned Options::get_seed() { return m_seed; }

/*****************************************************************************/
/*!
\brief
  Returns the name of the phoneme data file to be used by the generator.

\return The phoneme config file name.
*/
/*****************************************************************************/
const std::string & Options::get_phoneme_file() { return m_phoneme_file; }

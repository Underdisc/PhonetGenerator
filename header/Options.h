/*****************************************************************************/
/*!
\file Options.h
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 15/07/2016
\brief
  This contains the interface for the PhonetGenerator's options class.
*/
/*****************************************************************************/

/*****************************************************************************/
/*!
\class Options
\brief
  This Options class is specific to the PhonetGenerator. Given argc and argv,
  the constructor for this class will use getopt to parse the command line and
  configure the Options object's members to the proper values. Those members
  are various configurations used for the PhonetGenerator.

\par
    Operations include:
    - Creating the Options object.
    - Getting all members of the Options object through getters.
    - Printing out the help interface for the PhonetGenerator's switches.

\deprecated
    - Nothing

\bug
    - Nothing
*/
/*****************************************************************************/
class Options
{
  public:
    Options(int, char **);
    ~Options();
    size_t get_min_length();
    size_t get_max_length();
    unsigned get_num_words();
    unsigned get_num_spellings();
    bool get_pronunciation();
    unsigned get_seed();
  private:
    void parse_options(int, char **);
    void print_help();
    //! The minimum number of Phonemes that can be in a Phonet.
    size_t m_min_length;
    //! The maximum number of Phonemes that can be in a Phonet.
    size_t m_max_length;
    //! The number of Phonets that will be generated.
    unsigned m_num_words;
    //! The number of spellings that will be generated for each of the Phonets.
    unsigned m_num_spellings;
    //! Determines whether the Phonets' pronunciations will be printed or not.
    bool m_pronunciation;
    //! The seed used for the PhonetGenerator's randomization.
    unsigned m_seed;
};

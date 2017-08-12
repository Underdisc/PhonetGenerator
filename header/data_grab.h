/*****************************************************************************/
/*!
\file data_grab.h
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 13/07/2016
\brief
  The interface for the data_grab.cpp file. For more information on this
  functionalitly, refer to the data_grab.cpp file.
*/
/*****************************************************************************/

void read_file(std::vector<std::string> & vector, const char * file_name);
void create_phonemes(std::vector<Phoneme> & phonemes,
                     const std::vector<std::string> & data);
void extract_phoneme_data(std::vector<Phoneme> & phonemes,
                          const std::vector<std::string> & data,
                          std::vector<size_t> & rule_starts);
void extract_rule_data(std::vector<Phoneme> & phonemes,
                       const std::vector<std::string> & data,
                       std::vector<size_t> & rule_starts);
Phoneme * find_phoneme(std::vector<Phoneme> & phonemes,
                       const std::string & phoneme_string);

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
void parse (std::vector<std::string> & storage, const std::string & data,
            const char delimiter);
void parse_phoneme_data(std::string & phoneme, std::string & pronunciation,
                   std::string & spellings, const std::string & data);
void create_phonemes(std::vector<Phoneme> & phonemes,
                     const std::vector<std::string> & data);

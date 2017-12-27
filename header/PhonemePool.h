/*****************************************************************************/
/*!
\file PhonemePool.h
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 13/08/2017
\brief
  Contains the interface for the PhonemePool.
*/
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
#ifndef PHONEMEPOOL_H
#define PHONEMEPOOL_H
///////////////////////////////////////////////////////////////////////////////

#include <vector> // vector:c

#include "../header/Phoneme.h" // Phoneme:c

/*****************************************************************************/
/*!
\class PhonemePool
\brief
  This class is a wrapper around a vector of phonemes. It is only here to store
  a pool of existing phonemes that are read in from a phoneme file in the
  the constructor.
*/
/*****************************************************************************/
class PhonemePool
{
  public:
    PhonemePool(const char * phoneme_file);
    const Phoneme * get_phoneme() const;
    bool read_success() const;
  private:
    void extract_phoneme_data(const std::vector<std::string> & data,
                              std::vector<size_t> & rule_starts);
    void extract_rule_data(const std::vector<std::string> & data,
                           const std::vector<size_t> & rule_starts);
    Phoneme * find_phoneme(const std::string & phoneme_string);
    //! The vector of phonemes that the PhonemePool holds.
    std::vector<Phoneme> m_phonemes;
    //! Identifies whether the phoneme file was successfully read or not.
    bool m_read_success;
};

#endif

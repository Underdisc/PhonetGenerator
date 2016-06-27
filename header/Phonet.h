/*****************************************************************************/
/*!
\file Phonet.h
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 27/06/2016
\brief
  Interface for the Phonet class.
*/
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
#ifndef Phonet_H
#define Phonet_H
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // srand, rand
#include <string>   // string:c
#include <vector>   // vector:c
#include <iostream> // cout

/*****************************************************************************/
/*!
\class Phonet
\brief
  A Phonet is a vector of phonemes responsible for creating the phonetic version
  of a word. Phonets should only be used to store the phonetic spellings of
  words and not there actual spellings.

\par
    Operations include:
    - Constructing an empty Phonet
    - Constructing a randomly generated Phonet
    - Constructing an already existing Phonet
    - Generating a random Phonet
    - Printing a Phonet to console

\deprecated
    - Nothing

\bug
    - Nothing
*/
/*****************************************************************************/

class Phonet
{
  public:
    Phonet();
    Phonet(std::vector<std::string> &, std::vector<std::string> &, unsigned);
    Phonet(std::vector<std::string> &);
    ~Phonet();
    void generate(std::vector<std::string> &, std::vector<std::string> &, unsigned);
    void print();
  private:


    std::vector<std::string> m_phonet;
    unsigned m_min_length;
    unsigned m_max_length;

    enum Phoneme_Type
    {
      CONSONANT = 0,
      VOWEL = 1
    };
};

#endif
///////////////////////////////////////////////////////////////////////////////

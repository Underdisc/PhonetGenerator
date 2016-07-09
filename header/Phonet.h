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

#include "../header/Phoneme.h" //Phoneme:c

#include <string>   // string:c
#include <vector>   // vector:c

/*****************************************************************************/
/*!
\class Phonet
\brief
  A Phonet is a vector of Phoneme objects responsible for creating the phonetic
  version of a word. Since Phonets consist of Phonemes, the Phonet will also
  hold the pronunciation of the word, suggested spellings for the word, and the
  class will be able to generate its own Phonets.

\par
    Operations include:
    - Constructing an empty Phonet
    - Constructing a randomly generated Phonet
    - Constructing an already existing Phonet
    - Generating a random Phonet
    - Printing a Phonet to console
    - Printing a Phonets pronunciation to console
    - Printing a Phonet to console using << operator

\deprecated
    - Phonets now use Phoneme class instead of std::string.

\bug
    - The generation is terrible.
*/
/*****************************************************************************/

class Phonet
{
  public:
    Phonet();
    Phonet(std::vector<Phoneme> &, std::vector<Phoneme> &, unsigned);
    Phonet(std::vector<Phoneme> &);
    ~Phonet();
    void generate(std::vector<Phoneme> &, std::vector<Phoneme> &, unsigned);
    void print_phonet() const;
    void print_pronunciation() const;
    friend std::ostream & operator<<(std::ostream & os, const Phonet & rhs);

  private:
    //! The vector containing all of the Phonemes responsible for creating the
    // Phonet.
    std::vector<Phoneme> m_phonemes;
    //! The minimum number of Phonemes that this Phonet can contain.
    unsigned m_min_length;
    //! The maximum number of Phonemes that this Phonet can contain.
    unsigned m_max_length;

/*****************************************************************************/
/*!
\enum Phoneme_Type
\brief
  A Phoneme can only be two types, a consonant or a vowel. This is used to
  segment to the phoneme types in order to generate the Phonets

\par
    Members
    - CONSONANT
    - VOWEL
*/
/*****************************************************************************/
    enum Phoneme_Type
    {
      CONSONANT = 0,
      VOWEL = 1
    };
};

#endif
///////////////////////////////////////////////////////////////////////////////

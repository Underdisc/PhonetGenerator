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

#include "../header/Phoneme.h"     //Phoneme:c
#include "../header/PhonemePool.h" //PhonemePool:c

#include <string>   // string:c
#include <vector>   // vector:c

/*****************************************************************************/
/*!
\class Phonet
\brief
  A Phonet is a vector of Phoneme objects responsible for creating the phonetic
  version of a word. If you search for a phonet on the internet, you will likely
  find doucments relating to phonetics. I needed a name for a string of
  phonemes, so I called it a phonet. The Phonemes within the phonet also have
  data that allow phonets to display it's pronunciation and possible spellings
  for the word the phonet can represent.

\par
    Phonet Resources
    - <a href="https://en.wikipedia.org/wiki/Phonetics">Phonetics</a>

\par
    Operations include:
    - Constructing an empty Phonet
    - Constructing a randomly generated Phonet
    - Constructing an already existing Phonet
    - Generating a random Phonet
    - Printing a Phonet to console
    - Printing a Phonets pronunciation to console
    - Printing a possible spelling for the Phonet
    - Printing a Phonet to console using << operator

\deprecated
    - Phonets now use Phoneme class instead of std::string.
    - Phonets no longer need a seed for generation. To seed to generation,
      srand() and give a seed.

\bug
    - The generation is terrible.
*/
/*****************************************************************************/

class Phonet
{
  public:
    Phonet();
    Phonet(const PhonemePool & pool, const size_t, const size_t);
    Phonet(const std::vector<const Phoneme *> &);
    ~Phonet();
    void generate(const PhonemePool & pool);
    void print_phonet() const;
    void print_pronunciation() const;
    void print_spelling() const;
    friend std::ostream & operator<<(std::ostream & os, const Phonet & rhs);

  private:
    //! The vector containing all of the Phonemes responsible for creating the
    // Phonet.
    std::vector<const Phoneme *> m_phonemes;
    //! The minimum number of Phonemes that this Phonet can contain.
    size_t m_min_length;
    //! The maximum number of Phonemes that this Phonet can contain.
    size_t m_max_length;

};

#endif
///////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/*!
\file Phoneme.h
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 06/07/2016
\brief
  Interface for the Phoneme class.
*/
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
#ifndef Phoneme_H
#define Phoneme_H
///////////////////////////////////////////////////////////////////////////////

#include <string> // string:c
#include <vector> // vector:c

/*****************************************************************************/
/*!
\class Phoneme
\brief
  A Phoneme is a fundamental sound within a language. Combinations of phonemes
  are responsible for creating the pronunciation of words. For example, the
  english /b/ phoneme is responsible for the \<beh\> sound in the word \<b\>ad.
  This Phoneme class is for storing those phonemes and certain traits they have.

\par
    Operations include:
    - Constructing a Phoneme using strings
    - Constructing a Phoneme with a Phoneme
    - Printing the Phoneme
    - Printing an example of how the Phoneme is used
    - Setting one Phoneme equal to another
    - Printing a Phoneme with the output operator

\deprecated
    - print_example changed to print_pronunciation

\bug
    - Nothing
*/
/*****************************************************************************/
class Phoneme
{
  public:
    Phoneme();
    Phoneme(const std::string &, const std::string &);
    Phoneme(const Phoneme &);
    ~Phoneme();
    void print_phoneme() const;
    void print_pronunciation() const;
    Phoneme & operator=(const Phoneme &);
    friend std::ostream & operator<<(std::ostream &, const Phoneme &);

  private:
    //! The string where the Phoneme is stored.
    std::string m_phoneme;
    //! The string where an example usage of the phoneme is stored.
    std::string m_example;
};

#endif
///////////////////////////////////////////////////////////////////////////////

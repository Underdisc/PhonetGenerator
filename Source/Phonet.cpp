/*****************************************************************************/
/*!
\file Phonet.cpp
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 27/06/2016
\brief
  Contains the implementation of the Phonet. Details on a Phonet's purpose can
  be found in the Phonet's header file.

\par
    Functions Include:
    - Default Constructor
    - Parameterized Constructor: 2
    - Destructor
    - generate
    - print_phonet
    - print_pronunciation
    - print_spelling
    - operator <<

\par Functions Undergoing Improvement
    - generate
*/
/*****************************************************************************/

#include <cstdlib>  // srand, rand
#include <iostream> // cout, endl
#include "../header/Phonet.h" // Phonet:c

/*****************************************************************************/
/*!
\brief
  Defualt constructor for the Phonet. A Phonet will start with a min length of
  2 and a max length of 10.
*/
/*****************************************************************************/
Phonet::Phonet() : m_phonemes(), m_min_length(2), m_max_length(10)
{
}

/*****************************************************************************/
/*!
\brief
  Parameterized Constructor. The Phonet will be generated during the
  object creation. The Phonet will begin with a min length of 2 and a max length
  of ten.

\param phonemes
  The vector of phonemes that will be used to generate a random phonet.
\param min_length
  The minimum length the Phonet could have when generated.
\param max_length
  The maximum length the Phonet could have when generated.
*/
/*****************************************************************************/
Phonet::Phonet(const PhonemePool & pool,
               const size_t min_length, const size_t max_length):
m_min_length(min_length),
m_max_length(max_length)
{
  generate(pool);
}

/*****************************************************************************/
/*!
\brief
  Parameterized constructor. Given a vector of Phonemes, a Phonet object will
  be created. The min and max lengths of the Phonet will be the size of the
  Phoneme vector.

\param phonemes
  The vector of strings containing the phonemes the Phonet will be initialized
  with.
*/
/*****************************************************************************/

Phonet::Phonet(const std::vector<const Phoneme *> & phonemes):
m_min_length(phonemes.size()),
m_max_length(phonemes.size())
{
  m_phonemes = phonemes;
}

/*****************************************************************************/
/*!
\brief
  Empty Phonet destructor.
*/
/*****************************************************************************/
Phonet::~Phonet()
{}

/*****************************************************************************/
/*!
\brief
  Given a vector of all the existing phonemes being used, a randomized
  phonet will be generated.
*/
/*****************************************************************************/

void Phonet::generate(const PhonemePool & pool)
{
  m_phonemes.clear();
  size_t length = (rand() % (m_max_length - m_min_length + 1)) + m_min_length;
  // picking first phoneme
  if(length > 0)
  {
    m_phonemes.push_back(pool.get_phoneme());
    --length;
  }
  else
    return;
  // picking remaining phonemes
  while(length)
  {
    const Phoneme * next_phoneme = m_phonemes.back()->get_following_phoneme();
    // make sure that the phoneme has at least one following phoneme
    if(!next_phoneme)
    {
      length = 0;
    }
    else
    {
      m_phonemes.push_back(m_phonemes.back()->get_following_phoneme());
      --length;
    }
  }
}

/*****************************************************************************/
/*!
\brief
  Prints out the Phonemes in the constructed Phonet to console.
*/
/*****************************************************************************/
void Phonet::print_phonet() const
{
  std::vector<const Phoneme *>::const_iterator it = m_phonemes.begin();
  std::vector<const Phoneme *>::const_iterator it_e = m_phonemes.end();
  if(it == it_e)
    return;
  std::cout << *(*it);
  while(it != it_e)
  {
    ++it;
    // skipping colon print
    if(it == it_e)
      break;
    std::cout << ":" << *(*it);
  }
}

/*****************************************************************************/
/*!
\brief
  Prints out an example of how the Phonet is supposed to be pronounced to
  console. The example will consist of multiple words printed in the correct
  order. Each word will consist of one Phoneme that is in the word generated.
*/
/*****************************************************************************/
void Phonet::print_pronunciation() const
{
  std::vector<const Phoneme *>::const_iterator it = m_phonemes.begin();
  std::vector<const Phoneme *>::const_iterator it_e = m_phonemes.end();
  if(it == it_e)
    return;
  (**it).print_pronunciation();
  while(it != it_e)
  {
    ++it;
    if(it == it_e)
      break;
    std::cout << " : ";
    (**it).print_pronunciation();
  }
}

/*****************************************************************************/
/*!
\brief
  Prints a possible random spelling for the Phonet.
*/
/*****************************************************************************/
void Phonet::print_spelling() const
{
  std::vector<const Phoneme *>::const_iterator it = m_phonemes.begin();
  std::vector<const Phoneme *>::const_iterator it_e = m_phonemes.end();
  for(; it != it_e; ++it)
    (**it).print_spelling();
}

/*****************************************************************************/
/*!
\brief
  Overloads the output operator to print a Phonet to console. Only the Phonet
  itself will be printed, not the pronunciation or suggested spellings.

\param os
  The ostream the phonet will be sent to.
\param rhs
  The Phonet that is being sent to the ostream.

\return The ostream the Phonet was sent to.
*/
/*****************************************************************************/
std::ostream & operator<<(std::ostream & os, const Phonet & rhs)
{
  rhs.print_phonet();
  return os;
}

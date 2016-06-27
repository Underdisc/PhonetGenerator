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
    - print

\par Functions Undergoing Improvement
    - generate

\par Future Functions
    - spelling: will suggest a spelling for the Phonet.
*/
/*****************************************************************************/

#include "../header/Phonet.h" // Phonet:c

/*****************************************************************************/
/*!
\brief
  Defualt constructor for the Phonet. m_phonet(0), m_min_length(2),
  m_max_length(10)
*/
/*****************************************************************************/
Phonet::Phonet() : m_phonet(0), m_min_length(2), m_max_length(10)
{

}

/*****************************************************************************/
/*!
\brief
  Parameterized Constructor. The Phonet will be generated during the
  object creation. m_min_length(2), m_max_length(10)

\param consonants
  A reference to the vector of consonants being used for the Phonet.
\param vowels
  A reference to the vector of vowels being used for the Phonet.
\param seed
  The seed being used for the generator.
*/
/*****************************************************************************/
Phonet::Phonet(std::vector<std::string> & consonants,
               std::vector<std::string> & vowels,
               unsigned seed):
m_min_length(2),
m_max_length(10)
{
  generate(consonants, vowels, seed);
}

/*****************************************************************************/
/*!
\brief
  Parameterized constructor. Given a vector of strings containing phonemes, a
  Phonet object will be created. m_min_length(phonemes.size()),
  m_max_length(phonemes.size())

\param phonemes
  The vector of strings containing the phonemes the Phonet will be initialized
  with.
*/
/*****************************************************************************/

Phonet::Phonet(std::vector<std::string> & phonemes):
m_min_length(phonemes.size()),
m_max_length(phonemes.size())
{
  m_phonet = phonemes;
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
  Given a vector of both consonant and vowel phonemes and a seed, a randomized
  phonet will be generated with the rules of the English phonetic alphabet.
  This is currently pretty screwy.

\param consonants
  The Vector of consonants being used for the generation.
\param vowels
  The vector of vowels being used for the gneneration.
\param seed
  The seed used for the random number generator.
*/
/*****************************************************************************/

void Phonet::generate(std::vector<std::string> & consonants,
                      std::vector<std::string> & vowels,
                      unsigned seed)
{
  srand(seed);
  m_phonet.clear();

  unsigned length = (rand() % (m_max_length - m_min_length + 1)) + m_min_length;
  Phoneme_Type type = static_cast<Phoneme_Type>(rand() % 2);

  while(length)
  {
    if(type)
    {
      unsigned vowel_index = rand() % vowels.size();
      m_phonet.push_back(vowels[vowel_index]);
      type = static_cast<Phoneme_Type>(0);

    }
    else
    {
      unsigned consonant_index = rand() % consonants.size();
      m_phonet.push_back(consonants[consonant_index]);
      type = static_cast<Phoneme_Type>(1);
    }
    --length;
  }
}

/*****************************************************************************/
/*!
\brief
  Prints out the constructed Phonet to console.
*/
/*****************************************************************************/
void Phonet::print()
{
  std::vector<std::string>::iterator phoneme;
  phoneme = m_phonet.begin();
  std::cout << *phoneme;
  while(phoneme != m_phonet.end())
  {
    std::cout << ":" << *phoneme;
    ++phoneme;
  }
  std::cout << std::endl;
}

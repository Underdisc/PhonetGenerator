/*****************************************************************************/
/*!
\file Phoneme.cpp
\author Connor Deakin
\par E-mail: connortdeakin\@gmail.com
\par Project: PhonetGenerator
\date 06/07/2016
\brief
  Contains the implementation of the Phoneme class. Details on the Phoneme's
  purpost can be found in the Phoneme class within the Phoneme header file.

\par
    Functions Include:
    - Parameterized Constructor
    - Copy Constructor
    - Destructor
    - print_phoneme
    - print_example
    - operator=
    - operator<<
*/
/*****************************************************************************/

#include "../header/Phoneme.h" // Phoneme:c

#include <iostream> // cout

/*****************************************************************************/
/*!
\brief
  Parameterized Constructor for a Phoneme.

\param phoneme
  A standard string containing the phoneme.
\param example
  A standard string containing an example of the phoneme in use.
*/
/*****************************************************************************/
Phoneme::Phoneme(const std::string & phoneme, const std::string & example)
: m_phoneme(phoneme), m_example(example)
{
}

/*****************************************************************************/
/*!
\brief
  Copy constructor for the Phoneme class.

\param other
  The other Phoneme being used to create this Phoneme.
*/
/*****************************************************************************/
Phoneme::Phoneme(const Phoneme & other)
: m_phoneme(other.m_phoneme), m_example(other.m_example)
{
}

/*****************************************************************************/
/*!
\brief
  Destructor for the Phoneme.
*/
/*****************************************************************************/
Phoneme::~Phoneme()
{
}

/*****************************************************************************/
/*!
\brief
  Prints the phoneme string to console.
*/
/*****************************************************************************/
void Phoneme::print_phoneme()
{
  std::cout << m_phoneme;
}

/*****************************************************************************/
/*!
\brief
  Prints the example of how the phoneme is used to console.
*/
/*****************************************************************************/
void Phoneme::print_example()
{
  std::cout << m_example;
}

/*****************************************************************************/
/*!
\brief
  Overloads the '=' operator in order to allow phonemes to be set equal to
  eachother.

\param rhs
  The Phoneme that this Phoneme is being set equal to.

\return A reference to the phoneme on the left side of the operator.
*/
/*****************************************************************************/
Phoneme & Phoneme::operator=(const Phoneme & rhs)
{
  if(this != &rhs)
  {
    m_phoneme = rhs.m_phoneme;
    m_example = rhs.m_example;
  }
  return *this;
}

/*****************************************************************************/
/*!
\brief
  Overloads the '<<' so Phonemes can be printed using the operator. This will
  only print the phoneme string and nothing else.

\param os
  The ostream that the phoneme is being sent to (lhs).

\param rhs
  The Phoneme that is being sent to the ostream.

\return The ostream the phoneme was sent to.
*/
/*****************************************************************************/
std::ostream & operator<<(std::ostream & os, const Phoneme & rhs)
{
  os << rhs.m_phoneme;
  return os;
}

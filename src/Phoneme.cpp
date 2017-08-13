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
    - print_pronunciation
    - print_spelling
    - operator=
    - operator<<
*/
/*****************************************************************************/

#include "../header/Phoneme.h" // Phoneme:c

#include <cstdlib>  // rand
#include <iostream> // cout

/*****************************************************************************/
/*!
\brief
  Default constructor for the Phoneme object. Both strings within the Phoneme
  object are constructed as empty strings.
*/
/*****************************************************************************/
Phoneme::Phoneme(): m_phoneme(), m_example(), m_spellings(), m_rules()
{
}

/*****************************************************************************/
/*!
\brief
  Parameterized Constructor for a Phoneme.

\param phoneme
  A standard string containing the phoneme.
\param example
  A standard string containing an example of the phoneme in use.
\param spellings
  A vector a strings which contain possible spellings for the Phoneme.
*/
/*****************************************************************************/
Phoneme::Phoneme(const std::string & phoneme, const std::string & example,
                 const std::string & spellings)
: m_phoneme(phoneme), m_example(example), m_spellings(), m_rules()
{
  // parsing the spellings string
  size_t start = 0;
  size_t end = 0;
  end = spellings.find((char)',', start);
  if(spellings.size() <= 0)
    return;
  while(end != std::string::npos)
  {
    m_spellings.push_back(spellings.substr(start, end - start));
    start = end + 1;
    end = spellings.find((char)',', start);
  }
  m_spellings.push_back(spellings.substr(start, spellings.size() - start));
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
: m_phoneme(other.m_phoneme), m_example(other.m_example),
  m_spellings(other.m_spellings)
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
  Adds a new rule to this phoneme. In other words, the rule added will be a
  phoneme that can come after this phoneme.

\param new_rule
  The new phoneme that is being used as a rule.
*/
/*****************************************************************************/
void Phoneme::add_rule(const Phoneme * new_rule)
{
  m_rules.push_back(new_rule);
}

/*****************************************************************************/
/*!
\brief
  Gets a phoneme that can follow this phoneme.

\return A pointer to the random phoneme that can follow this one.
*/
/*****************************************************************************/
const Phoneme * Phoneme::get_following_phoneme() const
{
  size_t rule_index = rand() % m_rules.size();
  return m_rules[rule_index];
}


/*****************************************************************************/
/*!
\brief
  Prints the phoneme string to console.
*/
/*****************************************************************************/
void Phoneme::print_phoneme() const
{
  std::cout << m_phoneme;
}

/*****************************************************************************/
/*!
\brief
  Prints the example of how the phoneme is used to console.
*/
/*****************************************************************************/
void Phoneme::print_pronunciation() const
{
  std::cout << m_example;
}

/*****************************************************************************/
/*!
\brief
  Prints one of the multiple spellings the Phoneme can have.
*/
/*****************************************************************************/
void Phoneme::print_spelling() const
{
  std::cout <<  m_spellings.at(rand() % m_spellings.size());
}

/*****************************************************************************/
/*!
\brief
  Tests for equality between a phoneme and a string that contains a phoneme.
  Just an explicit string comparison.

\param phoneme
  The phoneme string that will be checked for equality with this phoneme.


\return If the string represents this phoneme, true.
*/
/*****************************************************************************/
bool Phoneme::operator==(const std::string & phoneme) const
{
  if(m_phoneme.size() != phoneme.size())
    return false;
  unsigned index = 0;
  while(m_phoneme[index] == phoneme[index]){
    ++index;
    if(m_phoneme.size() == index)
      return true;
  }
  return false;
}


/*****************************************************************************/
/*!
\brief
  Prints out all of the phonemes that can follow this phoneme. Not very useful
  except for debugging.
*/
/*****************************************************************************/
void Phoneme::print_rules() const
{
  size_t num_rules = m_rules.size();
  for(size_t cur_rule = 0; cur_rule < num_rules; ++cur_rule)
  {
    m_rules[cur_rule]->print_phoneme();
    std::cout << std::endl;
  }
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
    m_spellings = rhs.m_spellings;
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





#include "../header/Phonet.h" // Phonet:c

Phonet::Phonet() : m_phonet(0), m_min_length(2), m_max_length(10)
{

}

Phonet::Phonet(std::vector<std::string> & consonants,
               std::vector<std::string> & vowels,
               unsigned seed)
{
  generate(consonants, vowels, seed);
}




Phonet::Phonet(std::vector<std::string> & phonemes)
{
  m_phonet = phonemes;
}

Phonet::~Phonet()
{}


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

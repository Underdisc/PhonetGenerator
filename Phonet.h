
///////////////////////////////////////////////////////////////////////////////
#ifndef Phonet_H
#define Phonet_H
///////////////////////////////////////////////////////////////////////////////


#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

class Phonet
{
  public:
    Phonet();
    Phonet(std::vector<std::string> &, std::vector<std::string> &, unsigned);
    Phonet(std::vector<std::string> &);
    ~Phonet();
    // add suggested spellings
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

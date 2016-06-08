

#include <fstream>
#include <vector>
#include <string>
#include <ctime>

#include "Phonet.h"

void get_phonemes(std::vector<std::string> & phonemes, const char * file_name)
{
  std::ifstream file(file_name);
  if(!file.is_open())
    std::cout << "File Not Opened" << std::endl;
  else
  {
    while(!file.eof())
    {
      std::string phoneme;
      std::getline(file, phoneme);
      phonemes.push_back(phoneme);
    }
  }
}

int main(int argc, char ** argv)
{
  std::vector<std::string> consonants;
  std::vector<std::string> vowels;
  get_phonemes(consonants, "consonants.txt");
  get_phonemes(vowels, "vowels.txt");


  Phonet phonet;
  phonet.print();
  phonet.generate(consonants, vowels, (unsigned)time(0));
  phonet.print();

  return 0;
}

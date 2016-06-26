

#include <fstream> // ifstream
#include <vector>  // vector:c
#include <string>  // string:c
#include <ctime>   // time

#include "../header/Phonet.h"

void read_file(std::vector<std::string> & vector, const char * file_name)
{
  std::ifstream file(file_name);
  if(!file.is_open())
    std::cout << "File [" << file_name << "] Not Opened" << std::endl;
  else
  {
    std::string line;
    std::getline(file, line);
    while(!file.eof())
    {
      vector.push_back(line);
      std::getline(file, line);
    }
  }
}

int main(int argc, char ** argv)
{
  std::vector<std::string> phoneme_consonant;
  std::vector<std::string> phoneme_vowel;
  std::vector<std::string> pronunciation_consonant;
  std::vector<std::string> pronunciation_vowel;

  read_file(phoneme_consonant, "../data/phoneme/consonant.txt");
  read_file(phoneme_vowel, "../data/phoneme/vowel.txt");
  read_file(pronunciation_consonant, "../data/pronunciation/consonant.txt");
  read_file(pronunciation_vowel, "../data/pronunciation/vowel.txt");

  Phonet phonet;
  phonet.generate(phoneme_consonant, phoneme_vowel, (unsigned)time(0));
  phonet.print();

  return 0;
}

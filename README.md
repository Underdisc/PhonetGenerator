# Phonet Genertor

**Compile and Run**
```
mkdir build
cd build
cmake ../
make
```

All current documentation can be found in documentation/html/index.html

Will generate words for you based off of the rules of the *English Phonetic Alphabet* rather than just the *English Alphabet*. That's the goal. It generates phonetic versions of words currently, but it is not currently using the rules of the phonetic alphabet. Going to get on that soon.

Planned Features:
- Generate suggested spellings.
- Options for choosing what the program does.
- More robust generation system in order to use any phonetic alphabet.

**Current Version: 0.7**

Version List
- Basic implementation versions
- **0.7** - Contains a very basic generation method. The method used in this version switches back and forth between vowel and consonant phonemes. This version generates interesting phonets, however, it does not have an option interface.

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
- Options for choosing what the program does. **0.9**
- More robust generation system in order to use any phonetic alphabet. **1.0**

**Current Version: 0.8**

Version List
- Basic implementation versions
- 0.7 - Contains a very basic generation method. The method used in this version switches back and forth between vowel and consonant phonemes. This version generates interesting phonets, however, it does not have an option interface
- **0.8** - Suggests a single spelling for any Phonet generated.

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

##### Options
- --maximum-length [number or -n [number]: Decide the minimum number of phonemes in a phonet.
- --maximum-length [number] or -x [number]: Decide the maximum number of phonemes in a phonet.
- --words [number] or -w [number]: Decide the number of phonets that are generated.
- --spellings [number] or -s [number]: Decide the number of suggested spellings that generated for each generated phonet.
- --pronunciation or -p: Print the pronunciation of the phonet.
- --seed [number] or -r [number]: Provide the seed used for the randomization. If a seed is not provided, the time is used as the alternative.
- --help or -h: Print this.

Planned Features:
- More robust generation system in order to use any phonetic alphabet. **1.0**

**Current Version: 0.93**

Version List
- Basic implementation versions
- 0.70 - Contains a very basic generation method. The method used in this version switches back and forth between vowel and consonant phonemes. This version generates interesting phonets, however, it does not have an option interface
- 0.80 - Suggests a single spelling for any Phonet generated.
- 0.90 - Added an options interface for the PhonetGenerator.
- 0.91 - Added more options and organized the output.
- 0.92 - Added a help option.
- **0.93** - Added long options.

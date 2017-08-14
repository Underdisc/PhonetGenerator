# Phonet Genertor
*A Multilingual Word Generator*

This is a program that uses *Phonetics* to generate randomized words. Instead of using syllables or just characters like other generators, this generator makes words by shoving sounds together that exist within a language. For example, in English, there are 44 different sounds that speakers will make. Using just these 44 sounds, you can say any word in the language.

At first, this generator could only generate words for the English language, but it is now able to generate words for almost any language. It might not be possible for certain languages due to my own lack of knowledge, but producing words for Romantic and Germanic languages should be possible if there are configuration files for the language.

*If there isn't a configuration file for the language you are looking for, feel free to contribute and add a configuration. A tutorial on how to create and use the configuration files is located at the bottom of this page.*

## Running

You can either build it from source or check the release folder. Each of the zips in the release folder contain the configuration files needed to run the program.

If you want to build from source, do this from the root of the repository.
I am using version 3.6.2 of cmake.

```
mkdir build
cd build
cmake ../
make
```

Alternatively, since this project is very small.

```
mkdir build
cd build
g++ ../src/main.cpp ../src/Options.cpp ../src/Phoneme.cpp ../src/PhonemePool.cpp ../src/Phonet.cpp ../src/utility.cpp -o ptgen.exe
```

After that, just make sure that the config directory is located in the same directory as the program before running it.

## Options
- --maximum-length [number or -n [number]: Decide the minimum number of phonemes in a phonet.
- --maximum-length [number] or -x [number]: Decide the maximum number of phonemes in a phonet.
- --words [number] or -w [number]: Decide the number of phonets that are generated.
- --spellings [number] or -s [number]: Decide the number of suggested spellings that generated for each generated phonet.
- --pronunciation or -p: Print the pronunciation of the phonet.
- --seed [number] or -r [number]: Provide the seed used for the randomization. If a seed is not provided, the time is used as the alternative.
- --file [path] or - f [path]: Choose the phoneme file that will be used for the phoneme data used by the generator.
- --help or -h: Print this.

## Versions
**Current Version: 1.0**

Version List
- Basic implementation versions
- 0.70 - Contains a very basic generation method. The method used in this version switches back and forth between vowel and consonant phonemes. This version generates interesting phonets, however, it does not have an option interface
- 0.80 - Suggests a single spelling for any Phonet generated.
- 0.90 - Added an options interface for the PhonetGenerator.
- 0.91 - Added more options and organized the output.
- 0.92 - Added a help option.
- 0.93 - Added long options.
- **1.0** - Added rules.

## How to Create Configuration Files
This process should be very easy, but it might take some time to make a full configuration file. To start, have a look at these two lines.

```
s:<s>un:s,se,ss,c,ce,sc:a,e,i,o,u,ā,ē,ī,ō,ū,oo,ōō,ow,oy,ar,ār,ir,or,ur,l,w
t:<t>op:t,tt,ed:a,e,i,o,u,ā,ē,ī,ō,ū,oo,ōō,ow,oy,ar,ār,ir,or,ur
```

These two are found in `release/config/english_default.phoneme` on lines 13 and 14. If you open the file, you will notice that every line has the same structure. We'll take a look at line 13, the first of the two above.

Each line is split into four different sections that are separated with a colon `:`.

1. The identifier for the phoneme.
2. An example where the phoneme is used in a word with the key letters responsible for the sound surrounded in angle brackets.
3. Possible spellings that are used to represent the phoneme.
4. The identifiers of other phonemes that can follow the phoneme being described.

This is what those four sections look like on line 13 for the /s/ phoneme.

1. `s`
2. `<s>un`
3. `s,se,ss,c,ce,sc`
4. `a,e,i,o,u,ā,ē,ī,ō,ū,oo,ōō,ow,oy,ar,ār,ir,or,ur,l,w`

Of these four lines, the most special line is the fourth. These are phonemes that can come after the /s/ phoneme when used in a word. For example, you can have a /s/:/e/ phoneme combination in which /e/ follows /s/ to make a phonet that sounds like the word see. Notice how **e** is the second phoneme in the fourth section for the /s/ phoneme. Also notice how there is no **s** in the fourth section for the /t/ phoneme. An /s/ sound just doesn't make much sense after a /t/ sound.

Besides that, there is nothing else to these files. The order in which you put the phonemes does not matter. These are the most important things.

- Each phoneme takes up and only one line. No more, no less.
- Each of the four sections must be separated by a colon `:`.
- Each delimiter within the sections must be separated by a comma `,`. This does not apply to sections 1 and 2. The identifier and pronunciation sections only take one parameter each.
- No spaces.

Once you have created your file, just use the `--file` or `-f` option to specify the file path when running the program. The program will always use english_default.phoneme unless otherwise specified.

#ifndef __LEXICON_H
#define __LEXICON_H

#include "string"
#include "ostream"
#include <unordered_map>

class Lexicon
{
public:
    Lexicon(const std::string &name);

    static Lexicon FromString(const std::string &name, const std::string &s);

    // Insert new word to lexicon
    void append(const std::string &word, int count = 1);

    // Get the count of a word in the lexicon, returns -1 if not found
    int count(const std::string &word) const;

    // Get the number of different words in the lexicon
    int size() const;

    // Remove word from the lexicon
    void remove(const std::string &word);

    // Save to file
    void save(const std::string &filename) const;

    Lexicon operator+(const Lexicon &other);
    Lexicon operator-(const Lexicon &other);

    friend std::ostream &operator<<(std::ostream &os, const Lexicon &l);

public:
    std::string name;

private:
    std::unordered_map<std::string, int> _counts;
};

#endif
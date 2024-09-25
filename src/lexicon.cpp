#include "lexicon.h"
#include "utilitaire.hpp"
#include "iostream"
#include <fstream>

#include <cstring>

Lexicon::Lexicon(const std::string &name) : name(name)
{
}

Lexicon Lexicon::FromString(const std::string &name, const std::string &s)
{
    Lexicon out(name);

    char *throwAwayString = new char[s.size() + 1](); // +1 for null terminator
    std::strcpy(throwAwayString, s.c_str());

    char *pch;
    const char *ponct = " \",.-“”\r\n\t";

    pch = std::strtok(throwAwayString, ponct);
    while (pch != NULL)
    {
        std::string word(pch);
        toLower(word);
        remove_punctuation(word);
        out.append(word);

        pch = strtok(NULL, ponct);
    }

    delete[] throwAwayString;

    return out;
}

void Lexicon::append(const std::string &word, int count)
{
    if (_counts.find(word) == _counts.end()) // key doesnt already exists
        _counts[word] = count;
    else
        _counts[word] += count;
}

int Lexicon::count(const std::string &word) const
{
    if (_counts.find(word) == _counts.end()) // key doesnt already exists
        return -1;
    else
        return _counts.at(word);
}

int Lexicon::size() const
{
    return _counts.size();
}

void Lexicon::save(const std::string &filename) const
{
    std::ofstream out(filename, std::ofstream::trunc);
    out << *this;
    out.close();
}

void Lexicon::remove(const std::string &word)
{
    // TODO: Should I check if element exists?
    _counts.erase(word);
}

Lexicon Lexicon::operator+(const Lexicon &other)
{
    Lexicon out(name);
    out._counts = _counts;

    for (auto [word, count] : other._counts)
    {
        out.append(word, count);
    }

    return out;
}

Lexicon Lexicon::operator-(const Lexicon &other)
{
    Lexicon out(name);

    for (auto [word, count] : _counts)
    {
        if (other.count(word) == -1)
            out.append(word, count);
    }

    return out;
}

std::ostream &operator<<(std::ostream &os, const Lexicon &l)
{
    os << "==== " << l.name << std::endl; // Header

    for (auto &e : l._counts) // Words
    {
        os << e.first << ": " << e.second << std::endl;
    }

    return os;
}

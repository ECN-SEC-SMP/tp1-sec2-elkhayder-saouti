#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

#include "utilitaire.hpp"

/**
 Lit le fichier dans le chemin d'entrée path et met son contenu sous forme d'une string dans content
 */
void readFileIntoString(const string &path, string &content)
{
    ifstream input_file(path);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    content = string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    input_file.close();
}

/**
 Supprime la ponctuation restante avant ou après un mot sous forme de string
 */

void remove_punctuation(string &word)
{
    for (int i = 0, len = word.size(); i < len; i++)
    {
        // check whether parsing character is punctuation or not
        if (ispunct(word[i]))
        {
            word.erase(i--, 1);
            len = word.size();
        }
    }
}
/**
 Mets la chaine de caractères passée en paramètre en minuscules
 */
void toLower(std::string &s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

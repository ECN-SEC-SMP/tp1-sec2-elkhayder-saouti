#include <iostream>

#include "utilitaire.hpp"
#include "lexicon.h"

int main()
{

    std::string lesMiserablesContent, notreDameDeParisContent;
    readFileIntoString("files/lesMiserables_A.txt", lesMiserablesContent);
    readFileIntoString("files/notreDameDeParis_A.txt", notreDameDeParisContent);

    Lexicon lesMiserables = Lexicon::FromString("Les Miserables", lesMiserablesContent);
    Lexicon notreDameDeParis = Lexicon::FromString("Notre Dame de Paris", notreDameDeParisContent);

    Lexicon diff = lesMiserables - notreDameDeParis;
    Lexicon sum = lesMiserables + notreDameDeParis;

    lesMiserables.save("les_miserables.txt");
    notreDameDeParis.save("notre_dame_de_paris.txt");
    diff.save("diff.txt");
    sum.save("sum.txt");
}
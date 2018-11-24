#ifndef PARSERFILES_H
#define PARSERFILES_H
#include "parser.h"
#include <vector>

using std::vector;
typedef vector<Handler*> Parsers;

class ParserFiles
{

    Parsers _parsers;
public:
    ParserFiles();
    int FindParser(const string type) const;
    Parsers& GetParsers();
    Handler* GetParser(const int i);
    Handler* GetParser(const string type);
};

#endif // PARSERFILES_H

#include "parserfiles.h"

ParserFiles::ParserFiles(){

    _parsers.push_back(new HandlerFBTtoTXT("FBX to TXT", "txt", "Конвертирует из одного формата в другой"));
}

int ParserFiles::FindParser(const string type) const{

    for(int i = 0; i < _parsers.size(); ++i){
        if(_parsers[i]->GetType() == type){
            return i;
        }
    }
    return -1;
}

Parsers& ParserFiles::GetParsers(){

        return _parsers;
}

Handler* ParserFiles::GetParser(const string type){

        return GetParser(FindParser(type));
}

Handler* ParserFiles::GetParser(const int i){

        return _parsers[i];
}

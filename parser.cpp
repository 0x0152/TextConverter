#include "parser.h"

string* HandlerFBTtoTXT::Working(string* text,
                                const string arg) const{
    string* out = new string();

    bool isWrite = false;
    for(auto it = text->begin(); it != text->end(); ++it){
        if(it + 1 == text->end()){
            isWrite = false;
        }

        if(*it == '<'){
            isWrite = false;
        }
        if (*it == '>'){
            isWrite = true;
            continue;
        }

        if(isWrite){
            *out += *it;
        }


    }

    Console::Instance()->AddMessage("Файл обработан", Console::MSG_OK);

    delete text;

    text = out;
    return text;
}

#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "console.h"

using std::string;

class Handler
{
private:
    string _type;
    string _extension;
    string _help;
public:
    Handler(const string type, const string extension, const string help) : _type(type), _extension(extension), _help(help){}
    virtual string GetType() const final{
        return _type;
    }

    virtual string GetExtension() const final{
        return _extension;
    }

    virtual string GetHelp() const final{
        return _help;
    }

    virtual string* Working(string* text,
                            const string arg) const = 0;
};
//---------------Реализация-----------------------------------
class HandlerFBTtoTXT : public Handler{
public:
    HandlerFBTtoTXT(const string type, const string extension, const string help) : Handler(type, extension, help){}

    string* Working(string* text,
                    const string arg) const override;
};

#endif // PARSER_H

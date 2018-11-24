#ifndef CONSOLE_H
#define CONSOLE_H
#include <QTextEdit>
#include <string>

using std::string;

class Console
{
public:
    enum TypeMsg{MSG_INFO = 1, MSG_OK, MSG_ERROR};
private:
    static QTextEdit* _textEdit;
    static Console* _console;
    static int _countOk;
    static int _countError;

    static QString _Color(TypeMsg tm);

    Console();

public:

    static Console* Instance();
    static void Log(); //Выводит кол-во выполненых и не выполненных операций
    static QTextEdit* GetTextEdit();
    static void AddMessage(const QString text, const TypeMsg tm);
    static void Clear();
};

#endif // CONSOLE_H

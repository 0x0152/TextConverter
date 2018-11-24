#include "console.h"

QTextEdit* Console::_textEdit = nullptr;
Console* Console::_console = nullptr;
int Console::_countOk = 0;
int Console::_countError = 0;

Console::Console(){
    _textEdit = new QTextEdit();
}

QString Console::_Color(TypeMsg tm){
    switch (tm){
        case MSG_ERROR:
            _countError++;
            return "<font color = red>";
        break;
        case MSG_INFO:
            return "<font color = blue>";
        break;
        case MSG_OK:
            _countOk++;
            return "<font color = green>";
        break;
    }
}

Console* Console::Instance(){
    if(_console == nullptr){
        _console = new Console();
    }

    return _console;
}

void Console::Log(){
    AddMessage("Успешно выполненных операций: " + QString::number(_countOk) + ", Ошибок: " + QString::number(_countError), MSG_INFO);
    _countOk = 0;
    _countError = 0;
}

QTextEdit* Console::GetTextEdit(){

    return _textEdit;

}

void Console::AddMessage(const QString text,const TypeMsg tm = MSG_INFO){
    QString color =_Color(tm);
    _textEdit->append(color + text);
}


void Console::Clear(){
    _textEdit->clear();
}

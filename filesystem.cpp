#include "filesystem.h"

FileSystem::FileSystem()
{
}

string* FileSystem::OpenFile(const string nameFile){
    string* text = new string;

    ifstream file(nameFile);

    if(!file.is_open()){
        Console::Instance()->AddMessage("Ошибка: Не возможно открыть файл!", Console::MSG_ERROR);
    }

    while (!file.eof()){
        *text += file.get();
    }

    Console::Instance()->AddMessage(string("Файл" + nameFile + " прочитан.").c_str(), Console::MSG_OK);
    file.close();

    return text;
}

void FileSystem::SaveFile(const string nameFile, const string direct, const string& text, const string exstensive){

    string fileName = direct + "/" + _GetNameFile(nameFile)+ "." + exstensive;
    ofstream file(fileName);

    if(!file.is_open()){
        Console::Instance()->AddMessage("Ошибка: Не возможно создать файл!", Console::MSG_ERROR);
    }
    file << text;
    Console::Instance()->AddMessage(string("Файл" + fileName + " удачно записан.").c_str(), Console::MSG_OK);
    file.close();
}

string FileSystem::_GetNameFile(const string file) const{

    string nameFile;
    for(auto it = file.rbegin(); it != file.rend(); ++it){
        if(*it == '/'){
            if(nameFile.length() == 0){
                nameFile = "unknown";
            }

            break;
        }
        nameFile += *it;
    }
    string tmp;
    for(auto it = nameFile.rbegin(); it != nameFile.rend(); ++it){
        tmp += *it;
    }

    return tmp;
}

#ifndef FB2CONVERTER_H
#define FB2CONVERTER_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QListWidget>
#include <QTextEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QLabel>
#include <string>
#include "console.h"
#include "parserfiles.h"
#include "filesystem.h"

using std::string;

class Converter : public QWidget
{
    Q_OBJECT
private:
    QListWidget* _listFilesPath;
    QLineEdit* _pathSaveFolder;
    QLineEdit* _argsHandler;
    QComboBox* _typeHandler;
    QPushButton* _butttonSelectFiles;
    QPushButton* _buttonSelectSaveFolder;
    QPushButton* _buttonConvert;
    QPushButton* _buttonShowHelpHandler;

    QHBoxLayout* _horizontalTopLayout;
    QHBoxLayout* _horizontalMiddleLayout;
    QVBoxLayout* _verticalLayout;

    QFileDialog* _dialogSelectFils;
    QFileDialog* _dialogSelectSaveFolder;

    ParserFiles _handler;

    void _InitHLayout();
    void _InitVLayout();
    void _InitComboBox();
    void _InitFileDialog();
public:
    Converter(QWidget *parent = 0);
    ~Converter();
public slots:
    void SelectFiles(QStringList path); //Получение файлов
    void SelectSaveFolder(QString path); //Получение директории сохранения
    void Conversion(); //Конвертация
    void ShowHelp(); //Показывает справку о обработчике
};

#endif // FB2CONVERTER_H

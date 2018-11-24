#include "converter.h"

Converter::Converter(QWidget *parent) : QWidget(parent)
{
        _listFilesPath = new QListWidget;
        _pathSaveFolder = new QLineEdit;

         _butttonSelectFiles = new QPushButton("...");
         _buttonSelectSaveFolder = new QPushButton("...");
         _buttonConvert = new QPushButton("Конвертация");
         _buttonShowHelpHandler = new QPushButton("Справка");

         _dialogSelectFils = new QFileDialog();
         _dialogSelectSaveFolder = new QFileDialog;

        _typeHandler = new QComboBox();
        _argsHandler = new QLineEdit();

        _InitHLayout();
        _InitVLayout();
        _InitComboBox();
        _InitFileDialog();

        connect(_dialogSelectFils,SIGNAL(filesSelected(QStringList)), SLOT(SelectFiles(QStringList))); //Отпаравляем имена файлов в LineEdit
        connect(_buttonShowHelpHandler, SIGNAL(clicked()), SLOT(ShowHelp()));
        connect(_dialogSelectSaveFolder, SIGNAL(fileSelected(QString)), SLOT(SelectSaveFolder(QString)));
        connect(_buttonConvert, SIGNAL(clicked()), SLOT(Conversion()));
        connect(_butttonSelectFiles, SIGNAL(clicked()), _dialogSelectFils, SLOT(open())); //Связываем кнопку с вызовом диологового окна
        connect(_buttonSelectSaveFolder, SIGNAL(clicked(bool)), _dialogSelectSaveFolder, SLOT(show())); // связываем кнопку с вызовом диологового окна
}

void Converter::_InitHLayout(){
        _horizontalTopLayout = new QHBoxLayout;

        _listFilesPath->setMinimumSize(QSize(300, 25));
        _horizontalTopLayout->addWidget(_listFilesPath, 9);
        _horizontalTopLayout->addWidget(_butttonSelectFiles, 1);

        _horizontalMiddleLayout = new QHBoxLayout;

        _pathSaveFolder->setMinimumSize(QSize(300, 25));
        _horizontalMiddleLayout->addWidget(_pathSaveFolder, 9);
        _horizontalMiddleLayout->addWidget(_buttonSelectSaveFolder, 1);
}

void Converter::_InitVLayout(){
    _verticalLayout = new QVBoxLayout; // Добовляем слои
         _verticalLayout->addWidget(new QLabel("Файлы:"));
         _verticalLayout->addLayout(_horizontalTopLayout);

         _verticalLayout->addWidget(new QLabel("Путь до папки сохранения:"));
         _verticalLayout->addLayout(_horizontalMiddleLayout);

         _verticalLayout->addWidget(new QLabel("Тип конвертации:"));
         _verticalLayout->addWidget(_typeHandler);

         _verticalLayout->addWidget(_buttonShowHelpHandler);

         _verticalLayout->addWidget(new QLabel("Параметры:"));
         _verticalLayout->addWidget(_argsHandler);

         _verticalLayout->addWidget(Console::Instance()->GetTextEdit());

         _verticalLayout->addWidget(_buttonConvert);

         setLayout(_verticalLayout);
}

void Converter::_InitComboBox(){
    int count = _handler.GetParsers().size();
    for(int i = 0; i < count; ++i){
        _typeHandler->addItem(QString(_handler.GetParser(i)->GetType().c_str()));//Проходим по всем парсерам
    }
}

void Converter::_InitFileDialog(){
    _dialogSelectFils->setFileMode(QFileDialog::ExistingFiles); //Создаем диологовое окно выбора файлов
    _dialogSelectSaveFolder->setFileMode(QFileDialog::DirectoryOnly); //Создаем диологовое окно выбора паки сохранения

}

//------------------------------SLOTS---------------------------------------------------

void Converter::SelectFiles(QStringList path){
    _listFilesPath->clear();
    _listFilesPath->addItems(path);
}

void Converter::SelectSaveFolder(QString path){

      _pathSaveFolder->setText(path);
}

void Converter::Conversion(){

  FileSystem files;
  string* text;
  int countFiles = _listFilesPath->count(); //Получить количество фалов
  string directSave = _pathSaveFolder->text().toStdString(); //Получаем путь до папки сохранения

  for(int i = 0; i < countFiles; ++i){ //Цикл пробегает по все файлам

        string nameFiles = _listFilesPath->item(i)->text().toStdString(); //Получаем имя файла
        text = files.OpenFile(nameFiles); //Получаем текст из файла
        Handler* currParser = _handler.GetParser(_typeHandler->currentText().toStdString());//Получаем выбранный обработчик
        text = currParser->Working(text, _argsHandler->text().toStdString());//Передает текст обработчику
        string extension = currParser->GetExtension(); //Получаем расширение выходного файла
        files.SaveFile(nameFiles, directSave, *text, extension);//Сохраняем текст
		
        delete text;
  }
        Console::Instance()->Log(); //Выводим список успешных операций
}

void Converter::ShowHelp(){
    Handler* currParser = _handler.GetParser(_typeHandler->currentText().toStdString());//Получаем выбранный парсер
    QMessageBox* mbHelp = new QMessageBox(); //Создаем диологовое окно
    mbHelp->setText(QString(currParser->GetHelp().c_str())); //Устанавливаем текст
    mbHelp->open(); //Открываем
}

Converter::~Converter()
{

}

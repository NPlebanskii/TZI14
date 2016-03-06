#include "vigenerecode.h"
#include <iostream>
#include <QFile>
#include <QTextStream>

VigenereCode::VigenereCode(const QString &keyWord, const QString &fileName,
                           const QString &alphabet):
    mKeyWord(keyWord),
    mAlphabet(alphabet),
    mFileName(fileName)
{
    if (mAlphabet.isEmpty())
    {
        mAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,;-'";
    }
    getTextFromFile();
}

void VigenereCode::codeTextToFile(const QString &fileName)
{
    QString codedText = "";
    int textSize = mText.size();
    int keyWordSize = mKeyWord.size();
    int alphabetSize = mAlphabet.size();

    for (int i = 0; i < textSize; ++i)
    {
        if (mText.at(i) == QChar('\n') || mText.at(i) == QChar('\r'))
        {
            codedText += mText.at(i);
        }
        else
        {
            // Current index of symbol of keyword
            int keyCurrentIndex = i % keyWordSize;
            // Position of current keyword symbol in mAlphabet
            int keyPosInAlphabet = mAlphabet.indexOf(mKeyWord.at(keyCurrentIndex));
            // Position of current text symbol in mAlphabet
            int symbolPosInAlphabet = mAlphabet.indexOf(mText.at(i));
            // Getting index in mAlphabet of new coded symbol
            int codedSymbolIndex = (keyPosInAlphabet + symbolPosInAlphabet) % alphabetSize;
            codedText += mAlphabet.at(codedSymbolIndex);
        }
    }

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    if (file.isOpen())
    {
        QTextStream stream(&file);
        stream << codedText;
    }
    else
    {
        std::cerr << "Failed to open file '" << file.fileName().toStdString()
                  << "' for writing!" << std::endl;
    }
}

void VigenereCode::decodeTextToFile(const QString &fileName)
{
    QString decodedText = "";
    int textSize = mText.size();
    int keyWordSize = mKeyWord.size();
    int alphabetSize = mAlphabet.size();

    for (int i = 0; i < textSize; ++i)
    {
        if (mText.at(i) == QChar('\n') || mText.at(i) == QChar('\r'))
        {
            decodedText += mText.at(i);
        }
        else
        {
            // Current index of symbol of keyword
            int keyCurrentIndex = i % keyWordSize;
            // Position of current keyword symbol in mAlphabet
            int keyPosInAlphabet = mAlphabet.indexOf(mKeyWord.at(keyCurrentIndex));
            // Position of current text symbol in mAlphabet
            int symbolPosInAlphabet = mAlphabet.indexOf(mText.at(i));
            // Getting index in mAlphabet of new decoded symbol
            int decodedSymbolIndex = (symbolPosInAlphabet - keyPosInAlphabet
                                      + alphabetSize) % alphabetSize;
            decodedText += mAlphabet.at(decodedSymbolIndex);
        }
    }

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    if (file.isOpen())
    {
        QTextStream stream(&file);
        stream << decodedText;
    }
    else
    {
        std::cerr << "Failed to open file '" << file.fileName().toStdString()
                  << "' for writing!" << std::endl;
    }
}

QString VigenereCode::alphabet() const
{
    return mAlphabet;
}

void VigenereCode::setAlphabet(const QString &alphabet)
{
    mAlphabet = alphabet;
}

QString VigenereCode::keyWord() const
{
    return mKeyWord;
}

void VigenereCode::setKeyWord(const QString &keyWord)
{
    mKeyWord = keyWord;
}

QString VigenereCode::fileName() const
{
    return mFileName;
}

void VigenereCode::setFileName(const QString &fileName)
{
    mFileName = fileName;
    getTextFromFile();
}

QString VigenereCode::text() const
{
    return mText;
}

void VigenereCode::getTextFromFile()
{
    if (mFileName.isEmpty())
    {
        return;
    }
    QFile file(mFileName);
    file.open(QIODevice::ReadOnly);
    if (file.isOpen())
    {
        QTextStream stream(&file);
        mText = stream.readAll();
    }
    else
    {
        std::cerr << "Failed to open file '" << file.fileName().toStdString()
                  << "' for reading!" << std::endl;
    }
}


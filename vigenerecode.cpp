#include "vigenerecode.h"

VigenereCode::VigenereCode(const QString &keyWord, const QString &readFile, const QString &writeFile)
{

}

QString VigenereCode::readFileName() const
{
    return mReadFileName;
}

void VigenereCode::setReadFileName(const QString &readFileName)
{
    mReadFileName = readFileName;
}

QString VigenereCode::writeFileName() const
{
    return mWriteFileName;
}

void VigenereCode::setWriteFileName(const QString &writeFileName)
{
    mWriteFileName = writeFileName;
}

void VigenereCode::codeTextToFile()
{

}

void VigenereCode::decodeTextToFile()
{

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


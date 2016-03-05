#ifndef VIGENERECODE_H
#define VIGENERECODE_H

#include <QString>

class VigenereCode
{
public:
    VigenereCode(const QString &keyWord = "", const QString &readFile = "",
                 const QString &writeFile = "");

    QString readFileName() const;
    void setReadFileName(const QString &readFileName);

    QString writeFileName() const;
    void setWriteFileName(const QString &writeFileName);

    void codeTextToFile();
    void decodeTextToFile();

    QString alphabet() const;
    void setAlphabet(const QString &alphabet);

    QString keyWord() const;
    void setKeyWord(const QString &keyWord);

private:
    QString mKeyWord;
    QString mAlphabet;
    QString mReadFileName;
    QString mWriteFileName;
    QString mText;
};

#endif // VIGENERECODE_H

#ifndef VIGENERECODE_H
#define VIGENERECODE_H

#include <QString>

class VigenereCode
{
public:
    VigenereCode(const QString &keyWord = "", const QString &fileName = "",
                 const QString &alphabet = "");

    void codeTextToFile(const QString &fileName);
    void decodeTextToFile(const QString &fileName);

    QString alphabet() const;
    void setAlphabet(const QString &alphabet);

    QString keyWord() const;
    void setKeyWord(const QString &keyWord);

    QString fileName() const;
    void setFileName(const QString &fileName);

    QString text() const;

private:
    void getTextFromFile();

    QString mKeyWord;
    QString mAlphabet;
    QString mFileName;
    QString mText;
};

#endif // VIGENERECODE_H

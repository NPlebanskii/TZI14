#ifndef CEZARDECODER_H
#define CEZARDECODER_H

#include <QString>

class CezarDecoder
{
public:
    CezarDecoder(const QString &fileName = "", const QString &alphabet = "");

    QString fileName() const;
    void setFileName(const QString &fileName);

    QString decodedString() const;

    QString alphabet() const;
    void setAlphabet(const QString &alphabet);

private:
    void processFile();
    void decodeFile(int key);

    QString mFileName;
    QString mDecodedString;
    QString mAlphabet;
};

#endif // CEZARDECODER_H

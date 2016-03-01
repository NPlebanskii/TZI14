#ifndef CEZARDECODER_H
#define CEZARDECODER_H

#include <QString>

class CezarDecoder
{
public:
    CezarDecoder(const QString &fileName = "");

    QString fileName() const;
    void setFileName(const QString &fileName);

    QString decodedString() const;

private:
    void processFile();
    void decodeFile(int key);

    QString mFileName;
    QString mDecodedString;
};

#endif // CEZARDECODER_H

#include "cezardecoder.h"
#include "textstatisticgenerator.h"
#include <QFile>
#include <QTextStream>
#include <iostream>

CezarDecoder::CezarDecoder(const QString &fileName, const QString &alphabet):
    mFileName(fileName),
    mDecodedString(""),
    mAlphabet(alphabet)
{
    if (mAlphabet.isEmpty())
    {
        mAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,;-'";
    }
    processFile();
}

QString CezarDecoder::fileName() const
{
    return mFileName;
}

void CezarDecoder::setFileName(const QString &fileName)
{
    mFileName = fileName;
    processFile();
}

QString CezarDecoder::decodedString() const
{
    return mDecodedString;
}

void CezarDecoder::processFile()
{
    if(mFileName.isEmpty())
    {
        return;
    }

    TextStatisticGenerator tsg(mFileName);
    // Generating symbol statistic from file
    auto statistic = tsg.generateSortedFreqStatistic(1);
    // Getting the most frequent symbol
    QChar space = statistic[0].first.at(0);
    // Assuming, that this symbol is whitespace
    int key = mAlphabet.indexOf(space) - mAlphabet.indexOf(' ');
    std::cout << "cezar key: " << key << std::endl;
    decodeFile(key);
}

void CezarDecoder::decodeFile(int key)
{
    QFile file(mFileName);
    QString data;
    QString decodedData;
    file.open(QIODevice::ReadOnly);
    if (file.isOpen())
    {
        QTextStream stream(&file);
        data = stream.readAll();
    }
    else
    {
        std::cerr << "Failed to open file" << file.fileName().toStdString()
                  << "for reading!" << std::endl;
    }

    for (int i = 0; i < data.size(); ++i)
    {
        QChar symbol = data.at(i);
        if (symbol == '\n' || symbol == '\r')
        {
            decodedData.push_back(symbol);
        }
        else
        {
            int decodedSymbolPos = (mAlphabet.indexOf(symbol) - key) % mAlphabet.size();
            decodedData.push_back(mAlphabet.at(decodedSymbolPos));
        }
    }

    mDecodedString = decodedData;
}
QString CezarDecoder::alphabet() const
{
    return mAlphabet;
}

void CezarDecoder::setAlphabet(const QString &alphabet)
{
    mAlphabet = alphabet;
}

void CezarDecoder::writeDecodedStringToFile(const QString &fileName)
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    if (file.isOpen())
    {
        QTextStream stream(&file);
        stream << mDecodedString;
    }
    else
    {
        std::cerr << "Failed to open file" << file.fileName().toStdString()
                  << "for reading!" << std::endl;
    }
}



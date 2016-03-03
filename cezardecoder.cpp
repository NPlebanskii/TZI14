#include "cezardecoder.h"
#include "textstatisticgenerator.h"
#include <QFile>
#include <QTextStream>
#include <algorithm>
#include <QDebug>

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
    auto statistic = tsg.generateStatistic(1);
    auto statValues = statistic.values();

    // Getting the most frequent symbol
    int maxVal = *std::max_element(statValues.begin(), statValues.end());
    QChar space = statistic.key(maxVal).at(0);
    // Assuming, that this symbol is whitespace
    int key = mAlphabet.indexOf(space) - mAlphabet.indexOf(' ');
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

    std::string dataStr = data.toStdString();
    for (uint i = 0; i < dataStr.size(); ++i)
    {
        QChar symbol = data.at(i);
        qDebug() << "symbol: " << symbol;
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
    qDebug() << decodedData;
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



#include "cezardecoder.h"
#include "textstatisticgenerator.h"
#include <QFile>
#include <QTextStream>
#include <algorithm>
#include <QDebug>

CezarDecoder::CezarDecoder(const QString &fileName):
    mFileName(fileName),
    mDecodedString("")
{
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
    char space = statistic.key(maxVal).at(0).toLatin1();
    // Assuming, that this symbol is whitespace
    int key = space - ' ';
    qDebug() << "space: " << space;
    qDebug() << "key: " << key;
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
    for (int i = 0; i < data.size(); i++)
    {
        char symbol = data[i].toLatin1();
        qDebug() << "data[i].toLatin(): " << data[i].row();
        qDebug() << "symbol: " << symbol;
        decodedData += QString(QChar(symbol - key));
    }
//    std::string dataStr = data.toStdString();
//    for (int i = 0; i < dataStr.size(); i++)
//    {

//    }
    qDebug() << data;
    mDecodedString = decodedData;
}


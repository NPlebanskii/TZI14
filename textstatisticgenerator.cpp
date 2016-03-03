#include "textstatisticgenerator.h"
#include <QTextStream>
#include <QFile>
#include <QHash>

TextStatisticGenerator::TextStatisticGenerator(const QString &fileName) :
    mFileName(fileName)
{
}

QString TextStatisticGenerator::fileName() const
{
    return mFileName;
}

void TextStatisticGenerator::setFileName(const QString &fileName)
{
    mFileName = fileName;
}

ListOfPair TextStatisticGenerator::generateSortedAlphaStatistic(int gram)
{
    ListOfPair rStatisticList = generateStatistic(gram);
    qSort(rStatisticList.begin(), rStatisticList.end(),
          [](const QPair<QString, int> &first,
          const QPair<QString, int> &second)
    {
        bool rIsLess = true;
        if (first.first < second.first)
        {
            rIsLess = false;
        }

        return rIsLess;
    });

    return rStatisticList;
}

ListOfPair TextStatisticGenerator::generateSortedFreqStatistic(int gram)
{
    ListOfPair rStatisticList = generateStatistic(gram);
    qSort(rStatisticList.begin(), rStatisticList.end(),
          [](const QPair<QString, int> &first,
          const QPair<QString, int> &second)
    {
        bool rIsLess = true;
        if (first.second < second.second)
        {
            rIsLess = false;
        }

        return rIsLess;
    });

    return rStatisticList;
}



ListOfPair TextStatisticGenerator::generateStatistic(int gram)
{
    QHash<QString, int> generatedStatistic;

    if (mFileName.isEmpty())
    {
        ListOfPair emptyList;
        return emptyList;
    }

    QFile file(mFileName);
    file.open(QIODevice::ReadOnly);

    // Reading all symbols from file
    if (file.isOpen())
    {
        QTextStream stream(&file);
        QString symbols;
        while (!stream.atEnd())
        {
            symbols = stream.read(gram);
            symbols = symbols.toUpper();
            // Skipping escape-symbols
            if (symbols.contains("\n") || symbols.contains("\r"))
            {
                // If bigram or trigram
                if (gram > 1)
                {
                    stream.seek(stream.pos() - 1);
                }
                continue;
            }
            if (symbols.size() < gram)
            {
                break;
            }
            // Transforming whitespace into underscore in order to see symbol
            if (symbols.contains(" "))
            {
                symbols[symbols.indexOf(" ")] = QChar('_');
            }
            if (generatedStatistic.contains(symbols))
            {
                generatedStatistic[symbols]++;
            }
            else
            {
                generatedStatistic[symbols] = 1;
            }

            if (gram > 1)
            {
                // Moving pointer on one symbol backward
                stream.seek(stream.pos() - 1);
            }
        }
    }

    ListOfPair rGeneratedList;

    foreach(QString key, generatedStatistic.keys())
    {
        QPair<QString, int> pair;
        pair.first = key;
        pair.second = generatedStatistic.value(key);
        rGeneratedList << pair;
    }

    return rGeneratedList;
}

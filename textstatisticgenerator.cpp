#include "textstatisticgenerator.h"
#include <QTextStream>
#include <QFile>

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

QHash<QString, int> TextStatisticGenerator::generateStatistic(int gram)
{
    QHash<QString, int> rGeneratedStatistic;

    if (mFileName.isEmpty())
    {
        return rGeneratedStatistic;
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
            if (rGeneratedStatistic.contains(symbols))
            {
                rGeneratedStatistic[symbols]++;
            }
            else
            {
                rGeneratedStatistic[symbols] = 1;
            }

            if (gram > 1)
            {
                // Moving pointer on one symbol backward
                stream.seek(stream.pos() - 1);
            }
        }
    }

    return rGeneratedStatistic;
}

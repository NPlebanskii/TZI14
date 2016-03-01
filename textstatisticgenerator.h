#ifndef TEXTSTATISTICGENERATOR_H
#define TEXTSTATISTICGENERATOR_H

#include <QHash>
#include <QString>

class TextStatisticGenerator
{
public:
    TextStatisticGenerator(const QString &fileName = "");

    QString fileName() const;
    void setFileName(const QString &fileName);

    QHash<QString, int> generateStatistic(int gram);

private:

    QString mFileName;

};

#endif // TEXTSTATISTICGENERATOR_H

#ifndef TEXTSTATISTICGENERATOR_H
#define TEXTSTATISTICGENERATOR_H

#include <QPair>
#include <QList>
#include <QString>

typedef QList< QPair<QString, int> > ListOfPair;

class TextStatisticGenerator
{
public:
    TextStatisticGenerator(const QString &fileName = "");

    QString fileName() const;
    void setFileName(const QString &fileName);

    /*!
     * \brief generateSortedAlphaStatistic - generates sorted statisitic by alphabet
     * \param gram - specify object of statistic (symbol, bigram, trigram)
     * \return list of generated statistic
     */
    ListOfPair generateSortedAlphaStatistic(int gram);
    /*!
     * \brief generateSortedFreqStatistic - generates sorted statisitic by frequency
     * \param gram - specify object of statistic (symbol, bigram, trigram)
     * \return list of generated statistic
     */
    ListOfPair generateSortedFreqStatistic(int gram);

private:
    ListOfPair generateStatistic(int gram);

    QString mFileName;

};

#endif // TEXTSTATISTICGENERATOR_H

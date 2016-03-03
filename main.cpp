#include <QApplication>
#include "histogramwidget.h"
#include "textstatisticgenerator.h"
#include "cezardecoder.h"
#include <QHash>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    HistogramWidget hwEnglish;
//    hwEnglish.setColumnNumber(30);
//    TextStatisticGenerator tsg;
//    tsg.setFileName("C:\\Users\\student\\Desktop\\site\\proj\\TZI14\\englishText.txt");
//    QHash<QString, int> statistic = tsg.generateStatistic(1);
//    hwEnglish.setData(statistic);
//    hwEnglish.show();

//    HistogramWidget hwUkrainian;
//    tsg.setFileName("C:\\Users\\student\\Desktop\\site\\proj\\TZI14\\ukrainianText.txt");
//    statistic = tsg.generateStatistic(1);
//    hwUkrainian.setColumnNumber(36);
//    hwUkrainian.setData(statistic);
//    hwUkrainian.show();

//    HistogramWidget hwTest;
//    tsg.setFileName("C:\\Users\\student\\Desktop\\site\\proj\\TZI14\\englishText.txt");
//    statistic = tsg.generateStatistic(2);
//    hwTest.setColumnNumber(15);
//    hwTest.setData(statistic);
//    hwTest.show();

//    HistogramWidget hwTest2;
//    tsg.setFileName("C:\\Users\\student\\Desktop\\site\\proj\\TZI14\\englishText.txt");
//    statistic = tsg.generateStatistic(3);
//    hwTest2.setColumnNumber(15);
//    hwTest2.setData(statistic);
//    hwTest2.show();
    CezarDecoder cd("C:\\Users\\student\\Desktop\\site\\proj\\TZI14\\SH_VT18");

    qDebug() << cd.decodedString();

    return a.exec();
}

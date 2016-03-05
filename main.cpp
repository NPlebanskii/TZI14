#include <QApplication>
#include "histogramwidget.h"
#include "textstatisticgenerator.h"
#include "cezardecoder.h"
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString projectPath = "D:\\NazarsProjectsProgramming\\Qt_projects\\TZI_1\\";

    HistogramWidget hwEnglish;
    hwEnglish.setColumnNumber(30);
    TextStatisticGenerator tsg;
    tsg.setFileName(projectPath + "englishText.txt");
    hwEnglish.setData(tsg.generateSortedFreqStatistic(1));
    hwEnglish.show();

    HistogramWidget hwUkrainian;
    tsg.setFileName(projectPath + "ukrainianText.txt");
    hwUkrainian.setData(tsg.generateSortedAlphaStatistic(1));
    hwUkrainian.setColumnNumber(36);
    hwUkrainian.show();

    HistogramWidget hwTest;
    tsg.setFileName(projectPath + "englishText.txt");
    hwTest.setColumnNumber(15);
    hwTest.setData(tsg.generateSortedFreqStatistic(2));
    hwTest.show();

    HistogramWidget hwTest2;
    tsg.setFileName(projectPath + "englishText.txt");
    hwTest2.setColumnNumber(15);
    hwTest2.setData(tsg.generateSortedFreqStatistic(3));
    hwTest2.show();

    CezarDecoder cd(projectPath + "SH_VT18");
    qDebug() << cd.decodedString();

    return a.exec();
}

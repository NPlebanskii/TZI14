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

    HistogramWidget hwEnglishSymbol;
    hwEnglishSymbol.setColumnNumber(30);
    TextStatisticGenerator tsg;
    tsg.setFileName(projectPath + "englishText.txt");
    hwEnglishSymbol.setData(tsg.generateSortedFreqStatistic(1));
    hwEnglishSymbol.setWindowTitle("English text single-symbol statistic");
    hwEnglishSymbol.show();

    HistogramWidget hwUkrainianSymbol;
    tsg.setFileName(projectPath + "ukrainianText.txt");
    hwUkrainianSymbol.setData(tsg.generateSortedFreqStatistic(1));
    hwUkrainianSymbol.setColumnNumber(36);
    hwUkrainianSymbol.setWindowTitle("Ukrainian text single-symbol statistic");
    hwUkrainianSymbol.show();

    HistogramWidget hwEnglishBigram;
    tsg.setFileName(projectPath + "englishText.txt");
    hwEnglishBigram.setColumnNumber(15);
    hwEnglishBigram.setData(tsg.generateSortedFreqStatistic(2));
    hwEnglishBigram.setWindowTitle("English text bigram statistic");
    hwEnglishBigram.show();

    HistogramWidget hwEnglishTrigram;
    tsg.setFileName(projectPath + "englishText.txt");
    hwEnglishTrigram.setColumnNumber(15);
    hwEnglishTrigram.setData(tsg.generateSortedFreqStatistic(3));
    hwEnglishTrigram.setWindowTitle("English text trigram statistic");
    hwEnglishTrigram.show();

    CezarDecoder cd(projectPath + "SH_VT18");
    cd.writeDecodedStringToFile("decodedText");

    return a.exec();
}

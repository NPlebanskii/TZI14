#include <QApplication>
#include "histogramwidget.h"
#include "textstatisticgenerator.h"
#include "cezardecoder.h"
#include "vigenerecode.h"
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* D:\\NazarsProjectsProgramming\\Qt_projects\\TZI_1\\
       D:\\Qt_Projects\\TZI14\\TZI14\\ */
    QString projectPath = "D:\\NazarsProjectsProgramming\\Qt_projects\\TZI_1\\";

//    HistogramWidget hwEnglishSymbol;
//    hwEnglishSymbol.setColumnNumber(32);
    TextStatisticGenerator tsg;
//    tsg.setFileName(projectPath + "englishText.txt");
//    hwEnglishSymbol.setData(tsg.generateSortedFreqStatistic(1));
//    hwEnglishSymbol.setWindowTitle("English text single-symbol statistic"
//                                   ", sorted by frequency");
//    hwEnglishSymbol.show();

//    HistogramWidget hwEnglishSymbolAlphabet;
//    hwEnglishSymbolAlphabet.setColumnNumber(33);
//    tsg.setFileName(projectPath + "englishText.txt");
//    hwEnglishSymbolAlphabet.setData(tsg.generateSortedAlphaStatistic(1));
//    hwEnglishSymbolAlphabet.setWindowTitle("English text single-symbol statistic"
//                                           ", sorted by alphabet");
//    hwEnglishSymbolAlphabet.show();

//    HistogramWidget hwEnglishBigram;
//    tsg.setFileName(projectPath + "englishText.txt");
//    hwEnglishBigram.setColumnNumber(15);
//    hwEnglishBigram.setData(tsg.generateSortedFreqStatistic(2));
//    hwEnglishBigram.setWindowTitle("English text bigram statistic");
//    hwEnglishBigram.show();

//    HistogramWidget hwEnglishTrigram;
//    tsg.setFileName(projectPath + "englishText.txt");
//    hwEnglishTrigram.setColumnNumber(15);
//    hwEnglishTrigram.setData(tsg.generateSortedFreqStatistic(3));
//    hwEnglishTrigram.setWindowTitle("English text trigram statistic");
//    hwEnglishTrigram.show();

    // Getting statistic for coded Cezar text
//    HistogramWidget hwCezarSymbAlpha;
//    tsg.setFileName(projectPath + "SH_VT18");
//    hwCezarSymbAlpha.setColumnNumber(29);
//    hwCezarSymbAlpha.setData(tsg.generateSortedAlphaStatistic(1));
//    hwCezarSymbAlpha.setWindowTitle("Cezar text symbol statistic, sorted by alphabet");
//    hwCezarSymbAlpha.show();

//    HistogramWidget hwCezarSymbFreq;
//    hwCezarSymbFreq.setColumnNumber(29);
//    hwCezarSymbFreq.setData(tsg.generateSortedFreqStatistic(1));
//    hwCezarSymbFreq.setWindowTitle("Cezar text symbol statistic, sorted by frequency");
//    hwCezarSymbFreq.show();

//    HistogramWidget hwCezarBigram;
//    hwCezarBigram.setColumnNumber(15);
//    hwCezarBigram.setData(tsg.generateSortedFreqStatistic(2));
//    hwCezarBigram.setWindowTitle("Cezar text bigram statistic");
//    hwCezarBigram.show();

//    HistogramWidget hwCezarTrigram;
//    hwCezarTrigram.setColumnNumber(15);
//    hwCezarTrigram.setData(tsg.generateSortedFreqStatistic(3));
//    hwCezarTrigram.setWindowTitle("Cezar text trigram statistic");
//    hwCezarTrigram.show();

//    // Decoding Cezar text
//    CezarDecoder cd(projectPath + "SH_VT18");
//    cd.writeDecodedStringToFile(projectPath + "decodedCezarText");

    // Creating statistic for simple change method text
    HistogramWidget hwSimpleChangeSymb;
    tsg.setFileName(projectPath + "S18");
    hwSimpleChangeSymb.setColumnNumber(28);
    hwSimpleChangeSymb.setData(tsg.generateSortedFreqStatistic(1));
    hwSimpleChangeSymb.setWindowTitle("Simple change symbol statistic, sorted by frequency");
    hwSimpleChangeSymb.show();

    HistogramWidget hwSimpleChangeBigram;
    hwSimpleChangeBigram.setColumnNumber(15);
    hwSimpleChangeBigram.setData(tsg.generateSortedFreqStatistic(2));
    hwSimpleChangeBigram.setWindowTitle("Simple change bigram statistic, sorted by frequency");
    hwSimpleChangeBigram.show();

    HistogramWidget hwSimpleChangeTrigram;
    hwSimpleChangeTrigram.setColumnNumber(15);
    hwSimpleChangeTrigram.setData(tsg.generateSortedFreqStatistic(3));
    hwSimpleChangeTrigram.setWindowTitle("Simple change trigram statistic, sorted by frequency");
    hwSimpleChangeTrigram.show();

    VigenereCode vc("NAZARIIPLEBANSKII", projectPath + "decodedCezarText");
    vc.codeTextToFile(projectPath + "codedVigenereText");
    vc.setFileName(projectPath + "codedVigenereText");
    vc.decodeTextToFile(projectPath + "decodedVigenereText");
    return a.exec();
}

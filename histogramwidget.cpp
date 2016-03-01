#include "histogramwidget.h"
#include <QPair>
#include <QHash>
#include <QPaintEvent>
#include <QPainter>
#include <QFont>

HistogramWidget::HistogramWidget(QWidget *parent) :
    QWidget(parent),
    mIsSorted(false),
    mSideOffset(5),
    mTopOffset(30),
    mBottomOffset(30),
    mColumnOffset(3),
    mColumnColor(Qt::yellow),
    mColumnNumber(0)
{
    setGeometry(50, 50, 700, 500);
    setMinimumHeight(500);
    setMinimumWidth(700);
}

QHash<QString, int> *HistogramWidget::data() const
{
    QHash<QString, int> *hash = new QHash<QString, int>();
    for (ListOfPair::const_iterator it = mData.constBegin();
         it != mData.constEnd(); ++it)
    {
        hash->insert(it->first, it->second);
    }
    return hash;
}

void HistogramWidget::setData(const QHash<QString, int> &data)
{
    foreach(QString key, data.keys())
    {
        QPair<QString, int> pair;
        pair.first = key;
        pair.second = data.value(key);
        mData << pair;
    }

    mIsSorted = false;
}

void HistogramWidget::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);

    if(mData.empty())
    {
        return;
    }
    if(!mIsSorted)
    {
        sortData();
    }

    // Count of columns to be drawn
    int count = mColumnNumber;
    // Maximum frequency of elements from mData
    int maxFreq = mData[0].second;
    // Maximum height for column
    int maxHeight = e->rect().height() - mTopOffset - mBottomOffset;
    // Width of single column
    int width = (e->rect().width() - 2 * mSideOffset -
                 (count - 1) * mColumnOffset) / count;

    QPainter painter(this);
    painter.setBrush(mColumnColor);
    QFont font;
    font.setPointSize(10);
    painter.setFont(font);

    ListOfPair::const_iterator i = mData.constBegin();
    int j = 0;
    while (i != mData.constEnd())
    {
        int columnX = mSideOffset + j * (width + mColumnOffset);
        int height = maxHeight * i->second / maxFreq;
        int columnY = mTopOffset + maxHeight - height;
        painter.drawRect(columnX, columnY, width, height);

        painter.setPen(Qt::black);
        int symbolX = mSideOffset + width / 2 + j * (width + mColumnOffset);
        int symbolY = e->rect().height() - mBottomOffset / 4;
        int freqY = e->rect().height() - mBottomOffset - height - mTopOffset / 4;
        painter.drawText(symbolX, symbolY, i->first);
        painter.drawText(symbolX, freqY, QString::number(i->second));
        ++i;
        ++j;
        if (j == mColumnNumber)
        {
            break;
        }
    }
}

void HistogramWidget::sortData()
{
    qSort(mData.begin(), mData.end(),
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

    mIsSorted = true;
}

int HistogramWidget::columnOffset() const
{
    return mColumnOffset;
}

void HistogramWidget::setColumnOffset(int columnOffset)
{
    mColumnOffset = columnOffset;
}

int HistogramWidget::bottomOffset() const
{
    return mBottomOffset;
}

void HistogramWidget::setBottomOffset(int bottomOffset)
{
    mBottomOffset = bottomOffset;
}

int HistogramWidget::topOffset() const
{
    return mTopOffset;
}

void HistogramWidget::setTopOffset(int topOffset)
{
    mTopOffset = topOffset;
}

int HistogramWidget::sideOffset() const
{
    return mSideOffset;
}

void HistogramWidget::setSideOffset(int sideOffset)
{
    mSideOffset = sideOffset;
}

QColor HistogramWidget::columnColor() const
{
    return mColumnColor;
}

void HistogramWidget::setColumnColor(const QColor &columnColor)
{
    mColumnColor = columnColor;
}

int HistogramWidget::columnNumber() const
{
    return mColumnNumber;
}

void HistogramWidget::setColumnNumber(int columnNumber)
{
    mColumnNumber = columnNumber;
}


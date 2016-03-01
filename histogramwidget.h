#ifndef HISTOGRAMWIDGET_H
#define HISTOGRAMWIDGET_H

#include <QWidget>
#include <QList>
#include <QPair>
#include <QColor>
#include <QString>

typedef QList< QPair<QString, int> > ListOfPair;

class HistogramWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HistogramWidget(QWidget *parent = 0);

    QHash<QString, int> *data() const;
    void setData(const QHash<QString, int> &data);

    int columnNumber() const;
    void setColumnNumber(int columnNumber);

    QColor columnColor() const;
    void setColumnColor(const QColor &columnColor);

    int sideOffset() const;
    void setSideOffset(int sideOffset);

    int topOffset() const;
    void setTopOffset(int topOffset);

    int bottomOffset() const;
    void setBottomOffset(int bottomOffset);

    int columnOffset() const;
    void setColumnOffset(int columnOffset);

protected:
    void paintEvent(QPaintEvent *e);

signals:

public slots:

private:
    void sortData();

    bool mIsSorted;
    ListOfPair mData;
    int mSideOffset;
    int mTopOffset;
    int mBottomOffset;
    int mColumnOffset;
    QColor mColumnColor;
    int mColumnNumber;
};

#endif // HISTOGRAMWIDGET_H

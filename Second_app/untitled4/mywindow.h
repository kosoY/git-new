#ifndef MYWINDOW
#define MYWINDOW

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>


class MyWindow : public QDialog
{
        Q_OBJECT
public:
        MyWindow(QWidget *parent=0);
private:
        struct QPair
        {
            QString first;
            int second;
        };

        QPair Array[3];
        int Generator();
        QLabel *mLbl;
        QPushButton *mButStone;
        QPushButton *mButPaper;
        QPushButton *mButScis;
public
slots:
       void ButStoneClicked();
       void ButPaperClicked();
       void ButScissorsClicked();
signals:
void Res();

};
#endif // MYWINDOW


#include "mywindow.h"


MyWindow::MyWindow(QWidget *parent) :QDialog(parent)
{
   mLbl= new QLabel;
   mButStone= new QPushButton("Stone");
   mButStone->setDefault(true);
   mButPaper= new QPushButton("Paper");
   mButScis= new QPushButton("Scissors");
   QHBoxLayout *sublayout = new QHBoxLayout;
   sublayout->addWidget(mButStone);
   sublayout->addWidget(mButPaper);
   sublayout->addWidget(mButScis);
   QVBoxLayout *mainlayout =new QVBoxLayout;
   mainlayout->addWidget(mLbl);
   mainlayout->addLayout(sublayout);
   Array[0].first="Stone";
   Array[0].second=0;
   Array[1].first="Paper";
   Array[1].second=1;
   Array[2].first="Scissors";
   Array[2].second=2;
   connect(mButStone,SIGNAL(clicked(bool)),this,SLOT(ButStoneClicked()));
   connect(mButPaper,SIGNAL(clicked(bool)),this,SLOT(ButPaperClicked()));
   connect(mButScis,SIGNAL(clicked(bool)),this,SLOT(ButScissorsClicked()));
   setLayout(mainlayout);
   setWindowTitle("Mini game");
}

int MyWindow::Generator()
{
    return rand()%3;
}

void MyWindow::ButStoneClicked()
{
 if(abs(Generator()-0)==0)
                mLbl->setText("Draw!");
 if(abs(Generator()-0)==1)
                mLbl->setText("<font color=red>Loooser!</font>");
if(abs(Generator()-0)==2)
                mLbl->setText("<font color=green>You Win!</font>");


}
void MyWindow::ButPaperClicked()
{
    if((Generator()-1)==0)
                   mLbl->setText("Draw!");
    if((Generator()-1)==-1)
                   mLbl->setText("<font color=green>You Win!</font>");
   if((Generator()-1)==1)
                   mLbl->setText("<font color=red>Loooser!</font>");
}
void MyWindow::ButScissorsClicked()
{
    if(abs(Generator()-2)==0)
                   mLbl->setText("Draw!");
    if(abs(Generator()-2)==1)
                   mLbl->setText("<font color=green>You Win!</font>");
   if(abs(Generator()-2)==2)
                   mLbl->setText("<font color=red>Loooser!</font>");
}




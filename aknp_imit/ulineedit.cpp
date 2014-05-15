#include "ulineedit.h"

ULineEdit::ULineEdit(QWidget *parent):QLineEdit(parent){
   
   //  QFont font("Monospace",9);
   //  this->setFont(font);

    this->setFixedHeight(30);

    this->valid = true;
    connect(this,SIGNAL(textChanged(QString)),this,SLOT(slotTextEdit(QString)));

}

void ULineEdit::slotTextEdit(QString str){

    bool ok;
    int pos = this->cursorPosition();
    this->setText(str);
    float value = str.toFloat(&ok);
   
    this->setCursorPosition(pos);

    if (ok && (min<= value) && (value <= max)){
        this->setStyleSheet("background-color: white");
        this->valid = true;
    }

    else{
        this->setStyleSheet("background-color: pink");
        this->valid= false;
    }
    
}

float ULineEdit::value(){
  
  float data;
  data = this->text().toFloat();

  return data;  
}


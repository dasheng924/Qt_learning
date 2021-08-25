#include "smallwidget.h"



SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{

    //创建布局对象
    QHBoxLayout * hlayout = new QHBoxLayout;

    //将控件添加到布局中
    slider = new QSlider(Qt::Horizontal,this);
    spinBox = new QSpinBox(this);
    hlayout->addWidget(slider);
    hlayout->addWidget(spinBox);

    this->setLayout(hlayout);

    //控件的初始化
    slider->setRange(0,100);
    slider->setValue(0);
    slider->setTickPosition(QSlider::TicksBothSides);
    slider->setTickInterval(1);

    spinBox->setRange(0,100);
    spinBox->setValue(0);
    spinBox->setPrefix("第");
    spinBox->setSuffix("个");
    spinBox->setSingleStep(1);//默认步长为 1

    QObject::connect(slider,&QSlider::valueChanged,this,[=](int i){
        spinBox->setValue(i);
    });
    QObject::connect(spinBox,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,[=](int i){
        slider->setValue(i);
    });








}

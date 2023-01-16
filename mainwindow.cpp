#include "mainwindow.h"
#include "ui_mainwindow.h"
//-------
extern uint8_t CompAnt_rez;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
    //---init system timer
    timer = new QTimer();
    timer->setTimerType(Qt::PreciseTimer);
    connect(timer, SIGNAL(timeout()),this, SLOT(slotTimerAlarm()));
    timer->start(TICK_timer);
    //--------------------------
     disp   = new DispL410();//for control

}


MainWindow::~MainWindow()
{
    delete ui                ;
    delete disp              ;
}

void MainWindow::slotTimerAlarm()
{
    disp->Manager();
    if(countForPrint++ > 50) // 5
    {
          countForPrint=0;
          Print_manager();
    }
}
void  MainWindow:: Print_manager       ()
{
//Recv
//ui->text_3->setText("Период приема AHRS_STATUS: " + QString::number(disp->RecvPNS->m_tim->_FrameOne)+ " мс");
//ui->text_7->setText("Счетчик приемов = " + QString::number(disp->RecvPNS->countRecv));


//Send
ui->text_0->setText("Период таймера базовый: " + QString::number(disp->pFrameTimeAlarm->_FrameOne)+ " мс");

//ui->label->setText(QString::number(CompAnt_rez));

ui->label_2->setText("Send to АРК: " + QString::number(disp->cointToNet[0]));
ui->label_3->setText("Send to РСБН: " + QString::number(disp->cointToNet[1]));
ui->label_4->setText("Send ID false: " + QString::number(disp->cointToNet[2]));
//ui->label_5->setText("Update от РСБН: " + QString::number(disp->cointUpdateRecv[1]));
//float    delta_pitch                                                    // смещения тангажа, градусы
//float    delta_roll                                                       // смещения крена, градусы
//uint16_t snsStatus                  // данные от СНС, 1 - приходят, 0 - давно не было или не валидны
//uint16_t courseStatus   // Определение курсового угла по данным СНС: 1 - завершено; 0 – не завершено
//uint8_t  ready                  // выставка, 2 - БКВ готова, 1 - идет выставка, 0 - выставки не было
//float    timeToReady                   // время до окончания выставки в секундах (если идет выставка)
//float    totalTime                            // общее время, на которое запущена выставка в секундах
//uint8_t  snsCorrection                     // коррекция по СНС, 1 - выполняется, 0 - не выполняется
//===========================================================================================================
//ui->text_4-> setText("float delta_pitch;                                                    // смещения тангажа, градусы    = " + QString::number(fromBKV_PNS.delta_pitch  ) );
//ui->text_5-> setText("float delta_roll;                                                       // смещения крена, градусы    = " + QString::number(fromBKV_PNS.delta_roll   ) );
//ui->text_12->setText("uint16_t snsStatus;               // данные от СНС, 1 - приходят, 0 - давно не было или не валидны    = " + QString::number(fromBKV_PNS.snsStatus    ) );
//ui->text_15->setText("uint16_t courseStatus; // Определение курсового угла по данным СНС: 1 - завершено; 0 – не завершено   = " + QString::number(fromBKV_PNS.courseStatus ) );
//ui->text_9 ->setText("uint8_t ready;                 // выставка, 2 - БКВ готова, 1 - идет выставка, 0 - выставки не было   = " + QString::number(fromBKV_PNS.ready        ) );
//ui->text_10->setText("float timeToReady;                   // время до окончания выставки в секундах (если идет выставка)   = " + QString::number(fromBKV_PNS.timeToReady  ) );
//ui->text_11->setText("float totalTime;                            // общее время, на которое запущена выставка в секундах   = " + QString::number(fromBKV_PNS.totalTime    ) );
//ui->text_14->setText("uint8_t snsCorrection;                     // коррекция по СНС, 1 - выполняется, 0 - не выполняется   = " + QString::number(fromBKV_PNS.snsCorrection) );

}// Print_manager


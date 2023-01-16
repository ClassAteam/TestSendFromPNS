
//Добавить в файл про:    QT          +=  network

#ifndef UDPSEND_H
#define UDPSEND_H
#include <QObject>
#include <QHostAddress>

//#define CONTROL_TIME  // #ifdef  CONTROL_TIME   #endif//CONTROL_TIME  // TimeClass*  m_timRecv;

#ifdef  CONTROL_TIME
#include "Dispether/utilTimeClassQt.h"
#endif//CONTROL_TIME



#pragma once

class QUdpSocket;

class UdpSend : public  QObject
{
Q_OBJECT
public:
    UdpSend( QHostAddress host );//int sizeFrom,int portIN,
    ~UdpSend();
    void UpdateSendData(void* dataDest , int sizeFrom,int portIN);
#ifdef  CONTROL_TIME
    TimeClass*  m_tim;
#endif//CONTROL_TIME
    int countSend{0};//счетчик посылок
    //int countRecvOne{0};
   // int paketID{0};//идентификатор пакета
private:
    QUdpSocket* m_pUdpSend;

    //int sizeFromTo{0} ;
    //int port{0}    ;
    //bool bBind{0};
    QHostAddress adr ;
    QByteArray baDatagram;
private slots:
    //void slotReceivingData();
};

#endif // UDPRECV_H



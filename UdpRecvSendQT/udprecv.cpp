#include "udprecv.h"
//#include <QSharedMemory>
#include <QtNetwork/QUdpSocket>
//#include <QNetworkProxy>
//#include <QTextCodec>
//UdpRecv::UdpRecv(int size,int portIN, QHostAddress host )
UdpRecv:: UdpRecv(uint8_t DevId_0, uint8_t PackId_0,int size_0,uint8_t DevId_1, uint8_t PackId_1,int size_1, int portIN, QHostAddress host)
{
#ifdef  CONTROL_TIME
    m_tim = new TimeClass("FromIVO    ",200);//for control
#endif//CONTROL_TIME  // TimeClass*  m_timRecv;
   // s2 = socket_in->bind(QHostAddress::LocalHost, 7755);
    m_pUdpRecv = new QUdpSocket();
    //m_pUdpRecv->setProxy(QNetworkProxy::NoProxy);
    NumDatagram=2;
    DevIdRecv_0  = DevId_0;
    DevIdRecv_1  = DevId_1;
    PackIdRecv_0 = PackId_0;
    PackIdRecv_1 = PackId_1;
//    sizeFromTo_0 = size_0;
//    sizeFromTo_1 = size_1 ;
    QByteArray baDatagram;
    baDatagram.resize(size_0);
    baDatagramArray.push_back(baDatagram);
    baDatagram.resize(size_1);
    baDatagramArray.push_back(baDatagram);

    baDatagramRead.resize(MAX_BUF);
    //sizeFromTo = size;
    //baDatagram.resize(size);
    port = portIN;
    adr = host ;
    bBind = m_pUdpRecv->bind(adr, port);
    connect(m_pUdpRecv, SIGNAL(readyRead()),this , SLOT(slotReceivingData()));
}//

UdpRecv::~UdpRecv()
{
   delete  m_pUdpRecv;
#ifdef  CONTROL_TIME
   delete  m_tim ;//for control
#endif//CONTROL_TIME  // Ti
}

void UdpRecv::slotReceivingData()
{
//#ifdef  CONTROL_TIME
//    m_tim ->StartFrame();//for control
//#endif//CONTROL_TIME  // TimeClass*  m_timRecv;

    do {
        //countRecvOne++;//была выборка
        int sizeRec= m_pUdpRecv->pendingDatagramSize() ;
        if(sizeRec == baDatagramArray[0].size()  || sizeRec == baDatagramArray[1].size())
        {
          // baDatagramFrom.resize(sizeFrom);
           //m_pUdpRecv->readDatagram(baDatagramFrom.data(), baDatagramFrom.size(), &adr);
            m_pUdpRecv->readDatagram(baDatagramRead.data(), baDatagramArray[0].size(), &adr);
            if(DevIdRecv_0==baDatagramRead[0] && PackIdRecv_0==baDatagramRead[1])
            {
                  memcpy(baDatagramArray[0].data(), baDatagramRead.data(), baDatagramArray[0].size());
                  countRecv_0++;
            }        
            else if(DevIdRecv_1==baDatagramRead[0] && PackIdRecv_1==baDatagramRead[1])
            {
                  memcpy(baDatagramArray[1].data(), baDatagramRead.data(), baDatagramArray[1].size());
                  countRecv_1++;
            }

        }
    } while(m_pUdpRecv->hasPendingDatagrams());
}
void UdpRecv::UpdateReceivingData(void* dataDest, int Index , int & countRecv )
{
    //if(countRecv%20 )
           // countRecvOne=0;
    memcpy( dataDest, baDatagramArray[Index].data(), baDatagramArray[Index].size() );
    if(Index ==0)
      countRecv= countRecv_0;
    else if(Index ==1)
      countRecv= countRecv_1;
}

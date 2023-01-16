#include "udpsend.h"
//#include <QSharedMemory>
#include <QtNetwork/QUdpSocket>
//#include <QNetworkProxy>
//#include <QTextCodec>
UdpSend::UdpSend( QHostAddress host )//int size,int portIN,
{
#ifdef  CONTROL_TIME
    m_tim = new TimeClass("FromIVO    ",200);//for control
#endif//CONTROL_TIME  // TimeClass*  m_timRecv;
   // s2 = socket_in->bind(QHostAddress::LocalHost, 7755);
    m_pUdpSend = new QUdpSocket();
    //m_pUdpRecv->setProxy(QNetworkProxy::NoProxy);
//    sizeFromTo = size;
//    baDatagram.resize(size);
//    port = portIN;
    adr = host;

}//

UdpSend::~UdpSend()
{
   delete  m_pUdpSend;
#ifdef  CONTROL_TIME
   delete  m_tim ;//for control
#endif//CONTROL_TIME  // Ti
}


void UdpSend::UpdateSendData(void* dataDest, int size,int portIN)
{
    //if(countRecv%20 )
            //countRecvOne=0;

    countSend++;
    baDatagram.resize(size);
    memcpy(  baDatagram.data(), dataDest,baDatagram.size() );
    m_pUdpSend->writeDatagram(baDatagram, adr, portIN);
}

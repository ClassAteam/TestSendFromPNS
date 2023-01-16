#include <QtNetwork/QUdpSocket>

#include "displ410.h"
#include "defineMat.h"
//=============================
uint8_t DevId_ARK=2;
uint8_t DevId_RSBN=3;
uint8_t PackId_ARK=0;
uint8_t PackId_RSBN=0;

//
//------------ARK

ARC40InModeStruct ARC40InMode; // PackId = 0; Режим работы АРК40
//
//------------RSBN
//

RSBNInContrWordStruct RSBNInContrWord; // PackId = 0; Слово управления
//
//------------BKS

//------------KRA

//------------BSOI
//
//---------------------------
// int rk_status_in	        =10134	;//10  Гц   Приём данных от РК
// int bsap_data_in	        =10601	;//25  Гц   Приём данных от БСАП
// int svs_data_full_in	    =10208	;//10  Гц   Приём управляющих данных СВС
// int operating_time_in	    =10011	;//1   Гц   Приём времени наработки
// int magnetometer_data_in	=10203	;//10  Гц   Приём данных от ММК
// int ahrs_data_in	        =10201	;//25  Гц   Приём даных от БКВ
// int sns_data_in	        =10200	;//5   Гц   Приём данных от СНС
//int arinc_rpkb_in	        =10130	;//50  Гц   Приём данных в ИБКО (ARINC-429)

int arinc_rpkb_out	        =10310	;//50  Гц   Выдача  данных из ИБКО  (ARINC-429)

// int cv_vim95_data_in	    =10801	;//50  Гц   Приём данных VIM-95 (ЦВ ИСУ)
// int cv_dme_data_in	        =10802	;//50  Гц   Приём данных DME (ЦВ ИСУ)
// int cv_svs1_data_in	    =10803	;//50  Гц   Приём данных СВС1 (ЦВ ИСУ)
// int cv_svs2_data_in	    =10804	;//50  Гц   Приём данных СВС2 (ЦВ ИСУ)
// int cv_np101_data_in	    =10808	;//50  Гц   Приём данных НП-101 (ЦВ ИСУ)
////------------------------
//int portSVS_ctrl            =10304  ;//10  Гц    Приём ctrl данных СВС
//int portAHRS_STATUS         = 10223;      //25gh 40ms
//int portSendStat= 10223;
//int portSendBKV= 10201;

bool bZn0, bZn1,bZn2,bZn3,bZn4,bZn5,bZn6,bZn7,bZn8,bZn9,bZn10,
bZn11,bZn12,bZn13,bZn14,bZn15,bZn16,bZn17,bZn18,bZn19,bZn20,
bZn21,bZn22,bZn23,bZn24,bZn25,bZn26,bZn27,bZn28,bZn29,bZn30,
bZn31,bZn32,bZn33,bZn34,bZn35,bZn36,bZn37;


float ControlMinMaxF(float arg,bool & bZn,float  D ,float min,float  max);
//-------
uint8_t CompAnt_rez{0};
//--------------------------------------------------

DispL410::DispL410(QObject *parent) : QObject(parent)
{

//------------TestQHostAddress::LocalHost
     SendTest = new UdpSend(QHostAddress(QHostAddress::Broadcast));//


     pFrameTimeAlarm        = new TimeClass("ToDisp     ",200);//for control

}
//---------------------------------------------------------------------------

DispL410::~DispL410()
{
    delete pFrameTimeAlarm;

    delete SendTest;

}

//void DispL410::ReadIni(void)
//{
//    //path to ini
//   #define STR_IN    64
//   QString strTemp;//("Кириллица");//
//   QString stringI{QDir::currentPath()};
//   const QString stringINI{ stringI + "/SettingsNet.ini"};//{QCoreApplication::applicationDirPath() + "/geocoord.ini"};
//   QSettings settings( stringINI, QSettings::IniFormat );
//   //-------------------------------------------
//   int countN=0;
//   while(1)
//   {
//       QString p;
//       p.setNum(countN);//itoa (i, p, 10);
//       QString grup = "Network_" + p ;//settings.endGroup();
//       settings.beginGroup(grup );
//       strTemp = settings.value("Name","No").toString();
//       if(strTemp =="No")
//       {
//           settings.endGroup();
//           break;
//       }
//       else
//       {
//           int temp= settings.value("portRecv","-1").toInt();
//           if(temp<1023 || temp>65335)
//                portFrom.push_back(-1);
//           else
//                portFrom.push_back(temp);
//           //int y=portFrom[0];
//             temp= settings.value("portSend","-1").toInt();
//             if(temp<1023 || temp>65335)
//                  portTo.push_back(-1);
//             else
//                  portTo.push_back(temp);

//           QString tempAdr = settings.value("SendIP","255.255.255.255").toString();
//           adrToFrom.push_back(QHostAddress(tempAdr));
//       }
//       settings.endGroup();
//       countN++;
//   }//while(1)
//   cointHost=countN;
//}//void DispL410::ReadIni(void)

    //memcpy(ibko,&AVN->IBKO , sizeof(SHMAIN_STRUCT_IN));
    //memcpy(ibko,&AVN->IBKO , sizeof(SHMAIN_STRUCT_IN));
//


//---------------------------------------------------------------------------

void  DispL410::Manager()
{
    //====control time
    pFrameTimeAlarm->StartFrame();
   // timeFromStart+=(unsigned long)(pFrameTimeAlarm->_FrameOne*1000.0);//(ms)

//    uint8_t DevId_ARK=2;
//    uint8_t DevId_RSBN=3;
//    uint8_t PackId_ARK=0;
//    uint8_t PackId_RSBN=0;

    //
    //------------ARK

    ARC40InMode.DevId  = DevId_ARK    ; // PackId = 0; Режим работы АРК40
    ARC40InMode.PackId =  PackId_ARK ;//
    //
    //------------RSBN
    //

    RSBNInContrWord.DevId   =   DevId_RSBN ;
    RSBNInContrWord.PackId  =  PackId_RSBN;
    //-------------------------

    //10gh 100ms
    if(coint_5<5)
          coint_5++;
    else
    {
        coint_5=0;

    }

    //25gh 40ms
    if(coint_2<2)
          coint_2++;
    else
    {
        coint_2=0;
        SendTest->UpdateSendData(&ARC40InMode, sizeof(ARC40InModeStruct) , arinc_rpkb_out);
        cointToNet[0]++;
    }

    //1gh 1000ms
    if(coint_50<50)
          coint_50++;
    else
    {
        coint_50=0;

    }


    //5gh  200ms
    if(coint_10<10)
          coint_10++;
    else
    {
        coint_10=0;
        SendTest->UpdateSendData(&RSBNInContrWord, sizeof(RSBNInContrWordStruct) , arinc_rpkb_out);
        cointToNet[1]++;
    }
//
//------------50 Hz 20 ms
//
    RSBNInContrWord.DevId   =  25;
    SendTest->UpdateSendData(&RSBNInContrWord, sizeof(RSBNInContrWordStruct) , arinc_rpkb_out);
    cointToNet[2]++;
}
//---------------------------------------------------------------------------




float ControlMinMaxF(float arg,bool & bZn,float  D ,float min,float  max)
{
    float rez=0.0;
    if(bZn)
    {
        arg+=D;
        if(arg<max)
        {
            rez=arg;
        }
        else
        {
            rez=max;
            bZn=0;
        }

    }
    else
    {
        arg-=D;
        if(arg>min)
            rez=arg;
        else
        {
            rez=min;
            bZn=1;
        }
    }

    return rez;
}




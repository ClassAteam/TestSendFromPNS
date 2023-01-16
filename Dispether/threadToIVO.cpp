//#define __WIN__

//#ifndef __WIN__   //============================
//#include < unistd.h >
//#else
//#include <windows.h>
////void usleep(__int64 usec)
////{
////    HANDLE timer;
////    LARGE_INTEGER ft;

////    ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

////    timer = CreateWaitableTimer(NULL, TRUE, NULL);
////    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
////    WaitForSingleObject(timer, INFINITE);
////    CloseHandle(timer);
////}

//#endif//===================


//#include <chrono>
//#include <QSharedMemory>
#include "threadToIVO.h"




//=================  ThreadModel
void ThreadToIVO::run ()
{

    //while(!exitThreadModel)
    while(1)
    {
        disp->pFrameToIVO->StartFrame();
        this->usleep(3990);
        //this->usleep(2000);
        //Sleep();
    }

//int a=1+0;
//int b =a;
}//

//===============  INPUT Data
//void IN_aircondition_int()
//{
//    if(pDev->IN_MAT[640])
//        exchange::s1_2151 = static_cast<int>(exchange::s1_2151::avtomat);else
//    if(pDev->IN_MAT[641])
//        exchange::s1_2151 = static_cast<int>(exchange::s1_2151::hol);else
//    if(pDev->IN_MAT[642])
//        exchange::s1_2151 = static_cast<int>(exchange::s1_2151::gor);else
//        exchange::s1_2151 = static_cast<int>(exchange::s1_2151::neytr);

//    exchange::s1_2110 = pDev->IN_MAT[637];
//    exchange::s2_2110 = pDev->IN_MAT[639];

//}

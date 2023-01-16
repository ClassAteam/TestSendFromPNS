#ifndef THREADTOIVO_H
#define THREADTOIVO_H

#include <QThread>
//#include <QMainWindow>
//#include <QTimer>
#include "displ410.h"
//#ifdef  CONTROL_TIME
#include "Dispether/utilTimeClassQt.h"
//#endif//CONTROL_TIME
//========================================model


class ThreadToIVO : public QThread
{
 //Q_OBJECT
public:
    ThreadToIVO(){};
    ~ThreadToIVO(){};

    void run () ;

};


#endif //THREADMODEL_H




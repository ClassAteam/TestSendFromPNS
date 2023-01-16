
#ifndef _utTimer_h
#define _utTimer_h
#include <math.h>
//#include <Windows.h>
#include <QElapsedTimer>
#include <cstring>
class TimeClass //
{

public:
		//TimeClass() {};
        TimeClass(int    iNum);
		TimeClass(const char* name,int    iNum);
		TimeClass(const char* name,double FrameContr,int iNum,int LimProcent);
		//TimeClass(const TimeClass &Time);
        ~TimeClass();
		void   StartNow();//запуск измерения 
		void   StartThen();//конец измерения для N-го измерения, результат в _Frame..... или только в_FrameOne если _iNum=1
		void   StartFrame();//измерение для полных циклов, результат в _Frame.....;		
		void   StartOut(double FrameOne,double FrameContr, int LimProcent);//ф-я измерения от внешнего источника измерений - для подсчета min-max з-ий и счетчиков выхода за процентный диапазон, результат в _Frame.....;	
		
///--------Frame
		double      _FrameOne;//время цикла за 1 проход 
		double      _FrameAll;//общее среднее  время цикла после сброса
		double      _FrameMin;// Min время цикла за все время после сброса
		double      _FrameMax;// Max время цикла за все время после сброса
		double      _FrameN;//среднее время цикла за  N последних проходов 
		double      _FrameMinN;//Min время цикла за N последних циклов
		double      _FrameMaxN;//Max время цикла за N последних циклов
		//int         _NminN;//число процентов минимальных з-ий (менее 110 процента от контрольного з-ия)за N циклов
		//int         _NmaxN;//число процентов минимальных з-ий (менее 110 процента от контрольного з-ия)за N циклов
		int         _LimProcent;//лимит в процентах передается при запуске в целых числах
		double		_ProcentOut;//выход за лимит в процентах 
		double      _FrameContr;//эталонное з-ие ИЗМЕРЕНИЯ ВРЕМЕНИ, передается при запуске в мс

///------------------------------------------------------------------конец Frame
		int         _Prohod;//число проходов
		int         _iNum;//измерения для Frame за N последних циклов, если N=1,производится только одно измерение для _FrameOne
		char        _Name[32];
		//int         _iErrCicFrame;  //кол-во циклов превышающих 500мс для Frame
		void        CleanFrame();
private:
		void        StartQPF();
		int         _countNminN;//счетчик число процентов минимальных з-ий (менее LimProcent процента от контрольного з-ия)за N циклов
		int         _countNmaxN;//счетчик число процентов минимальных з-ий (менее LimProcent процента от контрольного з-ия)за N циклов
		int         _lShetCicl;//счетчик циклов(служебный)
		int         _shet;//счетчик проходов за  N циклов(служебный)
		bool        _bProhod;//(служебный)
		double      _dSumma ;//значение суммарное(служебный)
		double      _dSummaN;//значение суммарное за N циклов(служебный)
		double      _dNum;//обратное число _iNum(служебный)
		double      _FrameLimMin;//контрольное з-ие ИЗМЕРЕНИЯ процентов
		double      _FrameLimMax;//контрольное з-ие ИЗМЕРЕНИЯпроцентов

//        LONGLONG    _lStart;//значение счетчика в момент запуска измерения интервала для 1-го измерения(для Win)
//        static      double      _dQPF; //обратная частота процессора(для Win)
        QElapsedTimer* ptim;

};

class GenerateClass //
{
public:
		//GenerateClass() {};
        GenerateClass(double  Period_0,double  Period_1)
		{
			Period0=fabs(Period_0);
			Period1=fabs(Period_1);
			Summator=0.0;
			ret=0;
		};
       // ~GenerateClass();
		bool GenImpuls(double tik )
		{
		    double  PeriodTek;
			if(ret)  
				 PeriodTek=Period1;
			else
				 PeriodTek=Period0;
           Summator+= tik ;
			if(Summator>=PeriodTek)
			{
				Summator=0.0;
				ret=!ret;
			}

			return ret;
		};


private:
		double  Period0;
		double  Period1;
		double  Summator;
		bool    ret;

};
#endif

extern TimeClass Frame[];
extern GenerateClass Gen[];
//extern TimeClass Frame;
//extern TimeClass FrameS;
//extern TimeClass FrameR;
//extern TimeClass FrameNet;
//===================================================
//-------------------TIME-------------------------------------------------
//TimeClass Frame[]=
//{
//    TimeClass("Frame",16.667,200,25),	               //[0]
//    TimeClass("fromIVO)",LtikIVO,100,20),	           //[1]
//    TimeClass("toPrib",20.0,100,20),               //[2]
//    TimeClass("toFromAdvan",LtikInput,200,10),           //[3]
//    TimeClass("Model",10)      //[4]
//  //  TimeClass("Advan All",200),// [5]
//    //TimeClass("Write DO",200),//  [6]
//    //TimeClass("Frame AI13",200),//[7]
//    //TimeClass("Frame AI15",200),//[8]
//};
//------------------------------------------------------------------------
//  1. Frame[0].StartFrame();
//------------------------------------
//  2. Frame[1].StartNow();
//     		UpdateInput();
//     Frame[1].StartThen();
//
//===================================================

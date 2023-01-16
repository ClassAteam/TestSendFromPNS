//#define _TIME_QT_LIBE
//#ifdef _TIME_QT_LIBE//QT_TIME
//#else
//#endif
#include "utilTimeClassQt.h"



//double TimeClass::_dQPF;


TimeClass::TimeClass(int    iNum)
{
	//if(!_ShetObj)
	_iNum=iNum;
	_dNum=1.0/iNum;
     ptim = new QElapsedTimer();
//	if(!_dQPF)
//	{
//		//_ShetObj++;
//		StartQPF();
//	}
	_bProhod=false;
	CleanFrame();	
};

TimeClass::TimeClass(const char* name,int    iNum)
{
	 strcpy(_Name,name);
	_iNum=iNum;
	_dNum=1.0/iNum;
     ptim = new QElapsedTimer();
//	if(!_dQPF)
//	{
//		//_ShetObj++;
//		StartQPF();
//	}
	_bProhod=false;
	CleanFrame();	
};

TimeClass::TimeClass(const char* name,double FrameContr,int iNum,int LimProcent)
{

	 strcpy(_Name,name);
	_iNum=iNum;
	_FrameContr=FrameContr;
	_LimProcent=LimProcent;
	double kM=_LimProcent*0.01;
    _FrameLimMin=(FrameContr-FrameContr*kM)*0.001;
    _FrameLimMax=(FrameContr+FrameContr*kM)*0.001;

	_dNum=1.0/iNum;
//	if(!_dQPF)
//	{
//		//_ShetObj++;
//		StartQPF();
//	}
     ptim = new QElapsedTimer();
	_bProhod=false;
	CleanFrame();	
};
TimeClass::~TimeClass()
{
  delete ptim;
  ptim  = nullptr;
};

//void TimeClass::StartQPF()
//	{
//		LARGE_INTEGER  qwTicksPerSec;
//		QueryPerformanceFrequency( &qwTicksPerSec );
//		//*adr=(double)qwTicksPerSec.QuadPart;
//		_dQPF=1.0/qwTicksPerSec.QuadPart;
         
//	}

 void   TimeClass::StartNow()
	{
//		LARGE_INTEGER  qwtimeNow;
//        QueryPerformanceCounter( &qwtimeNow );
//        _lStart=qwtimeNow.QuadPart;
     ptim->start();

	}



void  TimeClass::StartThen()
	{
//		LARGE_INTEGER  qwtimeThen;
//		QueryPerformanceCounter( &qwtimeThen);
//		_FrameOne= _dQPF*(qwtimeThen.QuadPart -_lStart );
        _FrameOne=ptim->nsecsElapsed()*0.000001;//mc
		_Prohod++;
		if(_iNum==1)
		    return;
		else
		 _lShetCicl++;

		_dSumma+=_FrameOne;
        _FrameAll=_dSumma/_lShetCicl;
		//определяем макс-мин з-я за ALL циклов
		if (_lShetCicl==1)
		{
				_FrameMax=_FrameMin=_FrameMaxN=_FrameMinN=_FrameOne;
		       _ProcentOut=0.0;// _NminN=_NmaxN =0;//(g_FrameMax<=0.00001) 
		}
		else if(_FrameOne<_FrameMin)     _FrameMin=_FrameOne;
		else if(_FrameOne>_FrameMax)     _FrameMax=_FrameOne;



		
	    if(_shet<_iNum)
		{
	        if(_shet==0)
				_FrameMaxN=_FrameMinN=_FrameOne;
			_dSummaN+=_FrameOne;
			//определяем макс-мин з-я за N циклов
			if(_FrameOne<_FrameMinN)            _FrameMinN=_FrameOne;
		    else if(_FrameOne>_FrameMaxN)       _FrameMaxN=_FrameOne  ;

			//определяем число выходов за контрольное з-ие на 10 процентов
			if(_FrameOne<_FrameLimMin)          _countNminN++;
			else if(_FrameOne>_FrameLimMax)     _countNmaxN++;

			_shet++;
		}else
		{
			/* _NminN= _countNminN;
			 _NmaxN= _countNmaxN;*/
			 double t= _countNmaxN+_countNminN;
			 _ProcentOut=(t/_iNum)*100.0;
			 _FrameN= _dSummaN*_dNum;
			_dSummaN=0.0;
			_shet=0;
			 _countNminN=0;
			 _countNmaxN=0;
		}


	}

void  TimeClass::StartFrame()
{
		_bProhod=!_bProhod;
		if(_bProhod)
			StartNow();
		else
			StartThen();
}

void  TimeClass::CleanFrame()
{
		_lShetCicl=0;
		_FrameMin=0.0;
		_FrameMax=0.0;
		_FrameAll=0.0;
		_FrameN=0.0;
		_FrameMinN=0.0;
		_FrameMaxN=0.0;
		_dSumma=0.0;
		_countNminN=0;
		_countNmaxN=0;
		_dSummaN=0.0;
		_shet=0;
		_ProcentOut=0.0;//_NminN=_NmaxN =0;
}

//ф-я измерения от внешнего источника измерений - для подсчета min-max з-ий и счетчиков выхода за процентный диапазон
void  TimeClass::StartOut(double FrameOne,double FrameContr, int LimProcent    )
	{
		
		_FrameOne= FrameOne;
		_FrameContr=FrameContr;
	    _LimProcent=LimProcent;
		_Prohod++;
		if(_iNum==1)
		    return;
		else
		 _lShetCicl++;

		_dSumma+=_FrameOne;
        _FrameAll=_dSumma/_lShetCicl;
		//определяем макс-мин з-я за ALL циклов
		if (_lShetCicl==1)
		{
				_FrameMax=_FrameMin=_FrameMaxN=_FrameMinN=_FrameOne;
		        _ProcentOut=0; //_NminN=_NmaxN =0;//(g_FrameMax<=0.00001) 
		}
		else if(_FrameOne<_FrameMin)     _FrameMin=_FrameOne;
		else if(_FrameOne>_FrameMax)     _FrameMax=_FrameOne;



		
	    if(_shet<_iNum)
		{
	        if(_shet==0)
				_FrameMaxN=_FrameMinN=_FrameOne;
			_dSummaN+=_FrameOne;
			//определяем макс-мин з-я за N циклов
			if(_FrameOne<_FrameMinN)            _FrameMinN=_FrameOne;
		    else if(_FrameOne>_FrameMaxN)       _FrameMaxN=_FrameOne  ;

			//определяем число выходов за контрольное з-ие на 10 процентов
			if(_FrameOne<_FrameLimMin)          _countNminN++;
			else if(_FrameOne>_FrameLimMax)     _countNmaxN++;

			_shet++;
		}else
		{
			 double t= _countNmaxN+_countNminN;
			 _ProcentOut=(t/_iNum)*100.0;
			 _FrameN= _dSummaN*_dNum;
			_dSummaN=0.0;
			_shet=0;
			 _countNminN=0;
			 _countNmaxN=0;
		}


	}

//------------------------------------------------------------------------------
 #define   NUMVPP_READ      10   //всего ВПП (с прям. и обратн.)
 #define   NUMSTART_READ    5    //старт.точек на одной ВПП (с прям. и обратн.)
 #define   NUMRNT_READ      100  //max num -  всего приводных (БПРС ДПРС ОПРС) станций //всего ADM-RSBN станций  //всего VOR станций
 #define   NUMTRAS_READ     5    //всего [TRAS_0]- [TRASSA_4] для набора прс, адм, вор
 #define   NUMRNT           NUMRNT_READ+NUMVPP_READ*4 //всего станций одного типа :  приводных (БПРС ДПРС ОПРС) станций //либо ADM-RSBN //либо VOR
//----------------------------------------------------
#pragma pack(push, 1)
//#ifdef _NavMap_h
struct SHGEOPOINT{
		double LatGeo_g;    //тек. координаты
		double Lat_r;
		double Lon_g;
		double Lon_r;
		double YrovenMest; //тек. уровень места

};
struct SHRECTPOINT{         //тек. прямоуг.координаты  отн.принятой точки старта
		double XZa	[2];     // (торцы ВПП прямого старта)
		double XZk	[2];
		double  Y_AK; //  коорд. Y (высоты) отн. принятой точки старта
};

//struct SHANGLEDALN{
//		double Az_Tek_r;
//		double Az_Tek_g;
//		double AnglNakl_r;
//		double AnglNakl_g;
//		double D_Tek;
//		double Dn_Tek;
//};
struct SHSP{
	   //	char name[64];
		//SHGEOPOINT  posNul; //коорд.точки в гео
		SHRECTPOINT NulKRM;    //коорд.точки в прямоуг.СК, относительно выбранного центра - торцы АЕР прямого курса
		SHRECTPOINT NulGRM;
		double TopXA;
		double BottomXA;
		double PolySektorJob;
		double PolySektorLimTop;
		double PolySektorLimBottom;
		double DalnLim;
		float  Freq;
		bool   enabl;
		//bool   enablDn;
		bool   enablHg;
		int    morse[3];
 };
//struct SHGRM{
//	   //	char name[64];
//		SHGEOPOINT  posNul; //коорд.точки в гео
//		SHRECTPOINT Nul;    //коорд.точки в прямоуг.СК, относительно выбранного центра - торцы АЕР прямого курса
// };


struct SHPRS{
//	RADIOPOINT::RADIOPOINT(){Lat_g=0.0,Lon_g=0.0, Lat_r=0.0, Az_r=0.0,  D=0.0};
		//string nameAer;
		char name[64];
		SHGEOPOINT  posNul; //коорд.точки в гео
		SHRECTPOINT Nul;    //коорд.точки в прямоуг.СК, относительно выбранного центра - торцы АЕР прямого курса
		double DalnLim;
	   //	unsigned int tip; //prs=0, adm = 1  vor/dme=2   vor=3
		unsigned int KanNavig;
		unsigned int KanPos;
//		unsigned int Freq_MHg_KHg;
//		unsigned int Freq_Hg;
		float  Freq;
		bool   enabl;
		bool   enablDn;
		bool   enablHg;
		int    morse[2];
};
struct SHADM{
//	RADIOPOINT::RADIOPOINT(){Lat_g=0.0,Lon_g=0.0, Lat_r=0.0, Az_r=0.0,  D=0.0};
		//string nameAer;
		char name[64];
		SHGEOPOINT  posNul; //коорд.точки в гео
		SHRECTPOINT Nul;    //коорд.точки в прямоуг.СК, относительно выбранного центра - торцы АЕР прямого курса
		double DalnLim;
		unsigned int tip; //0-VOR_DME      1-VOR        2 DME
		unsigned int KanNavig;
		unsigned int KanPosForvard;
		unsigned int KanPosBack;
		unsigned int Freq_MHg_KHg;
		unsigned int Freq_Hg;
		bool   enabl;
		bool   enablDn;
		bool   enablHg;
		int    morse[2];
};
struct SHVOR{
//	RADIOPOINT::RADIOPOINT(){Lat_g=0.0,Lon_g=0.0, Lat_r=0.0, Az_r=0.0,  D=0.0};
		//string nameAer;
		char name[64];
		SHGEOPOINT  posNul; //коорд.точки в гео
		SHRECTPOINT Nul;    //коорд.точки в прямоуг.СК, относительно выбранного центра - торцы АЕР прямого курса
//		double XZa	[2];
//		double XZk	[2];
//		double  Y_AK;
		//SHANGLEDALN posAzD;
		//double Habs_Nul;
		unsigned int tip; // 0-VOR_DME      1-VOR        2 DME
		unsigned int KanNavig;
		unsigned int KanPos;
		unsigned int Freq_MHg_KHg;
		unsigned int Freq_Hg;
		bool   enabl;
		bool   enablDn;
		bool   enablHg;
		int    morse[2];
};

struct SHRECTDELTNULLPOINT{
		double Angl ;
		double DX[3] ;//x,y,z
};
struct SHSTARTPOINT{
		char name[64];
		SHGEOPOINT posNul;
		SHRECTPOINT Nul;
		double PSI_g ;
		double PSI_r ;
		//bool bBack;//=1   Back
};

 struct SHVPP{
		char name[64];
		SHGEOPOINT   posNul[2];  //коорд. в гео forvard/back торцов
		SHGEOPOINT   posKTA;  //коорд. в гео KTA[
		double Lvpp;
		//SHANGLEDALN  posAzD;
		//SHRECTPOINT  posRect[2];
		//double DXk[3] ;//x,y,z//
		SHRECTDELTNULLPOINT DeltNul;
		double MKa_g[2] ;
		double IKa_g[2] ;
		double  IKa_r[2];
		double MS_g[2] ; //расчетное, для справки
		SHRECTPOINT NulMrpD[2];    //коорд.точки в прямоуг.СК, относительно выбранного центра - торцы АЕР прямого курса
		SHRECTPOINT NulMrpM[2];
		SHRECTPOINT NulMrpB[2];
		bool bBackEquipment; //1=подклюоборудование обратного курса
//		double XZa_mrpD_F	[2]	;//[0][1] - forvard / x,z
//		double XZa_mrpM_F	[2]	;
//		double XZa_mrpB_F	[2]	;
//		double XZa_mrpD_B	[2]	;//[0][1] - back / x,z
//		double XZa_mrpM_B	[2]	;
//		double XZa_mrpB_B	[2]	;
//		double Y_AK_F[3]; // уровень места [0][1][2]- forvard  daln /  sred  /  blih
//		double Y_AK_B[3];
		bool       bMRP_F[3]; //наличие  mrp  [0][1][2]- forvard  daln /  sred  /  blih
		bool       bMRP_B[3]; //наличие  mrp  [0][1][2]- back  daln /  sred  /  blih
//		bool       bAdm; //наличие adm станций на аэродроме
//		bool       bVor; //наличие vor станций на аэродроме
//		int        iPrs; //число приводных станций на аэродроме
		SHADM      adm;
		SHVOR      vor;
		SHPRS      prs_F[2]; ////[0][1] - forvard dprs bprs
		SHPRS      prs_B[2]; ////[0][1] - back dprs bprs /
		SHSP       sp_F;//krm +grm // координаты krm и grm даются относительно БЛИЖАЙШЕГО торца
		SHSP       sp_B;//krm +grm // координаты krm и grm даются относительно БЛИЖАЙШЕГО торца
		float      UKV1_Freq;
		float      UKV2_Freq;
		float      KV_Freq;
	   //	SHRNT      dprs[2];
		SHSTARTPOINT stP[NUMSTART_READ];
	   //	bool bBack;   //==0 -forvard
	   //	unsigned int indAer;  //индекс аэродрома
};
//struct SHAER{
//		string nameAer  ;    //справка
//		double MSa_g	;    //справка
////		SHVPP  Fv  ;
////		SHVPP  Bk  ;
//	  //	bool   bBackVPPjob                      ;
//};



struct SHTEKTIMEPOINT{
		//--------------------в каждом тике
		SHGEOPOINT pos;
		SHRECTPOINT rect;
		double  MS_g;
		double  IK_r;
		double  IK_g;
		double  Tg_g;
		double  Kr_g;
		double  IKivo_r;
		double  IKivo_g;
		double  IKnulStP_r;
		double  IKnulStP_g;
		//--текущие настройки оборудования в каждом тике
		double ARK_freq;
		//int RSBN_kanN;//==num РСБН настроен на тек. канал, равный num  // 0 - не настроен
		//int RSBN_kanPos;//==num РСБН настроен на тек. канал, равный num  // 0 - не настроен

		int       iNumRSBN;//номер РСБН настроенонного на тек. канал :
		                   // для 1 aer: 1= канал НАВ 
					       //            2= канал ПОС прямого курса
					       //            3= канал ПОС обратного курса
					       // для 2 aer: 3,4,5   //   для 3 aer: 6,7,8 и т.д.

		 int    iNumNastrARK;         //0 - net 1,2,3,4  - 1 aer   5,6,7,8  - 2 aer    9,10,11,12  - 3 aer
		 //bool   bRSBN_es;           //признак из системы о настроенном оборудовании 1 -es
		 //bool   bARK_es;            //признак из системы о настроенном оборудовании 1 -es
		//--------------------при смене  Abase
		double  HabsStartSK;//абс.высота стартовой точки
		int     Abase;//номер тек аеродрома центра прямоуг.СК     //tek
};

//#endif
 ////////////////////////////////////
struct SHNAVMAP //
{


	//char logName[64] ;
	//char iniName[64] ;

	 //-----------------------------------------
	 //double inVgX;
	 //double inVgY;
	 //double inVgZ;

	 //double inPsi_r;
	 //double inPsi_g;
	 //double inKr_g;
	 //double inTg_g;

	//stringstream logStr;

	int NumVpp;//всего ВПП
	int NumStP;//всего  стартовых точек
	int NumADM;//всего трассовые +аер  ADM
	int NumVOR;//всего трассовые +аер VOR
	int NumPRS;//всего трассовые +аер ПРС (БПРС ДПРС ОПРС)
   //	int NumSumRNT;//всего станций  (NumADM + NumVOR + NumPRS)
	//int     Abase;//номер тек аеродрома центра прямоуг.СК     //tek
   //	bool    bZahod;// true - back
	double  Daer[NUMVPP_READ];                                //tek
	double  AZaer_g[NUMVPP_READ];                             //tek
	int     TekStA; //0, 1 , 2  //номер тек аеродром для тек  стартовой точки
	int     TekSt;//номер тек  стартовой точки
	SHVPP Vpp[NUMVPP_READ]; // 0-Balashev  1-Rtihevo  2 -Borisogleb
	SHPRS oprs_tras[NUMRNT_READ]; //трассовые oprs (если есть)
	SHADM adm_tras[NUMRNT_READ]; //трассовые adm (если есть)
	SHVOR vor_tras[NUMRNT_READ]; //трассовые vor (если есть)
	SHVOR* pVOR[NUMRNT];   //ук. на ВСЕ станции данного типа
	SHADM* pADM[NUMRNT];
	SHPRS* pPRS[NUMRNT];
	SHTEKTIMEPOINT tekP;      //tek
	//SHTEKTIMEPOINT oldP;
	//bool prConnectMap;
   bool prConnectNav;
   bool bClose;//признак завершения через внешнюю память из Disp410
};
#pragma pack(pop)



//#endif
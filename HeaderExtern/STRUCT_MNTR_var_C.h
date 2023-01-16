#pragma pack(push, 1)

typedef struct
{
//
//------------ќрганы управлени€----------------------------------------
//
/*double U_PRESSURE_SELECT_KNOB_LEFT;   //кремальера ¬Ёћ-15

double U_PRESSURE_SELECT_KNOB_RIGHT;  //кремальера ¬Ёћ-15
//-------
double U_CONTROL_STICK; // штурвальна€ колонка

double U_STEERING_WHEEL; // штурвал

double U_PEDAL; // педали
//-------
double U_THROTTLE_CONTROL_LEVER_LEFT_1; //–”ƒ левый є 1

double U_THROTTLE_CONTROL_LEVER_LEFT_2; //–”ƒ левый є 2

double U_THROTTLE_CONTROL_LEVER_RIGHT_3; //–”ƒ правый є 3

double U_THROTTLE_CONTROL_LEVER_RIGHT_4; //–”ƒ правый є 4
*/
//
//------------–уль высоты----------------------------------------------
//
/*double CONTROL_STICK_POSITION;  //  штурвальна€ колонка, мм

double DRV;				        //  elevator, grad
double DRV_SAU_DEMP;				        //  elevator, grad
double DRV_SAU_UPR;				        //  elevator, grad
double DRV_SAU_SUM;				        //  elevator, grad
double DRV_SUM;				        //  elevator, grad
*/
//
//------------Ёлероны--------------------------------------------------
//
/*double STEERING_WHEEL_ANGLE;

double DEL_LEFT;
double DEL_RIGHT;

double DEL_OMXT_DEMP;
double DEL_OMX_DEMP;

double DEL_BETT_DEMP;
double DEL_BET_DEMP;

double DEL_SAU_DEMP;
//--
double DEL_SAU_UPR;
//--
double DEL_SAU_SUM;

double DEL_LEFT_SUM;
double DEL_RIGHT_SUM;
*/
//
//------------–уль направлени€-----------------------------------------
//
/*double PEDAL_LEFT_POSITION;   // положение педалей, мм

double DRN;				      //  rudder, grad
double DRN_SAU_DEMP;				      //  rudder, grad
double DRN_SAU_UPR;				      //  rudder, grad
double DRN_SAU_SUM;				      //  rudder, grad
double DRN_SUM;				      //  rudder, grad
*/
//
//------------–”ƒ------------------------------------------------------
//
/*double AL_VAL_LEFT_1;
double AL_VAL_LEFT_2;

double AL_VAL_RIGHT_3;
double AL_VAL_RIGHT_4;
*/
//
//------------ƒвигатель------------------------------------------------
//
/*bool ENGINE_STARTED_LEFT_1; // Priznak raboti dvigatelya (1=yes)
bool ENGINE_STARTED_LEFT_2; // Priznak raboti dvigatelya (1=yes)

bool ENGINE_STARTED_RIGHT_3; // Priznak raboti dvigatelya (1=yes)
bool ENGINE_STARTED_RIGHT_4; // Priznak raboti dvigatelya (1=yes)
//-------
double ENGINE_NGG_LEFT_1; // 0+110%
double ENGINE_NGG_LEFT_2; // 0+110%

double ENGINE_NGG_RIGHT_3; // 0+110%
double ENGINE_NGG_RIGHT_4; // 0+110%
//-------
double ENGINE_NGG_ZAD_LEFT_1; // 0+110%
double ENGINE_NGG_ZAD_LEFT_2; // 0+110%

double ENGINE_NGG_ZAD_RIGHT_3; // 0+110%
double ENGINE_NGG_ZAD_RIGHT_4; // 0+110%
//-------
double ENGINE_NE_LEFT_1; // к¬т
double ENGINE_NE_LEFT_2; // к¬т

double ENGINE_NE_RIGHT_3; // к¬т
double ENGINE_NE_RIGHT_4; // к¬т
//-------
double ENGINE_GT_LEFT_1;
double ENGINE_GT_LEFT_2;

double ENGINE_GT_RIGHT_3;
double ENGINE_GT_RIGHT_4;
//-------
//double ENGINE_TGZ_LEFT;         // 0+900 град C
//double ENGINE_TGZ_RIGHT;         // 0+900 град C

double ENGINE_MKR_LEFT_1; // крут€щий момент H*m
double ENGINE_MKR_LEFT_2; // крут€щий момент H*m

double ENGINE_MKR_RIGHT_3; // крут€щий момент H*m
double ENGINE_MKR_RIGHT_4; // крут€щий момент H*m
//-------
double ENGINE_MKR_PERCENT_LEFT_1; // 0+120% Mk крут€щий момент
double ENGINE_MKR_PERCENT_LEFT_2; // 0+120% Mk крут€щий момент

double ENGINE_MKR_PERCENT_RIGHT_3; // 0+120% Mk крут€щий момент
double ENGINE_MKR_PERCENT_RIGHT_4; // 0+120% Mk крут€щий момент
*/
//
//------------¬инт-----------------------------------------------------
//
/*double ENGINE_FIBB_LEFT_1;    // -25+80 угол установки лопастей
double ENGINE_FIBB_LEFT_2;    // -25+80 угол установки лопастей

double ENGINE_FIBB_RIGHT_3;   // -25+80 угол установки лопастей
double ENGINE_FIBB_RIGHT_4;   // -25+80 угол установки лопастей
//-------
double ENGINE_LAMBDA_LEFT_1;
double ENGINE_LAMBDA_LEFT_2;

double ENGINE_LAMBDA_RIGHT_3;
double ENGINE_LAMBDA_RIGHT_4;
//-------
double ENGINE_ALFA_LEFT_1;
double ENGINE_ALFA_LEFT_2;

double ENGINE_ALFA_RIGHT_3;
double ENGINE_ALFA_RIGHT_4;
//-------
double ENGINE_BETTA_LEFT_1;
double ENGINE_BETTA_LEFT_2;

double ENGINE_BETTA_RIGHT_3;
double ENGINE_BETTA_RIGHT_4;
//-------
double ENGINE_NBB_ZAD_LEFT_1;    // 0+2400 обороты/мин
double ENGINE_NBB_ZAD_LEFT_2;    // 0+2400 обороты/мин

double ENGINE_NBB_ZAD_RIGHT_3;    // 0+2400 обороты/мин
double ENGINE_NBB_ZAD_RIGHT_4;    // 0+2400 обороты/мин
//-------
double ENGINE_NBB_LEFT_1;    // 0+2400 обороты/мин
double ENGINE_NBB_LEFT_2;    // 0+2400 обороты/мин

double ENGINE_NBB_RIGHT_3;    // 0+2400 обороты/мин
double ENGINE_NBB_RIGHT_4;    // 0+2400 обороты/мин
//-------
double ENGINE_MKRBB_LEFT_1; // крут€щий момент винта H*m
double ENGINE_MKRBB_LEFT_2; // крут€щий момент винта H*m

double ENGINE_MKRBB_RIGHT_3; // крут€щий момент винта H*m
double ENGINE_MKRBB_RIGHT_4; // крут€щий момент винта H*m
//-------
double ENGINE_MKRBB_PERCENT_LEFT_1; // 0+120% Mk крут€щий момент винта
double ENGINE_MKRBB_PERCENT_LEFT_2; // 0+120% Mk крут€щий момент винта

double ENGINE_MKRBB_PERCENT_RIGHT_3; // 0+120% Mk крут€щий момент винта
double ENGINE_MKRBB_PERCENT_RIGHT_4; // 0+120% Mk крут€щий момент винта
//-------
double ENGINE_NEBB_LEFT_1; // к¬т
double ENGINE_NEBB_LEFT_2; // к¬т

double ENGINE_NEBB_RIGHT_3; // к¬т
double ENGINE_NEBB_RIGHT_4; // к¬т
//-------
double ENGINE_PBB_LEFT_1;    // т€га винта левого кг
double ENGINE_PBB_LEFT_2;    // т€га винта левого кг

double ENGINE_PBB_RIGHT_3;   // т€га винта правого кг
double ENGINE_PBB_RIGHT_4;   // т€га винта правого кг
//-------
double ENGINE_PREACT_LEFT_1;    // т€га винта левого кг
double ENGINE_PREACT_LEFT_2;    // т€га винта левого кг

double ENGINE_PREACT_RIGHT_3;   // т€га винта правого кг
double ENGINE_PREACT_RIGHT_4;   // т€га винта правого кг
//-------
double ENGINE_FULL_THRUST_LEFT_1;    //
double ENGINE_FULL_THRUST_LEFT_2;    //

double ENGINE_FULL_THRUST_RIGHT_3;   //
double ENGINE_FULL_THRUST_RIGHT_4;   //
*/
//
//------------“опливо--------------------------------------------------
//
/*double WING_TANK_FUEL_WEIGHT_SUMMARY;       // масса топлива, kg
*/
//
//------------ѕараметры полета-----------------------------------------
//
/*double TEMP_AIR_CELS;

double TEMP_SEA_LEVEL_CELS;

double PRES_SEA_LEVEL;

bool PR_MCA;
//-------
double M;

double V;
double VXY;

double VPR;   // 0+600 km/h
double VPR_RMI;   // 0+600 km/h

double VIST;   // 0+600 km/h
//-------
double H;  // -500+10000 m высота
//-------
//double INO_HM;
double LOCATION_ALTITUDE_ABOVE_SEA_LEVEL;

//double RMI_AGLH;  //  радиовысота 0+900 м
double ALTITUDE_ABOVE_LOCATION_LEVEL;

double VKYG_PR; //  -30+30 ћ/— вертикальна€ скорость
//-------
double ALF;
double AL;
double BTF;
//
//-------
double NX;
double NY;
double NZ;

double AX;
double AY;
double AZ;
//
//-------
double VKXT;
double VKYT;
double VKZT;
//--
double VKX;
double VKY;
double VKZ;
//--
double WX;
double WY;
double WZ;
//--
double VX;
double VY;
double VZ;
//
//-------
double OMXT;
double OMYT;
double OMZT;
//--
double OMX;
double OMY;
double OMZ;
//--
double TGTR;
double KRTR;
double PSITR;
//--
double TGR;
double KRR;
double PSIR;
//--
double TG; // -90+90 град тангаж
double KR; // -180+180 град крен
double PSI; // -180+180 град  курс
double PSI_PR; // 0+360 град  курс
//-------
double MZ_CY;

double DRV_V;

double DRV_NY;

double OMZ_DRV;
//-------
double DEL_OMX;
//
//------------
double Vxg_DISS;   // VXG_D
double VKYG;
double Vzg_DISS;
*/
//
//------------IVO------------------------------------------------------
/*double Vxg_IVO;    // VXG_A
double VKYG_IVO;
double Vzg_IVO;

double XG_IVO;
double YG_IVO;
double ZG_IVO;
*/
//------------INO------------------------------------------------------
/*double Vxg_INO;    //VXG_G
double VKYG_INO;
double Vzg_INO;

double XG_INO;
double YG_INO;
double ZG_INO;
*/
//-------
/*double MAC;           //масса Ћј  кг

double XT_PERCENT;    //центровка, %
double XT;            //центровка, м
double DXT;
*/
//-------
//
//------------Tanker---------------------------------------------------
//
/*double TANKER_XF;
double TANKER_YF;
double TANKER_ZF;

double TANKER_VXF;
double TANKER_VYF;
double TANKER_VZF;

double TANKER_TGF;
double TANKER_KRF;
double TANKER_PSIF;

double TANKER_TGTF;
double TANKER_KRTF;
double TANKER_PSITF;
//-------
double TANKER_V;

double TANKER_VPR;

double TANKER_VIST;

double TANKER_H;
*/
//
//------------Airplane-------------------------------------------------
//
/*double AIRPLANE_XF;
double AIRPLANE_YF;
double AIRPLANE_ZF;

double AIRPLANE_VXF;
double AIRPLANE_VYF;
double AIRPLANE_VZF;

double AIRPLANE_TGF;
double AIRPLANE_KRF;
double AIRPLANE_PSIF;

double AIRPLANE_TGTF;
double AIRPLANE_KRTF;
double AIRPLANE_PSITF;
*/
//
//------------Fantom---------------------------------------------------
//
/*double FANTOM_XS;
double FANTOM_YS;
double FANTOM_ZS;

double FANTOM_VXS;
double FANTOM_VYS;
double FANTOM_VZS;

double FANTOM_TGS;
double FANTOM_KRS;
double FANTOM_PSIS;

double FANTOM_TGTS;
double FANTOM_KRTS;
double FANTOM_PSITS;
*/
//
//------------—илы X---------------------------------------------------
//
/*double CX_SEMI;
double CXALM;

double X_AERO;
//-------
double X_SHAS_NOSE;
double X_SHAS_LEFT;
double X_SHAS_RIGHT;
double X_SHAS_SUM;
//-------
double X_SU_LEFT_1;
double X_SU_LEFT_2;

double X_SU_RIGHT_3;
double X_SU_RIGHT_4;

double X_SU_SUM;
//-------
double X_SUM;
*/
//
//------------CY-------------------------------------------------------
//
/*double CY_SEMI;
double CYALM;

double Y_AERO;
//-------
double Y_SHAS_NOSE;
double Y_SHAS_LEFT;
double Y_SHAS_RIGHT;
double Y_SHAS_SUM;
//-------
double Y_SU_LEFT_1;
double Y_SU_LEFT_2;

double Y_SU_RIGHT_3;
double Y_SU_RIGHT_4;

double Y_SU_SUM;
//-------
double Y_SUM;
*/
//
//------------CZ-------------------------------------------------------
//
/*double CZBET;
double CZDRN;
double CZB_LEFT;
double CZB_RIGHT;
double CZ;

double Z_AERO;
//-------
double Z_SHAS_NOSE;
double Z_SHAS_LEFT;
double Z_SHAS_RIGHT;
double Z_SHAS_SUM;
//-------
double Z_SU_LEFT_1;
double Z_SU_LEFT_2;

double Z_SU_RIGHT_3;
double Z_SU_RIGHT_4;

double Z_SU_SUM;
//-------
double Z_SUM;
*/
//
//------------MX-------------------------------------------------------
//
/*double MX_SEMI;
double MXBET;
//-------
double MXDEL_LEFT;
double MXDEL_RIGHT;
double MXDEL;
//-------
double MXDRN;

double MXWX;
double MXWY;
double MXB_LEFT;
double MXB_RIGHT;
double MX;
double MX_DEMP;

double MX_AERO;
double MX_AERO_DEMP;
double MX_AERO_SUM;
double MX_ZV;
//-------
double MX_SHAS_NOSE;
double MX_SHAS_LEFT;
double MX_SHAS_RIGHT;
double MX_SHAS_SUM;
//-------
double MX_ENGINE_LEFT_1;
double MX_ENGINE_LEFT_2;

double MX_ENGINE_RIGHT_3;
double MX_ENGINE_RIGHT_4;

double MX_SU_SUM;
//------
double MX_CM;
//-------
double MX_SUM;
*/
//
//------------MY-------------------------------------------------------
//
/*double MY_SEMI;
double MYBET;
double MYDRN;

double MYWY;
double MYWX;

double MYB_LEFT;
double MYB_RIGHT;

double MY;
double MY_DEMP;

double MY_AERO;
double MY_AERO_DEMP;
double MY_AERO_SUM;
double MY_ZV;
//-------
double MY_SHAS_NOSE;
double MY_SHAS_LEFT;
double MY_SHAS_RIGHT;
double MY_SHAS_SUM;
//-------
double MY_ENGINE_LEFT_1;
double MY_ENGINE_LEFT_2;

double MY_ENGINE_RIGHT_3;
double MY_ENGINE_RIGHT_4;
//-------
double MY_GYRO_LEFT_1;
double MY_GYRO_LEFT_2;

double MY_GYRO_RIGHT_3;
double MY_GYRO_RIGHT_4;
//-------
double MY_SU_LEFT_1;
double MY_SU_LEFT_2;

double MY_SU_RIGHT_3;
double MY_SU_RIGHT_4;
//-------
double MY_SU_SUM;
//-------
double MY_CM;
//-------
double MY_SUM;
*/
//
//------------MZ-------------------------------------------------------
//
/*double MZALM;
double DMZB;

double MZDRV;
double DMZDRVB;

double MZWZ;
double MZWZ_LEFT;
double MZWZ_RIGHT;

double MZALT;
double MZALT_LEFT;
double MZALT_RIGHT;

double MZ;
double MZ_DEMP;
double MZ_DEMP_OMZ;
double MZ_DEMP_ALT;

double MZ_AERO;
double MZ_AERO_DEMP;

double MZ_AERO_SUM;
double MZ_ZV;
//-------
double MZ_SHAS_NOSE;
double MZ_SHAS_LEFT;
double MZ_SHAS_RIGHT;
double MZ_SHAS_SUM;
//-------
double MZ_ENGINE_LEFT_1;
double MZ_ENGINE_LEFT_2;

double MZ_ENGINE_RIGHT_3;
double MZ_ENGINE_RIGHT_4;
//-------
double MZ_GYRO_LEFT_1;
double MZ_GYRO_LEFT_2;

double MZ_GYRO_RIGHT_3;
double MZ_GYRO_RIGHT_4;
//-------
double MZ_SU_LEFT_1;
double MZ_SU_LEFT_2;

double MZ_SU_RIGHT_3;
double MZ_SU_RIGHT_4;

double MZ_SU_SUM;
//-------
double MZ_CM;
//-------
double MZ_SUM;
*/
//
//------------÷икл-----------------------------------------------------
//
/*double TimCalk[8][10];

char TimerName[8][64];

bool TimerReset;
*/
//-------
int PARAM_FOR_MONITOR_COUNT;
//
//------------Graphic value
//
double PARAM_FOR_MONITOR[30];
//
//------------Graphic name
//
wchar_t GraphicName[30][20];

/*wchar_t GraphicName_1[20];

wchar_t GraphicName_2[20];

wchar_t GraphicName_3[20];

wchar_t GraphicName_4[20];

wchar_t GraphicName_5[20];

wchar_t GraphicName_6[20];

wchar_t GraphicName_7[20];

wchar_t GraphicName_8[20];

wchar_t GraphicName_9[20];

wchar_t GraphicName_10[20];

wchar_t GraphicName_11[20];

wchar_t GraphicName_12[20];
*/
//
//------------Graphic color
//
//int RedValue[10];

//int GreenValue[10];

//int BlueValue[10];
//-------
} SHMNTR_VAR_C;

#pragma pack(pop)


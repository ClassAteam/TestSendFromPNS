// "STRUCT_CMF_410" - memory name
//17.09.2018

#pragma pack(push, 1)

typedef struct
{
//
//------------Аналоговые входные сигналы-------------------------------
//
double U_CONTROL_STICK; // штурвальная колонка

double U_STEERING_WHEEL; // штурвал

double U_PEDAL; // педали

double U_PILOT_BRAKE_PEDAL_LEFT; //левая подножка левого пульта
double U_PILOT_BRAKE_PEDAL_RIGHT; //правая подножка левого пульта

double U_CO_PILOT_BRAKE_PEDAL_LEFT; //левая подножка правого пульта
double U_CO_PILOT_BRAKE_PEDAL_RIGHT; //правая подножка правого пульта

double U_ELEVATOR_TRIM_HAND_WHEEL; // триммер руля высоты

double U_NOSE_LANDING_GEAR_STEERING_WHEEL; //рукоятка носового колеса

double U_EMERGENCY_HYDRAULIC_PUMP_LEVER; //ручная помпа
//
//------------Центральный пульт----------------------------------------
//
double U_THROTTLE_CONTROL_LEVER_LEFT; //РУД левый
double U_THROTTLE_CONTROL_LEVER_RIGHT; //РУД правый

double U_PROPELLER_CONTROL_LEVER_LEFT; //РУВ левый
double U_PROPELLER_CONTROL_LEVER_RIGHT; //РУВ правый

double U_EMERGENCY_THROTTLE_LEVER_LEFT; //Стоп-кран левый
double U_EMERGENCY_THROTTLE_LEVER_RIGHT; //Стоп-кран правый
//
//------------Загружатели----------------------------------------------
//
double U_FORCE_PEDAL; //Загружатель педалей

double U_FORCE_CONTROL_STICK; //Загружатель штурвальной колонки

double U_FORCE_STEERING_WHEEL; //Загружатель штурвала

double U_FORCE_ELEVATOR_TRIM; //Триммер руля высоты
//
//------------Органы управления----------------------------------------
//
double DRV;				        //  elevator, grad
//double CONTROL_STICK_POSITION;  //  штурвальная колонка, мм

double DEL_LEFT;			  // aileron left, grad
double DEL_RIGHT;			  // aileron right, grad
//double STEERING_WHEEL_ANGLE;  // угол поворота штурвала, град

double DRN;				      //  rudder, grad
//double PEDAL_LEFT_POSITION;   // положение педалей, мм

//double LEFT_PULT_TOE_ANGLE_LEFT;     // угол поворота тормозной подножки, град
//double LEFT_PULT_TOE_PRESSURE_LEFT;  // давление от тормозной подножки, кг/см2

//double LEFT_PULT_TOE_ANGLE_RIGHT;
//double LEFT_PULT_TOE_PRESSURE_RIGHT;

//double RIGHT_PULT_TOE_ANGLE_LEFT;
//double RIGHT_PULT_TOE_PRESSURE_LEFT;

//double RIGHT_PULT_TOE_ANGLE_RIGHT;
//double RIGHT_PULT_TOE_PRESSURE_RIGHT;

double WING_FLAPS_ANGLE;	//  zakrilki
double SPOILER_ANGLE;		//  interseptor
double SCHT_ANGLE;			//  shitok avtomat kren

//double NOSE_LANDING_GEAR_STEERING_WHEEL_ANGLE;
double FI_NOSE_WHEEL;             //  angle nos koleso

//double EMERGENCY_HYDRAULIC_PUMP_LEVER_ANGLE;
//
//------------
double AL_RUD_LEFT;
double AL_RUD_RIGHT;

double AL_RUB_LEFT;			     //rihag upravl vint left
double AL_RUB_RIGHT;			     //rihag upravl vint r

double AL_STOP_LEFT;			     //angle upravl stop-kran l
double AL_STOP_RIGHT;		     //angle upravl stop-kran r

bool PR_FUEL_FIRE_COCK_OFF_LEFT;

bool PR_FUEL_FIRE_COCK_OFF_RIGHT;
//
//------------Триммер РВ-----------------------------------------------
//
//double ELEVATOR_TRIM_HAND_WHEEL_ANGLE;

double ELEVATOR_TRIM_ANGLE;	     //trimer rul H

//double D_ELEVATOR_TRIM;
//
//------------
double AILERON_TRIM_ANGLE;	     //trimer eleron

double RUDDER_TRIM_ANGLE;	     //trimer rul napravlen
//
//------------Загружатель РВ-------------------------------------------
//
//double CONTROL_STICK_FORCE_ZAD;
//double ELEVATOR_FORCE_POSITION;
//double D_ELEVATOR_FORCE;
//double CONTROL_STICK_FORCE;
//
//------------Загружатель ЭЛ-------------------------------------------
//
//double FORCE_STEERING_WHEEL_ZAD;
//double AILERON_FORCE_POSITION;
//double D_AILERON_FORCE;
//double STEERING_WHEEL_FORCE;
//
//------------Загружатель РН-------------------------------------------
//
//double FORCE_PEDAL_ZAD;
//double RUDDER_FORCE_POSITION;
//double D_RUDDER_FORCE;
//double PEDAL_FORCE;
//-------
double GENERATOR_RPM_LEFT;        //oborot/min elektro-gen l
double GENERATOR_RPM_RIGHT;       //oborot/min elektro-gen r

double BRAKE_PRESSURE_LEFT;	     //davlen tormoz l
double BRAKE_PRESSURE_RIGHT;	     //davlen tormoz r
//
//------------
//double COCKPIT_TEMPERATURE;   // 0+40 grad C  температура кабины
//double CHANNEL_TEMPERATURE;    // 20+120 grad C  температура канала
//
//------------
//bool ENGINE_STARTED_LEFT; // Priznak raboti dvigatelya (1=yes)
//bool ENGINE_STARTED_RIGHT; // Priznak raboti dvigatelya (1=yes)

double ENGINE_NGG_LEFT; // 0+110%
double ENGINE_NGG_RIGHT; // 0+110%

//double ENGINE_NGG_ZAD_LEFT; // 0+110%
//double ENGINE_NGG_ZAD_RIGHT; // 0+110%

//double ENGINE_NE_LEFT; // кВт
//double ENGINE_NE_RIGHT; // кВт

//double ENGINE_GT_LEFT;
//double ENGINE_GT_RIGHT;

double ENGINE_TGZ_LEFT;         // 0+900 град C
double ENGINE_TGZ_RIGHT;         // 0+900 град C

//double ENGINE_MKR_LEFT; // крутящий момент H*m
//double ENGINE_MKR_RIGHT; // крутящий момент H*m

double ENGINE_MKR_PERCENT_LEFT; // 0+120% Mk крутящий момент
double ENGINE_MKR_PERCENT_RIGHT; // 0+120% Mk крутящий момент
//
//------------Винт-----------------------------------------------------
//
double ENGINE_NBB_LEFT;    // 0+2400 обороты/мин
double ENGINE_NBB_RIGHT;    // 0+2400 обороты/мин

//double ENGINE_NBB_ZAD_LEFT;    // 0+2400 обороты/мин
//double ENGINE_NBB_ZAD_RIGHT;    // 0+2400 обороты/мин

double ENGINE_FIBB_LEFT;    // -25+80 угол установки лопастей
double ENGINE_FIBB_RIGHT;   // -25+80 угол установки лопастей

//double ENGINE_MKRBB_LEFT; // крутящий момент винта H*m
//double ENGINE_MKRBB_RIGHT; // крутящий момент винта H*m

//double ENGINE_MKRBB_PERCENT_LEFT; // 0+120% Mk крутящий момент винта
//double ENGINE_MKRBB_PERCENT_RIGHT; // 0+120% Mk крутящий момент винта

//double ENGINE_NEBB_LEFT; // кВт
//double ENGINE_NEBB_RIGHT; // кВт

double ENGINE_PBB_LEFT;    // тяга винта левого кг
double ENGINE_PBB_RIGHT;   // тяга винта правого кг

//double ENGINE_PREACT_LEFT;    // тяга винта левого кг
//double ENGINE_PREACT_RIGHT;   // тяга винта правого кг
//
//-------
double ENGINE_FUEL_PRESSURE_LEFT; // 0+16 кг/см2     // давление топлива
double ENGINE_FUEL_PRESSURE_RIGHT; // 0+16 кг/см2     // давление топлива

double ENGINE_OIL_PRESSURE_LEFT;  // 0+4 кг/см2      // давление масла
double ENGINE_OIL_PRESSURE_RIGHT;  // 0+4 кг/см2      // давление масла

double ENGINE_OIL_TEMPERATURE_LEFT; // -30+120 grad C  // температура масла
double ENGINE_OIL_TEMPERATURE_RIGHT; // -30+120 grad C  // температура масла
//
//------------
//double LAMBDA_LEFT;
//double LAMBDA_RIGHT;
//
//------------
//double WING_TIP_TANK_FUEL_WEIGHT_LEFT; // 0+200 кг  масса топлива
//double WING_TIP_TANK_FUEL_WEIGHT_RIGHT; // 0+200 кг  масса топлива

double WING_TANK_FUEL_WEIGHT_SUM_LEFT;       // 0+525 kg масса топлива
double WING_TANK_FUEL_WEIGHT_SUM_RIGHT;       // 0+525 kg масса топлива

//double WING_TANK_FUEL_WEIGHT_SUMMARY;       // 0+525 kg масса топлива
//
//------------
//double TEMP_AIR_CELS;
//-------
//double M;

//double V;
//double VXY;

//double VPR;   // 0+600 km/h
double VPR_RMI;   // 0+600 km/h

//double VIST;   // 0+600 km/h
//-------
//double H;  // -500+10000 m высота
//double RMI_AGLH;  //  радиовысота 0+900 м

//double VKYG_PR; //  -30+30 М/С вертикальная скорость
//-------
double ALF;
//double AL;
double BTF;
//
//-------
double NX;
double NY;
double NZ;

//double AX;
//double AY;
//double AZ;
//
//-------
//double VKXT;
//double VKYT;
//double VKZT;
//--
//double VKX;
//double VKY;
//double VKZ;
//--
//double WX;
//double WY;
//double WZ;
//--
//double VX;
//double VY;
//double VZ;
//
//-------
//double OMXT;
//double OMYT;
//double OMZT;
//--
//double OMX;
//double OMY;
//double OMZ;
//--
double TGTR;
double KRTR;
double PSITR;
//--
double TGR;
double KRR;
double PSIR;
//--
//double TG; // -90+90 град тангаж
//double KR; // -180+180 град крен
//double PSI; // -180+180 град  курс
//double PSI_PR; // 0+360 град  курс
//
//------------
//double Vxg_DISS;   // VXG_D
//double VKYG;
//double Vzg_DISS;
//
//------------IVO------------------------------------------------------
//
//double Vxg_IVO;    // VXG_A
double VKYG_IVO;
//double Vzg_IVO;

double XG_IVO;
double YG_IVO;
double ZG_IVO;

double CMFfromNAV_VAX;
double CMFfromNAV_VAZ;
double CMFfromNAV_LATGG;
double CMFfromNAV_LONG;
double CMFfromNAV_IKG_START;
double CMFfromNAV_HA_START;    //высота ст. точки
double CMFfromNAV_IK_GRAD; // истинный курс в град.

bool   PR_OUTER_BEACON_IVO; //дальний
bool   PR_MEDIUM_BEACON_IVO; //средний
bool   PR_INNER_BEACON_IVO; //ближний
//
//------------INO------------------------------------------------------
//
//double Vxg_INO;    //VXG_G
//double VKYG_INO;
//double Vzg_INO;

//double XG_INO;
//double YG_INO;
//double ZG_INO;
//-------
double PSI_AIRFIELD_IK_GRAD;
//-------
double INO_HM;
//-------
double MAC;           //масса ЛА  кг

double XT_PERCENT;    //центровка, %
//double XT;            //центровка, м
//double DXT;
//-------Фары для ИВО--------------------------------------------------
bool PR_POSITION_LIGHTS;

bool PR_SEARCHLIGHTS_LANDING;

bool PR_SEARCHLIGHTS_TAXIING;
//-------
int FLIGHT_CYCLE_COUNT;

//double FLIGHT_CYCLE_TIME;

//int CYCLE_TIME;

//int CYCLE_ETALON;
//
//------------
bool PR_TOUCH_DOWN_NOSE;
bool PR_TOUCH_DOWN_LEFT;
bool PR_TOUCH_DOWN_RIGHT;

bool PR_TOUCH_DOWN_GROUND_RUNWAY_NOSE;
bool PR_TOUCH_DOWN_GROUND_RUNWAY_LEFT;
bool PR_TOUCH_DOWN_GROUND_RUNWAY_RIGHT;

bool PR_FUSELAGE_LANDING;//признак конца инициализации DIN

bool PR_TOUCH_DOWN_WING_LEFT;
bool PR_TOUCH_DOWN_WING_RIGHT;

bool PR_TAIL_LANDING;

bool PR_TIRE_BURST_NOSE;
bool PR_TIRE_BURST_LEFT;
bool PR_TIRE_BURST_RIGHT;

bool PR_ENGINE_FUEL_BURN_LEFT;
bool PR_ENGINE_FUEL_BURN_RIGHT;

bool PR_SHASSI_ACTUATION_NOSE;     //выпуск - 1
bool PR_SHASSI_ACTUATION_LEFT;     //выпуск - 1
bool PR_SHASSI_ACTUATION_RIGHT;    //выпуск - 1

bool PR_SHASSI_LOCK_OFF_NOSE;     // замок убранного положения
bool PR_SHASSI_LOCK_OFF_LEFT;
bool PR_SHASSI_LOCK_OFF_RIGHT;

bool PR_SHASSI_LOCK_ON_NOSE;      // замок выпущенного положения
bool PR_SHASSI_LOCK_ON_LEFT;
bool PR_SHASSI_LOCK_ON_RIGHT;
//-------
double STRUT_POSITION_NOSE;

double STRUT_POSITION_LEFT;

double STRUT_POSITION_RIGHT;
//-------
} SHCMF_410;

#pragma pack(pop)


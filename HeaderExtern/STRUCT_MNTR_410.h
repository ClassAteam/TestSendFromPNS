// "STRUCT_MNTR_410" - memory name
//04.06.2018

#pragma pack(push, 1)

typedef struct
{
//
//------------Внешние условия------------------------------------------
//
double AERODROM_ALTITUDE[3];

double AERODROM_TEMP_CELS[3];

double AERODROM_TEMP_KELVIN[3];

double AERODROM_PRES_HG[3];

double AERODROM_PRES_PA[3];

double AERODROM_AIRDENSITY[3];
//-------
double SEA_LEVEL_TEMP_CELS;

double SEA_LEVEL_TEMP_KELVIN;

double SEA_LEVEL_PRES_PA;

double SEA_LEVEL_PRES_HG;

double SEA_LEVEL_AIRDENSITY;
//-------
double GRVT;

double AIR_TEMP_KELVIN;

double AIR_TEMP_CELS;

double AIR_PRES_PA;

double AIR_PRES_HG;

double AIR_PRES_KGS_CM2;

double BARO_ALTITUDE;

double AIR_VISCOUS;

double AIR_AIRDENSITY;

double SOUND_VELOSITY;

double BRAKED_FLOW_TEMP_KELVIN;
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

double U_EMERGENCY_HYDRAULIC_PUMP_LEVER; //ручной насос
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
//------------Дискретные входные сигналы------------------------------
//
//
//------------Дискретные выходные сигналы------------------------------
//
//
//------------Органы управления----------------------------------------
//
double DRV;				        //  elevator, grad
double CONTROL_STICK_POSITION;  //  штурвальная колонка, мм

double DEL_LEFT;			  // aileron left, grad
double DEL_RIGHT;			  // aileron right, grad
double STEERING_WHEEL_ANGLE;  // угол поворота штурвала, град

double DRN;				      //  rudder, grad
double PEDAL_LEFT_POSITION;   // положение педалей, мм

double LEFT_PULT_TOE_ANGLE_LEFT;     // угол поворота тормозной подножки, град
double LEFT_PULT_TOE_PRESSURE_LEFT;  // давление от тормозной подножки, кг/см2

double LEFT_PULT_TOE_ANGLE_RIGHT;
double LEFT_PULT_TOE_PRESSURE_RIGHT;

double RIGHT_PULT_TOE_ANGLE_LEFT;
double RIGHT_PULT_TOE_PRESSURE_LEFT;

double RIGHT_PULT_TOE_ANGLE_RIGHT;
double RIGHT_PULT_TOE_PRESSURE_RIGHT;

double  WING_FLAPS_ANGLE;	//  zakrilki
double  SPOILER_ANGLE;		//  interseptor
double  SCHT_ANGLE;			//  shitok avtomat kren

double NOSE_LANDING_GEAR_STEERING_WHEEL_ANGLE;
double FI_NOSE_WHEEL;             //  angle nos koleso

double DSHAS_NOSE;
double DSHAS_LEFT;
double DSHAS_RIGHT;

double EMERGENCY_HYDRAULIC_PUMP_LEVER_ANGLE;
//
//------------
double AL_RUD_LEFT;
double AL_RUD_RIGHT;

double AL_RUB_LEFT;			     //rihag upravl vint left
double AL_RUB_RIGHT;			     //rihag upravl vint r

double AL_STOP_LEFT;			     //angle upravl stop-kran l
double AL_STOP_RIGHT;		     //angle upravl stop-kran r
//
//------------Триммер РВ-----------------------------------------------
//
double ELEVATOR_TRIM_HAND_WHEEL_ANGLE;

double ELEVATOR_TRIM_ANGLE;	     //trimer rul H

double D_ELEVATOR_TRIM;
//
//------------
double AILERON_TRIM_ANGLE;	     //trimer eleron

double RUDDER_TRIM_ANGLE;	     //trimer rul napravlen
//
//------------Загружатель РВ-------------------------------------------
//
double CONTROL_STICK_FORCE_ZAD;
double ELEVATOR_FORCE_POSITION;
double D_ELEVATOR_FORCE;
double CONTROL_STICK_FORCE;
//
//------------Загружатель ЭЛ-------------------------------------------
//
double FORCE_STEERING_WHEEL_ZAD;
double AILERON_FORCE_POSITION;
double D_AILERON_FORCE;
double STEERING_WHEEL_FORCE;
//
//------------Загружатель РН-------------------------------------------
//
double FORCE_PEDAL_ZAD;
double RUDDER_FORCE_POSITION;
double D_RUDDER_FORCE;
double PEDAL_FORCE;
//-------
double GENERATOR_RPM_LEFT;        //oborot/min elektro-gen l
double GENERATOR_RPM_RIGHT;       //oborot/min elektro-gen r

double BRAKE_PRESSURE_LEFT;	     //davlen tormoz l
double BRAKE_PRESSURE_RIGHT;	     //davlen tormoz r
//
//------------
double COCKPIT_TEMPERATURE;   // 0+40 grad C  температура кабины
double CHANNEL_TEMPERATURE;    // 20+120 grad C  температура канала
//
//------------
bool ENGINE_STARTED_LEFT; // Priznak raboti dvigatelya (1=yes)
bool ENGINE_STARTED_RIGHT; // Priznak raboti dvigatelya (1=yes)

double ENGINE_NGG_LEFT; // 0+110%
double ENGINE_NGG_RIGHT; // 0+110%

double ENGINE_NGG_ZAD_LEFT; // 0+110%
double ENGINE_NGG_ZAD_RIGHT; // 0+110%

double ENGINE_NE_LEFT; // кВт
double ENGINE_NE_RIGHT; // кВт

double ENGINE_GT_LEFT;
double ENGINE_GT_RIGHT;

double ENGINE_TGZ_LEFT;         // 0+900 град C
double ENGINE_TGZ_RIGHT;         // 0+900 град C

double ENGINE_MKR_LEFT; // крутящий момент H*m
double ENGINE_MKR_RIGHT; // крутящий момент H*m

double ENGINE_MKR_PERCENT_LEFT; // 0+120% Mk крутящий момент
double ENGINE_MKR_PERCENT_RIGHT; // 0+120% Mk крутящий момент
//
//------------Винт-----------------------------------------------------
//
double ENGINE_NBB_LEFT;    // 0+2400 обороты/мин
double ENGINE_NBB_RIGHT;    // 0+2400 обороты/мин

double ENGINE_NBB_ZAD_LEFT;    // 0+2400 обороты/мин
double ENGINE_NBB_ZAD_RIGHT;    // 0+2400 обороты/мин

double ENGINE_FIBB_LEFT;    // -25+80 угол установки лопастей
double ENGINE_FIBB_RIGHT;   // -25+80 угол установки лопастей

double ENGINE_MKRBB_LEFT; // крутящий момент винта H*m
double ENGINE_MKRBB_RIGHT; // крутящий момент винта H*m

double ENGINE_MKRBB_PERCENT_LEFT; // 0+120% Mk крутящий момент винта
double ENGINE_MKRBB_PERCENT_RIGHT; // 0+120% Mk крутящий момент винта

double ENGINE_NEBB_LEFT; // кВт
double ENGINE_NEBB_RIGHT; // кВт

double ENGINE_PBB_LEFT;    // тяга винта левого кг
double ENGINE_PBB_RIGHT;   // тяга винта правого кг

double ENGINE_PREACT_LEFT;    // тяга винта левого кг
double ENGINE_PREACT_RIGHT;   // тяга винта правого кг
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
double WING_TIP_TANK_FUEL_WEIGHT_LEFT; // 0+200 кг  масса топлива
double WING_TIP_TANK_FUEL_WEIGHT_RIGHT; // 0+200 кг  масса топлива

double WING_TANK_FUEL_WEIGHT_SUM_LEFT;       // 0+525 kg масса топлива
double WING_TANK_FUEL_WEIGHT_SUM_RIGHT;       // 0+525 kg масса топлива

double WING_TANK_FUEL_WEIGHT_SUMMARY;       // 0+525 kg масса топлива
//
//------------
double TEMP_AIR_CELS;
//-------
double M;

double V;
double VXY;

double VPR;   // 0+600 km/h
double VPR_RMI;   // 0+600 km/h

double VIST;   // 0+600 km/h
//-------
double H;  // -500+10000 m высота
double Hcm;  // -500+10000 m высота
double RMI_AGLH;  //  радиовысота 0+900 м

double VKYG_PR; //  -30+30 М/С вертикальная скорость
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
//
//------------
double Vxg_DISS;   // VXG_D
double VKYG;
double Vzg_DISS;
//
//------------IVO------------------------------------------------------
double Vxg_IVO;    // VXG_A
double VKYG_IVO;
double Vzg_IVO;

double XG_IVO;
double YG_IVO;
double ZG_IVO;
//------------INO------------------------------------------------------
double Vxg_INO;    //VXG_G
double VKYG_INO;
double Vzg_INO;

double XG_INO;
double YG_INO;
double ZG_INO;
//-------
double PSI_AIRFIELD_IK_GRAD;
//-------
double INO_HM;
//-------
double MAC;           //масса ЛА  кг

double XT_PERCENT;    //центровка, %
double XT;            //центровка, м
double DXT;
//-------
int FLIGHT_CYCLE_COUNT;

double FLIGHT_CYCLE_TIME;

int CYCLE_TIME;

int CYCLE_ETALON;
//-------
double VALUE_1;
double VALUE_2;
double VALUE_3;
double VALUE_4;
//-------
double AL_BALL;   // -1+1 угол скольжения (шарик)
double TURN_ANGLE; // -45 + 45 угол поворота
//
//------------Силы X---------------------------------------------------
//
double CX_SEMI;
double KCX;
double DCXZ;
double CXDRV;
double CXCY1;
double CXDINT;
double CXSHAS;
double CXBET;
double CXDRN;
double CXB_LEFT;
double CXB_RIGHT;
double CXZEM;
double KCXZEM;
double CX;

double X_AERO;
//-------
double X_SHAS_NOSE;
double X_SHAS_LEFT;
double X_SHAS_RIGHT;
double X_SHAS_SUM;
//-------
double X_SU_LEFT;
double X_SU_RIGHT;

double X_SU_SUM;
//-------
double X_SUM;
//
//------------CY-------------------------------------------------------
//
double CY_SEMI;
double CYALM;
double DCYZ;
double CYDRV;
double CYDINT;
double CYB_LEFT;
double CYB_RIGHT;
double CYZEM;
double KCYZEM;
double CYALT;
double KCYWZXT;
double KCYWZM;
double CY;
double CY1_SEMI;
double CY_CON;
double CY1;

double Y_AERO;
//-------
double Y_SHAS_NOSE;
double Y_SHAS_LEFT;
double Y_SHAS_RIGHT;
double Y_SHAS_SUM;
//-------
double Y_SU_LEFT;
double Y_SU_RIGHT;

double Y_SU_SUM;
//-------
double Y_SUM;
//
//------------CZ-------------------------------------------------------
//
double CZBET;
double CZDRN;
double CZDSCHT;
double CZWY;
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
double Z_SU_LEFT;
double Z_SU_RIGHT;

double Z_SU_SUM;
//-------
double Z_SUM;
//
//------------MX-------------------------------------------------------
//
double MX_SEMI;
double MXBET;
//-------
double MXDEL_LEFT;
double MXDEL_RIGHT;
double MXDEL;
//-------
double MXDRN;
double MXDSCHT;
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
double MX_ENGINE_LEFT;
double MX_ENGINE_RIGHT;

double MX_SU_SUM;
//------
double MX_CM;
//-------
double MX_SUM;
//
//------------MY-------------------------------------------------------
//
double MY_SEMI;
double MYBET;
double MYDRN;
double MYDSCHT;
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
double MY_ENGINE_LEFT;
double MY_ENGINE_RIGHT;

double MY_GYRO_LEFT;
double MY_GYRO_RIGHT;

double MY_SU_LEFT;
double MY_SU_RIGHT;

double MY_SU_SUM;
//-------
double MY_SUM;
//-------
double MY_CM;
//
//------------MZ-------------------------------------------------------
//
double MZALM;
double DMZ;
double MZDRV;
double MZDINT;
double MZSHAS;
double MZBET;
double MZB_LEFT;
double MZB_RIGHT;
double MZZEM;
double KMZZEM;
double MZWZ_LEFT;
double MZWZ_RIGHT;
double MZALT_LEFT;
double MZALT_RIGHT;
double MZ;
double MZ_DEMP;

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
double MZ_ENGINE_LEFT;
double MZ_ENGINE_RIGHT;

double MZ_GYRO_LEFT;
double MZ_GYRO_RIGHT;

double MZ_SU_LEFT;
double MZ_SU_RIGHT;
double MZ_SU_SUM;
//-------
double MZ_SUM;
//-------
double MZ_CM;
//
//------------Дискретные входные сигналы-------------------------------
//
bool PR_AUTO_FEATHER_SWITCH;

bool PR_MANUAL_FEATHER_PUSH_BUTTON_LEFT;
bool PR_MANUAL_FEATHER_PUSH_BUTTON_RIGHT;

bool PR_AUTOMAT_BANK_CONTROL_SWITCH;

bool PR_SPOILER_SWITCH;

bool PR_PARKING_BRAKE_CONTROL_LEVER;

bool PR_LANDING_GEAR_ACTUATOR_ON;
bool PR_LANDING_GEAR_ACTUATOR_OFF;

bool PR_NOSE_WHEEL_STEERING_MANUAL;
bool PR_NOSE_WHEEL_STEERING_PEDAL;

bool PR_FUEL_FIRE_COCK_OFF_LEFT;
bool PR_FUEL_FIRE_COCK_OFF_RIGHT;

bool PR_WING_FLAPS_ACTUATOR_0;
bool PR_WING_FLAPS_ACTUATOR_18;
bool PR_WING_FLAPS_ACTUATOR_42;

bool PR_DRY_MOTORING_RUN_BUTTON_LEFT;
bool PR_ENGINE_STARTING_BUTTON_LEFT;

bool PR_ENGINE_STARTING_BUTTON_RIGHT;
bool PR_DRY_MOTORING_RUN_BUTTON_RIGHT;

bool PR_WATER_INJECTION_BUTTON_ON;
bool PR_WATER_INJECTION_BUTTON_OFF;

bool PR_WATER_DRAIN_SWITCH;
//
//------------Топливная системв----------------------------------------
//
double EngineHourFuelConsumption_Left;      	 // часовой расход топлива левого двигателя
double EngineHourFuelConsumption_Right;     	 // часовой расход топлива правого двигателя

double EndTankFuelWeight_Left;                   // масса топлива в левом концевом баке
double EndTankFuelWeight_Right;                  // массо топлива в правом концевом баке

double WingFuelWeight_Left;                      // масса топлива в левых крыльевых баках (GTL)
double WingFuelWeight_Right;                     // масса топлива в правых крыльевых баках (GTP)

double SummaryTankFuelWeight_Left;
double SummaryTankFuelWeight_Right;

double SummaryTankFuelWeight;					 // суммарный остаток топлива

double WingGaugeDiskRotationSpeed_Left;          // скорость вращения диска топливомера левых крыльевых баков
double WingGaugeDiskRotationSpeed_Right;         // скорость вращения диска топливомера правых крыльевых баков

double EndTankGaugeDiskRotationSpeed_Left;       // скорость вращения диска топливомера левого концевого бака
double EndTankGaugeDiskRotationSpeed_Right;      // скорость вращения диска топливомера правого концевого бака
//------------Отказы---------------------------------------------------
bool FAULT_CloggingFilter_Left;                  //  #0     Срабатывание сигнала ЗАСОРЕНИЕ ФИЛЬТРА ДВИГ.ЛЕВ.
bool FAULT_CloggingFilter_Right;                 //  #1     Срабатывание сигнала ЗАСОРЕНИЕ ФИЛЬТРА ДВИГ.ПРАВ.
bool FAULT_FuelPump_Left;                        //  #2     Срабатывание сигнала ДАВЛ.ТОПЛИВА ДВИГ.ЛЕВ.
bool FAULT_FuelPump_Right;                       //  #3     Срабатывание сигнала ДАВЛ.ТОПЛИВА ДВИГ.ПРАВ.
bool FAULT_AutomaticPumping_Left;                //  #4     Отказ автоматической перекачки топлива
bool FAULT_AutomaticPumping_Right;               //  #5        при уменьшении уровня топлива в одной основной подсистеме до 400 кг
bool FAULT_SignalingMinFuelAmount_Left;          //  #6     Отказ сигнала табло МИН.ЗАПАС ТОПЛИВА
bool FAULT_SignalingMinFuelAmount_Right;         //  #7        при уменьшении запаса топлива ниже 108 кг
bool FAULT_FuelLeak_Left;                        //  #8     (УТЕЧКА) Образование топливного тумана за задней кромкой крыла
bool FAULT_FuelLeak_Right;                       //  #9       и более быстрое по сравнению с другой стороной изменение показаний топливомера
bool FAULT_WingFuelGauge_Left;                   //  #10   (ОТКАЗ ТОПЛИВОМЕРА) Застывание или быстрое
bool FAULT_WingFuelGauge_Right;                  //  #11       вращение контрольного диска
bool FAULT_EndTankFuelGauge_Left;                //  #12          в отверстии циферблата
bool FAULT_EndTankFuelGauge_Right;               //  #13             указателя топливомера
bool FAULT_FuelPumpingBoard_Left;                //  #14    Отказ табло ПЕРЕКАЧКА ТОПЛИВА ЛЕВ.
bool FAULT_FuelPumpingBoard_Right;               //  #15    Отказ табло ПЕРЕКАЧКА ТОПЛИВА ПРАВ.
//-------
//
//------------- Признаки ------------------------------------------------
//
bool PR_CraneBanding;                       	 // признак работы крана кольцевания (KK)
//-------------
bool PR_WingTransferPumpPressure_Left;           // признак давления за насосом перекачки крыл.баков лев. полусистемы (PPL)
bool PR_WingTransferPumpPressure_Right;          // признак давления за насосом перекачки крыл.баков прав. полусистемы (PPP)
//-------------
bool PR_WireVoltage_1493M;                   	 // признаки
bool PR_WireVoltage_1494M;                  	 //       наличия
bool PR_WireVoltage_1495M;                   	 //            напряжения
bool PR_WireVoltage_1496M;                   	 //                   на проводах
bool PR_WireVoltage_1497M;                   	 //                           (1493М...
bool PR_WireVoltage_1498M;                   	 //                               1498М)
//-------------
bool PR_WireVoltage_4107M;                   	 // признаки
bool PR_WireVoltage_4108M;                   	 //      наличия
bool PR_WireVoltage_4109M;                    	 //          напряжения
bool PR_WireVoltage_4110M;                   	 //                 на проводах
bool PR_WireVoltage_4111M;                   	 //                         (4107М...
bool PR_WireVoltage_4112M;                   	 //                             4112М)
//-------------
bool PR_RelayDelay_Left_M405;                    // признак задержки срабатывания реле M405
bool PR_RelayDelay_Right_M406;                   // признак задержки срабатывания реле М406
//-------------
bool PR_WireVoltage_256M;                        // признак наличия напряжения на проводе 256М
bool PR_WireVoltage_257M;                        // признак наличия напряжения на проводе 257М
//-------------
bool PR_EndTankFuelPumpOperation_Left_M419;      // признак работы топливного насоса левого концевого бака
bool PR_EndTankFuelPumpOperation_Right_M420;     // признак работы топливного насоса правого концевого бака
//-------------
bool PR_FuelPumpPressure_Left;                   // признак давления создаваемого насосом левого концевого бака
bool PR_FuelPumpPressure_Right;                  // признак давления создаваемого насосом правого концевого бака
//-------------
bool PR_FuelPumpOperation_Left_M121;             // признак работы топливного насоса левых крыльевых баков (М121)
bool PR_FuelPumpOperation_Right_M122;            // признак работы топливного насоса правых крыльевых баков (М122)
bool PR_WireVoltage_1228M;                       // признак наличия напряжения на проводе 1228М
bool PR_WireVoltage_1230M;                       // признак наличия напряжения на проводе 1230М
bool PR_AZS_M131;                                // признак АЗС "ТОПЛИВНЫЙ НАСОС ЛЕВ."
bool PR_AZS_M132;                                // признак АЗС "ТОПЛИВНЫЙ НАСОС ПРАВ."

bool PR_AZS_M135;                                // признак АЗС "КОЛЬЦЕВАНИЕ ТОПЛИВА" (М135)

bool PR_AZS_M401;                                // признак АЗС "КОНЦЕВОЙ БАК ЛЕВ."
bool PR_AZS_M402;                                // признак АЗС "КОНЦЕВОЙ БАК ПРАВ."

bool PR_Relay_M405;                              // признак работы реле M405
bool PR_Relay_M406;                              // признак работы реле M406
bool PR_Relay_M407;                              // признак работы реле M407
bool PR_Relay_M408;                              // признак работы реле M408
bool PR_Relay_M409;                              // признак работы реле M409
bool PR_Relay_M410;                              // признак работы реле M410

bool PR_WireVoltage_4002M;                       // признак наличия напряжения на проводе 4002М

bool PR_WireVoltage_739E;                        // признак наличия напряжения на проводе 739Е
bool PR_WireVoltage_740E;                        // признак наличия напряжения на проводе 740Е

bool PR_SwitchEndTankPumping_M403;               // признак Выкл. "ПЕРЕКАЧКА КОНЦ. БАКА ЛЕВ."
bool PR_SwitchEndTankPumping_M404;               // признак Выкл. "ПЕРЕКАЧКА КОНЦ. БАКА ПРАВ."

bool PR_AZS_Board_241;                           // признак АЗС "ТАБЛО СИГНАЛИЗАЦИИ ДВИГ. ЛЕВ."
bool PR_AZS_Board_242;                           // признак АЗС "ТАБЛО СИГНАЛИЗАЦИИ ПЛАНЕР"
bool PR_AZS_Board_244;                           // признак АЗС "ТАБЛО СИГНАЛИЗАЦИИ ДВИГ. ПРАВ."

bool PR_Board_282_1;                             // признак включения табло "КОЛЬЦЕВ.ТОПЛИВА"
bool PR_Board_282_5;                             // признак включения табло "ПЕРЕКАЧКА ТОПЛИВА ЛЕВ" (планер)
bool PR_Board_282_6;                             // признак включения табло "ПЕРЕКАЧКА ТОПЛИВА ПРАВ" (планер)
bool PR_Board_282_9;                             // признак включения табло "ВКЛЮЧИ ПЕРЕКАЧКУ" ЛЕВ (планер)
bool PR_Board_282_10;                            // признак включения табло "ВКЛЮЧИ ПЕРЕКАЧКУ" ПРАВ (планер)

bool PR_Board_281_3;                             // признак включения табло "ДАВЛ. ТОПЛИВА" (ДВИГ. ЛЕВ.)
bool PR_Board_281_4;                             // признак включения табло "МИН. ЗАПАС ТОПЛИВА" (ДВИГ. ЛЕВ.)
bool PR_Board_281_8;                             // признак включения табло "ЗАСОРЕНИЕ ФИЛЬТРА" (ДВИГ. ЛЕВ.)

bool PR_Board_284_3;                             // признак включения табло "ДАВЛ. ТОПЛИВА" (ДВИГ. ПРАВ.)
bool PR_Board_284_4;                             // признак включения табло "МИН. ЗАПАС ТОПЛИВА" (ДВИГ. ПРАВ.)
bool PR_Board_284_8;                             // признак включения табло "ЗАСОРЕНИЕ ФИЛЬТРА" (ДВИГ. ПРАВ.)
//===========================================================================================================
//автоном для навигации
double NAV_avtVg   [2];//avtonom Vx Vz
double NAV_avtVgy     ;//avtonom Vy
double NAV_avtAngl [3];//avtonom  PSI,Kren,Tang
bool   NAV_bAvt       ; //pr avtonom

//
//-------
} SHMNTR_410;

#pragma pack(pop)


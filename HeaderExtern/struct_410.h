// ==========================================
// ===== data structures for T01 L410   =====
// ==========================================
#define T_410_MAX_PO_NEAREST_COUNTER 8
#define T_410_MAX_PO_SCAN_FULL_COUNTER 64

struct descr_sm2_410_begin
  {unsigned short first;                   // 0       // == 0x00FF ?????????????
   unsigned short length;				   // 1 
   unsigned long  time_send;			   // 2 
   unsigned long  time_received;		   // 3 
   unsigned long  counter;				   // 4 
   };									 
struct descr_sm2_410_head
  {
	  unsigned short head_10;             // 0              // ID = 0x0010
      unsigned short priznak;             // 1              // =0 - day; =1 - night; =2 - dust 1; =3 - dust 2; =4 - dust 3;
      unsigned short year_time;           // 2              // =0 - summer; =1 - winter;
      unsigned short base_number;         // 3              // =0 - AER1(Balasev); =1 - AER2(Rtihevo); =2 - AER3(Borisoglebsk);      //1
      float sky_down;				      // 4       
      float sky_up;					      // 5       
      float distance;				      // 6       
      float runway_height;                // 7           // runway height above sea level FROM NAVIGATION
      float runway_ik_rads;               // 8           // ÈÊ main runway RADIANS
      float longitude;                    // 9           // äîëãîòà DEGREES
      float lattitude;                    // 10          // øèğîòà  DEGREES
      float wind_speed;                   // 11          // m/Sec
      float wind_ik;                      // 12          // RAD
      short cloud_difficulty;		      // 13      
      short back_runway_flag;             // 14                                                                        //2
      float layer_up_2;                   // 15         //   water snow on runway
      float layer_down_2;                 // 16         // down: fires visibility coeff
      float layer_complex;                // 17         // complexity: fires size coeff;
      float wind_speed_m_sec;		      // 18      
      float win_ik_radians;			      // 19      
      float weight;                       // 20                                                                         //3
      unsigned short stop_flag;           // 21                                                                          //4
      unsigned short channel_mask;        // 22  0 ğàçğÿä (0x0001) - âûêëş÷åíèå ëåâîãî êàíàëà
      unsigned short shutdown_flag;        // 23  âûêëş÷åíèå
      unsigned short res[7];              // 24-30
    };

struct descr_sm2_410_dynamic
{
		unsigned short head_12;       // 0       ID = 0x0012
		unsigned short mode;          // 1      
		float DRV;					  // 2      /rul H
		float DEL_LEFT;				  // 3      /eler L
		float DEL_RIGHT;			  // 4      /eler R
		float DRN;					  // 5      /rul napravlen
		float WING_FLAPS_ANGLE;		  // 6      /zakrilki
		float SPOILER_ANGLE;		  // 7      /interseptor
		float SCHT_ANGLE_LF;		  // 8      /shitok avtomat kren ëåâûé
		float FINW;					  // 9      /angle nos koleso
		float AL_RUD_LEFT;			  // 10     
		float AL_RUD_RIGHT;			  // 11     
		float AL_RUB_LEFT;			  // 12     //rihag upravl vint left
		float AL_RUB_RIGHT;			  // 13     //rihag upravl vint r
		float AL_STOP_LEFT;			  // 14     //angle upravl stop-kran l
		float AL_STOP_RIGHT;		  // 15     //angle upravl stop-kran r
		float ELEVATOR_TRIM_ANGLE;	  // 16     //trimer rul H
		float AILERON_TRIM_ANGLE;	  // 17     //trimer eleron
		float RUDDER_TRIM_ANGLE;	  // 18     //trimer rul napravlen
		float LEFT_SHASSI_STATE;     // 19      // ïîëîæåíèå ëåâîé ñòîéêè øàññè
		float RIGHT_SHASSI_STATE;    // 20      // ïîëîæåíèå ïğàâîé ñòîéêè øàññè
		float BRAKE_PRESSURE_LEFT;	  // 21     //davlen tormoz l
		float BRAKE_PRESSURE_RIGHT;	  // 22     //davlen tormoz r
		float NGG_LEFT;				  // 23     //oborot gazogen l ( %)
		float NGG_RIGHT;			  // 24     //oborot gazogen r (%)
		float NBB_LEFT;				  // 25     //oborot vinta l (ob/min)
		float NBB_RIGHT;			  // 26     //oborot vinta r (ob/min)
		float MKR_LEFT;				  // 27     //krut moment left Dvig(%)
		float MKR_RIGHT;			  // 28     //krut moment r Dvig(%)
		float PBB_LEFT;				  // 29     //tiaga left (kg)
		float PBB_RIGHT;              // 30     //tiaga r (kg)            //
		float FIBB_LEFT;			  // 31     //angle lopast left vint (grad)
		float FIBB_RIGHT;			  // 32     //angle lopast r vint (grad)
		float TGZ_LEFT;				  // 33     //T gaz l (C)
		float TGZ_RIGHT;			  // 34     //T gaz r (C)
		float FUEL_PRESSURE_LEFT;	  // 35     
		float FUEL_PRESSURE_RIGHT;	  // 36     
		float OIL_PRESSURE_LEFT;	  // 37     
		float OIL_PRESSURE_RIGHT;	  // 38     
		float OIL_TEMPERATURE_LEFT;	  // 39     
		float OIL_TEMPERATURE_RIGHT;  // 40     
		float WING_TANK_FUEL_LEFT;    // 41     //topliv0 in Left wing (kg)
		float WING_TANK_FUEL_RIGHT;   // 42     //topliv0 in R wing (kg)
		float MAC;                    // 43     //massa LA(kg)
		float XT;                     // 44     //centrovka(%)
	    float SCHT_ANGLE_RT;		  // 8      /shitok avtomat kren ïğàâûé
	    float NOSE_SHASSI_STATE;		  // 8      /shitok avtomat kren ïğàâûé
//-------								        
	    float res[3];                 // 45-49
	    float res_U[24];               // 50-73
};
///////////////////////////////////////////////////////////////////////////////////
     //------------Àíàëîãîâûå âõîäíûå ñèãíàëû-------------------------------
	 //res_U[0]=U_CONTROL_STICK; // øòóğâàëüíàÿ êîëîíêà
	 //res_U[1]=U_STEERING_WHEEL; // øòóğâàë
	 //res_U[2]=U_PEDAL; // ïåäàëè
	 //res_U[3]=U_PILOT_BRAKE_PEDAL_LEFT; //ëåâàÿ ïîäíîæêà ëåâîãî ïóëüòà
	 //res_U[4]=U_PILOT_BRAKE_PEDAL_RIGHT; //ïğàâàÿ ïîäíîæêà ëåâîãî ïóëüòà
	 //res_U[5]=U_CO_PILOT_BRAKE_PEDAL_LEFT; //ëåâàÿ ïîäíîæêà ïğàâîãî ïóëüòà
	 //res_U[6]=U_CO_PILOT_BRAKE_PEDAL_RIGHT; //ïğàâàÿ ïîäíîæêà ïğàâîãî ïóëüòà
	 //res_U[7]=U_ELEVATOR_TRIM_HAND_WHEEL; // òğèììåğ ğóëÿ âûñîòû
	 //res_U[8]=U_NOSE_LANDING_GEAR_STEERING_WHEEL; //ğóêîÿòêà íîñîâîãî êîëåñà
	 //res_U[9]=U_EMERGENCY_HYDRAULIC_PUMP_LEVER; //ğó÷íàÿ ïîìïà
	 // //--------Öåíòğàëüíûé ïóëüò----------------------------------------
	 //res_U[10]=U_THROTTLE_CONTROL_LEVER_LEFT; //ĞÓÄ ëåâûé
	 //res_U[11]=U_THROTTLE_CONTROL_LEVER_RIGHT; //ĞÓÄ ïğàâûé
	 //res_U[12]=U_PROPELLER_CONTROL_LEVER_LEFT; //ĞÓÂ ëåâûé
	 //res_U[13]=U_PROPELLER_CONTROL_LEVER_RIGHT; //ĞÓÂ ïğàâûé
	 //res_U[14]=U_EMERGENCY_THROTTLE_LEVER_LEFT; //Ñòîï-êğàí ëåâûé
	 //res_U[15]=U_EMERGENCY_THROTTLE_LEVER_RIGHT; //Ñòîï-êğàí ïğàâûé
	 // //--------Çàãğóæàòåëè----------------------------------------------
	 //res_U[16]=U_FORCE_PEDAL; //Çàãğóæàòåëü ïåäàëåé
	 //res_U[17]=U_FORCE_CONTROL_STICK; //Çàãğóæàòåëü øòóğâàëüíîé êîëîíêè
	 //res_U[18]=U_FORCE_STEERING_WHEEL; //Çàãğóæàòåëü øòóğâàëà
  //   res_U[19]=U_FORCE_ELEVATOR_TRIM; //Òğèììåğ ğóëÿ âûñîòû
/////////////////////////////////////////////////////////////////////////////////
struct descr_sm2_410_time
  {unsigned short head_14;             // 0      // ID = 0x0014
   unsigned short res1;      		   // 1 
   unsigned char day;                  // 2      // 1...
   unsigned char mon;                  // 3      // 1...
   unsigned char year;                 // 4      // from 1900
   unsigned char hour;                 // 5      // 0
   unsigned char min;                  // 6      // 0
   unsigned char recalc_flag;          // 7      // != 0: recalculate time of day
   unsigned short skin_type;		   // 8 
   };								    
									  

   // --- switches COMMON ---
//       0  //sw1                                      // - begin conditions 
//       1                                             // - fires RD         
//       2                                             //        "on sides"  
//       3                                             //        "on center" 
//       4                                             //        "forward"   
//       5                                             //        "backward"  
//       6                                             //        "thunder"   
//       7                                             //        "impulse"   
//       8                                             //  bright  "20%"     
//       9                                             //          "30%"     
//      10                                             //          "50%"     
//      11                                             //          "75%"     
//      12                                             //          "90%"     
//      13                                             //         "100%"     
//      14                                             //  land deny         
//      15                                             //  land permission   
//      0  // sw2                                      //      
//      1                                              //   
//      2                                              //  
//      3                                              // 
//      4                                              // 
//      5                                              // 
//      6                                              //
//      7                                              //
//      8                                              //  
//      9                                              //snow         
//     10                                              //rain  
//     11                                              //rain reset([10]=1 or [9]=1)
//     12                                              //large fires
//     13                                              //small fires
//     14                                              //reserved
//     15                                              //projectors on runway
//  go[0]//sw3 bool PR_FUEL_FIRE_COCK_OFF_LEFT;        // òîïë.êğàí ëåâ.
//  go[1]      bool PR_FUEL_FIRE_COCK_OFF_RIGHT;       //òîïë.êğàí ïğàâ.
//  go[2]      bool PR_TOUCH_DOWN_NOSE;                //êàñàí.íîñ êîëåñà íà áåòîí
//  go[3]      bool PR_TOUCH_DOWN_LEFT;                //êàñàí.ëåâîãî êîëåñà íà áåòîí
//  go[4]      bool PR_TOUCH_DOWN_RIGHT;               //êàñàí.ïğàâ. êîëåñà íà áåòîí
//  go[5]      bool PR_TOUCH_DOWN_GROUND_RUNWAY_NOSE;  //êàñàí.íîñ êîëåñà ãğóíò 
//  go[6]      bool PR_TOUCH_DOWN_GROUND_RUNWAY_LEFT;  //êàñàí.ëåâîãî êîëåñà ãğóíò
//  go[7]      bool PR_TOUCH_DOWN_GROUND_RUNWAY_RIGHT; //êàñàí.ïğàâ. êîëåñà ãğóíò
//  go[8]      bool PR_FUSELAGE_LANDING;               //ïîñàäêà íà ôşçåëÿæ
//  go[9]      bool PR_TOUCH_DOWN_WING_LEFT;           //êàñàí. êğûëà ëåâ.
//  go[10]     bool PR_TOUCH_DOWN_WING_RIGHT;          //êàñàí. êğûëà ïğàâ.
//  go[11]     bool PR_TAIL_LANDING;                   //êàñàí. õâîñò
//  go[12]     bool PR_TIRE_BURST_NOSE;                //ğàçğûâ íîñ êîëåñà
//  go[13]     bool PR_TIRE_BURST_LEFT;                //ğàçğûâ ëåâ êîëåñà
//  go[14]     bool PR_TIRE_BURST_RIGHT;               //ğàçğûâ ïğàâ êîëåñà
//  go[15]     bool PR_ENGINE_FUEL_BURN_LEFT;          //ïğèçíàê ãîğåíèÿ òîïëèâà â ëåâîì äâèã.
//  go[0]//sw4 bool PR_ENGINE_FUEL_BURN_RIGHT;         //ïğèçíàê ãîğåíèÿ òîïëèâà â ïğàâîì äâèã.
//  go[1]      bool PR_SHASSI_ACTUATION_NOSE;          //ïğèçíàê ïğîöåññà âûïóñêà\óáîğêè íîñîâîãî øàññè
//  go[2]      bool PR_SHASSI_ACTUATION_LEFT;          //ïğèçíàê ïğîöåññà âûïóñêà\óáîğêè ëåâ øàññè
//  go[3]      bool PR_SHASSI_ACTUATION_RIGHT;         //ïğèçíàê ïğîöåññà âûïóñêà\óáîğêè ïğàâ øàññè
//  go[4]      bool PR_SHASSI_LOCK_OFF_NOSE;           //ïğèçíàê ñğàáàòûâàíèÿ çàìêà óáğàííîãî ïîëîæåíèÿ  íîñîâîãî øàññè
//  go[5]      bool PR_SHASSI_LOCK_OFF_LEFT;           //ïğèçíàê ñğàáàòûâàíèÿ çàìêà óáğàííîãî ïîëîæåíèÿ  ëåâ øàññè
//  go[6]      bool PR_SHASSI_LOCK_OFF_RIGHT;          //ïğèçíàê ñğàáàòûâàíèÿ çàìêà óáğàííîãî ïîëîæåíèÿ ïğàâ  øàññè
//  go[7]      bool PR_SHASSI_LOCK_ON_NOSE;            //ïğèçíàê ñğàáàòûâàíèÿ çàìêà âûïóùåííîãî ïîëîæåíèÿ  íîñîâîãî øàññè
//  go[8]      bool PR_SHASSI_LOCK_ON_LEFT;			   //ïğèçíàê ñğàáàòûâàíèÿ çàìêà âûïóùåííîãî ïîëîæåíèÿ  ëåâ øàññè
//  go[9]      bool PR_SHASSI_LOCK_ON_RIGHT;		   //ïğèçíàê ñğàáàòûâàíèÿ çàìêà âûïóùåííîãî ïîëîæåíèÿ ïğàâ  øàññè
//  go[10]             
//  go[11]             
//  go[12]             
//  go[13]             
//  go[14]             
//  go[15]                                                                              
//  go[0] //sw5    bool Otkaz[100];        ÎÒÊÀÇÛ :    0 = ÎÁÎĞÎÒÛ ÂÈÍÒÀ ËÅÂ.                        
//  go[1]              								   1 = ÎÑÒÀÍÎÂ ÄÂÈÃÀÒÅËß ËÅÂ.
//  go[2]              								   2 = ĞÀÑÊĞ. ÂÈÍÒÀ ËÅÂ.
//  go[3]              								   3 = ÇÀÂÈÑÀÍÈÅ ÎÁÎĞÎÒÎÂ ËÅÂ.
//  go[4]              								   4 = ÄÀÂËÅÍÈÅ ÌÀÑËÀ ËÅÂ.
//  go[5]              								   5 = ÒÅÌÏÅĞÀÒÓĞÀ ÌÀÑËÀ ËÅÂ.
//  go[6]              								   6 = ÔËŞÃÈĞÎÂÀÍÈÅ ËÅÂ.
//  go[7]              								   7 = ÄÀÂËÅÍÈÅ ÒÎÏËÈÂÀ ËÅÂ.
//  go[8]              								   8 = ĞÀÑÕÎÄ ÒÎÏËÈÂÀ ËÅÂ.
//  go[9]              								   9 = ÒÌÒ ËÅÂ.
//  go[10]             								   10 = ÖİÁÎ ËÅÂ.
//  go[11]             								   11 = ÖÈÊË. ÓÑÒĞ. ÂÈÍÒÀ
//  go[12]             								   12 = ÎÁÎĞÎÒÛ ÂÈÍÒÀ ÏĞÀÂ.
//  go[13]             								   13 = ÎÑÒÀÍÎÂ ÄÂÈÃÀÒÅËß ÏĞÀÂ.
//  go[14]             								   14 = ĞÀÑÊĞ. ÂÈÍÒÀ ÏĞÀÂ.
//  go[15]             								   15 = ÇÀÂÈÑÀÍÈÅ ÎÁÎĞÎÒÎÂ ÏĞÀÂ.
//  go[0] //sw6										   16 = ÄÀÂËÅÍÈÅ ÌÀÑËÀ ÏĞÀÂ.
//  go[1] 											   17 = ÒÅÌÏÅĞÀÒÓĞÀ ÌÀÑËÀ ÏĞÀÂ.
//  go[2] 											   18 = ÔËŞÃÈĞÎÂÀÍÈÅ ÏĞÀÂ.
//  go[3] 											   19 = ÄÀÂËÅÍÈÅ ÒÎÏËÈÂÀ ÏĞÀÂ.
//  go[4] 											   20 = ĞÀÑÕÎÄ ÒÎÏËÈÂÀ ÏĞÀÂ.
//  go[5] 											   21 = ÒÌÒ ÏĞÀÂ.
//  go[6] 											   22 = ÖİÁÎ ÏĞÀÂ.
//  go[7] 											   23 = ÓÊÀÇÀÒÅËÜ ÌÊ ËÅÂ.
//  go[8] 											   24 = ÓÊÀÇÀÒÅËÜ ÌÊ ÏĞÀÂ.
//  go[9] 											   25 = ÃÌÊ
//  go[10]											   26 = ĞÂ
//  go[11]											   27 = ÀĞÊ
//  go[12]											   28 = ÑÏ-50
//  go[13]											   29 = ÌĞÏ ÇÂÓÊ.
//  go[14]											   30 = ÌĞÏ ÑÂÅÒ.
//  go[15]											   31 = ÓÊÂ I
//  go[0]//sw7 										   32 = ÑÏÓ I
//  go[1] 											   33 = ÒĞÈÌ İËÅĞ. ÑÒÎÏ
//  go[2] 											   34 = ÒĞÈÌ İËÅĞ. L
//  go[3] 											   35 = ÒĞÈÌ İËÅĞ. R
//  go[4] 											   36 = ÇÀÊĞÛËÊÈ
//  go[5] 											   37 = ÒĞÈÌ Ğ. ÍÀÏĞ. ÑÒÎÏ
//  go[6] 											   38 = ÒĞÈÌ Ğ. ÍÀÏĞ. L
//  go[7] 											   39 = ÒĞÈÌ Ğ. ÍÀÏĞ. R
//  go[8] 											   40 = ØÀÑÑÈ
//  go[9] 											   41 = ÏÎÆÀĞ ËÅÂ.
//  go[10]											   42 = ÏÎÆÀĞ ÏĞÀÂ.
//  go[11]											   43 = ÏÎÆÀĞ ÁÀÃÀÆ.
//  go[12]											   44 = ÎÁËÅÄÅÍÅÍÈÅ
//  go[13]											   45 = ÑÒÀÒÈ×ÅÑÊÎÅ ÄÀÂËÅÍÈÅ
//  go[14]											   46 = ÎÁÙÅÅ ÄÀÂËÅÍÈÅ
//  go[15]											   47 = ÇÀÏÀÑÍÎÉ ÀÃÄ ÑÒÎÏ
//  go[0]//sw8 										   48 = òàíãàæ ÑÒÎÏ (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[1] 											   49 = òàíãàæ 0.2° ÊÀÁĞÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[2] 											   50 = òàíãàæ 1.5° ÊÀÁĞÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[3] 											   51 = òàíãàæ 5° ÊÀÁĞÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[4] 											   52 = òàíãàæ 0.2° ÏÈÊÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[5] 											   53 = òàíãàæ 1.5° ÏÈÊÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[6] 											   54 = òàíãàæ 5° ÏÈÊÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[7] 											   55 = êğåí ÑÒÎÏ (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[8] 											   56 = êğåí 0.2° ËÅÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[9] 											   57 = êğåí 1.5° ËÅÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[10]											   58 = êğåí 5° ËÅÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[11]											   59 = êğåí 0.2° ÏĞÀÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[12]											   60 = êğåí 1.5° ÏĞÀÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[13]											   61 = êğåí 5° ÏĞÀÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ËÅÂ.)
//  go[14]											   62 = òàíãàæ ÑÒÎÏ (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[15]											   63 = òàíãàæ 0.2° ÊÀÁĞÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[0]//sw9 										   64 = òàíãàæ 1.5° ÊÀÁĞÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[1] 											   65 = òàíãàæ 5° ÊÀÁĞÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[2] 											   66 = òàíãàæ 0.2° ÏÈÊÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[3] 											   67 = òàíãàæ 1.5° ÏÈÊÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[4] 											   68 = òàíãàæ 5° ÏÈÊÈĞ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[5] 											   69 = êğåí ÑÒÎÏ (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[6] 											   70 = êğåí 0.2° ËÅÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[7] 											   71 = êğåí 1.5° ËÅÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[8] 											   72 = êğåí 5° ËÅÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[9] 											   73 = êğåí 0.2° ÏĞÀÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[10]											   74 = êğåí 1.5° ÏĞÀÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[11]											   75 = êğåí 5° ÏĞÀÂ. (ÓÕÎÄ ÀÂÈÀÃÎĞÈÇÎÍÒÀ ÏĞÀÂ.)
//  go[12]											   76 = ÊÇ ÃØ
//  go[13]											   77 = ÃÅÍÅĞÀÒÎĞ
//  go[14]											   78 = ÃÈÄĞÎÑÈÑÒÅÌÀ
//  go[15]											   79 = ÏĞÅÎÁĞÀÇÎÂÀÒÅËÜ 36Â
//  go[0]//sw10 									   80 = ÏĞÅÎÁĞÀÇÎÂÀÒÅËÜ 115Â
//  go[1]         
//  go[2] 			
//  go[3] 			
//  go[4] 			
//  go[5] 			
//  go[6] 			
//  go[7] 			
//  go[8] 			
//  go[9] 			                                   
//  go[10]			                                  //ïğèçíàê ïğîëåòà äàëüíåãî ìàğêåğà 	
//  go[11]			                                  //ïğèçíàê ïğîëåòà ñğåäíåãî ìàğêåğà	 	
//  go[12]			                                  //ïğèçíàê ïğîëåòà áëèæíåãî ìàğêåğà	 
//  go[13]			                                  //ïğèçíàê ôàğà áëèæíèé ñâåò		 
//  go[14]			                                  //ïğèçíàê ôàğà äàëüíèé ñâåò		 
//  go[15]											  //ïğèçíàê  ôàğà 	âûêë	
//  go[0]//sw11 		 bool  Avaria[19];             // 0 - ÂÍÅ ÂÏÏ
//  go[1] 											   // 1 - ÁÅÇ ØÀÑÑÈ
//  go[2] 											   // 2 - ÁÎËÜØÎÅ ÏËÀÍÈĞ.
//  go[3] 											   // 3 - ÓÄÀĞ ÊĞÛËÎÌ
//  go[4] 											   // 4 - ÓÄÀĞ ÕÂÎÑÒÎÌ
//  go[5] 											   // 5 - ÁÎËÜØÎÉ ÂÅÑ
//  go[6] 											   // 6 - ÎÁÍÓË. ÀÂÀĞÈÈ
//  go[7] 											   // 7 - ÂÛÊËŞ×. ÖÂÌ
//  go[8] 											   // 8 - ÀÂÀĞÈß
//  go[9] 											   // 9 - ÁÎËÜØÀß ÑÊÎĞÎÑÒÜ
//  go[10]											   // 10 - ÁÎËÜØÀß ÑÊÎĞ. Ñ ØÀÑÑÈ
//  go[11]											   // 11 - ÁÎËÜØÀß ÑÊÎĞ. Ñ ÇÀÊĞ.
//  go[12]											   // 12 - G > 5700 ÊÃ
//  go[13]											   // 13 - ÒÌÒ ËÅÂ.
//  go[14]											   // 14 - ÒÌÒ ÏĞÀÂ.
//  go[15]											   // 15 - ÂÈÍÒ ËÅÂ.
//  go[0]//sw12 									   // 16 - ÂÈÍÒ ÏĞÀÂ.
//  go[1] 											   // 17 - ÂÎÄÀ
//  go[2] 											   // 18 - ÏÍÅÂÌ.
//  go[3] 		
//  go[4] 
//  go[5] 
//  go[6] 
//  go[7] 
//  go[8] 
//  go[9] 
//  go[10]
//  go[11]
//  go[12]
//  go[13]
//  go[14]
//  go[15]

struct descr_sm2_410_switches
  {unsigned short head_20;        // 0                       // ID = 0x0020
   unsigned short res;			  // 1 
   unsigned short sw1;			  // 2 
   unsigned short sw2;			  // 3 
   unsigned short sw3;			  // 4 
   unsigned short sw4;			  // 5 
   unsigned short sw5;			  // 6 
   unsigned short sw6;			  // 7 
   unsigned short sw7;			  // 8 
   unsigned short sw8;			  // 9 
   unsigned short sw9;			  // 10
   unsigned short sw10;			  // 11
   unsigned short sw11;			  // 12
   unsigned short sw12;			  // 13
   };

struct descr_sm2_410_la
  {unsigned short head_30;      // 0                       // ID = 0x0030
   unsigned short res;		    // 1                         
   float Xla[3];                // 2 3 4                   // coords        M  !!! Y:above sea level      !!!
   float Ala[3];                // 5 6 7                   // angles        RAD!!! without LA_ABOVE_PLACE !!!
   float dXla[3];               // 8 9 10                  // coords      M/Sec
   float dAla[3];               // 11 12 13                // angles      PAD/Sec
   float Vprib;                 // 14                      //ñêîğîñòü ïğèáîğíàÿ  êì\÷
   float Alfa;                  // 15                      //óãîë àòàêè         grad
   float Beta;                  // 16                      //óãîë ñêîëüæåíèÿ    grad
   float Nx;                    // 17                      //ïåğåãğóçêà 
   float Ny; 					// 18
   float Nz;                    // 19       
   double lat;                   // 20                      //ãåîãğ. øèğîòà       grad
   double lon;                   // 21                      //ãåîãğ. äîëãîòà      grad
   float  IK_rad;                // 22                      //IK rad
   float res1[3];               // 23-25
   };							
								
struct descr_sm2_410_end		
  {unsigned short control;     // 0                        // = 0x8001
   unsigned short last;        // 1                        // = 0xFF00
   unsigned short res[2];	   // 2 3 
   };


// ===============================
// =====   main data block   =====
// ===============================
struct extern_sm2_410_array
  {struct descr_sm2_410_begin     begin;
   struct descr_sm2_410_head      head;
   struct descr_sm2_410_dynamic   dynamic;
   struct descr_sm2_410_time      time;
   struct descr_sm2_410_switches  switches;
   struct descr_sm2_410_la        la;
   struct descr_sm2_410_end       end;
   };






// ================================
// =====     back packet       ====
// ================================
struct descr_back_sm2_410_block
   {unsigned short first;        // == 0xFF00
    unsigned short length;       // in bytes
    float height;                // rel height above sea level ?????
    unsigned short last;         // == 0x00FF
    unsigned short cycle_counter;      // alive
    };


// ========= reference reference =========

union extern_sm2_410_pointer
  {unsigned short             *ptr_ushort;
   unsigned char              *ptr_uchar;
   struct descr_sm2_410_begin     *ptr_begin;
   struct descr_sm2_410_head      *ptr_head;
   struct descr_sm2_410_time      *ptr_time;
   struct descr_sm2_410_switches  *ptr_switches;
   struct descr_sm2_410_dynamic   *ptr_dynamic;
   struct descr_sm2_410_la        *ptr_la;
   struct descr_sm2_410_end       *ptr_end;
   struct descr_back_sm2_410_block   *ptr_back_sm2;
   };


// ========= reference reference =========

union extern_rmi_410_pointer
  {unsigned short               *ptr_ushort;
   unsigned char                *ptr_uchar;
   struct descr_rmi_410_begin   *ptr_rmi_begin;
   struct descr_rmi_410_digital *ptr_rmi_digital;
   struct descr_rmi_410_analog  *ptr_rmi_analog;
   struct descr_rmi_410_end     *ptr_rmi_end;
   struct descr_back_rmi_410_block  *ptr_rmi_back;
   };

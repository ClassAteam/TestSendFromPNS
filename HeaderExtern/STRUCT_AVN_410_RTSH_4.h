// "STRUCT_AVN_410" - memory name
//15.03.2021 –тищево-4
#include "Main_struct_cabine.h"//kabin prib
#include "Struct_prib410.h"    //pribor RMI, Radio,SOUND
#include "STRUCT_MNTR_410.h"   //monitor
#include "STRUCT_CMF_410.h"
#include "Main_struct_IBKO.h"
#include "StructCan.h"

#pragma pack(push, 1)


typedef struct
{
   SHMNTR_410				MNTR;
   SHCOMMON_STRUCT			COM;
   SHMAIN_STRUCT_CABINE		CAB;
   SHMAIN_STRUCT_CABINE_OUT CAB_OUT;
   SHCMF_410				CMF;
   SHMAIN_STRUCT_IN			IBKO;
   SHMAIN_STRUCT_OUT		IBKO_OUT;
   StructCan				CAN;
//-------
	bool PCIE_1680_E1_1[112]; // CAN BID#0
//-------
	bool PCIE_1754_E1_2[64]; // Input BID#0
	bool PCIE_1754_E1_3[64]; // Input BID#1
//-------
	bool PCIE_1758_E1_4[106]; // OUT BID#0
//-------
	double PCIE_1805_E1_5[25]; // Input BID#0
	double PCIE_1805_E1_6[9];  // Input BID#1
//-------
} SHAVN_410;

#pragma pack(pop)

extern SHAVN_410 *AVN_410;


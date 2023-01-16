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
//
//------------CARD_CAN
//
bool PCIE_1680_E1_9[112]; // CAN BID#0
//
//------------CARD_AI
//
bool PR_Ready_PCI_AI[2];

bool PR_Data_PCI_AI_Failure[2];

bool PR_Overrun_PCI_AI[2];
//-------
double PCI_1747_E1_6[24];

double PCI_1715_E1_7[3];
//
//------------CARD_AO
//
bool PR_Ready_PCI_AO[1];

bool PR_Data_PCI_AO_Failure[1];
//-------
double PCI_1720_E1_8[1];
//
//------------CARD_DI
//
bool PR_Ready_PCI_DI[4];

bool PR_Data_PCI_DI_Failure[4];
//-------
bool PCI_1754_E1_1[64];

bool PCI_1754_E1_2[64];

bool PCI_1754_E1_3[64];

bool PCI_1754_E1_4[64];
//
//------------CARD_DO
//
bool PR_Ready_PCI_DO[1];

bool PR_Data_PCI_DO_Failure[1];
//-------
bool PCI_1758_E1_5[96];
//
//------------
//
bool PR_Ready_Net_fromIDP;

double fromIDP_Net_CycleTime;
//-------
bool PR_AllProgramClose;
//-------
} SHAVN_410;

#pragma pack(pop)

extern SHAVN_410 *AVN_410;


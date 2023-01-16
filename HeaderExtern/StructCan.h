/*
==========================================================================
   СТРУКТУРА КАН
===========================================================================
*/

#pragma pack( push, 1 )

typedef struct {
	bool				buttons[12];			// From CAN   состояние кнопок СО2010
	int					enteredCodeA;			// From CAN   введный код А
} FromCan;

typedef struct {
	int					displayedCode;			// TO CAN     отображаемый код
	int 				message;				// TO CAN     сообщение, отправляемое и отображаемое на СО2010
	double              ark_Freq;               // TO CAN    
	double              KompasKurs;             // TO CAN
	double              Sharik;                 // TO CAN
} ToCan;


typedef struct {

FromCan  fromCan;
ToCan    toCan  ;

} StructCan;

#pragma pack( pop )
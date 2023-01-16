/*
===========================================================================

... для описания ...

===========================================================================
*/

#pragma pack( push, 1 )

// подструктура СО2010
typedef struct {
	bool				buttons[12];			// From CAN   состояние кнопок СО2010
	int					enteredCodeA;			// From CAN   введный код А
	int					codeA;					// JOB SRO     код режима А 
	int					codeFID;				// JOB SRO      код режима FID
	int					enteredCodeFID;			// From CAN    NO RELEASE!!!            введенный код FID
	int					codePVP;				// JOB SRO    код режима PVP
	int					displayedCode;			// TO CAN     отображаемый код
	int 				message;				// TO CAN     сообщение, отправляемое и отображаемое на СО2010
} soStruct_t;

#pragma pack( pop )
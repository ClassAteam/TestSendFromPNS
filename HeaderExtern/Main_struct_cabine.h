// ��������� �������� �������� L-410 (������ - ��������������� �������)
// ������������ ������� ������: Struct_L410_Cabine
// ������������ ������� ������: Struct_L410_Cabine_OUT
#ifndef _MAINSTRUCT_CABINE_H
#define _MAINSTRUCT_CABINE_H

#pragma pack(push, 1)

//-----------------------------------------------
// ��������� �������� ����� LUN 1348 (����� ���������)
typedef struct
{
 double fOborot;       // 0+2500 ��//���
}SHLUN1348_LEFT_IN;

//-----------------------------------------------
// ��������� �������� ����� LUN 1348 (������ ���������)
typedef struct
{
 double fOborot;       // 0+2500 ��//���
}SHLUN1348_RIGHT_IN;

//-----------------------------------------------
// ��������� ��������� ������� LUN-1539-02.8 (����� ���������)
typedef struct
{
 bool   blenker;     // ������� ������ 0=yes
 double fMk;         // 0+120% Mk �������� ������
}SHLUN1539_LEFT_IN;

//-----------------------------------------------
// ��������� ��������� ������� LUN-1539-02.8 (������ ���������)
typedef struct
{
 bool   blenker;      // ������� ������ 0=yes
 double fMk;          // 0+120% Mk �������� ������
}SHLUN1539_RIGHT_IN;

//-----------------------------------------------
//��������� ������������� LUN1687-8
typedef struct
{
 double Trim;   // -10+10 grad
}SHLUN1687_IN;  

//-----------------------------------------------
//��� -26 (��������� ���������)
typedef struct
{
 float Vprib;			// ��������� ��������
 float Vvert;			// ������������ ��������
 float Baro_H_QFE;		// ��������������� ������ (���������� �������� �� ������ ����)
 float Baro_H_QNH;		// ��������������� ������ (���������� �������� �� ������ ����)
 float Baro_H_STD;		// ��������������� ������ (���������� �������� �� ������ ����)
 float Kren;	   		// ����
 float Tangage;			// ������
 float Kurs;			// ������� ����
 float SetKurs;			// �������� ����
 float Number_M;		// ����� �

 bool Brightness_minus;	        // ������� ������ ���������� ������� (true - ������, false - �� ������)
 bool Brightness_plus;	        // ������� ������ ���������� ������� (true - ������, false - �� ������)
 bool Fast_Korrection;          // ������� ������ ���������� ���������
 bool HDG_press;		// ������� ���������������� ������� ���������� HDG;
 bool BARO_press;		// ������� ���������������� ������� ���������� BARO;
 int BARO_roll;			// �������� ����� BARO, ��������� �������� ����� 0. ��� �������� ������ ������� �� 1 ������ �������� HDG ������ ����������� 
 int HDG_roll;			// �������� ����� HDG, ��������� �������� ����� 0. ��� �������� ������ ������� �� 1 ������ �������� HDG ������ ����������� �� �������,
						// ��� �������� �� ������� ������������� �� �������. ����� ����� ���� "���������", ��� ��������� ����������� ���

 bool Otkaz[5];			// ������ �������:
				// 0 = ����� ��������� ��������
				// 1 = ����� ����� � �������
				// 2 = ����� �������������� �����
				// 3 = ����� ������������ ��������
				// 4 = ����� ��������������� ������

 bool Irp_1;			// ����������� ���-1 (true - ��, false - ���)
 float Battery;			// �������� ������ ������� ���-1

 bool Power;			// ��������� ���-26 (true - �������, false - ����), ��� �������� true ������������� �������������� ����� "��������� ��������"
}SHISRP26_IN;


// ������� ��������� - ������� ������ ��� �������� (�� ��� ��)
//-------------------------------------------
struct SHMAIN_STRUCT_CABINE
{
 int                 ID;              // ������������� ������ (ID =3030)!!!!

 SHLUN1539_LEFT_IN   LUN1539_LEFT;    // ��������� ��������� ������� LUN-1539-02.8 (����� ���������)
 SHLUN1539_RIGHT_IN  LUN1539_RIGHT;   // ��������� ��������� ������� LUN-1539-02.8 (������ ���������)
 SHLUN1348_LEFT_IN   LUN1348_LEFT;    // ��������� �������� ����� LUN 1348 (����� ���������)
 SHLUN1348_RIGHT_IN  LUN1348_RIGHT;   // ��������� �������� ����� LUN 1348 (������ ���������)
 SHLUN1687_IN        LUN1687_CENTER;  // ��������� �������� LUN 1687-8
 SHISRP26_IN         ISRP26;          // ��� -26 (��������� ���������)

 bool   Close;       		      // ������� �������� �������� � ���������� ������ Windows
 int    Power;         	              // ���������/���������� �������� �������� (1= ���� �������)
 double Kontur1;    	              // ������� �������� ������ 1 (0+100% �������)
};

//�������� ������ ��� ��������� � ����26
//-------------------------------------------
struct SHMAIN_STRUCT_CABINE_OUT
{
 int                 ID;              // ������������� ������ (ID =8989)!!!!

 float QFE_mmHg;		// �������� QFE � �� ��.��.
 float QFE_hPa;			// �������� QFE � ���
 float QNH_mmHg;		// �������� QNH � �� ��.��.
 float QNH_hPa;			// �������� QNH � ���
 float STD_mmHg;		// �������� STD � �� ��.��.
 float STD_hPa;			// �������� STD � ���
};

#pragma pack(pop)

#endif

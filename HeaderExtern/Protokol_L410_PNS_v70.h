#ifndef _PROTOKOL_L410_PNS_H // #endif
#define _PROTOKOL_L410_PNS_H

#include <cstdint> // uint8_t
#include <cstring>// memset
//------------------------------------------
//Протокол взаимодействия ПНС
//
//Версия 70
//
//
//
//
//
//ARINC
//	 СО-2010           DevId = 0
//    СО-2010 (Топливо) DevId = 1
//    АРК40             DevId = 2
//    РСБН              DevId = 3
//    БКС               DevId = 4
//    РВ                DevId = 5
//    БСОИ1             DevId = 6
//    БСОИ2             DevId = 7
//    БИНС              DevId = 8
//    ПНС               DevId = 9
//    БУР               DevId = 10
//    Выдача частоты    DevId = 11
//
/////////////////////////////////////////////////////////////////



//====================================Самолетный ответчик СО-2010=================
//DevId = 0

//ВЫДАЧА на Выходные структуры СО-2010 //	 СО-2010
//Слово состояния   // PackId = 0; Результаты самодиагностики
struct SOOutSelfContrStruct {
    uint8_t DevId;                                     // Идентификатор устройства
    uint8_t PackId;                                    // Идентификатор пакета   
    uint8_t IsprSO2010 : 1;                            // Неисправность блока СО-2010 (0 - исправен, 1 - неисправен)
    uint8_t StatusAFS837 : 1;                          // Отказ АФС частоты 837.5/740 МГц (0 - исправна, 1 - неисправна)
    uint8_t StatusAFS1030 : 1;                         // Отказ АФС частоты 1030/1090 МГц (0 - исправна, 1 - неисправна)
    uint8_t NoInfPNS12L1 : 1;                          // Отсутствие информации от ПНС1,2 линия 1 (0 - активен, 1 - неактивен (все слова отсутствуют))
    uint8_t IncomplPNS12L1 : 1;                        // Неполная информация от ПНС1,2 линия 1 (0 - поступают все слова, 1 - часть слов отсутствует)
    uint8_t NoInfPNS3L2 : 1;                           // Отсутствие информации от ПНС3 линия 2 (0 - активен, 1 - неактивен (все слова отсутствуют))
    uint8_t IncomplPNS3L2 : 1;                         // Неполная информация от ПНС3 линия 2 (0 - поступают все слова, 1 - часть слов отсутствует)
    uint8_t NoInfPNS12L3 : 1;                          // Отсутствие информации от ПНС1,2 линия 3 (0 - активен, 1 - неактивен (все слова отсутствуют))
    uint8_t IncomplPNS12L3 : 1;                        // Неполная информация от ПНС1,2 линия 3 (0 - поступают все слова, 1 - часть слов отсутствует)
    uint8_t NoInfPNS3L4 : 1;                           // Отсутствие информации от ПНС3 линия 4 (0 - активен, 1 - неактивен (все слова отсутствуют))
    uint8_t IncomplPNS3L4 : 1;                         // Неполная информация от ПНС3 линия 4 (0 - поступают все слова, 1 - часть слов отсутствует)
    uint8_t IncorrAddrIKAO : 1;                        // Некорректный адрес ИКАО (0 - корректный, 1 - некорректный)
    uint8_t Matrix : 2;                                // Матрица состояния: 0 - нормальная работа, 1 - нет вычисленных данных, 2 - функциональный тест, 3 - предупреждение об отказе
    uint8_t Reserv : 2;                                // Резерв
} __attribute__((packed));
//выдача на ПНС      //    ПНС               DevId = 9
//Слово режимов      // PackId = 1; Режим работы
struct SOOutModeStruct {
    uint8_t DevId;                                     // Идентификатор устройства
    uint8_t PackId;                                    // Идентификатор пакета 
    uint8_t Ready : 1;                                 // Работа/Готов: 0 - режим ACS или УВД; 1 - Готов
    uint8_t Earth : 1;                                 // Воздух/Земля: 0 - воздух; 1 - земля 
    uint8_t AZNVStat : 1;                              // Статус АЗН-В: 0 - действует; 1 - неисправно или неактивно
    uint8_t ExpSquitOff : 1;                           // Отключение расширенного сквиттера: 0 - выдача разрешена; 1 - выдача запрещена
    uint8_t AFSContr : 1;                              // Контроль АФС: 0 - АФС не контролируется; 1 - АФС контролируется
    uint8_t NACv : 2;                                  // Код NACv
    uint8_t SPIOn : 1;                                 // Включение SPI: 0 - SPI не включен; 1 - SPI включен
    uint8_t Mode : 1;                                  // Режим работы: 0 - УВД или Готов; 1 - ACS
    uint8_t Emerg : 1;                                 // Состояние аварии: 0 -отсутствует; 1 - присутствует
    uint8_t Matrix : 2;
    uint8_t Reserv : 4;                                // Резерв   
} __attribute__((packed));

//// =============================================// Прием от СО-2010=====Входные структуры для ПНС
//    SOOutSelfContrStruct SOOutSelfContr;               // PackId = 0; Результаты самодиагностики
//    SOOutModeStruct      SOOutMode;                         // PackId = 1; Режим работы

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////???=============================================================== Входные структуры СО-2010  //	 СО-2010           DevId = 0

// Высота абсолютная
struct SOInHAbsStruct {
    uint8_t DevId;                                     // Идентификатор устройства
    uint8_t PackId;                                    // Идентификатор пакета   
    float HAbs;                                        // Абсолютная барометрическая высота, м
} __attribute__((packed));

// Высота относительная

struct SOInHOtnStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    int16_t HOtn; // Относительная барометрическая высота, м
    uint8_t PressureSettings; // Установка давления: 1 - Стандартное, 0 - Нестандартное   
} __attribute__((packed));

// Скорость вертикальная от СВС

struct SOInVyStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    int16_t Vy; // Скорость вертикальная, фут/мин
} __attribute__((packed));

// Скорость приборная

struct SOInVpStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float Vp; // Скорость приборная, узел
} __attribute__((packed));

// Истинная воздушная скорость

struct SOInViStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float Vi; // Истинная воздушная скорость, узел
} __attribute__((packed));

// Число Маха

struct SOInMStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float M; // Число Маха
} __attribute__((packed));

// Курс магнитный

struct SOInCourseStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float Course; // Курс магнитный, град. (+-180 градусов)
} __attribute__((packed));

// Угол крена

struct SOInRollStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float Roll; // Угол крена, град. (+-180 градусов)
} __attribute__((packed));

// Скорость вертикальная инерциальная

struct SOInVyiStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    int16_t Vyi; // Скорость вертикальная инерциальная, фут/мин
} __attribute__((packed));

// Скорость изменения путевого угла

struct SOInVPutAngStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float PutAng; // Скорость изменения путевого угла, град/сек
} __attribute__((packed));

// Заданная высота от пульта управления

struct SOInHzStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint16_t Hz; // Заданная высота от пульта управления, фут
} __attribute__((packed));

// Установка барометрического давления на уровне мирового океана (QNH)

struct SOInPStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float P; // Установка барометрического давления на уровне мирового океана (QNH), мбар
} __attribute__((packed));

// Статус приемника СНС

struct SOInStSNSStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t StSNS; // Статус приемника СНС: 12 - Навигация
    //                                      13 - Использование дифференциальной поправок от спутниковой системы (SBAS) 
    //                                      14 - Использование дифференциальных поправок от систем наземного базирования (GBAS/GRAS)
} __attribute__((packed));

// Координаты

struct SOInCoordStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    double Lat; // Широта, град. (+-180)
    double Lon; // Долгота, град. (+-180)
} __attribute__((packed));

// Высота над эллипсоидом

struct SOInHStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float H; // Высота над эллипсоидом, фут
} __attribute__((packed));

// Путевая скорость

struct SOInVStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float V; // Путевая скорость, узел
} __attribute__((packed));

// Путевой угол

struct SOInAStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float A; // Путевой угол, град (+-180 градусов)
} __attribute__((packed));

// Вертикальная скорость от СНС

struct SOInVyfStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    int16_t Vyf; // Вертикальная скорость, фут/мин
} __attribute__((packed));

// Предел автономной целостности в горизонтальной плоскости

struct SOInLimHStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float LimH; // Предел автономной целостности в горизонтальной плоскости, м.миля
} __attribute__((packed));

// Уровень защиты в горизонтальной плоскости

struct SOInLevHStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float LevH; // Уровень защиты в горизонтальной плоскости, м.миля
} __attribute__((packed));

// Время точное

struct SOInTimeEStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint16_t TimeE; // Время точное, мкс
} __attribute__((packed));

// Время

struct SOInTimeStruct {
    unsigned char DevId; // Идентификатор устройства
    unsigned char PackId; // Идентификатор пакета
    float Time; // Время, сек
} __attribute__((packed));
//============================================//ВЫДАЧА на  СО-2010======Выходные структуры для ПНС
// // Входные структуры
// SOInHAbsStruct SOInHAbs;                           // PackId = 0; Абсолютная барометрическая высота
// SOInHOtnStruct SOInHOtn;                           // PackId = 1; Относительная барометрическая высота
// SOInVyStruct SOInVy;                               // PackId = 2; Скорость вертикальная от СВС
// SOInVpStruct SOInVp;                               // PackId = 3; Скорость приборная
// SOInViStruct SOInVi;                               // PackId = 4; Скорость истинная воздушная
// SOInMStruct SOInM;                                 // PackId = 5; Число Маха
// SOInCourseStruct SOInCourse;                       // PackId = 6; Курс магнитный
// SOInRollStruct SOInRoll;                           // PackId = 7; Угол крена
// SOInVyiStruct SOInVyi;                             // PackId = 8; Скорость вертикальная инерциальная
// SOInVPutAngStruct SOInVPutAng;                     // PackId = 9; Скорость изменения путевого угла
// SOInHzStruct SOInHz;                               // PackId = 10; Заданная высота от пульта управления
// SOInPStruct SOInP;                                 // PackId = 11; Установка барометрического давления на уровне мирового океана (QNH)
// SOInStSNSStruct SOInStSNS;                         // PackId = 12; Статус приемника СНС
// SOInCoordStruct SOInCoord;                         // PackId = 13; Координаты
// SOInHStruct SOInH;                                 // PackId = 14; Высота над эллипсоидом
// SOInVStruct SOInV;                                 // PackId = 15; Путевая скорость
// SOInAStruct SOInA;                                 // PackId = 16; Путевой угол
// SOInVyfStruct SOInVyf;                             // PackId = 17; Вертикальная скорость от СНС
// SOInLimHStruct SOInLimH;                           // PackId = 18; Предел автономной целостности в горизонтальной плоскости
// SOInLevHStruct SOInLevH;                           // PackId = 19; Уровень защиты в горизонтальной плоскости
// SOInTimeEStruct SOInTimeE;                         // PackId = 20; Время точное
// SOInTimeStruct SOInTime;                           // PackId = 21; Время

//=============================================================================Самолетный ответчик СО-2010 (Топливо)
    // Выходная структура для ПНС
struct SOFInFuelStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t Fuel; // Остаток топлива, %
} __attribute__((packed));

//SOFInFuelStruct SOFInFuel; // PackId = 0; Код остатка топлива, %
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 //=======================Автоматический радиокомпас АРК-40=============================================
//Выходные структуры ARC40

// Режим работы АРК40
struct ARC40OutModeStruct {
    uint8_t DevId; // Идентификатор устройстваок
    uint8_t PackId; // Идентификатор пакета   
    uint8_t CompAnt : 1; // 0 - Компас, 1 - Антенна
    uint8_t TlphTlg : 1; // 0 - Телефон, 1 - Телеграф
    uint8_t Res1 : 1; // Резерв
    uint8_t Matrix : 2; // 0 - Нормальное функицонирование, 1 - Зафиксирована и отрабатывается информация последнего входного слова, 2 - Режим АРК: контроль
    uint8_t Res2 : 3; // Резерв
    float Freq; // Частота, кГц
} __attribute__((packed));

// Курсовой угол
struct ARC40OutCourseStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float CourseAngle; // Курсовой угол, град. +- 180 градусов
    uint8_t Matrix : 2; // 0 - Предупреждение об отказе, 1 - Нет вычислительных данных (режим Антенна, отсутствие радиостанции), 2 - Функциональный контроль, 3 - Нормальное функционировние
    uint8_t Reserv : 6; // Резерв
} __attribute__((packed));


//---- Структура входных данных ARC40

// Режим работы АРК40

struct ARC40InModeStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t CompAnt : 1; // 0 - Компас, 1 - Антенна
    uint8_t TlphTlg : 1; // 0 - Телефон, 1 - Телеграф
    uint8_t Matrix : 2; // 0 - Нормальное функицонирование, 1 - Зафиксирована и отрабатывается информация последнего входного слова, 2 - Режим АРК: контроль
    uint8_t Reserv : 4; // Резерв
    float Freq; // Частота, кГц
} __attribute__((packed));

////Входные структуры для ПНС

//ARC40OutModeStruct   ARC40OutMode;   // PackId = 0; Режим работы АРК40
//ARC40OutCourseStruct ARC40OutCourse; // PackId = 1; Курсовой угол

//// Выходная структура для ПНС

//ARC40InModeStruct     ARC40InMode; // PackId = 0; Режим работы АРК40
////////////////////////////////////////////////////////////////////////////////////////


//===========================Радиосистема ближней навигации РСБН============================================

// Общая структура 

//Битовое поле режимов

struct ModeStruct {
    /** Битовое поле матрицы состояния режимов работы
     * 11 “Не используется” 
     * 10 “Функциональный тест”
     * 01 “Нет вычисленных данных”
     * 00 “Нормальная работа”
     */
    uint8_t CondMatrixMode : 2; // Битовое поле матрицы состояния режимов работы
    uint8_t AutoMode : 1; // Режим "Автомат" (всегда 1)
    uint8_t LandingMode : 1; // Режим "Посадка" (0 - режим "Навигация", 1 - режим "Посадка")
    uint8_t IdentMode : 1; // Режим "Опознование" (0 - выключен, 1 - включен)
    uint8_t RadioSilenceMode : 1; // Режим "Запрет излучения" (0 - отсутствие запрета излучения, 1 - запрет излучения)
    uint8_t BeaconType : 1; // Направленный маяк РСБН (0 - всенапраяленный маякЮ, 1 - напрадвенный маяк))
    uint8_t Reserv : 1; // Резерв
} __attribute__((packed));

// Выходные структуры РСБН

// ЧКК

struct RSBNOutChKKStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета
    ModeStruct Mode; // Битовое поле режимов
    uint8_t ChKK; // Номер ЧКК
} __attribute__((packed));

// Дальность

struct RSBNOutDfStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета
    float Df; // Дальность Df, 0-500 км
    /** Битовое поле матрицы состояния дальности
     * 11 “Нормальная работа”
     * 10 “Функциональный тест”
     * 01 “Нет вычисленных данных”
     * 00 “Отказ”
     */
    uint8_t CondMatrixDf : 2; // Битовое поле матрицы состояния Df
    uint8_t SignalDfLost : 1; // Признак режима памяти Df при потере радиосигнала
    uint8_t Reserv : 5; // Резерв
} __attribute__((packed));

// Азимут

struct RSBNOutAfStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float Af; // Азимут Af (+- 180 градусов)
    /** Битовое поле матрицы состояния азимута
     * 11 “Нормальная работа”
     * 10 “Функциональный тест”
     * 01 “Нет вычисленных данных”
     * 00 “Отказ” 
     */
    uint8_t CondMatrixAf : 2; // Битовое поле матрицы состояния Af
    uint8_t SignalAfLost : 1; // Признак режима памяти Af 
    uint8_t Reserv : 5; // Резерв    
} __attribute__((packed));

// Отклонение от линии курса посадки

struct RSBNOutEkfStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float Ekf; // Отклонение от линии посадки по курсу (%КРС)
    /** Битовое поле корректности данных отклонения от линии посадки
     * 11 “Нормальная работа”
     * 10 “Функциональный тест”
     * 01 “Нет вычисленных данных”
     * 00 “Отказ” 
     */
    uint8_t CondMatrixEkf : 2; // Битовое поле матрицы состояния Ekf 
    uint8_t Reserv : 6; // Резерв
} __attribute__((packed));

// Отклонение от линии глиссады

struct RSBNOutEgfStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float Egf; // Отклонение от линии посадки по глиссаде (%КРС)
    /** Битовое поле корректности данных отклонения от линии посадки
     * 11 “Нормальная работа”
     * 10 “Функциональный тест”
     * 01 “Нет вычисленных данных”
     * 00 “Отказ” 
     */
    uint8_t CondMatrixEgf : 2; // Битовое поле матрицы состояния Egf 
    uint8_t Reserv : 6; // Резерв
} __attribute__((packed));

// Слово состояния

struct RSBNOutCondWordStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета
    uint8_t BNPFault : 1; // Отказ БНП
    uint8_t Cntr1Fault : 1; // Отсутствует управление по входу 1
    uint8_t Cntr2Fault : 1; // Отсутствует управление по входу 2
    uint8_t AFSFault : 1; // Отказ АФС
    uint8_t RSBNFault : 1; // Отказ РСБН
    /** Битовое поле корректности данных слова состояния
     * 00 “Нормальная работа”
     * 01 “Нет вычисленных данных”
     * 10 “Функциональный тест”
     */
    uint8_t CondMatrixCondWord : 2; // Битовое поле матрицы состояния слова состояния
    uint8_t Reserv : 1;
} __attribute__((packed));

//Входная структура РСБН

// Управляющее слово

struct RSBNInContrWordStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета
    ModeStruct Mode; // Битовое поле режимов
    uint8_t ChKK; // Номер ЧКК
} __attribute__((packed));

////Входные структуры для ПНС
//RSBNOutChKKStruct RSBNOutChKK; // PackId = 0; Режимы+ЧКК
//RSBNOutDfStruct RSBNOutDf; // PackId = 1; Дальность Df
//RSBNOutAfStruct RSBNOutAf; // PackId = 2; Азимут Af
//RSBNOutEkfStruct RSBNOutEkf; // PackId = 3; Отклонение от линии посадки по курсу
//RSBNOutEgfStruct RSBNOutEgf; // PackId = 4; Отклонение от линии посадки по глиссаде
//RSBNOutCondWordStruct RSBNOutCondWord; // PackId = 5; Служебное слово

//// Выходная структура
//RSBNInContrWordStruct RSBNInContrWord; // PackId = 0; Слово управления

//////////////////////////////////////////////////////////////////////////////////////////////////////////



//===================================== Бортовой комплекс связи БКС================================

// Структура выходных данных БКС

// Слово состояния БКС

// Слово состояния БКС

struct BKSOutBKSCondStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета       
    uint8_t ExchSync : 4; // Синхронизация обмена (круговой счетчик))
    uint8_t KSSCond : 2; // Состояние КСС
    uint8_t CIMSAStat : 1; // Исправность ЦИМС-А  1-Исправно / 0-Неисправно
    uint8_t PrimaDMV1Stat : 1; // Исправность Прима ДМВ 1 1-Исправно / 0-Неисправно
    uint8_t PrimaDMV2Stat : 1; // Исправность Прима ДМВ 2 1-Исправно / 0-Неисправно
    uint8_t PrimaKVStat : 1; // Исправность Прима КВ 1-Исправно / 0-Неисправно
    uint8_t B850KR1Stat : 1; // Исправность Б8-50КР 1 1-Исправно / 0-Неисправно
    uint8_t B850KR2Stat : 1; // Исправность Б8-50КР 2 1-Исправно / 0-Неисправно
    uint8_t B7V35AStat : 1; // Исправность Б7В-35А 1-Исправно / 0-Неисправно
    uint8_t UNCh2x10Stat : 1; // Исправность УНЧ 2х10 1-Исправно / 0-Неисправно
    uint8_t UNCh2x3Stat : 1; // Исправность УНЧ 2х3 1-Исправно / 0-Неисправно
    uint8_t Reserv : 1; // Резерв
} __attribute__((packed));

// Слово расшифровки неисправностей Прима ДМВ

struct BKSOutPrimaDMVFaultStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета       
    uint8_t PRSFault : 1; // Отказ ПРС 0-Штатно / 1-Неисправность
    uint8_t PPRChFault : 1; // Отказ модуля ППРЧ 0-Штатно / 1-Неисправность
    uint8_t UUFault : 1; // Отказ УУ 0-Штатно / 1-Неисправность
    uint8_t APFault : 1; // Отказ АП 0-Штатно / 1-Неисправность
    uint8_t UMFault : 1; // Отказ УМ 0-Штатно / 1-Неисправность
    uint8_t PRVFault : 1; // Отказ ПРВ 0-Штатно / 1-Неисправность
    uint8_t COSFault : 1; // Отказ ЦОС 0-Штатно / 1-Неисправность
    uint8_t VIPFault : 1; // Отказ ВИП 0-Штатно / 1-Неисправность
    uint8_t ExcitFault : 1; // Нет возбуждения 0-Штатно / 1-Неисправность
    uint8_t NPGFault : 1; // Ошибка НПГ ПРВ 0-Штатно / 1-Неисправность
    uint8_t PGFault : 1; //  Ошибка ПГ ПРВ 0-Штатно / 1-Неисправность
    uint8_t UMOverHeat : 1; // Перегрев УМ 0-Штатно / 1-Неисправность
    uint8_t KSVFault : 1; // Отказ по КСВ 0-Штатно / 1-Неисправность
    uint8_t NoPower : 1; // Нет мощности 0-Штатно / 1-Неисправность
    uint8_t RDFault : 1; // Ошибка загр РД 0-Штатно / 1-Неисправность
    uint8_t CLFault : 1; // Неисправность линии управления 0-Штатно / 1-Неисправность
} __attribute__((packed));

// Слово расшифровки неисправностей Прима КВ

struct BKSOutPrimaKVFaultStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t ModemFault : 1; // Отказ Модем 0-Штатно / 1-Неисправность
    uint8_t PRDFault : 1; // Отказ Прд 0-Штатно / 1-Неисправность
    uint8_t PRMFault : 1; // Отказ ПРМ 0-Штатно / 1-Неисправность
    uint8_t PRSFault : 1; // Отказ ПРС 0-Штатно / 1-Неисправность
    uint8_t AVSKFault : 1; // Отказ АВСК 0-Штатно / 1-Неисправность
    uint8_t UMFault : 1; // Отказ УМ 0-Штатно / 1-Неисправность
    uint8_t ASUFault : 1; // Отказ АСУ 0-Штатно / 1-Неисправность
    uint8_t VIPFault : 1; // Отказ ВИП 0-Штатно / 1-Неисправность
    uint8_t BAROASU : 1; // БАРО АСУ 0-Штатно / 1-Неисправность
    uint8_t TermoASU : 1; // Термо АСУ 0-Штатно / 1-Неисправность
    uint8_t TermoUM : 1; // Термо УМ 0-Штатно / 1-Неисправность
    uint8_t CLFault : 1; // Неисправность линии управления 0-Штатно / 1-Неисправность
    uint8_t Reserv : 4; // Резерв   
} __attribute__((packed));

// Слово расшифровки неисправностей ЦИМС-А

struct BKSOutCIMSAFaultStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t ARODictFault : 1; // Словарь АРО    
    uint8_t PSBKFault : 1; // ПСБК 
    uint8_t AROFault : 1; // АРО 
    uint8_t AVSKFault : 1; // АВСК 
    uint8_t SCV1Fault : 1; // СЦВ1
    uint8_t SCV2Fault : 1; // СЦВ2
    uint8_t Reserv : 2; // Резерв
} __attribute__((packed));

// Слово состояния 1 радиостанции Прима ДМВ

struct BKSOutPrimaDMVCond1Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t NumCh; // Номер канала
    uint8_t PSh : 1; // ПШ 0-Выкл / 1-Вкл.
    uint8_t PPRCH : 1; // ФРЧ/ППРЧ 0-ФРЧ / 1-ППРЧ
    uint8_t Modul : 3; // Модуляция 0-АМУ / 1-АМШ / 2-ЧМ / 3-АМ
    uint8_t RRCH : 1; // РРЧ 0-высокая / 1-пониженная
    uint8_t AP : 1; // АП 0-выкл / 1-вкл
    uint8_t Ctr : 1; //Контроль 0-выкл / 1-вкл
    uint8_t Pow : 2; // Мощность 0-0 / 1-25% / 2-50% / 3-100%
    uint8_t NU : 1; // Признак НУ 0-выкл / 1-вкл
    uint8_t ChooseByComm : 1; // Выбрано командиром 0-не выбрана / 1-выбрана
    uint8_t ChooseBy2Pilot : 1; // Выбрано 2 членом экипажа 0-не выбрана / 1-выбрана
    uint8_t Reserv : 3; // Резерв
} __attribute__((packed));

// Слово состояния 2 радиостанции Прима ДМВ

struct BKSOutPrimaDMVCond2Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t kHz1 : 4; // Единицы килогерц ДДК (0 или 5)
    uint8_t kHz10 : 4; // Десятки килогерц ДДК (0 - 9)
    uint8_t kHz100 : 4; // Сотни килогерц ДДК (0 - 9)
    uint8_t MHz1 : 4; // Единицы мегагерц ДДК (0 - 9)
    uint8_t MHz10 : 4; // Десятки мегагерц ДДК (0 - 9)
    uint8_t MHz100 : 2; // Сотни мегагерц ДДК (0 - 3)
    uint8_t Reserv : 2; // Резерв
} __attribute__((packed));

// Слово состояния 3 радиостанции Прима ДМВ

struct BKSOutPrimaDMVCond3Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t TLF : 1; // Прием ТЛФ 0-нет приема / 1-идет прием
    uint8_t Izl : 1; // Излучение 0-нет ПРД / 1-идет ПРД
    uint8_t SA : 1; // СА Резерв
    uint8_t AP : 1; // Прием АП 0-нет приема / 1-идет прием
    uint8_t Reserv : 4; // Резерв
} __attribute__((packed));

// Слово состояния 1 радиостанции Прима КВ

struct BKSOutPrimaKVCond1Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t NumCh; // Номер канала
    uint8_t PSh : 1; // ПШ 0-Выкл / 1-Вкл.
    uint8_t Modul : 4; // Модуляция 0-R3E 300-3400 ВБП (ОМ1в)    / 1-R3E 300-3400 НБП (ОМ1н)     / 2-J3E 300-3400 ВБП (ОМв) /
    //           3-J3E 300-3400 НБП (ОМн)     / 4-J3E 300-2700 ВБП (ОМу)      / 
    //          12-A3E/H3E 300-3400 ВБП (АМэ) / 13-A3E/H3E 300-2700 ВБП (АМу)
    uint8_t Ctr : 1; //Контроль 0-выкл / 1-вкл
    uint8_t Pow : 1; // Мощность 0-100% / 1-25%
    uint8_t Res3 : 1;
    uint8_t NU : 1; // Признак НУ 0-выкл / 1-вкл
    uint8_t ChooseByComm : 1; // Выбрано командиром 0-не выбрана / 1-выбрана
    uint8_t ChooseBy2Pilot : 1; // Выбрано 2 членом экипажа 0-не выбрана / 1-выбрана
    uint8_t Reserv : 5; // Резерв
} __attribute__((packed));

// Слово состояния 2 радиостанции Прима КВ

struct BKSOutPrimaKVCond2Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t Hz100 : 4; // Сотни герц ДДК (0 - 9)
    uint8_t kHz1 : 4; // Единицы килогерц ДДК (0 - 9)
    uint8_t kHz10 : 4; // Десятки килогерц ДДК (0 - 9)
    uint8_t kHz100 : 4; // Сотни килогерц ДДК (0 - 9)
    uint8_t MHz1 : 4; // Единицы мегагерц ДДК (0 - 9)
    uint8_t MHz10 : 2; // Десятки мегагерц ДДК (0 - 3)
    uint8_t Reserv : 2; // Резерв
} __attribute__((packed));

// Слово состояния 3 радиостанции Прима КВ

struct BKSOutPrimaKVCond3Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t TLF : 1; // Прием ТЛФ Резерв
    uint8_t Izl : 1; // Излучение 0-нет ПРД / 1-идет ПРД
    uint8_t SA : 2; // СА Резерв
    uint8_t Reserv : 4; // Резерв
} __attribute__((packed));

// Слово ответа 1 на запрос канала ПСБК УКВ

struct BKSOutAnsw1DMVStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t ChNum; // Номер канала (1-40)
    uint8_t UKV : 1; // УКВ
    uint8_t PPRCH : 1; // 0-ФРЧ / 1-ППРЧ
    uint8_t Modul : 3; // 0-АМУ / 1-АМШ / 2-ЧМ / 3-АМ
    uint8_t Reserv : 3; // Резерв
} __attribute__((packed));

// Слово ответа 1 на запрос канала ПСБК УКВ

struct BKSOutAnsw1KVStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t ChNum; // Номер канала (1-40)
    uint8_t KV : 1; // КВ
    uint8_t Modul : 4; // Модуляция 0-R3E 300-3400 ВБП (ОМ1в)    / 1-R3E 300-3400 НБП (ОМ1н)     / 2-J3E 300-3400 ВБП (ОМв) /
    //           3-J3E 300-3400 НБП (ОМн)     / 4-J3E 300-2700 ВБП (ОМу)      / 
    //          12-A3E/H3E 300-3400 ВБП (АМэ) / 13-A3E/H3E 300-2700 ВБП (АМу)
    uint8_t Reserv : 3; // Резерв
} __attribute__((packed));

// Слово ответа 2 на запрос канала ПСБК УКВ рс

struct BKSOutAnsw2DMVStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t kHz1 : 4; // Единицы килогерц ДДК (0 или 5)
    uint8_t kHz10 : 4; // Десятки килогерц ДДК (0 - 9)
    uint8_t kHz100 : 4; // Сотни килогерц ДДК (0 - 9)
    uint8_t MHz1 : 4; // Единицы мегагерц ДДК (0 - 9)
    uint8_t MHz10 : 4; // Десятки мегагерц ДДК (0 - 9)
    uint8_t MHz100 : 2; // Сотни мегагерц ДДК (0 - 3) 
    uint8_t Reserv : 2; // Резерв
} __attribute__((packed));

// Слово ответа 2 на запрос канала ПСБК КВ рс

struct BKSOutAnsw2KVStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t Hz100 : 4; // Сотни герц ДДК (0 - 9)
    uint8_t kHz1 : 4; // Единицы килогерц ДДК (0 - 9)
    uint8_t kHz10 : 4; // Десятки килогерц ДДК (0 - 9)
    uint8_t kHz100 : 4; // Сотни килогерц ДДК (0 - 9)
    uint8_t MHz1 : 4; // Единицы мегагерц ДДК (0 - 9)
    uint8_t MHz10 : 2; // Десятки мегагерц ДДК (0 - 3)
    uint8_t Reserv : 2; // Резерв
} __attribute__((packed));

// Слово ответа 1 на запрос позывного канала ПСБК

struct BKSOutAnswPozStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t S[16]; // Символ в КОИ7
} __attribute__((packed));

// Входные структуры

// Слово запроса каналов ПСБК из КСС

struct BKSInReqChPSBKStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета       
    uint8_t ChNum; // Номер запрашиваемого канала из ПСБК (1-40))
    uint8_t KV : 1; // 0-УКВ / 1-КВ
    uint8_t PPRCH : 1; // 0-ФРЧ / 1-ППРЧ
    uint8_t Reserv : 6; // Резерв
} __attribute__((packed));

// Слово речевых сообщений

struct BKSInVMStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета       
    uint16_t Data; // Информационные разряды 0-Отсутствие РК / 1-Наличие РК
    uint8_t Id : 2; // Идентификатор блока 1-ПНС1(2) / 2-ПНС3    
    uint8_t Res : 3; // 0-ФРЧ / 1-ППРЧ
    uint8_t Matrix : 2; // 0-Нормальная работа / 2-Функциональный тест
    uint8_t Reserv : 1; // Резерв
} __attribute__((packed));

// Слово управления 1 радиостанции Прима ДМВ

struct BKSInCW1DMVStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t ChNum; // Номер канала (1-40)
    uint8_t PSh : 1; // ПШ: 0-выключено, 1-включено
    uint8_t PPRCH : 1; // 0-ФРЧ / 1-ППРЧ
    uint8_t Modul : 3; // Модуляция: 0-АМУ / 1-АМШ / 2-ЧМ / 3-АМ
    uint8_t AP : 1; // АП: 0-выключено, 1-включено
    uint8_t Pow : 2; // Мощность: 0-10%, 1-25%, 2-50%, 3-100%
    uint8_t NU : 1; // НУ: 0-выключено, 1-включено
    uint8_t Reserv : 7;
} __attribute__((packed));

// Слово управления 2 радиостанции Прима ДМВ

struct BKSInCW2DMVStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета  
    uint8_t kHz1 : 4; // Единицы килогерц ДДК (0 или 5)
    uint8_t kHz10 : 4; // Десятки килогерц ДДК (0 - 9)
    uint8_t kHz100 : 4; // Сотни килогерц ДДК (0 - 9)
    uint8_t MHz1 : 4; // Единицы мегагерц ДДК (0 - 9)
    uint8_t MHz10 : 4; // Десятки мегагерц ДДК (0 - 9)
    uint8_t MHz100 : 2; // Сотни мегагерц ДДК (0 - 3)    
    uint8_t Reserv : 2;
} __attribute__((packed));

// Слово управления 1 радиостанции Прима КВ

struct BKSInCW1KVStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета  
    uint8_t ChNum; // Номер канала (1-40)
    uint8_t PSh : 1; // ПШ: 0-выключено, 1-включено
    uint8_t Modul : 4; // Модуляция
    uint8_t Pow : 1; // Мощность: 0-100%, 1-25%
    uint8_t NU : 1; // НУ: 0-выключено, 1-включено
    uint8_t Reserv : 1;
} __attribute__((packed));

// Слово управления 2 радиостанции Прима КВ

struct BKSInCW2KVStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета  
    uint8_t Hz100 : 4; // Сотни герц ДДК (0 - 9)
    uint8_t kHz1 : 4; // Единицы килогерц ДДК (0 - 9)
    uint8_t kHz10 : 4; // Десятки килогерц ДДК (0 - 9)
    uint8_t kHz100 : 4; // Сотни килогерц ДДК (0 - 9)
    uint8_t MHz1 : 4; // Единицы мегагерц ДДК (0 - 9)
    uint8_t MHz10 : 2; // Десятки мегагерц ДДК (0 - 3)
    uint8_t Reserv : 2;
} __attribute__((packed));
////Входные структуры для ПНС
//BKSOutBKSCondStruct BKSOutBKSCond; // PackId = 0; Слово состояния БКС
//BKSOutPrimaDMVFaultStruct BKSOutPrimaDMV1Fault; // PackId = 1; Слово расшифровки неисправностей Прима ДМВ1
//BKSOutPrimaDMVFaultStruct BKSOutPrimaDMV2Fault; // PackId = 2; Слово расшифровки неисправностей Прима ДМВ2
//BKSOutPrimaKVFaultStruct BKSOutPrimaKVFault; // PackId = 3; Слово расшифровки неисправностей Прима КВ
//BKSOutCIMSAFaultStruct BKSOutCIMSAFault; // PackId = 4; Слово расшифровки неисправностей ЦИМС-А
//BKSOutPrimaDMVCond1Struct BKSOutPrimaDMV1Cond1; // PackId = 5; Слово состояния 1 радиостанции Прима ДМВ1
//BKSOutPrimaDMVCond1Struct BKSOutPrimaDMV2Cond1; // PackId = 6; Слово состояния 1 радиостанции Прима ДМВ2
//BKSOutPrimaDMVCond2Struct BKSOutPrimaDMV1Cond2; // PackId = 7; Слово состояния 2 радиостанции Прима ДМВ1
//BKSOutPrimaDMVCond2Struct BKSOutPrimaDMV2Cond2; // PackId = 8; Слово состояния 2 радиостанции Прима ДМВ2
//BKSOutPrimaDMVCond3Struct BKSOutPrimaDMV1Cond3; // PackId = 9; Слово состояния 3 радиостанции Прима ДМВ1
//BKSOutPrimaDMVCond3Struct BKSOutPrimaDMV2Cond3; // PackId = 10; Слово состояния 3 радиостанции Прима ДМВ2
//BKSOutPrimaKVCond1Struct BKSOutPrimaKVCond1; // PackId = 11; Слово состояния 1 радиостанции Прима КВ
//BKSOutPrimaKVCond2Struct BKSOutPrimaKVCond2; // PackId = 12; Слово состояния 2 радиостанции Прима КВ
//BKSOutPrimaKVCond3Struct BKSOutPrimaKVCond3; // PackId = 13; Слово состояния 3 радиостанции Прима КВ
//BKSOutAnsw1DMVStruct BKSOutAnsw1DMV; // PackId = 14; Слово ответа 1 на запрос канала ПСБК УКВ рс
//BKSOutAnsw1KVStruct BKSOutAnsw1KV; // PackId = 15; Слово ответа 1 на запрос канала ПСБК КВ рс
//BKSOutAnsw2DMVStruct BKSOutAnsw2DMV; // PackId = 16; Слово ответа 2 на запрос канала ПСБК УКВ рс
//BKSOutAnsw2KVStruct BKSOutAnsw2KV; // PackId = 17; Слово ответа 2 на запрос канала ПСБК КВ рс
//BKSOutAnswPozStruct BKSOutAnswPoz; // PackId = 18; Слово ответа на запрос позывного канала ПСБК

////Выходные структуры для ПНС
//BKSInReqChPSBKStruct BKSInReqChPSBK; // PackId = 0; Слово запроса каналов ПСБК из КСС
//BKSInVMStruct BKSInVM1; // PackId = 1; Слово речевых сообщений 1
//BKSInVMStruct BKSInVM2; // PackId = 2; Слово речевых сообщений 2
//BKSInVMStruct BKSInVM3; // PackId = 3; Слово речевых сообщений 3
//BKSInVMStruct BKSInVM4; // PackId = 4; Слово речевых сообщений 4
//BKSInVMStruct BKSInVM5; // PackId = 5; Слово речевых сообщений 5
//BKSInVMStruct BKSInVM6; // PackId = 6; Слово речевых сообщений 6
//BKSInVMStruct BKSInVM7; // PackId = 7; Слово речевых сообщений 7
//BKSInVMStruct BKSInVM8; // PackId = 8; Слово речевых сообщений 8
//BKSInVMStruct BKSInVM9; // PackId = 9; Слово речевых сообщений 9
//BKSInVMStruct BKSInVM10; // PackId = 10; Слово речевых сообщений 10
//BKSInVMStruct BKSInVM11; // PackId = 11; Слово речевых сообщений 11
//BKSInVMStruct BKSInVM12; // PackId = 12; Слово речевых сообщений 12
//BKSInVMStruct BKSInVM13; // PackId = 13; Слово речевых сообщений 13
//BKSInVMStruct BKSInVM14; // PackId = 14; Слово речевых сообщений 14
//BKSInVMStruct BKSInVM15; // PackId = 15; Слово речевых сообщений 15
//BKSInVMStruct BKSInVM16; // PackId = 16; Слово речевых сообщений 16
//BKSInCW1DMVStruct BKSInCW1DMV1; // PackId = 17; Слово управления 1 радиостанции Прима ДМВ1
//BKSInCW1DMVStruct BKSInCW1DMV2; // PackId = 18;  Слово управления 1 радиостанции Прима ДМВ2
//BKSInCW2DMVStruct BKSInCW2DMV1; // PackId = 19;  Слово управления 2 радиостанции Прима ДМВ1
//BKSInCW2DMVStruct BKSInCW2DMV2; // PackId = 20;  Слово управления 2 радиостанции Прима ДМВ2
//BKSInCW1KVStruct BKSInCW1KV; // PackId = 21;  Слово управления 1 радиостанции Прима КВ
//BKSInCW2KVStruct BKSInCW2KV; // PackId = 22;  Слово управления 2 радиостанции Прима КВ
////////////////////////////////////////////////////////////////////////////////////////////////


// =====================================Радиовысотомер KRA-405B===============================

// Радиовысотомер (двочиный) 
struct KRAOutAltBinStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float AltBin; //Радиовысотомер (двоичный), футы
    uint8_t SSM; // Матрица состояния: 0-предупреждение об отказе, 1-нет вычисленных данных, 2-функциональный тест, 3-нормальная работа
} __attribute__((packed));

// Радиовысотомер (двочино-десятичный) 
struct KRAOutAltBinDecStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    float AltBinDec; // Радиовысотомер (двоично-десятичный), футы    
    uint8_t SSM; // Матрица состояния: 0-информация верна и плюс, 1-нет вычисленных данных, 2-функциональный тест, 3-информация верна и минус
} __attribute__((packed));

////Входные структуры
//KRAOutAltBinStruct KRAOutAltBin; // PackId = 0; Радиовысотомер (двочиный)
//KRAOutAltBinDecStruct KRAOutAltBinDec; // PackId = 1; Радиовысотомер (двоично-десятичный)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


//================================Блок сбора и обработки информации БСОИ-29К-02================================

// Структура выходных данных BSOI

// Целые значения

struct BSOIOutIntStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    int16_t Data; // Данные целое значение
    uint8_t Matrix; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

// Структура данных БСОИ дробного типа

struct BSOIOutFloatStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета 
    float Data; // Данные дробное значение
    uint8_t Matrix; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

// Структура РК1

struct BSOIOutRK1Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t GearOnGround : 1; // Шасси обжато
    uint8_t US2B : 1; // Наличие напряжение на шине S2B
    uint8_t US3B : 1; // Наличие напряжение на шине S3B
    uint8_t US1A : 1; // Наличие напряжение на шине S1A
    uint8_t US1B : 1; // Наличие напряжение на шине S1B
    uint8_t _U28V1 : 1; // Отсутствие выходного напряжения преобразователя 26V №1
    uint8_t _U28V2 : 1; // Отсутствие выходного напряжения преобразователя 26V №2
    uint8_t _U36V1 : 1; // Отсутствие выходного напряжения преобразователя 36V №1
    uint8_t _U36V2 : 1; // Отсутствие выходного напряжения преобразователя 36V №2
    uint8_t Bell : 1; // Вызов экипажа
    uint8_t FireLeftEng : 1; // Пожар левого двигателя
    uint8_t FireRightEng : 1; // Пожар правого двигателя
    uint8_t FireFrontBaggage : 1; // Пожар переднего багажного отсека
    uint8_t Interceptor : 1; // Выпущены интерцепторы
    uint8_t Matrix : 2; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

// Структура РК2
 
struct BSOIOutRK2Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета    
    uint8_t Flaps0 : 1; // Закрылки положение 0
    uint8_t Flaps18 : 1; // Закрылки положение 18
    uint8_t Flaps42 : 1; // Закрылки положение 42
    uint8_t FlapsTo18 : 1; // Выпусти закрылки положение 18
    uint8_t ReadyAUK : 1; // Готовность АУК
    uint8_t AUKShield : 1; // Выпущен щит АУК
    uint8_t PFuelLeftLow : 1; // Давление топлива в левом двигателе низкое
    uint8_t PFuelRightLow : 1; // Давление топлива в правом двигателе низкое
    uint8_t LevFuelLeftLow : 1; // Низкий уровень топлива левой системы топливных баков
    uint8_t LevFuelRightLow : 1; // Низкий уровень топлива правой системы топливных баков
    uint8_t FuelCircle : 1; // Включено кольцевание топлива
    uint8_t FuelPumpLeftTermTank : 1; // Включена перекачка топлива из левого концевого бака
    uint8_t FuelPumpRightTermTank : 1; // Включена перекачка топлива из правого концевого бака
    uint8_t FuelPumpLeftTank : 1; // Включи перекачку топлива в левую систему топливных баков
    uint8_t FuelPumpRightTank : 1; // Включи перекачку топлива в правую систему топливных баков
    uint8_t ByPassFuelFilterLeft : 1; // Открытие обходного предохранительного клапана топливного фильтра левой системы
    uint8_t Matrix; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

// Структура РК3
 
struct BSOIOutRK3Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t ByPassFuelFilterRight : 1; // Открытие обходного предохранительного клапана топливного фильтра правой системы
    uint8_t TPumpBackLeft90 : 1; // Температура жидкости в обратном контуре насосов левой системы превышает 90 градусов
    uint8_t TPumpBackRight90 : 1; // Температура жидкости в обратном контуре насосов правой системы превышает 90 градусов
    uint8_t Icing : 1; // Обледенение
    uint8_t OpenSepIceLeft : 1; // Открыты левые створки сепараторов льда
    uint8_t OpenSepIceRight : 1; // Открыты правые створки сепараторов льда
    uint8_t HeatPSN : 1; // Включен обогрев ПСН
    uint8_t HeatPSD1 : 1; // Включен обогрев приемника статического давления I
    uint8_t HeatPSD2 : 1; // Включен обогрев приемника статического давления II
    uint8_t HeatPPD1 : 1; // Включен обогрев приемника полного давления I
    uint8_t HeatPPD2 : 1; // Включен обогрев приемника полного давления II
    uint8_t HeatGlassLeft : 1; // Включен обогрев стекол слева
    uint8_t HeatGlassRight : 1; // Включен обогрев стекол справа
    uint8_t FaultDeIcePropLeft : 1; // Отказ ПОС левого воздушного винта
    uint8_t FaultDeIcePropRight : 1; // Отказ ПОС правого воздушного винта
    uint8_t LeftGearOn : 1; // Левое шасси выпущено
    uint8_t Matrix; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

// Структура РК4
 
struct BSOIOutRK4Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t FrontGearOn : 1; // Переднее шасси выпущено
    uint8_t RightGearOn : 1; // Правое шасси выпущено
    uint8_t PropRestLeft : 1; // Упор винта левый
    uint8_t GearOn : 1; // Выпусти шасси
    uint8_t PropRestRight : 1; // Упор винта правый
    uint8_t ABSGearLeft : 1; // Срабатывание антиблокировочной системы левого шасси
    uint8_t ABSGearRight : 1; // Срабатывание антиблокировочной системы правого шасси   
    uint8_t Stall : 1; // Сваливание
    uint8_t AddVanePumpLeftOn : 1; // Включен вспомогательный флюгерный насос левого двигателя
    uint8_t AddVanePumpRightOn : 1; // Включен вспомогательный флюгерный насос правого двигателя
    uint8_t AutoVaneLeft : 1; // Автоматическое флюгирование левого двигателя
    uint8_t AutoVaneRight : 1; // Автоматическое флюгирование правого двигателя
    uint8_t DiapBLeft : 1; // Диапазон B левого двигателя
    uint8_t DiapBRight : 1; // Диапазон B правого двигателя
    uint8_t Matrix : 2; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

// Структура РК5

struct BSOIOutRK5Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t ECULeft : 1; // Готовность ЭБО левого двигателя
    uint8_t ECURight : 1; // Готовность ЭБО правого двигателя
    uint8_t _UACLeft : 1; // Отсутствие выходного напряжения генератора переменного тока левого
    uint8_t _UACRight : 1; // Отсутствие выходного напряжения генератора переменного тока правого
    uint8_t _UDCLeft : 1; // Отсутствие выходного напряжения генератора постоянного тока левого
    uint8_t _UDCRight : 1; // Отсутствие выходного напряжения генератора постоянного тока правого
    uint8_t EngineEmergLeft : 1; // Включена система управления аварийным режимом левого двигателя при помощи рычагов управления стоп-кранами
    uint8_t EngineEmergRight : 1; // Включена система управления аварийным режимом правого двигателя при помощи рычагов управления стоп-кранами
    uint8_t POilLowLeft : 1; // Низкое давление масла в левом двигателе
    uint8_t POilLowRight : 1; // Низкое давление масла в правом двигателе
    uint8_t ChipInOilLeft : 1; // Наличие стружки в левом маслобаке
    uint8_t ChipInOilRight : 1; // Наличие стружки в правом маслобаке
    uint8_t EngineStart : 1; // Запуск двигателей
    uint8_t EngineParamsExceedLeft : 1; // Превышение параметров левого двигателя
    uint8_t EngineParamsExceedRight : 1; // Превышение параметров правого двигателя
    uint8_t OilBypassOpenRight : 1; // Открыт предохранительный клапан масляной системы правого двигателя
    uint8_t Matrix; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

// Структура РК6
 
struct BSOIOutRK6Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint8_t OilBypassOpenLeft : 1; // Открыт предохранительный клапан масляной системы левого двигателя
    uint8_t TaxiLightOn : 1; // Включены рулежные фары
    uint8_t LandingLightOn : 1; // Включены посадочные фары
    uint8_t HandContrFrontWheel : 1; // Задействовано ручное управление передним колесом
    uint8_t FootContrFrontWheel : 1; // Задействовано ножное управление передним колесом
    uint8_t BattFault : 1; // Отказ аккумулятора
    uint8_t Batt1Overheat : 1; // Перегрев аккумулятора №1
    uint8_t Batt2Overheat : 1; // Перегрев аккумулятора №2
    uint8_t DoorOpen : 1; // Дверь открыта
    uint8_t GroundPower : 1; // Аэродромное питание
    uint8_t TestPanelButt : 1; // Нажата кнопка тестирования табло сигнализации
    uint8_t GearL : 1; // Левое шасси в процессе выпуска/уборки
    uint8_t GearF : 1; // Переднее шасси в процессе выпуска/уборки
    uint8_t GearR : 1; // Правое шасси в процессе выпуска/уборки
    uint8_t Matrix : 2; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

// Структура РК7
 
struct BSOIOutRK7Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета   
    uint16_t DeIceA : 1; // Работа противообледенительной системы А
    uint16_t DeIceB : 1; // Работа противообледенительной системы B
    uint16_t DeIceC : 1; // Работа противообледенительной системы C
    uint16_t OGOGood : 1; // Исправность ответчика ГО
    uint16_t OGOFault : 1; // Отказ ответчика ГО
    uint16_t OilLevMinL : 1; // Уровень масла левого минимальный
    uint16_t OilLevMinR : 1; // Уровень масла правого минимальный
    uint16_t MaxTempEngL : 1; // Максимальная температура левого двигателя
    uint16_t MaxTempEngR : 1; // Максимальная температура правого двигателя
    uint16_t RegOn : 1; // Регистратор включен
    uint16_t TangentaOn : 1; // Нажатие тангенты радиосвязи
    uint16_t ESGO115 : 1; // Наличие 115 вольт 400Гц ЕСГО 
    uint16_t FireTestOn : 1; // Нажата кнопка тестирования датчиков пожара
    uint16_t ESGOResInd : 1; // Индикатор запасной ЕСГО 
    uint16_t FuelAddTankMin : 1; // Минимальный уровень топлива в дополнительном баке 
    uint16_t FuelPumpAddTankOn : 1; // Включен насос топлива в дополнительном баке 
    uint16_t Matrix : 2; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
    uint16_t Reserv : 14; // Резерв
} __attribute__((packed));

// Структура РК8
 
struct BSOIOutRK8Struct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета 
    uint16_t SNOCOpen : 1; // Открытие створки СНОЦ/ВЕЕР 1
    uint16_t SNOCClose : 1; // Закрытие створки СНОЦ/ВЕЕР 2
    uint16_t UltraOpen : 1; // Открытие створки Ultra-Cam 1
    uint16_t UltraClose : 1; // Закрытие створки Ultra-Cam 2 
    uint16_t Matrix : 2; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
    uint16_t Reserv : 10; // Резерв
} __attribute__((packed));

// Слово состояния БСОИ

struct BSOIOutCWStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета     
    uint8_t FaultBSOI : 1; // Отказ БСОИ
    uint8_t FaultUU : 1; // Отказ УУ
    uint8_t FaultDPK : 1; // Отказ ДПК
    uint8_t FaultRK : 1; // Отказ РК
    uint8_t FaultMAC2 : 1; // Отказ МАК2
    uint8_t FaultMAC1 : 1; // Отказ МАК1
    uint8_t Matrix : 2; // Матрица достоверности (0 - нормальная работа, 1,2 - информация не достоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

//// Входные структуры для ПНС
//BSOIOutIntStruct BSOIOutTempAirHeater; // PackId = 0; Температура воздуха отопления, градус Цельсия
//BSOIOutIntStruct BSOIOutTempAirCabine; // PackId = 1; Температура воздуха в пассажирской кабине, градус Цельсия
//BSOIOutIntStruct BSOIOutULeft; // PackId = 2; Напряжение генератора левого, вольт
//BSOIOutIntStruct BSOIOutIGenLeftEng; // PackId = 3; Ток генератора левого двигателя, ампер
//BSOIOutIntStruct BSOIOutURight; // PackId = 4; Напряжение генератора правого, вольт
//BSOIOutIntStruct BSOIOutIGenRightEng; // PackId = 5; Ток генератора правого двигателя, ампер
//BSOIOutIntStruct BSOIOutUEmerg1; // PackId = 6; Напряжение аварийной шины 1, вольт
//BSOIOutIntStruct BSOIOutUEmerg2; // PackId = 7; Напряжение аварийной шины 2, вольт
//BSOIOutIntStruct BSOIOutUBat1; // PackId = 8; Напряжение аккумуляторной батареи 1, вольт
//BSOIOutIntStruct BSOIOutIBat1; // PackId = 9; Ток аккумуляторной батареи 1, ампер
//BSOIOutIntStruct BSOIOutUBat2; // PackId = 10; Напряжение аккумуляторной батареи 2, вольт
//BSOIOutIntStruct BSOIOutIBat2; // PackId = 11; Ток аккумуляторной батареи 2, ампер
//BSOIOutIntStruct BSOIOutU23Gen36V1; // PackId = 12; Напряжение между фазами 2-3 генератора 36 вольт №1, вольт
//BSOIOutIntStruct BSOIOutU13Gen36V1; // PackId = 13; Напряжение между фазами 1-3 генератора 36 вольт №1, вольт
//BSOIOutIntStruct BSOIOutU12Gen36V1; // PackId = 14; Напряжение между фазами 1-2 генератора 36 вольт №1, вольт
//BSOIOutIntStruct BSOIOutU23Gen36V2; // PackId = 15; Напряжение между фазами 2-3 генератора 36 вольт №2, вольт
//BSOIOutIntStruct BSOIOutU13Gen36V2; // PackId = 16; Напряжение между фазами 1-3 генератора 36 вольт №2, вольт
//BSOIOutIntStruct BSOIOutU12Gen36V2; // PackId = 17; Напряжение между фазами 1-2 генератора 36 вольт №2, вольт
//BSOIOutIntStruct BSOIOutUAGen115V1; // PackId = 18; Напряжение фазы A генератора 115 вольт №1, вольт
//BSOIOutIntStruct BSOIOutUBGen115V1; // PackId = 19; Напряжение фазы B генератора 115 вольт №1, вольт
//BSOIOutIntStruct BSOIOutUCGen115V1; // PackId = 20; Напряжение фазы C генератора 115 вольт №1, вольт
//BSOIOutIntStruct BSOIOutUAGen115V2; // PackId = 21; Напряжение фазы A генератора 115 вольт №2, вольт
//BSOIOutIntStruct BSOIOutUBGen115V2; // PackId = 22; Напряжение фазы B генератора 115 вольт №2, вольт
//BSOIOutIntStruct BSOIOutUCGen115V2; // PackId = 23; Напряжение фазы C генератора 115 вольт №2, вольт
//BSOIOutIntStruct BSOIOutLevFuelLeftTanks; // PackId = 24; Уровень топлива в левой системе топливных баков, кг
//BSOIOutIntStruct BSOIOutLevFuelRightTanks; // PackId = 25; Уровень топлива в правой системе топливных баков, кг
//BSOIOutIntStruct BSOIOutLevFuelLeftTermTanks; // PackId = 26; Уровень топлива в концевом топливном баке слева, кг
//BSOIOutIntStruct BSOIOutLevFuelRightTermTanks; // PackId = 27; Уровень топлива в концевом топливном баке справа, кг
//BSOIOutFloatStruct BSOIOutPFuelLeft; // PackId = 28; Давление топлива левой системы, МПа
//BSOIOutFloatStruct BSOIOutPOilLeft; // PackId = 29; Давление масла левой системы, МПа
//BSOIOutIntStruct BSOIOutTOilLeft; // PackId = 30; Температура масла левой системы, градус Цельсия
//BSOIOutFloatStruct BSOIOutPFuelRight; // PackId = 31; Давление топлива правой системы, МПа
//BSOIOutFloatStruct BSOIOutPOilRight; // PackId = 32; Давление масла правой системы, МПа
//BSOIOutIntStruct BSOIOutTOilRight; // PackId = 33; Температура масла правой системы, градус Цельсия
//BSOIOutIntStruct BSOIOutConsFuelLeft; // PackId = 34; Расход топлива левого двигателя, кг/ч
//BSOIOutIntStruct BSOIOutConsFuelRight; // PackId = 35; Расход топлива правого двигателя, кг/ч
//BSOIOutFloatStruct BSOIOutPGydroMain; // PackId = 36; Давление гидравлической жидкости в основном контуре постоянного давления, МПа
//BSOIOutFloatStruct BSOIOutPGydroBrake; // PackId = 37; Давление гидравлической жидкости в контуре тормозов, МПа
//BSOIOutFloatStruct BSOIOutElevatorAngle; // PackId = 40; Угол отклонения руля высоты, [-30..14], градусы (вверх - минус, вниз - плюс)
//BSOIOutFloatStruct BSOIOutAileronAngle; // PackId = 41; Угол отклонения элеронов, [-27..14], градусы (вверх - минус, вниз - плюс)
//BSOIOutFloatStruct BSOIOutRudderAngle; // PackId = 42; Угол отклонения руля направления, [-17..17], градусы (направо - минус, налево - плюс)
//BSOIOutFloatStruct BSOIOutTrimmerRudder; // PackId = 43; Угол отклонения триммера руля направления, [-10..10], градусы (направо - минус, налево - плюс)
//BSOIOutIntStruct BSOIOutRUDLeft; // PackId = 44; Положение РУД левого двигателя, %
//BSOIOutIntStruct BSOIOutRUDRight; // PackId = 45; Положение РУД правого двигателя, %
//BSOIOutIntStruct BSOIOutTorqLeft; // PackId = 46; Крутящий момент левого двигателя, %
//BSOIOutIntStruct BSOIOutTorqRight; // PackId = 47; Крутящий момент правого двигателя, %
//BSOIOutFloatStruct BSOIOutPGydroParkBrake; // PackId = 48; Давление в контуре стояночного тормоза, МПа
//BSOIOutFloatStruct BSOIOutPGydroBrakeLeft; // PackId = 49; Давление в левой гидравлической системе тормозов, МПа
//BSOIOutFloatStruct BSOIOutPGydroBrakeRight; // PackId = 50; Давление в правой гидравлической системе тормозов, МПа
//BSOIOutIntStruct BSOIOutNLeft; // PackId = 51; Обороты воздушного винта левого двигателя, об/мин
//BSOIOutIntStruct BSOIOutNRight; // PackId = 52; Обороты воздушного винта правого двигателя, об/мин
//BSOIOutIntStruct BSOIOutNGasGenLeft; // PackId = 53; Обороты газогенератора левого двигателя, %
//BSOIOutIntStruct BSOIOutNGasGenRight; // PackId = 54; Обороты газогенератора правого двигателя, %
//BSOIOutIntStruct BSOIOutTTurbLeft; // PackId = 55; Температура между турбиной газогенератора и турбиной воздушного винта левого двигателя, градус
//BSOIOutIntStruct BSOIOutTTurbRight; // PackId = 56; Температура между турбиной газогенератора и турбиной воздушного винта правого двигателя, градус
//BSOIOutIntStruct BSOIOutUoporPot; // PackId = 57; Опорное напряжение для датчиков на основе потенциометров и термосопротивлений, вольт
//BSOIOutIntStruct BSOIOutUoporFuelLeftTanks; // PackId = 58; Опорное напряжение для датчика уровня топлива в левой системе топливных баков, вольт
//BSOIOutIntStruct BSOIOutUoporFuelRightTanks; // PackId = 59; Опорное напряжение для датчика уровня топлива в правой системе топливных баков, вольт
//BSOIOutIntStruct BSOIOutUoporFuelLeftTerm; // PackId = 60; Опорное напряжение для датчика уровня топлива в левом концевом баке, вольт
//BSOIOutIntStruct BSOIOutUoporFuelRightTerm; // PackId = 61; Опорное напряжение для датчика уровня топлива в правом концевом баке, вольт
//BSOIOutIntStruct BSOIOutUoporPFuelLeft; // PackId = 62; Опорное напряжение для датчика давления топлива левой группы, вольт
//BSOIOutIntStruct BSOIOutUoporPOilLeft; // PackId = 63; Опорное напряжение для датчика давления масла левой группы, вольт
//BSOIOutIntStruct BSOIOutUoporPFuelRight; // PackId = 64; Опорное напряжение для датчика давления топлива правой группы, вольт
//BSOIOutIntStruct BSOIOutUoporPOilRight; // PackId = 65; Опорное напряжение для датчика давления масла правой группы, вольт
//BSOIOutIntStruct BSOIOutUoporPGydroMain; // PackId = 66; Опорное напряжение для датчика давления гидравлической жидкости в основном контуре, вольт
//BSOIOutIntStruct BSOIOutUoporPGydroBreak; // PackId = 67; Опорное напряжение для датчика давления гидравлической жидкости в контуре тормозов, вольт
//BSOIOutIntStruct BSOIOutTorqLeft_; // PackId = 85; Крутящий момент левого двигателя, %
//BSOIOutIntStruct BSOIOutTorqRight_; // PackId = 86; Крутящий момент правого двигателя, %
//BSOIOutFloatStruct BSOIOutAttackAngle1; // PackId = 68; Угол атаки 1, [-30..30], градусы
//BSOIOutFloatStruct BSOIOutAttackAngle2; // PackId = 75; Угол атаки 2, [-30..30], градусы
//BSOIOutFloatStruct BSOIOutPBFireExt; // PackId = 76; Давление огнетушителя багажного отсека [0..1.6], МПа
//BSOIOutFloatStruct BSOIOutTrimmerElev; // PackId = 77; Триммер руля высоты [-10..10], градусы
//BSOIOutFloatStruct BSOIOutTrimmerAiler; // PackId = 78; Триммер элеронов [-10..10], градусы
//BSOIOutIntStruct BSOIOutNGasGenLeftU; // PackId = 81; Обороты газогенератора левого двигателя (постоянное напряжение), %
//BSOIOutIntStruct BSOIOutNGasGenRightU; // PackId = 82; Обороты газогенератора правого двигателя (постоянное напряжение), %
//BSOIOutIntStruct BSOIOutFuelLevAddTank; // PackId = 83; Уровень топлива в дополнительном топливном баке, л
//BSOIOutRK1Struct BSOIOutRK1; // PackId = 69; Дискретные сигналы 1
//BSOIOutRK2Struct BSOIOutRK2; // PackId = 70; Дискретные сигналы 2
//BSOIOutRK3Struct BSOIOutRK3; // PackId = 71; Дискретные сигналы 3
//BSOIOutRK4Struct BSOIOutRK4; // PackId = 72; Дискретные сигналы 4
//BSOIOutRK5Struct BSOIOutRK5; // PackId = 73; Дискретные сигналы 5
//BSOIOutRK6Struct BSOIOutRK6; // PackId = 74; Дискретные сигналы 6
//BSOIOutRK7Struct BSOIOutRK7; // PackId = 79; Дискретные сигналы 7
//BSOIOutRK8Struct BSOIOutRK8; // PackId = 84; Дискретные сигналы 8
//BSOIOutCWStruct BSOIOutCW; // PackId = 80; Слово состояния БСОИ

/////////////////////////////////////////////////////////////////////////////////////////////////////////


//========================== Защищенная система регистрации параметрической информации БУР-410================================

// Слова синхронизации
struct BURInSyncStruct {
    uint16_t Sync1 : 12; // Слово Sync1 (0x247)
    uint16_t Sync2 : 12; // Слово Sync2 (0x5B8)
    uint16_t Sync3 : 12; // Слово Sync3 (0xA47)
    uint16_t Sync4 : 12; // Слово Sync4 (0xDB8)
} __attribute__((packed));

// Номер самолета
struct BURInNAirplaneStruct {
    uint8_t D1 : 4; // Единицы номера самолета
    uint8_t D10 : 4; // Десятки номера самолета
    uint8_t D100 : 4; // Сотни номера самолета
    uint8_t D1000 : 4; // Тысячи номера самолета
    uint8_t D10000 : 4; // Десятки тысяч номера самолета
} __attribute__((packed));

//Дата вылета
struct BURInFlightDateStruct {
    uint8_t D; // День
    uint8_t M; // Месяц
    uint8_t Y; // Год
} __attribute__((packed));

// Шифр задания
struct BURInCypherStruct {
    uint8_t C1 : 4; // 1 символ шифра
    uint8_t C2 : 4; // 2 символ шифра
    uint8_t C3 : 4; // 3 символ шифра
    uint8_t C4 : 4; // 4 символ шифра
} __attribute__((packed));

//Дополнительные структуры (достаточно передать один раз за полет)
struct BURInAddStruct {     
    BURInSyncStruct Sync;
    BURInNAirplaneStruct NAirplane;
    BURInFlightDateStruct FlightDate;
    BURInCypherStruct Cypher;
} __attribute__((packed));

//Время
struct BURInTimeStruct {      
    uint8_t Sec; // Секунды
    uint8_t Min; // Минуты
    uint8_t Hours; // Часы
} __attribute__((packed));

//Счетчик

struct BURInCountStruct {     
    uint16_t Count; // Счетчик 0-4095
} __attribute__((packed));

// Cлово состояния ИБКО
struct BURInCWIBKOStruct {
    uint8_t FaultPNS1 : 1; // Отказ ПНС №1 «0» - исправен, «1» - отказ
    uint8_t FaultPNS2 : 1; // Отказ ПНС №2 
    uint8_t FaultPNS3 : 1; // Отказ ПНС №3 
    uint8_t FaultICI1 : 1; // Отказ ИЦИ №1 
    uint8_t FaultICI2 : 1; // Отказ ИЦИ №2 
    uint8_t FaultICI3 : 1; // Отказ ИЦИ №3 
    uint8_t FaultBKV1 : 1; // Отказ БКВ №1     
    uint8_t FaultBKV2 : 1; // Отказ БКВ №2 
    uint8_t FaultBKV3 : 1; // Отказ БКВ №3 
    uint8_t FaultMFPU1 : 1; // Отказ МФПУ №1 
    uint8_t FaultMFPU2 : 1; // Отказ МФПУ №2 
    uint8_t FaultDT : 1; // Отказ ДТ  
    uint8_t FaultMMK : 1; // Отказ ММК  
    uint8_t FaultEth1 : 1; // Отказ контроллера Ethernet №1  
    uint8_t FaultEth2 : 1; // Отказ контроллера Ethernet №2 
    uint8_t FaultSNS1 : 1; // Отказ СНС №1
    uint8_t FaultSNS2 : 1; // Отказ СНС №2
    uint8_t FaultSNS3 : 1; // Отказ СНС №3
    uint8_t FaultSVS1 : 1; // Отказ СВС №1
    uint8_t FaultSVS2 : 1; // Отказ СВС №2
    uint8_t FaultSVS3 : 1; // Отказ СВС №3 
    uint8_t FaultCVISU : 1; // Отказ ЦВИСУ
    uint8_t FaultRV : 1; // Отказ РВ
    uint8_t Reserv : 1; // Резерв
} __attribute__((packed));

// Cлово состояния БКС
struct BURInCWBKSStruct {
    uint8_t Count : 4; // Синхронизация обмена (круговой счетчик)
    uint8_t BKSCond : 2; // Состояние БКС (0 - работа, 1 - контроль, 2 - резерв, 3 - отказ)
    uint8_t CIMSA : 1; // Исправность ЦИМС-А (0 - отказ, 1 - исправность)
    uint8_t DMV1 : 1; // Исправность Прима-ДМВ1 (0 - отказ, 1 - исправность)
    uint8_t DMV2 : 1; // Исправность Прима-ДМВ2 (0 - отказ, 1 - исправность)
    uint8_t KV : 1; // Исправность Прима-КВ (0 - отказ, 1 - исправность)
    uint8_t B8_50KR1 : 1; // Исправность Б8-50 КР№1 (0 - отказ, 1 - исправность)
    uint8_t B8_50KR2 : 1; // Исправность Б8-50 КР№2 (0 - отказ, 1 - исправность)
    uint8_t B7V_35A : 1; // Исправность Б7В-35А (0 - отказ, 1 - исправность)
    uint8_t UNCh2x10 : 1; // Исправность УНЧ 2х10 (0 - отказ, 1 - исправность)
    uint8_t UNCh2x3 : 1; // Исправность УНЧ 2х3 (0 - отказ, 1 - исправность)
    uint8_t Reserv : 1; // Резерв
} __attribute__((packed));

// Неисправности ДМВ
struct BURInFaultDMVStruct {
    uint8_t FaultPRS : 1; // Отказ ПРС (0 - исправен, 1 - отказ)
    uint8_t FaultPPRCh : 1; // Отказ модуля ППРЧ (0 - исправен, 1 - отказ)
    uint8_t FaultUU : 1; // Отказ УУ (0 - исправен, 1 - отказ)
    uint8_t FaultAP : 1; // Отказ АП (0 - исправен, 1 - отказ)
    uint8_t FaultUM : 1; // Отказ УМ (0 - исправен, 1 - отказ)
    uint8_t FaultPRV : 1; // Отказ ПРВ (0 - исправен, 1 - отказ)
    uint8_t FaultCOS : 1; // Отказ ЦОС (0 - исправен, 1 - отказ)
    uint8_t FaultVIP : 1; // Отказ ВИП (0 - исправен, 1 - отказ)
    uint8_t FaultAct : 1; // Нет возбуждения (0 - исправен, 1 - отказ)
    uint8_t FaultNPG_PRV : 1; // Ошибка НПГ-ПРВ (0 - исправен, 1 - отказ)
    uint8_t FaultPG_PRV : 1; // Ошибка ПГ-ПРВ (0 - исправен, 1 - отказ)
    uint8_t UMOverHeat : 1; // Перегрев УМ (0 - исправен, 1 - отказ)
    uint8_t FaultKSV : 1; // Отказ по КСВ (0 - исправен, 1 - отказ)
    uint8_t NoPowwer : 1; // Нет мощности (0 - исправен, 1 - отказ)
    uint8_t FaultRD : 1; // Ошибка загр РД (0 - исправен, 1 - отказ)
    uint8_t FaultCL : 1; // Неисправность линии управления (0 - исправен, 1 - отказ)
} __attribute__((packed));

// Неисправности ПРИМА-КВ
struct BURInFaultKVStruct {
    uint8_t FaultModem : 1; // Отказ Модем (0 - исправен, 1 - отказ)
    uint8_t FaultPRD : 1; // Отказ ПРД (0 - исправен, 1 - отказ)
    uint8_t FaultPRM : 1; // Отказ ПРМ (0 - исправен, 1 - отказ)
    uint8_t FaultPRS : 1; // Отказ ПРС (0 - исправен, 1 - отказ)
    uint8_t FaultAVSK : 1; // Отказ АВСК (0 - исправен, 1 - отказ)
    uint8_t FaultUM : 1; // Отказ УМ (0 - исправен, 1 - отказ)
    uint8_t FaultASU : 1; // Отказ АСУ (0 - исправен, 1 - отказ)
    uint8_t FaultVIP : 1; // Отказ ВИП (0 - исправен, 1 - отказ)
    uint8_t FaultBaroASU : 1; // БАРО АСУ (0 - исправен, 1 - отказ)
    uint8_t FaultThermoASU : 1; // Термо АСУ (0 - исправен, 1 - отказ)
    uint8_t FaultThermoUM : 1; // Термо УМ (0 - исправен, 1 - отказ)
    uint8_t FaultCL : 1; // Неисправность линии управления (0 - исправен, 1 - отказ)
    uint8_t Reserv : 4; // Резерв    
} __attribute__((packed));

// Неисправности ЦИМС-А
struct BURInFaultCIMSAStruct {
    uint8_t FaultDictARO : 1; // Словарь АРО (0 - исправен, 1 - отказ)
    uint8_t FaultPSBK : 1; // ПСБК (0 - исправен, 1 - отказ)
    uint8_t FaultARO : 1; // АРО (0 - исправен, 1 - отказ)
    uint8_t FaultAVSK : 1; // АВСК (0 - исправен, 1 - отказ)
    uint8_t FaultSCV1 : 1; // СЦВ1 (0 - исправен, 1 - отказ)
    uint8_t FaultSCV2 : 1; // СЦВ2 (0 - исправен, 1 - отказ)
    uint8_t Reserv : 2; // Резерв    
} __attribute__((packed));

// Слово состояния 1 ДМВ
struct BURInCW1DMVStruct {
    uint8_t ChNum; // Номер канала (1-80)
    uint8_t PSh : 1; // ПШ (0 - отключено, 1 - включено)
    uint8_t FRCH_PPRCH : 1; // ФРЧ/ППРЧ (0 - ФРЧ, 1 - ППРЧ)
    uint8_t Mod : 3; // Модуляция (0 - АМУ, 1 - АМШ, 2 - ЧМ, 3 - АМ)
    uint8_t RRCH : 1; // РРЧ (0 - высокая, 1 - пониженная)
    uint8_t AP : 1; // АП (0 - отключено, 1 - включено)
    uint8_t Contr : 1; // Контроль (0 - отключено, 1 - включено)
    uint8_t Pow : 2; // Мощность (0 - 10%, 1 - 25%, 2 - 50%, 3 - 100%)
    uint8_t NU : 1; // Признак НУ (0 - отключено, 1 - включено)
    uint8_t Primary : 1; // Выбрана командиром (0 - не выбрана, 1 - выбрана)
    uint8_t Secondary : 1; // Выбрана вторым членом экипажа (0 - не выбрана, 1 - выбрана)
    uint8_t Reserv : 3; // Резерв  
} __attribute__((packed));

// Слово состояния 2 ДМВ
struct BURInCW2DMVStruct {
    uint32_t Freq; // Частота, кГц
} __attribute__((packed));

// Слово состояния 3 ДМВ
struct BURInCW3DMVStruct {
    uint8_t TFL : 1; // Прием ТФЛ (0 - нет приема, 1 - идет прием)
    uint8_t Izl : 1; // Излучение (0 - нет излучения, 1 - есть излучение)
    uint8_t SA : 3; // Не используется
    uint8_t AP : 1; // Прием АП (0 - нет приема, 1 - идет прием)
    uint8_t Reserv : 2; // Резерв  
} __attribute__((packed));

// Слово состояния 1 ПРИМА-КВ
struct BURInCW1KVStruct {
    uint8_t ChNum; // Номер канала (1-40)
    uint8_t PSh : 1; // ПШ (0 - отключено, 1 - включено)
    uint8_t Mod : 4; // Модуляция (0 - R3E 300-3400 ВБП (ОМ1в), 1 - R3E 300-3400 НБП (ОМ1н), 2 - J3E 300-3400 ВБП (ОМв), 3 - J3E 300-3400 НБП (ОМн),
    // 4 - J3E 300-2700 ВБП (Ому), 12 - A3E/H3E 300-3400 ВБП (АМэ), 13 - A3E/H3E 300-2700 ВБП (АМу))
    uint8_t Contr : 1; // Контроль (0 - отключено, 1 - включено)
    uint8_t Pow : 1; // Мощность (0 - 10%, 1 - 25%, 2 - 50%, 3 - 100%)
    uint8_t NU : 1; // Признак НУ (0 - отключено, 1 - включено)
    uint8_t Primary : 1; // Выбрана командиром (0 - не выбрана, 1 - выбрана)
    uint8_t Secondary : 1; // Выбрана вторым членом экипажа (0 - не выбрана, 1 - выбрана)
    uint8_t Reserv : 6; // Резерв  
} __attribute__((packed));

// Слово состояния 2 ПРИМА-КВ
struct BURInCW2KVStruct {
    uint32_t Freq; // Частота, Гц
} __attribute__((packed));

// Слово состояния 3 ПРИМА-КВ
struct BURInCW3KVStruct {
    uint8_t TFL : 1; // Прием ТФЛ (0 - нет приема, 1 - идет прием)
    uint8_t Izl : 1; // Излучение (0 - нет излучения, 1 - есть излучение)
    uint8_t SA : 2; // Не используется
    uint8_t Reserv : 4; // Резерв  
} __attribute__((packed));

// Слово состояния БСОИ
struct BURInCWBSOIStruct {
    uint8_t FaultBSOI : 1; // Отказ БСОИ (0 - исправен, 1 - отказ)
    uint8_t FaultUU : 1; // Отказ УУ (0 - исправен, 1 - отказ)
    uint8_t FaultDPK : 1; // Отказ ДПК (0 - исправен, 1 - отказ)
    uint8_t FaultRK : 1; // Отказ РК (0 - исправен, 1 - отказ)
    uint8_t FaultMAS2 : 1; // Отказ МАС2 (0 - исправен, 1 - отказ)
    uint8_t FaultMAS1 : 1; // Отказ МАС1 (0 - исправен, 1 - отказ)
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)
} __attribute__((packed));

// Слово состояния 1 VIM
struct BURInCW1VIMStruct {
    uint16_t Mode : 2; // Режим работы: 0 - ILS, 1 - СП-50, 2 - VOR, 3 - Маркер
    uint16_t FaultVChK : 1; // Отказ ВЧ К: 0 - нет, 1 - да
    uint16_t FaultVChG : 1; // Отказ ВЧ Г: 0 - нет, 1 - да
    uint16_t FaultUOS : 1; // Отказ УОС: 0 - нет, 1 - да
    uint16_t FaultUVV : 1; // Отказ УВВ: 0 - нет, 1 - да
    uint16_t NoInW : 1; // Отсутствуют входные слова: 0 - присутствуют, 1 - отсутствуют
    uint16_t ReTuneDisable : 1; // Запрет перестройки: 0 - нет, 1 - да
    uint16_t FaultModule : 1; // Отказ блока: 0 - нет, 1 - да
    uint16_t AzToCorr : 1; // Коррекция азимута "НА": 0 - нет, 1 - да
    uint16_t AzFromCorr : 1; // Коррекция азимута "ОТ": 0 - нет, 1 - да
    uint16_t KReady : 1; // Готовность К: 0 - нет, 1 - да
    uint16_t GReady : 1; // Готовность Г: 0 - нет, 1 - да
    uint16_t Matrix : 2; //     Матрица состояния: 00 – нормальная работа, 01 – информация недостоверна, 10 – Тест, 11 – нормальная работа  
    uint16_t Reserv : 1; // Резерв 
} __attribute__((packed));

// Слово состояния 2 VIM
struct BURInCW2VIMStruct { 
    uint16_t FaultHF : 1; // Отказ ВЧ: 0- нет , 1- отказ
    uint16_t FaultLF : 1; // Отказ НЧ: 0- нет , 1- отказ
    uint16_t NoContr : 1; // Отсутствует управление: 1- отсутствует
    uint16_t FaultCourseAerial : 1; // Отказ курсовой антенны: 0- нет , 1- отказ
    uint16_t FaultGlissAerial : 1; // Отказ глиссадной антенны: 0- нет , 1- отказ
    uint16_t NearMark400 : 1; // Пролет ближнего маркерного маяка 400 Гц: 0 - нет, 1 - да
    uint16_t MidMark1300 : 1; // Пролет среднего маркерного маяка 1300 Гц: 0 - нет, 1 - да
    uint16_t FarMark3000 : 1; // Пролет дальнего маркерного маяка 3000 Гц: 0 - нет, 1 - да
    uint16_t MarkReliable : 1; // Информация о маркерных маяках достоверна: 0 - нет, 1 - да
    uint16_t ReTuneDisableAz : 1; // Отклонение от заданного азимута. Запрет перестройки: 0 - нет, 1 - да
    uint16_t ReTuneDisableGl : 1; // Отклонение от глиссады снижения. Запрет перестройки: 0 - нет, 1 - да
    uint16_t Matrix : 2; //     Матрица состояния: 00 – нормальная работа, 01 – информация недостоверна, 10 – Тест, 11 – нормальная работа 
    uint16_t Reserv : 3; // Резерв     
} __attribute__((packed));

// Слово состояния РСБН-НП
struct BURInCWRSBNStruct {
    uint8_t FaultBNP : 1; // Отказ БНП (0 - исправен, 1 - отказ)
    uint8_t FaultRSBN1 : 1; // Отказ РСБН по входу 1 (0 - исправен, 1 - отказ)
    uint8_t FaultRSBN2 : 1; // Отказ РСБН по входу 2 (0 - исправен, 1 - отказ)
    uint8_t FaultAFS : 1; // Отказ АФС РСБН (0 - исправен, 1 - отказ)
    uint8_t FaultRSBN : 1; // Отказ РСБН (0 - исправен, 1 - отказ)
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint8_t Reserv : 1; // Резерв  
} __attribute__((packed));

// ДС 1
struct BURInDS1Struct {
    uint8_t GearPressed : 1; // Шасси обжато
    uint8_t US2B : 1; // Наличие напряжения S2B
    uint8_t US3B : 1; // Наличие напряжения S3B
    uint8_t US1A : 1; // Наличие напряжения S1A
    uint8_t US1B : 1; // Наличие напряжения S1B
    uint8_t FaultU26_1 : 1; // Отсутствие выходного напряжения преобразователя 26В №1
    uint8_t FaultU26_2 : 1; // Отсутствие выходного напряжения преобразователя 26В №2
    uint8_t FaultU36_1 : 1; // Отсутствие выходного напряжения преобразователя 36В №1
    uint8_t FaultU36_2 : 1; // Отсутствие выходного напряжения преобразователя 36В №2
    uint8_t Bell : 1; // Вызов экипажа
    uint8_t Ailer0 : 1; // Закрылки в положении 0 градусов
    uint8_t Ailer18 : 1; // Закрылки в положении 18 градусов
    uint8_t Ailer42 : 1; // Закрылки в положении 42 градуса
    uint8_t SetAiler0 : 1; // Выпусти закрылки в положение 18 градусов
    uint8_t ReadyAUK : 1; // Готовность АУК
    uint8_t AUK : 1; // Выпущен щит АУК
    uint8_t FaultFuelLeftEng : 1; // Давление топлива в левом двигателе низкое
    uint8_t FaultFuelRightEng : 1; // Давление топлива в правом двигателе низкое
    uint8_t FuelLeftTankLow : 1; // Низкий уровень топлива левой системы топливных баков
    uint8_t FuelRightTankLow : 1; // Низкий уровень топлива правой системы топливных баков
    uint8_t FuelRing : 1; // Включено кольцевание топлива
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint8_t Reserv : 1; // Резерв  
} __attribute__((packed));

// ДС 2
struct BURInDS2Struct {
    uint8_t SwapFuelLeftTerm : 1; // Включена перекачка топлива из левого концевого топливного бака
    uint8_t SwapFuelRightTerm : 1; // Включена перекачка топлива из правого концевого топливного бака
    uint8_t SetSwapFuelLeft : 1; // Включи перекачку топлива в левую систему топливных баков
    uint8_t SetSwapFuelRight : 1; // Включи перекачку топлива в правую систему топливных баков
    uint8_t BypasFuelFiltrLeft : 1; // Открытие обходного предохранительного клапана топливного фильтра левой системы
    uint8_t BypasFuelFiltrRight : 1; // Открытие обходного предохранительного клапана топливного фильтра правой системы
    uint8_t TempFuelLeftOver90 : 1; // Температура жидкости в обратном контуре насосов левой системы превышает 90 градусов
    uint8_t TempFuelRightOver90 : 1; // Температура жидкости в обратном контуре насосов правой системы превышает 90 градусов
    uint8_t Icing : 1; // Обледенение
    uint8_t LeftIceSep : 1; // Открыты левые створки сепараторов льда
    uint8_t RightIceSep : 1; // Открыты правые створки сепараторов льда
    uint8_t PSNHeat : 1; // Включен обогрев ПСН
    uint8_t PSD1Heat : 1; // Включен обогрев приемника статического давления 1
    uint8_t PSD2Heat : 1; // Включен обогрев приемника статического давления 2
    uint8_t PPD1Heat : 1; // Включен обогрев приемника полного давления 1
    uint8_t PPD2Heat : 1; // Включен обогрев приемника полного давления 2
    uint8_t LeftIllumHeat : 1; // Включен обогрев стекол слева
    uint8_t RightIllumHeat : 1; // Включен обогрев стекол справа
    uint8_t FaultPOSLeftProp : 1; // Отказ ПОС левого винта
    uint8_t FaultPOSRightProp : 1; // Отказ ПОС правого винта
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint8_t Reserv : 2; // Резерв  
} __attribute__((packed));

// ДС 3
struct BURInDS3Struct {
    uint8_t LeftGear : 1; // Левое шасси выпущено
    uint8_t FrontGear : 1; // Переднее шасси выпущено
    uint8_t RightGear : 1; // Правое шасси выпущено
    uint8_t LeftPropStop : 1; // Упор винта левого
    uint8_t SetGear : 1; // Выпусти шасси
    uint8_t RightPropStop : 1; // Упор винта правого
    uint8_t ABSLeftGear : 1; // Срабатывание АБС левого шасси
    uint8_t ABSRightGear : 1; // Срабатывание АБС правого шасси
    uint8_t Stall : 1; // Сваливание
    uint8_t FlugPumpLeft : 1; // Включен вспомогательный флюгерный насос левого двигателя
    uint8_t FlugPumpRight : 1; // Включен вспомогательный флюгерный насос правого двигателя
    uint8_t AutoFlugLeft : 1; // Автоматическое флюгирование левого двигателя
    uint8_t AutoFlugRight : 1; // Автоматическое флюгирование правого двигателя
    uint8_t BetaEngLeft : 1; // Диапазон Бета левого двигателя
    uint8_t BetaEngRight : 1; // Диапазон Бета правого двигателя
    uint8_t EBOEngLeft : 1; // Готовность ЭБО левого двигателя
    uint8_t EBOEngRight : 1; // Готовность ЭБО правого двигателя
    uint8_t FaultUACLeft : 1; // Отсутствие выходного напряжения генератора переменного тока левого
    uint8_t FaultUACRight : 1; // Отсутствие выходного напряжения генератора переменного тока правого
    uint8_t FaultUDCLeft : 1; // Отсутствие выходного напряжения генератора постоянного тока левого
    uint8_t FaultUDCRight : 1; // Отсутствие выходного напряжения генератора постоянного тока правого
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint8_t Reserv : 1; // Резерв  
} __attribute__((packed));

// ДС 4
struct BURInDS4Struct {
    uint8_t EmergEngLeft : 1; // Включена система управления аварийным режимом левого двигателя при помощи рычагов управления стоп-кранами
    uint8_t EmergEngRight : 1; // Включена система управления аварийным режимом правого двигателя при помощи рычагов управления стоп-кранами
    uint8_t LowPOilEngLeft : 1; // Низкое давление масла в левом двигателе
    uint8_t LowPOilEngRight : 1; // Низкое давление масла в правом двигателе
    uint8_t SwarfLeft : 1; // Наличие стружки в левом маслобаке
    uint8_t SwarfRight : 1; // Наличие стружки в правом маслобаке
    uint8_t StartEng : 1; // Запуск двигателей
    uint8_t ExcursEngLeft : 1; // Превышение параметров левого двигателя
    uint8_t ExcursEngRight : 1; // Превышение параметров правого двигателя
    uint8_t BypassOilEngLeft : 1; // Открыт предохранительный клапан масляной системы левого двигателя
    uint8_t BypassOilEngRight : 1; // Открыт предохранительный клапан масляной системы правого двигателя
    uint8_t TaxLight : 1; // Включены рулежные фары
    uint8_t LandLight : 1; // Включены посадочные фары
    uint8_t HFrontWheel : 1; // Задействовано ручное управление передним колесом
    uint8_t FFrontWheel : 1; // Задействовано ножное управление передним колесом
    uint8_t FaultBatt : 1; // Отказ аккумулятора
    uint8_t Batt1OverHeat : 1; // Перегрев аккумулятора №1
    uint8_t Batt2OverHeat : 1; // Перегрев аккумулятора №2
    uint8_t Door : 1; // Дверь открыта
    uint8_t GroundPower : 1; // Аэродромное питание
    uint8_t RadioTang : 1; // Нажатие тангенты радиосвязи
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint8_t Reserv : 1; // Резерв  
} __attribute__((packed));

// ДС 5
struct BURInDS5Struct {
    uint16_t TestButt : 1; // Нажата кнопка тестирования табло сигнализации
    uint16_t LeftGear : 1; // Левое шасси в процессе уборки/выпуска
    uint16_t FrontGear : 1; // Переднее шасси в процессе уборки/выпуска
    uint16_t RightGear : 1; // Правое шасси в процессе уборки/выпуска
    uint16_t FireLeftEng : 1; // Пожар левого двигателя
    uint16_t FireRightEng : 1; // Пожар правого двигателя
    uint16_t FireFrontBag : 1; // Пожар переднего багажного отсека
    uint16_t Inter : 1; // Выпущены интерцепторы
    uint16_t AutoPilot : 1; // Включенное состояние автопилота
    uint16_t ActivePNS : 2; // Признак ведущего ПНС: 0-Нет ведущего ПНС, 1-Ведущее ПНС 1, 2-Ведущее ПНС 2, 3-Ведущее ПНС 3
    uint16_t Reserv1 : 6; // Резерв
    uint16_t KVRMode : 1; // Курсо-воздушный режим счисления: «0» – отсутствие признака, «1» – наличие признака
    uint16_t SNSCorr : 1; // Коррекция координат по СНС: «0» – отсутствие коррекции, «1» – наличие коррекции
    uint16_t RSBNCorr : 1; //Коррекция координат по РСБН: «0» – отсутствие коррекции, «1» – наличие коррекции
    uint16_t VORDMECorr : 1; //Коррекция по VOR/DME: «0» – отсутствие коррекции, «1» – наличие коррекции
    uint16_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint16_t Reserv2 : 9; // Резерв  
} __attribute__((packed));

// ДС 6
struct BURInDS6Struct {
    uint8_t DeIceA : 1; // Работа противообледенительной системы А
    uint8_t DeIceB : 1; // Работа противообледенительной системы В
    uint8_t DeIceC : 1; //Работа противообледенительной системы С
    uint8_t GOGood : 1; // Исправность ответчика ГО
    uint8_t FaultGO : 1; // Отказ ответчика ГО
    uint8_t MinOilLevL : 1; // Уровень масла левого минимальный
    uint8_t MinOilLevR : 1; // Уровень масла правого минимальный
    uint8_t MaxTempL : 1; // Максимальная температура левого двигателя
    uint8_t MaxTempR : 1; // Максимальная температура правого двигателя
    uint8_t RegOn : 1; // Регистратор включен
    uint8_t ARCFault : 1; // Отказ АРК
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint8_t ESGO115 : 1; // Наличие 115 В 400 Гц ЕСГО
    uint8_t ESGORes : 1; // Индикатор запасной ЕСГО        
    uint8_t Reserv : 1; // Резерв  
} __attribute__((packed));

// ДС 7
struct BURInDS7Struct {
    uint32_t MessAtaPr : 1; // Сообщение «Угол атаки предельный»
    uint32_t MessOverLoadPr : 1; // Сообщение «Перегрузка предельная»
    uint32_t MessVpr : 1; // Сообщение «Скорость предельная»
    uint32_t MessFault2Gen : 1; // Сообщение «Отказ двух генераторов = »
    uint32_t MessHOp : 1; // Сообщение «Высота опасная»
    uint32_t MessVLow : 1; // Сообщение «Скорость мала»
    uint32_t MessPOLowL : 1; // Сообщение «Давление масла левого мало»
    uint32_t MessPOLowR : 1; // Сообщение «Давление масла правого мало»
    uint32_t MessPFLowL : 1; // Сообщение «Давление топлива левого мало»
    uint32_t MessPFLowR : 1; // Сообщение «Давление топлива правого мало»
    uint32_t MessTOL : 1; // Сообщение «Температура масла левого»
    uint32_t MessTOR : 1; // Сообщение «Температура масла правого»
    uint32_t MessStartDenL : 1; // Сообщение «Запуск левого запрещен»
    uint32_t MessStartRDen : 1; // Сообщение «Запуск правого запрещен»
    uint32_t MessDoor : 1; // Сообщение «Дверь»
    uint32_t MessAlt4200 : 1; // Сообщение «Высота больше 4200»
    uint32_t MessFaultGen28L : 1; // Сообщение «Отказ генератора 28В лев»
    uint32_t MessFaultGen28R : 1; // Сообщение «Отказ генератора 28В прав»
    uint32_t MessFaultGen115L : 1; // Сообщение «Отказ генератора 115В лев»
    uint32_t MessFaultGen115R : 1; // Сообщение «Отказ генератора 115В прав»
    uint32_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint32_t Reserv : 10; // Резерв
} __attribute__((packed));

// ДС 8
struct BURInDS8Struct {
    uint16_t MessFaultConv36_1 : 1; // Сообщение «Отказ преобразователя №1 36В»
    uint16_t MessFaultConv36_2 : 1; // Сообщение «Отказ преобразователя №2 36В»
    uint16_t MessFaultConv26_1 : 1; // Сообщение «Отказ преобразователя №1 26В»
    uint16_t MessFaultConv26_2 : 1; // Сообщение «Отказ преобразователя №2 26В»
    uint16_t MessCheckInterc : 1; // Сообщение «Закрылки проверь»
    uint16_t MessCheckGear : 1; // Сообщение «Шасси проверь»
    uint16_t MessStopStart : 1; // Сообщение «Запуск прекрати»
    uint16_t MessTOELowL : 1; // Сообщение «Температура масла левого двигателя мала»
    uint16_t MessTOELowR : 1; // Сообщение «Температура масла правого двигателя мала»
    uint16_t MessCheckEchelon : 1; // Сообщение «Эшелон проверь»
    uint16_t MessCheckH : 1; // Сообщение «Высоту проверь»
    uint16_t MessHZad : 1; // Сообщение «Прошел заданную высоту»
    uint16_t Matrix : 2; // Матрица состояния
    uint16_t Reserv : 2; // Резерв
} __attribute__((packed));

// Слово состояния СО-2010
struct BURInCWSOStruct {
    uint8_t FaultSO2010 : 1; // Неисправность блока СО-2010 (0 - исправно, 1 - отказ)
    uint8_t FaultAFS1 : 1; // Отказ АФС частоты 837.5/740 МГц (0 - исправно, 1 - отказ)
    uint8_t FaultAFS2 : 1; // Отказ АФС частоты 1030/1090 МГц (0 - исправно, 1 - отказ)
    uint8_t FaultPNS12L1 : 1; // Отсутствие информации от ПНС 1, 2 (0 - исправно, 1 - отказ)
    uint8_t IncompletePNS12L1 : 1; // Неполная информация от ПНС 1, 2 (0 - исправно, 1 - отказ)
    uint8_t FaultPNS3L1 : 1; // Отсутствие информации от ПНС 3 (0 - исправно, 1 - отказ)
    uint8_t IncomplPNS3L1 : 1; // Неполная информация от ПНС 3 (0 - исправно, 1 - отказ)
    uint8_t FaultPNS12L2 : 1; // Отсутствие информации от ПНС 1, 2 (0 - исправно, 1 - отказ)
    uint8_t IncompletePNS12L2 : 1; // Неполная информация от ПНС 1, 2 (0 - исправно, 1 - отказ)
    uint8_t FaultPNS3L2 : 1; // Отсутствие информации от ПНС 3 (0 - исправно, 1 - отказ)
    uint8_t IncomplPNS3L2 : 1; // Неполная информация от ПНС 3 (0 - исправно, 1 - отказ)
    uint8_t IncorrAddrIKAO : 1; // Некорректный адрес ИКАО (0 - корректный, 1 - некорректный)
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint8_t Reserv : 2; // Резерв  
} __attribute__((packed));

// Сигналы маркерного приемника
struct BURInSMRStruct {
    uint8_t Near : 1; // Ближний МП
    uint8_t Middle : 1; // Средний МП
    uint8_t Far : 1; // Дальний МП
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint8_t Reserv : 3; // Резерв  
} __attribute__((packed));

// Остаток топлива для СО
struct BURInFuelSOStruct {
    uint8_t Fuel; // Остаток топлива, %
    uint8_t Matrix : 2; // Матрица состояния (0 - нормальная работа, 1, 2 - информация недостоверна, 3 - нет вычисленных данных)    
    uint8_t Reserv : 6; // Резерв  
} __attribute__((packed));

// Количество НТ №1
struct BURInNT1Struct {
    uint16_t RouteNum : 5; // Номер исполняемого маршрута: 0-нет исп. маршрута, 1–20- номер МРШ
    uint16_t PPMNum : 6; // Номер исполняемого ППМ: 0-нет исп. ППМ, 1–50- номер ППМ
    uint16_t GTNum : 7; // Номер исполняемой ГТ: 0-нет исп. ГТ, 1–100- номер ГТ
    uint16_t Reserv : 14; // Резерв  
} __attribute__((packed));

// Количество НТ №2
struct BURInNT2Struct {
    uint16_t CZNum : 5; // Номер исполняемого центра зоны: 0-нет исп. ЦЗ, 1–20- номер ЦЗ
    uint16_t RMRSBNNum : 5; // Номер исполняемого РМ РСБН: 0-нет исп. РМ РСБН, 1–20- номер РМ РСБН
    uint16_t RMVORNum : 5; // Номер исполняемого РМ VOR: 0-нет исп. РМ VOR, 1–20- номер РМ VOR
    uint16_t AFLNum : 5; // Номер исполняемого аэродрома посадки: 0 - нет исп. аэродрома, 1–20 - номер аэродрома
    uint16_t Reserv : 12; // Резерв  
} __attribute__((packed));

// Режимы самолетовождения
struct BURInFlightModeStruct {
    uint16_t TU : 1; // Способ траекторного управления: 0-маршрутный, 1-путевой
    uint16_t PPMPass : 2; // Способ прохода ППМ: 00 - проход, 01 - заход, 10 - ЛУР
    uint16_t FlightMode : 3; // Режимы самолетовождения: 0 - полет по маршруту (ПМРШ), 1 - полет по заданному курсу (ПЗК), 
    //2 - полет на навигационную точку (ПНТ), 3 - возврат, 4 - посадка, 5 - повторный заход на посадку
    uint16_t FlightTo : 1; // Функция «Полет прямо НА»: 0 - не задана, 1 - задана
    uint16_t FlightZPU : 1; // Функция «Полет с ручным заданным путевым углом (ЗПУ)» (резерв): 0 - не задана, 1 - задана 
    uint16_t CourseCorr : 1; // Наличие признака коррекции курса : «0» – отсутствие признака , «1» – наличие признака 
    uint16_t DirModeOn : 1; // Признак включения директорного режима
    uint16_t Reserv : 6; // Резерв
} __attribute__((packed));

// Структура слова «Состояние метеолокатора 1»
struct BURInMeteo1Struct {
    uint16_t FaultRLSS1 : 1; // Недостоверность РЛ информации в  СС 1: 0-достоверна, 1- недостоверна
    uint16_t DangerTurbul : 1; // Опасная турбулентность: 0- нет, 1- опасность
    uint16_t DangerMeteo : 1; // Опасные метеоусловия: 0- нет, 1- опасность
    uint16_t MWFOff : 1; // СВЧ отключено: 0- включено, 1- отключено
    uint16_t RangeUnits : 1; // Единицы измерения дальности: 0-морские мили, 1- километры
    uint16_t NoCommPNS : 1; // Нет связи с ПНС: 0-исправность, 1- нет связи
    uint16_t FaultAerial : 1; // Отказ антенны: 0-исправность, 1- отказ
    uint16_t FaultRecTrans : 1; // Отказ приемопередатчика: 0-исправность, 1- отказ
    uint16_t AerialStab : 1; // Стабилизация антенны; 0-выключена, 1-включена
    uint16_t MRLSMode : 3; // Режим работы МРЛС: 0-готов, 1-метео, 2-земля, 3-дежурный режим, 4-контроль, 7- метео/ВП
    uint16_t Reserv : 4; // Резерв    
    float AzAerialLean; // Угол наклона антенны (азимутальное сканирование)       
} __attribute__((packed));

// Структура слова «Состояние метеолокатора 2»
struct BURInMeteo2Struct {
    uint16_t FaultRLSS2 : 1; // Недостоверность РЛ информации в  СС 2: 0-достоверна, 1- недостоверна
    uint16_t Reserv : 15; // Резерв              
    float Gain; // Усиление
    float RangeRate; // Диапазон дальности
} __attribute__((packed));

// Структура слова «Состояние метеолокатора 3»

struct BURInMeteo3Struct {
    uint16_t FaultRLSS3 : 1; // Недостоверность РЛ информации в  СС 3: 0-достоверна, 1- недостоверна
    uint16_t Reserv : 15; // Резерв  
    float AzAerialScan; // Угол сканирования антенны (азимутальное сканирование)
} __attribute__((packed));

// Структура слова «Состояние метеолокатора 4»

struct BURInMeteo4Struct {
    uint16_t FaultRLSS4 : 1; // Недостоверность РЛ информации в  СС 4: 0-достоверна, 1- недостоверна
    uint16_t ScanMode : 1; // Сканирование: 0- азимутальное, 1-вертикальное
    uint16_t CoursorOn : 1; // Включение курсора: 0- выключен, 1- включен
    uint16_t Reserv : 13; // Резерв  
    float AerialLean; // Текущий угол наклона антенны
} __attribute__((packed));

// Структура слова «Состояние метеолокатора 5»

struct BURInMeteo5Struct {
    uint16_t FaultRLSS5 : 1; // Недостоверность РЛ информации в  СС 5: 0-достоверна, 1- недостоверна
    uint16_t Vydel : 6; // Выделение, 27 разряд равен 32
    uint16_t Reserv : 9; // Резерв
    float AzScanCourse; // КУА (Курс азимутального сканирования)    
} __attribute__((packed));

// Структура слова «Слово состояния ИБКО-2»

struct BURInIBKO2CondStruct {
    uint16_t BKV1Set : 1; // БКВ 1 выставка: 0 – отсутствие признака, 1 – наличие признака
    uint16_t BKV1Adj : 1; // БКВ 1 юстировка: 0 – отсутствие признака, 1 – наличие признака
    uint16_t BKV1Oper : 1; // БКВ 1 работа: 0 – отсутствие признака, 1 – наличие признака
    uint16_t BKV2Set : 1; // БКВ 2 выставка: 0 – отсутствие признака, 1 – наличие признака
    uint16_t BKV2Adj : 1; // БКВ 2 юстировка: 0 – отсутствие признака, 1 – наличие признака
    uint16_t BKV2Oper : 1; // БКВ 2 работа: 0 – отсутствие признака, 1 – наличие признака
    uint16_t BKV3Set : 1; // БКВ 3 выставка: 0 – отсутствие признака, 1 – наличие признака
    uint16_t BKV3Adj : 1; // БКВ 3 юстировка: 0 – отсутствие признака, 1 – наличие признака
    uint16_t BKV3Oper : 1; // БКВ 3 работа: 0 – отсутствие признака, 1 – наличие признака 
    uint16_t PNS1PowOff : 1; // Разовая команда снятия питания с блока ПНС №1
    uint16_t PNS2PowOff : 1; // Разовая команда снятия питания с блока ПНС №2
    uint16_t PNS3PowOff : 1; // Разовая команда снятия питания с блока ПНС №3
    uint16_t Matrix : 2; // Матрица состояния: 00 – нормальная работа; 11 – информация недостоверна
    uint16_t Reserv : 2; // Резерв         
} __attribute__((packed));

// Структура слова «Параметры ЦВ ИСУ 1»

struct BURInCVISU1ParStruct {
    uint16_t Mode : 3; // Режим работы: 0 ? ГЛОНАСС, 1 ? GPS, 2 ? ГЛОНАСС +GPS, 3 ? отладочный, 4 ? слепой поиск
    uint16_t Ellips : 2; // Опорный эллипсоид: 0 – WGS-84, 1 – ПЗ 90.02, 2 – СК 42, 3 – СК 95  
    uint16_t FaultGLONASS : 1; // Отказ ГЛОНАСС
    uint16_t FaultGPS : 1; // Отказ GPS
    uint16_t Matrix : 2; // Матрица состояния: 00 – нормальная работа; 11 – информация недостоверна    
    uint16_t Reserv : 7; // Резерв              
    uint8_t TimeS; // Время секунды
    uint8_t TimeM; // Время минуты       
} __attribute__((packed));

// Структура слова «Параметры ЦВ ИСУ 2»
struct BURInCVISU2ParStruct {
    uint8_t TimeH; // Время часы
    uint8_t DateD; // Дата день
    uint8_t DateM; // Дата месяц
    uint8_t DateY; // Дата год 
    uint16_t Matrix : 2; // Матрица состояния: 00 – нормальная работа; 11 – информация недостоверна
    uint16_t Reserv : 14; // Резерв    
} __attribute__((packed));


//Параметры из ИБКО в БСАП
struct BURInIBKOToBSAPStruct {
    uint16_t PNSMasterIspr : 1; // Общая исправность аппаратуры ИБКО
    uint16_t BKVMasterIspr : 1; // Исправности аппаратуры, участвующей в формировании данных угловых отклонений положения самолета (PITCH, ROLL)
    uint16_t AzVORCorr : 1; // Значение азимута от VOR корректно
    uint16_t AzRSBNCorr : 1; // Значение азимута от РСБН корректно
    uint16_t YawDevIspr : 1; // Исправности аппаратуры, участвующей в формировании данных угловой скорости рысканья
    uint16_t DAzILSCorr : 1; // Значение отклонения от азимута подхода от ILS корректно
    uint16_t DAzRSBNCorr : 1; // Значение отклонения от азимута подхода от РСБН корректно
    uint16_t DGlisILSCorr : 1; // Значение отклонения по глиссаде от ILS корректно
    uint16_t DGlisRSBNCorr : 1; // Значение отклонения по глиссаде от РСБН корректно  
    uint16_t PBarDevIspr : 1; // Исправности аппаратуры, участвующей в формировании сигнала барометрической высоты  
    uint16_t Land : 1; // Посадка
    uint16_t RSBNNPMode : 1; // Режим работы РСБН-НП/VIM-95: 1 – посадка; 0 – навигация
    uint16_t NavSource : 1; // Выбранный источник навигации РСБН-НП/VIM-95: 1 – VIM-95; 0 – РСБН-НП
    uint16_t Matrix : 2; // Матрица состояния: 00 - нормальная работа, 11 - информация недостоверна
    uint16_t Reserv : 1; // Резерв     
} __attribute__((packed));

// Параметры 1 из БСАП в ИБКО
struct BURInBSAPToIBKO1Struct {
    uint16_t APServoOn : 1; // Автопилот включен и управляет сервоприводами AP CLUTHC: 1 – управляет сервоприводами: 0 – отключен от сервоприводов
    uint16_t APValid : 1; // Автопилот исправен AP VALID: 1 – вкл. и исправен; 0 – выкл. / вкл. и неисправен
    uint16_t AltMode : 1; // Включен режим ALT: 1 – включен; 0 – выключен
    uint16_t ARMAlt : 1; // Предварительный режим ARM ALT: 1 – активирован; 0 – не активирован.    
    uint16_t HDGMode : 1; // Включен режим HDG: 1 – включен: 0 – выключен
    uint16_t NavMode : 1; // Включен режим NAV: 1 – включен: 0 – выключен
    uint16_t ARMNav : 1; // Предварительный режим ARM NAV: 1 – активирован: 0 – не активирован
    uint16_t APRMode : 1; // Включен режим APR: 1 – включен; 0 – выключен
    uint16_t ARMAPR : 1; // Предварительный режим ARM APR: 1 – активирован; 0 – не активирован
    uint16_t GSMode : 1; // Удержание глиссады GS: 1 – включен; 0 – выключен
    uint16_t BCMode : 1; //Включен режим BC: 1 – активирован; 0 – не активирован
    uint16_t IASMode : 1; // Включен режим IAS: 1 – включен; 0 – выключен
    uint16_t GAMode : 1; // Включен режим GA: 1 – включен; 0 – выключен
    uint16_t YD : 1; // Включен демпфер рыскания YD: 1 – включен; 0 – выключен
    uint16_t HalfBankMode : 1; // Включен режим HALF BANK: 1 – включен; 0 – выключен 
    uint16_t FDMode : 1; // Включен режим FD: 1 – включен; 0 – выключен   
    uint16_t CourseMode : 2; // Выбранный режим на пульте задачи курса: 0 - маршрут; 1 - РСБН/VOR; 2 – резерв; 3  - резерв         
    uint16_t Matrix : 2; // Матрица состояния: 00 - нормальная работа, 11 - информация недостоверна    
    uint16_t Reserv : 12; // Резерв  
} __attribute__((packed));

// СС 2 Ответчик УВД
 struct BURInSS2UVDStruct {
    uint16_t Mode1 : 1; // Работа / готов: 0- режим ACS или УВД; 1- режим ГОТОВ     
    uint16_t AirGround : 1; // Воздух / земля: 0 – воздух; 1 – земля      
    uint16_t AZNV : 1; // Статус АЗН-В: 0 – действует; 1 - неисправно или неактивно
    uint16_t Squit : 1; // Отключение расширенного сквиттера: 0 – выдача разрешена; 1 – выдача запрещена
    uint16_t AFSContr : 1; // Контроль АФС: 0 – АФС не контролируется; 1 – АФС контролируется
    uint16_t NACvCode : 2; // Код NACv  
    uint16_t SPIMode : 1; // Включение SPI: 0 – SPI не включен; 1 – SPI включен
    uint16_t Mode2 : 1; // Режим работы:  – УВД или ГОТОВ; 1 – ACS    
    uint16_t Emerg : 1; // Состояние аварии: 0 – отсутствует; 1 - присутствует
    uint16_t Matrix : 2; // Матрица состояния: 00 – нормальная работа; 11 – информация недостоверна
    uint16_t Reserv : 4; // Резерв    
} __attribute__((packed));

// Ведущие системы
struct BurInMasterSysStruct {
    uint16_t MasterBKV : 3; // Признак ведущего БКВ: 0 - Нет ведущего БКВ; 1 - Ведущее БКВ 1; 2 - Ведущее БКВ 2; 3 - Ведущее БКВ 3; 4 - Ведущий БИНС
    uint16_t MasterSNS : 3; // Признак ведущего СНС: 0 - Нет ведущего СНС; 1 - Ведущее СНС 1; 2 - Ведущее СНС 2; 3 - Ведущее СНС 3; 4 - Ведущее СНС ЦВ ИСУ
    uint16_t MasterSVS : 3; // Признак ведущего СВС: 0 - Нет ведущего СВС; 1 - Ведущее СВС 1; 2 - Ведущее СВС 2; 3 - Ведущее СВС 3; 4 - Ведущее СВС AC32№1; 5 - Ведущее СВС AC32№2
    uint16_t BINSCorrCoord : 2; // Коррекция координат по БИНС: 0 - нет коррекции, 1 - координаты БИНС инерциальные, 2 - координаты БИНС гибридные
    uint16_t Matrix : 2; // Матрица состояния: 00 – нормальная работа; 11 – информация недостоверна
    uint16_t Reserv : 3; // Резерв    
} __attribute__((packed));

// Аналоговые параметры
struct BURInFloatStruct { 
    float Data; // Данные
    uint8_t Matrix : 2; // Матрица состояния (0 - отказ аппаратуры, 3 - достоверное значение, 2, 1 - не используется)    
    uint8_t Reserv : 6; // Резерв
} __attribute__((packed));

struct BURInStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета  
    BURInCWIBKOStruct BURInCWIBKO; // Cлово состояния ИБКО
    BURInCWBKSStruct BURInCWBKS; // Cлово состояния БКС
    BURInFaultDMVStruct BURInFaultDMV1; // Неисправности ДМВ №1
    BURInFaultDMVStruct BURInFaultDMV2; // Неисправности ДМВ №2
    BURInFaultKVStruct BURInFaultKV; // Неисправности ПРИМА-КВ
    BURInFaultCIMSAStruct BURInFaultCIMSA; // Неисправности ЦИМС-А
    BURInCW1DMVStruct BURInCW1DMV1; // Слово состояния 1 ДМВ 1
    BURInCW1DMVStruct BURInCW1DMV2; // Слово состояния 1 ДМВ 2
    BURInCW2DMVStruct BURInCW2DMV1; // Слово состояния 2 ДМВ 1
    BURInCW2DMVStruct BURInCW2DMV2; // Слово состояния 2 ДМВ 2
    BURInCW3DMVStruct BURInCW3DMV1; // Слово состояния 3 ДМВ 1
    BURInCW3DMVStruct BURInCW3DMV2; // Слово состояния 3 ДМВ 2
    BURInCW1KVStruct BURInCW1KV; // Слово состояния 1 ПРИМА-КВ
    BURInCW2KVStruct BURInCW2KV; // Слово состояния 2 ПРИМА-КВ
    BURInCW3KVStruct BURInCW3KV; // Слово состояния 3 ПРИМА-КВ
    BURInCWBSOIStruct BURInCWBSOIM; // Слово состояния БСОИ основной
    BURInCWBSOIStruct BURInCWBSOIR; // Слово состояния БСОИ резервный
    BURInCW1VIMStruct BURInCW1VIM; // Слово состояния 1 VIM
    BURInCW2VIMStruct BURInCW2VIM; // Слово состояния 2 VIM
    BURInCWRSBNStruct BURInCWRSBN; // Слово состояния РСБН-НП
    BURInDS1Struct BURInDS1; // ДС 1
    BURInDS2Struct BURInDS2; // ДС 2
    BURInDS3Struct BURInDS3; // ДС 3
    BURInDS4Struct BURInDS4; // ДС 4
    BURInDS5Struct BURInDS5; // ДС 5
    BURInCWSOStruct BURInCWSO; // Слово состояния СО-2010
    BURInSMRStruct BURInSMR; // Сигналы маркерного приемника
    BURInFuelSOStruct BURInFuelSO; // Остаток топлива для СО

    BURInFloatStruct BURInTAH; // Температура воздуха отопления
    BURInFloatStruct BURInTAPC; // Температура воздуха в пассажирской кабине
    BURInFloatStruct BURInUGL; // Напряжение генератора левого
    BURInFloatStruct BURInIGL; // Ток генератора левого
    BURInFloatStruct BURInUGR; // Напряжение генератора правого
    BURInFloatStruct BURInIGR; // Ток генератора правого
    BURInFloatStruct BURInUASh1; // Напряжение аварийной шины №1
    BURInFloatStruct BURInUASh2; // Напряжение аварийной шины №2
    BURInFloatStruct BURInUB1; // Напряжение аккумуляторной батареи №1
    BURInFloatStruct BURInIB1; // Ток аккумуляторной батареи №1
    BURInFloatStruct BURInUB2; // Напряжение аккумуляторной батареи №2
    BURInFloatStruct BURInIB2; // Ток аккумуляторной батареи №2
    BURInFloatStruct BURInU36F23G1; // Напряжение между фазами 2-3 генератора 36 В №1
    BURInFloatStruct BURInU36F13G1; // Напряжение между фазами 1-3 генератора 36 В №1
    BURInFloatStruct BURInU36F12G1; // Напряжение между фазами 1-2 генератора 36 В №1
    BURInFloatStruct BURInU36F23G2; // Напряжение между фазами 2-3 генератора 36 В №2
    BURInFloatStruct BURInU36F13G2; // Напряжение между фазами 1-3 генератора 36 В №2
    BURInFloatStruct BURInU36F12G2; // Напряжение между фазами 1-2 генератора 36 В №2
    BURInFloatStruct BURInU115FAG1; // Напряжение фазы А генератора 115 В №1
    BURInFloatStruct BURInU115FBG1; // Напряжение фазы B генератора 115 В №1
    BURInFloatStruct BURInU115FCG1; // Напряжение фазы C генератора 115 В №1
    BURInFloatStruct BURInU115FAG2; // Напряжение фазы А генератора 115 В №2
    BURInFloatStruct BURInU115FBG2; // Напряжение фазы B генератора 115 В №2
    BURInFloatStruct BURInU115FCG2; // Напряжение фазы C генератора 115 В №2
    BURInFloatStruct BURInFuelLevTankL; // Уровень топлива в левой системе топливных баков
    BURInFloatStruct BURInFuelLevTankR; // Уровень топлива в правой системе топливных баков
    BURInFloatStruct BURInFuelLevTankTermL; // Уровень топлива в концевом топливном баке слева
    BURInFloatStruct BURInFuelLevTankTermR; // Уровень топлива в концевом топливном баке справа
    BURInFloatStruct BURInPFuelL; // Давление топлива левой системы
    BURInFloatStruct BURInPOilL; // Давление масла левой системы
    BURInFloatStruct BURInTOilL; // Температура масла левой системы
    BURInFloatStruct BURInPFuelR; // Давление топлива правой системы
    BURInFloatStruct BURInPOilR; // Давление масла правой системы
    BURInFloatStruct BURInTOilR; // Температура масла правой системы
    BURInFloatStruct BURInFuelConsL; // Расход топлива левого двигателя
    BURInFloatStruct BURInFuelConsR; // Расход топлива правого двигателя
    BURInFloatStruct BURInPGydroMain; // Давление гидр. жидкости в основном контуре постоянного давления
    BURInFloatStruct BURInPGydroBrake; // Давление гидр. жидкости в контуре тормозов
    BURInFloatStruct BURInHBar; // Резерв
    BURInFloatStruct BURInVPrib; // Приборная скорость полета
    BURInFloatStruct BURInARV; // Угол отклонения руля высоты
    BURInFloatStruct BURInAAiler; // Угол отклонения элеронов
    BURInFloatStruct BURInARN; // Угол отклонения руля направления
    BURInFloatStruct BURInATRN; // Угол отклонения триммера руля направления
    BURInFloatStruct BURInRUDL; // Положение РУД левого двигателя
    BURInFloatStruct BURInRUDR; // Положение РУД правого двигателя
    BURInFloatStruct BURInTorgEngL; // Крутящий момент левого двигателя
    BURInFloatStruct BURInTorgEngR; // Крутящий момент правого двигателя
    BURInFloatStruct BURInPParkBrake; // Давление в контуре стояночного тормоза
    BURInFloatStruct BURInPGydroBrakeL; // Давление в левой гидравлической системе тормозов
    BURInFloatStruct BURInPGydroBrakeR; // Давление в правой гидравлической системе тормозов
    BURInFloatStruct BURInNPropEngL; // Обороты воздушного винта левого двигателя
    BURInFloatStruct BURInNPropEngR; // Обороты воздушного винта правого двигателя
    BURInFloatStruct BURInGenEngL; // Обороты газогенератора левого двигателя
    BURInFloatStruct BURInGenEngR; // Обороты газогенератора правого двигателя
    BURInFloatStruct BURInDTGenPropL; // Температура между турбиной газогенератора турбиной воздушного винта левого двигателя
    BURInFloatStruct BURInDTGenPropR; // Температура между турбиной газогенератора турбиной воздушного винта левого двигателя
    BURInFloatStruct BURInA; // Угол атаки
    BURInFloatStruct BURInRoll; // Угол крена
    BURInFloatStruct BURInPitch; // Угол тангажа
    BURInFloatStruct BURInWx; // Угловая скорость ?x
    BURInFloatStruct BURInWy; // Угловая скорость ?y
    BURInFloatStruct BURInWz; // Угловая скорость ?z
    BURInFloatStruct BURInAx; // Линейное ускорение ax
    BURInFloatStruct BURInAy; // Линейное ускорение ay
    BURInFloatStruct BURInAz; // Линейное ускорение az
    BURInFloatStruct BURInLon; // Долгота комплексная
    BURInFloatStruct BURInLat; // Широта комплексная
    BURInFloatStruct BURInHSNS; // Спутниковая высота
    BURInFloatStruct BURInHB; // Барометрическая высота
    BURInFloatStruct BURInVym; // Резерв
    BURInFloatStruct BURInVAir; // Воздушная скорость 
    BURInFloatStruct BURInVPut; // Путевая скорость
    BURInFloatStruct BURInVys; // Вертикальная скорость (м/с)
    BURInFloatStruct BURInCourseM; // Магнитный курс
    BURInFloatStruct BURInLonBINS; // Долгота БИНС
    BURInFloatStruct BURInLatBINS; // Широта БИНС
    BURInSS2UVDStruct BURInSS2UVD; // СС 2 Ответчик УВД
    BURInFloatStruct BURInFreqILSSP; // Частота настройки ILS/СП
    BURInFloatStruct BURInFreqVORILSSP; // Частота настройки VOR/ILS/СП
    BURInFloatStruct BURInAzZVOR; // Заданный азимут, Азад VOR
    BURInFloatStruct BURInLonGBINS; // Долгота БИНС (гибрид)
    BURInFloatStruct BURInLatGBINS; // Широта БИНС (гибрид)
    BURInFloatStruct BURInEkVOR; // Отклонение от азимута (курса посадки, ?к) VOR
    BURInFloatStruct BURInEgVOR; // Отклонение от глиссады снижения ?r VOR
    BURInFloatStruct BURInAzVOR; // Азимут текущий (маяка VOR), Атек 
    BURInFloatStruct BURInP; // Установка барометрического давления на уровне мирового океана
    BURInFloatStruct BURInDME; // Дистанция до азимутного радиомаяка (DME)
    BURInFloatStruct BURInAzRSBN; // Азимут РСБН
    BURInFloatStruct BURInDRSBN; // Дальность РСБН
    BURInFloatStruct BURInHRV; // Высота по радиовысотомеру
    BURInFloatStruct BURInFreqARK; // Частота настройки радиокомпаса
    BURInFloatStruct BURInAzARK; // Азимут радиокомпаса

    BURInNT1Struct BURInNT1; // Количество НТ №1
    BURInNT2Struct BURInNT2; // Количество НТ №2
    BURInFlightModeStruct BURInFlightMode; // Режимы самолетовождения
    BURInDS6Struct BURInDS6; // ДС 6    

    BURInFloatStruct BURInCourseIstCompl; // Курс истинный комплексныйв какуюв какую
    BURInFloatStruct BURInDTraektNT; // Дальность траекторная до исполняемой НТ
    BURInFloatStruct BURInLonPPM; // Долгота исполняемого ППМ
    BURInFloatStruct BURInLatPPM; // Широта исполняемого ППМ
    BURInFloatStruct BURInHAirField; // Высота круга аэродрома
    BURInFloatStruct BURInAGliss; // Угол наклона глиссады
    BURInFloatStruct BURInCourseAirField; // Курс захода на аэродром
    BURInFloatStruct BURInVGroundN; // Северная составляющая земной скорости комплексная
    BURInFloatStruct BURInVGroundE; // Восточная составляющая земной скорости комплексная
    BURInFloatStruct BURInVGroundZ; // Вертикальная составляющая земной скорости комплексная
    BURInFloatStruct BURInTimeZ; // Заданное время прибытия в точку с признаком «Цель»
    BURInFloatStruct BURInFuelAmount; // Количество топлива
    BURInFloatStruct BURInTAirOuter; // Температура наружного воздуха
    BURInFloatStruct BURInPFireExting; // Давление огнетушителя багажника
    BURInFloatStruct BURInATrimElev; // Угол отклонения триммера руля высоты
    BURInFloatStruct BURInATrimAiler; // Угол отклонения триммера элеронов
    BURInFloatStruct BURInHComplex; // Высота комплексная
    BURInFloatStruct BURInAPutCur; // Текущий путевой угол (курс от СНС)
    BURInFloatStruct BURInTimeCur; // Текущее местное время
    BURInFloatStruct BURInSOCT; // Оставшаяся дальность вдоль ортодромии (Sост)
    BURInFloatStruct BURInDZ; // Дальность выхода на посадочный курс (Д3)

    BURInAddStruct BURInAdd; // Дополнительные структуры
    BURInTimeStruct BURInTime; // Время
    BURInCountStruct BURInCount; // Счетчик 0-4095    

    BURInFloatStruct BURInCourseSNS; // Истинный курс откорректированный по данным СНС      
    BURInFloatStruct BURInHDecis; // Значение высоты принятия решения
    BURInFloatStruct BURInRollZad; // Значение заданного крена
    BURInFloatStruct BURInOverLoadZZad; // Значение заданной вертикальной перегрузки
    BURInFloatStruct BURInLoadZ; // Вертикальная перегрузка
    BURInFloatStruct BURInLoadY; // Боковая перегрузка
    BURInFloatStruct BURInLoadX; // Продольная перегрузка
    BURInFloatStruct BURInHOp; // Значение опасной высоты
    BURInFloatStruct BURInHPr; // Значение прогноза высоты
    BURInFloatStruct BURInVPr; // Значение прогноза скорости
    BURInFloatStruct BURInVMinCrit; // Значение минимальной критической скорости
    BURInFloatStruct BURInVMaxCrit; // Значение максимальной критической скорости
    BURInFloatStruct BURInLoadPr; // Значение прогноза перегрузки
    BURInFloatStruct BURInLoadMinCrit; // Значение минимальной критической перегрузки
    BURInFloatStruct BURInLoadMaxCrit; // Значение максимальной критической перегрузки
    BURInFloatStruct BURInHZad; // Значение заданной высоты

    BURInDS7Struct BURInDS7; // ; ДС 7
    BURInDS8Struct BURInDS8; // ; ДС 8
    BURInFloatStruct BURInAtaMax; // Значение максимального угла атаки
    BURInFloatStruct BURInRollMax; // Значение максимального крена

    BURInMeteo1Struct BURInMeteo1; // Структура слова «Состояние метеолокатора 1»
    BURInMeteo2Struct BURInMeteo2; // Структура слова «Состояние метеолокатора 2»
    BURInMeteo3Struct BURInMeteo3; // Структура слова «Состояние метеолокатора 3»
    BURInMeteo4Struct BURInMeteo4; // Структура слова «Состояние метеолокатора 4»
    BURInMeteo5Struct BURInMeteo5; // Структура слова «Состояние метеолокатора 5»
    BURInIBKO2CondStruct BURInIBKO2Cond; // Структура слова «Слово состояния ИБКО-2»
    BURInCVISU1ParStruct BURInCVISU1Par; // Структура слова «Параметры ЦВ ИСУ 1»
    BURInCVISU2ParStruct BURInCVISU2Par; // Структура слова «Параметры ЦВ ИСУ 2»

    BURInFloatStruct BURInVCalc; // Значение расчетной скорости (для прибытия в точку в заданное время)
    BURInFloatStruct BURInDOrt; // Отклонение от ортодромии (ΔZ)
    BURInFloatStruct BURInDPhi; // Отклонение от заданного курса(Δφ)
    BURInFloatStruct BURInLatCVISU; // Широта ЦВ ИСУ
    BURInFloatStruct BURInLonCVISU; // Долгота ЦВ ИСУ
    BURInFloatStruct BURInHCVISU; // Высота ЦВ ИСУ
    BURInFloatStruct BURInVPutCVISU; // Путевая скорость ЦВ ИСУ
    BURInFloatStruct BURInVZCVISU; // Вертикальная скорость ЦВ ИСУ
    BURInFloatStruct BURInAPutCVISU; // Значение путевого угла ЦВ ИСУ

    BURInFloatStruct BURInDirH; // Отклонение директорной планки по горизонтали
    BURInFloatStruct BURInDirV; // Отклонение директорной планки по вертикали 

    BURInFloatStruct BURInFlightDirPitch; // Управляющий сигнал флайтдиректора по тангажу
    BURInFloatStruct BURInFlightDirRoll; // Управляющий сигнал флайтдиректора по крену
    BURInFloatStruct BURInZK; // ЗК (пульт задачи курса)
    BURInFloatStruct BURInZPU; // ЗПУ (пульт задачи курса)
    BURInFloatStruct BURInDAzVOR; // Отклонение от азимута подхода к посадочному маяку VOR (в БСАП)
    BURInFloatStruct BURInDAzRSBN; // Отклонение от азимута подхода к посадочному маяку РСБН (в БСАП)
    BURInFloatStruct BURInDAILS; // Отклонение от установленного вертикального угла подхода к глиссадному маяку ILS (в БСАП)
    BURInFloatStruct BURInDARSBN; // Сигнал отклонения от установленного вертикального угла подхода к посадочному маяку РСБН (в БСАП)
    BURInFloatStruct BURInLeadSysRoll; // Сигнал крена от ведущей системы определения углового положения (в БСАП)

    BURInFloatStruct BURInLeadSysPitch; // Сигнал тангажа от ведущей системы определения углового положения (в БСАП)
    BURInFloatStruct BURInAVYaw; // Угловая скорость рыскания (в БСАП)
    BURInFloatStruct BURInPFix; // Сигнал установленного давления относительно земли в текущем местоположении самолета  (QFE) (в БСАП)
    BURInFloatStruct BURInHCurr1013; // Текущая высота относительно уровня 1013 мбар (QNE) (в БСАП)
    BURInFloatStruct BURInSideDevLZP; // Линейное боковое уклонение от ЛЗП (в БСАП)
    BURInFloatStruct BURInMVAR; // Текущие магнитное склонение (в БСАП)
    BURInFloatStruct BURInAzVORCurr; // Текущий азимут от маяка VOR (в БСАП)
    BURInFloatStruct BURInAzRSBNCurr; // Текущий азимут от маяка РСБН (в БСАП)
    BURInFloatStruct BURInZKIBKO; // ЗК (ИБКО)  
    BURInFloatStruct BURInZPUIBKO; // ЗПУ (ИБКО)
    BURInFloatStruct BURInABINS; // Угол сноса от БИНС    
    BURInFloatStruct BURInDCourseRSBN; // Отклонение по курсу РСБН
    BURInFloatStruct BURInDGlideRSBN; // Отклонение по глиссаде РСБН
    BURInFloatStruct BURInRollBINS; // Угол крена БИНС 
    BURInFloatStruct BURInPitchBINS; // Угол тангажа БИНС      

    BURInIBKOToBSAPStruct BURInIBKOToBSAP; // Параметры из ИБКО в БСАП
    BURInBSAPToIBKO1Struct BURInBSAPToIBKO1; // Параметры 1 из БСАП в ИБКО
    BurInMasterSysStruct BurInMasterSys; // Ведущие системы  
};

//// Выходная структура для ПНС
//BURInStruct BURIn;

///////////////////////////////////////////////////////////////////////////////////////////////////////


//==========================бесплатформенная инерциальная навигационная система БИНС-СП-1==========================

// Структуры выходных данных BINS

struct BINSOutFloatStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета 0
    float Data; // Данные
    uint8_t Matrix : 2; // 0 - Предупреждение об отказе, 1 - Нет вычислительных данных, 2 - Тест-контроль, 3 - Нормальная работа
    uint8_t Reserv : 6; // Резерв
} __attribute__((packed));

struct BINSOutDoubleStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета 0
    double Data; // Данные
    uint8_t Matrix : 2; // 0 - Предупреждение об отказе, 1 - Нет вычислительных данных, 2 - Тест-контроль, 3 - Нормальная работа
    uint8_t Reserv : 6; // Резерв
} __attribute__((packed));

struct BINSOutIntStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета 0
    int16_t Data; // Данные
    uint8_t Matrix : 2; // 0 - Предупреждение об отказе, 1 - Нет вычислительных данных, 2 - Тест-контроль, 3 - Нормальная работа
    uint8_t Reserv : 6; // Резерв
} __attribute__((packed));

struct BINSOutCWStruct {
    uint8_t DevId; // Идентификатор устройства
    uint8_t PackId; // Идентификатор пакета 0
    uint32_t SetMode : 1; // Режим «Выставка»
    uint32_t CourseVertMode : 1; // Режим «Курсовертикаль»
    uint32_t NavMode : 1; // Режим «Навигация»    
    uint32_t OutMagnDecl : 1; // Работа по внешнему магнитному склонению
    uint32_t WrongAnglePos : 1; // Неправильное угловое положение 
    uint32_t SVSNoData : 1; // Нет данных от СВС
    uint32_t InertFault : 1; // Отказ инерциального блока
    uint32_t NoOutMagnDecl : 1; // Нет внешнего магнитного склонения
    uint32_t InterSet : 1; // Прерванная выставка
    uint32_t NoInitData : 1; // Отсутствуют начальные данные (0, 0); 0 отлично от  выставки на 30¢
    uint32_t VWrong : 1; // Ошибка по скорости 0,01 м/с с коэф. изм. курса > 2c
    uint32_t SNSNoData : 1; // Нет данных от СНС
    uint32_t TimeToFin : 3; // Время до окончания выставки и ПГ (Показатель готовности) (0-7 мин.)
    uint32_t Matrix : 2; // 0 - Нормальная работа, 1 - Нет вычислительных данных, 2 - Функциональный контроль, 3 - Предупреждение об отказе
    uint32_t Reserv : 15; // Резерв
} __attribute__((packed));

////Входная структура для ПНС
//   BINSOutFloatStruct BINSOutAp; // PackId = 0; Ускорение угла тангажа
//   BINSOutFloatStruct BINSOutAr; // PackId = 1; Ускорение угла крена
//   BINSOutFloatStruct BINSOutAy; // PackId = 2; Ускорение угла рыскания
//   BINSOutDoubleStruct BINSOutLat; // PackId = 3; Географическая широта
//   BINSOutDoubleStruct BINSOutLon; // PackId = 4; Географическая долгота
//   BINSOutFloatStruct BINSOutVPut; // PackId = 5; Путевая скорость
//   BINSOutFloatStruct BINSOutAPut; // PackId = 6; Путевой угол
//   BINSOutFloatStruct BINSOutCourseI; // PackId = 7; Истинный курс
//   BINSOutIntStruct BINSOutVW; // PackId = 8; Скорость ветра
//   BINSOutFloatStruct BINSOutAW; // PackId = 9; Угол ветра
//   BINSOutFloatStruct BINSOutMAPut; // PackId = 10; Магнитный путевой угол
//   BINSOutFloatStruct BINSOutMCourse; // PackId = 11; Магнитный курс
//   BINSOutFloatStruct BINSOutUS; // PackId = 12; Угол сноса
//   BINSOutFloatStruct BINSOutUN; // PackId = 13; Угол наклона траектории полёта
//   BINSOutFloatStruct BINSOutATr; // PackId = 14; Ускорение вдоль траектории полёта
//   BINSOutFloatStruct BINSOutPitch; // PackId = 15; Угол тангажа
//   BINSOutFloatStruct BINSOutRoll; // PackId = 16; Угол крена
//   BINSOutFloatStruct BINSOutWz; // PackId = 17; Угловая скорость вокруг поперечной оси ЛА
//   BINSOutFloatStruct BINSOutWx; // PackId = 18; Угловая скорость вокруг продольной оси ЛА
//   BINSOutFloatStruct BINSOutWy; // PackId = 19; Угловая скорость вокруг нормальной оси ЛА
//   BINSOutFloatStruct BINSOutAx1; // PackId = 20; Ускорение вдоль продольной оси ЛА
//   BINSOutFloatStruct BINSOutAz1; // PackId = 21; Ускорение вдоль поперечной оси ЛА
//   BINSOutFloatStruct BINSOutAy1; // PackId = 22; Нормальное ускорение
//   BINSOutFloatStruct BINSOutCourseG; // PackId = 23; Гироскопический курс
//   BINSOutFloatStruct BINSOutWPut; // PackId = 24; Угловая скорость изменения путевого угла
//   BINSOutFloatStruct BINSOutWPitch; // PackId = 25; Угловая скорость изменения тангажа
//   BINSOutFloatStruct BINSOutWRoll; // PackId = 26; Угловая скорость изменения крена
//   BINSOutIntStruct BINSOutVVP; // PackId = 27; Скорость вертикальная потенциальная
//   BINSOutFloatStruct BINSOutHI; // PackId = 28; Высота инерциальная
//   BINSOutFloatStruct BINSOutAprod; // PackId = 29; Ускорение горизонтальное вдоль линии пути ЛА
//   BINSOutFloatStruct BINSOutApop; // PackId = 30; Ускорение горизонтальное, перпендикулярное линии пути ЛА
//   BINSOutFloatStruct BINSOutAz; // PackId = 31; Вертикальное ускорение
//   BINSOutIntStruct BINSOutVz; // PackId = 32; Скорость инерциальная вертикальная
//   BINSOutFloatStruct BINSOutVn; // PackId = 33; Северная составляющая скорости
//   BINSOutFloatStruct BINSOutVe; // PackId = 34; Восточная составляющая скорости
//   BINSOutFloatStruct BINSOutE; // PackId = 35; Угол платформы
//   BINSOutCWStruct BINSOutCW; // PackId = 36; Слово состояния
//   BINSOutFloatStruct BINSOutVPutG; // PackId = 37; Скорость путевая гибрид.
//   BINSOutFloatStruct BINSOutAPutG; // PackId = 38; Путевой угол, гибрид.
//   BINSOutFloatStruct BINSOutLATG; // PackId = 39; Геогр. широта гибрид.
//   BINSOutFloatStruct BINSOutLONG; // PackId = 40; Геогр. долгота гибрид.
//   BINSOutFloatStruct BINSOutVNG; // PackId = 41; Северная составляющая скорости, гибрид.
//   BINSOutFloatStruct BINSOutVEG; // PackId = 42; Восточная составляющая скорости, гибрид.
//   BINSOutIntStruct BINSOutMAPUTG; // PackId = 43; Магнитный путевой угол, гибрид.


//==========================================Выдача частоты приема параметра ======================================
//  DevId = 11

//Структура запроса: 
struct FreqInStruct {
    uint8_t DevId; // Идентификатор устройства/запроса
    uint8_t PackId; // Идентификатор пакета – номер канала
    uint8_t Addr; // Адрес запрашиваемого параметра 0-255
} __attribute__((packed));
//где DevId = 11

//Структура ответа:
struct FreqOutStruct {
    uint8_t DevId; // Идентификатор устройства/запроса
    uint8_t PackId; // Идентификатор пакета – номер канала
    uint8_t Addr; // Адрес запрошенного параметра 0-255
    float Freq; // Частота 
} __attribute__((packed));
//где DevId = 11


//********************************************************************************************************************************************************


//-----------------------------Управление разовыми командами----------------------------------
//Имя порта отправителя            //rk_ctrl_out     
//Имя порта приемника              //rk_ctrl_in   
//Структура                        //RK_OUT_CTRL
//Частота                          //Произвольная
//--------------------------------------------------------------------------------------------
/*
 * Управление выходными разовыми командами
 */
struct RK_OUT_CTRL
{
    /*
     * Порядковый номер выходной разовой команды
     * для ПНС: от 1 до 11
     * для МФИ: от 1 до 4
     */
    uint16_t rk;
    /*
     * 1 - включить
     * 0 - выключить
     */
    uint8_t state;
} __attribute__((packed));
//-----------------------------------------------------------------------------------------



//------------------------------Состояние разовых команд-----------------------------------
//Имя порта отправителя            //rk_status_out                
//Имя порта приемника              //rk_status_in                
//Структура                        //RK_STATUS               
//Частота                          //5 Гц                      
//-----------------------------------------------------------------------------------------
/*
 * Состояние входных и выходных разовых команд
 */
struct RK_STATUS
{
    /*
     * Состояние выходных разовых команд
     * Младший бит - первая разовая команда
     * Используются:
     * для ПНС: первые 11 бит
     * для МФИ: первые 4 бита
     */
    uint32_t out_status;
    
    /*
     * Состояние входных разовых команд
     * Младший бит - первая разовая команда
     * Старший бит (32й) -  разовая команда снятия питания с блока
     * Используются:
     * для ПНС: первые 20 бит
     * для МФИ: первые 8 бит
     */
    uint32_t in_status;

    uint8_t in_valid; // 0 - не исправны, 1 — исправны
    uint8_t out_valid; // 0 - не исправны, 1 - исправны
} __attribute__((packed));
//-------------------------------------------------------------------------------------------


//-------------------------------------Состояние записи логов--------------------------------------------
//Имя порта отправителя                //sns_log_out  //svs_log_out  //ahrs_log_out  //dmk_dt_log_out                                          
//Имя порта приемника                  //sns_log_in   //svs_log_in   //ahrs_log_in   //dmk_dt_log_in                                                 
//Структура                            //LogState     //LogState     //LogState      //LogState                                     
//Частота                              //5 Гц         //5 Гц         //5 Гц          //5 Гц               
//--------------------------------------------------------------------------------------------------------
//
// Состояние записи логов
//
struct LogState {
    uint64_t size; // размер логов в байтах
    uint8_t state; // состояние записи, 1 - вкл, 0 - выкл
} __attribute__((packed));
//--------------------------------------------------------------------------------------------------------

//-----------------------------------Управление записью логов-----------------------------------------------------------------------
//Имя порта отправителя                 //sns_log_ctrl_out   //svs_log_ctrl_out   //ahrs_log_ctrl_out   //dmk_dt_log_ctrl_out                                                           
//Имя порта приемника                   //sns_log_ctrl_in    //svs_log_ctrl_in    //ahrs_log_ctrl_in    //dmk_dt_log_ctrl_in                                                        
//Структура                             //LogControl         //LogControl         //LogControl          //LogControl                                                                                            
//Частота                               //Произвольная       //Произвольная       //Произвольная        //Произвольная                                                
//-----------------------------------------------------------------------------------------------------------------------------------
//
// Управление записью логов
//
struct LogControl {
    /**
     * @brief команда:
     * 0 - выключить запись лога
     * 1 - включить запись лога
     * 2 - очистить логи
     */
    uint8_t command;
} __attribute__((packed));
//------------------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------Данные от БСАП----------------------------------
//Имя порта отправителя    //bsap_data_out                    
//Имя порта приемника      //bsap_data_in                                    
//Структура                //BSAP_DATA                                      
//Частота                  // -                                                     
//--------------------------------------------------------------------------------------------------
//
// Данные от БСАП в ИБКО410
//
struct BSAP_DATA {
    float dlt_pitch; // Управляющий сигнал флайтдиректора по тангажу, [-15..15], градусы
    float dlt_roll; // Управляющий сигнал флайтдиректора по крену, [-15..15], градусы
    uint16_t heading; // ЗК (пульт задачи курса), [0..359], градусы
    uint16_t crs; // ЗПУ (пульт задачи курса), [0..359], градусы
    
    uint8_t ap_clutch; // Автопилот включен и управляет сервоприводами (1 - вкл, 0 - выкл)
    uint8_t ap_valid; // Автопилот исправен (1 - вкл и исправен, 0 - не исправен)
    uint8_t alt; // Включен режим ALT (1 - вкл, 0 - выкл)
    uint8_t alt_arm; // Предварительный режим ALT (1 - активирован, 0 - не активирован)
    uint8_t hdg; // Включен режим HDG (1 - вкл, 0 - выкл)
    uint8_t nav; // Включен режим NAV (1 - вкл, 0 - выкл)
    uint8_t nav_arm; // Предварительный режим NAV (1 - активирован, 0 - не активирован)
    uint8_t apr; // Включен режим APR (1 - вкл, 0 - выкл)
    uint8_t apr_arm; // Предварительный режим APR (1 - активирован, 0 - не активирован)
    uint8_t gs; // Удержание глиссады (1 - вкл, 0 - выкл)
    uint8_t bc; // Включен режим BC (1 - вкл, 0 - выкл)
    uint8_t ias; // Включен режим IAS (1 - вкл, 0 - выкл)
    uint8_t ga; // Включен режим GA (1 - вкл, 0 - выкл)
    uint8_t yd; // Включен демпфер рысканья (1 - вкл, 0 - выкл)
    uint8_t hb; // Включен режим HALF BANK (1 - вкл, 0 - выкл)
    uint8_t fd; // Включен режим FD (1 - вкл, 0 - выкл)
    uint8_t mode; // Выбранный режим на пульте задачи курса (0 - маршрут, 1 — РСБН/VOR)
    uint8_t cws; // Включен совмещенный режим (1 - включен, 0 - выключен)

    BSAP_DATA() {
        memset(this, 0, sizeof(*this));
    }
} __attribute__((packed));
//------------------------------------------------------------------------------------------------


//--------------------------------------Данные в БСАП----------------------------------
//Имя порта отправителя       //bsap_ctrl_out                                  
//Имя порта приемника         //bsap_ctrl_in                                            
//Структура                   //BSAP_CONTROL                         
//Частота                     //20Гц  
//-------------------------------------------------------------------------------------
//
// Данные в БСАП от ИБКО410
//
struct BSAP_CONTROL {
    float dlt_b_vor; // Отклонение от азимута подхода к посадочному маяку VOR, [-0.4..0.4] РГМ
    float dlt_b_rsbn; // Отклонение от азимута подхода к посадочному маяку РСБН, [-38.2..38.2] %КРС
    float dlt_g_ils; // Отклонение от установленного вертикального угла подхода к глиссадному маяку ILS, [-0.8..0.8] РГМ
    float dlt_g_rsbn; // Отклонение от установленного вертикального угла подхода к посадочному маяку РСБН, [-41.8..41.8] %КРС
    float roll; // Сигнал крена от ведущей системы определения углового положения, [-180..180] град
    float pitch; // Сигнал тангажа от ведущей системы определения углового положения, [-180..180] град
    float yaw_rate; // Угловая скорость рысканья, [-10..10] град/сек
    float bar_pres; // Сигнал установленного давления относительно земли в текущем местоположении самолета (QFE), [28.10..30.99] InHg
    float alt; // Текущая высота относительно уровня 1013 мбар (QNE), [-500..6000] м
    float lbu; // Линейное боковое уклонение от ЛЗП, [0..20] MM
    float b_vor; // Текущий азимут от маяка VOR, [-180..180] град
    float b_rsbn; // Текущий азимут от маяка РСБН, [-180..180] град
    uint16_t hdg_ibko; // ЗК (ИБКО), [0..359] град
    uint16_t crs_ibko; // ЗПУ (ИБКО), [0..359] град
    uint16_t tru_hdg; // Текущий истиный курс, [0..359] град
    uint16_t mag_hdg; // Текущий магнитный курс, [0..359] град
    float corr_a; // Текущий угол сноса, [-30..30], град

    uint8_t valid_ibko; // Исправность ведущего ПНС (1 - исправен, 0 - не исправен)
    uint8_t valid_angles; // Исправность ведущей системы определения углового положения (1 - исправен, 0 - не исправен)
    uint8_t valid_b_vor; // Значение азимута от VOR корректно (1 - да, 0 - нет)
    uint8_t valid_b_rsbn; // Значение азимута от РСБН корректно (1 - да, 0 - нет)
    uint8_t valid_yaw_rate; // Исправности аппаратуры, формирующей угловую скорость рысканья (1 - исправен, 0 - не исправен)
    uint8_t valid_delta_b_ils; // Значение отклонения от азимута подхода от ILS корректно (1 - да, 0 - нет)
    uint8_t valid_delta_b_rsbn; // Значение отклонения от азимута подхода от РСБН корректно (1 - да, 0 - нет)
    uint8_t valid_delta_g_ils; // Значение отклонения по глиссаде от ILS корректно (1 - да, 0 - нет)
    uint8_t valid_delta_g_rsbn; // Значение отклонения по глиссаде от РСБН корректно (1 - да, 0 - нет)
    uint8_t valid_svs; // Исправность аппаратуры, формирующей баро-высоту (1 - исправен, 0 - не исправен)
    uint8_t en_apr; // Посадка (1 - да, 0 - нет)
    uint8_t valid_lbu; // Исправность сигнала линейного бокового уклонения от ЛЗП (1 - исправен, 0 - не исправен)
    uint8_t valid_hdg_ibko; // Исправность сигнала ЗК (ИБКО) (1 - исправен, 0 - не исправен)
    uint8_t valid_crs_ibko; // Исправность сигнала ЗПУ (ИБКО) (1 - исправен, 0 - не исправен)
    uint8_t valid_quorum; // Исправность кворум элемента в ИБКО (1 - исправен, 0 - не исправен)
    uint8_t manual_kv; // В ручном режиме выполнен выбор источника крена и тангажа (1 - выбран, 0 - не выбран)
    uint8_t mode_nav; // Режим работы РСБН-НП/VIM-95 (1 - посадка, 0 - навигация)
    uint8_t source; // Выбранный источник навигации (посадки) (1 - VOR/ILS, 0 — РСБН)
    uint8_t mode_hdg; // Выбор типа текущего курса (1 - магнитный, 0 - истинный)

    BSAP_CONTROL() {
        memset(this, 0, sizeof(*this));
    }
} __attribute__((packed));
//---------------------------------------------------------------------------


//------------------------------Диспетчер → СВС-----SVS_DATA_FULL--CTRL_DATA_FULL----------------------

                         //Отправка                   //Прием
                         //svs_data_full_out          //svs_data_full_in
                         //10121                      //10208
//Название               //svs_ctrl_out               //svs_ctrl_in                                                                                                                    
//Номер                  //10116                      //10304  
//Программа              //au_dispetcher              //wise_svs
//--------------------------------------------------------------------------
/**
 * @brief Данные от датчика СВС
 */
struct SVS_DATA_FULL {
    float v_prib; // приборная скорость, км/ч
    float v_ist; // Истинная (воздушная) скорость, км/ч
    float h_baro; // Абсолютная барометрическая высота, м
    float h_qfe; // Относительная барометрическая высота (коррекция по QFE), м
    float h_qnh; // Относительная барометрическая высота (коррекция по QNH), м
    float vy; // вертикальная скорость, м/с
    float P; // Статическое давление воздуха, мм.рт.ст.
    float q; // Скоростной напор, Па

    /*
     * Статус данных:
     * 1 - достоверны
     * 0 - не достоверны
     */
    uint8_t status;
} __attribute__((packed));

//
// Управляющие данные для СВС
//
    struct CTRL_DATA_FULL { 
        float temp; // температура окружающего воздуха 
        float P_qfe; // Давление (коррекция) QFE, мм.рт.ст. 
        float P_qnh; // Давление (коррекция) QNH, мм.рт.ст.

        struct Valid {
            uint8_t temp; // Валидность температуры
            uint8_t P_qfe; // Валидность давления qfe
            uint8_t P_qnh; // Валидность давления qnh
        } valid;
    } __attribute__((packed));
//--------------------------------------------------------------------------


//-------------------------Отправка наработки (суммарное время работы) каждого блока в диспетчер----------------------------
//Имя порта отправителя       //operating_time_out                                                   
//Имя порта приемника         //operating_time_in                                                                             
//Структура                   //BlockOpetatingTime                                                                        
//Частота                     //1 Гц                         
//---------------------------------------------------------------------------------------------------------------------------
//
// Структура с именем и наработкой блока
//
struct BlockOpetatingTime {
    char blockName[10]; //!< имя блока, например "MFI1"
    uint32_t operatingTime; //!< время наработки в секундах
} __attribute__((packed));
//ММК+БКВ → Диспетчер

//
// Режим расчета курса
//
enum class CourseRegime   {
    courseFromDmk, // курс, крен, тангаж от ММК
    vectorsFromDmk, // векторы магнитного поля X, Y, Z от ММК
    courseFromBkv, // курсы, посчитанные БКВ
    courseFromBkvWithSns // курсы, посчитанные БКВ, с учетом поправки от СНС
};


//
// Данные от БКВ+ММК
//
struct COURSE_DATA {
    float value1; // зависит от режима
    float value2; // зависит от режима
    float value3; // зависит от режима

    CourseRegime regime; // режим расчета курса
    
    /*
     * Статус данных:
     * 1 - достоверны
     * 0 - не достоверны
     */
    uint8_t status;
    
    COURSE_DATA() : 
    value1(0),//    gyroCourse(0),
    value2(0),//    magneticCourseZero(0),
    value3(0),//    magneticCourse(0),
    regime(CourseRegime::courseFromDmk),
    status(0) {}
} __attribute__((packed));


//Примечание:
//
//При режиме  courseFromDmk:
//value1 → heading; // курс в градусах
//value2 → pitch; // тангаж в градусах
//value3 → roll; // крен в градусах
//
//При режиме  vectorsFromDmk:
//value1 → X; // X, милигауссы//метрическая единица плотности магнитного потока, равная 0,001 Гаусса, 0,1 микротесла или 100 нанотесла. 
//value2 → Y; // Y, милигауссы
//value3 → Z; // Z, милигауссы
//
//При режиме courseFromBkv и courseFromBkvWithSns:
//value1 → gyroCourse;         // гиромагнитный курс, градусы
//value2 → magneticCourseZero; // магнитный курс (без учета крена и тангажа), градусы
//value3 → magneticCourse;     // магнитный курс (с учетом крена и тангажа), градусы

//-----------------------------------------------------------------------------------------
                     //Отправка                     //Прием                     
//Название           //magnetometer_data_out        //magnetometer_data_in                                                               
//Номер              //10113                        //10203                                              
//Программа          //wise_dt_dmk || wise_ahrs     //au_dispetcher                                                  
//-----------------------------------------------------------------------------------------


//-----------------------Управление БКВ--курсовертикаль----------------------------------
//Имя порта отправителя        //ahrs_ctrl_out                                                         
//Имя порта приемника          //ahrs_ctrl_in                                                                   
//Структура                    //AHRS_CTRL                                                                     
//Частота                      //5-10 Гц
//-------------------------------------------------------------------------
//
// Точка в девиационной таблице
//
struct mmkDeviationValue {
    float x; // значение с датчика
    float fx; // эталонное значение
    
    mmkDeviationValue() :
    x(0),
    fx(0) {}
} __attribute__((packed));

//
// Девиационная таблица для ММК
//
struct mmkDeviationTable {
    uint8_t valid; // валидность девиационной таблицы

    size_t points; // количество используемых точек
    mmkDeviationValue value[100]; // точки девиаицонной таблицы
        
    mmkDeviationTable() :
    valid(0),
    points(0) {}
} __attribute__((packed));


//
// Управление БКВ (состояние шасси, смещения по крену и тангажу, таблица)
//
struct AHRS_CTRL {
    uint8_t chassisState; // состояние шассии, 1 - обжато, 0 - не обжато
    float delta_roll; // смещение по крену, градусы
    float delta_pitch; // смещение по тангажу, градусы

    // Режим коррекции СНС, 0 - выполнять коррекцию, 1 - выключить
    uint8_t snsCorrectionOff; 

    uint8_t earthWater; // режим, 1 - земля, 0 - вода
    uint8_t enginesOn; // cостояние двигателя, 1 - запущен, 0 - иначе
    float initialCourse; // cтояночный курс в градусах
    
//
// Валидности полей структуры
//    * 0 - не валидно
//    * 1 - валидно

    struct Valid {
        uint8_t chassisState; // валидность поля chassisState
        uint8_t delta_roll; // валидность поля delta_roll
        uint8_t delta_pitch; // валидность поля delta_pitch

        uint8_t snsCorrectionOff; // валидность поля snsCorrectionOff

        uint8_t earthWater; // валидность поля earthWater
        uint8_t enginesOn; // валидность поля enginesOn
        uint8_t initialCourse; // валидность поля initialCourse
    } __attribute__((packed)) valid;
        
    mmkDeviationTable table;
    
    AHRS_CTRL() {
        memset(this, 0, sizeof(*this));
    }
} __attribute__((packed));
//----------------------------------------------------------------------------------------------


//-----------------------------------------Диспетчер → ДМК--------------------------------------
                  //Отправка                  //Прием                                  
//Название        //dmk_ctrl_out              //dmk_ctrl_in                                               
//Номер           //10110                     //10301                                     
//Программа       //au_dispetcher             //wise_dt_dmk                                         
//----------------------------------------------------------------------------------------------
//
// Команда для управления ДМК
//
enum class CommandDmk {
    None,
    calculateDeltas // посчитать смещения крена и тангажа
};
//----------------------------------------------------------------------------------------------


//---------------------------------------БКВ → Диспетчер----Данные------------------------------------
                //Отправка                    //Прием                                                          
//Название      //ahrs_data_out               //ahrs_data_in                                                                        
//Номер         //10111                       //10201                                                             
//Программа     //wise_ahrs                   //au_dispetcher                                                                     
//----------------------------------------------------------------------------------------------                                                                                             
//
// Показания датчика БКВ
//
struct AHRS_DATA 
{
    float Ax; // ускорение, g
    float Ay; // ускорение, g
    float Az; // ускорение, g
    
    float Wx; // угловая скорость, рад/c
    float Wy; // угловая скорость, рад/c
    float Wz; // угловая скорость, рад/c

    float roll;  // угол крена БКВ, град
    float pitch; // угол тангажа БКВ, град

    /*
     * Статус БКВ:
     * (0 - неисправна, 1 - исправна)
     */
    unsigned char status; 
} __attribute__((packed));
//----------------------------------------------------------------------------


//---------------------------------------БКВ → Диспетчер---Состояние----------
              //Отправка                //Прием                                                 
//Название    //ahrs_status_out         //ahrs_status_in                                                        
//Номер       //10222                   //10223                                           
//Программа   //wise_ahrs               //au_dispetcher                                                   
//---------------------------------------------------------------------------                                                                     

//
// Состояние БКВ
//
struct AHRS_STATUS {
    float delta_pitch; // смещения тангажа, градусы
    float delta_roll; // смещения крена, градусы
    uint16_t snsStatus; // данные от СНС, 1 - приходят, 0 - давно не было или не валидны
    uint16_t courseStatus; // Определение курсового угла по данным СНС: 1 - завершено; 0 – не завершено
    uint8_t ready; // выставка, 2 - БКВ готова, 1 - идет выставка, 0 - выставки не было 
    float timeToReady; // время до окончания выставки в секундах (если идет выставка)
    float totalTime; // общее время, на которое запущена выставка в секундах
    uint8_t snsCorrection; // коррекция по СНС, 1 - выполняется, 0 - не выполняется
    
    AHRS_STATUS() : 
    delta_pitch(0),
    delta_roll(0),
    snsStatus(0),
    courseStatus(0),
    ready(0),
    timeToReady(0),
    totalTime(0),
    snsCorrection(1) {}
} __attribute__((packed));
//---------------------------------------------------------------------------



//----------------------------------СНС → Диспетчер--------------------------
//Имя порта отправителя     //sns_data_out                                         
//Имя порта приемника       //sns_data_in                                        
//Структура                 //SNS_DATA                             
//Частота обновления        //5 Гц                                      
//---------------------------------------------------------------------------
struct SNS_DATA {
    unsigned int time; // время в секундах
    float splitSeconds; // доли секунд
    unsigned int date; // дата ddmmyy
    double lat; // широта в радианах 
    double lon; // долгота в радианах
    float speed; // скорость в км/ч
    float course; // курс в градусах
    float height; // высота антенны над уровнем моря (геоидом), м

    /*
     * Статус решения:
     * 1 - данные достоверны
     * 0 - не достоверны
     */
    unsigned char status;

    /*
     * Используемая спутниковая система:
     * 0 - GNSS
     * 1 - GPS
     * 2 - GLONASS
     */
    unsigned char satellite_sys;

    /*
     * Используемая система координат:
     * 0 - WGS-84
     * 1 - PZ-90
     * 2 - SK-42
     * 3 - SK-95
     * 4 - PZ-90.02
     */
    unsigned char coordinate_sys;

    /*
     * Значение фильтра:
     * 0  - фильтр выключен
     * 10 - фильтр решение без использования Stop - фильтра
     * 20 - фильтр решение с применением Stop – фильтра, но без COG фильтра
     * 30 - фильтр решение с применением Stop и COG фильтров
     */
    unsigned char filter;

    SNS_DATA() {
        memset(this, 0, sizeof(SNS_DATA));
    }
} __attribute__((packed));
//--------------------------------------------------------------------



//---------------------------------Диспетчер → СНС--------------------                                                           
                     //Отправка           //Прием                               
//Название           //sns_ctrl_out      //sns_ctrl_in                                           
//Номер              //10107             //10300             
//Программа          //au_dispetcher     //wise_sns                           
//--------------------------------------------------------------------
//
// Управляющая структура для СНС
//
struct SNS_CTRL
{
    /*
     * Команда:
     * 1 - изменить спутниковую систему
     * 2 - изменить систему координат
     * 3 - провести тест
     * 4 - перезапустить приемник
     * 5 - изменить часовой пояс
     * 6 — настроить фильтр
     */
    unsigned char cmd;
    
    /* 
     * Значение:
     * Если (cmd == 1)
     * 0 - GNSS
     * 1 - GPS
     * 2 - GLONASS
     * 
     * Если (cmd == 2)
     * 0 - WGS-84
     * 1 - PZ-90
     * 2 - SK-42
     * 3 - SK-95
     * 4 — PZ-90.02
     * 
     * Если (cmd == 3) или (cmd == 4)
     * То это поле не используется
     * 
     * Если (cmd == 5)
     * 0 - -12:00
     * 1 - -11:30
     * 2 - -11:00
     * ...
     * 24 - 0
     * ...
     * 47 - 11:30
     * 48 - 12:00
     * 
     * Если (cmd == 6)
     * 0  - фильтр выключен
     * 10 - фильтр решение без использования Stop - фильтра
     * 20 - фильтр решение с применением Stop – фильтра, но без COG фильтра
     * 30 - фильтр решение с применением Stop и COG фильтров
     */
    unsigned char value;
} __attribute__((packed));

//---------------------------------------------------------------end SNS


//-----------------------------------Управление реле----------------------------------
//Имя порта отправителя     //relay_ctrl2_out                                                          
//Имя порта приемника       //relay_ctrl2_in                                                       
//Структура                 //RELAY_CTRL                                            
//Частота                   //Произвольная                                           
//------------------------------------------------------------------------------------
/*
 * Управление реле
 */
struct RELAY_CTRL {
    /*
     * 0 - rs485_1
     * 1 - rs485_2
     * 2 - rs232
     * 3 - can
     * 4 - arinc429_in_1
     * 5 - arinc429_in_2
     * 6 - arinc429_in_3
     * 7 - arinc429_in_4
     * 8 - arinc429_in_5
     * 9 - arinc429_in_6
     * 10 - arinc429_in_7
     * 11 - arinc429_in_8
     * 12 - arinc429_out_1
     * 13 - arinc429_out_2
     * 14 - arinc429_out_3
     * 15 - arinc429_out_4
     */
    uint8_t interface;
    
    /*
     * Состояние Реле
     * 0 - к АЦП (для самоконтроля)
     * 1 - к драйверу (нормальная работа)
     * 2 - к терминатору (выключено)
     * Для входных каналов Аринк:
     * 3 - вход на выход
     * (1 на 1, 2 на 2, 3 на 3, 4 на 4, 5 на 1, 6 на 2, 7 на 3, 8 на 4)
     * 4 - обрыв
     */
    uint8_t state;
    
    RELAY_CTRL() :
    interface(0),
    state(0) {}
} __attribute__((packed));
//-----------------------------------------------------------------------------





#endif

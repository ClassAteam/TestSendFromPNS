#define GRAD_TO_RADS 0.01745329251994329576923690768489F
#define RADS_TO_GRAD 1.0/GRAD_TO_RADS



#define  SetBit(reg, bit)      reg |= (1<<bit)           //ystanovka bit == 1
#define  ClearBit(reg, bit)    reg &= (~(1<<bit))        //ystanovka bit ==  0
#define  InvBit(reg, bit)      reg ^= (1<<bit)           //Inversia bita
#define  BitIsSet(reg, bit)    ((reg & (1<<bit)) != 0)   //Proverka bita na 1
#define  BitIsClear(reg, bit)  ((reg & (1<<bit)) == 0)   //Proverka bita na 0

#define  SetBit15(reg, bit)      reg |= (1<<(15-bit))           //ystanovka bit == 1, shet obratni
#define  ClearBit15(reg, bit)    reg &= (~(1<<(15-bit)))        //ystanovka bit ==  0, shet obratni
#define  InvBit15(reg, bit)      reg ^= (1<<(15-bit))           //Inversia bita, shet obratni
#define  BitIsSet15(reg, bit)  ((reg & (1<<(15-bit))) != 0)   //Proverka bita na 1, shet obratni
#define  BitIsClear15(reg, bit)  ((reg & (1<<(15-bit))) == 0)   //Proverka bita na 0, shet obratni
#define  BitSetting15(es,bit,reg) ((es) ?  (reg |= (1<<(15-bit))) : (reg &= (~(1<<(15-bit)))) )
#define  BitSetting(es,bit,reg) ((es) ?  (reg |= (1<<(bit))) : (reg &= (~(1<<(bit)))) )
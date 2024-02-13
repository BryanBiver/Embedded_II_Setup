typedef struct 
{
	uint32_t pin0: 4;
	uint32_t pin1: 4;
	uint32_t pin2: 4;
	uint32_t pin3: 4;
	uint32_t RESERVED1: 16;
} bitfield;

typedef union 
{
	uint32_t data;
	bitfield pins;
} SYSCFG_EXTICRx_TypeDef;

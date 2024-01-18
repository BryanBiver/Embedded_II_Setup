typedef struct 
{
	uint32_t MSION: 1;
	uint32_t MSIRDY: 1;
	uint32_t MSIPLLEN: 1;
	uint32_t MSIRGSEL: 5;
	uint32_t MSIRANGE: 4;
	uint32_t HSION: 1;
	uint32_t HSIKERON: 1;
	uint32_t HSIRDY: 1;
	uint32_t HSIASFS: 1;
	uint32_t RESERVED0: 4;
	uint32_t HSEON: 1;
	uint32_t HSERDY: 1;
	uint32_t HSEBYP: 1;
	uint32_t CSSON: 1;
	uint32_t RESERVED1: 4;
	uint32_t PLLON: 1;
	uint32_t PLLRDY: 1;
	uint32_t PLLSAI1ON: 1;
	uint32_t PLLSAI2ON: 1;
	uint32_t PLLSAI2RDY: 1;
	uint32_t RESERVED2: 2;
} RCC_CR_TypeDef;

typedef struct 
{
	uint32_t MSICAL: 8;
    uint32_t MSITRIM: 8;
    uint32_t HSICAL: 8;
    uint32_t HSITRIM: 8;
} RCC_CFGR_TypeDef;

typedef struct 
{
    uint32_t SW: 2;
    uint32_t SWS: 2;
    uint32_t HPRE: 4;
    uint32_t PPRE1: 3;
    uint32_t PPRE2: 3;
    uint32_t RESERVED0: 1;
    uint32_t STOPWUCK: 1;
    uint32_t RESERVED1: 8;
    uint32_t MCOSEL: 4;
    uint32_t MCOPRE: 3;
    uint32_t RESERVED2: 1;
} RCC_PLLCFGR_TypeDef;

typedef struct 
{
    uint32_t RESERVED0: 4;
    uint32_t PLLSAI1M: 4;
    uint32_t PLLSAI1N: 7;
    uint32_t RESERVED1: 1;
    uint32_t PLLSAI1PEN: 1;
    uint32_t PLLSAI1P: 1;
    uint32_t RESERVED2: 2;
    uint32_t PLLSAI1QEN: 1;
    uint32_t PLLSAI1Q: 2;
    uint32_t RESERVED3: 1;
    uint32_t PLLSAI1REN: 1;
    uint32_t PLLSAI1R: 2;
    uint32_t PLLSAI1PDIV: 5;
} RCC_PLLSAI1CFGR_TypeDef;

typedef struct 
{
    uint32_t RESERVED0: 4;
    uint32_t PLLSAI2M: 4;
    uint32_t PLLSAI2N: 7;
    uint32_t RESERVED1: 1;
    uint32_t PLLSAI2PEN: 1;
    uint32_t PLLSAI2P: 1;
    uint32_t RESERVED2: 2;
    uint32_t PLLSAI2QEN: 1;
    uint32_t PLLSAI2Q: 2;
    uint32_t RESERVED3: 1;
    uint32_t PLLSAI2REN: 1;
    uint32_t PLLSAI2R: 2;
    uint32_t PLLSAI2PDIV: 5;
} RCC_PLLSAI1CFGR_TypeDef;


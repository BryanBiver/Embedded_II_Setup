typedef struct
{
	uint32_t AFSEL0: 4;
	uint32_t AFSEL1: 4;
	uint32_t AFSEL2: 4;
	uint32_t AFSEL3: 4;
	uint32_t AFSEL4: 4;
	uint32_t AFSEL5: 4;
	uint32_t AFSEL6: 4;
	uint32_t AFSEL7: 4;
} GPIOx_AFRL_TypeDef;

typedef struct
{
	uint32_t PE: 1;
	uint32_t FE: 1;
	uint32_t NF: 1;
	uint32_t ORE: 1; 
	uint32_t IDLE: 1; 
	uint32_t RXNE: 1;
	uint32_t TC: 1;
	uint32_t TXE: 1;
	uint32_t LBD: 1;
	uint32_t CTS: 1;
	uint32_t RESERVED0: 22;
} USARTx_SR_TypeDef;

typedef struct
{
	uint32_t SBK: 1;
	uint32_t RWU: 1;
	uint32_t RE: 1;
	uint32_t TE: 1;
	uint32_t IDLEIE: 1;
	uint32_t RXNEIE: 1;
	uint32_t TCIE: 1;
	uint32_t TXEIE: 1;
	uint32_t PCIE: 1;
	uint32_t PS: 1;
	uint32_t PCE: 1;
	uint32_t WAKE: 1;
	uint32_t M: 1;
	uint32_t UE: 1;
	uint32_t RESERVED0: 1;
	uint32_t OVER8: 1;
	uint32_t RESERVED1: 16;
} USARTx_CR1_TypeDef;
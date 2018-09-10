#ifndef	BS81X_H
#define	BS81X_H

#include <stdbool.h>
#include "gpio.h"


#if	(_BS81X_USE_FREERTOS==0)
#define	_BS81X_DELAY(x)		HAL_Delay(x)
#else
#include "cmsis_os.h"
#define	_BS81X_DELAY(x)		osDelay(x)
#endif
//################################################################################################
typedef struct
{
	bool				ChangeState;
	uint8_t			LastKey;
	uint32_t		LastTime;	
	
}Bs81x_t;

extern Bs81x_t Bs81x;
//################################################################################################
#if	(_BS81X_USE_FREERTOS==0)
void	Bs81x_Init(void);
#else
void	Bs81x_Init(osPriority Priority);
#endif

int16_t	Bs81x_Scan(void);

void	Bs81x_UserKeyChangeState(uint8_t	Key);

//################################################################################################

#endif

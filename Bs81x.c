
#include "gpio.h"
#include "Bs81x.h"
#include "bs81x_Conf.h"



#if	(_BS81X_USE_FREERTOS!=0)
osThreadId Bs81xHandle;
void Task_Bs81x(void const * argument);
#endif

Bs81x_t	Bs81x;
//###################################################################################################################
uint16_t	Bs81x_ReadData(void)
{
	uint16_t Bs81X_Data=0;
	if(HAL_GPIO_ReadPin(_BS81X_DATA_GPIO,_BS81X_DATA_PIN)==GPIO_PIN_SET)
		return 0xFFFF;
	HAL_GPIO_WritePin(_BS81X_CLOCK_GPIO,_BS81X_CLOCK_PIN,GPIO_PIN_RESET);
	_BS81X_DELAY(1);
	for(uint8_t	i=0 ; i<_BS81X_KEY*2 ; i++)
	{
		HAL_GPIO_WritePin(_BS81X_CLOCK_GPIO,_BS81X_CLOCK_PIN,GPIO_PIN_SET);
		for(uint32_t delay=0 ;  delay<SystemCoreClock/500000 ; delay++)
			__NOP();
		if(HAL_GPIO_ReadPin(_BS81X_DATA_GPIO,_BS81X_DATA_PIN)==GPIO_PIN_SET)
			Bs81X_Data|=1<<i;
		HAL_GPIO_WritePin(_BS81X_CLOCK_GPIO,_BS81X_CLOCK_PIN,GPIO_PIN_RESET);		
		for(uint32_t delay=0 ;  delay<SystemCoreClock/500000 ; delay++)
			__NOP();
	}	
	HAL_GPIO_WritePin(_BS81X_CLOCK_GPIO,_BS81X_CLOCK_PIN,GPIO_PIN_SET);
	return Bs81X_Data;	
}
//###################################################################################################################
#if	(_BS81X_USE_FREERTOS==0)
void	Bs81x_Init(void)
{
	HAL_GPIO_WritePin(_BS81X_CLOCK_GPIO,_BS81X_CLOCK_PIN,GPIO_PIN_SET);
	while(HAL_GetTick() < 1000)	// need 1 second for calibration
		_BS81X_DELAY(1);
	Bs81x.LastKey=0;
}
#else
//###################################################################################################################
void	Bs81x_Init(osPriority Priority)
{



}
#endif
//###################################################################################################################
int16_t	Bs81x_Scan(void)
{
	uint16_t	Data=Bs81x_ReadData();
	#if (_BS81X_KEY==4)
	if(Data==0xFFFF)	//	no happend
	{
		Bs81x.ChangeState=false;
		return -1;			
	}
	// change key
	else	if((Data & 0x80) == 0x80)// check stop bit 
	{
		Data = Data & 0x0F;
		Data = ~Data;					
		Data=Data&0x000F;
		if(Data!=Bs81x.LastKey)
			Bs81x.ChangeState=true;
		else
			Bs81x.ChangeState=false;
		Bs81x_UserKeyChangeState(Data);		
		Bs81x.LastKey=Data;
		return Data;

	}			
	#else
	if((Data & 0xA000) == 0xA000)// check stop bit
	{
	
	
	
		
	}				
	#endif
	return false;
}

//###################################################################################################################

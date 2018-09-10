#ifndef	BS81X_CONFIG_H
#define	BS81X_CONFIG_H


//				4=BS814A-2					8=BS818A-2
#define		_BS81X_KEY						4		

#define		_BS81X_USE_FREERTOS		0

#define		_BS81X_DATA_GPIO			TOUCH_DATA_GPIO_Port
#define		_BS81X_DATA_PIN				TOUCH_DATA_Pin
#define		_BS81X_CLOCK_GPIO			TOUCH_CLOCK_GPIO_Port		
#define		_BS81X_CLOCK_PIN			TOUCH_CLOCK_Pin


#if ((_BS81X_KEY!=4)&&(_BS81X_KEY!=8))
#error	"Please Select _BS81X_KEY=4 or _BS81X_KEY=8"
#endif
#endif

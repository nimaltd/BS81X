# BS814A-2 and BS818A-2 library
<br />
# I Don't Writen FreeRTOS and BS818A-2 Yet.
<br />
I hope use it and enjoy.
<br />
I use Stm32f0k6 and Keil Compiler and Stm32CubeMX wizard.
 <br />
Please Do This ...
<br />
<br />
1)  Select "General peripheral Initalizion as a pair of '.c/.h' file per peripheral" on project settings. 
<br />
2) Select 1 pin as gpio output for Clock and 1 pin as gpio input for Data.
<br />
3) Config your Bs81x_Conf.h. 
<br />
4) After Bs81x_Init() you can call Bs81x_Scan(). return -1 if no key pressed.

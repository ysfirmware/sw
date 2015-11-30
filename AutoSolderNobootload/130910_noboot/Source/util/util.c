#include "util.h"
#include "uartdef.h"
#include <stdarg.h>  
#include <stdio.h>  


//#pragma import(__use_no_semihosting_swi)

struct __FILE {
  int handle;                 // Add whatever you need here 
};
FILE __stdout;
FILE __stdin;

/*----------------------------------------------------------------------------
  fputc
 *----------------------------------------------------------------------------*/
int fputc(int ch, FILE *f) {
  USART_SendData(DEBUGPORT, (uint8_t)ch); 
	while (USART_GetFlagStatus(DEBUGPORT, USART_FLAG_TC) == RESET); 
	
	return ch; 
}

int fgetc(FILE *f) {
  int ch;

  do {
    ch = GetKey ();
  }
  while (ch == -1);
  USART_SendData(DEBUGPORT, (uint8_t)ch); 
  return (ch);
}

/*----------------------------------------------------------------------------
  _ttywrch
 *----------------------------------------------------------------------------*/
void _ttywrch(int ch) {
 USART_SendData(DEBUGPORT, (unsigned char) ch); 
}

/*----------------------------------------------------------------------------
  ferror
 *----------------------------------------------------------------------------*/
int ferror(FILE *f) {
                              // Your implementation of ferror
  return EOF;
}

/*----------------------------------------------------------------------------
  _sys_exit
 *----------------------------------------------------------------------------*/
void _sys_exit(int return_code) {
label:  goto label;           // endless loop
}

/*
void Delay(__IO uint32_t nCount)
{
	while(nCount--)
	{
		//__NOP();
	}
}
*/
#define _DLY_CNT_us_		40		// Polling 이므로 오차가 존재함 (Vector에 의한...) 1us좀 덜되게 함. 0.99
void delay_us(__IO uint32_t nCount)
{
	uint32_t u32SubCNT;

	while(nCount--)
	{
		u32SubCNT = _DLY_CNT_us_;
		while(u32SubCNT--)
		{
			__NOP();
		}
	}
}

void delay_ms(__IO uint32_t nCount)
{
	uint32_t u32SubCNT;

	nCount *= 1000;
	while(nCount--)
	{
		u32SubCNT = _DLY_CNT_us_;
		while(u32SubCNT--)
		{
			__NOP();
		}
	}
}

/*
void Delayms(unsigned int ms) //딜레이 함수..
{ 
  volatile unsigned int count, countmax = (MASTERCLOCK / 10000) * ms;
 
  for(count = 0; count < countmax; count++);
}

*/

#if 0
extern int _write(int fd, char *str, int len); 


void ts_itoa(char **buf, unsigned int d, int base)  
{       
	int div = 1;    
	while (d/div >= base)        
	div *= base;         
	while (div != 0)      
	{              
		int num = d/div;          
		d = d%div;                
		div /= base;                
		if (num > 9)                    
			*((*buf)++) = (num-10) + 'A';       
		else                        
			*((*buf)++) = num + '0';      
	}  
}  

int ts_formatstring(char *buf, const char *fmt, va_list va)  
{     
	char *start_buf = buf;    
	while(*fmt)       
	{            
		/* Character needs formating? */       
		if (*fmt == '%')         
		{                      
			switch (*(++fmt))               
			{                       
			case 'c':                       
				*buf++ = va_arg(va, int);        
				break;                       
			case 'd':                          
			case 'i':                   
				{                           
					signed int val = va_arg(va, signed int);    
					if (val < 0)                           
					{                                            
						val *= -1;                                         
						*buf++ = '-';                                   
					}                                         
					ts_itoa(&buf, val, 10);                         
				}                             
				break;           
			case 's':                             
				{                                     
					char * arg = va_arg(va, char *);          
					while (*arg)                                       
					{                                             
						*buf++ = *arg++;                      
					}                              
				}                               
				break;                       
			case 'u':                                
				ts_itoa(&buf, va_arg(va, unsigned int), 10);          
				break;                       
			case 'x':                       
			case 'X':                        
				ts_itoa(&buf, va_arg(va, int), 16);                                
				break;                            
			case '%':    
				*buf++ = '%';    
				break;                   
			}   
			fmt++;              
		}                 
		/* Else just copy */                
		else                 
		{                    
		*buf++ = *fmt++;            
		}          
	}          
	*buf = 0;          
	return (int)(buf - start_buf); 
}    
int ts_formatlength(const char *fmt, va_list va)
{
	int length = 0;      
	while (*fmt)       
	{               
		if (*fmt == '%')     
		{                
			++fmt;                
			switch (*fmt)                
			{                       
				case 'c':         
					va_arg(va, int);        
					++length;           
					break;                       
				case 'd':                  
				case 'i':                    
				case 'u':                             
					/* 32 bits integer is max 11 characters with minus sign */              
					length += 11;                               
					va_arg(va, int);                            
					break;                            
				case 's':                                  
					{                                        
						char * str = va_arg(va, char *);                
						while (*str++)                                     
							++length;                                   
					}                                   
					break;                           
				case 'x':                    
				case 'X':                    
					/* 32 bits integer as hex is max 8 characters */      
					length += 8;                              
					va_arg(va, unsigned int);                 
					break;                      
				default:                          
					++length;                         
					break;                        
			}     
		}              
		else             
		{                
			++length;        
		}                
	++fmt;          

	}   
	return length; 
}  



int LCDprintf(const char *fmt, ...)  
{        
	int length = 0;  
	  
	va_list va;        
	va_start(va, fmt);    
	length = ts_formatlength(fmt, va);          
	va_end(va);   
	{                  
		char buff[length];      
		va_start(va, fmt);             
		length = ts_formatstring(buff, fmt, va);         
		length = _write(1, buff, length);              
		va_end(va);         
	}     
	return length;  
}  

#endif 

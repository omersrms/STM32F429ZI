/*
 * http_ssi.c
 *
 *  Created on: 11-Oct-2021
 *      Author: controllerstech
 */


#include"http_ssi.h"
#include "string.h"
#include "stdio.h"

#include "lwip/tcp.h"
#include "lwip/apps/httpd.h"
#include "stm32f4xx_hal.h"
extern UART_HandleTypeDef huart3;
int indx = 0;
/* we will use character "x", "y","z" as tag for SSI */
char const* TAGCHAR[]={"x", "y", "z"};
char const** TAGS=TAGCHAR;

uint16_t ssi_handler (int iIndex, char *pcInsert, int iInsertLen)
{
	switch (iIndex) {
		case 0:
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		case 1:
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		case 2:
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		default :
			break;
	}

	return 0;
}

/************************ CGI HANDLER ***************************/
const char *CGIForm_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);
const char *CGILED_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

const tCGI FORM_CGI = {"/form.cgi", CGIForm_Handler};
const tCGI LED_CGI = {"/led.cgi", CGILED_Handler};

char name[30];

tCGI CGI_TAB[2];


const char *CGIForm_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	if (iIndex == 0)
	{
		for (int i=0; i<iNumParams; i++)
		{
			if (strcmp(pcParam[i], "baud") == 0)  // if the fname string is found
			{
				memset(name, '\0', 30);
				strcpy(name, pcValue[i]);

				if (strncmp(name,"115200",6) == 0)
							{
					// baud 115200
							}
				else if (strncmp(name, "57600",5) == 0)
							{
					// baud 115200
							}
				else if (strncmp(name, "38400",5) == 0)
							{
					// baud 115200
							}
				else if (strncmp(name, "19200",5) == 0)
							{
					// baud 115200
							}
				else if (strncmp(name, "9600",4) == 0)
							{
					// baud 115200
							}
			}
			else if (strcmp(pcParam[i], "parity") == 0)
			{
				memset(name, '\0', 30);
				strcpy(name, pcValue[i]);

				if (strncmp(name,"None",4) == 0)
							{
					// none
							}
				else if (strncmp(name, "Odd",3) == 0)
							{
					// odd
							}
				else if (strncmp(name, "Even",4) == 0)
							{
					// even
							}
				else if (strncmp(name, "Mark",4) == 0)
							{
					// mark
							}
				else if (strncmp(name, "Space",5) == 0)
							{
					// space
							}
			}
				else if (strcmp(pcParam[i], "dbits") == 0)
				{
					memset(name, '\0', 30);
					strcpy(name, pcValue[i]);

					if (strncmp(name,"8bits",5) == 0)
								{
						// none
								}
					else if (strncmp(name,"7bits",5) == 0)
								{
						// odd
								}
					else if (strncmp(name,"6bits",5) == 0)
								{
						// even
								}
					else if (strncmp(name, "5bits",5) == 0)
								{
						// mark
								}
				}else if (strcmp(pcParam[i], "sbits") == 0)
				{
					memset(name, '\0', 30);
					strcpy(name, pcValue[i]);

					if (strncmp(name,"1bit",4) == 0)
								{
						// none
								}
					else if (strncmp(name,"2bits",5) == 0)
								{
						// odd
								}

				}
				else if (strcmp(pcParam[i], "hfc") == 0)
				{
					memset(name, '\0', 30);
					strcpy(name, pcValue[i]);

					if (strncmp(name,"None",4) == 0)
								{
						// none
								}
					else if (strncmp(name,"DTR/DSR",7) == 0)
								{
						// odd
								}
					else if (strncmp(name,"RTS/CTS",7) == 0)
								{
						// even
								}
					else if (strncmp(name, "Rs485-rts",9) == 0)
								{
						// mark
								}
				}
				else if (strcmp(pcParam[i], "data") == 0)
				{
					HAL_GPIO_TogglePin(LD3_GPIO_Port,LD3_Pin);
					memset(name, '\0', 30);
					strcpy(uart_data, pcValue[i]);
					HAL_UART_Transmit(&huart3,uart_data,sizeof(uart_data),HAL_MAX_DELAY);
					HAL_Delay(2000);

				}

			}








	}

	return "/cgiform.html";
}


const char *CGILED_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	if (iIndex == 1)
	{
		for (int i=0; i<iNumParams; i++)
		{
			if (strcmp(pcParam[i], "LED1") == 0)
			{
				HAL_GPIO_TogglePin(LD1_GPIO_Port,LD1_Pin);
			}

			else if (strcmp(pcParam[i], "LED2") == 0)
			{
				HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);
			}
			else if (strcmp(pcParam[i], "LED3") == 0)  // if the fname string is found
			{
				HAL_GPIO_TogglePin(LD3_GPIO_Port,LD3_Pin);
			}
		}
	}

	return "/cgiled.html";
}


void http_server_init (void)
{
	httpd_init();

	http_set_ssi_handler(ssi_handler, (char const**) TAGS, 3);

	CGI_TAB[0] = FORM_CGI;
	CGI_TAB[1] = LED_CGI;

//	http_set_cgi_handlers (&FORM_CGI, 1);
	http_set_cgi_handlers (CGI_TAB, 2);
}

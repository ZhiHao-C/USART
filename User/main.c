#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_usart.h"
#include <stdio.h>
//uint8_t a[10]={1,2,3,4,5,6,7,8,9,10};

void delay_ms(int n)//��ʱ����
{
	int i;
	while (n--)
	{
		for(i=0;i<5520;i++);
	}
}



int main()
{
	uint8_t ch;
	USART_Config();
	
	
	
//	USART_Sendbyte(USART1,0x64);
//	USART_Send_twobyte(USART1,0xff56);
//	USART_Sendarr(USART1,a,10);
//	USART_Sendstr(DEBUG_USARTx,"�Һ�������");
//	printf("���ڲ���");
//	putchar('p');
	
	while (1)
	{
		ch=getchar();
		printf("ch=%c\n",ch);
		switch(ch)//ʵ�ֵ����Ը���Ƭ������1ʱ���̵ƣ�2Ϊ����3Ϊ���
		{
			case '1':GPIO_DeInit(GPIOB);LED_G_GPIO_Config();led_G(on);break;
			case '2':GPIO_DeInit(GPIOB);LED_B_GPIO_Config();led_B(on);break;
			case '3':GPIO_DeInit(GPIOB);LED_R_GPIO_Config();led_R(on);break;
			default:all_ledoff;break;
		}
		
	}
	
}


////���մ����жϺ���
//void DEBUG_USART_IRQHandler(void)
//{
//	uint8_t temp;
//	if((USART1->SR&0x20)==0x20)
//	{
//		temp=USART_ReceiveData(USART1);
//		USART_SendData(USART1,temp);
//		while (!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
//	}
//}	




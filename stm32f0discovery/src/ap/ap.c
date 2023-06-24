/*
 * ap.c
 *
 *  Created on: Jun 23, 2023
 *      Author: KIMMINJI
 */


#include "ap.h"




void apInit(void)
{
  uartOpen(_DEF_UART1, 115200);
}

void apMain(void)
{
  uint32_t pre_time;
  uint8_t btn_state;

  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      /*board LD3 Toggle*/
      ledToggle(_DEF_LED1);

      /*uartPrint: millis value for checking uart state*/
      uartPrintf(_DEF_UART1, "Uart1 %d\n", millis());

      /*Check Reed port State*/
      btn_state = Read_Reed_state();
      uartPrintf(_DEF_UART1, "button %d\n", btn_state);

      uartPrintf(_DEF_UART1, "register %d\n", Holding_Registers_Database[0]);
    }

    if (uartAvailable(_DEF_UART1)>0)
    {
      uint8_t rx_data;

      rx_data = uartRead(_DEF_UART1);
      uartPrintf(_DEF_UART1, "Uart1 Rx %c %X\n", rx_data, rx_data);
    }

  }
}

uint8_t Read_Reed_state(void)
{
  uint8_t ret = 0;
  GPIO_PinState state;

  state = buttonStateCheck(_DEF_BUTTON1);

  if (state == GPIO_PIN_SET)
  {
    ret = 1;
    Holding_Registers_Database[0] = 1234;
  }
  else
  {
    ret = 0;
    Holding_Registers_Database[0] = 5555;
  }

  return ret;
}

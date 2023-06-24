/*
 * hw.c
 *
 *  Created on: Jun 23, 2023
 *      Author: KIMMINJI
 */


#include "hw.h"




void hwInit(void)
{
  bspInit();
  ledInit();
  uartInit();
  buttonInit();
}

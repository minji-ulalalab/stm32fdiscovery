/*
 * modbusSlave.h
 *
 *  Created on: Oct 27, 2022
 *      Author: controllerstech.com
 */

#ifndef INC_MODBUSSLAVE_H_
#define INC_MODBUSSLAVE_H_

#include "modbus_crc.h"
#include "hw_def.h"

#define SLAVE_ID               HW_SLAVE_ID

#define ILLEGAL_FUNCTION       HW_ILLEGAL_FUNCTION
#define ILLEGAL_DATA_ADDRESS   HW_ILLEGAL_DATA_ADDRESS
#define ILLEGAL_DATA_VALUE     HW_ILLEGAL_DATA_VALUE



uint8_t readHoldingRegs (void);
uint8_t readInputRegs (void);

#endif /* INC_MODBUSSLAVE_H_ */

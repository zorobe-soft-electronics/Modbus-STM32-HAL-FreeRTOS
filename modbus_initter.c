/*
 * modbus_initter.c
 *
 *  Created on: Jan 20, 2025
 *      Author: Kornel
 */

#include "usart.h"
#include "Modbus.h"

#define SLAVE_ID (0x01)

extern uint16_t* const modData[314];

modbusHandler_t modbusExternal;
modbusHandler_t modbusDisplay;

void initModbusHandlers(){

	modbusExternal.uModbusType = MB_SLAVE;
	modbusExternal.port = &EXT_UART_INST;
	modbusExternal.u8id = SLAVE_ID;
	modbusExternal.u16timeOut = 1000;
	modbusExternal.EN_Port = EXT_RS485_DIR_GPIO_Port;
	modbusExternal.EN_Pin = EXT_RS485_DIR_Pin;
	modbusExternal.u16regs = &modData;
	modbusExternal.u16regsize= sizeof(modData)/sizeof(modData[0]);
	modbusExternal.xTypeHW = USART_HW_DMA;

	ModbusInit(&modbusExternal);
	ModbusStart(&modbusExternal);

	modbusDisplay.uModbusType = MB_SLAVE;
	modbusDisplay.port = &DISPLAY_UART_INST;
	modbusDisplay.u8id = SLAVE_ID;
	modbusDisplay.u16timeOut = 1000;
	modbusDisplay.EN_Port = DISP_RS485_DIR_GPIO_Port;
	modbusDisplay.EN_Pin = DISP_RS485_DIR_Pin;
	modbusDisplay.u16regs = &modData;
	modbusDisplay.u16regsize= sizeof(modData)/sizeof(modData[0]);
	modbusDisplay.xTypeHW = USART_HW_DMA;

	ModbusInit(&modbusDisplay);
	ModbusStart(&modbusDisplay);
}

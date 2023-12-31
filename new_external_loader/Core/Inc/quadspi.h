/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    quadspi.h
  * @brief   This file contains all the function prototypes for
  *          the quadspi.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __QUADSPI_H__
#define __QUADSPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern QSPI_HandleTypeDef hqspi;

/* USER CODE BEGIN Private defines */

uint8_t CSP_QUADSPI_Init(void);
uint8_t CSP_QSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress);
uint8_t CSP_QSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size);
uint8_t CSP_QSPI_EnableMemoryMappedMode(void);
uint8_t CSP_QSPI_Erase_Chip (void);
uint8_t CSP_EXIT_MEMORY_MAPPED_MODE(void);
/* USER CODE END Private defines */

void MX_QUADSPI_Init(void);

/* USER CODE BEGIN Prototypes */

/*N25Q256A memory parameters*/
#define MEMORY_FLASH_SIZE               0x2000000 /* 256 MBits*/
#define MEMORY_SECTOR_SIZE				0x1000 		/* 4KB */
#define MEMORY_PAGE_SIZE                0x100     /* 256 bytes */


/*MY WINBOND  commands */




#define WRITE_ENABLE_CMD 0x06
#define READ_STATUS_REG1_CMD 0x05
#define READ_STATUS_REG2_CMD 0x35
#define WRITE_STATUS_REG1_CMD 0x01
#define WRITE_STATUS_REG2_CMD 0x31
#define SECTOR_ERASE_CMD 0x20
//use BLOCK_ERASE_64KB_CMD instead of the above one ;
#define BLOCK_ERASE_32KB_CMD 0x52
#define BLOCK_ERASE_64KB_CMD 0xD8
#define CHIP_ERASE_CMD 0xC7
#define PAGE_PROGRAM_CMD 0x02
#define QUAD_PAGE_PROGRAM_CMD 0x32
#define FAST_READ_CMD 0x0B
#define FAST_READ_DUAL_OUT_CMD 0x3B
#define FAST_READ_QUAD_OUT_CMD 0x6B
#define FAST_READ_DUAL_IO_CMD 0xBB
#define FAST_READ_QUAD_IO_CMD 0xEB
#define FAST_READ_QUAD_4_BYTE_ADDRESSING_MODE 0XEC
#define RESET_ENABLE_CMD 0x66
#define RESET_MEMORY_CMD 0x99
#define PAGE_PROGRAM_QUAD_INP_4B 0x34U

// Application-specific definitions:
#define W25Q256JV_SR_WREN 0x02
#define READ_STATUS_REG_CMD READ_STATUS_REG1_CMD
#define W25Q256JV_SR_WIP 0x01
#define PAGE_PROG_CMD PAGE_PROGRAM_CMD
#define QUAD_INOUT_FAST_READ_CMD FAST_READ_QUAD_IO_CMD
#define QUAD_IN_FAST_PROG_CMD QUAD_PAGE_PROGRAM_CMD

// Additional definitions:
#define ENTER_4_BYTE_ADD_CMD 0xB7
#define WRITE_VOL_CFG_REG_CMD 0x81
#define READ_CONFIGURATION_REG_CMD 0x85
#define QUAD_OUT_FAST_READ_CMD 0xEB
#define DUMMY_CLOCK_CYCLES_READ_QUAD 0
#define RESET_EXECUTE_CMD 0x99





/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __QUADSPI_H__ */


# External Loader for Winbond Q25Q256JV using STM32H750VB (QuadSPI Interface)

## Overview

This set of code files forms an external loader implementation for interfacing with the Winbond Q25Q256JV flash memory using the STM32H750VB microcontroller through a Quad-SPI (QSPI) interface. The loader is designed to initialize the QSPI peripheral, program, erase, and read the flash memory.

## Files and Modules

- `quadspi.h`: Header file for the QuadSPI interface. It includes function prototypes and necessary includes for the QSPI configuration and operations.

- `main.h`: Main header file, including declarations and includes central to the overall functionality of the loader.

- `gpio.h`: Header file for the General-Purpose Input/Output (GPIO) configurations necessary for the QSPI interface.

- `Dev_Inf.c`: Contains the `StorageInfo` structure with detailed information about the memory device, including device type, start address, size, page size, sector information, and initial memory content.

- `quadspi.c`: Main source file containing the definitions of functions to configure and interact with the QSPI peripheral. This file includes functions for initialization, write, erase, and read operations on the flash memory.

## Key Functions

- `Init()`: Initializes the system, including setting up the system clock, GPIO, and QuadSPI peripheral. It also includes necessary adaptations for different device types (e.g., STM32H7 series).

- `Write(uint32_t Address, uint32_t Size, uint8_t* buffer)`: Programs the memory at the specified address with the data provided in the buffer. The size parameter specifies the number of bytes to write.

- `SectorErase(uint32_t EraseStartAddress, uint32_t EraseEndAddress)`: Erases a sector of the memory starting from EraseStartAddress to EraseEndAddress.

- `MassErase()`: Performs a mass erase of the external flash memory. It is optional and can be omitted if not required.

- `CheckSum(uint32_t StartAddress, uint32_t Size, uint32_t InitVal)`: Calculates a checksum of the specified memory zone, starting at StartAddress for Size bytes.

- `Verify(uint32_t MemoryAddr, uint32_t RAMBufferAddr, uint32_t Size, uint32_t missalignement)`: Verifies the flash memory against a RAM buffer and calculates a checksum value of the programmed memory.

- `CSP_QUADSPI_Init()`: Configures and initializes the QuadSPI peripheral for communication with the external flash memory.

- `CSP_QSPI_EraseSector()`, `CSP_QSPI_Erase_Chip()`, `CSP_QSPI_WriteMemory()`: These functions are used for erasing sectors, the entire chip, and writing data to the flash memory, respectively.

- `QSPI_AutoPollingMemReady()`, `QSPI_Configuration()`, `QSPI_ResetChip()`, `QSPI_WriteEnable()`: Internal helper functions for handling the QSPI commands like write enable, chip reset, automatic polling for memory readiness, and configuration settings.

- `CSP_QSPI_EnableMemoryMappedMode()`: Enables Memory-Mapped mode for the QSPI, facilitating easier access to the flash memory.

## Conclusion

This documentation provides a comprehensive guide to the `external_loader_winbond_q25q256jv` used with the STM32H750VB microcontroller. It is designed for interfacing with the Winbond Q25Q256JV flash memory via QSPI, covering initialization, programming, erasing, and verifying memory operations. This documentation should be included with the source code for reference and guidance in utilizing the loader effectively.

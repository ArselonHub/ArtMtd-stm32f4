/*
 * SdDefines.h
 *
 *  Created on: Mar 14, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_SDDEFINES_H_
#define ART_PRIVATE_SDDEFINES_H_

#include <Art/Types.h>

namespace Art
{
	enum SdCommand
	{
		SdCommandCMD0_GoIdle = 0, ///< Go Idle
		SdCommandCMD2_AllSendCid = 2, ///< Send CID
		SdCommandCMD3_SendRelativeAddr = 3, ///< Send Relative Address
		SdCommandCMD7_SelectDeselect = 7, ///< Select/Deselect card for transfer mode
		SdCommandCMD8_SendIfCondition = 8,
		SdCommandCMD9_SendCardSpecificData = 9,
		SdCommandCMD13_SendStatus = 13,
		SdCommandCMD16_SetBlockLength = 16,
		SdCommandCMD17_ReadSingleBlock = 17,
		SdCommandCMD18_ReadMultipleBlock = 18,
		SdCommandCMD24_WriteBlock = 24, ///< Write Block
		SdCommandCMD55_AppCommand = 55,
		SdCommandACMD41_AppOpCondition = 41,
	};

	struct SdCsdStruct
	{
		UWord padding: 1;
		UWord crc: 7;
		UWord reserved0: 2;
		UWord fileFormat: 2;
		UWord tmpWriteProtection: 1;
		UWord permanentWriteProtection: 1;
		UWord copyFlag: 1;
		UWord fileFormatGroup: 1;
		UWord reserved1: 5;
		UWord partialWriteAllowed: 1;
		UWord writeBlockLength: 4;
		UWord writeSpeedFactor: 3;
		UWord reserved2: 2;
		UWord writeGroupEnabled: 1;
		UWord writeProtectGroupSize: 7;
		UWord eraseSectorSize: 7;
		UWord eraseSingleBlockEnable: 1;
		UWord deviceSizeMultiplier: 3;
		UWord maxWriteCurrentAtVddMax: 3;
		UWord maxWriteCurrentAtVddMin: 3;
		UWord maxReadCurrentAtVddMax: 3;
		UWord maxReadCurrentAtVddMin: 3;
		UWord deviceSize: 12;
		UWord reserved3: 2;
		UWord dsrImplemented: 1;
		UWord readBlockMisalignment: 1;
		UWord writeBlockMisalignment: 1;
		UWord partialReadAllowed: 1;
		UWord maxReadBlockLenght: 4;
		UWord commandClasses: 12;
		UWord maxTransferRate: 8;
		UWord dataReadAccessTime2:8;
		UWord dataReadAccesstime1: 8;
		UWord reserved4: 6;
		UWord version: 2;
	} __attribute((packed));

	struct SdCsdStruct2
	{
		UWord padding: 1;
		UWord crc: 7;
		UWord reserved0: 2;
		UWord fileFormat: 2;
		UWord tmpWriteProtection: 1;
		UWord permanentWriteProtection: 1;
		UWord copyFlag: 1;
		UWord fileFormatGroup: 1;
		UWord reserved1: 5;
		UWord partialWriteAllowed: 1;
		UWord writeBlockLength: 4;
		UWord writeSpeedFactor: 3;
		UWord reserved2: 2;
		UWord writeGroupEnabled: 1;
		UWord writeProtectGroupSize: 7;
		UWord eraseSectorSize: 7;
		UWord eraseSingleBlockEnable: 1;
		UWord reserved3:1;
		UWord deviceSize: 22;
		UWord reserved4: 6;
		UWord dsrImplemented: 1;
		UWord readBlockMisalignment: 1;
		UWord writeBlockMisalignment: 1;
		UWord partialReadAllowed: 1;
		UWord maxReadBlockLenght: 4;
		UWord commandClasses: 12;
		UWord maxTransferRate: 8;
		UWord dataReadAccessTime2:8;
		UWord dataReadAccesstime1: 8;
		UWord reserved5: 6;
		UWord version: 2;
	} __attribute((packed));

}

#endif /* SOURCE_ART_PRIVATE_SDDEFINES_H_ */

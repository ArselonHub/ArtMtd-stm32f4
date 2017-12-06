/*
 * Flash.h
 *
 *  Created on: Dec 29, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_FLASH_H_
#define SOURCE_FLASH_H_

#include <Art/Device.h>

namespace Art
{
	class Flash : public Device
	{
	public:
		virtual Int sectorSize(Word sector) = 0;
		virtual Word sectorCount() = 0;
		virtual Word eraseSector(Word sector) = 0;
		virtual Word eraseRange(Int start, Int end) = 0;
		virtual Long addressOf(Word sector) = 0;
		virtual Word sectorOf(Long address) = 0;
		virtual Word writeData(Long address, const void* data, Word length) = 0;
		virtual Word writeData(Long address, const void* data0, Word length0, const void* data1, Word length1) = 0;
		virtual Word copy(Long target, Long source, Word length) = 0;
		virtual Word readData(Long address, void* data, Word length) = 0;
		virtual Word blockSizeInPowerOf2() = 0;
	};

} /* namespace Art */

#endif /* SOURCE_FLASH_H_ */

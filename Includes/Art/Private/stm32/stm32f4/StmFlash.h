/*
 * StmFlash.h
 *
 *  Created on: Dec 29, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_STMFLASH_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_STMFLASH_H_

#include <Art/Flash.h>

namespace Art
{
	enum FlashVoltageRange
	{
		FlashVoltageRange1_7Vto2_1V,
		FlashVoltageRange2_1Vto2_7V,
		FlashVoltageRange2_7Vto3_6V,
		FlashVoltageRangeExternalVpp
	};

	namespace Private
	{

		class StmFlash : public Flash
		{
		public:
			StmFlash();
			virtual ~StmFlash();

			virtual Int sectorSize(Word sector);
			virtual Word sectorCount();
			virtual Word eraseSector(Word sector);
			virtual Word eraseRange(Int start, Int end);
			virtual Long addressOf(Word sector);
			virtual Word sectorOf(Long address);
			virtual Word writeData(Long address, const void* data, Word length);
			virtual Word writeData(Long address, const void* data0, Word length0,
					const void* data1, Word length1);
			virtual Word readData(Long address, void* data, Word length);
			virtual Word blockSizeInPowerOf2();
			virtual Word copy(Long target, Long source, Word length);

			FlashVoltageRange voltageRange() const;
			Word setVoltageRange(FlashVoltageRange voltageRange);

		protected:
			virtual Word openDevice();
			virtual Word closeDevice();
			UByte				m_sectorSizes[23];
			Byte				m_sectorCount;
			FlashVoltageRange	m_voltageRange;
		};

		inline Art::FlashVoltageRange StmFlash::voltageRange() const
		{
			return m_voltageRange;
		}


} /* namespace Private */

	extern Private::StmFlash* ifm();

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_STMFLASH_H_ */

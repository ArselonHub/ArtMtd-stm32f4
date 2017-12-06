/*
 * StmSdio.h
 *
 *  Created on: Feb 28, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_SDIO_H_
#define ART_PRIVATE_STM32_STM32F4_SDIO_H_

#include <Art/Private/SdioSdCard.h>

namespace Art
{
	namespace Private
	{
		class StmSdio : public Private::SdioSdCard
		{
		public:
			StmSdio();
			virtual ~StmSdio();

			Pin* ckPin() const;
			Pin* cmdPin() const;
			Pin* d0Pin() const;
			void setCkPin(Pin* ckPin);
			void setCmdPin(Pin* cmdPin);
			void setD0Pin(Pin* d0Pin);

		private:
			virtual Word openDevice();
			virtual Word closeDevice();

			virtual Word powerUpPort();
			virtual Word powerDownPort();
			virtual Word executePort(SdCommand command, UWord argument);
			virtual Word executePort(SdCommand command, UWord argument, void* response);
			virtual Word writeSectorPort(UInt index, void* buffer);
			virtual Word readSectorPort(UInt index, void* buffer);
			virtual Word setSpeedPort(Int value);

			Pin* m_d0Pin;
			Pin* m_d1Pin;
			Pin* m_d2Pin;
			Pin* m_d3Pin;
			Pin* m_ckPin;
			Pin* m_cmdPin;
		};

		inline Art::Pin* StmSdio::ckPin() const
		{
			return m_ckPin;
		}

		inline void StmSdio::setCkPin(Pin* ckPin)
		{
			m_ckPin = ckPin;
		}

		inline Art::Pin* StmSdio::cmdPin() const
		{
			return m_cmdPin;
		}

		inline void StmSdio::setCmdPin(Pin* cmdPin)
		{
			m_cmdPin = cmdPin;
		}

		inline Art::Pin* StmSdio::d0Pin() const
		{
			return m_d0Pin;
		}

		inline void StmSdio::setD0Pin(Pin* d0Pin)
		{
			m_d0Pin = d0Pin;
		}

	}

	extern Private::StmSdio* sdio();
}

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_SDIO_H_ */

/*
 * SdCard.h
 *
 *  Created on: Feb 28, 2017
 *      Author: denizcan
 */

#ifndef ART_SDCARD_H_
#define ART_SDCARD_H_

#include <Art/Device.h>
#include <Art/Disk.h>
#include <Art/LevelDetector.h>
#include <Art/Private/SdDefines.h>

namespace Art
{
	class SdCard : public Device, public Disk
	{
	public:
		SdCard();
		virtual ~SdCard();
		Pin* cardDetectPin();
		void setCardDetectPin(Pin* value);
		Thread* thread();
		void setThread(Thread* value);

		Signal<void*> onCardInserted() SIGNAL;
		Signal<void*> onCardRemoved() SIGNAL;

		Word executeAppCommand(SdCommand command, UWord argument, void* response);
		Word execute(SdCommand command, UWord argument);
		Word execute(SdCommand command, UWord argument, void* response);
		virtual Word writeSector(UInt index, void* buffer);
		virtual Word readSector(UInt index, void* buffer);
		virtual UInt sectorCount();

		Bool isAttached() const;
		Bool isInserted() const;

		Pin* powerPin() const;
		void setPowerPin(Pin* powerPin);

		Word attach();
		Word detach();

		Bool isAutoAttach() const;
		Bool isSdhc() const;
		void setAutoAttach(Bool value);

	protected:
		virtual Word openDevice();
		virtual Word closeDevice();
		virtual void doAfterOpen();
		Word processCsd(void* value);
		Word setSpeed(Int value);
		UInt toPhysicalBlockAddress(UInt value);
	private:
		void doCardDetectionEvent(void* sender);
		void doCardInserted();
		void doCardRemoved();

		virtual Word powerUpPort() = 0;
		virtual Word powerDownPort() = 0;
		virtual Word initializePort() = 0;
		virtual Word executePort(SdCommand command, UWord argument) = 0;
		virtual Word executePort(SdCommand command, UWord argument, void* response) = 0;
		virtual Word writeSectorPort(UInt address, void* block) = 0;
		virtual Word readSectorPort(UInt address, void* block) = 0;
		virtual Word setSpeedPort(Int value) = 0;

		LevelDetector	m_cardDetector;
		Bool			m_inserted;
		Bool			m_attached;
		Bool			m_autoAttach;
		Bool			m_sdhc;
		Pin*			m_powerPin;
		UInt			m_sectorCount;
	};

	inline Art::Pin* SdCard::cardDetectPin()
	{
		return m_cardDetector.pin();
	}

	inline void SdCard::setCardDetectPin(Pin* value)
	{
		m_cardDetector.setPin(value);
	}

	inline Thread* SdCard::thread()
	{
		return m_cardDetector.thread();
	}

	inline void SdCard::setThread(Thread* value)
	{
		m_cardDetector.setThread(value);
	}


	inline Bool SdCard::isInserted() const
	{
		return m_inserted;
	}

	inline Pin* SdCard::powerPin() const
	{
		return m_powerPin;
	}

	inline void SdCard::setPowerPin(Pin* powerPin)
	{
		m_powerPin = powerPin;
	}

	inline Bool SdCard::isAttached() const
	{
		return m_attached;
	}

	inline Bool SdCard::isAutoAttach() const
	{
		return m_autoAttach;
	}

	inline Bool SdCard::isSdhc() const
	{
		return m_sdhc;
	}

	inline void SdCard::setAutoAttach(Bool value)
	{
		m_autoAttach = value;
	}

	inline UInt SdCard::toPhysicalBlockAddress(UInt value)
	{
		return m_sdhc ? value : (value * 512);
	}

}

#ifndef ART_PRIVATE_SDIOSDCARD_H_
	#include <Art/Private/stm32/stm32f4/StmSdio.h>
#endif

#endif

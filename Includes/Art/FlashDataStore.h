/*
 * FlashDataStore.h
 *
 *  Created on: Dec 31, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_FLASHDATASTORE_H_
#define SOURCE_ART_FLASHDATASTORE_H_

#include <Art/DataStore.h>
#include <Art/Flash.h>

namespace Art
{
	class FlashDataStore : public DataStore
	{
	public:
		FlashDataStore();
		virtual ~FlashDataStore();
		Word open();

		virtual Bool isOpen();
		virtual Word close();
		virtual Word read(UShort key, void* data, Word length);
		virtual Word write(UShort key, const void* data, Word length);
		virtual Word hasKey(UShort key);
		virtual Word erase();

		Flash* flash() const;
		void setFlash(Flash* flash);

		Int endAddress() const;
		Int startAddress() const;
		void setEndAddress(Int endAddress);
		void setStartAddress(Int startAddress);
		Word compact();

	private:
		Int find(UShort key, void* header);

		Word closeOnError(Word result);
		Int checkHalf(Int startAddress, Int endAddress);

		Flash*	m_flash;
		Int		m_startAddress;
		Int		m_endAddress;
		volatile Int m_cursor;
	};

	inline Flash* FlashDataStore::flash() const
	{
		return m_flash;
	}

	inline void FlashDataStore::setFlash(Flash* flash)
	{
		m_flash = flash;
	}

	inline Int FlashDataStore::endAddress() const
	{
		return m_endAddress - 1;
	}

	inline void FlashDataStore::setEndAddress(Int endAddress)
	{
		m_endAddress = endAddress + 1;
	}

	inline Int FlashDataStore::startAddress() const
	{
		return m_startAddress;
	}

	inline void FlashDataStore::setStartAddress(Int startAddress)
	{
		m_startAddress = startAddress;
	}
} /* namespace Art */

#endif /* SOURCE_ART_FLASHDATASTORE_H_ */

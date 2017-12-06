/*
 * Sector.h
 *
 *  Created on: Mar 17, 2017
 *      Author: denizcan
 */

#ifndef ART_SECTOR_H_
#define ART_SECTOR_H_

#include <Art/BasicStack.h>
#include <Art/BasicQueue.h>

namespace Art
{
	namespace Private
	{
		class SectorDevice;
	}

	class Sector
	{
	public:
		UInt index();
		Bool isModified();
		void makeModified();
		UByte* data();
		Word release();
		Word flush();
	private:
		Sector*	m_next;
		UByte*	m_data;
		Private::SectorDevice*	m_device;
		UInt	m_index;
		Word	m_refCount;
		Bool	m_modified;

		friend class BasicStack<Sector>;
		friend class BasicQueue<Sector>;
		friend class Private::SectorDevice;
	};

	inline UInt Sector::index()
	{
		return m_index;
	}

	inline Bool Sector::isModified()
	{
		return m_modified;
	}

	inline void Sector::makeModified()
	{
		m_modified = 1;
	}

	inline UByte* Sector::data()
	{
		return m_data;
	}

} /* namespace Art */

#endif /* SOURCE_ART_SECTOR_H_ */

/*
 * Partition.h
 *
 *  Created on: Mar 17, 2017
 *      Author: denizcan
 */

#ifndef ART_PARTITION_H_
#define ART_PARTITION_H_

#include <Art/Private/SectorDevice.h>
#include <Art/String.h>
#include <Art/BasicStack.h>

namespace Art
{
	class Disk;

	class Partition : public Private::SectorDevice
	{
	public:
		Partition(Disk* disk, UInt firstSector, UInt sectorCount);
		virtual ~Partition();
	private:
		virtual Word readSector(UInt index, void* buffer);
		virtual Word writeSector(UInt index, void* buffer);
		virtual UInt sectorCount();

		Partition* 	m_next;
		Disk*		m_disk;
		UInt		m_firstSector;
		UInt		m_sectorCount;

		friend class DiskManager;
		friend class BasicStack<Partition>;
	};

} /* namespace Art */

#endif /* SOURCE_ART_PARTITION_H_ */

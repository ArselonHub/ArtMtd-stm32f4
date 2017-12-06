/*
 * Disk.h
 *
 *  Created on: Mar 16, 2017
 *      Author: denizcan
 */

#ifndef ART_DISK_H_
#define ART_DISK_H_

#include <Art/Types.h>
#include <Art/Sector.h>
#include <Art/Private/SectorDevice.h>
#include <Art/Partition.h>
#include <Art/BasicStack.h>
#include <Art/List.h>

namespace Art
{
	class Disk : public Private::SectorDevice
	{
	public:
		Word partitionCount();
		Partition* partitionAt(Word index);
	private:
		BasicStack<Partition> m_partitions;
	};

} /* namespace Art */

#endif /* SOURCE_ART_DISK_H_ */

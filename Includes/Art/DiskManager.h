/*
 * DiskManager.h
 *
 *  Created on: Mar 16, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_DISKMANAGER_H_
#define SOURCE_ART_DISKMANAGER_H_

#include <Art/BasicStack.h>
#include <Art/BasicQueue.h>
#include <Art/FileSystem.h>
#include <Art/String.h>
#include <Art/Disk.h>
#include <Art/Partition.h>
#include <Art/Sector.h>

namespace Art
{
	class DiskManager
	{
	public:
		void addFileSystem(FileSystem* fileSystem);
		Word mountDisk(Disk* disk, const String& path);
		static DiskManager* instance();
	private:
		Word getFileSystem(FileSystem** value);
		Word mountPartition(Partition* partition);

		BasicStack<FileSystem> m_fileSystems;
		BasicStack<Partition> m_partitions;
		BasicStack<Sector> m_activeSectors;
		BasicQueue<Sector> m_freeSectors;

		static DiskManager s_instance;

		friend class Sector;
		friend class Disk;
	};

	inline DiskManager* DiskManager::instance()
	{
		return &s_instance;
	}

	inline DiskManager* diskManager()
	{
		return DiskManager::instance();
	}

} /* namespace Art */

#endif /* SOURCE_ART_DISKMANAGER_H_ */

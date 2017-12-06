/*
 * FileSystem.h
 *
 *  Created on: Mar 16, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_FILESYSTEM_H_
#define SOURCE_ART_FILESYSTEM_H_

#include <Art/BasicStack.h>
#include <Art/Partition.h>

namespace Art
{
	class FileSystem
	{
	public:
		Word open();
	private:
		virtual Word test(Partition* partition) = 0;
		virtual Word mount(Partition* partition) = 0;

		FileSystem* m_next;
		BasicStack<FileSystem> s_fileSytems;

		friend class BasicStack<FileSystem>;
		friend class DiskManager;
		friend class Disk;
		friend class Partition;
	};

} /* namespace Art */

#endif /* SOURCE_ART_FILESYSTEM_H_ */

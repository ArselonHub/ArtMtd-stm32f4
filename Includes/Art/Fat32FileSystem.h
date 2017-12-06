/*
 * FatFileSystem.h
 *
 *  Created on: Mar 16, 2017
 *      Author: denizcan
 */

#ifndef ART_FATFILESYSTEM_H_
#define ART_FATFILESYSTEM_H_

#include <Art/FileSystem.h>

namespace Art
{

	class Fat32FileSystem : public FileSystem
	{
	public:
		Fat32FileSystem();
		virtual ~Fat32FileSystem();
	private:
		virtual Word test(Partition* volume);
	};

	Fat32FileSystem* fat32FileSystem();

} /* namespace Art */

#endif /* SOURCE_ART_FATFILESYSTEM_H_ */

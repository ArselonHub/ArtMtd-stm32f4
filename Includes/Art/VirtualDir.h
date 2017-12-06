/*
 * VirtualDir.h
 *
 *  Created on: Mar 17, 2017
 *      Author: denizcan
 */

#ifndef ART_VIRTUALDIR_H_
#define ART_VIRTUALDIR_H_

#include <Art/VirtualFile.h>
#include <Art/BasicStack.h>
#include <Art/DirReader.h>

namespace Art
{

	class VirtualDir : public VirtualFile
	{
	public:
		VirtualDir(const String& name);
		Word add(VirtualFile* file);
	private:
		DirReader* createReader();

		BasicStack<VirtualFile> m_files;

		friend class VirtualDirReader;
	};

	extern VirtualDir* rootDir();

} /* namespace Art */

#endif /* SOURCE_ART_VIRTUALDIR_H_ */

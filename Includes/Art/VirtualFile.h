/*
 * VirtualFile.h
 *
 *  Created on: Mar 17, 2017
 *      Author: denizcan
 */

#ifndef ART_VIRTUALFILE_H_
#define ART_VIRTUALFILE_H_

#include <Art/String.h>
#include <Art/BasicStack.h>

namespace Art
{
	class VirtualFile
	{
	public:
		VirtualFile(const String& name);
		const String& name();
	private:
		VirtualFile*	m_next;
		String			m_name;

		friend class BasicStack<VirtualFile>;
		friend class VirtualDir;
		friend class VirtualDirReader;
	};

	inline const Art::String& VirtualFile::name()
	{
		return m_name;
	}

} /* namespace Art */

#endif /* SOURCE_ART_VIRTUALFILE_H_ */

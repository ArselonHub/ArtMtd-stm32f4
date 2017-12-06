/*
 * DirIterator.h
 *
 *  Created on: Mar 17, 2017
 *      Author: denizcan
 */

#ifndef ART_DIRITERATOR_H_
#define ART_DIRITERATOR_H_

#include <Art/String.h>
#include <Art/DirReader.h>

namespace Art
{

	class DirIterator
	{
	public:
		DirIterator();
		DirIterator(const String& path);
		~DirIterator();
		const String& fileName();
		const String& path();
		Word setPath(const String& path);
		Word next();
		Bool hasNext();

	private:
		DirReader* m_reader;
		const String m_path;
	};

inline const Art::String& DirIterator::path()
{
	return m_path;
}

} /* namespace Art */

#endif /* SOURCE_ART_DIRITERATOR_H_ */

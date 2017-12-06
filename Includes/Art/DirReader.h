/*
 * DirNode.h
 *
 *  Created on: Mar 17, 2017
 *      Author: denizcan
 */

#ifndef ART_DIRNODE_H_
#define ART_DIRNODE_H_

#include <Art/String.h>

namespace Art
{
	class DirReader
	{
	public:
		virtual ~DirReader() = 0;
		virtual const String& fileName() = 0;
		virtual Word next() = 0;
		virtual Bool hasNext() = 0;
	protected:
		virtual DirReader* createSubReader() = 0;

	};

} /* namespace Art */

#endif /* SOURCE_ART_DIRNODE_H_ */

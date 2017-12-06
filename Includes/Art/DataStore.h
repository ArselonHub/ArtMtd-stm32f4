/*
 * DataStore.h
 *
 *  Created on: Dec 31, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_DATASTORE_H_
#define SOURCE_ART_DATASTORE_H_

#include <Art/Types.h>

namespace Art
{
	class DataStore
	{
	public:
		DataStore();
		virtual ~DataStore();
		virtual Bool isOpen() = 0;
		virtual Word close() = 0;
		virtual Word read(UShort key, void* data, Word length) = 0;
		virtual Word write(UShort key, const void* data, Word length) = 0;
		virtual Word hasKey(UShort key) = 0;
		virtual Word erase() = 0;
	};
} /* namespace Art */

#endif /* SOURCE_ART_DATASTORE_H_ */

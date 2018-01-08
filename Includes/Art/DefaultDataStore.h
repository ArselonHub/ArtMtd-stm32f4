/*
 * DefaultDataStore.h
 *
 *  Created on: Jan 2, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_DEFAULTDATASTORE_H_
#define SOURCE_ART_DEFAULTDATASTORE_H_

#include <Art/DataStore.h>

namespace Art
{
	class FlashDataStore;

	namespace Private
	{
		class DefaultDataStore : public DataStore
		{
		public:
			DefaultDataStore();
			virtual ~DefaultDataStore();

			virtual Bool isOpen();
			virtual Word close();
			virtual Word read(UShort key, void* data, Word length);
			virtual Word write(UShort key, const void* data, Word length);
			virtual Word hasKey(UShort key);
			virtual Word erase();

			static DefaultDataStore* instance();
			const DataStore* target() const;
			void setTarget(DataStore* target);

		private:
			DataStore* m_target;

			static DefaultDataStore s_instance;

			friend class ::Art::FlashDataStore;
		};

		inline DefaultDataStore* DefaultDataStore::instance()
		{
			return &s_instance;
		}

		inline const DataStore* DefaultDataStore::target() const
		{
			return m_target;
		}

		inline void DefaultDataStore::setTarget(DataStore* target)
		{
			m_target = target;
		}
	}

	inline Private::DefaultDataStore* defaultDataStore()
	{
		return Private::DefaultDataStore::instance();
	}

} /* namespace Art */

#endif /* SOURCE_ART_DEFAULTDATASTORE_H_ */

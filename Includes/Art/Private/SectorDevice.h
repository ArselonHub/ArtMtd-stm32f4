/*
 * SectorDevice.h
 *
 *  Created on: Mar 17, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_SECTORDEVICE_H_
#define ART_PRIVATE_SECTORDEVICE_H_

#include <Art/Sector.h>

namespace Art
{
	class Sector;

	namespace Private
	{
		class SectorDevice
		{
		public:
			Word getSector(UInt index, Sector** value, Bool load = true);

			virtual Word readSector(UInt index, void* buffer) = 0;
			virtual Word writeSector(UInt index, void* buffer) = 0;
			virtual UInt sectorCount() = 0;
		private:
			static BasicStack<Sector> s_activeSectors;
			static BasicQueue<Sector> s_freeSectors;

			friend class ::Art::Sector;
		};
	}

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_SECTORDEVICE_H_ */

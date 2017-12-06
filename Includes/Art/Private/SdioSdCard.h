/*
 * SdioSdCard.h
 *
 *  Created on: Mar 4, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_SDIOSDCARD_H_
#define ART_PRIVATE_SDIOSDCARD_H_

#include <Art/SdCard.h>

namespace Art
{
	namespace Private
	{
		class SdioSdCard : public SdCard
		{
		public:
			SdioSdCard();
			virtual ~SdioSdCard();
			UWord m_rca;
		private:
			virtual Word initializePort();

		};
	}
}

#endif /* SOURCE_ART_SDIOSDCARD_H_ */

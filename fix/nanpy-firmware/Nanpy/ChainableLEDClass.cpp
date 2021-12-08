#include "cfg.h"

#if USE_ChainableLED

#include <Arduino.h>
#include "ChainableLED.h"
#include "ChainableLEDClass.h"
#include <stdlib.h>

const char* nanpy::ChainableLEDClass::get_firmware_id()
{
    return "ChainableLED";
}

void nanpy::ChainableLEDClass::elaborate( nanpy::MethodDescriptor* m ) {
        ObjectsManager<ChainableLED>::elaborate(m);

        if (strcmp(m->getName(),"new") == 0) {
            ChainableLED * leds;
			int pin = m->getInt(0);
			leds = new ChainableLED(m->getInt(0), m->getInt(1), m->getInt(2));
			v.insert(leds);
            m->returns(v.getLastIndex());
        }

        if (strcmp(m->getName(), "setRGB") == 0) {
           v[m->getObjectId()]->setColorRGB(m->getInt(0), m->getInt(1), m->getInt(2), m->getInt(3));
		    m->returns(0);
        }


};
#endif


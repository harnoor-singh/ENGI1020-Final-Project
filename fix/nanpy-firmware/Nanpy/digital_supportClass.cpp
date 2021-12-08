#include "cfg.h"

#if USE_digital_support

#include <Arduino.h>
#include "digital_support.h"
#include "digital_supportClass.h"
#include <stdlib.h>

const char* nanpy::digital_supportClass::get_firmware_id()
{
    return "digital_support";
}

void nanpy::digital_supportClass::elaborate( nanpy::MethodDescriptor* m ) {
				ObjectsManager<digital_support>::elaborate(m);

				if (strcmp(m->getName(),"new") == 0) {
								digital_support * ds;
								ds = new digital_support();
								v.insert(ds);
								m->returns(v.getLastIndex());
				}

			
				if (strcmp(m->getName(), "speakerPlayNote") == 0) {
								v[m->getObjectId()]->speakerPlayNote(m->getInt(0), m->getInt(1), m->getFloat(2));
								m->returns(0);
				}

};
#endif


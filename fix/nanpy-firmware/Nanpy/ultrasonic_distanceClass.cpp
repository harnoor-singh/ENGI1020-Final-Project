#include "cfg.h"

#if USE_ultrasonic_distance

#include <Arduino.h>
#include "ultrasonic_distance.h"
#include "ultrasonic_distanceClass.h"
#include <stdlib.h>

const char* nanpy::ultrasonic_distanceClass::get_firmware_id()
{
    return "ultrasonic_distance";
}

void nanpy::ultrasonic_distanceClass::elaborate( nanpy::MethodDescriptor* m ) {
	ObjectsManager<ultrasonic_distance>::elaborate(m);

	if (strcmp(m->getName(),"new") == 0) {
		ultrasonic_distance * ds;
		ds = new ultrasonic_distance();
		v.insert(ds);
		m->returns(v.getLastIndex());
	}


	if (strcmp(m->getName(), "ultraInit") == 0) {
		v[m->getObjectId()]->ultraInit(m->getInt(0));
		m->returns(0);
	}

	if (strcmp(m->getName(), "ultraGetDist") == 0) {
		m->returns(v[m->getObjectId()]->ultraGetDist());
	}


};
#endif


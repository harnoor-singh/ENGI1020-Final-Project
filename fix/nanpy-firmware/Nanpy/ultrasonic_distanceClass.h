#ifndef ULTRASONIC_DISTANCE_CLASS
#define ULTRASONIC_DISTANCE_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

#include "ultrasonic_distance.h"

class ultrasonic_distance;

namespace nanpy {

    class ultrasonic_distanceClass: public ObjectsManager<ultrasonic_distance> {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
}

#endif


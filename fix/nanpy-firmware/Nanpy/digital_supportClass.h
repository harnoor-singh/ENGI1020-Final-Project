#ifndef DIGITAL_SUPPORT_CLASS
#define DIGITAL_SUPPORT_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

#include "digital_support.h"

class digital_support;

namespace nanpy {

    class digital_supportClass: public ObjectsManager<digital_support> {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
}

#endif


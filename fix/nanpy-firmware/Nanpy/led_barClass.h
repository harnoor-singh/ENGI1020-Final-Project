#ifndef LED_BAR_CLASS
#define LED_BAR_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

#include "led_bar.h"

class led_bar;

namespace nanpy {

    class led_barClass: public ObjectsManager<led_bar> {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
}

#endif


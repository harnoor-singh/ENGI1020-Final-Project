#ifndef RGB_LCD_CLASS
#define RGB_LCD_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

#include "rgb_lcd.h"

class rgb_lcd;

namespace nanpy {

    class rgb_lcdClass: public ObjectsManager<rgb_lcd> {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
}

#endif

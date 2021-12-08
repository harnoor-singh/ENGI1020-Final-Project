#ifndef LCD_DISPLAY_CLASS
#define LCD_DISPLAY_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"
#include "lcd_display.h"

class lcd_display;

namespace nanpy {

    class lcd_displayClass: public ObjectsManager<lcd_display> {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
}

#endif


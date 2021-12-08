#include "cfg.h"

#if USE_rgb_lcd

#include <Arduino.h>
#include "rgb_lcd.h"
#include "rgb_lcdClass.h"
#include <stdlib.h>


const char* nanpy::rgb_lcdClass::get_firmware_id()
{
    return "rgb_lcd";
}

void nanpy::rgb_lcdClass::elaborate( nanpy::MethodDescriptor* m ) {
				ObjectsManager<rgb_lcd>::elaborate(m);

				if (strcmp(m->getName(),"new") == 0) {
								rgb_lcd * lcd;
								lcd = new rgb_lcd();
								//Was a pointer operation but wouldn't allow access to second line
								(*lcd).begin(16, 2);
								lcd->clear();
								v.insert(lcd);
								m->returns(v.getLastIndex());
				}

				if (strcmp(m->getName(), "print") == 0) {
								m->returns(v[m->getObjectId()]->print(m->getInt(0)));
				}

				if (strcmp(m->getName(), "printString") == 0) {
								v[m->getObjectId()]->printString(m->getString(0));
								m->returns(0);
				}

				if (strcmp(m->getName(), "clear") == 0) {
								v[m->getObjectId()]->clear();
								m->returns(0);
				}

				if (strcmp(m->getName(), "setRGB") == 0) {
								v[m->getObjectId()]->setRGB(m->getInt(0), m->getInt(1), m->getInt(2));
								m->returns(0);
				}

				if (strcmp(m->getName(), "moveCursor") == 0) {
								v[m->getObjectId()]->setCursor(m->getInt(0), m->getInt(1));
								m->returns(0);
				}

};
#endif

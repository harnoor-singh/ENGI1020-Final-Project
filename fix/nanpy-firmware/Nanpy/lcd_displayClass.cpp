#include "cfg.h"

#if USE_lcd_display

#include <Arduino.h>
#include "lcd_display.h"
#include "lcd_displayClass.h"
#include <stdlib.h>

const char* nanpy::lcd_displayClass::get_firmware_id()
{
    return "lcd_display";
}

void nanpy::lcd_displayClass::elaborate( nanpy::MethodDescriptor* m ) {
        ObjectsManager<lcd_display>::elaborate(m);

	if (strcmp(m->getName(),"lcdInit") == 0) {
		v[m->getObjectId()]->lcdInit();
		m->returns(0);
	}

	if (strcmp(m->getName(), "lcdPrint") == 0) {
		v[m->getObjectId()]->lcdPrint(m->getInt(0));
		m->returns(0);
	}

	if (strcmp(m->getName(), "lcdClear") == 0) {
		v[m->getObjectId()]->lcdClear();
		m->returns(0);
	}

	if (strcmp(m->getName(), "lcdMoveCursor") == 0) {
		v[m->getObjectId()]->lcdMoveCursor(m->getInt(0), m->getInt(1));
		m->returns(0);
	}

};
#endif


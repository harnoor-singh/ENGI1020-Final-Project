/*
 * Copyright (c) 2019-2020 Mahya Soleimani Jadidi
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "cfg.h"

#if USE_rgba_leds

#include <Arduino.h>
#include "rgba_leds.h"
#include "rgba_ledsClass.h"
#include <stdlib.h>

const char* nanpy::rgba_ledsClass::get_firmware_id()
{
    return "rgba_leds";
}

void nanpy::rgba_ledsClass::elaborate( nanpy::MethodDescriptor* m ) {
				ObjectsManager<rgba_leds>::elaborate(m);

				if (strcmp(m->getName(),"new") == 0) {
								rgba_leds * ds;
								ds = new rgba_leds();
                ds->rgbLedInit(m->getInt(0), m->getInt(1));
								v.insert(ds);
								m->returns(v.getLastIndex());
				}

			
				if (strcmp(m->getName(), "rgbLedInit") == 0) {
								v[m->getObjectId()]->rgbLedInit(m->getInt(0), m->getInt(1));
								m->returns(0);
				}

				if (strcmp(m->getName(), "rgbLedHSB") == 0) {
								v[m->getObjectId()]->rgbLedHSB(m->getInt(0), m->getFloat(1), m->getFloat(2), m->getFloat(3));
								m->returns(0);
				}
	
				if (strcmp(m->getName(), "rgbLedRGB") == 0) {
								v[m->getObjectId()]->rgbLedRGB(m->getInt(0), m->getInt(1), m->getInt(2), m->getInt(3));
								m->returns(0);
				}


};
#endif


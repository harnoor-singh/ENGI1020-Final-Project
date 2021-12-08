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

#if USE_led_bar

#include <Arduino.h>
#include "led_bar.h"
#include "led_barClass.h"
#include <stdlib.h>

const char* nanpy::led_barClass::get_firmware_id()
{
	return "led_bar";
}

void nanpy::led_barClass::elaborate( nanpy::MethodDescriptor* m ) {
	ObjectsManager<led_bar>::elaborate(m);

	if (strcmp(m->getName(),"new") == 0) {
		led_bar * ds;
		ds = new led_bar();
    ds->barInit(m->getInt(0));
		v.insert(ds);
		m->returns(v.getLastIndex());
	}


	if (strcmp(m->getName(), "barInit") == 0) {
		v[m->getObjectId()]->barInit(m->getInt(0));
		m->returns(0);
	}
	
	if (strcmp(m->getName(), "barSetLevel") == 0) {
		v[m->getObjectId()]->barSetLevel(m->getFloat(0));
		m->returns(0);
	}

	if (strcmp(m->getName(), "barSetLed") == 0) {
		v[m->getObjectId()]->barSetLed(m->getInt(0), m->getFloat(1));
		m->returns(0);
	}


};
#endif


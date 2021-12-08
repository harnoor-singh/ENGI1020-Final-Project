/*
 * Copyright (c) 2018-2019 Jonathan Anderson
 * 		 2019	   Mahya Soleimani 
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

#include "ChainableLED.h"
#include "rgba_leds.h"
//#include "seeed-kit.h"

ChainableLED *ledChain;

rgba_leds::rgba_leds()
{
}

void rgba_leds::rgbLedInit(int digitalPin, int count)
{
	ledChain = new ChainableLED(digitalPin, digitalPin + 1, count);
}


void rgba_leds::rgbLedHSB(int led, float hue, float saturation, float brightness)
{
	if (ledChain)
	{
		ledChain->setColorHSB(led, hue, saturation, brightness);
	}
}


void rgba_leds::rgbLedRGB(int led, int red, int green, int blue)
{
	if (ledChain)
	{
		ledChain->setColorRGB(led, red, green, blue);
	}
}

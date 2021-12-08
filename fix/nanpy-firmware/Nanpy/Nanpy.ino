#include "cfg_all.h"

// external libraries should be put inside #if ... #endif
//    internal headers not.

#if USE_MCP41xxx
#include <MCP41xxx.h>
#endif

#if USE_EEPROM
#include <EEPROM.h>
#endif

#if USE_Servo
#include <Servo.h>
#endif

#if USE_LiquidCrystal
#include <LiquidCrystal.h>
#endif


#if USE_LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>
#endif


#if USE_Stepper
#include <Stepper.h>
#endif

#if USE_OneWire
#include <OneWire.h>
#endif

#if USE_DallasTemperature
#include <DallasTemperature.h>
#endif

#if USE_CapacitiveSensor
#include <CapacitiveSensor.h>
#endif

#if USE_DHT
#include <DHT.h>
#endif

#if USE_Wire
#include <Wire.h>
#endif

#if USE_TLC5947
#include <Adafruit_TLC5947.h>
#endif

// Grove components
#if USE_rgb_lcd
#include "rgb_lcd.h"
#endif

// To support speaker (basic digital support)
#if USE_digital_support
#include "digital_support.h"
#endif

// To support ultrasonic_distance
#if USE_ultrasonic_distance
#include "ultrasonic_distance.h"
#endif 

// To support rgba_leds
#if USE_rgba_leds
#include "rgba_leds.h"
#endif

// To support led_bar
#if USE_led_bar
#include "led_bar.h"
#endif

// To support lcd_display
#if USE_lcd_display
#include "lcd_display.h"
#endif

#include "MCP41xxxClass.h"
#include "BaseClass.h"
#include "ArduinoClass.h"
#include "OneWireClass.h"
#include "StepperClass.h"
#include "ServoClass.h"
#include "DallasTemperatureClass.h"
#include "LiquidCrystalClass.h"
#include "LiquidCrystalClass_I2C.h"
#include "CapacitiveSensorClass.h"
#include "ToneClass.h"
#include "MethodDescriptor.h"
#include "ComChannel.h"
#include "EEPROMClass.h"
#include "RAMClass.h"
#include "DHTClass.h"

#include "DefineClass.h"
#include "ArduinoCoreClass.h"
#include "WatchdogClass.h"
#include "RegisterClass.h"
#include "CounterClass.h"
#include "InfoClass.h"
#include "WireClass.h"

#include "TLC5947Class.h"
#include "EspClass.h"
#include "UltrasonicClass.h"
#include "ColorSensorClass.h"

//Grove components
#include "rgb_lcdClass.h"

// To support digital devices
#include "digital_supportClass.h"

// To support ultrasonic_distance
#include "ultrasonic_distanceClass.h"

// To support rgba_leds
#include "rgba_ledsClass.h"

// To support led_bar
#include "led_barClass.h"
#include "Grove_LED_Bar.h"

// To support lcd_display
#include "lcd_displayClass.h"

using namespace nanpy;

MethodDescriptor *m = NULL;

void setup() {
    disable_watchdog_at_startup();
   
    REGISTER_CLASS(ArduinoClass);                                                   // 0.8 k
//
    REGISTER_CLASS_CONDITIONAL(MCP41xxxClass, USE_MCP41xxx);
    REGISTER_CLASS_CONDITIONAL(nanpy::EEPROMClass, USE_EEPROM);                     // 0.3 k
    REGISTER_CLASS_CONDITIONAL(nanpy::RAMClass, USE_RAM);                           // 
    REGISTER_CLASS_CONDITIONAL(LiquidCrystalClass, USE_LiquidCrystal);              //  2.3 k
    REGISTER_CLASS_CONDITIONAL(LiquidCrystalClass_I2C, USE_LiquidCrystal_I2C);
    REGISTER_CLASS_CONDITIONAL(OneWireClass, USE_OneWire);                          // 1.7 k
    REGISTER_CLASS_CONDITIONAL(DallasTemperatureClass, USE_DallasTemperature);      // 6.1 k
    REGISTER_CLASS_CONDITIONAL(StepperClass, USE_Stepper);                          // 0.8 k
    REGISTER_CLASS_CONDITIONAL(ServoClass, USE_Servo);                              // 2.5 k
    REGISTER_CLASS_CONDITIONAL(ToneClass, USE_Tone);                                // 2.2 k
    REGISTER_CLASS_CONDITIONAL(CapacitiveSensorClass, USE_CapacitiveSensor);        // 2.2 k
    REGISTER_CLASS_CONDITIONAL(DefineClass, USE_Define);                            // 0.6 k
    REGISTER_CLASS_CONDITIONAL(ArduinoCoreClass, USE_ArduinoCore);                  // 
    REGISTER_CLASS_CONDITIONAL(WatchdogClass, USE_Watchdog);                        // 0.2 k
    REGISTER_CLASS_CONDITIONAL(RegisterClass, USE_Register);                        // 1.5 k

    REGISTER_CLASS_CONDITIONAL(CounterClass, USE_Counter);                          // 
    REGISTER_CLASS_CONDITIONAL(InfoClass, USE_Info);                          // 
    REGISTER_CLASS_CONDITIONAL(DHTClass, USE_DHT);
    REGISTER_CLASS_CONDITIONAL(WireClass, USE_Wire);
    
    REGISTER_CLASS_CONDITIONAL(TLC5947Class, USE_TLC5947);

    REGISTER_CLASS_CONDITIONAL(nanpy::EspClass, USE_ESP);

    // GW Classes
    REGISTER_CLASS_CONDITIONAL(UltrasonicClass, USE_Ultrasonic);
    REGISTER_CLASS_CONDITIONAL(ColorSensorClass, USE_ColorSensor);
    
    //Grove components
    REGISTER_CLASS_CONDITIONAL(rgb_lcdClass, USE_rgb_lcd);
	
	// To support digital devices   
    REGISTER_CLASS_CONDITIONAL(digital_supportClass, USE_digital_support);
	
	// To support ultrasonic_distance  
    REGISTER_CLASS_CONDITIONAL(ultrasonic_distanceClass, USE_ultrasonic_distance);

	// To support rgba_leds
    REGISTER_CLASS_CONDITIONAL(rgba_ledsClass, USE_rgba_leds);
 
	// To support rgba_leds
    REGISTER_CLASS_CONDITIONAL(led_barClass, USE_led_bar);
	
	// To support lcd_display
    REGISTER_CLASS_CONDITIONAL(lcd_displayClass, USE_lcd_display);

    ComChannel::connect();
}

void loop() {
    if(ComChannel::available()) {
        m = new MethodDescriptor();
        Register::elaborate(m);
    }
}

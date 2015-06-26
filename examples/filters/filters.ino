//
// filters
//
// Description of the project
// Developed with [embedXcode](http://embedXcode.weebly.com)
//
// Author 		sqrtmo
// 				sqrtmo
//
// Date			5/6/15 15:03
// Version		1.0
//
// Copyright	© sqrtmo, 2015
// Licence		free
//
// See         ReadMe.txt for references
//


// Core library for code-sense - IDE-based
#include "Arduino.h"

// Include application, user and local libraries
#include "FIRFilters.h"

filters f;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    uint16_t sensor = analogRead(A0);
    sensor = f.clip( sensor, 126, 560 );
    
    sensor = f.EMA(sensor, 0.1);
    delay(10);
}

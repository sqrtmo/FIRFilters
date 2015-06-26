//
// File			LocalLibrary.h
// Brief		Library header
//
// Project	 	filters
// Developed with [embedXcode](http://embedXcode.weebly.com)
// 
// Author		sqrtmo
// 				sqrtmo
// Date			5/6/15 15:03
// Version		1.0
// 
// Copyright	© sqrtmo, 2015
// Licence		free
//
// See			ReadMe.txt for references
//

#include "Arduino.h"

#ifndef FIRFilters_h
#define FIRFilters_h

class filters
{
    
private:
    int emaPrev;
    
public:
    int EMA( int in, float alpha );
    int SMA( int in, uint8_t bufferSize );
    
    int clip( int16_t in, int16_t min, int16_t max );
};


#endif

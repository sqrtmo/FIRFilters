#include "Arduino.h"
#include "FIRFilters.h"

#define SMA_bufferSize (10)
#define MM_bufferSize  (10)

#define alpha (0.3)
//alpha mst be float between 0 and 1

int SMA_buffer[SMA_bufferSize];
int MM_buffer [MM_bufferSize];
//buffers must be in int!

filters<int> f;
//Create the object.
//You can use only one one filter of kind with this object.
//If need to handle with more than one sensors with the same kind of filter simultaneously.
//You need to create new objects for them.

void setup()
{
    Serial.begin(9600);
    delay(10);
}

void loop()
{
    uint16_t sensorProbe = analogRead(A0);
    
    uint16_t SMA_out = f.SMA( sensorProbe, SMA_buffer, SMA_bufferSize );
    uint16_t MM_out  = f.MM ( sensorProbe, SMA_buffer, SMA_bufferSize );
    uint16_t EMA_out = f.EMA( sensorProbe, alpha );
    uint16_t EMD_out = f.EMD( sensorProbe, alpha );
    
    Serial.print( "SMA out is " );
    Serial.print( SMA_out );
    Serial.print( ", " );
    
    Serial.print( "MM out is " );
    Serial.print( MM_out );
    Serial.println( ", " );
    
    Serial.print( "EMA out is " );
    Serial.print( EMA_out );
    Serial.print( ", " );

    Serial.print( "EMD out is " );
    Serial.println( EMD_out );

    delay(10);
}


#include "Arduino.h"

#ifndef FIRFilters_h
#define FIRFilters_h

int cmp( int *num1, int *num2 );

template< typename T >
class filters
{
    
private:
    int emaPrev;
    int y1Prev, y2Prev;
    
public:
    int EMA( T in, float alpha );
    int EMD( T in, float alpha );
    int SMA( T in, T buffer[], T bufferSize );
    int MM ( T in, T buffer[], T bufferSize );
        
    int clip( T in, T min, T max );
};
#endif


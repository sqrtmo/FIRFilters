#include "FIRFilters.h"

template< typename T >
int filters<T>::EMA( T in, float alpha )
{
    float S;
    S = alpha * in + ( 1 - alpha ) * emaPrev;
    emaPrev = S;
    delay(1);
    return S;
}
template< typename T >
int filters<T>::EMD( T in, float alpha )
{
    float y1, y2;
    
    y2 = alpha * in + ( 1 - alpha ) * y2Prev;
    y2Prev = y2;
    
    y1 = alpha * abs(in-y2) + ( 1 - alpha ) * y1Prev;
    y1Prev = y1;

    return y1;
}

template< typename T >
int filters<T>::SMA( T in, T buffer[], T bufferSize )
{
    static int readIndex = 0;
    static int total = 0;
    static int average = 0;
    
    total -= buffer[readIndex];
    buffer[readIndex] = in;
    total += buffer[readIndex];
    readIndex += 1;
    
    if( readIndex >= bufferSize )readIndex = 0;
    
    average = total / bufferSize;
    return average;
}

//----------------moving median---------------------
template< typename T >
int filters<T>::MM ( T in, T buffer[], T bufferSize )
{
    static int readIndex = 0;
    static int total = 0;
    static int average = 0;
    
    total -= buffer[readIndex];
    buffer[readIndex] = in;
    total += buffer[readIndex];
    readIndex += 1;
    
    if( readIndex >= bufferSize )
    {
        readIndex = 0;
        qsort( buffer, bufferSize, sizeof(int), (int (*)(const void *, const void *)) cmp );
    }
    return buffer[bufferSize / 2];
}
int cmp( int *num1, int *num2 )
{
    if( *num1 < *num2 ) return -1;
    else if( *num1 == *num2 ) return 0;
    return 1;
}
//--------------------------------------------------

template< typename T >
int filters<T>::clip( T in, T min, T max )
{
    if( in < min || in > max )return 0;
    else return in;
}

template class filters<int>;
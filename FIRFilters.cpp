//
// LocalLibrary.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode 
// http://embedXcode.weebly.com
//
// Project 		filters
//
// Created by 	sqrtmo, 5/6/15 15:03
// 				sqrtmo
//	
// Copyright 	© sqrtmo, 2015
// Licence 		free
//
// See 			ReadMe.txt for references
//

#include "FIRFilters.h"

int filters::EMA( int in, float alpha )
{
    float S;
    S = alpha * in + ( 1 - alpha ) * emaPrev;
    emaPrev = S;
    return S;
}

int filters::SMA( int in, uint8_t bufferSize )
{
    //TODO
    return 0;
}

int filters::clip( int16_t in, int16_t min, int16_t max )
{
    if( in < min || in > max )
    {
        return 0;
        } else {
        return in;
    }

}
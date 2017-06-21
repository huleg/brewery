/*
 * Andy's Workshop Brewery Relays controller ATMega328p firmware
 * Copyright (c) 2017 Andy Brown. http://www.andybrown.me.uk
 * Please see website for licensing terms.
 */

#include "Application.h"


// static variable setup

namespace brewery {
 volatile uint8_t TriacControl::_percentage=0;
 volatile uint8_t TriacControl::_counter=0;
}


/*
 * Zero crossing interrupt handler
 */

ISR(INT0_vect) {
  brewery::TriacControl::zeroCrossingHandler();
}


/*
 * Timer2 comparison value A matched
 */

ISR(TIMER2_COMPA_vect) {
  brewery::TriacControl::timerComparatorHandler();
}


/*
 * Timer2 overflow handler
 */

ISR(TIMER2_OVF_vect) {
  brewery::TriacControl::timerOverflowHandler();
}


/*
 * Lookup table for mapping desired output power percentage to linear percentage
 * distance along the half-cycle. See spreadsheet in the doc/ directory for
 * further information.
 */

const PROGMEM uint8_t brewery::TriacControl::LookupTable[99]={
  // 0      // zero isn't required (oven is off at zero)
  6,        // 1%
  9,        // 2% etc...
  11,
  13,
  14,
  16,
  17,
  18,
  19,
  21,
  22,
  23,
  23,
  24,
  26,
  26,
  27,
  28,
  29,
  29,
  31,
  31,
  32,
  33,
  33,
  34,
  35,
  36,
  36,
  37,
  38,
  38,
  39,
  39,
  41,
  41,
  42,
  42,
  43,
  43,
  44,
  45,
  46,
  46,
  47,
  47,
  48,
  49,
  49,
  50,
  51,
  51,
  52,
  53,
  53,
  54,
  54,
  55,
  56,
  57,
  57,
  58,
  58,
  59,
  59,
  61,
  61,
  62,
  62,
  63,
  64,
  64,
  65,
  66,
  67,
  67,
  68,
  69,
  69,
  71,
  71,
  72,
  73,
  74,
  74,
  76,
  77,
  77,
  78,
  79,
  81,
  82,
  83,
  84,
  86,
  87,
  89,
  91,      // 98%
  94       // 99%   
//  100    // 100% is not required (oven fully on)
};

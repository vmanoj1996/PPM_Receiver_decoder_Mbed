#pragma once
#include "mbed.h"

class ppm_receiver_8ch
{
public:
  //USE ONLY VOLATILE TYPE FOR ISR handling to avoid compiler optimizations
  volatile int marker = 7;       // Marks the Interrupted Pin
  volatile int input_signal[8] = {0}; //Pulse width in MicroS
  Timer mbd_timer;
  InterruptIn rx_interrupt;
  ppm_receiver_8ch(PinName RX_interrupt_pin); //setup
  void receiverISR(); //Interrupt service routine to calculate the PWidths

};

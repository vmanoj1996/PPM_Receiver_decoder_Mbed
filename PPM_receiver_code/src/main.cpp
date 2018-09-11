#include "mbed.h"
#include "receiver.h"
//Only external interrupt pins are supported!
ppm_receiver_8ch rx(PC_4);
Serial pc(USBTX,USBRX);
void print_RX();

int  main()
{
  pc.baud(57600);
  while(1){
            print_RX();
            wait(0.05);
          }
}

void print_RX(){
  for(int i=0;i<=7;i++){
    pc.printf("%d ",rx.input_signal[i]);
  }
  pc.printf("\n");
}


/////////////////////////configured from original midi controller v1.2///notesandvolts.com///////
///midiklone v1 - 32 x potentiometers************klonecom-electronics******///


#include <MIDI.h>
#include "Controller.h"



MIDI_CREATE_DEFAULT_INSTANCE();


byte NUMBER_MUX_POTS = 32;
Mux M1(A0, 16, true);
Mux M2(A5, 16, true); 

Pot MPO1(M1, 0, 0, 110, 1);
Pot MPO2(M1, 1, 0, 21, 1);
Pot MPO3(M1, 2, 0, 22, 1);
Pot MPO4(M1, 3, 0, 115, 1);
Pot MPO5(M1, 4, 0, 24, 1);
Pot MPO6(M1, 5, 0, 25, 1);
Pot MPO7(M1, 6, 0, 117, 1);
Pot MPO8(M1, 7, 0, 103, 1);
Pot MPO9(M1, 8, 0, 28, 1);
Pot MPO10(M1, 9, 0, 29, 1);
Pot MPO11(M1, 10, 0, 30, 1);
Pot MPO12(M1, 11, 0, 112, 1);
Pot MPO13(M1, 12, 0, 118, 1);
Pot MPO14(M1, 13, 0, 86, 1);
Pot MPO15(M1, 14, 0, 87, 1);
Pot MPO16(M1, 15, 0, 88, 1);

Pot MPO17(M2, 0, 0, 110, 1);
Pot MPO18(M2, 1, 0, 21, 1);
Pot MPO19(M2, 2, 0, 22, 1);
Pot MPO20(M2, 3, 0, 115, 1);
Pot MPO21(M2, 4, 0, 24, 1);
Pot MPO22(M2, 5, 0, 25, 1);
Pot MPO23(M2, 6, 0, 117, 1);
Pot MPO24(M2, 7, 0, 103, 1);
Pot MPO25(M2, 8, 0, 28, 1);
Pot MPO26(M2, 9, 0, 29, 1);
Pot MPO27(M2, 10, 0, 30, 1);
Pot MPO28(M2, 11, 0, 112, 1);
Pot MPO29(M2, 12, 0, 118, 1);
Pot MPO30(M2, 13, 0, 86, 1);
Pot MPO31(M2, 14, 0, 87, 1);
Pot MPO32(M2, 15, 0, 88, 1);

Pot *MUXPOTS[] {&MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6, &MPO7, &MPO8, &MPO9, &MPO10, &MPO11, &MPO12, &MPO13, &MPO14, &MPO15, &MPO16, &MPO17, &MPO18, &MPO19, &MPO20, &MPO21, &MPO22, &MPO23, &MPO24, &MPO25, &MPO26, &MPO27, &MPO28, &MPO29, &MPO30, &MPO31, &MPO32 };


void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {

  if (NUMBER_MUX_POTS != 0) updateMuxPots();
}



void updateMuxPots() {
  for (int i = 0; i < NUMBER_MUX_POTS; i = i + 1) {
    MUXPOTS[i]->muxUpdate();
    byte potmessage = MUXPOTS[i]->getValue();
    if (potmessage != 255) MIDI.sendControlChange(MUXPOTS[i]->Pcontrol, potmessage, MUXPOTS[i]->Pchannel);
  }
}

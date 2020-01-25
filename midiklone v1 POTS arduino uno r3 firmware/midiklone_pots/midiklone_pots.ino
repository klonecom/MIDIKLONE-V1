
/////////////////////////configured from original midi controller v1.2///notesandvolts.com///////
///midiklone v1 - 16 x potentiometers************klonecom-electronics******///


#include <MIDI.h>
#include "Controller.h"



MIDI_CREATE_DEFAULT_INSTANCE();


byte NUMBER_MUX_POTS = 16;

Mux M2(A5, 16, true); 



Pot MPO1(M2, 0, 0, 110, 1);
Pot MPO2(M2, 1, 0, 21, 1);
Pot MPO3(M2, 2, 0, 22, 1);
Pot MPO4(M2, 3, 0, 115, 1);
Pot MPO5(M2, 4, 0, 24, 1);
Pot MPO6(M2, 5, 0, 25, 1);
Pot MPO7(M2, 6, 0, 117, 1);
Pot MPO8(M2, 7, 0, 103, 1);
Pot MPO9(M2, 8, 0, 28, 1);
Pot MPO10(M2, 9, 0, 29, 1);
Pot MPO11(M2, 10, 0, 30, 1);
Pot MPO12(M2, 11, 0, 112, 1);
Pot MPO13(M2, 12, 0, 118, 1);
Pot MPO14(M2, 13, 0, 86, 1);
Pot MPO15(M2, 14, 0, 87, 1);
Pot MPO16(M2, 15, 0, 88, 1);

Pot *MUXPOTS[] {&MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6, &MPO7, &MPO8, &MPO9, &MPO10, &MPO11, &MPO12, &MPO13, &MPO14, &MPO15, &MPO16, };


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

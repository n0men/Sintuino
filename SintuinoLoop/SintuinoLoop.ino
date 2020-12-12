#include "NotesTable.h"
#include "Sintuino.h"
#include "Volume3.h"
#include <NewPing.h>

NewPing pitch(TRIGGER_PIN_PITCH,ECHO_PIN_PITCH,MAX_DISTANCE);
NewPing shift(TRIGGER_PIN_SHIFT,ECHO_PIN_SHIFT,MAX_DISTANCE);
int volume;
int tune;
int *octave;
Volume wave;


void setup() {
  pinMode(WAVE_PIN, OUTPUT);
  pinMode(VOLUME_PIN,INPUT);
  pinMode(OCTAVE_PIN,INPUT);
  pinMode(TREMOLO_PIN,INPUT);
  pinMode(SHIFT_PIN,INPUT);
}

void loop() {
  frequency = pitch.ping_cm();
  
  // put your main code here, to run repeatedly:

}

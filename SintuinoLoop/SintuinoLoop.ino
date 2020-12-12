#include <NewPing.h>
#include <TimerOne.h>
#include <Volume3.h>
#include "NotesTable.h"
#include "Sintuino.h"

#define TRIGGER_PIN_SHIFT 9
#define ECHO_PIN_SHIFT 10
#define TRIGGER_PIN_PITCH 11
#define ECHO_PIN_PITCH 12
#define MAX_DISTANCE 60
#define VOLUME_PIN A0
#define OCTAVE_PIN A1
#define TREMOLO_PIN 8
#define T_RATE_PIN A2
#define SHIFT_PIN A3
#define WAVE_PIN 9

; //idk, without it won't compile
int max_volume;
int volume;
NewPing pitch(TRIGGER_PIN_PITCH,ECHO_PIN_PITCH,MAX_DISTANCE);
NewPing shift(TRIGGER_PIN_SHIFT,ECHO_PIN_SHIFT,MAX_DISTANCE);
int octave;
int tune;
int tremolo_rate;
bool tremolo_desc;
bool tremolo;


void setup() {
  pinMode(WAVE_PIN, OUTPUT);
  pinMode(VOLUME_PIN,INPUT);
  pinMode(OCTAVE_PIN,INPUT);
  pinMode(T_RATE_PIN,INPUT);
  pinMode(TREMOLO_PIN,INPUT);
  pinMode(SHIFT_PIN,INPUT);
}

void loop() {
  tune = pitch.ping_cm()/5; //calcola nota
  //se la nota è suonabile
  if(tune < 13) {
    max_volume = analogRead(VOLUME_PIN); //legge volume massimo
    octave = analogRead(OCTAVE_PIN); //legge l'ottava
  
    vol.tone(WAVE_PIN,notes[octave][tune],volume); //suona la nota
    //se il tremolo è attivo
    if(tremolo) {
      // se il tremolo è in fase di discesa
      if(tremolo_desc) {
        volume -= 1;
      }
      //se il tremolo è in fase di salita
     else {
        volume += 1;
      }
      
      if(volume == 0) {
        tremolo_desc == false;
      }
      if(volume == max_volume) {
        tremolo_desc == true;
      }
      //ogni quanto deve agire il tremolo
      delay(tremolo_rate);
    }
  }
  else {
    vol.noTone();
  }

  //pensare primo settaggio volume

}

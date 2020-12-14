// librerie
#include <NewPing.h>
#include <TimerOne.h>
#include <Volume3.h>
#include "NotesTable.h"
//#include "Sintuino.h"

// definizioni
#define TREMOLO_PIN 2
#define TRIGGER_PIN_SHIFT 7
#define ECHO_PIN_SHIFT 8
#define WAVE_PIN 9
#define TRIGGER_PIN_PITCH 11
#define ECHO_PIN_PITCH 12
#define VOLUME_PIN A0
#define OCTAVE_PIN A1
#define T_RATE_PIN A2
#define MAX_DISTANCE 60
#define MAX_SHIFT_DISTANCE 20

// variabili globali
int volume;
NewPing pitch(TRIGGER_PIN_PITCH,ECHO_PIN_PITCH,MAX_DISTANCE);
NewPing shift(TRIGGER_PIN_SHIFT,ECHO_PIN_SHIFT,MAX_SHIFT_DISTANCE);
int octave;
int note;
int tremolo;


void setup() {
  Serial.begin(115200);
  pinMode(WAVE_PIN, OUTPUT);
  pinMode(VOLUME_PIN,INPUT);
  pinMode(OCTAVE_PIN,INPUT);
  pinMode(T_RATE_PIN,INPUT);
  pinMode(TREMOLO_PIN,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(TREMOLO_PIN),set_tremolo,LOW);
  
}

void loop() {
  int note = (pitch.ping_cm()+4)/5; //calcola nota
  
  //se la nota è suonabile
  if(note) {
    volume = analogRead(VOLUME_PIN); //legge volume
    octave = analogRead(OCTAVE_PIN)/204; //legge l'ottava

    play_note();
 
    if(tremolo) {
       tremolo_effect();
    }
    
  }
  else {
    vol.noTone(); //fa smettere di suonare la nota
  }

}


//corpo funzioni
void set_tremolo() {
  tremolo = 1 - tremolo;
}

void tremolo_effect() {
  int tremolo_rate = analogRead(T_RATE_PIN)/10+10; //legge tremolo rate
  delay(tremolo_rate);
  vol.noTone();
  delay(tremolo_rate);
  }

void play_note() {
  int shift_amount = shift.ping_cm();
  
  if(shift_amount) {
    shift_amount = octave*(4 - shift_amount/2);
  }
    
  vol.tone(WAVE_PIN,notes[octave][note] + shift_amount,volume);
}

//Aggiungere interrupt per controllo volume

// librerie
#include <NewPing.h>
#include <TimerOne.h>
#include <Volume3.h>
#include "NotesTable.h"
#include "Sintuino.h"

// pins
#define TRIGGER_PIN_SHIFT 7
#define ECHO_PIN_SHIFT 8
#define TRIGGER_PIN_PITCH 11
#define ECHO_PIN_PITCH 12
#define MAX_DISTANCE 60
#define VOLUME_PIN A0
#define OCTAVE_PIN A1
#define TREMOLO_PIN 3
#define T_RATE_PIN A2
#define SHIFT_PIN A3
#define WAVE_PIN 9

; //idk, without it won't compile
// variabili globali
int max_volume;
int volume;
NewPing pitch(TRIGGER_PIN_PITCH,ECHO_PIN_PITCH,MAX_DISTANCE);
NewPing shift(TRIGGER_PIN_SHIFT,ECHO_PIN_SHIFT,MAX_DISTANCE);
int octave;
int distance;
int tremolo_rate;
bool tremolo_desc;
bool tremolo;


void setup() {
  Serial.begin(115200);
  pinMode(WAVE_PIN, OUTPUT);
  pinMode(VOLUME_PIN,INPUT);
  pinMode(OCTAVE_PIN,INPUT);
  pinMode(T_RATE_PIN,INPUT);
  pinMode(TREMOLO_PIN,INPUT);
  pinMode(SHIFT_PIN,INPUT);
}

void loop() {
  distance = pitch.ping_cm(); //calcola nota
  //Serial.println(distance);
  //se la nota è suonabile
  if(distance) {
    max_volume = analogRead(VOLUME_PIN); //legge volume massimo
    octave = analogRead(OCTAVE_PIN); //legge l'ottava
 
    //se il tremolo è attivo
    tremolo = digitalRead(2); //leggi se è attivo
    if(tremolo) {
      // se il tremolo è in fase di discesa
      if(volume >= max_volume) {
        volume -= 1;
      }
      //se il tremolo è in fase di salita
      if(volume <= 0) {
        volume += 1;
      }
      
      /*if(volume <= 0) {
        tremolo_desc = false;
      }
      if(volume >= max_volume) {
        tremolo_desc = true;
      }*/
      //ogni quanto deve agire il tremolo
      delay(analogRead(A0));
    }
    // tremolo disattivato
    else  {
      volume = max_volume;
    }
    Serial.println(volume);

    vol.tone(WAVE_PIN,notes[octave/204][distance/5],volume); //suona la nota
  }
  else {
    
    vol.noTone(); //fa smettere di suonare la nota
  }

}

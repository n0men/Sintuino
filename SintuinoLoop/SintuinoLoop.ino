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
#define T_RATE_PIN A2
#define SHIFT_PIN A3
#define TREMOLO_PIN 2
#define WAVE_PIN 9

// variabili globali
int max_volume;
int volume;
NewPing pitch(TRIGGER_PIN_PITCH,ECHO_PIN_PITCH,MAX_DISTANCE);
NewPing shift(TRIGGER_PIN_SHIFT,ECHO_PIN_SHIFT,20);
int shift_amount;
int octave;
int note;
long int tremolo_rate;
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
  note = (pitch.ping_cm()+4)/5; //calcola nota
  //Serial.println(distance);
  //se la nota è suonabile
  if(note) {
    max_volume = analogRead(VOLUME_PIN); //legge volume massimo
    octave = analogRead(OCTAVE_PIN)/204; //legge l'ottava
 
    //se il tremolo è attivo
    tremolo = digitalRead(TREMOLO_PIN); //leggi se è attivo
    if(tremolo) {
       tremolo_rate = analogRead(T_RATE_PIN)/10+10; //legge tremolo rate
 
      // se il tremolo è in fase di discesa
      /*if(tremolo_desc) {
        volume -= max_volume/26;
      }
      
      //se il tremolo è in fase di salita
      if(!tremolo_desc) {
        volume += max_volume/26;
      }
      
      if(volume <= 0) {
        tremolo_desc = false;
      }
      
      if(volume >= max_volumùe) {
        tremolo_desc = true;
      }*/
      //ogni quanto deve agire il tremolo
      delay(tremolo_rate);
      vol.noTone();
      delay(tremolo_rate);
      Serial.println("si");
    }
    // tremolo disattivato
    else  {
      volume = max_volume;
    }
    
    //Serial.println(tremolo_rate);
    //Serial.println(max_volume);

    shift_amount = shift.ping_cm();
    if(shift_amount) {
      shift_amount = octave*(4 - shift_amount/2);
    }
    Serial.println(shift_amount);

    vol.tone(WAVE_PIN,notes[octave][note] + shift_amount,max_volume); //suona la nota
  }
  else {
    
    vol.noTone(); //fa smettere di suonare la nota
  }

}

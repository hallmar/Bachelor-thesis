#include "settings.h"
#include "variables.h"


void handleMIDIon(byte channel, byte note, byte velocity)
{
  Serial.println(String("Note On:  ch=") + channel + ", note=" + note + ", velocity=" + velocity);

  if (channel == (midichannel))
  {
    usbMIDI.sendNoteOn(note, velocity, channel);
    noteON(note);
  }
}

void handleMIDIoff(byte channel, byte note, byte velocity)
{

  if (channel == (midichannel))
  {
    Serial.println(String("Note off:  ch=") + channel + ", note=" + note + ", velocity=" + velocity);
    noteOFF(note);
  }
}

void pitchbend(byte channel, int bend)
{
  float bended;
  if (bend >= 0)
  {
    bended = (float)bend / 8191;
    pbend = 1 + bended;
  }
  if (bend < 0)
  {
    bended = (float)bend / 8192;
    pbend = 1 + 0.5 * bended;
  }


  if (channel == (midichannel))
  {
    Serial.println(String("Bend:") + bend);
    Serial.println(String("Bended:") + pbend);
    AudioNoInterrupts();

    AudioInterrupts();
  }
} //pitchbend ends

void controlchange(byte channel, byte number, byte value)
{

}

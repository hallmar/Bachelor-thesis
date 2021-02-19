#include "settings.h"
#include "variables.h"


float midi_notes[127] = { 8.66196	, 9.17702	, 9.72272	, 10.30086	, 10.91338	, 11.56233	, 12.24986
                          , 12.97827	, 13.75000	, 14.56762	, 15.43385	, 16.35160	, 17.32391	, 18.35405	, 19.44544
                          , 20.60172	, 21.82676	, 23.12465	, 24.49971	, 25.95654	, 27.50000	, 29.13524	, 30.86771
                          , 32.70320	, 34.64783	, 36.70810	, 38.89087	, 41.20344	, 43.65353	, 46.24930	, 48.99943
                          , 51.91309	, 55.00000	, 58.27047	, 61.73541	, 65.40639	, 69.29566	, 73.41619	, 77.78175
                          , 82.40689	, 87.30706	, 92.49861	, 97.99886	, 103.82617	, 110.00000	, 116.54094	, 123.47083
                          , 130.81278	, 138.59132	, 146.83238	, 155.56349	, 164.81378	, 174.61412	, 184.99721	, 195.99772
                          , 207.65235	, 220.00000	, 233.08188	, 246.94165	, 261.62557	, 277.18263	, 293.66477	, 311.12698
                          , 329.62756	, 349.22823	, 369.99442	, 391.99544	, 415.30470	, 440.00000	, 466.16376	, 493.88330
                          , 523.25113	, 554.36526	, 587.32954	, 622.25397	, 659.25511	, 698.45646	, 739.98885	, 783.99087
                          , 830.60940	, 880.00000	, 932.32752	, 987.76660	, 1046.50226	, 1108.73052	, 1174.65907	, 1244.50793
                          , 1318.51023	, 1396.91293	, 1479.97769	, 1567.98174	, 1661.21879	, 1760.00000	, 1864.65505	, 1975.53321
                          , 2093.00452	, 2217.46105	, 2349.31814	, 2489.01587	, 2637.02046	, 2793.82585	, 2959.95538	, 3135.96349
                          , 3322.43758	, 3520.00000	, 3729.31009	, 3951.06641	, 4186.00904	, 4434.92210	, 4698.63629	, 4978.03174
                          , 5274.04091	, 5587.65170	, 5919.91076	, 6271.92698	, 6644.87516	, 7040.00000	, 7458.62018	, 7902.13282
                          , 8372.01809	, 8869.84419	, 9397.27257	, 9956.06348	, 10548.08182	, 11175.30341	, 11839.82153	, 12543.85395
                        };


void noteOFF(byte note)
{
  menu_redraw_required = 1;
  if (gate_out && (gate_out_n == note))
  {
    gate_out = 0;
    digitalWrite(gate, HIGH);
    digitalWrite(gateled, LOW);
    Serial.println(String("Gate = ") + gate_out);
  }

  if ((voicetrig[0] == 1) && (note == voicenote[0]))
  {
    AudioNoInterrupts();
    envelope1.noteOff();
    op2env1.noteOff();
    op3env1.noteOff();
    AudioInterrupts();
    voicetrig[0] = 0;
  }
  if ((voicetrig[1] == 1) && (note == voicenote[1]))
  {
    AudioNoInterrupts();
    envelope2.noteOff();
    op2env2.noteOff();
    op3env2.noteOff();
    AudioInterrupts();
    voicetrig[1] = 0;
  }
  if ((voicetrig[2] == 1) && (note == voicenote[2]))
  {
    AudioNoInterrupts();
    envelope3.noteOff();
    op2env3.noteOff();
    op3env3.noteOff();
    AudioInterrupts();
    voicetrig[2] = 0;
  }
  if ((voicetrig[3] == 1) && (note == voicenote[3]))
  {
    AudioNoInterrupts();
    envelope4.noteOff();
    op2env4.noteOff();
    op3env4.noteOff();
    AudioInterrupts();
    voicetrig[3] = 0;
  }
}


void noteON(byte note)
{
  float freq_note = midi_notes[note - 1] * pbend;
  uint8_t temp;
  menu_redraw_required = 1;
  if (!gate_out)
  {
    gate_out = 1;
    digitalWrite(gate, LOW);
    digitalWrite(gateled, HIGH);
    gate_out_n = note;
    //Serial.println(String("Gate = ") + gate_out);
  }

  if (voicehist[0] == 1 && !voicetrig[0])
  {
    voicenote[0] = note;
    voicetrig[0] = 1;
    //shift voicehistory by 1 to the left
    temp = voicehist[3];
    voicehist[3] = voicehist[2];
    voicehist[2] = voicehist[1];
    voicehist[1] = voicehist[0];
    voicehist[0] = temp;

    AudioNoInterrupts();
    voicefreq[0] = freq_note;
    envelope1.noteOn();
    op2env1.noteOn();
    op3env1.noteOn();
    pwm1.frequency(freq_note * 0.5 + pwmdetune);
    wave1.frequency(freq_note * (waveoct) + wavedetune);
    op1v1.frequency(freq_note);
    op2v1.frequency(freq_note * op2_ratio);
    op3v1.frequency(freq_note * op3_ratio);
    AudioInterrupts();
    return;
  }

  if (voicehist[0] == 2 && !voicetrig[1])
  {
    voicenote[1] = note;
    voicetrig[1] = 1;
    //shift voicehistory by 1 to the left
    temp = voicehist[3];
    voicehist[3] = voicehist[2];
    voicehist[2] = voicehist[1];
    voicehist[1] = voicehist[0];
    voicehist[0] = temp;
    AudioNoInterrupts();
    voicefreq[1] = freq_note;
    envelope2.noteOn();
    op2env2.noteOn();
    op3env2.noteOn();
    pwm2.frequency(freq_note * 0.5 + pwmdetune);
    wave2.frequency(freq_note * (waveoct) + wavedetune);
    op1v2.frequency(freq_note);
    op2v2.frequency(freq_note * op2_ratio);
    op3v2.frequency(freq_note * op3_ratio);
    AudioInterrupts();
    return;

  }

  if (voicehist[0] == 3  && !voicetrig[2])
  {
    voicenote[2] = note;
    voicetrig[2] = 1;
    //shift voicehistory by 1 to the left
    temp = voicehist[3];
    voicehist[3] = voicehist[2];
    voicehist[2] = voicehist[1];
    voicehist[1] = voicehist[0];
    voicehist[0] = temp;
    AudioNoInterrupts();
    voicefreq[2] = freq_note;
    envelope3.noteOn();
    op2env3.noteOn();
    op3env3.noteOn();
    pwm3.frequency(freq_note * 0.5 + pwmdetune);
    wave3.frequency(freq_note * (waveoct) + wavedetune);
    op1v3.frequency(freq_note);
    op2v3.frequency(freq_note * op2_ratio);
    op3v3.frequency(freq_note * op3_ratio);
    AudioInterrupts();
    return;


  }

  if (voicehist[0] == 4  && !voicetrig[3])
  {
    voicenote[3] = note;
    voicetrig[3] = 1;
    //shift voicehistory by 1 to the left
    temp = voicehist[3];
    voicehist[3] = voicehist[2];
    voicehist[2] = voicehist[1];
    voicehist[1] = voicehist[0];
    voicehist[0] = temp;
    AudioNoInterrupts();
    voicefreq[3] = freq_note;
    envelope4.noteOn();
    op2env4.noteOn();
    op3env4.noteOn();
    pwm4.frequency(freq_note * 0.5 + pwmdetune);
    wave4.frequency(freq_note * (waveoct) + wavedetune);
    op1v4.frequency(freq_note);
    op2v4.frequency(freq_note * op2_ratio);
    op3v4.frequency(freq_note * op3_ratio);
    AudioInterrupts();
    return;

  }

}

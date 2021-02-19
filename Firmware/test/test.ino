#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce2.h>
#include <ResponsiveAnalogRead.h>

// GUItool: begin automatically generated code
AudioSynthWaveformModulated modulator21;    //xy=243,223
AudioSynthWaveformModulated modulator12;    //xy=419,386
AudioSynthWaveformModulated modulator22;    //xy=422,309
AudioSynthWaveformModulated modulator11;    //xy=428,220
AudioMixer4              mixer1;         //xy=572,339
AudioSynthWaveform       lfo;      //xy=615,499
AudioSynthWaveformModulated carrier1;       //xy=641,212
AudioSynthWaveformModulated carrier2;       //xy=709,331
AudioAnalyzePeak         peak1;          //xy=789,497
AudioFilterStateVariable filter1;        //xy=883,248
AudioFilterStateVariable filter2;        //xy=884,347
AudioOutputI2S           i2s1;           //xy=1078,293
AudioConnection          patchCord1(modulator21, 0, modulator11, 0);
AudioConnection          patchCord2(modulator12, 0, mixer1, 1);
AudioConnection          patchCord3(modulator22, 0, mixer1, 0);
AudioConnection          patchCord4(modulator11, 0, carrier1, 0);
AudioConnection          patchCord5(mixer1, 0, carrier2, 0);
AudioConnection          patchCord6(lfo, peak1);
AudioConnection          patchCord7(carrier1, 0, filter1, 0);
AudioConnection          patchCord8(carrier2, 0, filter2, 0);
AudioConnection          patchCord9(filter1, 0, i2s1, 0);
AudioConnection          patchCord10(filter2, 0, i2s1, 1);
// GUItool: end automatically generated code


Bounce pushbutton = Bounce();



ResponsiveAnalogRead ctl2(A10, true);
ResponsiveAnalogRead modi1(A8, true);
ResponsiveAnalogRead modi2(A5, true);
ResponsiveAnalogRead fm1(A4, true);
ResponsiveAnalogRead fm2(A3, true);
ResponsiveAnalogRead decay(A2, true);
ResponsiveAnalogRead attack(A1, true);
ResponsiveAnalogRead ctl1(A0, true);

const float midi_notes[127] = { 8.66196  , 9.17702  , 9.72272  , 10.30086 , 10.91338 , 11.56233 , 12.24986
                                , 12.97827 , 13.75000 , 14.56762 , 15.43385 , 16.35160 , 17.32391 , 18.35405 , 19.44544
                                , 20.60172 , 21.82676 , 23.12465 , 24.49971 , 25.95654 , 27.50000 , 29.13524 , 30.86771
                                , 32.70320 , 34.64783 , 36.70810 , 38.89087 , 41.20344 , 43.65353 , 46.24930 , 48.99943
                                , 51.91309 , 55.00000 , 58.27047 , 61.73541 , 65.40639 , 69.29566 , 73.41619 , 77.78175
                                , 82.40689 , 87.30706 , 92.49861 , 97.99886 , 103.82617  , 110.00000  , 116.54094  , 123.47083
                                , 130.81278  , 138.59132  , 146.83238  , 155.56349  , 164.81378  , 174.61412  , 184.99721  , 195.99772
                                , 207.65235  , 220.00000  , 233.08188  , 246.94165  , 261.62557  , 277.18263  , 293.66477  , 311.12698
                                , 329.62756  , 349.22823  , 369.99442  , 391.99544  , 415.30470  , 440.00000  , 466.16376  , 493.88330
                                , 523.25113  , 554.36526  , 587.32954  , 622.25397  , 659.25511  , 698.45646  , 739.98885  , 783.99087
                                , 830.60940  , 880.00000  , 932.32752  , 987.76660  , 1046.50226 , 1108.73052 , 1174.65907 , 1244.50793
                                , 1318.51023 , 1396.91293 , 1479.97769 , 1567.98174 , 1661.21879 , 1760.00000 , 1864.65505 , 1975.53321
                                , 2093.00452 , 2217.46105 , 2349.31814 , 2489.01587 , 2637.02046 , 2793.82585 , 2959.95538 , 3135.96349
                                , 3322.43758 , 3520.00000 , 3729.31009 , 3951.06641 , 4186.00904 , 4434.92210 , 4698.63629 , 4978.03174
                                , 5274.04091 , 5587.65170 , 5919.91076 , 6271.92698 , 6644.87516 , 7040.00000 , 7458.62018 , 7902.13282
                                , 8372.01809 , 8869.84419 , 9397.27257 , 9956.06348 , 10548.08182  , 11175.30341  , 11839.82153  , 12543.85395
                              };

const uint8_t ratioindexnumber = 17;
const float ratioindex[18] = { 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7,7.5,8,8.5,9};


const short ADCRes = 4096;
const short ADCbit = 11; //according to measurement theory the maximum readable bits are 11 bits because of quantization noise and other noise
const uint8_t activitythreshold = 40;
const uint8_t modactivitythreshold = 80;

float fm1_knob;
float fm2_knob;
float modi1_knob;
float modi2_knob;
float ctl1_knob;
float ctl2_knob;
float mod_index1;
float mod_index2;
const int phasemodamount = 180;
float freq;
int midi_note;
bool manual;
bool freqmanual;

float peak1read; 
float peak1readold; 
int cutoff;



void setup() {
  pinMode(13, OUTPUT);


  analogReadResolution(ADCbit);

  fm1.setAnalogResolution(ADCRes);
  fm2.setAnalogResolution(ADCRes);
  modi1.setAnalogResolution(ADCRes);
  modi2.setAnalogResolution(ADCRes);
  ctl1.setAnalogResolution(ADCRes);
  ctl2.setAnalogResolution(ADCRes);


  fm1.setActivityThreshold(activitythreshold);
  fm2.setActivityThreshold(activitythreshold);
  modi1.setActivityThreshold(modactivitythreshold);
  modi2.setActivityThreshold(modactivitythreshold);
  ctl1.setActivityThreshold(activitythreshold);
  ctl2.setActivityThreshold(activitythreshold);


  fm1_knob = ADCRes - fm1.getValue();
  fm1_knob = (pow(fm1_knob, 2) / ADCRes); //mapping the linear scale of the pot to a logarithmic
  //Serial.println(String("fm value(no div):")+fm_knob);
  fm1_knob = (fm1_knob / ADCRes - (1 / ADCRes));

  fm2_knob = ADCRes - fm2.getValue();
  fm2_knob = (pow(fm2_knob, 2) / ADCRes); //mapping the linear scale of the pot to a logarithmic
  //Serial.println(String("fm value(no div):")+fm_knob);
  fm2_knob = (fm2_knob / ADCRes - (1 / ADCRes));

  modi1_knob = (1 - ((float)modi1.getValue() / ADCRes));
  modi2_knob = (1 - ((float)modi2.getValue() / ADCRes));
  ctl1_knob = (1 - ((float)ctl1.getValue() / ADCRes - (1 / ADCRes)));
  ctl2_knob = (1 - ((float)ctl2.getValue() / ADCRes - (1 / ADCRes)));

  midi_note = ctl1_knob * 127;
  freq = midi_notes[midi_note];


  mod_index1 = ratioindex[(int)(modi1_knob * ratioindexnumber)];
  mod_index2 = ratioindex[(int)(modi2_knob * ratioindexnumber)];

  manual = 0;
  freqmanual = 1;
  fm1_knob = 0;
  fm2_knob = 0;
  mod_index1 = 2;
  mod_index2 = 4;
  freq = midi_notes[60];

  fm1.enableEdgeSnap();
  fm2.enableEdgeSnap();
  modi1.enableEdgeSnap();
  modi2.enableEdgeSnap();
  ctl1.enableEdgeSnap();
  ctl2.enableEdgeSnap();

  pushbutton.attach(4, INPUT_PULLUP);
  Serial.begin(9600);

  AudioNoInterrupts();
  AudioMemory(80);
  carrier1.begin(0.8, freq, WAVEFORM_SINE);
  modulator11.begin(fm1_knob, freq * mod_index1, WAVEFORM_SINE);
  modulator21.begin(fm2_knob, freq * mod_index2, WAVEFORM_SINE);



  carrier2.begin(0.8, freq, WAVEFORM_SINE);
  modulator12.begin(fm1_knob, freq * mod_index1, WAVEFORM_SINE);
  modulator22.begin(fm2_knob, freq * mod_index2, WAVEFORM_SINE);

  lfo.begin(ctl1_knob, ctl2_knob+0.5, WAVEFORM_SINE);


  mixer1.gain(0, 1);
  mixer1.gain(1, 1);

  carrier1.frequencyModulation(0);
  carrier1.phaseModulation(phasemodamount);
  modulator11.frequencyModulation(0);
  modulator11.phaseModulation(phasemodamount);
  modulator21.frequencyModulation(0);
  modulator21.phaseModulation(phasemodamount);
  carrier2.frequencyModulation(0);
  carrier2.phaseModulation(phasemodamount);
  modulator12.frequencyModulation(0);
  modulator12.phaseModulation(phasemodamount);
  modulator22.frequencyModulation(0);
  modulator22.phaseModulation(phasemodamount);


  filter1.frequency(15000);
  filter2.frequency(15000);


  AudioInterrupts();

}
bool on = 0;
void loop() {


  // put your main code here, to run repeatedly:
  fm1.update();
  if (fm1.hasChanged() == 1)
  {
    fm1_knob = ADCRes - fm1.getValue();
    //fm1_knob = (pow(fm1_knob, 2) / ADCRes); //mapping the linear scale of the pot to a logarithmic
    //Serial.println(String("fm value(no div):")+fm_knob);
    fm1_knob = (fm1_knob / ADCRes - (1 / ADCRes));
    //Serial.println(fm1_knob);
    /*if(fm_knob <= 0.001)
      {fm_knob = 0;}*/

    AudioNoInterrupts();
    modulator11.amplitude(fm1_knob);
    modulator12.amplitude(fm1_knob);
    AudioInterrupts();
    Serial.println(String("FM: ") + fm1_knob );

  }


  fm2.update();
  if (fm2.hasChanged() == 1 && manual == 0)
  {
    fm2_knob = ADCRes - fm2.getValue();
    //fm2_knob = (pow(fm2_knob, 2) / ADCRes); //mapping the linear scale of the pot to a logarithmic
    //Serial.println(String("fm value(no div):")+fm_knob);
    fm2_knob = (fm2_knob / ADCRes - (1 / ADCRes));
    /*if(fm_knob <= 0.001)
      {fm_knob = 0;}*/

    AudioNoInterrupts();
    modulator21.amplitude(fm2_knob);
    modulator22.amplitude(fm2_knob);
    AudioInterrupts();

  }

  modi1.update();
  if (modi1.hasChanged() && manual == 0)
  {
    modi1_knob = (1 - ((float)modi1.getValue() / ADCRes - (1 / ADCRes)));
    Serial.println(String("modi1: ") + modi1_knob );

    mod_index1 = ratioindex[(int)(modi1_knob * ratioindexnumber)];
    Serial.println(String("mod index1: ") + mod_index1 );
    AudioNoInterrupts();
    modulator11.frequency(freq * mod_index1);
    modulator12.frequency(freq * mod_index1);
    AudioInterrupts();
  }
  //
  modi2.update();
  if (modi2.hasChanged() && manual == 0)
  {
    modi2_knob = (1 - ((float)modi2.getValue() / ADCRes - (1 / ADCRes)));

    mod_index2 = ratioindex[(int)(modi2_knob * ratioindexnumber)];
    AudioNoInterrupts();
    modulator21.frequency(freq * mod_index2);
    modulator22.frequency(freq * mod_index2);
    AudioInterrupts();
  }

  ctl1.update();
  if (ctl1.hasChanged() && freqmanual == 0)
  {
    ctl1_knob = (1 - ((float)ctl1.getValue() / ADCRes - (1 / ADCRes)));
    midi_note = ctl1_knob * 127;
    freq = midi_notes[midi_note-1];
    AudioNoInterrupts();
      carrier1.frequency(freq);
      carrier2.frequency(freq);
    AudioInterrupts();
  }


 
  
  ctl2.update();
  if (ctl2.hasChanged())
  {

    // ctl2_knob = ADCRes - ctl2.getValue();
    // ctl2_knob = (pow(ctl2_knob, 2) / ADCRes); //mapping the linear scale of the pot to a logarithmic
    //   //Serial.println(String("fm value(no div):")+fm_knob);
    // ctl2_knob = (ctl2_knob / ADCRes - (1 / ADCRes));

    ctl2_knob = (1 - ((float)ctl2.getValue() / ADCRes - (1 / ADCRes)));
    if(ctl2_knob <= 0.02)
      ctl2_knob = 0;
      
    AudioNoInterrupts();
    lfo.frequency(ctl2_knob+0.5);
    AudioInterrupts();
    Serial.println(String("Cutoff: ") + ctl2_knob );
  }
  

  pushbutton.update();
  if (pushbutton.fell())
  {
   
  }

   if (pushbutton.rose())
   {
    
  
   }


} //loop ends

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <ResponsiveAnalogRead.h>
#include <Bounce2.h>
#include <U8g2lib.h>
#include <Encoder.h>
#include <MIDI.h>
#include <USBHost_t36.h>
#include <EEPROM.h>

#include "settings.h"
#include "variables.h"




// #if defined(USBCON)
// #include <midi_UsbTransport.h>

// static const unsigned sUsbTransportBufferSize = 16;
// typedef midi::UsbTransport<sUsbTransportBufferSize> UsbTransport;

// UsbTransport sUsbTransport;

// MIDI_CREATE_INSTANCE(UsbTransport, sUsbTransport, MIDI);

// #else // No USB available, fallback to Serial
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
//#endif

//MIDI_CREATE_DEFAULT_INSTANCE();

USBHost myusb;
MIDIDevice midi1(myusb);

//U8GLIB_SSD1306_ADAFRUIT_128X64 u8g(13, 11, 10, 5, 4);
//U8GLIB_SSD1306_128X64 u8g (13, 11, 10, 5);

// GUItool: begin automatically generated code
AudioSynthWaveformModulated op3v3;          //xy=280.2500457763672,295.8214416503906
AudioSynthWaveformModulated op3v1;          //xy=281.25004959106445,199.0714292526245
AudioSynthWaveformModulated op3v2;          //xy=281.25004959106445,249.07143020629883
AudioSynthWaveformModulated op3v4;          //xy=283.2500457763672,348.8214416503906
AudioEffectEnvelope      op3env2;       //xy=400.50003814697266,249.32143020629883
AudioEffectEnvelope      op3env1;       //xy=401.00003814697266,197.8214282989502
AudioEffectEnvelope      op3env3;       //xy=401.2500305175781,296.8214416503906
AudioEffectEnvelope      op3env4;       //xy=402.2500305175781,348.8214416503906
AudioSynthWaveformModulated op2v4;           //xy=518.0000305175781,348.5714416503906
AudioSynthWaveformModulated op2v1;           //xy=520.2500381469727,198.5714292526245
AudioSynthWaveformModulated op2v3;           //xy=520.0000305175781,299.5714416503906
AudioSynthWaveformModulated op2v2;           //xy=521.5000381469727,251.32143020629883
AudioSynthWaveformDc     dc1;            //xy=605,453
AudioEffectEnvelope      op2env4;        //xy=635.0000610351562,349.5714416503906
AudioEffectEnvelope      op2env3;        //xy=637.0000610351562,298.5714416503906
AudioEffectEnvelope      op2env1;        //xy=639.0000686645508,199.0714292526245
AudioEffectEnvelope      op2env2;        //xy=641.2500686645508,250.82143020629883
AudioSynthWaveformModulated pwm2; //xy=741,443
AudioSynthWaveformModulated pwm3; //xy=742,476
AudioSynthWaveformModulated pwm1; //xy=743,411
AudioSynthWaveformModulated pwm4; //xy=743,508
AudioSynthWaveformModulated op1v4;            //xy=754.0000381469727,351.57142639160156
AudioSynthWaveformModulated op1v2;            //xy=756.0000381469727,253.57142639160156
AudioSynthWaveformModulated op1v3;            //xy=756.0000381469727,299.57142639160156
AudioSynthWaveformModulated op1v1;            //xy=758.0000381469727,199.57142639160156
AudioSynthWaveformModulated wave3;          //xy=758.000072479248,652.3214206695557
AudioSynthWaveformModulated wave2;          //xy=758.250072479248,618.0714206695557
AudioSynthWaveformModulated wave1;          //xy=758.750072479248,583.071418762207
AudioSynthWaveformModulated wave4;          //xy=759.000072479248,686.32142162323
AudioMixer4              voice1;         //xy=976.0000381469727,325.57142639160156
AudioMixer4              voice2;         //xy=976.0000381469727,399.57142639160156
AudioMixer4              voice3;         //xy=977.0000381469727,472.57142639160156
AudioMixer4              voice4;         //xy=978.0000381469727,543.5714263916016
AudioEffectEnvelope      envelope2;      //xy=1184.0000381469727,408.57142639160156
AudioEffectEnvelope      envelope3;      //xy=1185.0000381469727,451.57142639160156
AudioEffectEnvelope      envelope1;      //xy=1186.0000381469727,361.57142639160156
AudioEffectEnvelope      envelope4;      //xy=1187.0000381469727,497.57142639160156
AudioMixer4              left;           //xy=1424.0000381469727,386.57142639160156
AudioMixer4              right;          //xy=1426.0000381469727,465.57142639160156
AudioFilterStateVariable filter1;        //xy=1568,383
AudioFilterStateVariable filter2; //xy=1569,451
AudioOutputI2S           i2s1;           //xy=1702,419.5714416503906
AudioConnection          patchCord1(op3v3, op3env3);
AudioConnection          patchCord2(op3v1, op3env1);
AudioConnection          patchCord3(op3v2, op3env2);
AudioConnection          patchCord4(op3v4, op3env4);
AudioConnection          patchCord5(op3env2, 0, op2v2, 0);
AudioConnection          patchCord6(op3env1, 0, op2v1, 0);
AudioConnection          patchCord7(op3env3, 0, op2v3, 0);
AudioConnection          patchCord8(op3env4, 0, op2v4, 0);
AudioConnection          patchCord9(op2v4, op2env4);
AudioConnection          patchCord10(op2v1, op2env1);
AudioConnection          patchCord11(op2v3, op2env3);
AudioConnection          patchCord12(op2v2, op2env2);
AudioConnection          patchCord13(dc1, 0, pwm1, 1);
AudioConnection          patchCord14(dc1, 0, pwm2, 1);
AudioConnection          patchCord15(dc1, 0, pwm3, 1);
AudioConnection          patchCord16(dc1, 0, pwm4, 1);
AudioConnection          patchCord17(op2env4, 0, op1v4, 0);
AudioConnection          patchCord18(op2env3, 0, op1v3, 0);
AudioConnection          patchCord19(op2env1, 0, op1v1, 0);
AudioConnection          patchCord20(op2env2, 0, op1v2, 0);
AudioConnection          patchCord21(pwm2, 0, voice2, 1);
AudioConnection          patchCord22(pwm3, 0, voice3, 1);
AudioConnection          patchCord23(pwm1, 0, voice1, 1);
AudioConnection          patchCord24(pwm4, 0, voice4, 1);
AudioConnection          patchCord25(op1v4, 0, voice4, 0);
AudioConnection          patchCord26(op1v2, 0, voice2, 0);
AudioConnection          patchCord27(op1v3, 0, voice3, 0);
AudioConnection          patchCord28(op1v1, 0, voice1, 0);
AudioConnection          patchCord29(wave3, 0, voice3, 2);
AudioConnection          patchCord30(wave2, 0, voice2, 2);
AudioConnection          patchCord31(wave1, 0, voice1, 2);
AudioConnection          patchCord32(wave4, 0, voice4, 2);
AudioConnection          patchCord33(voice1, envelope1);
AudioConnection          patchCord34(voice2, envelope2);
AudioConnection          patchCord35(voice3, envelope3);
AudioConnection          patchCord36(voice4, envelope4);
AudioConnection          patchCord37(envelope2, 0, left, 1);
AudioConnection          patchCord38(envelope2, 0, right, 1);
AudioConnection          patchCord39(envelope3, 0, left, 2);
AudioConnection          patchCord40(envelope3, 0, right, 2);
AudioConnection          patchCord41(envelope1, 0, left, 0);
AudioConnection          patchCord42(envelope1, 0, right, 0);
AudioConnection          patchCord43(envelope4, 0, left, 3);
AudioConnection          patchCord44(envelope4, 0, right, 3);
AudioConnection          patchCord45(left, 0, filter1, 0);
AudioConnection          patchCord46(right, 0, filter2, 0);
AudioConnection          patchCord47(filter1, 0, i2s1, 0);
AudioConnection          patchCord48(filter2, 0, i2s1, 1);
// GUItool: end automatically generated code


Bounce but_switch = Bounce();
Bounce enc_switch = Bounce();

ResponsiveAnalogRead ctl2(A10, true);
ResponsiveAnalogRead ratio1(A8, true);
ResponsiveAnalogRead ratio2(A5, true);
ResponsiveAnalogRead fm1(A4, true);
ResponsiveAnalogRead fm2(A3, true);
ResponsiveAnalogRead release(A2, true);
ResponsiveAnalogRead attack(A1, true);
ResponsiveAnalogRead ctl1(A0, true);



void setup()
{
  pinMode(gateled, OUTPUT);
  pinMode(gate, OUTPUT);
  //analog in settings and knobs
  analogReadResolution(ADCbit);

  fm1.setAnalogResolution(ADCRes);
  fm2.setAnalogResolution(ADCRes);
  ratio1.setAnalogResolution(ADCRes);
  ratio2.setAnalogResolution(ADCRes);
  ctl1.setAnalogResolution(ADCRes);
  ctl2.setAnalogResolution(ADCRes);
  attack.setAnalogResolution(ADCRes);
  release.setAnalogResolution(ADCRes);

  fm1.setActivityThreshold(activitythreshold);
  fm2.setActivityThreshold(activitythreshold);
  ratio1.setActivityThreshold(modactivitythreshold);
  ratio2.setActivityThreshold(modactivitythreshold);
  ctl1.setActivityThreshold(activitythreshold);
  ctl2.setActivityThreshold(activitythreshold);
  attack.setActivityThreshold(activitythreshold);
  release.setActivityThreshold(activitythreshold);


  fm1.enableEdgeSnap();
  fm2.enableEdgeSnap();
  ratio1.enableEdgeSnap();
  ratio2.enableEdgeSnap();
  ctl1.enableEdgeSnap();
  ctl2.enableEdgeSnap();
  attack.enableEdgeSnap();
  release.enableEdgeSnap();


  fm1_knob = (1 - ((float)fm1.getValue() / ADCRes - (1 / ADCRes)));
  fm2_knob = (1 - ((float)fm2.getValue() / ADCRes - (1 / ADCRes)));
  ratio1_knob = (1 - ((float)ratio1.getValue() / ADCRes)) * ratiosteps;
  ratio2_knob = (1 - ((float)ratio2.getValue() / ADCRes)) * ratiosteps;
  ctl1_knob = (1 - ((float)ctl1.getValue() / ADCRes - (1 / ADCRes)));
  ctl2_knob = (1 - ((float)ctl2.getValue() / ADCRes - (1 / ADCRes)));
  attack_knob = (1 - ((float)attack.getValue() / ADCRes - (1 / ADCRes)));
  release_knob = (1 - ((float)release.getValue() / ADCRes - (1 / ADCRes)));

  op2_ratio = ratioindex[(int)(ratio1_knob * ratiosteps)];
  op3_ratio = ratioindex[(int)(ratio2_knob * ratiosteps)];
  //button inputs
  //  but_switch.attach(button);
  //  enc_switch.attach(enc_button);
  //  but_switch.interval(debounce);
  //  enc_switch.interval(debounce);

  //midi settings

  Serial.begin(57600); //set baud rate to 57600 if you want to send messages to serial console
  //normally its 31250

  MIDI.begin(MIDI_CHANNEL_OMNI);
  //myusb.begin();

  midi1.setHandleNoteOn(handleMIDIon);
  midi1.setHandleNoteOff(handleMIDIoff);
  midi1.setHandleControlChange(controlchange);

  MIDI.setHandleNoteOff(handleMIDIoff);
  MIDI.setHandleNoteOn(handleMIDIon);
  MIDI.setHandlePitchBend(pitchbend);
  MIDI.setHandleControlChange(controlchange);
  usbMIDI.setHandleNoteOff(handleMIDIoff);
  usbMIDI.setHandleNoteOn(handleMIDIon);
  usbMIDI.setHandleControlChange(controlchange);

  uiSetup();     // setup key detection and debounce algorithm
  AudioMemory(80);
  getsettings(); //get settings from EEPROM
  initial(); //initialize all audio objects
}

void loop()
{

  MIDI.read();
  myusb.Task();
  midi1.read();

  usbMIDI.read();

  fm1.update();
  if (fm1.hasChanged() == 1)
  {
    fm1_knob = (upperfm1-lowerfm1) - fm1.getValue();
    
    fm1_knob = (pow(fm1_knob, 2) / (upperfm1-lowerfm1)); //mapping the linear scale of the pot to a logarithmic
    //Serial.println(String("fm value(no div):")+fm_knob);
    fm1_knob = (fm1_knob / (upperfm1-lowerfm1) - (1 / (upperfm1-lowerfm1)));
    Serial.println(String("Fm1 knob:") + fm1_knob);
    /*if(fm_knob <= 0.001)
      {fm_knob = 0;}*/

    AudioNoInterrupts();
    op2v1.amplitude(fm1_knob);
    op2v2.amplitude(fm1_knob);
    op2v3.amplitude(fm1_knob);
    op2v4.amplitude(fm1_knob);
    AudioInterrupts();

  }

  fm2.update();
  if (fm2.hasChanged() == 1)
  {
    fm2_knob = (upperfm2-lowerfm2) - fm2.getValue();
    Serial.println(String("FM2 knob:") + fm2_knob);
    fm2_knob = (pow(fm2_knob, 2) / (upperfm2-lowerfm2)); //mapping the linear scale of the pot to a logarithmic
    //Serial.println(String("fm value(no div):")+fm_knob);
    fm2_knob = (fm2_knob / (upperfm2-lowerfm2) - (1 / (upperfm2-lowerfm2)));
    Serial.println(String("FM2 knob2:") + fm2_knob);
    /*if(fm_knob <= 0.001)
      {fm_knob = 0;}*/

    AudioNoInterrupts();
    op3v1.amplitude(fm2_knob);
    op3v2.amplitude(fm2_knob);
    op3v3.amplitude(fm2_knob);
    op3v4.amplitude(fm2_knob);
    AudioInterrupts();

  }

  ratio1.update();
  if (ratio1.hasChanged())
  {
    ratio1_knob = (upperratio1-lowerratio1) - (float)ratio1.getValue();
    Serial.println(String("Ratio1 knob:") + ratio1_knob);
    //Serial.println(String("modi value(no div):")+modi_knob);
    ratio1_knob = (ratio1_knob / (upperratio1-lowerratio1) - (1 / (upperratio1-lowerratio1)));

    op2_ratio = ratioindex[(int)(ratio1_knob * ratiosteps)];
    AudioNoInterrupts();
    op2v1.frequency(voicefreq[0] * op2_ratio);
    op2v2.frequency(voicefreq[1] * op2_ratio);
    op2v3.frequency(voicefreq[2] * op2_ratio);
    op2v4.frequency(voicefreq[3] * op2_ratio);
    AudioInterrupts();
  }

  ratio2.update();
  if (ratio2.hasChanged())
  {
    ratio2_knob = (upperratio2-lowerratio2) - (float)ratio2.getValue();
    Serial.println(String("Ratio2 knob:") + ratio2_knob);
    //Serial.println(String("modi value(no div):")+modi_knob);
    ratio2_knob = ((ratio2_knob / (upperratio2-lowerratio2) - (1 / (upperratio2-lowerratio2))));

    op3_ratio = ratioindex[(int)(ratio2_knob * ratiosteps)];
    AudioNoInterrupts();
    op3v1.frequency(voicefreq[0] * op3_ratio);
    op3v2.frequency(voicefreq[1] * op3_ratio);
    op3v3.frequency(voicefreq[2] * op3_ratio);
    op3v4.frequency(voicefreq[3] * op3_ratio);
    AudioInterrupts();
  }

  release.update();
  if (release.hasChanged())
  {
    release_knob = (upperrelease-lowerrelease) - (float)release.getValue();
    Serial.println(String("Release knob:") + release_knob);
    //Serial.println(String("modi value(no div):")+modi_knob);
    release_knob = ((release_knob / (upperrelease-lowerrelease) - (1 / (upperrelease-lowerrelease))));

    AudioNoInterrupts();
    op2env1.release(release_knob * releasemult);
    op2env2.release(release_knob * releasemult);
    op2env3.release(release_knob * releasemult);
    op2env4.release(release_knob * releasemult);

    op3env1.release(release_knob * releasemult);
    op3env2.release(release_knob * releasemult);
    op3env3.release(release_knob * releasemult);
    op3env4.release(release_knob * releasemult);

    envelope1.release(release_knob * releasemult);
    envelope2.release(release_knob * releasemult);
    envelope3.release(release_knob * releasemult);
    envelope4.release(release_knob * releasemult);
    AudioInterrupts();
  }

  attack.update();
  if (attack.hasChanged())
  {
    attack_knob = (upperattack-lowerattack) - (float)attack.getValue();
    Serial.println(String("Attack:") + attack_knob);
    //Serial.println(String("modi value(no div):")+modi_knob);
    attack_knob = (attack_knob / (upperattack-lowerattack) - (1 / (upperattack-lowerattack)));

    AudioNoInterrupts();
    op2env1.attack(attack_knob * 1000);
    op2env2.attack(attack_knob * 1000);
    op2env3.attack(attack_knob * 1000);
    op2env4.attack(attack_knob * 1000);

    op3env1.attack(attack_knob * 1000);
    op3env2.attack(attack_knob * 1000);
    op3env3.attack(attack_knob * 1000);
    op3env4.attack(attack_knob * 1000);

    envelope1.attack(attack_knob * 1000);
    envelope2.attack(attack_knob * 1000);
    envelope3.attack(attack_knob * 1000);
    envelope4.attack(attack_knob * 1000);
    AudioInterrupts();
  }

  ctl1.update();
  if (ctl1.hasChanged())
  {
    ctl1_knob = (upperctl1-lowerctl1) - (float)ctl1.getValue();
    Serial.println(String("ctl1 knob:") + ctl1_knob);
    ctl1_knob = (ctl1_knob / (upperctl1-lowerctl1) - (1 / (upperctl1-lowerctl1)));
    Serial.println(String("ctl1 knob2:") + ctl1_knob);
    pwmdetune = (ctl1_knob*5);
    wavedetune = pwmdetune;

    // AudioNoInterrupts();
    // wave1.frequency(voicefreq[0] *(waveoct) + wavedetune);
    // wave2.frequency(voicefreq[1] *(waveoct) + wavedetune);
    // wave3.frequency(voicefreq[2] *(waveoct) + wavedetune);
    // wave4.frequency(voicefreq[3] *(waveoct) + wavedetune);

    // pwm1.frequency(voicefreq[0] *  0.5 + pwmdetune);
    // pwm2.frequency(voicefreq[1] *  0.5 + pwmdetune);
    // pwm3.frequency(voicefreq[2] *  0.5 + pwmdetune);
    // pwm4.frequency(voicefreq[3] *  0.5 + pwmdetune);
    // AudioInterrupts();
    dc1.amplitude(ctl1_knob);
    switch (ctl1_dest)
    {
      case 1:

        break;

      case 2:

        break;
    }
  } //ctl 1 ends

  ctl2.update();
  if (ctl2.hasChanged())
  {
  	ctl2_knob = (upperctl2-lowerctl2) - (float)ctl2.getValue();
  	ctl2_knob = (ctl2_knob / (upperctl2-lowerctl2) - (1 / (upperctl2-lowerctl2)));
  	spread = ctl2_knob*100;
  	if(spread <= 0.08)
  		spread = 0;

  	//byrja spread algorithm
  	Serial.println(String("Spread:") + spread);
  	float righttemp = calcright( ((spread/200)+0.5)*PI/2 );
 	float lefttemp = calcleft( ((spread/200)+0.5)*PI/2 );
 	// Serial.println(String("Righttemp:") + righttemp);
 	// Serial.println(String("lefttemp:") + lefttemp);
 	voice1panL = lefttemp;
 	voice1panR = righttemp;
 	voice4panR = lefttemp;
 	voice4panL = righttemp;
 	righttemp = calcright( (( (100-spread)/400 ) +0.25)*PI/2 );
 	lefttemp = calcleft( (( (100-spread)/400 )+0.25)*PI/2 );
 	// Serial.println(String("Righttemp2:") + righttemp);
 	// Serial.println(String("lefttemp2:") + lefttemp);
 	voice2panL = lefttemp;
 	voice2panR = righttemp;
 	voice3panR = lefttemp;
 	voice3panL = righttemp;

  	AudioNoInterrupts();
	 right.gain(0, voice1panR*0.8);
	 left.gain(0, voice1panL*0.8);

	 right.gain(1,voice2panR*0.8);
	 left.gain(1,voice2panL*0.8);

	 right.gain(2,voice3panR*0.8);
	 left.gain(2,voice3panL*0.8);

	 right.gain(3,voice4panR*0.8);
	 left.gain(3,voice4panL*0.8);
  	AudioInterrupts();
  	//enda spread algorithm
    switch (ctl2_dest)
    {
      case 1:

        break;

      case 2:

        break;
    }
  } //ctl 2 ends

  //UI hluti byrjar
  uiStep();                                     // check for key press
  menuredraw();

}//main endar


float calcright(float theta)
{
  	
  	float right = sqrt((theta)*(2/PI)*sin(theta));
  	//Serial.println(String("Right:") + right);
  	return right;
}

float calcleft(float theta)
{
	float left = sqrt((PI/2-(theta))*(2/PI)*cos(theta));
	//Serial.println(String("Left:") + left);
	return left;
}

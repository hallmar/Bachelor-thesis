#include "settings.h"
#include "variables.h"

void initial()
{
  float mixerinit = 0.5;
  AudioNoInterrupts();

  filter1.frequency(15000);
  filter2.frequency(15000);
  dc1.amplitude(0.5);
  op1v1.begin(pmampmult, voicefreq[0], current_op1waveform);
  op1v2.begin(pmampmult, voicefreq[1], current_op1waveform);
  op1v3.begin(pmampmult, voicefreq[2], current_op1waveform);
  op1v4.begin(pmampmult, voicefreq[3], current_op1waveform);

  op2v1.begin(fm1_knob, voicefreq[0], current_op2waveform);
  op2v2.begin(fm1_knob, voicefreq[1], current_op2waveform);
  op2v3.begin(fm1_knob, voicefreq[2], current_op2waveform);
  op2v4.begin(fm1_knob, voicefreq[3], current_op2waveform);

  op3v1.begin(fm2_knob, voicefreq[0], current_op3waveform);
  op3v2.begin(fm2_knob, voicefreq[1], current_op3waveform);
  op3v3.begin(fm2_knob, voicefreq[2], current_op3waveform);
  op3v4.begin(fm2_knob, voicefreq[3], current_op3waveform);

  //wave1.begin(voiceampinit, voicefreq[0], current_waveform);
  wave1.begin((wavelvl/100)*waveampmult, voicefreq[0], current_waveform);
  wave2.begin((wavelvl/100)*waveampmult, voicefreq[1], current_waveform);
  wave3.begin((wavelvl/100)*waveampmult, voicefreq[2], current_waveform);
  wave4.begin((wavelvl/100)*waveampmult, voicefreq[3], current_waveform);

  pwm1.begin((sublvl/100)*pwmampmult, voicefreq[0], WAVEFORM_PULSE );
  pwm2.begin((sublvl/100)*pwmampmult, voicefreq[1], WAVEFORM_PULSE );
  pwm3.begin((sublvl/100)*pwmampmult, voicefreq[2], WAVEFORM_PULSE );
  pwm4.begin((sublvl/100)*pwmampmult, voicefreq[3], WAVEFORM_PULSE );

  op1v1.frequencyModulation(0);
  op1v1.phaseModulation(phasemod);
  op1v2.frequencyModulation(0);
  op1v2.phaseModulation(phasemod);
  op1v3.frequencyModulation(0);
  op1v3.phaseModulation(phasemod);
  op1v4.frequencyModulation(0);
  op1v4.phaseModulation(phasemod);

  op2v1.frequencyModulation(0);
  op2v1.phaseModulation(phasemod);
  op2v2.frequencyModulation(0);
  op2v2.phaseModulation(phasemod);
  op2v3.frequencyModulation(0);
  op2v3.phaseModulation(phasemod);
  op2v4.frequencyModulation(0);
  op2v4.phaseModulation(phasemod);

  op3v1.frequencyModulation(0);
  op3v1.phaseModulation(phasemod);
  op3v2.frequencyModulation(0);
  op3v2.phaseModulation(phasemod);
  op3v3.frequencyModulation(0);
  op3v3.phaseModulation(phasemod);
  op3v4.frequencyModulation(0);
  op3v4.phaseModulation(phasemod);

  envelope1.sustain(1);
  envelope2.sustain(1);
  envelope3.sustain(1);
  envelope4.sustain(1);
  op2env1.sustain(1);
  op2env2.sustain(1);
  op2env3.sustain(1);
  op2env4.sustain(1);
  op3env1.sustain(1);
  op3env2.sustain(1);
  op3env3.sustain(1);
  op3env4.sustain(1);

  envelope1.attack(attack_knob* 1000);
  envelope2.attack(attack_knob* 1000);
  envelope3.attack(attack_knob* 1000);
  envelope4.attack(attack_knob* 1000);

  op2env1.attack(attack_knob * 1000);
  op2env2.attack(attack_knob * 1000);
  op2env3.attack(attack_knob * 1000);
  op2env4.attack(attack_knob * 1000);

  op3env1.attack(attack_knob * 1000);
  op3env2.attack(attack_knob * 1000);
  op3env3.attack(attack_knob * 1000);
  op3env4.attack(attack_knob * 1000);

  envelope1.release(releasemult * release_knob);
  envelope2.release(releasemult * release_knob);
  envelope3.release(releasemult * release_knob);
  envelope4.release(releasemult * release_knob);

  op2env1.release(release_knob * releasemult);
  op2env2.release(release_knob * releasemult);
  op2env3.release(release_knob * releasemult);
  op2env4.release(release_knob * releasemult);

  op3env1.release(release_knob * releasemult);
  op3env2.release(release_knob * releasemult);
  op3env3.release(release_knob * releasemult);
  op3env4.release(release_knob * releasemult);

  envelope1.hold(0);
  envelope2.hold(0);
  envelope3.hold(0);
  envelope4.hold(0);
  op2env1.hold(0);
  op2env2.hold(0);
  op2env3.hold(0);
  op2env4.hold(0);
  op3env1.hold(0);
  op3env2.hold(0);
  op3env3.hold(0);
  op3env4.hold(0);

  envelope1.delay(0);
  envelope2.delay(0);
  envelope3.delay(0);
  envelope4.delay(0);
  op2env1.delay(0);
  op2env2.delay(0);
  op2env3.delay(0);
  op2env4.delay(0);
  op3env1.delay(0);
  op3env2.delay(0);
  op3env3.delay(0);
  op3env4.delay(0);

  left.gain(0, mixerinit);
  left.gain(1, mixerinit);
  left.gain(2, mixerinit);
  left.gain(3, mixerinit);

  right.gain(0, mixerinit);
  right.gain(1, mixerinit);
  right.gain(2, mixerinit);
  right.gain(3, mixerinit);

  voice1.gain(0, mixerinit);
  voice1.gain(1, mixerinit);
  voice1.gain(2, mixerinit);
  voice1.gain(3, mixerinit);

  voice2.gain(0, mixerinit);
  voice2.gain(1, mixerinit);
  voice2.gain(2, mixerinit);
  voice2.gain(3, mixerinit);

  voice3.gain(0, mixerinit);
  voice3.gain(1, mixerinit);
  voice3.gain(2, mixerinit);
  voice3.gain(3, mixerinit);

  voice4.gain(0, mixerinit);
  voice4.gain(1, mixerinit);
  voice4.gain(2, mixerinit);
  voice4.gain(3, mixerinit);



  AudioInterrupts();
}

void getsettings()
{

}

void savesettings()
{

}

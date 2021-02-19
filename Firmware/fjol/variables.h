#ifndef variables_h

#define variables_h

#include "Arduino.h"

#define WAVEFORM_SINE              0
#define WAVEFORM_SAWTOOTH          1
#define WAVEFORM_SQUARE            2
#define WAVEFORM_TRIANGLE          3
#define WAVEFORM_ARBITRARY         4
#define WAVEFORM_PULSE             5
#define WAVEFORM_SAWTOOTH_REVERSE  6
#define WAVEFORM_SAMPLE_HOLD       7
#define WAVEFORM_TRIANGLE_VARIABLE 8

//-------Calibration values------
extern uint8_t lowerfm1;
extern uint16_t upperfm1;

extern uint8_t lowerfm2;
extern uint16_t upperfm2;

extern uint8_t lowerratio1;
extern uint16_t upperratio1;

extern uint8_t lowerratio2;
extern uint16_t upperratio2;

extern uint8_t lowerattack;
extern uint16_t upperattack;

extern uint8_t lowerrelease;
extern uint16_t upperrelease;

extern uint8_t lowerctl1;
extern uint16_t upperctl1;

extern uint8_t lowerctl2;
extern uint16_t upperctl2;
//-------Menu variables-----

extern uint8_t menu_redraw_required;
extern bool midi_received;

//-------outputs--------
extern bool gate_out;
extern uint8_t gate_out_n;
extern short gate;
extern short gateled;

//------Inputs---------
extern float fm1_knob;
extern float fm2_knob;
extern float ratio1_knob;
extern float ratio2_knob;

extern float attack_knob;
extern float release_knob;
extern float ctl1_knob;
extern float ctl2_knob;

extern uint8_t button_i;
extern uint8_t enc_button;

//-----constant variables------
extern const short debounce;
extern const short ADCRes;
extern const short ADCbit;
extern const uint8_t activitythreshold;
extern const uint8_t modactivitythreshold;
extern const short ratiosteps;
extern const float ratioindex[18];
extern const int releasemult;
extern const int attackmult;
extern const float waveampmult;
extern const float pwmampmult;
extern const float pmampmult;

//-----Midi notes variables-----
extern byte voicenote[4];
extern bool voicetrig[4];
extern uint8_t voicehist[4]; //0th place is newest voice 3rd place is oldest voice
extern uint8_t midichannel;
extern float voicefreq[4];
extern float pbend;
//-----Voice settings variables----

extern byte current_op1waveform;
extern byte current_op2waveform;
extern byte current_op3waveform;

extern byte current_waveform; //extra oscillator

extern int phasemod; //sets the amount of degrees an operator can phase modulate another operator

extern float voice1panL;
extern float voice1panR;

extern float voice2panL;
extern float voice2panR;

extern float voice3panL;
extern float voice3panR;

extern float voice4panL;
extern float voice4panR;

extern uint8_t pwmdetune;
extern uint8_t wavedetune;


//-----FM settings values-----
extern float op2_ratio;
extern float op3_ratio;

extern uint8_t pwm;
extern float sublvl;
extern float wavelvl;
extern uint8_t waveoct;
extern float spread;

extern uint8_t op2attack;
extern uint8_t op2decay;
extern uint8_t op2sustain;
extern uint8_t op2release;

extern uint8_t op3attack;
extern uint8_t op3decay;
extern uint8_t op3sustain;
extern uint8_t op3release;

extern uint8_t op1_feedback;
extern uint8_t op2_feedback;
extern uint8_t op3_feedback;

extern uint8_t ctl1_dest;
extern uint8_t ctl2_dest;


#endif // variables_h

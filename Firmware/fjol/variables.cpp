#include "variables.h"


//-------Calibration values------
uint8_t lowerfm1 = 0;
uint16_t upperfm1 = 4096;

uint8_t lowerfm2 = 0;
uint16_t upperfm2 = 4096;

uint8_t lowerratio1= 0;
uint16_t upperratio1 = 4096;

uint8_t lowerratio2 = 0;
uint16_t upperratio2 = 4096;

uint8_t lowerattack = 0;
uint16_t upperattack = 4096;

uint8_t lowerrelease = 0;
uint16_t upperrelease = 4096;

uint8_t lowerctl1 = 40;
uint16_t upperctl1 = 4096;

uint8_t lowerctl2 = 0;
uint16_t upperctl2 = 4006;

//-------Menu variables-----

uint8_t menu_redraw_required = 0;
bool midi_received = 0;

//-------outputs--------
bool gate_out = 0;
uint8_t gate_out_n = 1;
short gate = 3;
short gateled = 6;

//------Inputs---------
float fm1_knob;
float fm2_knob;
float ratio1_knob;
float ratio2_knob;

float attack_knob;
float release_knob;
float ctl1_knob;
float ctl2_knob;

uint8_t button_i = 4;
uint8_t enc_button = 2;

//-----constant variables------
const short debounce = 20;
const short ADCRes = 8192;
const short ADCbit = 13;
const uint8_t activitythreshold = 40;
const uint8_t modactivitythreshold = 80;
const short ratiosteps = 17;
const float ratioindex[18] = { 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9};
const int releasemult = 3000;
const int attackmult = 2000;
const float waveampmult = 0.125;
const float pwmampmult = 0.125;
const float pmampmult = 0.125;

//-----Midi notes variables-----
byte voicenote[4] = { 0, 0, 0, 0};
bool voicetrig[4] = { 0, 0, 0, 0};
uint8_t voicehist[4] = {4, 3, 2, 1}; //0th place is the oldest voice 3rd place is newest voice
byte midichannel = 4;
float voicefreq[4] = {};
float pbend = 1;
//-----Voice settings variables----

byte current_op1waveform = WAVEFORM_SINE;
byte current_op2waveform = WAVEFORM_SINE;
byte current_op3waveform = WAVEFORM_SINE;
byte current_waveform = WAVEFORM_SINE; //extra oscillator

int phasemod = 180;

float voice1panL = 0;
float voice1panR = 0;

float voice2panL = 0;
float voice2panR = 0;

float voice3panL = 0;
float voice3panR = 0;

float voice4panL = 0;
float voice4panR = 0;

uint8_t pwmdetune = 0;
uint8_t wavedetune = 0;

//-----FM settings values-----
float op2_ratio;
float op3_ratio;


uint8_t pwm = 0;
float sublvl = 0;
float wavelvl = 0;
uint8_t waveoct = 2;
float spread = 0;


uint8_t op2attack = 0;
uint8_t op2decay = 0;
uint8_t op2sustain = 0;
uint8_t op2release = 0;

uint8_t op3attack = 0;
uint8_t op3decay = 0;
uint8_t op3sustain = 0;
uint8_t op3release = 0;

uint8_t op1_feedback = 0;
uint8_t op2_feedback = 0;
uint8_t op3_feedback = 0;

uint8_t ctl1_dest = 1;
uint8_t ctl2_dest = 1;

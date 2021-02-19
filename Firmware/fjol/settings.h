
void noteON(byte note);
void noteOFF(byte note);


void handleMIDIon(byte channel, byte note, byte velocity);
void handleMIDIoff(byte channel, byte note, byte velocity);
void controlchange(byte channel, byte number, byte value);
void pitchbend(byte channel, int bend);

void changeenvelope();
void changewavesh();
void initial();
void getsettings();
void savesettings();
void waveformrefresh();

float calcright(float theta);
float calcleft(float theta);


void uiSetup();
void uiStep();
void drawMainMenu();
void drawParameter();
void drawsubparameter();
void drawMidi();
void drawmidichannel();
void drawSave();
void updateMenu();
void updatemidimenu();
void updateparametermenu();
void updatesublvl();
void updatewavelvl();
void updateshape();
void menuredraw();


// int sublvl( uint8_t command, uint8_t increment);
// int spread( uint8_t command, uint8_t increment);
// int midichannel( uint8_t command, uint8_t value);
// int wavelvl( uint8_t command, uint8_t increment);

// int pan1( uint8_t command, uint8_t increment);
// int pan2( uint8_t command, uint8_t increment);
// int pan3( uint8_t command, uint8_t increment);
// int pan4( uint8_t command, uint8_t increment);

// int op1shape( uint8_t command, uint8_t increment);
// int op2shape( uint8_t command, uint8_t increment);
// int op3shape( uint8_t command, uint8_t increment);

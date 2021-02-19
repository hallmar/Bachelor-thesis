#include "settings.h"
#include "variables.h"

#define imageWidth 128
#define imageHeight 64

static unsigned char u8g_logo_bits[] = //cowboy logo yee hawwww
{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xe0, 0x01, 0x00, 0x00, 0x00, 0xf0, 0xff, 0x9f, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x80, 0xff, 0xff, 0x3f,
   0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x07, 0x00,
   0xf8, 0xff, 0xff, 0x7f, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x7c, 0x00, 0xf8, 0x01, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 0xc0, 0x9e, 0xff, 0xff, 0xff, 0xff,
   0xf3, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0xe0,
   0xff, 0xff, 0xff, 0xff, 0x87, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x3e, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00,
   0x00, 0x80, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x1f, 0x00, 0x00, 0xf0, 0xff, 0x03, 0x00, 0x00, 0x00, 0xfc,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x2f, 0x00, 0x00, 0xfe, 0xff, 0x03,
   0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00,
   0xc0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0x00, 0xf0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0xf8,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x20, 0xfe, 0xff, 0xff, 0x03,
   0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xc0,
   0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x7f, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0xf0,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc6, 0xff, 0xff, 0xff, 0xff, 0x01,
   0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xd0, 0xff,
   0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x01, 0x83, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x0f, 0x00, 0x00, 0xe0,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x01, 0xfe, 0xff, 0xff, 0x3f, 0x00,
   0xff, 0x07, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xfe,
   0xff, 0xff, 0x1f, 0x00, 0x80, 0xff, 0x01, 0xc0, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x07, 0xfc, 0xf8, 0xff, 0x0f, 0x00, 0x00, 0xc0, 0xff, 0xc0,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x88, 0x7f, 0xf2, 0xff, 0x03, 0x00,
   0x3f, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x71,
   0xf4, 0x7f, 0x00, 0x00, 0xfe, 0x1f, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x7f, 0x60, 0xe8, 0x07, 0x00, 0x00, 0x03, 0xff, 0x0f, 0xf8,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc0, 0x68, 0x00, 0x00, 0x00,
   0xf8, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0e, 0x80,
   0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x27, 0x80, 0x07, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x23, 0x00, 0x06, 0x01, 0x00, 0x00,
   0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0x01, 0x00,
   0x00, 0x03, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xc9, 0x7f, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x41, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff,
   0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
   0xfe, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xfc, 0xef, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff,
   0x4b, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
   0xf0, 0xfc, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0xf9, 0xff, 0xff, 0x09, 0x00, 0x00, 0x00,
   0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf3, 0xff, 0xff,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x10, 0x00,
   0x80, 0xe7, 0xff, 0xff, 0xff, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
   0x00, 0xf0, 0x0f, 0x00, 0x00, 0xee, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xcf, 0xff, 0x03, 0x08, 0x00, 0xc0, 0xff, 0xff,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8f, 0xff, 0xff, 0xcf,
   0xff, 0x9f, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00,
   0xc0, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
   0xef, 0x00, 0x00, 0x00, 0x10, 0xfc, 0x07, 0x00, 0x8f, 0x0f, 0xe8, 0xff,
   0x7f, 0xff, 0xfe, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x10, 0xf8, 0x0f, 0x00,
   0xdc, 0x00, 0x08, 0xff, 0x7f, 0xff, 0xfd, 0xff, 0x3f, 0x00, 0x00, 0x00,
   0x10, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0xff, 0xfb, 0xff,
   0x3f, 0x00, 0x00, 0x00, 0x30, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0x3f, 0xfe, 0xff, 0xff, 0x3f, 0x0e, 0x00, 0x01, 0x38, 0xe0, 0xff, 0x0b,
   0x00, 0x00, 0x00, 0x00, 0x3e, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0xfa, 0x00,
   0xfc, 0xe0, 0xff, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xbf, 0xff,
   0xff, 0xff, 0x7f, 0x00, 0x3e, 0xff, 0xff, 0xff, 0x00, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x78, 0xff, 0xff, 0xff, 0x1f, 0x00, 0xbf, 0xff, 0xff, 0xbf,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x07, 0x80,
   0xff, 0xff, 0xff, 0xf7 };

//skoðaðu listan frá þeim til að sjá hvaða display með hvaða driver þeir styðja. https://github.com/olikraus/u8g2lib/wiki/device
//u8g2LIB_SSD1306_ADAFRUIT_128X64 u8g2(13, 11, 10, 5, 4);
//u8g2LIB_SSD1306_128X64 u8g2 (13, 11, 10, 5);
//u8g2LIB_SH1106_128X64 u8g2(13, 11, 10, 5);  // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
#define cs_spi 10
#define dc 5
U8G2_SSD1306_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 5);

#define KEY_NONE 0
#define KEY_PREV 1
#define KEY_NEXT 3
#define KEY_SELECT 2
#define KEY_BACK 4

#define PARAMETER_MENU 6
#define MIDI_MENU 7
#define MAIN_MENU 8

uint8_t uiKeySelect = 2;
uint8_t uiKeyBack = 4;

uint8_t uiKeyCodeold = KEY_NONE;
uint8_t uiKeyCode = KEY_NONE;

uint8_t menu_current = 0;


uint8_t menutype = 0;
bool submenu = 0; //flag sem segir þér að þú ert í submenu og að þú átt að hætta að teikna mainmenu
bool subsubmenu = 0;
uint8_t parametertype = 0;
uint8_t midimenutype = 0;
uint8_t width_screen , height_screen; //basic breytur sem segja þér hæð og breidd oled
uint8_t boxwidth = 22;

Encoder myEnc(8, 9);
long oldPosition = 0;
Bounce *buttons = new Bounce[2];

#define MENU_ITEMS 4
#define midimenuitems 1
#define parametermenuitems 3

const char *midimenu_strings[midimenuitems] = { "MIDI channel:"};
const char *menu_strings[MENU_ITEMS] = { "Synth Parameters", "MIDI settings", "Save settings" , "Performance"};
const char *stringparameter[1] = {"Parameter menu"}; //getur líka haft þetta í drawParameter function ef þú vilt
const char *stringmidi[1] = {"MIDI menu"};
const char *parameter_menu_strings[parametermenuitems] = {"Sub Osc lvl:", "Wave lvl:", "Waveform:"};
const char *waveformindex[4] = {"Sin", "Saw", "Squ", "Tri"};
//update-x-menu er basically túlkun á skipunum frá encoder og hvað það page á að gera þegar það fær 'next', 'back' eða 'select' skipanir
//draw er bara hvernig á að teikna það tiltekna page/subpage
//ui setup er að setja upp encoder og takka
//ui step tekur inn upplýsingar frá tökkum og rotary encoder og gefa því meiningu, s.s. next, prev, select og back

void menuredraw(void)
{

  //u8g2lib virkar þannig að maður þarf að hafa svokaallað 'picture loop' sem er þetta firstpage() og do,while(next page) dæmi.

  if (  menu_redraw_required != 0) {
    u8g2.firstPage();
    do  {

      if(voicetrig[0] == 1 && !submenu)
      {
        // u8g2.setFont(u8g_font_6x13);
        // u8g2.setFontRefHeightText();
        // u8g2.setFontPosTop();
        // u8g2.setDrawColor(1);
        // //u8g2.drawStr(16,60,"1");
        u8g2.drawCircle(16, 50, 4, U8G2_DRAW_UPPER_LEFT);
      }
      if(voicetrig[1] == 1 && !submenu)
      {
        // u8g2.setFont(u8g_font_6x13);
        // u8g2.setFontRefHeightText();
        // u8g2.setFontPosTop();
        // u8g2.setDrawColor(1);
        // //u8g2.drawStr(32,60,"2");
        u8g2.drawCircle(16, 50, 4, U8G2_DRAW_UPPER_RIGHT);
      }
      if(voicetrig[2] == 1 && !submenu)
      {
        // u8g2.setFont(u8g_font_6x13);
        // u8g2.setFontRefHeightText();
        // u8g2.setFontPosTop();
        // u8g2.setDrawColor(1);
        // //u8g2.drawStr(48,60,"3");
        u8g2.drawCircle(16, 50, 4, U8G2_DRAW_LOWER_RIGHT);
      }
      if(voicetrig[3] == 1 && !submenu)
      {
        // u8g2.setFont(u8g_font_6x13);
        // u8g2.setFontRefHeightText();
        // u8g2.setFontPosTop();
        // u8g2.setDrawColor(1);
        // u8g2.drawStr(64,60,"4");
        u8g2.drawCircle(16, 50, 4, U8G2_DRAW_LOWER_LEFT);
      }

      

      if (submenu == 0)
      {
        drawMainMenu();
      }
      else if (submenu != 0 && menutype == 0)
      {
        if (subsubmenu != 0)
        {
          drawsubparameter();
        }
        else
          drawParameter();
      } //ef parameter page

      else if (submenu != 0 && menutype == 1)
      {
        if (subsubmenu != 0)
        {
          drawmidichannel();
        }
        else
          drawMidi();
      }//ef midi page
      else if (submenu != 0 && menutype == 2)
      {
        drawSave();
      }

    } while ( u8g2.nextPage() );

    menu_redraw_required = 0;

    if (menutype == 2 && submenu == 1)
    {
      delay(10);
      submenu = 0;
      menu_redraw_required = 1; //endurteikna skjáinn
    }
  } //if endar


  if (submenu != 1)
  {
    updateMenu();
  }
  if (submenu == 1)
  {
    switch (menutype)
    {
      case 0: //parameter menu
        if (subsubmenu != 0)
        {
          switch (parametertype)
          {
            case 0:
              updatesublvl();
              break;
            case 1:
              updatewavelvl();
              break;
            case 2:
              updateshape();
              break;
          }
        }
        else
          updateparametermenu();
        break;

      case 1: //midi menu
        if (subsubmenu != 0)
        {
          switch (midimenutype)
          {
            case 0:
              updatemidichannel();
          }
        }
        else
          updatemidimenu();
        break;

      case 2: //save menu
        //do nothing
        break;
    } //switch endar
  } //if submenu == 1 endar

}

void uiSetup(void) {
  // configure input keys
  
  u8g2.begin();
  buttons[0].attach(enc_button, INPUT_PULLUP);
  buttons[1].attach(button_i, INPUT_PULLUP);

  menu_redraw_required = 1;     // force initial redraw
  width_screen = u8g2.getDisplayWidth();
  height_screen = u8g2.getDisplayHeight();

  u8g2.clearBuffer();
  u8g2.drawXBM(0,0,width_screen,height_screen, u8g_logo_bits);
  u8g2.sendBuffer();
  delay(2000);
}

void uiStep(void)
{
  buttons[0].update();
  buttons[1].update();

  long newPosition = myEnc.read();
  if (newPosition < (oldPosition - 1))
  {
    oldPosition = newPosition;
    uiKeyCode = KEY_NEXT;

  }
  else if (newPosition > (oldPosition + 1))
  {
    oldPosition = newPosition;
    uiKeyCode = KEY_PREV;
  }

  else if (buttons[0].fell())
  {
    uiKeyCode = KEY_SELECT;
  }
  else if ( buttons[1].fell())
    uiKeyCode = KEY_BACK;
  else
    uiKeyCode = KEY_NONE;

}

void drawMainMenu(void) {
  uint8_t i, h;
  u8g2_uint_t d;
  u8g2.setFont(u8g_font_6x13);

  u8g2.setFontRefHeightText();
  u8g2.setFontPosTop();
  d = 0;
  h = u8g2.getAscent() - u8g2.getDescent();
  for ( i = 0; i < MENU_ITEMS; i++ ) {
    
    d = (width_screen - u8g2.getStrWidth(menu_strings[i])) / 2;

    if ( i == menu_current ) {
      u8g2.setDrawColor(1);
      u8g2.drawBox(0, i * h + 1, width_screen, h);
    }
    u8g2.setFontMode(1);
    u8g2.setDrawColor(2);
    u8g2.drawStr(d, i * h, menu_strings[i]);
  }
}

void drawParameter(void)
{

  uint8_t i, h;
  u8g2_uint_t d;
  uint8_t stringwidth = u8g2.getStrWidth(parameter_menu_strings[0]);
  uint8_t stringwidth2 = u8g2.getStrWidth(parameter_menu_strings[1]);
  uint8_t stringwidth3 = u8g2.getStrWidth(parameter_menu_strings[2]);

  u8g2.setFont(u8g_font_6x13);
  u8g2.setFontRefHeightText();
  u8g2.setFontPosTop();

  h = (u8g2.getAscent() - u8g2.getDescent()) + 4;
  //teikna banner
  d = (width_screen - u8g2.getStrWidth(stringparameter[0])) / 2;
  u8g2.setDrawColor(1); //setja bakgrunnslit fyrir box sem hvítann
  u8g2.drawBox(0, 0, width_screen, h - 4);
  u8g2.setFontMode(1);
  u8g2.setDrawColor(0); //setja bakgrunnslit fyrir texta sem 'svartann'
  u8g2.drawStr(d, 0, stringparameter[0]);
  //sub level
  for ( i = 0; i < parametermenuitems; i++ ) {
  d = (width_screen - u8g2.getStrWidth(parameter_menu_strings[i])) / 2;
    u8g2.setDrawColor(1);
    if ( i == menu_current ) {
      u8g2.drawFrame(120, (i + 1)*h, 2, h - 4);
    }
    u8g2.setFontMode(1);
    u8g2.setDrawColor(1);
    u8g2.drawStr(0, (i + 1)*h, parameter_menu_strings[i]);
  }//for endar
  
  u8g2.setDrawColor(1);
  u8g2.setCursor(stringwidth + 6, h);
  u8g2.print((int)(sublvl));
  u8g2.setCursor(stringwidth2 + 6, h * 2);
  u8g2.print((int)(wavelvl));
  u8g2.drawStr(stringwidth3 + 6, h * 3, waveformindex[current_waveform]);

}
void drawsubparameter(void)
{

  uint8_t i, h;
  u8g2_uint_t d;
  uint8_t stringwidth = u8g2.getStrWidth(parameter_menu_strings[0]);
  uint8_t stringwidth2 = u8g2.getStrWidth(parameter_menu_strings[1]);
  uint8_t stringwidth3 = u8g2.getStrWidth(parameter_menu_strings[2]);

  u8g2.setFont(u8g_font_6x13);
  u8g2.setFontRefHeightText();
  u8g2.setFontPosTop();

  h = (u8g2.getAscent() - u8g2.getDescent()) + 4;
  //teikna banner
  d = (width_screen - u8g2.getStrWidth(stringparameter[0])) / 2;
  u8g2.setDrawColor(1); //setja bakgrunnslit fyrir box sem hvítann
  u8g2.drawBox(0, 0, width_screen, h-4);
  u8g2.setFontMode(1);
  u8g2.setDrawColor(0); //setja bakgrunnslit fyrir texta sem 'svartann'
  u8g2.drawStr(d, 0, stringparameter[0]);
  //sub level
  for ( i = 0; i < parametermenuitems; i++ ) {
    d = (width_screen - u8g2.getStrWidth(parameter_menu_strings[i])) / 2;
    u8g2.setDrawColor(1);
    if ( i == menu_current ) {
      u8g2.drawBox(u8g2.getStrWidth(parameter_menu_strings[i]) + 3, (i + 1)*h, 22, h - 4);
    }
    u8g2.setFontMode(1);
    u8g2.setDrawColor(1);
    u8g2.drawStr(0, (i + 1)*h, parameter_menu_strings[i]);
  }//for endar

  if (menu_current == 0)
    u8g2.setDrawColor(0);
  else
    u8g2.setDrawColor(1);

  u8g2.setFontMode(1);
  u8g2.setCursor(stringwidth + 6, h);
  u8g2.print((int)(sublvl));
  if (menu_current == 1)
    u8g2.setDrawColor(0);
  else
    u8g2.setDrawColor(1);

  u8g2.setFontMode(1);
  u8g2.setCursor(stringwidth2 + 6, h * 2);
  u8g2.print((int)(wavelvl));

  if (menu_current == 2)
    u8g2.setDrawColor(0);
  else
    u8g2.setDrawColor(1);

  u8g2.setFontMode(1);
  u8g2.drawStr(stringwidth3 + 6, h * 3, (waveformindex[current_waveform]));

}

void drawMidi(void)
{
  uint8_t i, h;
  u8g2_uint_t d;
  uint8_t stringwidth = u8g2.getStrWidth(midimenu_strings[0]);
  uint8_t boxwidth;
  u8g2.setFont(u8g_font_6x13);
  u8g2.setFontRefHeightText();
  u8g2.setFontPosTop();
  h = (u8g2.getAscent() - u8g2.getDescent()) + 4;
  //teikna banner
  d = (width_screen - u8g2.getStrWidth(stringmidi[0])) / 2;
  u8g2.setDrawColor(0); //setja bakgrunnslit fyrir box sem hvítann
  u8g2.drawBox(0, 0, width_screen, h - 4);
  u8g2.setDrawColor(1); //setja bakgrunnslit fyrir texta sem 'svartann'
  u8g2.drawStr(d, 0, stringmidi[0]);

  for ( i = 0; i < midimenuitems; i++ ) {
    // d = (width_screen - u8g2.getStrWidth(midimenu_strings[i])) / 2;
    u8g2.setDrawColor(0);
    u8g2.drawFrame(120, (i + 1)*h, 2, h - 4);
    u8g2.drawStr(0, (i + 1)*h, midimenu_strings[i]);

  }//for endar
  u8g2.setDrawColor(0);
  u8g2.setCursor(stringwidth + 6, h);
  u8g2.print((midichannel));
}

void drawmidichannel(void)
{
  uint8_t i, h;
  u8g2_uint_t d;
  uint8_t stringwidth = u8g2.getStrWidth(midimenu_strings[0]);
  uint8_t boxwidth;
  u8g2.setFont(u8g_font_6x13);
  u8g2.setFontRefHeightText();
  u8g2.setFontPosTop();
  h = (u8g2.getAscent() - u8g2.getDescent()) + 4;
  //teikna banner
  d = (width_screen - u8g2.getStrWidth(stringmidi[0])) / 2;
  u8g2.setDrawColor(0); //setja bakgrunnslit fyrir box sem hvítann
  u8g2.drawBox(0, 0, width_screen, h);
  u8g2.setDrawColor(1); //setja bakgrunnslit fyrir texta sem 'svartann'
  u8g2.drawStr(d, 0, stringmidi[0]);

  for ( i = 0; i < midimenuitems; i++ ) {
    // d = (width_screen - u8g2.getStrWidth(midimenu_strings[i])) / 2;
    u8g2.setDrawColor(0);
    if ( i == menu_current ) {
      if ((midichannel) <= 9)
      {
        boxwidth = 11;
      }
      else if ((midichannel) > 9)
      {
        boxwidth = 17;
      }
      u8g2.drawBox(u8g2.getStrWidth(midimenu_strings[i]) + 3, (i + 1)*h, boxwidth, 15);
    }
    u8g2.drawStr(0, (i + 1)*h, midimenu_strings[i]);

  }//for endar
  u8g2.setDrawColor(1);
  u8g2.setCursor(stringwidth + 6, h);
  u8g2.println((midichannel));

}

void drawSave(void)
{
  const char *stringsaved[1] = {"Saved!"};
  u8g2_uint_t d;
  int8_t h;
  u8g2.setFont(u8g_font_6x13);
  u8g2.setFontRefHeightText();
  u8g2.setFontPosTop();
  u8g2.setDrawColor(1);
  u8g2.setDrawColor(0);

  h = u8g2.getAscent() - u8g2.getDescent();
  d = (width_screen - u8g2.getStrWidth(stringsaved[0])) / 2;
  u8g2.drawStr(d, height_screen / 2, stringsaved[0]);

}

void updateMenu(void) {
  if ( uiKeyCode == uiKeyCodeold && submenu != 1) {
    return;
  }
  uiKeyCodeold = uiKeyCode;

  switch ( uiKeyCode )
  {
    case KEY_NEXT:
      menu_current++;
      if ( menu_current >= MENU_ITEMS )
        menu_current = 0;
      menu_redraw_required = 1;
      break;
    case KEY_PREV:
      Serial.println("back");
      if ( menu_current == 0 )
        menu_current = MENU_ITEMS;
      menu_current--;
      menu_redraw_required = 1;
      break;
    case KEY_SELECT:
      menu_redraw_required = 1;
      switch (menu_current)
      {
        case 0:
          menutype = 0;
          submenu = 1;
          menu_current = 0;
          break;

        case 1:
          menutype = 1;
          submenu = 1;
          menu_current = 0;
          break;

        case 2:
          savesettings();
          menutype = 2;
          submenu = 1;
          menu_current = 0;
          break;
      } //case select endar

      break;
    case KEY_BACK:
      submenu = 0;
      menu_redraw_required = 1;
      break;
  } //switch uikeycode endar
}//update menu endar

void updatemidimenu(void)
{
  if ( uiKeyCode == uiKeyCodeold) {
    return;
  }
  uiKeyCodeold = uiKeyCode;

  switch ( uiKeyCode )
  {
    case KEY_NEXT:
      menu_current++;
      if ( menu_current >= midimenuitems )
        menu_current = 0;
      menu_redraw_required = 1;
      break;
    case KEY_PREV:
      if ( menu_current == 0 )
        menu_current = midimenuitems;
      menu_current--;
      menu_redraw_required = 1;
      break;
    case KEY_SELECT:
      menu_redraw_required = 1;
      switch (menu_current)
      {
        case 0:
          menu_current = 0;
          subsubmenu = 1;
          midimenutype = 0;
          // case 1:
          //   menutype = 1;
          //   subsubmenu = 1;

      }
      break;
    case KEY_BACK:
      submenu = 0;
      menu_redraw_required = 1;
      break;
  } //switch uikeycode endar
}

void updateparametermenu(void)
{
  if ( uiKeyCode == uiKeyCodeold) {
    return;
  }
  uiKeyCodeold = uiKeyCode;

  switch ( uiKeyCode )
  {
    case KEY_NEXT:
      menu_current++;
      if ( menu_current >= parametermenuitems )
        menu_current = 0;
      menu_redraw_required = 1;
      break;
    case KEY_PREV:
      if ( menu_current == 0 )
        menu_current = parametermenuitems;
      menu_current--;
      menu_redraw_required = 1;
      break;
    case KEY_SELECT:

      switch (menu_current)
      {
        case 0:
          parametertype = 0;
          subsubmenu = 1;
          break;
        case 1:
          parametertype = 1;
          subsubmenu = 1;
          break;
        case 2:
          parametertype = 2;
          subsubmenu = 1;

      }
      menu_redraw_required = 1;
      break;
    case KEY_BACK:
      submenu = 0;
      menu_redraw_required = 1;
      break;
  } //switch uikeycode endar
}

void updatesublvl(void)
{
  if ( uiKeyCode == uiKeyCodeold) {
    return;
  }
  uiKeyCodeold = uiKeyCode;
  switch ( uiKeyCode )
  {

    case KEY_NEXT:
      if ((sublvl) < 96)
        sublvl += 5;

      menu_redraw_required = 1;
      break;

    case KEY_PREV:
      if ((sublvl) > 4)
        sublvl -= 5;

      menu_redraw_required = 1;
      break;

    case KEY_SELECT:
      menu_redraw_required = 1;
      subsubmenu = 0;
      submenu = 1;
      menutype = 0;

      break;
    case KEY_BACK:
      menu_redraw_required = 1;
      subsubmenu = 0;
      submenu = 1;
      menutype = 0;
      break;
      
  } //switch uikeycode endar
  AudioInterrupts();
      pwm1.amplitude((sublvl/100)*pwmampmult);
      pwm2.amplitude((sublvl/100)*pwmampmult);
      pwm3.amplitude((sublvl/100)*pwmampmult);
      pwm4.amplitude((sublvl/100)*pwmampmult);
  AudioInterrupts();

}

void updatewavelvl(void)
{
  //
  if ( uiKeyCode == uiKeyCodeold) {
    return;
  }
  uiKeyCodeold = uiKeyCode;
  switch ( uiKeyCode )
  {

    case KEY_NEXT:
      if ( (wavelvl) < 96)
        wavelvl += 5;

      menu_redraw_required = 1;
      break;

    case KEY_PREV:
      if ((wavelvl) > 4)
        wavelvl -= 5;
      menu_redraw_required = 1;
      break;

    case KEY_SELECT:
      menu_redraw_required = 1;
      subsubmenu = 0;
      submenu = 1;
      menutype = 0;
      break;

    case KEY_BACK:
      menu_redraw_required = 1;
      subsubmenu = 0;
      submenu = 1;
      menutype = 0;
      break;
  } //switch uikeycode endar
    AudioInterrupts();
      wave1.amplitude((wavelvl/100)*waveampmult);
      wave2.amplitude((wavelvl/100)*waveampmult);
      wave3.amplitude((wavelvl/100)*waveampmult);
      wave4.amplitude((wavelvl/100)*waveampmult);
    AudioInterrupts();
}


void updateshape(void)
{
  //
  if ( uiKeyCode == uiKeyCodeold) {
    return;
  }
  uiKeyCodeold = uiKeyCode;
  switch ( uiKeyCode )
  {

    case KEY_NEXT:
      if ( current_waveform < 3)
        current_waveform += 1;

      menu_redraw_required = 1;
      break;

    case KEY_PREV:
      if (current_waveform > 0)
        current_waveform -= 1;

      menu_redraw_required = 1;
      break;

    case KEY_SELECT:
      menu_redraw_required = 1;
      subsubmenu = 0;
      submenu = 1;
      menutype = 0;
      break;

    case KEY_BACK:
      menu_redraw_required = 1;
      subsubmenu = 0;
      submenu = 1;
      menutype = 0;
      break;
  } //switch uikeycode endar
  AudioNoInterrupts();
  wave1.begin(current_waveform);
  wave2.begin(current_waveform);
  wave3.begin(current_waveform);
  wave4.begin(current_waveform);
  AudioInterrupts();
}


void updatemidichannel(void)
{
  if ( uiKeyCode == uiKeyCodeold)
  {
    return;
  }
  uiKeyCodeold = uiKeyCode;

  switch ( uiKeyCode )
  {
    case KEY_NEXT:
      ++(midichannel);
      if ( midichannel > 16)
        midichannel = 1;
      menu_redraw_required = 1;
      break;
    case KEY_PREV:
      --(midichannel);
      if ( midichannel == 0 )
        midichannel = 16;
      menu_redraw_required = 1;
      break;
    case KEY_SELECT:
      menu_redraw_required = 1;
      subsubmenu = 0;
      submenu = 1;
      menutype = 1;

      break;
    case KEY_BACK:

      break;
  } //switch uikeycode endar
}


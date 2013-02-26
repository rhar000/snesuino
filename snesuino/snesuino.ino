/* 
  Snesuino
  Version: 1.0 (26/02/2013) - first version   
*/

#include <SNESpad.h>

// put your own strobe/clock/data0/data1 pin numbers here
SNESpad nintendo = SNESpad(2,3,4,7);

// keyboard output buffer
uint8_t buf[8] = { 0 };	

#define KEY_LEFT_CTRL	0x01
#define KEY_LEFT_SHIFT	0x02
#define KEY_RIGHT_CTRL	0x10
#define KEY_RIGHT_SHIFT	0x20

//int newstate_0 = 0;
int oldstate_0 = 0;
//int newstate_1 = 0;
int oldstate_1 = 0;

// define keyboard keys to press (controller 0)
#define SNES0_KEY_A 0x11; // N
#define SNES0_KEY_B 0x10; // M
#define SNES0_KEY_X 0x0F; // L
#define SNES0_KEY_Y 0x1C; // K
#define SNES0_KEY_UP 0x52; // ArrowUp
#define SNES0_KEY_DOWN 0x51; // ArrowDown
#define SNES0_KEY_LEFT 0x50; // ArrowLeft
#define SNES0_KEY_RIGHT 0x4F; // ArrowRight
#define SNES0_KEY_L 0x05; // B
#define SNES0_KEY_R 0x0D; // J
#define SNES0_KEY_SELECT 0x16; // S
#define SNES0_KEY_START 0x07;  // D

void setup() {
  Serial.begin(115200);  
}

void loop() {
  
  nintendo.buttons();

  if (nintendo.state_0 != oldstate_0)
  {
     // er is iets veranderd, afhandelen die hap
    
     processButtons(oldstate_0, nintendo.state_0);
     
     // de nieuwe staat is de oude staat
     oldstate_0 = nintendo.state_0; 
  }
  
  if (nintendo.state_1 != oldstate_1)
  {
     // er is iets veranderd, afhandelen die hap
    
     processButtons2();
     
     // de nieuwe staat is de oude staat
     oldstate_1 = nintendo.state_1; 
  }

}

// yes this is ugly, but it is still in testing
//
//void processButtons(int oldstate, int newstate)
//{
//  processButton(SNES_A, SNES0_KEY_A, oldstate, newstate);
//  processButton(SNES_B, SNES0_KEY_B, oldstate, newstate);
//  processButton(SNES_X, SNES0_KEY_X, oldstate, newstate);
//  processButton(SNES_Y, SNES0_KEY_Y, oldstate, newstate);
//  processButton(SNES_UP, SNES0_KEY_UP, oldstate, newstate);
//  processButton(SNES_DOWN, SNES0_KEY_DOWN, oldstate, newstate);
//  processButton(SNES_LEFT, SNES0_KEY_LEFT, oldstate, newstate);
//  processButton(SNES_RIGHT, SNES0_KEY_RIGHT, oldstate, newstate);
//  processButton(SNES_START, SNES0_KEY_START, oldstate, newstate);
//  processButton(SNES_SELECT, SNES0_KEY_SELECT, oldstate, newstate);
//  processButton(SNES_L, SNES0_KEY_L, oldstate, newstate);
//  processButton(SNES_R, SNES0_KEY_R, oldstate, newstate);
//}
//
//void processButtons2()
//{
//  processButton(SNES_A, SNES1_KEY_A, oldstate, newstate);
//  processButton(SNES_B, SNES1_KEY_B, oldstate, newstate);
//  processButton(SNES_X, SNES1_KEY_X, oldstate, newstate);
//  processButton(SNES_Y, SNES1_KEY_Y, oldstate, newstate);
//  processButton(SNES_UP, SNES1_KEY_UP, oldstate, newstate);
//  processButton(SNES_DOWN, SNES1_KEY_DOWN, oldstate, newstate);
//  processButton(SNES_LEFT, SNES1_KEY_LEFT, oldstate, newstate);
//  processButton(SNES_RIGHT, SNES1_KEY_RIGHT, oldstate, newstate);
//  processButton(SNES_START, SNES1_KEY_START, oldstate, newstate);
//  processButton(SNES_SELECT, SNES1_KEY_SELECT, oldstate, newstate);
//  processButton(SNES_L, SNES1_KEY_L, oldstate, newstate);
//  processButton(SNES_R, SNES1_KEY_R, oldstate, newstate);
//}


//void processButton(int button, int mappedkey, int oldstate, int newstate)
//{
//  if (!(oldstate & button) && (newstate & button))
//  {
//     // button press
//     Serial.print(button);
//     Serial.print(" pressed, map: ");
//     Serial.println(mappedkey);
//  }
//  if ((oldstate & button) && !(newstate & button))
//  {
//     // button release
//     Serial.print(button);
//     Serial.print(" released, map: ");
//     Serial.println(mappedkey);
//  }
//}

void sendKeyboardPress(int key, int modifier)
{

}

void sendKeyboardRelease(int key, int modifier)
{
  
}



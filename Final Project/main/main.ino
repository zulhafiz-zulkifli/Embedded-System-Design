//INCLUDE LIBRARIES
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <Tone.h>
//DEFINE CONSTANTS
#define PB_SIZES 6
#define LED_SIZES 4
#define MAX_LEVEL 5
#define MAX_LEVEL_HARD 10
#define DEBOUNCE_DELAY 10
//DEFINE COMPONENTS PIN
#define RED_PB 2
#define RED_LED 3
#define GREEN_PB 4
#define GREEN_LED 5
#define YELLOW_PB 6
#define YELLOW_LED 7
#define BLUE_PB 8
#define BLUE_LED 9
#define CHANGE_PB 10
#define SELECT_PB 11
#define BUZZER A3
//DEFINE VARIABLES
LiquidCrystal_I2C lcd(0x27, 16, 2);
Tone speakerpin;
int LED_PINS[] = {RED_LED, GREEN_LED, YELLOW_LED, BLUE_LED};
int PB_PINS[] = {RED_PB, GREEN_PB, YELLOW_PB, BLUE_PB, CHANGE_PB, SELECT_PB};
int total_score = 0;
int high_score = 0;
int total_win = 0;
int sequence[MAX_LEVEL_HARD];
int sequence_count = 0;
int level = 1;
int level_prev = level;
unsigned long currentMillis, previousMillis, lastInputPB ;
bool gameOver = false;
bool gameComplete = false;
bool gamePlaying = false;
bool hardMode = true;
bool gameMode = false;
bool gameStats = false;
bool optionCursor = true;
//FUNCTION PROTOTYPES
void randomizeSequence();
void playSequence();
void printDisplay();
void loadStats();
void saveStats();
void playLoseSound();
void playWinSound();

//DEFINE BUTTON STRUCTURE FOR DEBOUNCE
struct Button {
  unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  int lastSteadyState = LOW;       // the previous steady state from the input pin
  int lastFlickerableState = LOW;  // the previous flickerable state from the input pin
  int currentState;                // the current reading from the input pin
} PB_STATES[PB_SIZES];

//SETUP FUNCTION
void setup() {
  loadStats();
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  speakerpin.begin(BUZZER); 
  randomizeSequence();
  pinMode(BUZZER, OUTPUT);
  for (int i = 0; i < LED_SIZES; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  for (int i = 0; i < PB_SIZES; i++) {
    pinMode(PB_PINS[i], INPUT_PULLUP);
  }

}

//MAIN LOOP
void loop() {
  if (!gameOver && !gameComplete && gamePlaying) {
    playSequence();
    lastInputPB = millis();
    while (level == level_prev && !gameOver && !gameComplete && gamePlaying) {
      for (int i = 0; i < PB_SIZES-2; i++) {
        printDisplay();
        PB_STATES[i].currentState = digitalRead(PB_PINS[i]);
        if (PB_STATES[i].currentState != PB_STATES[i].lastFlickerableState) {
          PB_STATES[i].lastDebounceTime = millis();
          PB_STATES[i].lastFlickerableState = PB_STATES[i].currentState;
        }
        if ((millis() - PB_STATES[i].lastDebounceTime) > DEBOUNCE_DELAY) {
          if (PB_STATES[i].lastSteadyState == HIGH && PB_STATES[i].currentState == LOW) {
            digitalWrite(LED_PINS[i], HIGH);
            digitalWrite(BUZZER, HIGH);
            if (i == sequence[sequence_count]) {
              total_score += hardMode? 50 : 20;
            } 
            else {
              gameOver = true;
              digitalWrite(LED_PINS[i], LOW);
              digitalWrite(BUZZER, LOW);
              printDisplay();
              playLoseSound();
            }
            sequence_count++;
          }
          else if (PB_STATES[i].lastSteadyState == LOW && PB_STATES[i].currentState == HIGH) {
            digitalWrite(LED_PINS[i], LOW);
            digitalWrite(BUZZER, LOW);
            if (sequence_count == level) {
              level++;
              int time_taken = (millis()-lastInputPB)/1000;
              total_score += time_taken<2? 100 : (time_taken<5? 50 : (time_taken<10? 20 : 0));
              sequence_count = 0;
              printDisplay();
              if (level > (hardMode? MAX_LEVEL_HARD : MAX_LEVEL)){
                gameComplete = true;
                printDisplay();
                playWinSound();
              }
            }
          }
          PB_STATES[i].lastSteadyState = PB_STATES[i].currentState;
        }
      }
    }
  }
  else {
    for (int i = 4; i < PB_SIZES; i++){
      printDisplay();
      PB_STATES[i].currentState = digitalRead(PB_PINS[i]);
      if (PB_STATES[i].currentState != PB_STATES[i].lastFlickerableState) {
        PB_STATES[i].lastDebounceTime = millis();
        PB_STATES[i].lastFlickerableState = PB_STATES[i].currentState;
      }
      if ((millis() - PB_STATES[i].lastDebounceTime) > DEBOUNCE_DELAY) {
        if (PB_STATES[i].lastSteadyState == HIGH && PB_STATES[i].currentState == LOW) {
          digitalWrite(BUZZER, HIGH);
          if(gameComplete || gameOver){
            if(gameComplete) total_win++;
            high_score = total_score>high_score? total_score : high_score;
            saveStats();
            total_score = 0;
            sequence_count = 0;
            level = 1;
            level_prev = level;
            gameOver = false;
            gameComplete = false;
            gamePlaying = false;
            optionCursor = true;
            randomizeSequence();
          }
          else if(gameMode && i==5){
            optionCursor? hardMode=false : hardMode=true;
            gamePlaying = true;
            gameMode = false;
            lcd.clear();
            delay(250);
            digitalWrite(BUZZER, LOW);
          }
          else if(gameStats){
            gameStats = false;
            lcd.clear();
            delay(250);
            digitalWrite(BUZZER, LOW);
          }
          else if(i==4){
            optionCursor = !optionCursor;
          }
          else if(i==5 && optionCursor){
            gameMode = true;
            lcd.clear();
            delay(250);
            digitalWrite(BUZZER, LOW);
          }
          else if(i==5 && !optionCursor){
            gameStats = true;
            lcd.clear();
            delay(250);
            digitalWrite(BUZZER, LOW);
          }
        }
        else if (PB_STATES[i].lastSteadyState == LOW && PB_STATES[i].currentState == HIGH) {
          digitalWrite(BUZZER, LOW);
        }
        PB_STATES[i].lastSteadyState = PB_STATES[i].currentState;
      }
    }
  }
}

//FUNCTION TO PRINT DISPLAY ON LCD
void printDisplay() {
  if(gamePlaying){
    if (!gameOver && !gameComplete) {
      lcd.setCursor(0, 0);
      lcd.print("SCORE:");
      lcd.setCursor(6, 0);
      lcd.print(String(total_score));
      lcd.setCursor(0, 1);
      lcd.print("LEVEL:");
      lcd.setCursor(6, 1);
      lcd.print(String(level));
    }
    else if (gameOver){
      lcd.setCursor(0, 0);
      lcd.print("GAME OVER!");
      lcd.setCursor(0, 1);
      lcd.print("PRESS TO RETURN");
    }
    else if (gameComplete){
      lcd.setCursor(0, 0);
      lcd.print("GAME COMPLETE!");
      lcd.setCursor(0, 1);
      lcd.print("PRESS TO RETURN");
    }
  }
  else{
    if(gameStats){
      lcd.setCursor(0, 0);
      lcd.print("HIGHSCORE:");
      lcd.setCursor(10, 0);
      lcd.print(String(high_score));
      lcd.setCursor(0, 1);
      lcd.print("TOTAL WIN:");
      lcd.setCursor(10, 1);
      lcd.print(String(total_win));

    }
    else{
      lcd.setCursor(0, 0);
      lcd.print("**COLOR MEMORY**");
      lcd.setCursor(0, 1);
      if(gameMode){
        if(optionCursor){
          lcd.print("> NORMAL    HARD");
        }
        else{
          lcd.print("  NORMAL  > HARD");
        }
      }
      else{
        if(optionCursor){
          lcd.print("> PLAY     STATS");
        }
        else{
          lcd.print("  PLAY   > STATS");
        }
      }
  
    }
  }
}

//FUNCTION TO PLAY COLOR SEQUENCE
void playSequence() {
  if(level==1) delay(1000);
  delay(1000);
  for (int i = 0; i < level; i++) {
    digitalWrite(LED_PINS[sequence[i]], HIGH);
    digitalWrite(BUZZER, HIGH);
    hardMode? delay(150) : delay(400);
    digitalWrite(LED_PINS[sequence[i]], LOW);
    digitalWrite(BUZZER, LOW);
    hardMode? delay(150) : delay(400);
  }
  level_prev = level;
}

//FUNCTION TO RANDOMIZE COLOR SEQUENCE
void randomizeSequence(){
  randomSeed(analogRead(0));
  for(int i=0; i<MAX_LEVEL_HARD;i++){
    sequence[i] = random(PB_SIZES-2);
  }
}

//FUNCTION TO LOAD STATS INTO EEPROM
void loadStats(){
  EEPROM.get(0, high_score);
  EEPROM.get(sizeof(int), total_win);
}

//FUNCTION TO SAVE STATS INTO EEPROM
void saveStats(){
  EEPROM.put(0, high_score);
  EEPROM.put(sizeof(int), total_win);
}

//FUNCTION TO PLAY LOSING SOUND
void playLoseSound(){
  for (int i=0; i<=3; i++){
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    speakerpin.play(NOTE_G2, 300);
    delay(200);
    digitalWrite(LED_PINS[0], LOW);
    digitalWrite(LED_PINS[1], LOW);
    digitalWrite(LED_PINS[2], LOW);
    digitalWrite(LED_PINS[3], LOW);
    speakerpin.play(NOTE_C2, 300);
    delay(200);
  }
}

//FUNCTION TO PLAY WINNING SOUND
void playWinSound(){
  int note[] = {NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4};
  int duration[] = {100, 100, 100, 300, 100, 300};
  for (int y=0; y<=2; y++){
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[1], HIGH);
    digitalWrite(LED_PINS[2], HIGH);
    digitalWrite(LED_PINS[3], HIGH);
    delay(200);
    for(int thisNote = 0; thisNote < 6; thisNote ++){
      speakerpin.play(note[thisNote]);
      delay(duration[thisNote]);
      speakerpin.stop();
      delay(25);
    }
    digitalWrite(LED_PINS[0], LOW);
    digitalWrite(LED_PINS[1], LOW);
    digitalWrite(LED_PINS[2], LOW);
    digitalWrite(LED_PINS[3], LOW);
    delay(200);
  }
}

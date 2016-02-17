//Button Press Detection - debounce with millis()

#include <SoftwareSerial.h>// import the serial library
#include <U8glib.h>

SoftwareSerial mySerial(10, 11); // RX, TX
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_NO_ACK|U8G_I2C_OPT_FAST);

int buttonPin = 7;
int buttonPin2 = 6;
int buttonPin3 = 5;
int buttonPin4 = 4;
int buttonPin5 = 3;

int count,count1,count2,count3,count4,finalcount=0;
boolean currentState = LOW;
boolean lastState = LOW;
boolean debouncedState = LOW;

boolean currentState1 = LOW;
boolean lastState1 = LOW;
boolean debouncedState1 = LOW;

boolean currentState2 = LOW;
boolean lastState2 = LOW;
boolean debouncedState2 = LOW;

boolean currentState3 = LOW;
boolean lastState3 = LOW;
boolean debouncedState3 = LOW;

boolean currentState4 = LOW;
boolean lastState4 = LOW;
boolean debouncedState4 = LOW;


int debounceInterval = 20;
unsigned long timeOfLastButtonEvent = 0;
int mode = 0;

char data;
String speech, voice;

void u8g_mode1() {
   u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos( 5, 18);
     u8g.print(speech.substring(0,15));
     u8g.setPrintPos( 5, 36);
     u8g.print(speech.substring(15,30)); 
   u8g.setPrintPos( 5, 54);
     u8g.print(speech.substring(30,45));   
  // u8g.drawBitmapP( 10, 16, 4, 27, rpm);
  if (speech.length()>45){
    delay(1000);
    speech=speech.substring(45,speech.length());
      //mode=3;
  }
}
void u8g_mode2() {
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos( 5, 18);
     u8g.print(speech.substring(45,60));
 
}


void draw(void) {
  // u8g_prepare();
       u8g.drawBox(0, 0, 129, 4);
       //u8g_time();
  switch(mode) {
    case 0: u8g_mode1(); break;
    case 1: u8g_mode2(); break;
  }
}


void setup(){
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);//initialize Serial connection
  mySerial.begin(9600);
}

void loop(){
  
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );

  currentState = digitalRead(buttonPin);
  currentState1 = digitalRead(buttonPin2);
  currentState2 = digitalRead(buttonPin3);
  currentState3 = digitalRead(buttonPin4);
  currentState4 = digitalRead(buttonPin5);
  
count =Button();
count1 =Button1();
count2 =Button2();
count3 =Button3();
count4 =Button4();
finalcount=count*1+count1*2+count2*4+count3*8+count4*16;
if(finalcount<32 && finalcount>0)
{
  
  if(finalcount==1)
  {
   speech+='a';
      Serial.print('a');
   delay(300);
  }
  else if(finalcount==2)
  {
     speech+='b';
       Serial.print('b');
   delay(300);
  }
  else if(finalcount==3)
  {
    speech+='c';
   Serial.print('c');
   delay(300);
  }
  else if(finalcount==4)
  {
   speech+='d';
   Serial.print('d');
   delay(300);
  }
  else if(finalcount==5)
   {
   speech+='e';
   Serial.print('e');
   delay(300);
  }
  else if(finalcount==6)
  {
   speech+='f';
   Serial.print('f');
   delay(300);
  }
  else if(finalcount==7)
  {
    speech+='g';
   Serial.print('g');
   delay(300);
  }
  else if(finalcount==8)
  {
    speech+='h';
   Serial.print('h');
   delay(300);
  }
  else if(finalcount==9)
  {
    speech+='i';
   Serial.print('i');
   delay(300);
  }
  else if(finalcount==10)
  {
   speech+='j';
   Serial.print('j');
   delay(300);
  }
  else if(finalcount==11)
  {
   speech+='k';
   Serial.print('k');
   delay(300);
  }
  else if(finalcount==12)
  {
   speech+='l';
   Serial.print('l');
   delay(300);
  }
  else if(finalcount==13)
  {
    speech+='m';
   Serial.print('m');
   delay(300);
  }
  else if(finalcount==14)
  {
    speech+='n';
   Serial.print('n');
   delay(300);
  }
  else if(finalcount==15)
  {
    speech+='o';
   Serial.print('o');
   delay(300);
  }
  else if(finalcount==16)
  {
    speech+='p';
   Serial.print('p');
   delay(300);
  }
  else if(finalcount==17)
   {
    speech+='q';
   Serial.print('q');
   delay(300);
  }
  else if(finalcount==18)
  {
    speech+='r';
   Serial.print('r');
   delay(300);
  }
   if(finalcount==19)
  {
   speech+='s';
   Serial.print('s');
   delay(300);
  }
  else if(finalcount==20)
  {
   speech+='t';
   Serial.print('t');
   delay(300);
  }
  else if(finalcount==21)
  {
   speech+='u';
   Serial.print('u');
   delay(300);
  }
  else if(finalcount==22)
  {
    speech+='v';
   Serial.print('v');
   delay(300);
  }
  else if(finalcount==23)
  {
    speech+='w';
   Serial.print('w');
   delay(300);
  }
  else if(finalcount==24)
  {
   speech+='x';
   Serial.print('x');
   delay(300);
  }
    else if(finalcount==25)
  {
    speech+='y';
   Serial.print('y');
   delay(300);
  }
  else if(finalcount==26)
  {
    speech+='z';
   Serial.print('z');
   delay(300);
  }
  else if(finalcount==27)
  {
   speech=speech.substring(0,speech.length()-1);
   Serial.print("delete");
   delay(300);
  }
  else if(finalcount==28)
  {
    speech+=' ';
   Serial.print(' ');
   delay(300);
  }

  
  
}

     if (mySerial.available())

{
data=mySerial.read();

speech+=data;

} 
}

int Button(){
    unsigned long currentTime = millis();
  
  if (currentState != lastState){
    timeOfLastButtonEvent = currentTime;
  }
  
  if (currentTime - timeOfLastButtonEvent > debounceInterval){
    if (currentState != debouncedState){
      debouncedState = currentState;
      if (debouncedState == HIGH){
        return 1;
      } else {
        return 0;
      }
    }
  }
  lastState = currentState;
}

int Button1(){
    unsigned long currentTime1 = millis();
  
  if (currentState1 != lastState1){
    timeOfLastButtonEvent = currentTime1;
  }
  
  if (currentTime1 - timeOfLastButtonEvent > debounceInterval){
    if (currentState1 != debouncedState1){
      debouncedState1 = currentState1;
      if (debouncedState1 == HIGH){
         return 1;
      } else {
        return 0;
      }
    }
  }
  lastState1 = currentState1;
}
int Button2(){
    unsigned long currentTime2 = millis();
  
  if (currentState2 != lastState2){
    timeOfLastButtonEvent = currentTime2;
  }
  
  if (currentTime2 - timeOfLastButtonEvent > debounceInterval){
    if (currentState2 != debouncedState2){
      debouncedState2 = currentState2;
      if (debouncedState2 == HIGH){
         return 1;
      } else {
        return 0;
       
      }
    }
  }
  lastState2 = currentState2;
}
int Button3(){
    unsigned long currentTime3 = millis();
  
  if (currentState3 != lastState3){
    timeOfLastButtonEvent = currentTime3;
  }
  
  if (currentTime3 - timeOfLastButtonEvent > debounceInterval){
    if (currentState3 != debouncedState3){
      debouncedState3 = currentState3;
      if (debouncedState3 == HIGH){
          return 1;
      } else {
        return 0;
      }
    }
  }
  lastState3 = currentState3;
}
int Button4(){
    unsigned long currentTime4 = millis();
  
  if (currentState4 != lastState4){
    timeOfLastButtonEvent = currentTime4;
  }
  
  if (currentTime4 - timeOfLastButtonEvent > debounceInterval){
    if (currentState4 != debouncedState4){
      debouncedState4 = currentState4;
      if (debouncedState4 == HIGH){
          return 1;
      } else {
         return 0;
      }
    }
  }
  lastState4 = currentState4;
}


void a()
{ 
  unsigned long currentTime4 = millis();
  
  if (finalcount != lastState4){
    timeOfLastButtonEvent = currentTime4;
  }
  
  if (currentTime4 - timeOfLastButtonEvent > debounceInterval){
    if (currentState4 != debouncedState4){
      debouncedState4 = currentState4;
      if (debouncedState4 == HIGH){
           Serial.print('a');
      } else {
       //  Serial.print('0');
      }
    }
  }
  lastState4 = currentState4;
}

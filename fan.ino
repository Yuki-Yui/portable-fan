//#define SwitchPin 0
#define PWMPin 7
#define ButtonPin 3
#define LEDPin1 26
#define LEDPin2 27
#define LEDPin3 28
#define LEDPin4 29
#define Modes 4

volatile uint8_t state = 0;
volatile int timer = 0;
//uint8_t i = 0;

void setup() {
  //Serial.begin(19200);
  //pinMode(0, OUTPUT);

  //FanSpeed
  pinMode(PWMPin, OUTPUT);

  //RGBLED
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(25, OUTPUT);
  digitalWrite(16,HIGH);
  digitalWrite(17,HIGH);
  digitalWrite(25,HIGH);

  //LED
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(LEDPin4, OUTPUT);
  digitalWrite(LEDPin1,HIGH);

  //Button
  pinMode(ButtonPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ButtonPin), change, FALLING);
}

void loop() {
  //Serial.println(timer);
  //Serial.print(",");
  //Serial.println(state);
  //change();
  timer = 0;
  delay(100);
}

/*void ps(){
  timer += 1;
}*/

void change(){
  if(timer == 0){
    timer = 1;
    state = (state+1)%Modes;
    analogWrite(PWMPin,(state+1)*255/Modes);
    for(int i=0; i<Modes; i++){
      if(i<=state){
        digitalWrite(i+26,HIGH);
      }else{
        digitalWrite(i+26,LOW); 
      }
    }
  }
}

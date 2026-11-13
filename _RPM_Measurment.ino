// --------------------PINS----------------------------------------------
//sensor
const int ir_pin = 2;

//the motor
const int enA_pin = 7;
const int in1_pin = 6;
const int in2_pin = 5;
int speed = 200;  //0-255

//----------------RPM MEASURING VARIABLES---------------------------------------
//Time
unsigned long previousTime = 0;
unsigned long currentTime;
const unsigned long interval = 100;

//PULSE & REVOLUTION
unsigned long pulses; 
const unsigned int PPR = 20; // number of holes in the encoder
volatile unsigned long pulseCount;
float Revolution;
float RPM;

//---------INTERRUPT FOUNCTION-----------------------------
void countPulse(){
  pulseCount++;
}

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);

  //sensor
  pinMode(ir_pin, INPUT);

  //convert the digital pins to interrupt pins(2 & 3 in arduino are interrupt pins)
  attachInterrupt(digitalPinToInterrupt(ir_pin), countPulse, RISING); 

  //MOTOR
  pinMode(in1_pin, OUTPUT);
  pinMode(in2_pin, OUTPUT);
  pinMode(enA_pin, OUTPUT);
  digitalWrite(in1_pin, HIGH);
  digitalWrite(in2_pin, LOW);
  analogWrite(enA_pin,speed);

  previousTime = millis(); //

}


void loop() {
  // put your main code here, to run repeatedly:
    currentTime = millis();

    if(currentTime - previousTime >= interval){
      
      noInterrupts();
      pulses = pulseCount;
      pulseCount = 0;
      interrupts();

      Revolution = (float)pulses/PPR;

      RPM = (Revolution * 60 * 1000)/interval;

      Serial.print("RPM: ");
      Serial.println(RPM);

      previousTime = currentTime;

    }
    
}

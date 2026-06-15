#define STEP_PIN 6 // slider
#define DIR_PIN  30
#define EN_PIN  31  // Optional (can remove if not used)

#define STEP_PIN_1 2
#define DIR_PIN_1  23
#define En_p1 22

#define STEP_PIN_2 3
#define DIR_PIN_2  25
#define En_p2 24

#define STEP_PIN_3 4
#define DIR_PIN_3 27
#define En_p3 26

#define STEP_PIN_4 5
#define DIR_PIN_4  29
#define En_p4 28

#define STEP_PIN_gri 7
#define DIR_PIN_gri  36
#define En_pgri 34

int RPWM = 9;
int LPWM = 8;
int R_EN = 39;
int L_EN = 38;




int pulseDelay =325;   // Lower = faster (try 400–1200)

void back(float dis){
  
  digitalWrite(EN_PIN, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(DIR_PIN, HIGH); // Set direction
  
  for(int i = 0; i < (250*dis); i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(pulseDelay);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(pulseDelay);
  } 
}

void front(float dis){
  digitalWrite(EN_PIN, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(DIR_PIN, LOW); // Set direction
  
  for(int i = 0; i < (250*dis); i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(pulseDelay);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(pulseDelay);
  }
}

void up(float dis){
  digitalWrite(En_p1, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(En_p2, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(En_p3, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(En_p4, LOW);   // Enable driver (LOW = enabled for A4988)

  digitalWrite(DIR_PIN_1, LOW); // Set direction
  digitalWrite(DIR_PIN_2, LOW); // Set direction
  digitalWrite(DIR_PIN_3, LOW); // Set direction
  digitalWrite(DIR_PIN_4, LOW); // Set direction
  
  for(int i = 0; i < (250*dis); i++) {
    digitalWrite(STEP_PIN_1, HIGH);
    digitalWrite(STEP_PIN_2, HIGH);
    digitalWrite(STEP_PIN_3, HIGH);
    digitalWrite(STEP_PIN_4, HIGH);
    delayMicroseconds(500);

    digitalWrite(STEP_PIN_1, LOW);
    digitalWrite(STEP_PIN_2, LOW);
    digitalWrite(STEP_PIN_3, LOW);
    digitalWrite(STEP_PIN_4, LOW);
    delayMicroseconds(500);
  }
}

void down(float dis){
  digitalWrite(En_p1, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(En_p2, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(En_p3, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(En_p4, LOW);   // Enable driver (LOW = enabled for A4988)

  digitalWrite(DIR_PIN_1, HIGH); // Set direction
  digitalWrite(DIR_PIN_2, HIGH); // Set direction
  digitalWrite(DIR_PIN_3, HIGH); // Set direction
  digitalWrite(DIR_PIN_4, HIGH); // Set direction
  
  for(int i = 0; i < (250*dis); i++) {
    digitalWrite(STEP_PIN_1, HIGH);
    digitalWrite(STEP_PIN_2, HIGH);
    digitalWrite(STEP_PIN_3, HIGH);
    digitalWrite(STEP_PIN_4, HIGH);
    delayMicroseconds(500);

    digitalWrite(STEP_PIN_1, LOW);
    digitalWrite(STEP_PIN_2, LOW);
    digitalWrite(STEP_PIN_3, LOW);
    digitalWrite(STEP_PIN_4, LOW);
    delayMicroseconds(500);
  }
}

void grab(float dis){
  digitalWrite(En_pgri, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(DIR_PIN_gri, LOW); // Set direction
  
  for(int i = 0; i < (200*dis); i++) {
    digitalWrite(STEP_PIN_gri, HIGH);
    delayMicroseconds(pulseDelay);
    digitalWrite(STEP_PIN_gri, LOW);
    delayMicroseconds(500);
  }
}

void Release(float dis){
  digitalWrite(En_pgri, LOW);   // Enable driver (LOW = enabled for A4988)
  digitalWrite(DIR_PIN_gri, HIGH); // Set direction
  
  for(int i = 0; i < (200*dis); i++) {
    digitalWrite(STEP_PIN_gri, HIGH);
    delayMicroseconds(pulseDelay);
    digitalWrite(STEP_PIN_gri, LOW);
    delayMicroseconds(500);
  }
}


void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);

  pinMode(STEP_PIN_1, OUTPUT);
  pinMode(DIR_PIN_1, OUTPUT);
  pinMode(En_p1, OUTPUT);

  pinMode(STEP_PIN_2, OUTPUT);
  pinMode(DIR_PIN_2, OUTPUT);
  pinMode(En_p2, OUTPUT);

  pinMode(STEP_PIN_3, OUTPUT);
  pinMode(DIR_PIN_3, OUTPUT);
  pinMode(En_p3, OUTPUT);
  
  pinMode(STEP_PIN_4, OUTPUT);
  pinMode(DIR_PIN_4, OUTPUT);
  pinMode(En_p4, OUTPUT);
  
  pinMode(STEP_PIN_gri, OUTPUT);
  pinMode(DIR_PIN_gri, OUTPUT);
  pinMode(En_pgri, OUTPUT);
  

  // conveyor
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);

  // Enable both sides
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);

  analogWrite(RPWM, 0); // speed 0-255
  analogWrite(LPWM, 180);

//calibration
  up(1);
  delay(200);
}



void loop() {


for(int i=1;i<14;i++){
  
  
  up(6);
  delay(200);

  back((23.9+(i*3.6)));
  delay(200);
  
  down(6);
  delay(200);

  grab(3);
  delay(2000);

  up(6);
  delay(200);

  front(23.9+(i*3.6));
  delay(200);
  

  down(6);
  delay(200);

  Release(3);
  delay(200);

}

}

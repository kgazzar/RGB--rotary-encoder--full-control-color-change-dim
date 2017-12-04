#define outputA 5
#define outputB 6
int lastcounter = 0;
int counter = 0;
int aState;
int aLastState;
int r, g, b,rv,gv,bv;
float factor=0.5;
int mode;
int a;
void setup() {
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);
  pinMode (7, OUTPUT);
  Serial.begin (115200);
  // Reads the initial state of the outputA
  aLastState = digitalRead(outputA);
  r = 0;
  g = 40;
  b = 0;
}
void loop() {
  aState = digitalRead(outputA);
  if (aState != aLastState) {
    if (digitalRead(outputB) != aState) {
      counter ++;
    } else {
      counter --;
    }
   //Serial.print(counter);Serial.print("   ");
   //counter=counter/2;
   if (mode==0) colorchange();
   if (mode==1){colordim();}
  }
  aLastState = aState;
a=analogRead(0); //for the swith
if ( a<40 && mode==0){mode=1;Serial.print("Mode");Serial.println(mode);while (analogRead(0)<500){};a=analogRead(0);}
if ( a<40 && mode==1){mode=2;Serial.print("Mode");Serial.println(mode);while (analogRead(0)<500){};a=analogRead(0);}
if ( a<40 && mode==2){mode=3;Serial.print("Mode");Serial.println(mode);while (analogRead(0)<500){};a=analogRead(0);}
if ( a<40 && mode==3){mode=0;Serial.print("Mode");Serial.println(mode);while (analogRead(0)<500){};a=analogRead(0);}
}

void colorchange() {


  if (counter > lastcounter && r < 40 && g == 40 && b == 0 ) {r ++;}
  if (counter > lastcounter && r == 40 && g <= 40 && b == 0 && g > 0) {g--;}
  if (counter > lastcounter && r == 40 && g == 0 && b < 40 ) {b++;}
  if (counter > lastcounter && r <= 40 && g == 0 && b == 40 && r > 0) {r--;}
  if (counter > lastcounter && r == 0 && g < 40 && b == 40 ) {g++;}
  if (counter > lastcounter && r == 0 && g == 40 && b <= 40 && b > 0 ) {b--;}
  /*******************/

  if (counter < lastcounter && r <= 40 && g == 40 && b == 0 && r > 0 ) {r --;}
  if (counter < lastcounter && r == 40 && g < 40 && b == 0 ) {g++;}
  if (counter < lastcounter && r == 40 && g == 0 && b <= 40 && b > 0 ) {b--;}
  if (counter < lastcounter && r < 40 && g == 0 && b == 40 ) {r++;}
  if (counter < lastcounter && r == 0 && g <= 40 && b == 40 && g > 0 ) {g--;}
  if (counter < lastcounter && r == 0 && g == 40 && b < 40  ) {b++;}

  
  rv = map(r, 0, 40, 0, 255);
  gv = map(g, 0, 40, 0, 255);
  bv = map(b, 0, 40, 0, 255);
  Serial.print("mode: ");
  Serial.print(mode);
  Serial.print("   ");
  Serial.print("color: ");
  Serial.print(rv*factor);
  Serial.print("  ;  ");
  Serial.print(gv*factor);
  Serial.print("  ;  ");
  Serial.println(bv*factor);

  analogWrite(8, rv*factor);
  analogWrite(9, gv*factor);
  analogWrite(10, bv*factor);
  lastcounter = counter;
}
void colordim(){
  
  
  if (counter < lastcounter && factor>0){factor=factor-0.025;}
 if (counter > lastcounter&& rv*(factor+0.025)<255&&gv*(factor+0.025)<255&&bv*(factor+0.025)<255){factor=factor+0.025;}
 
  Serial.print("mode: ");
  Serial.print(mode);
  Serial.print("   ");
  Serial.print("color: ");
  Serial.print(rv*factor);
  Serial.print("  ;  ");
  Serial.print(gv*factor);
  Serial.print("  ;  ");
  Serial.println(bv*factor);

 analogWrite(8, rv*factor);
  analogWrite(9, gv*factor);
  analogWrite(10, bv*factor);
  lastcounter = counter;
}


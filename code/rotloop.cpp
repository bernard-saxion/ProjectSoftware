/**
 * code to read one quadratic rotary encoder gray code.
 *
 * rights: http://tinyurl.com/by-sa-3-0
 */

int inputPin1 = 2;  // A
int inputPin2 = 4;  // B
int val1 = 0, val2 = 0;
int oldVal1 = 0, oldVal2 = 0;
int pos = 0, oldPos = 0;
int turn = 0, oldTurn = 0, turnCount=0;

/**
 * this is the heartbeat function for the rotary encoder
 * should be called from the loop()
 */
 
void rotEnc () {
  
  val1 = digitalRead(inputPin1);
  val2 = digitalRead(inputPin2);
    // Detect changes
  if ( val1 != oldVal1 || val2 != oldVal2) {
    
      //for each pair there's a position out of four
    if      ( val1 == 1 && val2 == 1 ) // stationary position
      pos = 0;
    else if ( val1 == 0 && val2 == 1 )
      pos = 1;
    else if ( val1 == 0 && val2 == 0 )
      pos = 2;
    else if ( val1 == 1 && val2 == 0 )
      pos = 3;
    
    turn = pos-oldPos;
    
    if (abs(turn) != 2) // impossible to understand where it's turning otherwise.
      if (turn == -1 || turn == 3)
        turnCount++;
      else if (turn == 1 || turn == -3)
        turnCount--;
    
    if (pos == 0){ // only assume a complete step on stationary position
      if (turnCount > 0)
        Serial.print("<");
      else if (turnCount < 0)
        Serial.print(">");
      turnCount=0;
    }
    
    oldVal1 = val1;
    oldVal2 = val2;
    oldPos  = pos;
    oldTurn = turn;
  }
}


void setup() {
  pinMode(inputPin1, INPUT);
  digitalWrite(inputPin1, HIGH);
  pinMode(inputPin2, INPUT);
  digitalWrite(inputPin2, HIGH);
  Serial.begin(9600);
}

void loop(){
  rotEnc(); 
}
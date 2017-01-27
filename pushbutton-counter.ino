int led = 13;
int kpinGameONButton = 7;

boolean isGameON = false;

int lastButtonStateA = 0;
int countPressTimes = 0;



void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(kpinGameONButton, INPUT);
  digitalWrite(kpinGameONButton, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  
  int counterGameOnButtonCounter = buttonPressCount(kpinGameONButton, lastButtonStateA);
  
  if (counterGameOnButtonCounter % 4 == 1){
    isGameON = true;
    Serial.println("One");
  }
  else if (counterGameOnButtonCounter % 4 == 2) {
    Serial.println("Two");
  }
  else if (counterGameOnButtonCounter % 4 == 3) {
    Serial.println("Three");
  }
  else {
    isGameON = false;
    Serial.println("Off");

  }
  
   
  // Main game loop
//  if (isGameON){
//    Serial.println("Game ON");
//  }
//  else {
//    Serial.println("Game Over");
//  }
}


int buttonPressCount(int button, int lastButtonState){
  		
  		int buttonState = 0;        

  		buttonState = digitalRead(button);

 		 // compare the buttonState to its previous state
  		if (buttonState != lastButtonState) {
    	// if the state has changed, increment the counter
   		 if (buttonState == LOW) {
      	 	// if the current state is HIGH then the button
      	 	// wend from off to on:
      		countPressTimes++;
      		
    		// Delay a little bit to avoid bouncing
    		delay(50);
           
  		 }
  		// save the current state as the last state,
  		//for next time through the loop
  		lastButtonStateA = buttonState;
        }
          return countPressTimes;

    
  }

  //Check if Game Button pressed ONCE

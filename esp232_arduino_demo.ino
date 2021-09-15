long timeSince = 0;
long interval = 1000; // 1 second

const int ledPin = LED_BUILTIN;
int ledState = HIGH;

long dataToSend[1000] = {0};
int i = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(0));
}


// the loop function runs over and over again forever
void loop() {

// blink with timer rather than delay
// -------------------------------------------------------------
  long currentTime = millis();
  
  if (currentTime - timeSince >= interval){
    
    timeSince = currentTime;
    
    if (ledState == LOW){
      ledState = HIGH;
      Serial.println("*****************************************");
      Serial.println("on");
      Serial.println("Sending sensor data...");
      Serial.println(sizeof(dataToSend));
      Serial.println("*****************************************");
    }
    else {
      ledState = LOW;
      // dataToSend[1000] = {0};
      i = 0;
      
      Serial.println("*****************************************");
      Serial.println("off");
      Serial.println("Reseting sensor data...");
      // Serial.println(sizeof(dataToSend));
      Serial.println("*****************************************");
    }
  }

  digitalWrite(ledPin, ledState);

  //------------------------------------------------------------
  
  long simulatedSensor = random(300);

  dataToSend[i] = simulatedSensor;
  i ++;
  
  Serial.print("Count: ");
  Serial.println(i);

//***************************************************************
  // This stalls the CPU and blocks processing  
  // digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  // delay(1000);                       // wait for a second
  // Serial.println("on");
  

  // digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  // delay(1000);                       // wait for a second
  // Serial.println("off");

  //***************************************************************
  


  Serial.print("Simulated Sensor Reading: ");
  Serial.println(simulatedSensor);

}
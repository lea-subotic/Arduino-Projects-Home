const int analogPin = A0;  
const int threshold = 20;  
float Temp;
int analogValue= 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  
  analogValue = analogRead(analogPin);
  
  // if the analog value is high enough, turn on the LED:
  if (analogValue > threshold) {
    digitalWrite(LED_BUILTIN, HIGH);
      delay(2500); 
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }


  Temp =log(10000.0/(1024.0/analogValue-1)); // for pull-up configuration
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;            // Convert Kelvin to Celcius
  
  Serial.print("AnalogValue: "); 
  Serial.print(analogValue);
  Serial.println("  ");

  Serial.print("Temperature: "); 
  Serial.print(Temp );
  Serial.println(" C"); 

  delay(2000);  
}

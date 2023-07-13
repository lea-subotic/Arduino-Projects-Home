const int analogInPin = A0; 

const int analogOutPin = 9;

int Value = 0;        
int outputValue = 0;        

void setup() {

  Serial.begin(9600);
}

void loop() {

  // read the analog in value:

  Value = analogRead(analogInPin);

  // map it to the range of the analog out:

  outputValue = map(Value, 0, 1023, 0, 255);

  // change the analog out value:

  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:

  Serial.print("Value = ");

  Serial.print(Value);

  Serial.print("\t led = ");

  Serial.println(outputValue);

  delay(500);
}
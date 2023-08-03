//Switch an LED using an IR sensor

	int ir = 2;
	int PinLed = LED_BUILTIN;
	int val=0;


	void setup()
	{
		pinMode(ir, INPUT);
		pinMode(LED_BUILTIN, OUTPUT);

	}

	void loop()
	{
		if(digitalRead(ir) == LOW)
		{
			digitalWrite(LED_BUILTIN, HIGH);
		}
		else
		{
			digitalWrite(LED_BUILTIN, LOW);
		}
    Serial.println(digitalRead(ir) );
	}

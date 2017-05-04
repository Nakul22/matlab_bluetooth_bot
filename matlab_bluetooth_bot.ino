#define ML1  3
#define ML2  4
#define MR1  5
#define MR2  6

int data = 0;            //Variable for storing received data
void setup()
{
  Serial.begin(9600);   //Sets the baud for serial data transmission

  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
}
void loop()
{
  if (Serial.available() > 0)     // Send data only when you receive data:
  {
    data = Serial.read();        //Read the incoming data & store into data
    //    Serial.print(data);          //Print Value inside data in Serial monitor
    //    Serial.print("\n");
    if (data == 30)  // Move Forward
    {
      digitalWrite(ML1, HIGH);
      digitalWrite(ML2, LOW);
      digitalWrite(MR1, HIGH);
      digitalWrite(MR2, LOW);
      delay(100);
    }

    if (data == 31)  // Move Backward
    {

      digitalWrite(ML1, LOW);
      digitalWrite(ML2, HIGH);
      digitalWrite(MR1, LOW);
      digitalWrite(MR2, HIGH);
      delay(100);
    }
    if (data == 28)  // LEFT
    {

      digitalWrite(ML1, LOW);
      digitalWrite(ML2, LOW);
      digitalWrite(MR1, HIGH);
      digitalWrite(MR2, LOW);
      delay(100);
    }
    if (data == 29)  // RIGHT
    {

      digitalWrite(ML1, HIGH);
      digitalWrite(ML2, LOW);
      digitalWrite(MR1, LOW);
      digitalWrite(MR2, LOW);
      delay(100);
    }
  }
  else
  {
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, LOW);
    digitalWrite(MR1, LOW);
    digitalWrite(MR2, LOW);
  }
}


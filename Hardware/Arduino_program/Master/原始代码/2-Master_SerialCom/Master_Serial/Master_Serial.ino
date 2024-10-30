#include <Wire.h>

// IIC initial setup
#define buffer_size 26
#define slave_num 1
char buff[slave_num][buffer_size] = {""};

String str = "";
int count = 0;
unsigned long myTime;

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup()
{
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);

  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(2000000);
  delay(500);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, HIGH);  
}


// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================
void loop()
{
   myTime = millis();
    updateSlaveIMUs();
   Serial.println(String(1000/(millis() - myTime)) + " fps");
}


// ================================================================
// ===                    Custom Functions                      ===
// ================================================================

void updateSlaveIMUs() 
{
  uint8_t node_count = 0;
  for(uint8_t i=0; i<slave_num; i++)
  {    
      node_count ++;
      Wire.requestFrom(i, buffer_size);    // request buffer_size bytes from slave device #xxx
      count = 0;

      while(Wire.available())    // slave may send less than requested
       {
          buff[i][count++] = Wire.read();    // receive a byte as character
          if(count >= buffer_size)
            break;
        }

      str += buff[i];
      str += ";";
  }
  Serial.println(str);
  str = "";
}

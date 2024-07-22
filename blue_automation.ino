
//----------------------Header files------------------//
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include<utility/imumaths.h>
#include <avr/wdt.h>
#define bno055_ka_delay (100)

Adafruit_BNO055 myIMU = Adafruit_BNO055(55, 0x28, &Wire);
// Adafruit_BNO055 myIMU = Adafruit_BNO055(55, 0x29, &Wire);


//------------------defining base motors----------------------//
#define md1 29
#define md2 23
#define md3 27
#define md4 25
#define pwm1 7
#define pwm2 4
#define pwm3 6
#define pwm4 5

//----------------------mechanism motors--------------//
#define fallmd 28
#define fallpwm 10
#define pickmd 26
#define pickpwm 9

//-------------------Encoder pins--------------//
#define encbr 18
#define encfr 19
#define encfl 2
#define encbl 3
#define flpin 50
#define frpin 51
#define blpin 52
#define brpin 53                                                    // w----x
//                                                                          |    |
                                                                       // y----z

//---------------pin for changing Area 3 code-------------//
#define codechangepin 13

//--------------encoder counts and it's related variables--------//
float w, x, y, z;
float cor = (w + x + z) / 3, temp, Xcor, Ycor;

//---------Robot state from i=0 to i=7------------//
int i = 0;

//------------base motors vairable speed-----------//
float ms = 230;
float velocity = 140;
int slow_speed = 90;

//-------------IMU variables-------------------//
float yy, yaw, roll, pitch, yawDeg, pitchDeg, rollDeg;
float imutune = 3.1;

//------------------sensor data and their indices------------------//
int sensor[9];
byte id = 0;
byte frontlsa = 1;
byte leftlsa = 2;
byte rightlsa = 3;
byte proxi_wall = 4;
byte proxi_silo_left = 5;
byte proxi_silo_right = 6;
byte proxi_zone = 7;
byte push = 8;

//--------------------lsa factors for PID--------------//
float lsat = 35;
float lkp = 0.6, lki = 0.0001, lkd = 0.000001;
float lsa_erri, lsa_errd, lsa_eprev, lsa_err;
float p;

//-----------------Motion from A1-A3-----------------//
int lsa_flag = 0;

//---------------buffer variables and counts for A1,water zone-------------//
float buff = 0;
float first_step,third_step;

//----------------for throwing ball into silo------------//
int silo_flag;
int silo_count = 1;

//
int lsa_buff;

//----------------motors direction pin for forward-------------//
bool fl = 1;
bool fr = 1;
bool bl = 0;
bool br = 1;

//
bool sensor_flag = 0;

//----------------switching between A3 codes-------------//
int switching =1;

//---------------center line storage zone variables-------------//
float frontwall = 1250, rightwall = 540, leftwall = 990;
int i1silo = 5, i2silo = 5, i3silo = 450;

//---------------line before center plus storage zone variables-------------//
float frontwall2 = 1100, rightwall2 = 910, leftwall2 = 700;
float corner = 380;
int i1silo2 = 5, i2silo2 = 10, i3silo2 = 680, i6silo2 = 200, i7silo2=5;

//---------------line after center plus storage zone variables-------------//
float frontwall3 = 1010, rightwall3 = 750, leftwall3 = 900;
float corner3 = 380;
int i1silo3 = 5, i2silo3 = -5, i3silo3 = 680, i6silo3 = 200, i7silo3=5;

//------------------count updation after throwing into silo-------------//
float silobuffforleft = 700;
float silobufffori3 = 680;
float silobufffori2 = 10;
float silobufffori7 = 5;

//--------------speed variation after ballpick-------------//
byte ballpick=0;

//---------------retry zone changing code-----------------//
byte retry=0;

void setup()
{
  Serial.begin(115200);
  Serial.println("No begin");
  Wire.begin(0x90);
  Serial.println("begin");

  myIMU.begin();
  while (!myIMU.begin())
  {
    Serial.println("nope");
  }
  int8_t temp = myIMU.getTemp();
  myIMU.setExtCrystalUse(true);

  pinMode(codechangepin, INPUT_PULLUP);

  pinMode(md1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(md2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(md3, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(md4, OUTPUT);
  pinMode(pwm4, OUTPUT);

  pinMode(encfr, INPUT_PULLUP);
  pinMode(encfl, INPUT_PULLUP);
  pinMode(encbl, INPUT_PULLUP);
  pinMode(encbr, INPUT_PULLUP);
  pinMode(frpin, INPUT_PULLUP);
  pinMode(flpin, INPUT_PULLUP);
  pinMode(blpin, INPUT_PULLUP);
  pinMode(brpin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encfr), ENCFR, RISING);
  attachInterrupt(digitalPinToInterrupt(encfl), ENCFL, FALLING);
  attachInterrupt(digitalPinToInterrupt(encbl), ENCBL, FALLING);
  attachInterrupt(digitalPinToInterrupt(encbr), ENCBR, RISING);
  pinMode(pickmd, OUTPUT);
  pinMode(pickpwm, OUTPUT);
  pinMode(fallmd, OUTPUT);
  pinMode(fallpwm, OUTPUT);
  Serial.println("No Receive");
  Wire.onReceive(sensordata);
  Serial.println("Receive");
  delay(1000);
  if(digitalRead(codechangepin)==HIGH)
  {
    switching=0;
    third_step=750;
  }
  else
  {
    switching=1;
    third_step=1440;
  }
  if (sensor[frontlsa] <= 70 && (sensor[rightlsa] < 60 || sensor[leftlsa] < 60))
  {
    first_step = 2000;
    retry=0;
  }
  else
  {
    first_step = 330;
    retry=1;
    corner=150;
    corner3 = 200; 
  }
  Serial.println(first_step);
//    while(1);

}

void loop()
{
  //  Serial.println(cor);
  //  Serial.println();
//    printing();
//    imus();
//    Serial.println(yawDeg);
  //  ms=100;
  //  forward(0,0);

//  digitalWrite(pickmd, HIGH);
//  analogWrite(pickpwm, 255);
//    digitalWrite(fallmd, HIGH);
//  analogWrite(fallpwm, 255);
//  delay(2000);
//    digitalWrite(pickmd, LOW);
//  analogWrite(pickpwm, 255);
//    digitalWrite(fallmd, LOW);
//  analogWrite(fallpwm, 255);
//   delay(2000);
//  i=-56;
//  Serial.println(digitalRead(codechangepin));  

  
 //----------------Motion from A1-A3--------------// 
  if (i == 0)
  {
    imu_path_area1_to_3();
  }

  //--------------Area 3 navigations--------------//
  else if (i > 0)
  {
    if (switching  < 1)
    {
      area3_navigation2();
    }
    else
    {
      area3_navigation3();
    }
  }
  else
  {
    halt();
  }

}


void husky()
{
  if(sensor[id]==1)
  {
    delay(50);
    if(sensor[id]==1)
    {
     return;
    }
  }
  else if(sensor[id]==2)
  {
    delay(50);
    if(sensor[id]==2)
    { 
     picking(0);
     free_fall(255);
     delay(2000);
    } 
  }
  else
  {
    picking(255);
    free_fall(0);
  }
}

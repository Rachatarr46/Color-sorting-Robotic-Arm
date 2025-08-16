#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;
int de1 = 12;
int pos1 = 0; //
int pos2 = 0; //ลง
int pos3 = 0; //
int pos4 = 0; //100 คือ จับ 50 คือ อ้า

const int buttonPinA = 7; //เขียว 
const int buttonPinB = 8; //เหลือง
const int buttonPinC = 9; //แดง
int buttonStateA = 0; //เขียว
int buttonStateB = 0; //เหลือง
int buttonStateC = 0; //แดง
int A = 0; //เขียว
int B = 0; //เหลือง
int C = 0; //แดง
int colorState = 0;
bool colorFind = false;
void setup() 
{
  pinMode(buttonPinA , INPUT); //เขียว
  pinMode(buttonPinB , INPUT); //เหลือง
  pinMode(buttonPinC , INPUT); //แดง

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);

  myservo1.attach(10);
  myservo2.attach(11);
  myservo3.attach(12);
  myservo4.attach(13);
  myservo1.write(3);
  myservo2.write(90);
  myservo3.write(45);
  myservo4.write(40);
}

void loop ()
{ 
 
 setfrequency ();
  buttonStateA = digitalRead(buttonPinA);
  if (buttonStateA==LOW)
  {
    A = 1;
   C = 0;
  }
   
   buttonStateB = digitalRead(buttonPinB);
  if (buttonStateB==LOW)
  {
    B = 1;
  }

   buttonStateC = digitalRead(buttonPinC);
  if (buttonStateC==LOW)
  {
    C = 1;
    A=0;
    
  }
  else if  (B==1)
  {
    for (pos1= 5; pos1 <= 180; pos1 += 1) 
      { 
      myservo1.write(pos1);          
      delay(de1);                     
      }
      delay(100);
      for (pos1= 180; pos1 >= 3; pos1 -= 1) 
      { 
      myservo1.write(pos1);              
      delay(de1);                              
      } 
      delay(100);
      for (pos2= 90; pos2 >= 60; pos2 -= 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);                     
      }
      delay(100);
      for (pos2= 60; pos2 <= 90; pos2 += 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);                 
      }
      delay(100);
      for (pos3= 50; pos3 >= 22; pos3 -= 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }
      delay(100);
      for (pos3= 22; pos3 <= 50; pos3 += 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }
      delay(100);
      for (pos4= 40; pos4 <= 85; pos4 += 1) 
      { 
      myservo4.write(pos4);          
      delay(de1);                     
      }
      delay(100);
      for (pos4= 85; pos4 >= 40; pos4 -= 1) 
      { 
      myservo4.write(pos4);          
      delay(de1);                     
      }
      delay(100);
      B=0;

 
      
   
      
  }
 else if  (A==1)
    {
      delay(20);
  buttonStateC = digitalRead(buttonPinC);
  if (buttonStateC==LOW)
  {
    C = 1;
    A=0;
  }
    
    checkcolor ();
    if (colorState==1)
    {
      redred();
      delay(50);
      colorState = 0;
    }
  
    if (colorState == 2)
    {
      blueblue();
      delay(50);
      colorState = 0;
    }

     if (colorState==3)
    {
      greengreen();
      delay(50);
   colorState = 0;
    }

    if (colorState==4)
    {
      myservo1.write(3);    
      myservo2.write(90);     
      myservo3.write(45);    
      myservo4.write(40); 
      delay(50);
   colorState = 0;
    }
   if (C==1){A=0; delay(100);}
   if (B==1){A=0; delay(100);}
    else 
    {
      myservo1.write(3);    
      myservo2.write(90);     
      myservo3.write(45);    
      myservo4.write(40);    
      Serial.println("EMTYE");
      A=1;
    
    }

  }
   
}
void setfrequency() 
{
  digitalWrite(S2,LOW); // red
  digitalWrite(S3,LOW);
  redfrequency = pulseIn(sensorOut, LOW);
  delay(100);

  digitalWrite(S2,HIGH); //green
  digitalWrite(S3,HIGH);
  greenfrequency = pulseIn(sensorOut, LOW);
  delay(100);

  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  bluefrequency = pulseIn(sensorOut, LOW);
  delay(100);

}
void greengreen ()
{
  delay(100);                           
    Serial.println("YELLOW COLOR");         
    
    

      for (pos3= 50; pos3 >= 22; pos3 -= 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }
  for (pos2= 90; pos2 >= 60; pos2 -= 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);                     
      }
      for (pos4= 40; pos4 <= 85; pos4 += 1) 
      { 
      myservo4.write(pos4);          
      delay(de1);                     
      }

 for (pos2= 60; pos2 <= 90; pos2 += 1)
      { 
      myservo2.write(pos2); 
      for(pos3= 22; pos3 >= 15; pos3 -= 1)
      {
        myservo3.write(pos3); 
 
      }         
      delay(de1);
                           
      }  
      for (pos3= 22; pos3 <= 55; pos3 += 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }

      for (pos1= 3; pos1 <= 95; pos1 += 1) 
      { 
      myservo1.write(pos1);          
      delay(de1);                     
      }
     for (pos2= 90; pos2 >= 55; pos2 -= 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);  
      } 
      for (pos3= 45; pos3 >= 30; pos3 -= 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }
   
      for (pos4= 85; pos4 >= 40; pos4 -= 1) 
      { 
      myservo4.write(pos4);          
      delay(de1);                     
      }

      for (pos2= 55; pos2 <= 90; pos2 += 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);                     
      }
      for (pos3= 30; pos3 <= 45; pos3 += 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);
      } 
      for (pos1= 95; pos1 >= 3; pos1 -= 1) 
      { 
      myservo1.write(pos1);              
      delay(de1);                              
      } 
}

void checkcolor ()
{
  if (greenfrequency<255 && greenfrequency>70)
  {
      colorFind = true;
      colorState = 1;
  }
  else if (redfrequency<255 && redfrequency>60)
  {
      colorFind = true;
      colorState = 2;
  }
  else if (redfrequency<25)
  {
      colorFind = true;
      colorState = 3;
  }

  else if((redfrequency>60)&&(greenfrequency>60)&&( bluefrequency>60))
  {
      colorFind = true;
      colorState = 4;
  }
}
void redred ()
{
  delay(100);                           
    Serial.println("RED COLOR");         
    
    for (pos3= 60; pos3 >= 22; pos3 -= 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }
  for (pos2= 90; pos2 >= 60; pos2 -= 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);                     
      }
      for (pos4= 40; pos4 <= 85; pos4 += 1) 
      { 
      myservo4.write(pos4);          
      delay(de1);                     
      }

 for (pos2= 60; pos2 <= 90; pos2 += 1)
      { 
      myservo2.write(pos2); 
      for(pos3= 22; pos3 >= 15; pos3 -= 1)
      {
        myservo3.write(pos3); 
 
      }         
      delay(de1);
                           
      } 
      for (pos3= 22; pos3 <= 55; pos3 += 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }

      for (pos1= 3; pos1 <= 43; pos1 += 1) 
      { 
      myservo1.write(pos1);          
      delay(de1);                     
      }
     
      for (pos2= 90; pos2 >= 40; pos2 -= 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);  
      } 
      
   
      for (pos4= 85; pos4 >= 40; pos4 -= 1) 
      { 
      myservo4.write(pos4);          
      delay(de1);                     
      }

      for (pos3= 55; pos3 <= 57; pos3 += 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }

      for (pos2= 45; pos2 <= 90; pos2 += 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);                     
      }
      
      for (pos1= 43; pos1 >= 3; pos1 -= 1) 
      { 
      myservo1.write(pos1);              
      delay(de1);                              
      } 
}

void blueblue()
{
    delay(100);                           
    Serial.println("BLUE COLOR");   
 for (pos3= 50; pos3 >= 22; pos3 -= 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }
  for (pos2= 90; pos2 >= 60; pos2 -= 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);                     
      }
      for (pos4= 40; pos4 <= 85; pos4 += 1) 
      { 
      myservo4.write(pos4);          
      delay(de1);                     
      }
       for (pos2= 60; pos2 <= 90; pos2 += 1)
      { 
      myservo2.write(pos2); 
      for(pos3= 22; pos3 >= 15; pos3 -= 1)
      {
        myservo3.write(pos3); 
 
      }         
      delay(de1);
                           
      } 
     
      for (pos3= 22; pos3 <= 55; pos3 += 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }


      for (pos1= 3; pos1 <= 150; pos1 += 1) 
      { 
      myservo1.write(pos1);          
      delay(de1);                     
      }
     for (pos2= 90; pos2 >= 65; pos2 -= 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);  
      } 
      for (pos3= 45; pos3 >= 25; pos3 -= 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);                     
      }
   
      for (pos4= 85; pos4 >= 40; pos4 -= 1) 
      { 
      myservo4.write(pos4);          
      delay(de1);                     
      }

      for (pos2= 65; pos2 <= 90; pos2 += 1) 
      { 
      myservo2.write(pos2);          
      delay(de1);                     
      }
      for (pos3= 25; pos3 <= 45; pos3 += 1) 
      { 
      myservo3.write(pos3);          
      delay(de1);
      } 
      for (pos1= 150; pos1 >= 3; pos1 -= 1) 
      { 
      myservo1.write(pos1);              
      delay(de1);                              
      } 
}

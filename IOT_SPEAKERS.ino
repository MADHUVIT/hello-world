#define button 2 //digital pin I/P
#define  led 3   //digital pin  O/P
#define  temp 0 //analog   I/P
#define  speak 4   // digital  O/P
#define  gas 4 //analog   I/P
#define  soil 5 //analog  I/P
#define  door 3 //analog  I/P
#define  motorin1 5//digital  O/P
#define  motorin2 6//digital 0/P
#define ena 7// enable pin DIGITAL O/P
void setup() {
  // put your setup code here, to run once:
 pinMode(button,INPUT);
 pinMode(temp,INPUT);
 pinMode(soil,INPUT);
  pinMode(door,INPUT);
 pinMode(gas,INPUT);
 pinMode(led,OUTPUT);
 pinMode(speak,OUTPUT);
 pinMode(motorin1,OUTPUT);
 pinMode(motorin2,OUTPUT);
 pinMode(ena,OUTPUT);
 digitalWrite(led,LOW);
 digitalWrite(motorin1,HIGH);
 digitalWrite(motorin2,LOW);
 digitalWrite(ena,LOW);
 Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonr=digitalRead(button);  //ref
  Serial.println(buttonr);
  delay(100);
  if(buttonr==1)
  { digitalWrite(led,1);
    }
  if(buttonr==0)
  { digitalWrite(led,0);
    }

 /////////////////////////////////////   
  int tempr=analogRead(temp); //ther
  Serial.println(tempr);
  delay(100);
  ///////////////////////////////////
  int doorr=analogRead(door); //main door
  Serial.println(doorr);
  
  delay(100);



  ///////////////////////////////////////  
 int gasr=analogRead(gas); //gas
  Serial.println(gasr);
  delay(100);
   if(gasr<=400 || tempr>200 || doorr<300)
  { digitalWrite(speak,0);
    }
  if(gasr>400 || tempr<=200 || doorr>=300)
  { digitalWrite(speak,1);
    }   
   ////////////////////////////////////////
   int soilr=analogRead(soil); //soil
  Serial.println(soilr);
  delay(100);
    if(soilr<=300)
  { digitalWrite(ena,LOW);
    }
  if(soilr>500)
  { digitalWrite(ena,HIGH);
    Serial.println("motor on");
    }   

  /////////////////////////////////////////
  
    
  
  
  
}

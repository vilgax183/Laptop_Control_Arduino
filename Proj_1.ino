int trig_1=2;
int echo_1=3;
int trig_2=5;
int echo_2=6;
long dist_1;
long dist_2;


void setup() {
  pinMode(trig_1,OUTPUT);
  pinMode(trig_2,OUTPUT);
  pinMode(echo_1,INPUT);
  pinMode(echo_2,INPUT);
  
  Serial.begin(9600);
  

}
long distance(int trig,int echo){
  //Serial.println(trig);
  //Serial.println(echo);
  long tim;
  long dist;
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(100);
  digitalWrite(trig,LOW);
  tim=pulseIn(echo,HIGH);
  //Serial.println(tim);
  dist=0.017*tim;
 // Serial.println(dist);
  return dist;
}

void loop() {
  
  dist_1=distance(trig_1,echo_1);

  dist_2=distance(trig_2,echo_2);

  delay(500);
  if(dist_1>40 && dist_2>40){
    Serial.println("No command");
  }
  if(dist_1<10 && dist_2<10){
    Serial.println("Pause/Play");
    delay(500);
  }

  if(dist_1>10 && dist_2<40){
    long dist=distance(trig_2,echo_2);
    while(dist<40){
      if(dist<10){
        Serial.println("down");
      }
      if(dist>10 && dist<40){
        Serial.println("up");
      }
      dist=distance(trig_2,echo_2);
      delay(100);
    }
  }
   if(dist_2>10 && dist_1<40 && dist_1>5){
    long dist=distance(trig_1,echo_1);
    while(dist<40){
      if(dist<15){
        Serial.println("Forward");
      }
      if(dist>15 && dist<40){
        Serial.println("Rewind");
      }
      dist=distance(trig_1,echo_1);
      delay(1000);
    }
   }
    if(dist_1<5 && dist_2>5){
      
      Serial.println("screenshot");
      delay(1000);
    }
}
  

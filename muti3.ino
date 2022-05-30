#define c3 131
#define d3 147
#define e3 165
#define f3 175
#define g3 196
#define a3 220
#define b3 247
#define c4 262
byte pins[7]={13,12,11,10,9,8,7};
byte show[10][7]={
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {1,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0},
  };
int melody1[]={
  c3,g3,b3,e3,a3,b3,e3,f3
  };
int melody2[]={
  c4,b3,a3,g3,g3,a3,b3,c3
  };
int nds1[]={
  8,4,4,8,4,4,8,4
  };
int nds2[]={
  2,2,2,2,8,4,8,4
  };
int tn=0,nd=0;
long previousT=0,presentT=0,pbn=0;
void setup() {
for(byte i=0;i<7;++i){
  pinMode(pins[i],OUTPUT);
  }
   pinMode(6,OUTPUT);
   pinMode(2,INPUT_PULLUP);
   pinMode(3,INPUT_PULLUP);
}
void checktoplay(){
  presentT=millis();
  if(presentT-previousT>=2000){
    if(digitalRead(2)==0){
      tn-=1;
      }
    else{tn+=1;}
    
    if(tn>9){
      tn=-1;
      previousT=millis();
     }
     else{
      for(byte j=0;j<7;j++){
    digitalWrite(pins[j],show[tn][j]);
      }
      previousT=millis();
      }
    }
  }
void loop() {
  for(byte i=0;i<8;i++){
   if(digitalRead(3)==0){
     nd=1000/nds2[i];
     tone(6,melody2[i],nd);
     checktoplay();
   delay(nd*1.3);
    }
   else{
    nd=1000/nds1[i];
    tone(6,melody1[i],nd);
     checktoplay();
   delay(nd*1.3);
    }
   }
}

#include <Stepper.h>
int value = 0;
int state_mercury = 0;
int leng = 0 ;
int data ;
long timer = 0;
const int stepsPerRevolution = 1024;
Stepper step_one(stepsPerRevolution,11,9,10,8);
Stepper step_two(stepsPerRevolution,7,5,6,4);
Stepper step_three(stepsPerRevolution,53,51,52,50);
Stepper step_center(stepsPerRevolution,35,33,34,32);

void route(int value);

void waitHorizon(){
  
  // 초기화
  timer = 0;
  int temp = 0 ;
  state_mercury = 0 ;
  while(1){
     temp = digitalRead(2);
     // 1에서 0
     if(state_mercury && !temp){
        break;
     } else if (timer >= 1000 && !temp ) {  // 현재 따르고 있지 않으면서 시간이 초과되었을때
        break;        
     }else {     
        timer++;
        Serial.println(timer);
        state_mercury = temp;
     }
  
  }

}

void setup() {

  pinMode(2, INPUT);
  step_one.setSpeed(28);
  step_two.setSpeed(28);
  step_three.setSpeed(28);
  step_center.setSpeed(28);

  Serial.begin(9600);
}

void loop() {
  
  
  if(Serial.available())      //시리얼 모니터에 데이터가 입력되면
  {
    leng++;    
    // data is two digit 1의자리 카트리지, 10의자리 잔 수
    if( leng == 1){ 
      data = Serial.read() - '0';  
      Serial.write("yet");
    } else if(leng == 2 ){      
    data = data * 10 ;
    data += Serial.read()-'0';
    Serial.print(data);    
    Serial.write("working");
    leng = 0;
    route(data);      
    }
  }
  
}
void first(int cupNumber) {
  for(int i = 0 ; i < cupNumber; i++){
    step_center.step(1024);
    step_one.step(512);
    step_center.step(-1024);
    waitHorizon();
  }
}

void second(int cupNumber) {
  for(int i = 0 ; i < cupNumber; i++){
    step_center.step(2048);
    step_two.step(512);
    step_center.step(-2048);
    waitHorizon();
  }
}

void third(int cupNumber) {
  for(int i = 0 ; i < cupNumber; i++){
    step_center.step(3072);
    step_three.step(512);
    step_center.step(-3072);
    waitHorizon();  
  }  
}

void route(int value) {  
  
  switch(value%10){   
    case 1:
      first(value/10);
      break;
    case 2:
      second(value/10);
      break;
    case 3:
      third(value/10);
      break;
    default :
      break;
  }
  Serial.write('ready');
}

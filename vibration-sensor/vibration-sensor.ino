#define LED_Pin 5 //NodeMCU GPIO D01
#define VSensor 13 //NodeMCU GPIO D07

long measurement;

void setup(){
  Serial.begin(115200);
  pinMode(LED_Pin, OUTPUT);
  pinMode(VSensor, INPUT);
}

void loop(){
  measurement = TP_init();
  Serial.println("Measurement:");
  if(measurement > 1000){
    digitalWrite(LED_Pin, HIGH);
    Serial.println(measurement);
  }else{
    digitalWrite(LED_Pin,LOW);
    Serial.println(measurement);
  }
}

long TP_init(){
  delay(10);
  long measurement = pulseIn(VSensor, HIGH);
  return measurement;
}

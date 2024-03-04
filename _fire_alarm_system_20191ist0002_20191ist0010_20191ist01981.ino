//Fire Alarm System 20191IST0002,20191IST0010,20191IST0198
float temp;
float vo;
float vo1;
int gas_sensor;

int buz=7;

void setup(){
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(buz,OUTPUT);
Serial.begin(9600);
}

void loop(){
vo=analogRead(A1);
//Convert the raw data value(0 - 1023) to voltage(0.0V - 5.0V)
vo1=vo*(5.0/1023.0);
//conert voltage value to temperature in celcius
temp=100.0*vo1-50.0;
gas_sensor=analogRead(A0);
if(temp>=80){
  
  digitalWrite(buz,HIGH);
}
else{
  
  digitalWrite(buz,LOW);
}
if(gas_sensor>=200){
  
  digitalWrite(buz,HIGH);
}
else{
 
  digitalWrite(buz,LOW);
}
Serial.print("temperature in C =");
Serial.print(" ");
Serial.print(temp);
Serial.print(" ");
Serial.print("Gas Sensor =");
Serial.print(" ");
Serial.print(gas_sensor);
Serial.println();
delay(500);
}
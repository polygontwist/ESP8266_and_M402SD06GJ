/* 
 ESP GPIO04 (D2) (Serial1 TX) -> VFD_19 RXD
  	
*/ 
 
#include <ESP8266WiFi.h>

void setup() {
  WiFi.mode(WIFI_OFF);//WIFI aus
 
  Serial.begin(115200);//DEBUG
  Serial.println("");
  Serial.println("ready.");
  
  Serial1.begin(15625, SERIAL_8N1);//VFD 1xStartbit,8xDatenbit,1xstopbit
 
  delay(1000);
  
  VFD_reset();
  VFD_Mode(true);
  VFD_Cursor(false);
  VFD_dim(4);
  VFD_setCursor(1,0);

  VFD_writeText("hallo");

  VFD_setCursor(5,1);
  
  VFD_writeText("ESP8266");

  VFD_setCursor(36,1);
  VFD_writeData(0xa9);
  VFD_writeData(0xf3);
  VFD_writeData(0xaa);

  Serial.println("go");
}

byte counter=0;
void loop() {
  counter++;
  VFD_setCursor(10,0);
  if(counter<10)VFD_writeText(" ");
  if(counter<100)VFD_writeText(" ");
  VFD_writeText(String(counter));
  delay(100);
}


//----VFD----

void VFD_writeText(String s){
  for(byte i=0; i<s.length(); i++){  
     char chr=s;
     Serial1.write(chr);
     delay(1);
  }
}

void VFD_writeData(uint8_t wert){
 Serial1.write(wert);
 delay(1);//ms (-min 20us)
} 

void VFD_reset(){
	VFD_writeData(0x1F);
}

void VFD_dim(uint8_t stufe){
	uint8_t out=0x20;		//20%
	if(stufe==2)out=0x40;	//40%
	if(stufe==3)out=0x60;	//60%
	if(stufe==4)out=0xff;	//100%
	VFD_writeData(0x04);	//Dimm
	VFD_writeData(out);	
}

void VFD_Cursor(bool an){
	if(an){
		VFD_writeData(0x13);//DC3: Cursor on 
	}
	else{
		VFD_writeData(0x14);//DC4: Cursor off 
	}
}
void VFD_Mode(bool isnormal){
	if(isnormal){
		VFD_writeData(0x11);//DC1: Normal Display Mode
	}
	else{
		VFD_writeData(0x12);//DC2: Vertical Scroll Mode 
	}
}

void VFD_setCursor(uint8_t x,uint8_t y){
	if(x<0)x=0;
	if(x>39)x=39;
	if(y<0)y=0;
	if(y>1)y=1;
    
	uint8_t pos=x+y*0x28;
	VFD_writeData(0x10);
	VFD_writeData(pos);
}

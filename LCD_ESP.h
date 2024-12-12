#include <LCDI2C_Multilingual.h>

LCDI2C_Latin_Symbols lcd(0x27, 20, 4); 

void lcdPrint2(String s1)
{
 char c;
 byte d;
 for (int a=0; a<s1.length(); a++)
  {
   c=s1.charAt(a);
   d=(byte)c;
   if      (d==161) d=1;
   else if (d==169) d=2;
   else if (d==173) d=3;
   else if (d==179) d=4;
   else if (d==186) d=5;
   else if (d==177) d=238;
   else if (d==129) d=6;   //sustituye porque solo hay campo para 7 definiciones, y no alcanza para las mayúsculas
   else if (d==137) d=7;
   else if (d==141) d=3;
   else if (d==147) d=4;
   else if (d==154) d=5;
   else if (d==145) d=8;
   else if (d==188) d=245;
   else if (d==156) d=245;
 
    
   if (d!=195) {
   lcd.write(d);
   
   }
   
   
  } 
 }//lcdPrint2(String s1)

void lcdCreateChar(char cod, const char *cpm)
{
 byte c[8];
 for (byte a=0; a<8; a++)
  {
   c[a]=pgm_read_byte_near(cpm+a);
  } 
 lcd.createChar(cod,c);
}

 // á a con tilde
char const lcdDibA[8] PROGMEM = 
 {
  B00010,
  B00100,
  B01110,
  B00001,
  B01111,
  B10001,
  B01111,
  B00000
 };
 // é e con tilde
char const lcdDibE[8] PROGMEM =
 {
  B00001,
  B00010,
  B01110,
  B10001,
  B11111,
  B10000,
  B01110,
  B00000 
 };

 // í i con tilde
char const lcdDibI[8] PROGMEM =
 {
  B00010,
  B00100,
  B00000,
  B01100,
  B00100,
  B00100,
  B01110,
  B00000  
 };
  
  // ó o con tilde
char const lcdDibO[8] PROGMEM =
 {
  B00010,
  B00100,
  B00000,
  B01110,
  B10001,
  B10001,
  B01110,
  B00000
 };
 
 // ú u con tilde
char const lcdDibU[8] PROGMEM =
 {
  B00010,
  B00100,
  B10001,
  B10001,
  B10001,
  B10011,
  B01101,
  B00000
 };
 char const lcdDicA[8] PROGMEM =
 {
  B00010,
  B00100,
  B01110,
  B10001,
  B10001,
  B11111,
  B10001,
  B00000
 };
 char const lcdDicE[8] PROGMEM =
 {
  B00010,
   B00100,
   B11111,
   B10000,
   B11110,
   B10000,
   B11111,
   B00000
 };
 char const lcdDicN[8] PROGMEM =
 {
  
   B01110,
   B00000,
   B10001,
   B11001,
   B10101,
   B10011,
   B10001,
   B00000
 };
 //ya hay ñ (enne) hecha
 
/*  El LCD no soporta mas que 8 definiciones. No alcanza para las mayúsculas, pero son estas.......
 // Á
 byte A2[8] = 
 {
  B00010,
  B00100,
  B01110,
  B10001,
  B10001,
  B11111,
  B10001,
  B10001
 };
  
 // É
 byte E2[8] = 
  {
   B00010,
   B00100,
   B00000,
   B11111,
   B10000,
   B11110,
   B10000,
   B11111
  };
  
 // Í
 byte I2[8] = 
  {
   B00010,
   B00100,
   B00000,
   B01110,
   B00100,
   B00100,
   B00100,
   B01110
  };
 // Ó
 byte O2[8] = 
  { 
   B00010,
   B00100,
   B00000,
   B01110,
   B10001,
   B10001,
   B10001,
   B01110
  };
 // U
 byte U2[8] = 
  { 
   B00010,
   B00100,
   B10001,
   B10001,
   B10001,
   B10001,
   B10001,
   B01110
  };

 // Ñ
 byte N2[8] = 
  {
   B01101,
   B10010,
   B00000,
   B10001,
   B11001,
   B10101,
   B10011,
   B10001
  };*/

void lcdIni()
{
 

 lcdCreateChar(1, lcdDibA);
 lcdCreateChar(2, lcdDibE);
 lcdCreateChar(3, lcdDibI);
 lcdCreateChar(4, lcdDibO);
 lcdCreateChar(5, lcdDibU);
 lcdCreateChar(6, lcdDicA);
 lcdCreateChar(7, lcdDicE);
 lcdCreateChar(8, lcdDicN);
    //6 sería 'ñ', pero ya está en la 238
}//lcdIni()

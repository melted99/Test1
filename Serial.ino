
//Define Pinouts
#define SC_L   3
#define SDIN   4
// SDOUT pin grounded 
#define C_S    5


/********INITIAL FUNCTIONS******/
void command(unsigned char ins){
//  digitalWrite(C_S, HIGH);
//  delay(10);
  int a;
  digitalWrite(C_S,LOW);
  delay(10);
  digitalWrite(SC_L,LOW);
  delay(10);
  digitalWrite(SDIN, LOW);        //RS = 0 >> Command
  delay(10);
  digitalWrite(SC_L, HIGH);        //RS Registered
  delay(10);
  digitalWrite(SC_L, LOW);
  delay(10);
  digitalWrite(SDIN, LOW);        // RW = 0 = Write
  delay(10);
  digitalWrite(SC_L, HIGH);        // LATCH
  delay(10);
  digitalWrite(SC_L, LOW);
  delay(10);
  for (a =0; a<8 ; a++){
    if((ins&0x80) == 0x80){
    digitalWrite(SDIN, HIGH);
    delay(10);
    }else{
    digitalWrite(SDIN, LOW);
    delay(10);
    }
    ins = (ins<<1);
    digitalWrite(SC_L, LOW);
    delay(10);
    digitalWrite(SC_L, HIGH);
    delay(10);
    digitalWrite(SC_L, LOW);
    delay(10);
  }
  digitalWrite(C_S, HIGH);
  delay(10);
}
void dataInit(){                    //Start of Data Set
//  digitalWrite(C_S, HIGH);
//  delay(10);
  digitalWrite(C_S,LOW);
  delay(10);
  digitalWrite(SC_L,LOW);
  delay(10);
  digitalWrite(SDIN, HIGH);        //RS = 1 >> DATA
  delay(10);
  digitalWrite(SC_L, HIGH);         //LATCH
  delay(10);
  digitalWrite(SC_L, LOW);
  delay(10);
  digitalWrite(SDIN, LOW);         // RW = 0 = Write
  delay(10);
  digitalWrite(SC_L, HIGH);         // LATCH
  delay(10);
  digitalWrite(SC_L, LOW);
  delay(10);
}

void data(unsigned char a){       //Continuous Data Set
  for (int i = 0x80; i; i>>=1){
    if((a&0x80) == 0x80){
    digitalWrite(SDIN, HIGH);
    delay(10);
    }else{
    digitalWrite(SDIN, LOW);
    delay(10);
    }
    a = (a<<1);
    digitalWrite(SC_L, LOW);        // Clock 
    delay(10);
    digitalWrite(SC_L, HIGH);
    delay(10);
    digitalWrite(SC_L, LOW);        // End Clock
    delay(10);
  }
}
/**************INITIALIZIATION**********/
void init1(){
  command(0x38);                // Function
  delay(30);
  command(0x38);                // Function
  delay(30);
  command(0x06);                // Entry mode
  delay(30);
  command(0x02);                // Go home
  delay(30);
  command(0x01);                // Clear
  delay(30);
  command(0x0F);                //Display on
  delay(30);
  command(0x80);                //head to line one char 1
  delay(30);
}
void setup() {
  DDRD = 0xFF; // port D as output
  init1(); 
  delay(2000);
 // digitalWrite(C_S, HIGH);
 // delay(10);
   /******************** TEST CODE *****************/
  command(0x80);
  delay(10);
//  char x = 0x21;
//  dataInit();
//  delay(10);
//  for( int i = 0; i < 20; i++){
//    delay(10);
//    data(x++);
//    delay(10);  
//  }
//  delay(10000);
}

void loop() {
 
   /*char x = 0x21;
   int i;
   digitalWrite(C_S, HIGH);
   
  while(1){
    
    digitalWrite(C_S, HIGH);
    delay(10);
    command(0x80);              // Line 1
    delay(10);
    dataInit();
    for( i= 0; i < 20; i++){
      data(x++);
          delay(10);
    }
    digitalWrite(C_S, HIGH);
    delay(10);
    command(0xc0);                //Line 2
    delay(10);
    dataInit();
    for( i= 0; i < 20; i++){
      data(x++);
      delay(10);
    }
    digitalWrite(C_S, HIGH);
    delay(10);
    command(0x94);              //Line 3
    delay(10);
    dataInit();
    for(i= 0; i < 20; i++){
      data(x++);
      delay(10);
    }
    digitalWrite(C_S, HIGH);
    delay(10);
    command(0xd4);              //Line 4
    delay(10);
  
    dataInit();
    for( i= 0; i < 20; i++){
      data(x++);
      delay(10);
    }
    digitalWrite(C_S, HIGH);
  
  delay(2500);
  }*/
  
 delay(10000);
}

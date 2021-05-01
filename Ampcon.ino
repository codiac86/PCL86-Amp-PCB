   
//               ATTINY 85 VALVE AMP CONTROLLER 
//    For use with 19/20 volt 4amp laptop power supplies and
//    PCL86 valves requiring approx 13 volts for the filament
//    supply. Has soft start and excess valve current shutdown
//    with audible alert. Program the 85 chip for 8 MHz clock.
// ** insert value for a = 176 for 19v supply, 168 for 20v supply **
   
    int a = 176; // Max pulsewith after s.start delay
    int b = 448; // approx = 6.5v shutdown voltage    
    int pw = 0;
void setup(){
  DDRB = 18; //Sets Pin1 & Pin4 as Outputs
  PORTB = 0; //Sets Outputs LOW
  analogWrite(0,0);} //Sets pulsewidth to zero
void loop(){
  if(analogRead(A1) > b || analogRead(A3) > b)
  {analogWrite(0,0); PORTB = 16; delay(100); shutdown();}
  if(pw < a){pw++;} analogWrite(0,pw); delay(5);}
void shutdown(){ 
  for(int x = 0; x < 200; x++)
  {PORTB = PORTB ^ 2; delayMicroseconds(63);} 
  delay (20);shutdown();}  

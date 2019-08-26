#define CENTRE 140//Value of PWM signal when transmitter stick is at its mean position
#define ERR 6//error parameter for motion of stick

#include<Servo.h>
Servo m1,m2,m3,m4;
void setup() {
  // put your setup code here, to run once:
  
 pinMode(2,INPUT);//Channel_1
 pinMode(3,INPUT);//Channel_2
 pinMode(4,INPUT);//Channel_3
 pinMode(5,INPUT);//Channel_4
 
  Serial.begin(9600);
  m1.attach(8);//Attach ESC m1 to port 8 on arduino board
  delay(1);
  m2.attach(9);//Attach ESC m2 to port 9 on arduino board
  delay(1);
  m3.attach(10);//Attach ESC m3 to port 10 on arduino board
  delay(1);
  m4.attach(11);//Attach ESC m4 to port 11 on arduino board
  delay(1);
  
  m1.write(10);
  m2.write(10);
  m3.write(10);
  m4.write(10);
  delay(5000);
  
}

void loop() {
  // repeatedly take input from reciever:
 double m1_in = pulseIn(2,HIGH);
 constrain(m1_in,995,1986);


  double m2_in = pulseIn(3,HIGH);
 constrain(m2_in,995,1986);
  

  double m3_in = pulseIn(4,HIGH); 
 constrain(m3_in,995,1986);

  double m4_in = pulseIn(5,HIGH);
 constrain(m4_in,995,1986);
 



  //ESC's only support values upto 180
   m1_in= map(m1_in,995,1986,110,170);
   m2_in= map(m2_in,995,1986,110,170);
   m3_in= map(m3_in,995,1986,110,170);
   m4_in= map(m4_in,995,1986,110,170);
 

          m1.write(110);
          m2.write(110);
          m3.write(110);
          m4.write(110);

      double m1_write;
      double m2_write;
      double m3_write;
      double m4_write;
      

if(m3_in<=112&&m4_in<=112)
{
            //delay(1000);

                    while(!(m1_in<=112&&m2_in<=112))
                  {

                        m1_write=m3_in+5;
                        m2_write=m3_in+5;
                        m3_write=m3_in+5;
                        m4_write=m3_in+5;

                        
                        if(m1_write>=170)
                        m1_write=170;
                         if(m2_write>=170)
                        m2_write=170;
                         if(m3_write>=170)
                        m3_write=170;
                         if(m4_write>=170)
                        m4_write=170;
                          
                            m1.write(m1_write);
                            m3.write(m3_write);
                            m4.write(m4_write);
                            m2.write(m2_write);
                                //ASSUMING THAT CENTER VALUE OF EACH STICK ARE SAME
                           if(abs(CENTRE-m1_in)>=ERR&&abs(CENTRE-m2_in)<ERR)
                           {
                              if(m1_in-CENTRE>=ERR)
                              {
                                //DECREASE SPEED OF MOTOR 1 AND 4 WHILE 2 AND 3 KEPT UNCHANGED
                          
                                 
                                m1.write(m1_write-abs(CENTRE-m1_in));
                                m4.write(m4_write-abs(CENTRE-m1_in));
                                taketime();
                                m1.write(m1_write);
                                m4.write(m4_write);
                              }
                          
                              else if(CENTRE-m1_in>=ERR)
                              {
                          
                                //DECREASE SPEED OF MOTOR 2 AND 3 WHILE 1 AND 4 KEPT UNCHANGED
                          
                                m2.write(m2_write-abs(CENTRE-m1_in));
                                m3.write(m3_write-abs(CENTRE-m1_in));
                                taketime();
                                m3.write(m3_write);
                                m2.write(m2_write);
                                
                              }
                              
                           }
                          
                          
                           else if(abs(CENTRE-m2_in)>=ERR&&abs(CENTRE-m1_in)<ERR)
                           {
                              if(m2_in-CENTRE>=ERR)
                              {
                                //DECREASE SPEED OF MOTOR 1 AND 3 WHILE 2 AND 4 KEPT UNCHANGED
                                m1.write(m1_write-abs(CENTRE-m2_in));
                                m3.write(m3_write-abs(CENTRE-m2_in));
                                taketime();
                                m1.write(m1_write);
                                m3.write(m3_write);
                              }
                          
                              else if(CENTRE-m2_in>=ERR)
                              {
                          
                                //DECREASE SPEED OF MOTOR 2 AND 4 WHILE 1 AND 3 KEPT UNCHANGED
                                m2.write(m2_write-abs(CENTRE-m2_in));
                                m4.write(m4_write-abs(CENTRE-m2_in));
                               taketime();
                                m2.write(m2_write);
                                m4.write(m4_write);
                              }
                              
                           }
                          
                          
                         
                          
                          
                          else if(abs(CENTRE-m4_in)>=ERR)
                           {
                              if(m4_in-CENTRE>=ERR)
                              {
                                //DECREASE SPEED OF MOTOR 1 AND 2 WHILE 3 AND 4 KEPT UNCHANGED
                                m1.write(m1_write-abs(CENTRE-m4_in));
                                m2.write(m2_write-abs(CENTRE-m4_in));
                                   taketime();
                                m1.write(m1_write);
                                m2.write(m2_write);
                              }
                          
                              else if(CENTRE-m4_in>=ERR)
                              {
                          
                                //DECREASE SPEED OF MOTOR 3 AND 4 WHILE 1 AND 2 KEPT UNCHANGED
                                m3.write(m3_write-abs(CENTRE-m4_in));
                                m4.write(m4_write-abs(CENTRE-m4_in));
                                      taketime();
                                m3.write(m3_write);
                                m4.write(m4_write);
                              }
                              
                           }



                             m1_in = pulseIn(2,HIGH);
                            constrain(m1_in,995,1986);
                  
                  
                            m2_in = pulseIn(3,HIGH);
                            constrain(m2_in,995,1986);
                    
                  
                            m3_in = pulseIn(4,HIGH); 
                            constrain(m3_in,995,1986);
                  
                           m4_in = pulseIn(5,HIGH);
                            constrain(m4_in,995,1986);
                   
                  
                  

                  
                  
                           m1_in= map(m1_in,995,1986,110,170);
                           m2_in= map(m2_in,995,1986,110,170);
                           m3_in= map(m3_in,995,1986,110,170);
                           m4_in= map(m4_in,995,1986,110,170);
                           Serial.print(m1_in   );
                           Serial.print(m2_in   );
                           Serial.print(m3_in  );
                           Serial.print(m4_in   );
                           Serial.println("");


                                             if(m1_in<=112&&m2_in<=112){
                                              int timer=0;
                                              
                                              while(1)
                                              {
                                                timer++;
                                                m1_in=pulseIn(3,HIGH);
                                                m2_in=pulseIn(4,HIGH);
                                            
                                                Serial.println(timer);
                                                if(timer>=20)
                                                break;
                                              }
                                              break;
                                              
                                             }
                                   
                  }



          m1.write(110);
          m2.write(110);
          m3.write(110);
          m4.write(110);


}

}


void taketime()
{
  delay(10);
}

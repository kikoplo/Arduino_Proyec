#include <Servo.h>
Servo Motor;
  int valor = 0;// guarda el valor del sensor    
  int aplauso = 0;// guarda la candidad de aplausos   
  int estado_boton = 0;
  int variable = 0;
  void setup()
  {
    Motor.attach(10);//motor conectado en el puerto 10  
    pinMode(3,OUTPUT);
    Motor.attach(10);  
    pinMode(2, INPUT_PULLUP); 
    pinMode(4,INPUT);
  
  }
 
  void loop(){
    estado_boton=digitalRead(4);

    if(estado_boton == HIGH){

            variable =! variable;
            delay (10);
    }
        // leemos el valor del sensor y lo guardamos
       if (variable == HIGH){ 
        valor = digitalRead(2);
   
        // Si es la primera palmada que estamos dando
       if (valor == HIGH){
          Motor.write(180);//abrimos las cortinas
          digitalWrite(3,LOW);
        
          aplauso = aplauso + 1; // Se incrementa una unidad la variable aplauso
      
          delay(100); // Retardo que evita rebotes del sensor
    }
 
        // Si es la segunda palmada que estamos dando
          if (aplauso == 2){
      
           Motor.write(90);//cerramos las cortinas
            
           aplauso = aplauso + 1; // Se inicializa el contador de aplausos
      
            delay(100);
    }
          if (aplauso == 4)
    {
          digitalWrite(3, HIGH);
        
          aplauso = aplauso + 1;
      
          delay(100);
    }
         if (aplauso == 6){
      
          digitalWrite(3,LOW);
      
          aplauso = 0;
     
          delay(100);
    }
       }
       else{
        
        digitalWrite(3,LOW);
        
        Motor.write(0); 
        
        delay(10);
        
        aplauso = 0;
       }
  }
       
 

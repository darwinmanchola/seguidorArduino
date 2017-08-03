

int sensorI=2;
int sensorD =4; 

int M1_Izq = 12; //Direccion
int M1_Derecha = 11; //Direccion

int M2_Izq = 9; //Direccion
int M2_Derecha = 8; //Direccion

int espera=50;

void setup() {
  //Serial.begin(9600);
  pinMode(sensorI,INPUT);
  pinMode(sensorD,INPUT);
  pinMode(M1_Izq, OUTPUT);
  pinMode(M1_Derecha, OUTPUT);
  pinMode(M2_Izq, OUTPUT);
  pinMode(M2_Derecha, OUTPUT);
}

void loop() {
  parar();
  int sensorIValue = digitalRead(sensorI);
  int sensorDValue = digitalRead(sensorD);
  delay(50);
  
  if(sensorIValue==0 && sensorDValue==0)
  {
   // Serial.println("avanzar");
    parar();
    avanzar();
    delay(espera);
    
  }
  else if(sensorIValue==1 && sensorDValue==0)
  {
    //Serial.println("a la izquierda");
    parar();
    izquierda();
    delay(espera/2);
  }
  else if(sensorIValue==0 && sensorDValue==1)
  {
    //Serial.println("a la derecha");
    parar();
    derecha(); 
    delay(espera/2);
  }
  else
  {
    //Serial.println("parar");
    parar();

    delay(espera);
  }
  
}


void avanzar()
{
    digitalWrite(M1_Izq, HIGH);
    digitalWrite(M1_Derecha, LOW);
    digitalWrite(M2_Izq, HIGH);
    digitalWrite(M2_Derecha, LOW);
}
void derecha()
{
    digitalWrite(M1_Izq, HIGH);
    digitalWrite(M1_Derecha, LOW);
    digitalWrite(M2_Izq, HIGH);
    digitalWrite(M2_Derecha, HIGH);
}

void izquierda()
{
    digitalWrite(M1_Izq, HIGH);
    digitalWrite(M1_Derecha, HIGH);
    digitalWrite(M2_Izq, HIGH);
    digitalWrite(M2_Derecha, LOW);
}
void parar(){
    digitalWrite(M1_Izq, HIGH);
    digitalWrite(M1_Derecha, HIGH);
    digitalWrite(M2_Izq, HIGH);
    digitalWrite(M2_Derecha, HIGH);
}


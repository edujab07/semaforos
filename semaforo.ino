//leds
const int r_1 = 2;
const int y_1 = 3;
const int g_1 = 4;
const int r_2 = 5;
const int y_2 = 6;
const int g_2 = 7;

//button
const int button = 9;
int b = 0;


void setup() 
{

pinMode(r_1, OUTPUT);
pinMode(y_1, OUTPUT);
pinMode(g_1, OUTPUT);

pinMode(r_2, OUTPUT);
pinMode(y_2, OUTPUT);
pinMode(g_2, OUTPUT);
pinMode(button, INPUT);
}

void stop()
{
    //INTERMITENCIA AL MANTENER PRESIONADO BOTON
  digitalWrite(r_1, LOW);
  digitalWrite(g_1, LOW);
   digitalWrite(r_2, LOW);
  digitalWrite(g_2, LOW);
  digitalWrite(y_1, HIGH);
  digitalWrite(y_2, HIGH);
  delay(700);
  digitalWrite(y_1, LOW);
  digitalWrite(y_2, LOW);
  delay(700);

}

void ciclo_1()
{
  //rojo sem_1
  digitalWrite(r_1, HIGH);
  digitalWrite(y_1, LOW);
  digitalWrite(g_1, LOW);

 //tiempo para evitar accidentes
  delay(1000);

  //verde sem_2
  digitalWrite(r_2, LOW);
  digitalWrite(y_2, LOW);
  digitalWrite(g_2, HIGH);


}

void ciclo_2()
{

  //Parpadeo sem_2
delay(4000);
  
  digitalWrite(g_2, LOW);
  delay(1000);
  digitalWrite(g_2, HIGH);
  delay(1000);

  digitalWrite(g_2, LOW);
  delay(1000);
  digitalWrite(g_2, HIGH);
  delay(1000);

}

void ciclo_3()
{

//sem_2 en amarillo a rojo
digitalWrite(r_2, LOW);
digitalWrite(y_2, HIGH);
digitalWrite(g_2, LOW);
delay(1500);

digitalWrite(r_2, HIGH);
digitalWrite(y_2, LOW);
digitalWrite(g_2, LOW);
//tiempo para evitar accidentes 
delay(1000);



}

void ciclo_4()
{
//cambio sem_1 a verde

digitalWrite(r_1, LOW);
digitalWrite(y_1, LOW);
digitalWrite(g_1, HIGH);
delay(4000);

//parpadeo sem_1
digitalWrite(g_1, LOW);
delay(1000);
digitalWrite(g_1, HIGH);
delay(1000);
digitalWrite(g_1, LOW);
delay(1000);
digitalWrite(g_1, HIGH);
delay(1000);

//Amarillo sem_1
digitalWrite(r_1, LOW);
digitalWrite(y_1, HIGH);
digitalWrite(g_1, LOW);
delay(1500);

}




void loop() 
{
b = digitalRead(button);
if(b==HIGH)
{
stop();
}

else{
  ciclo_1();
  ciclo_2();
  ciclo_3();
  ciclo_4();
}

}

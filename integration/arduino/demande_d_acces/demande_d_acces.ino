#define PIN_LED1 11 //le numéro de la broche sur laquelle la lampe 1  est branchée
//(par défaut intégrée dans la carte) est branchée 
const int btnPin  = A0; 
int btnVal  = 0; 
char data; // variable contenant le caractère lu




void setup() {
  // Configure la broche 11 sur laquelle est reliée notre LED  en sortie
  pinMode(PIN_LED1,OUTPUT);
//La LED reliée à la broche 11 est intialisé à l'état LOW
  digitalWrite(PIN_LED1,LOW);

pinMode(btnPin,INPUT_PULLUP);
  

  Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 


}



void loop() {
 if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='0') //si le caractère lu est égale à 1
     {
      digitalWrite(PIN_LED1,HIGH); 
      delay(1000);// alumer la lampe 
      Serial.write('0');}
      if(data=='3') //si le caractère lu est égale à 1
     {
      digitalWrite(PIN_LED1,LOW); // alumer la lampe 
      Serial.write('3');//envoyer le nouvel état de la lampe 
     }
     } 
     
   
  ////Read pushbutton 
  btnVal=analogRead(btnPin); 
  //Serial.print(btnVal); 
    if(btnVal<200)
  { 
    Serial.println("1"); //bouton appuiye
  }
  else
  { 
    Serial.println("2"); 
  } 
  
  delay(100);
 

}

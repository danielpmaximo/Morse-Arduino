int led = 9;
String str;
int delay_letra = 0;

#define DOT_DELAY 300

#define DASH_DELAY 3 * DOT_DELAY

#define IN_LETTER_SPACE_DELAY DOT_DELAY
#define OUT_LETTER_SPACE_DELAY 3 * DOT_DELAY
#define WORD_SPACE_DELAY 7 * DOT_DELAY

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    str = Serial.readString();
  for(int i=0; i<25;i++){
    if(str[i] == '.'){
      delay_letra = DOT_DELAY;
        digitalWrite(led, HIGH);
        delay(delay_letra);
        digitalWrite(led, LOW);
        delay(IN_LETTER_SPACE_DELAY);
      }
    else if(str[i] == '-'){
      delay_letra = DASH_DELAY;
        digitalWrite(led, HIGH);
        delay(delay_letra);
        digitalWrite(led, LOW);
        delay(IN_LETTER_SPACE_DELAY);
      }
    else if(str[i] == ' '){
       delay_letra = WORD_SPACE_DELAY;
         digitalWrite(led, HIGH);
        delay(delay_letra);
        digitalWrite(led, LOW);
        delay(IN_LETTER_SPACE_DELAY); 
       }
    else if(str[i] == '\0'){
       delay_letra = WORD_SPACE_DELAY;
          digitalWrite(led, LOW);
          delay(delay_letra);
       }
}
  }
  
}

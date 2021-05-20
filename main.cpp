
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int upButton = 10;
int downButton = 9;
int selectButton = 8;

int menu = 1;

int LED = 6;


void setup() {
  lcd.begin(16, 2);

  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  
  pinMode(LED, OUTPUT);

  updateMenu();
}


void loop() {
  if (!digitalRead(downButton)) {
    menu++;
    updateMenu();
    delay(150);
    while (!digitalRead(downButton));
  }

  if (!digitalRead(upButton)) {
    menu--;
    updateMenu();
    delay(150);
    while (!digitalRead(upButton));
  }

  if (!digitalRead(selectButton)) {
    execute();
    updateMenu();
    delay(150);
    while (!digitalRead(selectButton));
  }	
}

//Menu

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">ON LED");
      lcd.setCursor(0, 1);
      lcd.print(" OFF LED");
      break;
    case 2:
      lcd.clear();
      lcd.print(" ON LED");
      lcd.setCursor(0, 1);
      lcd.print(">OFF LED");
      break;
    case 3:
      lcd.clear();
      lcd.print(">Desvanecido");
      lcd.setCursor(0, 1);
      lcd.print(" Intermitente");
      break;
    case 4:
      lcd.clear();
      lcd.print(" Desvanecido");
      lcd.setCursor(0, 1);
      lcd.print(">Intermitente");
      break;
    case 5:
      menu = 4;
      break;
  }
}


// Ejecucion
void execute() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
     case 4:
      action4();
      break;
  }
}


// Acciones

void action1() {
  lcd.clear();
  lcd.print(">LED ON");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  
  digitalWrite(LED, HIGH);
  
  delay(500);
}

void action2() {
  lcd.clear();
  lcd.print(">LED OFF");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  
  digitalWrite(LED, LOW);
  
  delay(500);
}

void action3() {
  lcd.clear();
  lcd.print(">Desavecido");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  funcDesva(2);
  delay(1500);
  
}

  void action4() {
  lcd.clear();
  lcd.print(">Intermitente");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  intermitente();
  delay(1500);
}


void funcDesva(int temp){
  int periodo = temp;
  unsigned long tiempo1 = 0;
  unsigned long tiempo2 = 0;
  int brillo;
  for(brillo = 0; brillo <= 255; brillo++){
    analogWrite(LED,brillo);
    tiempo1 = millis();
    while (millis() < tiempo1 + periodo){
    }
  }
  for(brillo = 255; brillo >= 0; brillo-- ){
    analogWrite(LED,brillo);
    tiempo2 = millis();
    while (millis() < tiempo2 + periodo){
    }

  }

  
}



void intermitente(){
  digitalWrite(LED,HIGH);
  delay(350);
  digitalWrite(LED,LOW);
  delay(350);
  digitalWrite(LED,HIGH);
  delay(350);
  digitalWrite(LED,LOW);
  delay(350);
}
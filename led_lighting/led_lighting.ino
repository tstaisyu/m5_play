// 赤色LEDをGPIOピン番号25に接続
// 黄色LEDをGPIOピン番号26に接続
// 青色LEDをGPIOピン番号27に接続

#include <M5Stack.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// LEDピンの設定
const int pinRed = 25;
const int pinYellow = 26;
const int pinBlue = 27;

void setup() {
  M5.begin();
  SerialBT.begin("M5Stack"); // Bluetoothデバイス名を設定

  // LEDピンを出力として設定
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinBlue, OUTPUT);

  // すべてのLEDをオフに設定
  digitalWrite(pinRed, LOW);
  digitalWrite(pinYellow, LOW);
  digitalWrite(pinBlue, LOW);
}

void loop() {
  if (SerialBT.available()) {
    String command = SerialBT.readStringUntil('\n'); // 改行まで読み取る
    command.trim(); // 余分な空白を削除

    // すべてのLEDをオフにする
    digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinBlue, LOW);

    // 受信したコマンドに応じてLEDを制御
    if (command == "あか") {
      digitalWrite(pinRed, HIGH);
    } else if (command == "きいろ") {
      digitalWrite(pinYellow, HIGH);
    } else if (command == "あお") {
      digitalWrite(pinBlue, HIGH);
    }
  }
}



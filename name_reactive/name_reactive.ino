#include <M5Stack.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// 円弧を描画する関数の定義
void drawArc(int x, int y, int radius, int startAngle, int endAngle, uint16_t color) {
  for (int angle = startAngle; angle < endAngle; angle++) {
    float rad = angle * (PI / 180.0);
    int xPoint = x + radius * cos(rad);
    int yPoint = y + radius * sin(rad);
    M5.Lcd.drawPixel(xPoint, yPoint, color);
  }
}

// 笑顔を描画する関数の更新版
void drawSmileyFace() {
  M5.Lcd.fillScreen(BLACK); // 背景を黒に設定
  M5.Lcd.setTextColor(WHITE); // 文字色を白に設定
  
  // 目を描画（半円の上半分）
  M5.Lcd.fillCircle(120 - 40, 120 - 20, 10, WHITE); // 左目
  M5.Lcd.fillCircle(120 + 40, 120 - 20, 10, WHITE); // 右目

  // 口を描画（円弧の近似）
  drawArc(120, 160, 40, 0, 180, WHITE); // 口
}


void setup() {
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(50, 100);
  M5.Lcd.println("あなたのお名前は？");

  delay(3000); // ここで音声入力を待つ（仮想）

  // 仮に名前を "Yamada" とする（音声認識の結果を受け取る部分を想定）
  String name = "Yamada";
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(50, 100);
  M5.Lcd.println("Hello, " + name + "!");
  
  delay(3000); // 3秒待ってから笑顔を表示
  drawSmileyFace();
}

void loop() {
  // Bluetooth経由で名前の文字列を受信する
  if (SerialBT.available()) {
    String name = SerialBT.readStringUntil('\n'); // 改行まで読み取る
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(50, 100);
    M5.Lcd.println("Hello, " + name + "!");
    
    delay(3000); // 名前を表示した後、3秒待つ
    drawSmileyFace(); // 笑顔を表示
    delay(3000); // 笑顔を表示した後、さらに3秒待つ
  }
}

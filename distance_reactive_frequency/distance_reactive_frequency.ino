// 回路接続
// VCC: HC-SR04 の VCC を M5Stack の 5V に接続します。
// Trig: HC-SR04 の Trig ピンを M5Stack の GPIO です（例: GPIO 26）に接続します。
// Echo: HC-SR04 の Echo ピンを M5Stack の GPIO に接続します（例: GPIO 36）。
// GND: HC-SR04 の GND を M5Stack の GND に接続します。


#include <M5Stack.h>

// HC-SR04のピン設定
const int trigPin = 26;
const int echoPin = 36;

// 距離計測関数
long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  M5.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  M5.Speaker.begin();
}

void loop() {
  long distance = measureDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  // 障害物までの距離に応じてビープ音のピッチを変更
  if (distance > 0) {
    int pitch = map(distance, 0, 400, 2000, 100); // 距離が近いほどピッチが高くなる
    M5.Speaker.tone(pitch, 100); // ビープ音を鳴らす
  } else {
    // 距離が測定できない場合はビープ音を鳴らさない
    M5.Speaker.mute();
  }

  delay(100); // 100ミリ秒待機
}

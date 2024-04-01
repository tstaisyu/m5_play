#include <M5Stack.h>

// モードを表す変数
int mode = 0;

void setup() {
  M5.begin();
  // 各センサやデバイスの初期化処理をここに記述
}

void loop() {
  M5.update(); // M5Stackのボタン状態の更新

  // ボタンAが押されたらモードを切り替える
  if (M5.BtnA.wasPressed()) {
    mode++;
    if (mode > 2) { // 3つのモードがあるので、それ以上になったら0に戻る
      mode = 0;
    }
    // 画面のクリア
    M5.Lcd.fillScreen(BLACK);
  }

  // 現在のモードに応じて処理を実行
  switch (mode) {
    case 0:
      // LEDの音声制御モード
      controlLEDWithVoice();
      break;
    case 1:
      // 超音波センサでの音の変化モード
      changeSoundWithUltrasonic();
      break;
    case 2:
      // 名前を言ったら反応するモード
      respondToName();
      break;
  }
}

void controlLEDWithVoice() {
  // Bluetooth経由で音声認識結果を受信し、LEDを制御するコード
}

void changeSoundWithUltrasonic() {
  // 超音波センサの距離に応じて音を変えるコード
}

void respondToName() {
  // Bluetooth経由で名前を受信し、反応するコード
}

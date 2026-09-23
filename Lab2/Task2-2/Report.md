**`Lab2/Task2-2/report.md`（完整示範報告）**

```markdown
# 課題報告：Advanced Task 2-2 Ultrasonic Sensor Drives Servo Angle

- **學生姓名**：[林語柔]
- **學生學號**：[113511088]
- **完成日期**：2026-09-24

---

### 1. 實驗目標(可參考課程投影片寫法)
- 使用 HC-SR04 超音波感測器量測物體距離。
- 學習利用 `pulseIn()` 取得超音波往返時間，並換算為距離。
- 使用 `map()` 將量測距離轉換為 SG90 伺服馬達的旋轉角度。
- 實現依物體距離即時控制 SG90 Servo Motor 角度之功能。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- HC-SR04 超音波感測器 x 1
- SG90 Servo Motor x 1
- 麵包板（Breadboard） x 1
- 跳線 x 7
- 個人電腦（已安裝 Arduino IDE） x 1

### 3. 操作說明與成果
1. **電路連接**：將 HC-SR04 的 VCC 與 GND 分別接至 Arduino 的 5V 與 GND，TRIG 接至 D7，ECHO 接至 D6；SG90 的訊號線接至 D9，電源與接地分別接至 5V 與 GND。
2. **超音波測距**：程式控制 TRIG 腳送出短暫的 HIGH 訊號，使 HC-SR04 發出超音波，並透過 ECHO 腳接收反射訊號。使用 `pulseIn()` 取得超音波往返時間，再換算成物體與感測器之間的距離。
3. **距離轉換角度**：將量測距離限制在 5～30 cm，並使用 `map()` 將距離轉換為 0～180° 的 Servo 角度，例如距離越遠，SG90 的旋轉角度越大。
4. **Servo 控制**：使用 `myservo.write(angle)` 將計算出的角度傳送至 SG90，使伺服馬達依據超音波感測器量測到的距離即時改變角度。
5. **Serial Monitor 觀察**：開啟 Arduino IDE 的 Serial Monitor，將鮑率（Baud rate）設為 9600 baud，可即時觀察目前量測距離與對應的 Servo 角度。
6. **實驗成果**：當物體靠近 HC-SR04 時，量測距離減少，Servo 角度隨之減小；當物體逐漸遠離時，Servo 角度隨距離增加而增大，成功完成以超音波感測距離控制 SG90 旋轉角度之功能。
7. **操作影片**：請參閱同目錄下 `video/Task2-2.mp4` 之實際操作畫面。

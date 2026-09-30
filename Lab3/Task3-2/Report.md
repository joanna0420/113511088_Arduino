**`Lab3/Task3-2/report.md`（完整示範報告）**

```markdown
# 課題報告：Advanced Task 3-2 LED Control with Serial Communication

- **學生姓名**：[林語柔]
- **學生學號**：[113511088]
- **完成日期**：2026-09-30

---

### 1. 實驗目標(可參考課程投影片寫法)
- 使用 C# Windows Forms 建立具有 ON / OFF 按鈕的 GUI。
- 使用 UART Serial Communication 讓電腦與 Arduino 進行資料傳輸。
- 按下 GUI 上的 ON / OFF 按鈕時，透過 Serial Port 傳送控制指令至 Arduino。
- Arduino 根據接收到的指令控制 LED 開啟與關閉。
- 將 Arduino 實體按鈕狀態傳回電腦，並顯示 Button Pressed / Released 狀態。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 麵包板 x 1
- LED x 1
- 220 Ω 或 330 Ω 電阻 x 1
- 按鈕 x 1
- 杜邦線 x 4
- 個人電腦（已安裝 Arduino IDE）
- Visual Studio
- C# Windows Forms App

### 3. 操作說明與成果
1. **燒錄 Arduino 程式**：使用 USB 線連接 Arduino Uno 至電腦，開啟 `Task3-2.ino` 並點擊「上傳」。
2. **建立 C# GUI**：使用 Visual Studio 建立 Windows Forms App，加入 `ON`、`OFF` 兩個按鈕以及 Arduino 狀態顯示文字。
3. **建立 Serial Communication**：C# 與 Arduino 的 Serial Port baud rate 均設定為 **9600 baud**，並使用 Arduino 所對應的 COM Port 建立連線。
4. **測試 LED ON**：按下 GUI 上的 `ON` 按鈕後，C# 傳送字元 `1` 至 Arduino，Arduino 接收到指令後將 LED 點亮。
5. **測試 LED OFF**：按下 GUI 上的 `OFF` 按鈕後，C# 傳送字元 `0` 至 Arduino，Arduino 接收到指令後將 LED 熄滅。
6. **測試 Arduino 按鈕狀態**：按下 Arduino 實體按鈕時，Arduino 傳送 `Button Pressed!` 至 C# GUI；放開按鈕時傳送 `Button Released!`，並更新畫面上的狀態文字。
7. **實驗成果**：成功完成電腦端 C# GUI 與 Arduino 的雙向 Serial Communication，可由 GUI 控制 LED，並由 Arduino 將實體按鈕狀態回傳至電腦顯示。
8. **操作影片**：請參閱同目錄下 `video/Task3-2.mp4` 之實際操作畫面。

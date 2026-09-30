**`Lab3/Task3-2/report.md`（完整示範報告）**

```markdown
# 課題報告：Advanced Task 3-3 HC-05 Wireless LED Control

- **學生姓名**：[林語柔]
- **學生學號**：[113511088]
- **完成日期**：2026-09-30

---

### 1. 實驗目標(可參考課程投影片寫法)
- 使用 HC-05 Bluetooth 模組建立 Arduino 與電腦之間的無線通訊。
- 延續 Advanced Task 3-2 的 C# Windows Forms GUI，使用 ON / OFF 按鈕控制 LED。
- 將原本透過 USB Serial Port 傳輸的控制指令改為透過 Bluetooth COM Port 傳輸。
- Arduino 經由 HC-05 接收電腦端指令，控制 LED 開啟與關閉。
- 將 Arduino 實體按鈕狀態透過 HC-05 回傳至電腦，並在 GUI 顯示 Button Pressed / Released 狀態。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- HC-05 Bluetooth 模組 x 1
- USB Type-B 傳輸線 x 1
- 麵包板 x 1
- LED x 1
- 220 Ω 或 330 Ω 電阻 x 1
- 按鈕 x 1
- 1 kΩ 電阻 x 1
- 2 kΩ 電阻 x 1
- 杜邦線 X 8
- 個人電腦（已安裝 Arduino IDE）
- Visual Studio
- C# Windows Forms App

### 3. 操作說明與成果
1. **連接 HC-05 模組**：將 HC-05 與 Arduino 連接，TXD 接至 Arduino 的 RX 腳位，Arduino 的 TX 訊號經電阻分壓後接至 HC-05 的 RXD，以降低輸入至 HC-05 RXD 的電壓。
2. **燒錄 Arduino 程式**：使用 USB 線連接 Arduino Uno 至電腦，開啟 `Task3-3.ino` 並點擊「上傳」。
3. **配對 HC-05**：於 Windows Bluetooth 設定中搜尋並配對 HC-05，確認系統建立對應的 Bluetooth COM Port。
4. **設定 C# GUI**：延續 Advanced Task 3-2 的 Windows Forms App，保留 `ON`、`OFF` 按鈕以及 Arduino 狀態顯示文字。
5. **建立 Bluetooth Serial Communication**：將 C# Serial Port 改為 HC-05 所對應的 Bluetooth COM Port，baud rate 設定為 **9600 baud**。
6. **測試 LED ON**：按下 GUI 上的 `ON` 按鈕後，C# 透過 Bluetooth 傳送字元 `1` 至 HC-05，Arduino 接收到指令後將 LED 點亮。
7. **測試 LED OFF**：按下 GUI 上的 `OFF` 按鈕後，C# 透過 Bluetooth 傳送字元 `0` 至 HC-05，Arduino 接收到指令後將 LED 熄滅。
8. **測試 Arduino 按鈕狀態**：按下 Arduino 實體按鈕時，Arduino 經由 HC-05 傳送 `Button Pressed!` 至 C# GUI；放開按鈕時傳送 `Button Released!`，並更新畫面上的狀態文字。
9. **實驗成果**：成功完成電腦端 C# GUI 與 Arduino 之間的 Bluetooth 雙向 Serial Communication，可由電腦無線控制 LED，並由 Arduino 將實體按鈕狀態無線回傳至電腦顯示。
10. **操作影片**：請參閱同目錄下 `video/Task3-3.mp4` 之實際操作畫面。

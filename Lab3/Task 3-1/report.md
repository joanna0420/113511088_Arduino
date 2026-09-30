**`Lab3/Task3-1/report.md`（完整示範報告）**

```markdown
# 課題報告：Advanced Task 3-1 Timer Interrupt vs Blocking Delay

- **學生姓名**：[林語柔]
- **學生學號**：[113511088]
- **完成日期**：2026-09-30

---

### 1. 實驗目標(可參考課程投影片寫法)
- 使用 TimerOne 函式庫建立週期性的 Timer Interrupt。
- 比較 Timer Interrupt 與 Blocking Delay 兩種程式執行方式的差異。
- 使用兩組按鈕與 LED，觀察兩種方式對輸入訊號的反應速度。
- 理解 Timer Interrupt 在機器人即時控制系統中的應用方式。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 麵包板 x 1
- 按鈕 x 2
- LED x 2
- 220 Ω 或 330 Ω 電阻 x 2
- 杜邦線 x 7
- 個人電腦（已安裝 Arduino IDE）
- TimerOne Library

### 3. 操作說明與成果
### 3. 操作說明與成果
1. **燒錄程式**：使用 USB 線連接 Arduino Uno 至電腦，開啟 `Task3-1.ino` 並點擊上傳。
2. **測試 Button A**：按下 Button A，TimerOne 每 **50 ms** 觸發一次 Timer Interrupt，並在 `timerISR()` 中讀取按鈕狀態。按下時 LED A 亮起，放開時 LED A 熄滅。
3. **測試 Button B**：按下 Button B，Arduino 於 `loop()` 中讀取按鈕狀態並控制 LED B。由於程式最後加入 `delay(1000)`，LED B 的反應速度較慢。
4. **比較反應速度**：快速按下並放開 Button A 時，LED A 能快速反應；快速按下 Button B 時，可能因 Arduino 正在執行 `delay(1000)` 而未偵測到按鈕輸入。
5. **實驗結果**：Timer Interrupt 不會受到主程式中 Blocking Delay 的直接影響，因此 Button A 的反應明顯比 Button B 快，也較不容易漏掉短暫的輸入訊號。
6. **操作影片**：請參閱同目錄下 `video/Task3-1.mp4` 之實際操作畫面。

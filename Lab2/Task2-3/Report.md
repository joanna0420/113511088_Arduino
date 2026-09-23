**`Lab2/Task2-3/report.md`（完整示範報告）**

```markdown
# 課題報告：Advanced Task 2-3 External Interrupt vs Polling

- **學生姓名**：[林語柔]
- **學生學號**：[113511088]
- **完成日期**：2026-09-24

---

### 1. 實驗目標(可參考課程投影片寫法)
- 學習 Arduino External Interrupt（外部中斷）的基本使用方式。
- 使用 `attachInterrupt()` 與 ISR 函式控制 LED 狀態。
- 學習 Polling（輪詢）方式，利用 `digitalRead()` 持續讀取按鈕狀態。
- 使用 Edge Detection 偵測按鈕由 HIGH 轉為 LOW 的按下瞬間。
- 比較 External Interrupt 與 Polling 在 `delay(2000)` 阻塞情況下的反應差異。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- Push Button 按鈕 x 2
- LED x 2
- 電阻 x 2
- 麵包板（Breadboard） x 1
- 跳線 x 7
- 個人電腦（已安裝 Arduino IDE） x 1

### 3. 操作說明與成果
1. **Button A + LED A 電路**：將 Button A 接至 Arduino D2，LED A 接至數位輸出腳位。Button A 使用 `INPUT_PULLUP`，當按鈕按下時訊號由 HIGH 變為 LOW，產生 FALLING edge。
2. **External Interrupt 控制**：使用 `attachInterrupt()` 設定 D2 為外部中斷輸入。當 Button A 被按下時，Arduino 立即執行 `buttonISR()`，將 `ledStateA` 狀態反轉，使 LED A 在亮與滅之間切換。
3. **Button B + LED B 電路**：加入第二組 Button B 與 LED B。Button B 使用一般數位輸入腳位，LED B 使用另一數位輸出腳位，並透過 Polling 方式進行控制。
4. **Polling 控制**：程式在 `loop()` 中使用 `digitalRead()` 持續讀取 Button B 的目前狀態，並比較目前狀態與前一次狀態。當偵測到按鈕由 HIGH 變為 LOW 時，即判定為一次按下事件，並切換 LED B 狀態。
5. **Edge Detection**：透過比較 `lastButtonB` 與 `currentButtonB`，只有在 `HIGH → LOW` 的瞬間才切換 LED B，避免按住按鈕時重複觸發。
6. **Blocking System 測試**：在 `loop()` 最後加入 `delay(2000)`，使主程式每次暫停 2 秒，此時若快速按下 Button B，Polling 可能因程式正在 delay 而無法偵測到按鍵；Button A 則可透過 External Interrupt 立即觸發 ISR，因此即使主程式處於 delay 狀態仍能控制 LED A。
7. **實驗成果**：Button A 使用 External Interrupt 時反應較即時，即使 `loop()` 被 `delay(2000)` 阻塞仍可偵測按鈕事件；Button B 使用 Polling 時必須等程式執行到 `digitalRead()` 才能讀取按鈕，因此短暫的按鍵事件可能被漏掉。
8. **方法比較**：Polling 是由 Arduino 主動且持續檢查輸入狀態，而 External Interrupt 則是在指定訊號事件發生時自動執行 ISR。對於需要快速反應且不能漏掉的事件，例如緊急停止、碰撞感測或編碼器訊號，External Interrupt 較適合；對於不需要即時反應、只需週期性讀取的感測器，則可使用 Polling。
9. **操作影片**：請參閱同目錄下 `video/Task2-3.mp4` 之實際操作畫面。

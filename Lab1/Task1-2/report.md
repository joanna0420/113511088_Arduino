**`Lab1/Task1-2/report.md`（完整示範報告）**

```markdown
# 課題報告：Task 1-2 RGB LED — Layering Three Inputs

- **學生姓名**：[林語柔]
- **學生學號**：[113511088]
- **完成日期**：2026-09-13

---

### 1. 實驗目標(可參考課程投影片寫法)
- 使用按鈕作為數位輸入，控制 RGB LED 的紅色亮度。
- 使用 Serial Monitor 輸入資料，控制 RGB LED 的綠色亮度。
- 使用可變電阻作為類比輸入，控制 RGB LED 的藍色亮度。
- 將三種輸入方式結合，產生不同的 RGB 顏色。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- RGB LED x 1
- 可變電阻 x 1
- 按鈕 x 1
- 限流電阻 220Ω x 3
- 麵包板 x 1
- Jumper Wires x 12
- 個人電腦（已安裝 Arduino IDE）x 1

### 3. 操作說明與成果
1. **燒錄程式**：使用 USB 線連接 Arduino Uno 至電腦，開啟 `Task1-2.ino` 並點擊「上傳」。
2. **控制 RGB LED**：旋轉可變電阻控制藍色亮度，按下按鈕加入紅色，並透過 Serial Monitor 輸入 `1` 開啟綠色。
3. **實驗成果**：RGB LED 可依不同輸入疊加顏色，由藍色變成紫色，再加入綠色後顯示白色。
4. **操作影片**：請參閱同目錄下 `video/Task1-2.mp4` 之實際操作畫面。

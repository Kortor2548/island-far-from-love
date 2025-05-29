// SnakeGame.h        
#ifndef SNAKE_GAME_H            // ป้องกันไม่ให้ไฟล์นี้ถูก include ซ้ำหลายครั้ง
#define SNAKE_GAME_H

#include <windows.h>            // ใช้สำหรับฟังก์ชันของ Console เช่น SetConsoleCursorPosition
#include <string>               // ใช้จัดการข้อความ เช่น ตัวแปร string
#include <vector>               // ใช้เก็บข้อมูลแบบลิสต์ เช่น พิกัดของตัวงูแต่ละท่อน

// คลาสพื้นฐานที่ใช้เก็บตำแหน่งของวัตถุในเกม (เช่น งู, ผลไม้)
class GameEntity {
protected:
    int x, y;                   // พิกัดตำแหน่งของวัตถุ (แกน X, Y)

public:
    void setPosition(int px, int py) { x = px; y = py; } // กำหนดค่าตำแหน่งเริ่มต้นของวัตถุ
    int getX() const { return x; }                        // ดึงค่าตำแหน่งแกน X ของวัตถุ
    int getY() const { return y; }                        // ดึงค่าตำแหน่งแกน Y ของวัตถุ
};

// คลาสที่สืบทอดจาก GameEntity เพิ่มความสามารถในการเคลื่อนที่
class MovableEntity : public GameEntity {
protected:
    int dx, dy;                 // ทิศทางการเคลื่อนที่ (dx: แนวนอน, dy: แนวตั้ง)

public:
    void move() { x += dx; y += dy; } // อัปเดตตำแหน่งตามทิศทาง dx, dy
    void setDirection(int dxVal, int dyVal) { dx = dxVal; dy = dyVal; } // กำหนดค่าทิศทาง dx และ dy
};

// คลาสหลักของเกมงู สืบทอดคุณสมบัติจาก MovableEntity
class SnakeGame : public MovableEntity {
private:                                   // ส่วนข้อมูลภายในของคลาส (ภายนอกเข้าถึงไม่ได้โดยตรง)
    int width, height;                     // ขนาดสนามของเกม (กว้าง x สูง)
    int fruitX, fruitY;                    // ตำแหน่งของผลไม้ในสนาม
    int score;                             // คะแนนของผู้เล่น
    bool gameOver;                         // สถานะของเกม (true = เกมจบ, false = กำลังเล่น)

    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN }; // ตัวเลือกทิศทางที่งูสามารถเคลื่อนที่ได้
    Direction dir;                          // ทิศทางปัจจุบันของหัวงู

    std::vector<int> xSegments, ySegments;  // ลำดับตำแหน่งของลำตัวงูในแต่ละแกน (เป็นตัวแทนของแต่ละท่อน)

    void gotoxy(int, int);       // ย้ายตำแหน่งเคอร์เซอร์ไปยังตำแหน่ง (x, y) บน Console
    void spawnFruit();           // สุ่มตำแหน่งผลไม้ใหม่ในสนาม
    void draw();                 // วาดสนาม งู และผลไม้ลงบน Console
    void input();                // ตรวจจับการกดแป้นพิมพ์จากผู้เล่น
    void updateSnake();          // ขยับตัวงูแต่ละท่อนให้เคลื่อนไหวตามหัว
    void logic();                // ตรวจสอบเงื่อนไขในเกม เช่น การชนขอบ การชนตัวเอง การกินผลไม้

public:
    SnakeGame();                 // Constructor: เริ่มต้นค่าต่าง ๆ ของเกม เช่น งูเริ่มต้น, คะแนน, สถานะเกม
    void run();                  // ฟังก์ชันหลักที่ใช้เล่นเกม (เริ่มเกม ลูปการทำงานจนจบ)
};

#endif // ปิด include guard เพื่อไม่ให้ include ซ้ำ

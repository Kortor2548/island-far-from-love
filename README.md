## 🐍 Snake Game (Console Version)

A simple snake game built in C++ for the Windows console.
Move the snake, eat the fruit, grow longer, and avoid crashing into yourself or the wall!

---

### 📁 Project Structure

```bash
project-root/
├── src/
│   ├── SnakeGame.h        ✅ มีประกาศ class SnakeGame
│   ├── SnakeGame.cpp      ✅ มี implementation เช่น SnakeGame::SnakeGame() และ SnakeGame::run()
│   └── main.cpp           ✅ สร้าง object SnakeGame และเรียก run()
├── snake.exe              ✅ Executable Programs. 

```

---

### ✅ Features

* Console-based gameplay using ASCII graphics
* Smooth snake movement
* Fruit randomly spawns in the arena
* Score increases when fruit is eaten
* Game ends when the snake hits the wall or itself
* Final score is shown at game over

---

### ⚙️ How to Compile & Run (Windows)

1. Run the game:

```bash
./snake.exe
```

---

### 🎮 How to Play

* The game starts automatically when you run `snake.exe`
* Use the keyboard to control the snake:

  * `W` = Move up
  * `S` = Move down
  * `A` = Move left
  * `D` = Move right
  * `X` = Exit game
* Eat the `@` fruit to grow and increase your score
* Avoid hitting the walls or your own body
* When the game ends, your final score is displayed

---

### 👨‍💻 Object-Oriented Design (OOP) & Inheritance

This game demonstrates the use of **Object-Oriented Programming** in C++. The class structure applies principles like **encapsulation**, **abstraction**, and **inheritance**:

* `GameEntity` – A base class containing shared properties like position (`x`, `y`)
* `MovableEntity` – Inherits from `GameEntity`, adds movement capability via `dx`, `dy`
* `SnakeGame` – Inherits from `MovableEntity`, encapsulates all game logic (drawing, input, snake update, collision)

This layered structure promotes **code reuse** and **modularity**, making the code easier to maintain and extend in the future.

---

### 💡 Notes

* This game is designed to run in the Windows console (`cmd` or `PowerShell`)
* It uses Windows-specific libraries: `windows.h`, `_kbhit`, and `_getch`

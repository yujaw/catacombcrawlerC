# 🐉 Catacomb Crawler

## ✨ Overview
Catacomb Crawler is a dungeon exploration game written in C. Players navigate procedurally generated catacombs, battle enemies, solve puzzles, and collect treasures. The game emphasizes performance and retro-style gameplay mechanics.

## 🚀 Getting Started

### ⚙️ Prerequisites
Ensure you have the following installed on your system:
- 🐳 Docker (for cross-platform builds)
- 🛠️ GCC or Clang (for native builds)

### 📥 Installation and Usage

Clone the repository:
```bash
git clone https://github.com/yourusername/catacombcrawlerC.git
```

#### 🍎 For macOS
1. 📂 Navigate to the project folder:
    ```bash
    cd catacombcrawlerC
    ```
2. 🏗️ Build the program:
    ```bash
    gcc -o catacombcrawler main.c
    ```
3. ▶️ Run the program:
    ```bash
    ./catacombcrawler
    ```

#### 🖥️ For Windows
1. 📂 Navigate to the project folder:
    ```bash
    cd catacombcrawlerC
    ```
2. 🏗️ Build the program:
    ```bash
    gcc -o catacombcrawler.exe main.c
    ```
3. ▶️ Run the program:
    ```bash
    .\catacombcrawler.exe
    ```

#### 🐳 Using Docker
1. 🏗️ Build the Docker image:
    ```bash
    docker build -t catacombcrawler .
    ```
2. ▶️ Run the Docker container:
    ```bash
    docker run --rm -it catacombcrawler
    ```
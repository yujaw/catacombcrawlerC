# Catacomb Crawler 👺

## About the Game

Catacomb Crawler is an exciting dungeon exploration game where players navigate through procedurally generated catacombs, battling enemies, solving puzzles, and collecting treasures. Written in C, the game emphasizes performance and classic gameplay mechanics, offering a nostalgic yet challenging experience for fans of retro-style games.

## Prerequisites

- [Docker](https://www.docker.com/) installed on your system.

## Steps to Run

1. **Clone the Repository**  
    Clone this repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/catacombcrawlerC.git
    cd catacombcrawlerC
    ```

2. **Build the Docker Image**  
    Build the Docker image using the provided `Dockerfile`:
    ```bash
    docker build -t catacombcrawler .
    ```

3. **Run the Application**  
    Run the application in a Docker container:
    ```bash
    docker run --rm -it catacombcrawler
    ```

## Notes

- Ensure that the `Dockerfile` is correctly set up to compile and run the C program.
- If you need to map volumes or expose ports, modify the `docker run` command accordingly.

## Troubleshooting

- If you encounter issues, ensure Docker is running and that the `Dockerfile` is in the project root directory.
- Check the logs for errors during the build or run process.

Enjoy exploring the Catacomb Crawler!
FROM gcc:latest

WORKDIR /app

COPY . /app

CMD ["sh", "-c", "gcc main.c -o game.out && ./game.out"]
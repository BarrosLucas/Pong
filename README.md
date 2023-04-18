# Pong Game

This is a simple implementation of the classic game "Pong" using the OpenGL library to Graphical Computing subject at UFPB.

### Requirements

   - OpenGL
   - freeglut library

### How to compile

   - On Linux:
        - Install the required libraries: sudo apt-get install freeglut3-dev
        - Compile with the command: g++ pong.cpp -o pong -lglut -lGLU -lGL

   - On Windows:
        - Download freeglut library from https://www.transmissionzero.co.uk/software/freeglut-devel/
        - Extract the files to your preferred location.
        - Add the path to the freeglut headers to your compiler (e.g. -I C:\freeglut\include)
        - Add the path to the freeglut library to your linker (e.g. -L C:\freeglut\lib\x64)
        - Compile with the command: g++ pong.cpp -o pong -lfreeglut -lopengl32 -lglu32

### How to play

   - Use the "W" and "S" keys to move the left paddle up and down, respectively.
   - Use the "I" and "K" keys to move the right paddle up and down, respectively.
   - The objective of the game is to score points by hitting the ball with your paddle and making it go past your opponent's paddle.

### Credits

This game was developed by:
- Lucas Freitas de Barros
- Matheus Fernandes de Sousa

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
   - Use the "Up" and "Down" arrows keys to move the right paddle up and down, respectively.
   - The objective of the game is to score points by hitting the ball with your paddle and making it go past your opponent's paddle.
   
### Checklist

   - [x] Use the "W", "S", "Up" arrow and "Down" arrow to move left and right paddle to up and to down.
   - [x] Text players scores on top screen
   - [ ] Colision with paddles and walls perfectly
   - [x] Up speed when the ball colid with the paddle and when have a point the speed is restarted
   - [ ] After a match the ball must be positioned with the player paddle that scored
   - [x] Finish the game when one player to goal 15 points
   - [x] Space key is used to pause and play the game
   - [x] Play sounds when racket the ball, when some player score and when some player win
   - [x] Use double buffering

### Credits

This game was developed by:
- Lucas Freitas de Barros
- Matheus Fernandes de Sousa

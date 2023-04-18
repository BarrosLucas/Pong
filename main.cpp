#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <string>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
#include <thread>



// Constantes do jogo
const int WINDOW_WIDTH = 640; // largura da janela
const int WINDOW_HEIGHT = 480; // altura da janela
const int PADDLE_WIDTH = 10; // largura da raquete
const int PADDLE_HEIGHT = 50; // altura da raquete
const int BALL_SIZE = 10; // tamanho da bola
const int BALL_RADIUS = BALL_SIZE/2;
const int BALL_SPEED = 1; // velocidade da bola
const int PADDLE_SPEED = 5; // velocidade das raquetes
const int LEFT_PADDLE_X = 50; // posição x da raquete esquerda
const int RIGHT_PADDLE_X = WINDOW_WIDTH - PADDLE_WIDTH - 50; // posição x da raquete direita
const int LEFT_PADDLE_INITIAL_Y = WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2; // posição y inicial da raquete esquerda
const int RIGHT_PADDLE_INITIAL_Y = WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2; // posição y inicial da raquete direita

// Variáveis do jogo
int leftPaddleY = LEFT_PADDLE_INITIAL_Y; // posição y atual da raquete esquerda
int rightPaddleY = RIGHT_PADDLE_INITIAL_Y; // posição y atual da raquete direita
int ballX = WINDOW_WIDTH / 2 - BALL_SIZE / 2; // posição x atual da bola
int ballY = WINDOW_HEIGHT / 2 - BALL_SIZE / 2; // posição y atual da bola
int ballVelocityX = BALL_SPEED; // velocidade x atual da bola
int ballVelocityY = BALL_SPEED; // velocidade y atual da bola

int leftScore = 0; // pontuação do jogador da esquerda
int rightScore = 0; // pontuação do jogador da direita

bool isPaused = false;
bool isPlayingSound = false; // indica que o som está tocando

// Variáveis para os sons
ALCdevice *dev = NULL;
ALCcontext *ctx = NULL;
ALuint source;
ALuint buffer1, buffer2;


void drawBall() {
  glBegin(GL_TRIANGLE_FAN);
  for(int i=0; i<=360; i++) {
    float angulo = i * 3.14159f / 180.0f;
    float x = BALL_SIZE * cos(angulo);
    float y = BALL_SIZE * sin(angulo);
    glVertex2f(x + 0.0f, y + 0.0f);
  }
  glEnd();
}


void display()
{
    // Limpa a tela com a cor preta
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha as raquetes
    glColor3f(1.0, 1.0, 1.0); // cor branca
    glRectf(LEFT_PADDLE_X, leftPaddleY, LEFT_PADDLE_X + PADDLE_WIDTH, leftPaddleY + PADDLE_HEIGHT);
    glRectf(RIGHT_PADDLE_X, rightPaddleY, RIGHT_PADDLE_X + PADDLE_WIDTH, rightPaddleY + PADDLE_HEIGHT);

    
    // Desenha a bola
    glPushMatrix(); // salva a matriz de transformação atual
    glTranslatef(ballX + BALL_SIZE / 2.0, ballY + BALL_SIZE / 2.0, 0.0); // translada para o centro da bola
    drawBall();
    glPopMatrix(); // restaura a matriz de transformação anterior

    // Desenha o placar esquerdo
    glColor3f(1.0, 1.0, 1.0); // cor branca
    glRasterPos2f(WINDOW_WIDTH/4 - 50, WINDOW_HEIGHT - 30);// posição do placar na tela
    std::string leftScoreString = "Player 1: " + std::to_string(leftScore);
    for (char c : leftScoreString) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    // Desenha o placar direito
    glRasterPos2f(3*WINDOW_WIDTH/4 - 50, WINDOW_HEIGHT - 30); // posição do placar na tela
    std::string rightScoreString = "Player 2: " + std::to_string(rightScore);
    for (char c : rightScoreString) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    // Ativa o padrão de linha tracejada
    glEnable(GL_LINE_STIPPLE);

    // Especifica o padrão de linha como uma linha tracejada com um ponto e um espaço
    glLineStipple(1, 0x00FF);

    // Desenha a linha
    glLineWidth(2);
    glColor3f(1.0, 1.0, 1.0); // cor branca
    glBegin(GL_LINES);
        glVertex2f(WINDOW_WIDTH / 2, 0);
        glVertex2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
    glEnd();

    // Desativa o padrão de linha tracejada
    glDisable(GL_LINE_STIPPLE);

    // Atualiza o conteúdo da tela
    glutSwapBuffers();
}

void play_sound(const char* file_path) {

    alutInit(NULL,NULL);
    // Abrir o arquivo de som
    ALuint buffer = alutCreateBufferFromFile(file_path);
    if (!buffer) {
        printf("Erro ao abrir o arquivo de som!\n");
        return;
    }

    // Criar uma nova fonte de som
    ALuint source;
    alGenSources(1, &source);
    if (alGetError() != AL_NO_ERROR) {
        printf("Erro ao criar a fonte de som!\n");
        alutExit();
        return;
    }

    // Conectar a fonte de som com o buffer de som
    alSourcei(source, AL_BUFFER, buffer);
    if (alGetError() != AL_NO_ERROR) {
        printf("Erro ao conectar a fonte de som com o buffer de som!\n");
        alDeleteSources(1, &source);
        alDeleteBuffers(1, &buffer);
        alutExit();
        return;
    }

    // Tocar o som
    alSourcePlay(source);
    if (alGetError() != AL_NO_ERROR) {
        printf("Erro ao tocar o som!\n");
        alDeleteSources(1, &source);
        alDeleteBuffers(1, &buffer);
        alutExit();
        return;
    }

    // Aguardar o som terminar de tocar
    ALint status;
    do {
        alGetSourcei(source, AL_SOURCE_STATE, &status);
    } while (status == AL_PLAYING);

    // Limpar os recursos
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    alutExit();

    isPlayingSound = false;
}

void playSoundThread(const char* file_path) {
    if (isPlayingSound) {
        play_sound(file_path);
    }
}

void update() {
  if(isPaused){
    return;
  }

    // Movimentação da bola
    ballX += ballVelocityX;
    ballY += ballVelocityY;
    
    // Colisão da bola com as paredes superior e inferior
    if (ballY <= 0 || ballY >= WINDOW_HEIGHT - BALL_SIZE) {
        ballVelocityY = -ballVelocityY;
    }
    
    // Colisão da bola com as raquetes
    if ((ballX <= LEFT_PADDLE_X + PADDLE_WIDTH) && (ballY + BALL_SIZE >= leftPaddleY && ballY <= leftPaddleY + PADDLE_HEIGHT)) {
        if(ballVelocityX < 0){
          isPlayingSound = true;
          const char* soundFile = "/home/lucas/Documentos/homework/sounds/paddle2.wav";
          std::thread soundThread([soundFile]() {
              playSoundThread(soundFile);
          });
          soundThread.detach();
          ballVelocityX *= -1;
          if(ballVelocityX > 0){
            ballVelocityX ++;
          }else{
            ballVelocityX --;
          }
          
          if(ballVelocityY > 0){
            ballVelocityY ++;
          }else{
            ballVelocityY --;
          }
        }
    } else if ((ballX >= RIGHT_PADDLE_X - BALL_SIZE) && (ballY + BALL_SIZE >= rightPaddleY && ballY <= rightPaddleY + PADDLE_HEIGHT)) {
        if(ballVelocityX > 0){
          isPlayingSound = true;
          const char* soundFile = "/home/lucas/Documentos/homework/sounds/paddle2.wav";
          std::thread soundThread([soundFile]() {
              playSoundThread(soundFile);
          });
          soundThread.detach();
          ballVelocityX *= -1;
          if(ballVelocityX > 0){
            ballVelocityX ++;
          }else{
            ballVelocityX --;
          }
          if(ballVelocityY > 0){
            ballVelocityY ++;
          }else{
            ballVelocityY --;
          }
        }
    }
    
    // Verificação de pontuação
    if (ballX <= 0) {
        play_sound("/home/lucas/Documentos/homework/sounds/ponto.wav");
        // Ponto do jogador da direita
        ballX = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
        ballY = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;
        ballVelocityX = BALL_SPEED;
        ballVelocityY = BALL_SPEED;
        rightScore++;
        if(rightScore == 2){
          play_sound("/home/lucas/Documentos/homework/sounds/vitoria.wav");
          //Dispara som de vitoria do jogador 2
          exit(0);
        }
    } else if (ballX >= WINDOW_WIDTH - BALL_SIZE) {
        play_sound("/home/lucas/Documentos/homework/sounds/ponto.wav");
        // Ponto do jogador da esquerda
        ballX = WINDOW_WIDTH / 2 - BALL_SIZE / 2;
        ballY = WINDOW_HEIGHT / 2 - BALL_SIZE / 2;
        ballVelocityX = -BALL_SPEED;
        ballVelocityY = -BALL_SPEED;
        leftScore++;
        if(leftScore == 2){
          play_sound("/home/lucas/Documentos/homework/sounds/vitoria.wav");
          //Dispara som de vitoria do jogador 2
          exit(0);
        }
    }
    display();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            rightPaddleY += PADDLE_SPEED;
            break;
        case GLUT_KEY_DOWN:
            rightPaddleY -= PADDLE_SPEED;
            break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            leftPaddleY += PADDLE_SPEED;
            break;
        case 's':
            leftPaddleY -= PADDLE_SPEED;
            break;
        case ' ': 
            isPaused = !isPaused;
            break;
        case 27: // tecla ESC
            exit(0);
            break;
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // cor de fundo preta
    glMatrixMode(GL_PROJECTION); // define a matriz de projeção
    glLoadIdentity(); // carrega a matriz identidade
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT); // define as coordenadas da janela
    ballX = WINDOW_WIDTH / 2.0f; // posição inicial da bola no centro da tela
    ballY = WINDOW_HEIGHT / 2.0f;
    ballVelocityX = BALL_SPEED; // velocidade inicial da bola
    ballVelocityY = BALL_SPEED;
    leftPaddleY = WINDOW_HEIGHT / 2.0f; // posição inicial das raquetes
    rightPaddleY = WINDOW_HEIGHT / 2.0f;
    leftScore = 0; // pontuação inicial
    rightScore = 0;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // modo de exibição duplo buffer e RGB
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); // tamanho da janela
    glutCreateWindow("Pong Game"); // título da janela
    init(); // inicializa as variáveis do jogo
    glutDisplayFunc(display); // função que desenha o jogo
    glutIdleFunc(update); // função que atualiza o jogo
    glutKeyboardFunc(keyboard); // função que trata as teclas pressionadas
    glutSpecialFunc(specialKeys);
    glutMainLoop(); // inicia o loop principal do jogo
    return 0;
}

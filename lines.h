#pragma once

void Lines(GLvoid){
    //Linhas
    glColor3f(0,0,0);
    glLineWidth(2.0f);

    //Contorno Casa Direita
    glBegin(GL_LINE_STRIP);
        glVertex2f(557, 365);
        glVertex2f(557, 198);
        glVertex2f(272, 198);
        glVertex2f(272, 365);
        glVertex2f(557, 365);
    glEnd();

    //Contorno Casa Esquerda
    glBegin(GL_LINE_STRIP);
        glVertex2f(272, 365);
        glVertex2f(272, 171);
        glVertex2f(159, 59);
        glVertex2f(28, 190);
        glVertex2f(48, 170);
        glVertex2f(48, 365);
        glVertex2f(272, 365);
    glEnd();

    //Parte Telhado Direita
    glBegin(GL_LINE_STRIP);
        glVertex2f(198, 72);
        glVertex2f(301, 179);
        glVertex2f(291, 188);
        glVertex2f(272, 171);
        glVertex2f(272, 198);
        glVertex2f(582, 198);
        glVertex2f(508, 72);
        glVertex2f(198, 72);
    glEnd();

    //Parte Telhado Esquerda
    glBegin(GL_LINE_STRIP);
        glVertex2f(28, 190);
        glVertex2f(17, 178);
        glVertex2f(160, 37);
        glVertex2f(198, 72);
    glEnd();

    //Rodap� Porta
    glBegin(GL_LINE_STRIP);
        glVertex2f(301, 365);
        glVertex2f(301, 355);
        glVertex2f(389, 355);
        glVertex2f(389, 365);
        glVertex2f(301, 365);
    glEnd();

    //Porta
    glBegin(GL_LINE_STRIP);
        glVertex2f(312, 354);
        glVertex2f(312, 238);
        glVertex2f(380, 238);
        glVertex2f(380, 354);
        glVertex2f(312, 354);
    glEnd();

    //Ma�aneta
    glBegin(GL_LINE_STRIP);
        glVertex2f(321, 297);
        glVertex2f(325, 294);
        glVertex2f(329, 297);
        glVertex2f(325, 302);
        glVertex2f(321, 297);
    glEnd();

    //Borda Janela Direita
    glBegin(GL_LINE_STRIP);
        glVertex2f(416, 307);
        glVertex2f(416, 224);
        glVertex2f(523, 224);
        glVertex2f(523, 307);
        glVertex2f(416, 307);
    glEnd();

    //Interior Janela Direita
    glBegin(GL_LINE_STRIP);
        glVertex2f(424, 298);
        glVertex2f(424, 232);
        glVertex2f(469, 232);
        glVertex2f(469, 298);
        glVertex2f(424, 298);
        glVertex2f(469, 298);
        glVertex2f(512, 298);
        glVertex2f(512, 232);
        glVertex2f(469, 232);
        glVertex2f(469, 298);
    glEnd();

    //Borda da Janela Esquerda
    glBegin(GL_LINE_STRIP);
        glVertex2f(235, 310);
        glVertex2f(235, 221);
        glVertex2f(83, 221);
        glVertex2f(83, 310);
        glVertex2f(235, 310);
    glEnd();

    //Interior da Janela Esquerda
    glBegin(GL_LINE_STRIP);
        glVertex2f(93, 301);
        glVertex2f(135, 301);
        glVertex2f(135, 229);
        glVertex2f(93, 229);
        glVertex2f(93, 301);
        glVertex2f(183, 301);
        glVertex2f(183, 229);
        glVertex2f(135, 229);
        glVertex2f(226, 229);
        glVertex2f(226, 301);
        glVertex2f(183, 301);
    glEnd();

    //Janela Superior
    glBegin(GL_LINE_STRIP);
        glVertex2f(128, 166);
        glVertex2f(190, 166);
        glVertex2f(190, 115);
        glVertex2f(128, 115);
        glVertex2f(128, 166);
        glVertex2f(128, 142);
        glVertex2f(160, 142);
        glVertex2f(160, 166);
        glVertex2f(160, 115);
        glVertex2f(160, 142);
        glVertex2f(190, 142);
    glEnd();

    //Chamin�
    glBegin(GL_LINE_STRIP);
        glVertex2f(430, 72);
        glVertex2f(462, 72);
        glVertex2f(462, 54);
        glVertex2f(430, 54);
        glVertex2f(430, 72);
        glVertex2f(430, 54);
        glVertex2f(424, 54);
        glVertex2f(424, 40);
        glVertex2f(468, 40);
        glVertex2f(468, 54);
        glVertex2f(462, 54);
    glEnd();
}
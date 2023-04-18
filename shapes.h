#pragma once

Color COLOR_ROOF = Color(247,113,112);
Color COLOR_WALL = Color(238,231,215);
Color COLOR_GLASS = Color(150,227,255);
Color COLOR_HOUSE_WINDOW = Color(216,215,210);
Color COLOR_CHIMNEY = Color(190,164,149);
Color COLOR_DOOR = Color(192,145,103);
Color COLOR_DOOR_HANDLE = Color(200,200,200);

void DrawTriangle(Point p1, Point p2, Point p3, Color color);
void DrawSquare(Point p1, Point p2, Point p3, Point p4, Color color);


void Chimney(){
    DrawSquare(Point(424,54),Point(424,40),Point(468,40),Point(468,54),COLOR_CHIMNEY);
    DrawSquare(Point(430,72),Point(430,54),Point(462,54),Point(462,72),COLOR_CHIMNEY);
}

void Roof(){
    DrawTriangle(Point(582,198),Point(508,72),Point(508,198),COLOR_ROOF);
    DrawSquare(Point(508,72),Point(508,198),Point(198,198),Point(198,72),COLOR_ROOF);
    DrawSquare(Point(301,179),Point(291,188),Point(159,59),Point(198,72),COLOR_ROOF);
    DrawSquare(Point(159,59),Point(160,37), Point(17,178), Point(28,190),COLOR_ROOF);
    DrawTriangle(Point(198,73),Point(159,59),Point(160,37),COLOR_ROOF);
}

void Wall(){
    DrawSquare(Point(48,365),Point(557,365),Point(557,198),Point(48,198),COLOR_WALL);
    DrawSquare(Point(48,170),Point(272,171),Point(272,198),Point(48,198),COLOR_WALL);
    DrawTriangle(Point(48,170),Point(159,59),Point(272,171),COLOR_WALL);
}

void Windows(){
    DrawSquare(Point(416,307),Point(416,224),Point(523,224),Point(523,307),COLOR_HOUSE_WINDOW); //Direita
    DrawSquare(Point(83,310),Point(83,221),Point(235,221),Point(235,310),COLOR_HOUSE_WINDOW); //Esquerda
}

void Glass(){
    DrawSquare(Point(424,298),Point(424,232),Point(512,232),Point(512,298),COLOR_GLASS); //Direita
    DrawSquare(Point(93,301),Point(93,229),Point(226,229),Point(226,301),COLOR_GLASS); //Esquerda
    DrawSquare(Point(128,166),Point(128,115),Point(190,115),Point(190,166),COLOR_GLASS); //Superior
}

void Door(){
    DrawSquare(Point(312,354),Point(312,238),Point(380,238),Point(380,354),COLOR_DOOR);
    DrawSquare(Point(325,302),Point(321,297),Point(325,294),Point(329,297),COLOR_DOOR_HANDLE);
}

void Shapes(){
    Chimney();
    Roof();
    Wall();
    Windows();
    Glass();
    Door();
}
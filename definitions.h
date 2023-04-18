class Color{
public:
    GLfloat red;
    GLfloat green;
    GLfloat blue;

    Color(){}
    Color(float r, float g, float b){
        red = r > 1 ? r/255 : r;
        green = g > 1 ? g/255 : g;
        blue = b > 1 ? b/255 : b;
    }
};

class Point{
public:
    GLint x;
    GLint y;
    Color color;

    Point(int x, int y){
        this->x = (GLint)x;
        this->y = (GLint)y;
    }
    Point(int x, int y, Color color){
        this->x = (GLint)x;
        this->y = (GLint)y;
        this->color = color;
    }
};

Color COLOR_RED = Color(255,0,0);
Color COLOR_GREEN = Color(0,255,0);
Color COLOR_BLUE = Color(0,0,255);
Color COLOR_WHITE = Color(255,255,255);
Color COLOR_BLACK = Color(0,0,0);
Color COLOR_GREY = Color(128,128,128);
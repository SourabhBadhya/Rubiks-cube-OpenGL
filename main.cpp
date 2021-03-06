#include<bits/stdc++.h>
#include<unistd.h>
#include<GL/glut.h>
using namespace std;

const int WHITE = 0;
const int GREEN = 1;
const int BLUE = 2;
const int RED = 3;
const int ORANGE = 4;
const int YELLOW = 5;

struct cube{
    char faces[6][3][3];

    cube(){
        for(int i=0; i<6; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    faces[i][j][k] = i;
                }
            }
        }
    }

    void rotateR(){ //face 3
        char tmp = faces[3][0][0];

        //swapping corners
        swap(faces[3][0][2], tmp);
        swap(faces[3][2][2], tmp);
        swap(faces[3][2][0], tmp);
        swap(faces[3][0][0], tmp);

        tmp = faces[3][0][1];

        //swapping edges
        swap(faces[3][1][2], tmp);
        swap(faces[3][2][1], tmp);
        swap(faces[3][1][0], tmp);
        swap(faces[3][0][1], tmp);

        //fixing other faces
        char tmp_arr[3];

        for(int i=0; i<3; i++){
            tmp_arr[i] = faces[0][i][2];
        }

        for(int i=0; i<3; i++){
            swap(faces[2][i][2],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[5][3-1-i][0],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[1][i][2],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[0][i][2],tmp_arr[i]);
        }
    }

    void rotateL(){ //face 4
        char tmp = faces[4][0][0];

        //swapping corners
        swap(faces[4][0][2], tmp);
        swap(faces[4][2][2], tmp);
        swap(faces[4][2][0], tmp);
        swap(faces[4][0][0], tmp);

        tmp = faces[4][0][1];

        //swapping edges
        swap(faces[4][1][2], tmp);
        swap(faces[4][2][1], tmp);
        swap(faces[4][1][0], tmp);
        swap(faces[4][0][1], tmp);

        //fixing other faces
        char tmp_arr[3];

        for(int i=0; i<3; i++){
            tmp_arr[i] = faces[0][i][0];
        }

        for(int i=0; i<3; i++){
            swap(faces[1][i][0],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[5][3-1-i][2],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[2][i][0],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[0][i][0],tmp_arr[i]);
        }
    }

    void rotateU(){ //face 0
        char tmp = faces[0][0][0];

        //swapping corners
        swap(faces[0][0][2], tmp);
        swap(faces[0][2][2], tmp);
        swap(faces[0][2][0], tmp);
        swap(faces[0][0][0], tmp);

        tmp = faces[0][0][1];

        //swapping edges
        swap(faces[0][1][2], tmp);
        swap(faces[0][2][1], tmp);
        swap(faces[0][1][0], tmp);
        swap(faces[0][0][1], tmp);

        //fixing other faces
        char tmp_arr[3];

        for(int i=0; i<3; i++){
            tmp_arr[i] = faces[1][0][i];
        }

        for(int i=0; i<3; i++){
            swap(faces[4][i][2],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[2][2][3-1-i],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[3][3-1-i][0],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[1][0][i],tmp_arr[i]);
        }
    }

    void rotateD(){ //face 5
        char tmp = faces[5][0][0];

        //swapping corners
        swap(faces[5][0][2], tmp);
        swap(faces[5][2][2], tmp);
        swap(faces[5][2][0], tmp);
        swap(faces[5][0][0], tmp);

        tmp = faces[5][0][1];

        //swapping edges
        swap(faces[5][1][2], tmp);
        swap(faces[5][2][1], tmp);
        swap(faces[5][1][0], tmp);
        swap(faces[5][0][1], tmp);

        //fixing other faces
        char tmp_arr[3];

        for(int i=0; i<3; i++){
            tmp_arr[i] = faces[1][2][i];
        }

        for(int i=0; i<3; i++){
            swap(faces[3][3-1-i][2],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[2][0][3-1-i],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[4][i][0],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[1][2][i],tmp_arr[i]);
        }
    }

    void rotateF(){ //face 1
        char tmp = faces[1][0][0];

        //swapping corners
        swap(faces[1][0][2], tmp);
        swap(faces[1][2][2], tmp);
        swap(faces[1][2][0], tmp);
        swap(faces[1][0][0], tmp);

        tmp = faces[1][0][1];

        //swapping edges
        swap(faces[1][1][2], tmp);
        swap(faces[1][2][1], tmp);
        swap(faces[1][1][0], tmp);
        swap(faces[1][0][1], tmp);

        //fixing other faces
        char tmp_arr[3];

        for(int i=0; i<3; i++){
            tmp_arr[i] = faces[0][2][i];
        }

        for(int i=0; i<3; i++){
            swap(faces[3][2][i],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[5][2][i],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[4][2][i],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[0][2][i],tmp_arr[i]);
        }
    }

    void rotateB(){ //face 2
        char tmp = faces[2][0][0];

        //swapping corners
        swap(faces[2][0][2], tmp);
        swap(faces[2][2][2], tmp);
        swap(faces[2][2][0], tmp);
        swap(faces[2][0][0], tmp);

        tmp = faces[2][0][1];

        //swapping edges
        swap(faces[2][1][2], tmp);
        swap(faces[2][2][1], tmp);
        swap(faces[2][1][0], tmp);
        swap(faces[2][0][1], tmp);

        //fixing other faces
        char tmp_arr[3];

        for(int i=0; i<3; i++){
            tmp_arr[i] = faces[0][0][i];
        }

        
        for(int i=0; i<3; i++){
            swap(faces[4][0][i],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[5][0][i],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[3][0][i],tmp_arr[i]);
        }
        for(int i=0; i<3; i++){
            swap(faces[0][0][i],tmp_arr[i]);
        }
    }

    void rotateM(){
        char tmp_arr[3];

        for(int i=0; i<3; i++){
            tmp_arr[i] = faces[0][i][1];
        }

        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[1][i][1]);
        }
        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[5][3-1-i][1]);
        }
        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[2][i][1]);
        }
        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[0][i][1]);
        }
    }

    void rotateE(){
        char tmp_arr[3];

        for(int i=0; i<3; i++){
            tmp_arr[i] = faces[1][1][i];
        }

        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[3][3-1-i][1]);
        }
        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[2][1][3-1-i]);
        }
        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[4][i][1]);
        }
        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[1][1][i]);
        }
    }

    void rotateS(){
        char tmp_arr[3];

        for(int i=0; i<3; i++){
            tmp_arr[i] = faces[0][1][i];
        }

        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[3][1][i]);
        }
        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[5][1][i]);
        }
        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[4][1][i]);
        }
        for(int i=0; i<3; i++){
            swap(tmp_arr[i], faces[0][1][i]);
        }
    }

    void rotateRinverted(){
        for(int i=0; i<3; i++){
            rotateR();
        }
    }

    void rotateLinverted(){
        for(int i=0; i<3; i++){
            rotateL();
        }
    }

    void rotateUinverted(){
        for(int i=0; i<3; i++){
            rotateU();
        }
    }

    void rotateDinverted(){
        for(int i=0; i<3; i++){
            rotateD();
        }
    }

    void rotateFinverted(){
        for(int i=0; i<3; i++){
            rotateF();
        }
    }

    void rotateBinverted(){
        for(int i=0; i<3; i++){
            rotateB();
        }
    }

    void rotateMinverted(){
        for(int i=0; i<3; i++){
            rotateM();
        }
    }

    void rotateEinverted(){
        for(int i=0; i<3; i++){
            rotateE();
        }
    }

    void rotateSinverted(){
        for(int i=0; i<3; i++){
            rotateS();
        }
    }

    void rotateX(){
        rotateR();
        rotateLinverted();
        rotateMinverted();
    }

    void rotateXinverted(){
        rotateRinverted();
        rotateL();
        rotateM();
    }

    void rotateY(){
        rotateU();
        rotateDinverted();
        rotateEinverted();
    }

    void rotateYinverted(){
        rotateUinverted();
        rotateD();
        rotateE();
    }

    void rotateZ(){
        rotateF();
        rotateBinverted();
        rotateS();
    }

    void rotateZinverted(){
        rotateFinverted();
        rotateB();
        rotateSinverted();
    }

    // For debugging purposes only
    void draw_cube(){
        for(int i=0; i<6; i++){
            cout<<i<<": \n";
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    cout<<(int)faces[i][j][k]<<" ";
                }cout<<'\n';
            }
            cout<<"\n\n";
        }
    }
};


GLfloat angle, aspect_ratio, gap, elevation, cube_size;


cube RubiksCube;

void set_camera(){
    gluLookAt(0,80,100, 0,-cube_size/2,-cube_size/2, 0,1,0);
}

void draw_square(int color){

    switch(color){
        case WHITE : glColor3f(1.0f, 1.0f, 1.0f);
            break;
        
        case GREEN : 
            glColor3f(0.0f, 1.0f, 0.0f);
            break;

        case BLUE : 
            glColor3f(0.0f, 0.0f, 1.0f);
            break;

        case RED :
            glColor3f(1.0f, 0.0f, 0.0f);
            break;

        case ORANGE :
            glColor3f(1.0f, 0.5f, 0.0f);
            break;

        case YELLOW :
            glColor3f(1.0f, 1.0f, 0.0f);
            break;
    }

    
    
    glBegin(GL_QUADS);
        glVertex3f(-cube_size/6, cube_size/6, 0);
        glVertex3f(cube_size/6, cube_size/6, 0);
        glVertex3f(cube_size/6, -cube_size/6, 0);
        glVertex3f(-cube_size/6, -cube_size/6, 0);
    glEnd();
}

void draw_face(int face){

    for(int i=0; i<3; i++){
        glPushMatrix();
        glTranslatef(0.0f, (cube_size/3+gap)*(1-i), 0.0f);
        for(int j=0; j<3; j++){
            glPushMatrix();

            glTranslatef((cube_size/3+gap)*(j-1), 0.0f, 0.0f);

            draw_square(RubiksCube.faces[face][i][j]);

            glPopMatrix();
        }

        glPopMatrix();
    }
}



void draw_cube(){
    

    

    GLdouble total_elevation = cube_size/2+gap+elevation;

    for(int i=0; i<6; i++){
        if(i == 0){ // Top face
            glPushMatrix();

            glTranslatef(0, total_elevation, 0);
            glRotatef(-90, 1, 0, 0);
            draw_face(i);

            glPopMatrix();
        } else if(i == 1){ // Front face
            glPushMatrix();

            glTranslatef(0, 0, total_elevation);
            draw_face(i);

            glPopMatrix();
        } else if(i == 2){ // Back face
            glPushMatrix();

            glTranslatef(0, 0, -total_elevation);
            glRotatef(180, 1, 0, 0);
            draw_face(i);

            glPopMatrix();
        } else if(i == 3){ // Right face
            glPushMatrix();

            glTranslatef(total_elevation, 0, 0);
            glRotatef(90, 0, 1, 0);
            glRotatef(-90, 0, 0, 1);

            draw_face(i);

            glPopMatrix();
        } else if(i == 4){ // Left face 
            glPushMatrix();

            glTranslatef(-total_elevation, 0.0, 0.0);
            glRotatef(-90, 0, 1, 0);
            glRotatef(90, 0, 0, 1);

            draw_face(i);

            glPopMatrix();
        } else{ // Bottom face
            glPushMatrix();

            glTranslatef(0.0, -total_elevation, 0);
            glRotatef(-90, 1, 0, 0);
            glRotatef(180, 0, 1, 0);

            draw_face(i);

            glPopMatrix();
        }
    }

    glutPostRedisplay();

    glutSwapBuffers();
}

void draw_cube2(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    

    set_camera();

    string by = "By";
    string sourabh = "Sourabh S Badhya (1RV17CS159)";
    string sparsh = "Sparsh G Sarode (1RV17CS162)";

    glColor3f(1.0,1.0,0);


    glRasterPos2f(50,50);

    for(int i=0; i<by.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,by[i]);
    }

    glRasterPos2f(52,45);

    for(int i=0; i<sparsh.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,sparsh[i]);
    }

    glRasterPos2f(54,40);

    for(int i=0; i<sourabh.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,sourabh[i]);
    }

    draw_cube();
}

void load_visualization_parameters(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(angle,aspect_ratio,1,500);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    set_camera();
}

void init(){
    angle = 50;
    gap = 5;
    elevation = 1;
    cube_size = 30;

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_BLEND);
}

void reshape_func(GLsizei w, GLsizei h){
    if ( h == 0 ) h = 1;

    glViewport(0, 0, w, h);

    aspect_ratio = (GLfloat)w/(GLfloat)h;

    load_visualization_parameters();
}

void keyboardCallback(unsigned char key, int x, int y){
    switch(key){
        case 'a' :
            RubiksCube.rotateYinverted();
            break;

        case ';' :
            RubiksCube.rotateY();
            break;
        
        case 'q' :
            RubiksCube.rotateZinverted();
            break;
        
        case 'p' :
            RubiksCube.rotateZ();
            break;
        
        case 'w' :
            RubiksCube.rotateB();
            break;
        
        case 'o' :
            RubiksCube.rotateBinverted();
            break;
        
        case 'i' :
            RubiksCube.rotateR();
            break;
        
        case 'k' :
            RubiksCube.rotateRinverted();
            break;

        case 'e' :
            RubiksCube.rotateLinverted();
            break;

        case 'd' :
            RubiksCube.rotateL();
            break;
        
        case 'j' :
            RubiksCube.rotateU();
            break;

        case 'f' :
            RubiksCube.rotateUinverted();
            break;

        case 'h' :
            RubiksCube.rotateF();
            break;
        
        case 'g' :
            RubiksCube.rotateFinverted();
            break;
        
        case 't' :
            RubiksCube.rotateX();
            break;
        
        case 'v' :
            RubiksCube.rotateXinverted();
            break;

        case 's' :
            RubiksCube.rotateD();
            break;
        
        case 'l' :
            RubiksCube.rotateDinverted();
            break;
        
        case 'b' :
            RubiksCube.rotateMinverted();
            break;
        
        case 'n' :
            RubiksCube.rotateM();
            break;
        
        case 'I' :
            RubiksCube.rotateR();
            RubiksCube.rotateMinverted();
            break;
        
        case 'K' :
            RubiksCube.rotateRinverted();
            RubiksCube.rotateM();
            break;

        case 'E' :
            RubiksCube.rotateLinverted();
            RubiksCube.rotateMinverted();
            break;
        
        case 'D' :
            RubiksCube.rotateL();
            RubiksCube.rotateM();
            break;
        
        default:
            break;
    }

    
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Rubik's cube simulation");
    glutDisplayFunc(draw_cube2);
    glutReshapeFunc(reshape_func);
    glutKeyboardFunc(keyboardCallback);
    init();
    glutMainLoop();
}
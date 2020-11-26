#include<bits/stdc++.h>
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

int main(){
    cube MyCube;

    MyCube.rotateZinverted();
    MyCube.draw_cube();
}
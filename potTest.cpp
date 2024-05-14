// 20210815 백대현
#include <GL/freeglut.h>

float angle = 0.0; // 회전 각도 변수

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix(); // 현재 변환 행렬을 스택에 저장
    glRotatef(angle, 0.0, 1.0, 0.0); // 회전 변환 적용

    glColor3f(1.0, 1.0, 0.0);
    glutWireTeapot(1.0);

    glPopMatrix(); // 스택에서 행렬을 꺼내어 현재 행렬로 설정

    glutSwapBuffers(); // 프레임을 화면에 표시
}

void update(int value) {
    angle += 2.0; // 회전 각도 증가
    if (angle > 360) {
        angle -= 360; // 각도가 360을 초과하면 360을 뺌
    }

    glutPostRedisplay(); // 화면 다시 그리기 요청
    glutTimerFunc(16, update, 0); // 16밀리초 후에 update 함수 호출
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // 더블 버퍼링 활성화
    glutInitWindowSize(600, 600);
    glutCreateWindow("Pot");

    init();

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);

    glutTimerFunc(16, update, 0); // 타이머 함수 호출

    glutMainLoop();

    return 0;
}

# Pot_homework
dev_cpp로 돌아가는 주전자 만들기
> 20210815 백대현

# 소감문
처음 써보는 OPENGL을 이용한 과제를 해보니 코드를 실행하기 위해서 환경을 만들어줘야하는 것도 처음 해보는 작업이라 쉽지 않았지만 코드가 원활하게 실행되도록 만드는 과정에서 많은걸 배울 수 있었던 과제인 것 같습니다. 하지만 한편으로는 정말 앞으로 배울것이 산더미만큼 있다는 생각이 들기도 했지만, 이 모든 과정을 내 것으로 습득하면 좋은 개발자가 될 수 있을것 같다는 생각이 들었고, 앞으로도 남은 수업 열심히 수강하여 좋은 성적 받도록 노력하겠습니다.

# 코드 실행 방법
1. 업로드 되어있는 freeglut-MinGW-3.0.0-1.mp 파일을 다운로드 받아서 압축해제 합니다.
2. Dev-cpp/TDM-GCC-64/x86_64-w64-mingw32 파일로 들어갑니다.
3. 다운로드 받은 include에 있는 파일을 복사하여 2번에서 설명한 위치에 있는 include 폴더와 GL폴더 안에 붙여넣습니다.
4. 다운로드 받은 lib/x64 폴더 안의 파일을 2번에서 설명한 위치에 있는 lib 폴더 안에 붙여넣습니다.
5. 다운로드 받은 bin/x64 폴더 안의 파일을 c:/windows/System32 폴더 안에 붙여넣습니다.
6. 이후 dev cpp 프로그램을 실행하고, 프로젝트 - 프로젝트 설정 - 매개변수에 들어가서 라이브러리나 객체 추가하기를 누릅니다.
7. ibfreeglut.a , libopengl32.a , libglu32.a 세 개의 파일을 추가합니다.
8. 이후 깃에 올려져있는 코드를 실행합니다.

# 실행 코드 

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

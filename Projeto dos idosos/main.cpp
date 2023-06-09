#include <iostream>-
#include <opencv2/opencv.hpp>
#include <deque>
#include <chrono>

using namespace cv;
using namespace std;

int main() {

    int respforma;
    int contador = 1;


    cout << "Qual movimento você deseja? \n 1- Ampulheta \n 2- triangulo \n";
    cin >> respforma;

    if (respforma == 1)
    {
        Point previousPosition(-1, -1); // Posição anterior da bola

        VideoCapture cap(0);
        if (!cap.isOpened())
        {
            cout << "alterar o número da porta da câmera";
            return -1;
        }
        while (true)
        {
            Mat frame;
            cap.read(frame);

            // Checa se a imagem foi criada
            // successfully or not
            if (!frame.data) {
                std::cout << "Não foi possível abrir ou "
                    << "encontre a imagem\n";

                return 0;
            }

            contador = 1;


            int radius = 15;


            while (contador < 2)  // meio
            {
                int thickness = -1;

                Point center(325, 175);//declara o ponto central
                Scalar line_Color(218, 112, 214);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2) // meio baixo
            {
                int thickness = -1;

                Point center(325, 325);//declara o ponto central
                Scalar line_Color(0, 0, 255);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2) // meio cima
            {
                int thickness = -1;

                Point center(325, 25);//declara o ponto central
                Scalar line_Color(255, 69, 0);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2) // cima direita
            {
                int thickness = -1;

                Point center(525, 25);//declara o ponto central
                Scalar line_Color(119, 136, 153);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2) // cima esquerda
            {
                int thickness = -1;

                Point center(125, 25);//declara o ponto central
                Scalar line_Color(128, 0, 128);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2) // baixo esquerda
            {
                int thickness = -1;

                Point center(125, 325);//declara o ponto central
                Scalar line_Color(255, 165, 0);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2) // baixo direita
            {
                int thickness = -1;

                Point center(525, 325);//declara o ponto central
                Scalar line_Color(0, 0, 0);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            int thickness = 2;

            Point a1(125, 325), a2(525, 25);

            line(frame, a1, a2, Scalar(25, 25, 112),
                thickness, LINE_8);

            Point a3(125, 25), a4(525, 25);

            line(frame, a3, a4, Scalar(25, 25, 112),
                thickness, LINE_8);

            Point a5(125, 25), a6(525, 325);

            line(frame, a5, a6, Scalar(25, 25, 112),
                thickness, LINE_8);

            Point a7(125, 325), a8(525, 325);

            line(frame, a7, a8, Scalar(25, 25, 112),
                thickness, LINE_8);

            Mat hsvFrame;
            cvtColor(frame, hsvFrame, CV_RGB2HSV);

            blur(hsvFrame, hsvFrame, cv::Size(1, 1));

            //Threshold 
            Scalar lowerBound = cv::Scalar(55, 100, 50);
            Scalar upperBound = cv::Scalar(90, 255, 255);
            Mat threshFrame;
            inRange(hsvFrame, lowerBound, upperBound, threshFrame);

            //Calculate X,Y centroid      
            Moments m = moments(threshFrame, false);
            Point com(m.m10 / m.m00, m.m01 / m.m00);

            //Draw crosshair
            Scalar color = cv::Scalar(0, 0, 255);
            drawMarker(frame, com, color, cv::MARKER_CROSS, 20, 2);

            if (previousPosition.x != -1 && previousPosition.y != -1) {
                // Desenha a linha entre a posição atual e a posição anterior da bola
                line(frame, previousPosition, com, Scalar(0, 0, 255), 2);
            }

            previousPosition = com; // Atualiza a posição anterior

            cvNamedWindow("Detector de bola verde", CV_WINDOW_NORMAL);
            cvSetWindowProperty("Detector de bola verde", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);

            cv::Mat dst;
            cv::flip(frame, dst, 1);
            imshow("Detector de bola verde", dst);

            //imshow("Detector de bola verde", frame);
            //imshow("Thresholded Tennis Ball", threshFrame);


            // Show our image inside a window
            waitKey(30) == 27;

            if (cv::waitKey(30) >= 10)
                break;


        }
    }

    if (respforma == 2)
    {
        Point previousPosition(-1, -1); // Posição anterior da bola

        VideoCapture cap(0);
        if (!cap.isOpened())
        {
            cout << "alterar o número da porta da câmera";
            return -1;
        }
        while (true)
        {
            Mat frame;
            cap.read(frame);

            // Checa se a imagem foi criada
            // successfully or not
            if (!frame.data) {
                std::cout << "Não foi possível abrir ou "
                    << "encontre a imagem\n";

                return 0;
            }

            contador = 1;


            int radius = 15;


            contador = 1;

            while (contador < 2) // meio baixo
            {
                int thickness = -1;

                Point center(325, 325);//declara o ponto central
                Scalar line_Color(0, 0, 255);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }


            contador = 1;

            while (contador < 2) // cima direita
            {
                int thickness = -1;

                Point center(525, 25);//declara o ponto central
                Scalar line_Color(119, 136, 153);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2) // cima esquerda
            {
                int thickness = -1;

                Point center(125, 25);//declara o ponto central
                Scalar line_Color(128, 0, 128);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;


            int thickness = 2;

            Point a1(325, 325), a2(525, 25);

            line(frame, a1, a2, Scalar(25, 25, 112),
                thickness, LINE_8);

            Point a3(325, 325), a4(125, 25);

            line(frame, a3, a4, Scalar(25, 25, 112),
                thickness, LINE_8);

            Point a5(125, 25), a6(525, 25);

            line(frame, a5, a6, Scalar(25, 25, 112),
                thickness, LINE_8);

            Mat hsvFrame;
            cvtColor(frame, hsvFrame, CV_RGB2HSV);

            blur(hsvFrame, hsvFrame, cv::Size(1, 1));

            //Threshold 
            Scalar lowerBound = cv::Scalar(55, 100, 50);
            Scalar upperBound = cv::Scalar(90, 255, 255);
            Mat threshFrame;
            inRange(hsvFrame, lowerBound, upperBound, threshFrame);

            //Calculate X,Y centroid      
            Moments m = moments(threshFrame, false);
            Point com(m.m10 / m.m00, m.m01 / m.m00);

            //Draw crosshair
            Scalar color = cv::Scalar(0, 0, 255);
            drawMarker(frame, com, color, cv::MARKER_CROSS, 20, 2);

            if (previousPosition.x != -1 && previousPosition.y != -1) {
                // Desenha a linha entre a posição atual e a posição anterior da bola
                line(frame, previousPosition, com, Scalar(0, 0, 255), 2);
            }

            previousPosition = com; // Atualiza a posição anterior

            cvNamedWindow("Detector de bola verde", CV_WINDOW_NORMAL);
            cvSetWindowProperty("Detector de bola verde", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);

            cv::Mat dst;
            cv::flip(frame, dst, 1);
            imshow("Detector de bola verde", dst);

            //imshow("Detector de bola verde", frame);
            //imshow("Thresholded Tennis Ball", threshFrame);


            // Show our image inside a window
            waitKey(30) == 27;

            if (cv::waitKey(30) >= 10)
                break;


        }
        
    }

    else
    {
        cout << "Apenas 1 ou 2 eh aceito";
    }

}

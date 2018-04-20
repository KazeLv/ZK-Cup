#include "stdafx.h"
#include "opencv.h"
P P1, P2, P3, P4, P5, P6, P7, P8, P9;
vector<P> Ps;

void ColorTest(Mat imgHSV, String c)
{
	int iLowH, iHighH;
	int iLowS, iHighS;
	int iLowV, iHighV;
	Mat imgThresholded;
	Vec3b pixel;
	pixel[0] = pixel[1] = pixel[2] = 255;

	if (c == "White") {
		iLowH = 10;
		iHighH = 50;

		iLowS = 0;
		iHighS = 20;

		iLowV = 220;
		iHighV = 255;
	}
	else if (c == "Red") {
		iLowH = 156;
		iHighH = 180;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Yellow") {
		iLowH = 26;
		iHighH = 34;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Blue") {
		iLowH = 100;
		iHighH = 115;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Green") {
		iLowH = 50;
		iHighH = 70;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Orange") {
		iLowH = 0;
		iHighH = 10;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}

	cv::inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the imageq
	imwrite("threstest.png", imgThresholded);
	int count = 0;
	int i, j;

	for (i = 0; i < imgThresholded.rows; i++) {
		Vec3b *p = imgThresholded.ptr<Vec3b>(i);
		for (j = 0; j < imgThresholded.cols; j++)
			if (p[j] == pixel)
				count++;
	}
	
	cout << count << endl;

}

int Color(Mat imgHSV, String c)
{
	int iLowH, iHighH;
	int iLowS, iHighS;
	int iLowV, iHighV;
	Mat imgThresholded;
	Vec3b pixel;
	pixel[0] = pixel[1] = pixel[2] = 255;
	iLowH = 0;
	iHighH = 180;

	iLowS = 0;
	iHighS = 30;

	iLowV = 220;
	iHighV = 255;

	if (c == "White") {
		iLowH = 0;
		iHighH = 180;

		iLowS = 0;
		iHighS = 60;

		iLowV = 150;
		iHighV = 255;
	}
	else if (c == "Red") {
		iLowH = 0;
		iHighH = 5;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 200;
	}
	else if (c == "Yellow") {
		iLowH = 26;
		iHighH = 40;

		iLowS = 120;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Blue") {
		iLowH = 90;
		iHighH = 124;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Green") {
		iLowH = 40;
		iHighH = 70;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
	}
	else if (c == "Orange") {
		iLowH = 3;
		iHighH = 10;

		iLowS = 43;
		iHighS = 255;

		iLowV = 230;
		iHighV = 255;
	}
	
	
	cv::inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

	int count = 0;
	int i, j;

	for (i = 0; i < imgThresholded.rows; i++) {
		Vec3b *p = imgThresholded.ptr<Vec3b>(i);
		for (j = 0; j < imgThresholded.cols; j++)
			if (p[j] == pixel)
				count++;
	}

	if(c=="Red"){
		iLowH = 160;
		iHighH = 185;

		iLowS = 43;
		iHighS = 255;

		iLowV = 46;
		iHighV = 255;
		cv::inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
		int count2 = 0;
		for (i = 0; i < imgThresholded.rows; i++) {
			Vec3b *p = imgThresholded.ptr<Vec3b>(i);
			for (j = 0; j < imgThresholded.cols; j++) 
				if (p[j] == pixel)
					count2++;
		}
		count += count2;
	}

	if (count > 35)
		return 1;
	return 0;
}

void FillBlocks(Mat& A,string color,int num)			//num��ʾ�ڼ���ɫ��
{
	switch (num) {
	case(1):					//��һ��ɫ��
		if (color == "White")
			rectangle(A, Rect(0, 0, 120, 120), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(0, 0, 120, 120), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(0, 0, 120, 120), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(0, 0, 120, 120), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(0, 0, 120, 120), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(0, 0, 120, 120), Orange, -1, 1, 0);
	case(2):
		if (color == "White")
			rectangle(A, Rect(120, 0, 240, 120), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(120, 0, 240, 120), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(120, 0, 240, 120), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(120, 0, 240, 120), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(120, 0, 240, 120), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(120, 0, 240, 120), Orange, -1, 1, 0);
	case(3):
		if (color == "White")
			rectangle(A, Rect(240, 0, 360, 120), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(240, 0, 360, 120), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(240, 0, 360, 120), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(240, 0, 360, 120), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(240, 0, 360, 120), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(240, 0, 360, 120), Orange, -1, 1, 0);
	case(4):
		if (color == "White")
			rectangle(A, Rect(0, 120, 120, 240), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(0, 120, 120, 240), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(0, 120, 120, 240), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(0, 120, 120, 240), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(0, 120, 120, 240), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(0, 120, 120, 240), Orange, -1, 1, 0);
	case(5):
		if (color == "White")
			rectangle(A, Rect(120, 120, 240, 240), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(120, 120, 240, 240), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(120, 120, 240, 240), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(120, 120, 240, 240), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(120, 120, 240, 240), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(120, 120, 240, 240), Orange, -1, 1, 0);
	case(6):
		if (color == "White")
			rectangle(A, Rect(240, 120, 360, 240), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(240, 120, 360, 240), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(240, 120, 360, 240), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(240, 120, 360, 240), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(240, 120, 360, 240), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(240, 120, 360, 240), Orange, -1, 1, 0);
	case(7):
		if (color == "White")
			rectangle(A, Rect(0, 240, 120, 360), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(0, 240, 120, 360), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(0, 240, 120, 360), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(0, 240, 120, 360), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(0, 240, 120, 360), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(0, 240, 120, 360), Orange, -1, 1, 0);
	case(8):
		if (color == "White")
			rectangle(A, Rect(120, 240, 240, 360), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(120, 240, 240, 360), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(120, 240, 240, 360), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(120, 240, 240, 360), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(120, 240, 240, 360), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(120, 240, 240, 360), Orange, -1, 1, 0);
	case(9):
		if (color == "White")
			rectangle(A, Rect(240, 240, 360, 360), White, -1, 1, 0);
		else if (color == "Red")
			rectangle(A, Rect(240, 240, 360, 360), Red, -1, 1, 0);
		else if (color == "Yellow")
			rectangle(A, Rect(240, 240, 360, 360), Yellow, -1, 1, 0);
		else if (color == "Blue")
			rectangle(A, Rect(240, 240, 360, 360), Blue, -1, 1, 0);
		else if (color == "Green")
			rectangle(A, Rect(240, 240, 360, 360), Green, -1, 1, 0);
		else if (color == "Orange")
			rectangle(A, Rect(240, 240, 360, 360), Orange, -1, 1, 0);
	default:
		;
	}
}

void getHSV(Mat hsv, int x, int y) {
	Point p(x, y);
	printf("H=%d\t", hsv.at<Vec3b>(p)[0]);
	printf("S=%d\t", hsv.at<Vec3b>(p)[1]);
	printf("V=%d\n", hsv.at<Vec3b>(p)[2]);
	return;
}

void JudgeColor(Mat image, Mat& Blank, String c,string color[10],vector <struct P> Ps){
	resize(image, image, Size(900, 900), 0, 0, 3);			//����ͼƬ��С
	int i, j;

	//��ɫ��
	Mat P1 = image(Range(Ps[0].x1, Ps[0].x2), Range(Ps[0].y1, Ps[0].y2));		//��һ�е�һ��
	Mat P2 = image(Range(Ps[1].x1, Ps[1].x2), Range(Ps[1].y1, Ps[1].y2));		//��һ�еڶ���
	Mat P3 = image(Range(Ps[2].x1, Ps[2].x2), Range(Ps[2].y1, Ps[2].y2));		//��һ�е�����
	Mat P4 = image(Range(Ps[3].x1, Ps[3].x2), Range(Ps[3].y1, Ps[3].y2));		//�ڶ��е�һ��
	Mat P5 = image(Range(Ps[4].x1, Ps[4].x2), Range(Ps[4].y1, Ps[4].y2));		//�ڶ��еڶ���
	Mat P6 = image(Range(Ps[5].x1, Ps[5].x2), Range(Ps[5].y1, Ps[5].y2));		//�ڶ��е�����
	Mat P7 = image(Range(Ps[6].x1, Ps[6].x2), Range(Ps[6].y1, Ps[6].y2));		//�����е�һ��
	Mat P8 = image(Range(Ps[7].x1, Ps[7].x2), Range(Ps[7].y1, Ps[7].y2));		//�����еڶ���
	Mat P9 = image(Range(Ps[8].x1, Ps[8].x2), Range(Ps[8].y1, Ps[8].y2));		//�����е�����

	Rect ColorBlocks[10];
	ColorBlocks[1] = Rect(0, 0, 120, 120);					//��ʱ�����ͼƬ�޸Ĳ���,����һ��360*360��ħ��ʶ��ͼ
	ColorBlocks[2] = Rect(120, 0, 240, 120);
	ColorBlocks[3] = Rect(240, 0, 360, 120);
	ColorBlocks[4] = Rect(0, 120, 120, 240);
	ColorBlocks[5] = Rect(120, 120, 240, 240);
	ColorBlocks[6] = Rect(240, 120, 360, 240);
	ColorBlocks[7] = Rect(0, 240, 120, 360);
	ColorBlocks[8] = Rect(120, 240, 240, 360);
	ColorBlocks[9] = Rect(240, 240, 360, 360);
	imwrite("P1.png", P1);
	imwrite("P2.png", P2);
	imwrite("P3.png", P3);
	imwrite("P4.png", P4);
	imwrite("P5.png", P5);
	imwrite("P6.png", P6);
	imwrite("P7.png", P7);
	imwrite("P8.png", P8);
	imwrite("P9.png", P9);
	Mat imgHSV[10];
	Mat imgThresholded(200, 200, CV_8UC3);
	//string color[10];									//���9��ɫ�����ɫ
	cvtColor(P1, imgHSV[1], COLOR_BGR2HSV);
	cvtColor(P2, imgHSV[2], COLOR_BGR2HSV);
	cvtColor(P3, imgHSV[3], COLOR_BGR2HSV);
	cvtColor(P4, imgHSV[4], COLOR_BGR2HSV);
	cvtColor(P5, imgHSV[5], COLOR_BGR2HSV);
	cvtColor(P6, imgHSV[6], COLOR_BGR2HSV);
	cvtColor(P7, imgHSV[7], COLOR_BGR2HSV);   
	cvtColor(P8, imgHSV[8], COLOR_BGR2HSV);
	cvtColor(P9, imgHSV[9], COLOR_BGR2HSV);

	/*
	Mat test;
	test = imgHSV[7];
	for (i = 0; i < test.rows; i++) {			//print HSV
		for (j = 0; j < test.cols; j++)
		getHSV(test, i, j);
		printf("\n");
	}
	*/
	
	
	
	
	for (i = 1; i <= 9; i++) {				//��ÿ����ɫ��threshold,�õ�ɫ�����ɫ����
		if (Color(imgHSV[i], "Red") == 1)
			color[i] = "Red";
		else if (Color(imgHSV[i], "Orange") == 1)
			color[i] = "Orange";
		else if (Color(imgHSV[i], "Yellow") == 1)
			color[i] = "Yellow";
		else if (Color(imgHSV[i], "Blue") == 1)
			color[i] = "Blue";
		else if (Color(imgHSV[i], "Green") == 1)
			color[i] = "Green";
		else if (Color(imgHSV[i], "White") == 1)
			color[i] = "White";
	}

	for (i = 1; i <= 9; i++)				//ɫ�����
		FillBlocks(Blank, color[i], i);
	line(Blank, Point(0, 120), Point(360, 120), Scalar(0, 0, 0), 1, 8, 0);
	line(Blank, Point(0, 240), Point(360, 240), Scalar(0, 0, 0), 1, 8, 0);
	line(Blank, Point(120, 0), Point(120, 360), Scalar(0, 0, 0), 1, 8, 0);
	line(Blank, Point(240, 0), Point(240, 360), Scalar(0, 0, 0), 1, 8, 0);
	imwrite(c+".png", Blank);			//����ͼƬ

}

string Print_str(string color[10], vector <string> standardcolor)		//order URFDLB
{
	int i;
	string str;
	for (i = 1; i <= 9; i++) {
		if (color[i] == standardcolor[0])
			str += "U";
		else if (color[i] == standardcolor[1])
			str += "R";
		else if (color[i] == standardcolor[2])
			str += "F";
		else if (color[i] == standardcolor[3])
			str += "D";
		else if (color[i] == standardcolor[4])
			str += "L";
		else if (color[i] == standardcolor[5])
			str += "B";
	}
	return str;
}

void Ps_reset(vector<struct P>& Ps) {
	Ps.clear();
	P1.x1 = P2.x1 = P3.x1 = 190;
	P1.x2 = P2.x2 = P3.x2 = 200;
	P4.x1 = P5.x1 = P6.x1 = 420;
	P4.x2 = P5.x2 = P6.x2 = 430;
	P7.x1 = P8.x1 = P9.x1 = 720;
	P7.x2 = P8.x2 = P9.x2 = 730;
	P1.y1 = P4.y1 = P7.y1 = 250;
	P1.y2 = P4.y2 = P7.y2 = 260;
	P2.y1 = P5.y1 = P8.y1 = 460;
	P2.y2 = P5.y2 = P8.y2 = 470;
	P3.y1 = P6.y1 = P9.y1 = 640;
	P3.y2 = P6.y2 = P9.y2 = 650;

	Ps.push_back(P1);
	Ps.push_back(P2);
	Ps.push_back(P3);
	Ps.push_back(P4);
	Ps.push_back(P5);
	Ps.push_back(P6);
	Ps.push_back(P7);
	Ps.push_back(P8);
	Ps.push_back(P9);
}

void recognition() {
	
	vector <Point> center;								//���9��ɫ�������λ��,x��y��δ��������
														//��ʼ��9����ɫħ��
	Mat B(360, 360, CV_8UC3, Scalar(255, 255, 255));		//B��
	Mat D(360, 360, CV_8UC3, Scalar(255, 255, 255));		//D��
	Mat F(360, 360, CV_8UC3, Scalar(255, 255, 255));		//F��
	Mat L(360, 360, CV_8UC3, Scalar(255, 255, 255));		//L��
	Mat R(360, 360, CV_8UC3, Scalar(255, 255, 255));		//R��
	Mat U(360, 360, CV_8UC3, Scalar(255, 255, 255));		//U��
	int i;
	Mat image;
	string Bcolor[10];
	string Dcolor[10];
	string Fcolor[10];
	string Lcolor[10];
	string Rcolor[10];
	string Ucolor[10];
	vector <string> standardcolor;
	ofstream out;
	out.open("defination_str.txt", ios::out);			//��ħ�������ַ���д���ļ���
	string tmp[6];				//���ܷ��ص��ַ���


	Ps_reset(Ps);		// ��ʼ������
	image = imread("B.png");
	JudgeColor(image, B, "B_decode", Bcolor, Ps);

	while (1) {
		for (i = 1; i <= 9; i++)
			if (Bcolor[i] == "")
				break;
		if (i > 9)
			break;
		if (i == 4) {
			Ps[3].y1 += 10;
			Ps[3].y2 += 10;
		}
		if (i == 8) {
			Ps[7].x1 -= 10;
			Ps[7].x2 -= 10;
		}
		JudgeColor(image, B, "B_decode", Bcolor, Ps);
	}

	Ps_reset(Ps);
	image = imread("D.png");
	JudgeColor(image, D, "D_decode", Dcolor, Ps);

	while (1) {
		for (i = 1; i <= 9; i++)
			if (Dcolor[i] == "")
				break;
		if (i > 9)
			break;
		if (i == 2) {
			Ps[1].x1 += 10;
			Ps[1].x2 += 10;
		}
		if (i == 8) {
			Ps[7].x1 -= 10;
			Ps[7].x2 -= 10;
		}
		JudgeColor(image, D, "D_decode", Dcolor, Ps);
	}

	Ps_reset(Ps);
	image = imread("F.png");
	JudgeColor(image, F, "F_decode", Fcolor, Ps);

	while (1) {
		for (i = 1; i <= 9; i++)
			if (Fcolor[i] == "")
				break;
		if (i > 9)
			break;
		if (i == 6) {
			Ps[5].y1 -= 10;
			Ps[5].y2 -= 10;
		}
		if (i == 8) {
			Ps[7].x1 -= 10;
			Ps[7].x2 -= 10;
		}
		JudgeColor(image, F, "F_decode", Fcolor, Ps);
	}

	Ps_reset(Ps);
	image = imread("L.png");
	JudgeColor(image, L, "L_decode", Lcolor, Ps);


	Ps_reset(Ps);
	image = imread("R.png");
	JudgeColor(image, R, "R_decode", Rcolor, Ps);

	while (1) {
		for (i = 1; i <= 9; i++)
			if (Rcolor[i] == "")
				break;
		if (i > 9)
			break;
		if (i == 4) {
			Ps[3].y1 += 10;
			Ps[3].y2 += 10;
		}
		if (i == 6) {
			Ps[5].y1 -= 10;
			Ps[5].y2 -= 10;
		}
		JudgeColor(image, R, "R_decode", Rcolor, Ps);
	}


	Ps_reset(Ps);
	image = imread("U.png");
	JudgeColor(image, U, "U_decode", Ucolor, Ps);

	string Ustandard = Ucolor[5];
	string Rstandard = Rcolor[5];
	string Fstandard = Fcolor[5];
	string Dstandard = Dcolor[5];
	string Lstandard = Lcolor[5];
	string Bstandard = Bcolor[5];
	standardcolor.push_back(Ustandard);
	standardcolor.push_back(Rstandard);
	standardcolor.push_back(Fstandard);
	standardcolor.push_back(Dstandard);
	standardcolor.push_back(Lstandard);
	standardcolor.push_back(Bstandard);

	tmp[0] = Print_str(Ucolor, standardcolor);
	tmp[1] = Print_str(Rcolor, standardcolor);
	tmp[2] = Print_str(Fcolor, standardcolor);
	tmp[3] = Print_str(Dcolor, standardcolor);
	tmp[4] = Print_str(Lcolor, standardcolor);
	tmp[5] = Print_str(Bcolor, standardcolor);

	for (i = 0; i<6; i++)
		out << tmp[i];
	out.close();
}
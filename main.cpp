#include <bits/stdc++.h>
#include <graphics.h>
#include <winbgim.h>
using namespace std;

const int screenWidth = 1280;
const int screenHeight = 720;

bool showButtonsMatrix, showButtonsVector, showButtonsHome, showButtonsSettings;

struct Settings
{
    int backgroundColor = RGB(8, 12, 37);
    int backgroundColor_Red = 8;
    int backgroundColor_Green = 12;
    int backgroundColor_Blue = 37;

    bool playFXSounds = true;

    int animationSpeed = 600;

} settings;
struct Button
{
    int pozX;
    int pozY;

    int height;
    int width;

    bool mouseOver = false;
    bool show = false;
    bool press = false;

    int value = 0;

    struct Text
    {
        int pozX;
        int pozY;
        char buttonText[100];
    } text;
};
struct Nod
{
    Nod *nextElement;
    Nod *PreviewElement;

    char value[100];
    int valueInt;

    int indice;

    int pozX;
    int pozY;

    struct Text
    {
        int pozX;
        int pozY;
    } text;

    int width;
    int height = 50;

    bool show = false;
    bool press = false;
    bool on = false;

};
struct Vector
{
    int totalItems = 0;

    Nod *FirstElement;
    Nod *LastElement;

    Nod *selectedElement = new Nod;

    char sumElements[20];
    char producElements[20];

}*vect;
struct Matrix
{
    int width = 1;
    int height = 1;

    Nod *element[5][5];

    int countSelectedElements = 0;

    Nod *selectedElement = new Nod;

    bool generated = false;
    bool show = false;

    char tag[20];

    struct Determinant
    {
        int cont = 1;

        int vect_BK[5];
        int frec_BK[5];

        int pozX = 460;
        int pozY = 94;

        int determinant = 0;
        int produs = 1;

    } det;

} mainMatrix, secondMatrix, resultMatrix;

Button buttonMatrix, buttonVector, buttonSettings, buttonBack, buttonLoadData, buttonQuit;
Button buttonSumVect, buttonProductVect, buttonSortVect, buttonBubbleSortVect, buttonSelectionSortVect, buttonQuicksortVect, buttonShiftVect, buttonShiftLeftVect, buttonShiftRightVect, buttonProductScalarVect, buttonAddVector, buttonNextElementVect, buttonPreviewElementVect, buttonDeleteElementVect, buttonUndoVect, buttonSort_Selection;
Button buttonSumMatrix, buttonProductMatrix, buttonDecreaseMatrix, buttonPowMatrix, buttonTransposeMatrix, buttonInverseMatrix, buttonDetMatrix, buttonProductScalarMatrix, buttonDivisionMatrix, buttonMainMatrix_LineIncrease, buttonMainMatrix_LineDowncrease, buttonMainMatrix_ColumnIncrease, buttonMainMatrix_ColumnDowncrease, buttonSecondMatrix_LineIncrease, buttonSecondMatrix_LineDowncrease, buttonSecondMatrix_ColumnIncrease, buttonSecondMatrix_ColumnDowncrease, buttonSumElem_MainDiagonal, buttonSumElem_SecondDiagonal, buttonSumElem_BelowMainDiagonal, buttonSumElem_OverMainDiagonal, buttonSumElem_BelowSecondDiagonal, buttonSumElem_OverSecondDiagonal;

Button backgroundColor_Red, backgroundColor_Green, backgroundColor_Blue, buttonSetBackgroundColor;
Button speed_0, speed_100, speed_600, speed_1000;

void InitializationData();
void InitializationVectorHomeScreen();
void InitializationMatrixHomeScreen();
void InitializationSettingsHomeScreen();
void InitializationMatrixButtonsPress(Button *button);

void SaveFile_Vector();
void SaveFile_Matrix();
void SaveFile_Settings();
void LoadData();

void SetNumberBoxData(int &x, int &y, int index);
void FromDoubleToChar(double number, char sir[]);
double FromCharToDouble(char sir[30]);

void DrawHomeScreen();
void DrawSettingsScreen();
void DrawVectorButtons();
void DrawVector();

void DrawMainMatrix();
void DrawSecondMatrix();
void DrawResultMatrix();
void DrawMatrixButtons();

void OverButtonLevel1(int pozX, int pozY, Button *button);
void OverButtonLevel2(int pozX, int pozY, Button *button);

void OverButtonMatrix(int pozX, int pozY);
void OverButtonVector(int pozX, int pozY);
void OverButtonSettings(int pozX, int pozY);
void OverButtonBack(int pozX, int pozY);
void OverButtonLoadData(int pozX, int pozY);
void OverButtonQuit(int pozX, int pozY);

void OverButtonsVector(int pozX, int pozY);
void OverButtonsMatrix(int pozX, int pozY);
void OverButtonsSettings(int pozX, int pozY);


void PressButtonVector(int pozX, int pozY);
void PressButtonMatrix(int pozX, int pozY);
void PressButtonSettings(int pozX, int pozY);
void PressButtonLoadData(int pozX, int pozY);
void PressButtonBack(int pozX, int pozY);
void PressButtonQuit(int pozX, int pozY, bool &ok);

void PressButtonAdd(int pozX, int pozY);
void PressButtonSumVect(int pozX, int pozY);
void PressButtomProductVect(int pozX, int pozY);
void PressButtonSortVect(int pozX, int pozY);
void PressButtonShiftVect(int pozX, int pozY);
void PressButtonShiftLeftVect(int pozX, int pozY);
void PressButtonShiftRightVect(int pozX, int pozY);
void PressButtonProductScalarVect(int pozX, int pozY);
void PressButtonNextElementVect(int pozX, int pozY);
void PressButtonPreviewElementVect(int pozX, int pozY);
void PressButtonDeleteElementVect(int pozX, int pozY);
void PressButtonSelectionSort(int pozX, int pozY);
void PressButtonQuickSort(int pozX, int pozY);
void QuickSort(Nod *inf, Nod *sup);

void PressButtonResizeMatrix(int pozX, int pozY);
void PressButtonTransposeMatrix(int pozX, int pozY);
void PressButtonSumMatrix(int pozX, int pozY);
void ButtonEqual_Sum(int pozX, int pozY);
void PressButtonProductMatrix(int pozX, int pozY);
void ButtonEqual_Product(int pozX, int pozY);
void PressButtonDecreaseMatrix(int pozX, int pozY);
void ButtonEqual_Decrease(int pozX, int pozY);
void PressButtonDetMatrix(int pozX, int pozY);
void ButtonEqual_Det(int pozX, int pozY);
void PressButtonDivisionMatrix(int pozX, int pozY);
void ButtonEqual_Division(int pozX, int pozY);
void PressButtonPow(int pozX, int pozY);

void PressButton_Red(int pozX, int pozY);
void PressButton_Green(int pozX, int pozY);
void PressButton_Blue(int pozX, int pozY);
void PressButtonSetBackgroundColor(int pozX, int pozY);

void PressButtonVolum(int pozX, int pozY);
void ReadColor(Button *button);
void SelectSpeed(int pozX, int pozY);

void InverseMatrix(Matrix *matrix);
void Transpusa(Matrix *matrix);
void DeterminantMatrix_Backtracking(int row, Matrix *matrix);
void DeterminantMatrix_Backtracking_2(int row, Matrix *matrix, int line, int column, int cont);
void SelectElementMatrix(int pozX, int pozY);
void SelectElementVector(int pozX, int pozY);

void InitializationData()
{
    vect = new Vector;

    strcpy(mainMatrix.tag, "mainMatrix");
    strcpy(secondMatrix.tag, "secondMatrix");

    vect->selectedElement = NULL;
    vect->FirstElement = NULL;
    vect->LastElement = NULL;

    settings.backgroundColor_Red = 8;
    settings.backgroundColor_Green = 12;
    settings.backgroundColor_Blue = 37;


    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            mainMatrix.element[i][j] = new Nod;

    strcpy(mainMatrix.element[1][1]->value, "");

    buttonVector.width = 200;
    buttonVector.height = 75;
    buttonVector.pozX = (screenWidth - buttonVector.width) / 2;
    buttonVector.pozY = 250;

    buttonVector.text.pozX = (screenWidth - buttonVector.width) / 2 + 10;
    buttonVector.text.pozY = 265;
    strcpy(buttonVector.text.buttonText, "Vectori");

    buttonMatrix.width = 200;
    buttonMatrix.height = 75;
    buttonMatrix.pozX = (screenWidth - buttonMatrix.width) / 2;
    buttonMatrix.pozY = 350;

    buttonMatrix.text.pozX = (screenWidth - buttonMatrix.width) / 2 + 10;
    buttonMatrix.text.pozY = 365;
    strcpy(buttonMatrix.text.buttonText, "Matrici");

    buttonSettings.width = 150;
    buttonSettings.height = 50;
    buttonSettings.pozX = (screenWidth - buttonSettings.width) / 2;
    buttonSettings.pozY = 460;

    buttonSettings.text.pozX = (screenWidth - buttonSettings.width) / 2 + 25;
    buttonSettings.text.pozY = 470;
    strcpy(buttonSettings.text.buttonText, "Setari");

    buttonQuit.width = 150;
    buttonQuit.height = 50;
    buttonQuit.pozX = (screenWidth - buttonQuit.width) / 2;
    buttonQuit.pozY = 530;

    buttonQuit.text.pozX = (screenWidth - buttonQuit.width) / 2 + 25;
    buttonQuit.text.pozY = 540;
    strcpy(buttonQuit.text.buttonText, "Iesire");

    buttonLoadData.width = 435;
    buttonLoadData.height = 50;
    buttonLoadData.pozX = (screenWidth - buttonLoadData.width) / 2;
    buttonLoadData.pozY = 650;

    buttonLoadData.text.pozX = (screenWidth - buttonLoadData.width) / 2 + 25;
    buttonLoadData.text.pozY = 660;
    strcpy(buttonLoadData.text.buttonText, "Incarca ultima salvare");

    buttonBack.pozX = 1130;
    buttonBack.pozY = 650;
    buttonBack.width = 130;
    buttonBack.height = 50;

    buttonBack.text.pozX = 1140;
    buttonBack.text.pozY = 660;
    strcpy(buttonBack.text.buttonText, "Inapoi");

    buttonAddVector.width = 100;
    buttonAddVector.height = 50;

    buttonSumVect.pozX = 40;
    buttonSumVect.pozY = 270;
    buttonSumVect.width = 355;
    buttonSumVect.height = 50;

    strcpy(buttonSumVect.text.buttonText, "Suma Elementelor:");
    buttonSumVect.text.pozX = 50;
    buttonSumVect.text.pozY = 285;

    buttonProductVect.pozX = 40;
    buttonProductVect.pozY = 350;
    buttonProductVect.width = 410;
    buttonProductVect.height = 50;

    strcpy(buttonProductVect.text.buttonText, "Produsul Elementelor:");
    buttonProductVect.text.pozX = 50;
    buttonProductVect.text.pozY = 365;

    buttonSortVect.pozX = 40;
    buttonSortVect.pozY = 430;
    buttonSortVect.width = 290;
    buttonSortVect.height = 50;

    strcpy(buttonSortVect.text.buttonText, "Sortare Vector:");
    buttonSortVect.text.pozX = 50;
    buttonSortVect.text.pozY = 445;

    buttonSelectionSortVect.pozX = 360;
    buttonSelectionSortVect.pozY = 430;
    buttonSelectionSortVect.width = 270;
    buttonSelectionSortVect.height = 50;

    strcpy(buttonSelectionSortVect.text.buttonText, "Selection Sort");
    buttonSelectionSortVect.text.pozX = 370;
    buttonSelectionSortVect.text.pozY = 445;

    buttonQuicksortVect.pozX = 660;
    buttonQuicksortVect.pozY = 430;
    buttonQuicksortVect.width = 200;
    buttonQuicksortVect.height = 50;

    strcpy(buttonQuicksortVect.text.buttonText, "Quicksort");
    buttonQuicksortVect.text.pozX = 670;
    buttonQuicksortVect.text.pozY = 445;

    buttonShiftVect.pozX = 40;
    buttonShiftVect.pozY = 510;
    buttonShiftVect.width = 170;
    buttonShiftVect.height = 50;

    strcpy(buttonShiftVect.text.buttonText, "Shiftare:");
    buttonShiftVect.text.pozX = 50;
    buttonShiftVect.text.pozY = 525;

    buttonShiftLeftVect.pozX = 240;
    buttonShiftLeftVect.pozY = 510;
    buttonShiftLeftVect.width = 340;
    buttonShiftLeftVect.height = 50;

    strcpy(buttonShiftLeftVect.text.buttonText, "Shiftare la Stanga");
    buttonShiftLeftVect.text.pozX = 250;
    buttonShiftLeftVect.text.pozY = 525;

    buttonShiftRightVect.pozX = 610;
    buttonShiftRightVect.pozY = 510;
    buttonShiftRightVect.width = 355;
    buttonShiftRightVect.height = 50;

    strcpy(buttonShiftRightVect.text.buttonText, "Shiftare la Dreapta");
    buttonShiftRightVect.text.pozX = 620;
    buttonShiftRightVect.text.pozY = 525;

    buttonProductScalarVect.pozX = 40;
    buttonProductScalarVect.pozY = 590;
    buttonProductScalarVect.width = 370;
    buttonProductScalarVect.height = 50;

    strcpy(buttonProductScalarVect.text.buttonText, "Inmultire cu Scalar:");
    buttonProductScalarVect.text.pozX = 50;
    buttonProductScalarVect.text.pozY = 605;

    buttonNextElementVect.pozX = 1200;
    buttonNextElementVect.pozY = 270;
    buttonNextElementVect.width = 50;
    buttonNextElementVect.height = 50;

    buttonDeleteElementVect.pozX = 1130;
    buttonDeleteElementVect.pozY = 270;
    buttonDeleteElementVect.width = 50;
    buttonDeleteElementVect.height = 50;

    buttonPreviewElementVect.pozX = 1060;
    buttonPreviewElementVect.pozY = 270;
    buttonPreviewElementVect.width = 50;
    buttonPreviewElementVect.height = 50;

    buttonMainMatrix_LineIncrease.pozX = 320;
    buttonMainMatrix_LineIncrease.pozY = 213;
    buttonMainMatrix_LineIncrease.height = 40;
    buttonMainMatrix_LineIncrease.width = 40;

    buttonMainMatrix_LineDowncrease.pozX = 210;
    buttonMainMatrix_LineDowncrease.pozY = 213;
    buttonMainMatrix_LineDowncrease.height = 40;
    buttonMainMatrix_LineDowncrease.width = 40;

    buttonMainMatrix_ColumnIncrease.pozX = 320;
    buttonMainMatrix_ColumnIncrease.pozY = 268;
    buttonMainMatrix_ColumnIncrease.height = 40;
    buttonMainMatrix_ColumnIncrease.width = 40;

    buttonMainMatrix_ColumnDowncrease.pozX = 210;
    buttonMainMatrix_ColumnDowncrease.pozY = 268;
    buttonMainMatrix_ColumnDowncrease.height = 40;
    buttonMainMatrix_ColumnDowncrease.width = 40;

    buttonSecondMatrix_ColumnIncrease.pozX = 757;
    buttonSecondMatrix_ColumnIncrease.pozY = 213;
    buttonSecondMatrix_ColumnIncrease.height = 40;
    buttonSecondMatrix_ColumnIncrease.width = 40;

    buttonSecondMatrix_ColumnDowncrease.pozX = 647;
    buttonSecondMatrix_ColumnDowncrease.pozY = 213;
    buttonSecondMatrix_ColumnDowncrease.height = 40;
    buttonSecondMatrix_ColumnDowncrease.width = 40;

    buttonSumMatrix.pozX = 30;
    buttonSumMatrix.pozY = 358;
    buttonSumMatrix.width = 170;
    buttonSumMatrix.height = 40;

    strcpy(buttonSumMatrix.text.buttonText, "Adunare");
    buttonSumMatrix.text.pozX = 40;
    buttonSumMatrix.text.pozY = 363;

    buttonDecreaseMatrix.pozX = 230;
    buttonDecreaseMatrix.pozY = 358;
    buttonDecreaseMatrix.width = 170;
    buttonDecreaseMatrix.height = 40;

    strcpy(buttonDecreaseMatrix.text.buttonText, "Scadere");
    buttonDecreaseMatrix.text.pozX = 240;
    buttonDecreaseMatrix.text.pozY = 363;

    buttonProductMatrix.pozX = 30;
    buttonProductMatrix.pozY = 418;
    buttonProductMatrix.width = 180;
    buttonProductMatrix.height = 40;

    strcpy(buttonProductMatrix.text.buttonText, "Inmultire");
    buttonProductMatrix.text.pozX = 40;
    buttonProductMatrix.text.pozY = 423;

    buttonDivisionMatrix.pozX = 240;
    buttonDivisionMatrix.pozY = 418;
    buttonDivisionMatrix.width = 180;
    buttonDivisionMatrix.height = 40;

    strcpy(buttonDivisionMatrix.text.buttonText, "Impartire");
    buttonDivisionMatrix.text.pozX = 250;
    buttonDivisionMatrix.text.pozY = 423;

    buttonPowMatrix.pozX = 30;
    buttonPowMatrix.pozY = 478;
    buttonPowMatrix.width = 350;
    buttonPowMatrix.height = 40;

    strcpy(buttonPowMatrix.text.buttonText, "Ridicarea la putere");
    buttonPowMatrix.text.pozX = 40;
    buttonPowMatrix.text.pozY = 485;

    buttonTransposeMatrix.pozX = 30;
    buttonTransposeMatrix.pozY = 538;
    buttonTransposeMatrix.width = 200;
    buttonTransposeMatrix.height = 40;

    strcpy(buttonTransposeMatrix.text.buttonText, "Transpusa");
    buttonTransposeMatrix.text.pozX = 40;
    buttonTransposeMatrix.text.pozY = 545;

    buttonInverseMatrix.pozX = 30;
    buttonInverseMatrix.pozY = 598;
    buttonInverseMatrix.width = 145;
    buttonInverseMatrix.height = 40;

    strcpy(buttonInverseMatrix.text.buttonText, "Inversa");
    buttonInverseMatrix.text.pozX = 40;
    buttonInverseMatrix.text.pozY = 605;

    buttonDetMatrix.pozX = 30;
    buttonDetMatrix.pozY = 658;
    buttonDetMatrix.width = 240;
    buttonDetMatrix.height = 40;

    strcpy(buttonDetMatrix.text.buttonText, "Determinant");
    buttonDetMatrix.text.pozX = 40;
    buttonDetMatrix.text.pozY = 665;

    buttonSumElem_BelowMainDiagonal.pozX = 500;
    buttonSumElem_BelowMainDiagonal.pozY = 658;
    buttonSumElem_BelowMainDiagonal.width = 40;
    buttonSumElem_BelowMainDiagonal.height = 40;

    buttonSumElem_MainDiagonal.pozX = 540;
    buttonSumElem_MainDiagonal.pozY = 658;
    buttonSumElem_MainDiagonal.width = 40;
    buttonSumElem_MainDiagonal.height = 40;

    buttonSumElem_OverMainDiagonal.pozX = 580;
    buttonSumElem_OverMainDiagonal.pozY = 658;
    buttonSumElem_OverMainDiagonal.width = 40;
    buttonSumElem_OverMainDiagonal.height = 40;

    buttonSumElem_BelowSecondDiagonal.pozX = 680;
    buttonSumElem_BelowSecondDiagonal.pozY = 658;
    buttonSumElem_BelowSecondDiagonal.width = 40;
    buttonSumElem_BelowSecondDiagonal.height = 40;

    buttonSumElem_SecondDiagonal.pozX = 720;
    buttonSumElem_SecondDiagonal.pozY = 658;
    buttonSumElem_SecondDiagonal.width = 40;
    buttonSumElem_SecondDiagonal.height = 40;

    buttonSumElem_OverSecondDiagonal.pozX = 760;
    buttonSumElem_OverSecondDiagonal.pozY = 658;
    buttonSumElem_OverSecondDiagonal.width = 40;
    buttonSumElem_OverSecondDiagonal.height = 40;

    backgroundColor_Red.pozX = 680;
    backgroundColor_Red.pozY = 250;
    backgroundColor_Red.width = 150;
    backgroundColor_Red.height = 40;
    backgroundColor_Red.value = 8;

    strcpy(backgroundColor_Red.text.buttonText, "R: 8");

    backgroundColor_Green.pozX = 815;
    backgroundColor_Green.pozY = 250;
    backgroundColor_Green.width = 150;
    backgroundColor_Green.height = 40;
    backgroundColor_Green.value = 12;

    strcpy(backgroundColor_Green.text.buttonText, "G: 12");

    backgroundColor_Blue.pozX = 950;
    backgroundColor_Blue.pozY = 250;
    backgroundColor_Blue.width = 150;
    backgroundColor_Blue.height = 40;
    backgroundColor_Blue.value = 37;

    strcpy(backgroundColor_Blue.text.buttonText, "B: 37");

    buttonSetBackgroundColor.pozX = 1100;
    buttonSetBackgroundColor.pozY = 240;
    buttonSetBackgroundColor.width = 150;
    buttonSetBackgroundColor.height = 40;

    strcpy(buttonSetBackgroundColor.text.buttonText, "Seteaza");
    buttonSetBackgroundColor.text.pozX = 1105;
    buttonSetBackgroundColor.text.pozY = 247;

    speed_0.pozX = 680;
    speed_0.pozY = 350;

    speed_100.pozX = 750;
    speed_100.pozY = 350;

    speed_600.pozX = 850;
    speed_600.pozY = 350;
    speed_600.press = true;

    speed_1000.pozX = 950;
    speed_1000.pozY = 350;
}
void InitializationVectorHomeScreen()
{
    cleardevice();

    buttonBack.show = true;

    buttonAddVector.show = true;

    DrawVectorButtons();

    DrawVector();
}
void InitializationMatrixHomeScreen()
{
    cleardevice();

    showButtonsMatrix = true;

    buttonBack.show = true;

    DrawMatrixButtons();

    int x = 20, y = 30;

    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {

            if(mainMatrix.generated == false)
            {
                if(mainMatrix.element[i][j] == NULL) mainMatrix.element[i][j] = new Nod;

                mainMatrix.element[i][j]->width = 4 * 20;
                mainMatrix.element[i][j]->height = 32;
                mainMatrix.element[i][j]->pozX = x;
                mainMatrix.element[i][j]->pozY = y;

                mainMatrix.show = true;
            }

            if(secondMatrix.generated == false)
            {
                secondMatrix.element[i][j] = new Nod;

                secondMatrix.element[i][j]->width = 4 * 20;
                secondMatrix.element[i][j]->height = 32;
                secondMatrix.element[i][j]->pozX = x + 437;
                secondMatrix.element[i][j]->pozY = y;
            }

            if(resultMatrix.generated == false)
            {
                resultMatrix.element[i][j] = new Nod;

                resultMatrix.element[i][j]->width = 4 * 20;
                resultMatrix.element[i][j]->height = 32;
                resultMatrix.element[i][j]->pozX = x + 874;
                resultMatrix.element[i][j]->pozY = y;
            }

            x += 95;
        }
        y += 47;
        x = 20;
    }

    mainMatrix.generated = true;
    secondMatrix.generated = true;
    resultMatrix.generated = true;

    DrawMainMatrix();
}
void InitializationSettingsHomeScreen()
{
    buttonBack.show = true;

    DrawSettingsScreen();
}
void InitializationMatrixButtonsPress(Button *button)
{

    buttonSumMatrix.press = false;
    buttonProductMatrix.press = false;
    buttonDecreaseMatrix.press = false;
    buttonTransposeMatrix.press = false;
    buttonPowMatrix.press = false;
    buttonDivisionMatrix.press = false;
    buttonDetMatrix.press = false;
    buttonInverseMatrix.press = false;

    if(button != NULL) button->press = true;
}

void SaveFile_Vector()
{
    ofstream out("vector.out");

    Nod *p = vect->FirstElement;

    while(p != NULL)
    {
        out << p->value << " ";

        p = p->nextElement;
    }

    out.close();
}
void SaveFile_Matrix()
{
    ofstream out("matrix.out");

    out << mainMatrix.height << " " << mainMatrix.width << endl;

    for(int i = 1; i <= mainMatrix.height; i++)
    {
        for(int j = 1; j <= mainMatrix.width; j++)
            out << mainMatrix.element[i][j]->value << " ";
        out << endl;
    }

    out.close();
}
void SaveFile_Settings()
{
    ofstream out("settings.out");

    out << settings.backgroundColor_Red << " " << settings.backgroundColor_Green << " " << settings.backgroundColor_Blue << endl;

    out << settings.animationSpeed << endl;

    out << settings.playFXSounds;

    out.close();
}
void LoadData()
{
    ifstream in_vector("vector.out");

    vect->FirstElement = NULL;
    vect->LastElement = NULL;
    vect->totalItems = 0;
    vect->selectedElement = 0;

    int nr;
    char sir[20];
    Nod *p;

    while(in_vector >> nr)
    {
        itoa(nr, sir, 10);

        p = new Nod;
        strcpy(p->value, sir);
        p->nextElement = NULL;

        if(vect->totalItems == 0)
        {
            p->PreviewElement = NULL;
            vect->FirstElement = p;
            vect->LastElement = p;
        }
        else
        {
            p->PreviewElement = vect->LastElement;
            vect->LastElement->nextElement = p;
            vect->LastElement = p;
        }
        vect->totalItems++;
    }

    in_vector.close();

    ifstream in_matrix("matrix.out");

    int n, m;

    in_matrix >> n >> m;

    mainMatrix.height = n;
    mainMatrix.width = m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            nr = 0;

            in_matrix >> nr;

            mainMatrix.element[i][j]->valueInt = nr;

            itoa(nr, sir, 10);

            strcpy(mainMatrix.element[i][j]->value, sir);
        }
    }

    in_matrix.close();

    ifstream in_settings("settings.out");

    int red, green, blue;

    in_settings >> red >> green >> blue;

    backgroundColor_Red.value = red;
    backgroundColor_Green.value = green;
    backgroundColor_Blue.value = blue;

    char sir2[10];

    itoa(red, sir2, 10);
    strcpy(sir, "R: ");
    strcat(sir, sir2);
    strcpy(backgroundColor_Red.text.buttonText, sir);

    itoa(green, sir2, 10);
    strcpy(sir, "G: ");
    strcat(sir, sir2);
    strcpy(backgroundColor_Green.text.buttonText, sir);

    itoa(blue, sir2, 10);
    strcpy(sir, "B: ");
    strcat(sir, sir2);
    strcpy(backgroundColor_Blue.text.buttonText, sir);

    settings.backgroundColor = RGB(red, green, blue);

    setbkcolor(settings.backgroundColor);
    cleardevice();

    DrawHomeScreen();

    in_settings >> settings.animationSpeed;

    speed_600.press = false;
    if(settings.animationSpeed == 0) speed_0.press = true;
    if(settings.animationSpeed == 100) speed_100.press = true;
    if(settings.animationSpeed == 600) speed_600.press = true;
    if(settings.animationSpeed == 1000) speed_1000.press = true;

    in_settings >> settings.playFXSounds;

    in_settings.close();
}

/*
    Fuctille de desenare
*/
void DrawHomeScreen()
{
    setcolor(WHITE);

    settextstyle(9, 0, 7);

    setcolor(RGB(0, 170, 160));
    outtextxy(screenWidth / 2 - 140, 100, "Bib");
    setcolor(RGB(255, 122, 90));
    outtextxy(screenWidth / 2, 100, "Mat");

    setcolor(WHITE);
    settextstyle(9, 0, 5);

    rectangle(buttonVector.pozX, buttonVector.pozY, buttonVector.pozX + buttonVector.width, buttonVector.pozY + buttonVector.height);
    outtextxy(buttonVector.text.pozX, buttonVector.text.pozY, buttonVector.text.buttonText);

    buttonVector.show = true;

    rectangle(buttonMatrix.pozX, buttonMatrix.pozY, buttonMatrix.pozX + buttonMatrix.width, buttonMatrix.pozY + buttonMatrix.height);
    outtextxy(buttonMatrix.text.pozX, buttonMatrix.text.pozY, buttonMatrix.text.buttonText);

    buttonMatrix.show = true;

    settextstyle(9, 0, 4);

    rectangle(buttonSettings.pozX, buttonSettings.pozY, buttonSettings.pozX + buttonSettings.width, buttonSettings.pozY + buttonSettings.height);
    outtextxy(buttonSettings.text.pozX, buttonSettings.text.pozY, buttonSettings.text.buttonText);

    rectangle(buttonLoadData.pozX, buttonLoadData.pozY, buttonLoadData.pozX + buttonLoadData.width, buttonLoadData.pozY + buttonLoadData.height);
    outtextxy(buttonLoadData.text.pozX, buttonLoadData.text.pozY, buttonLoadData.text.buttonText);

    rectangle(buttonQuit.pozX, buttonQuit.pozY, buttonQuit.pozX + buttonQuit.width, buttonQuit.pozY + buttonQuit.height);
    outtextxy(buttonQuit.text.pozX, buttonQuit.text.pozY, buttonQuit.text.buttonText);

    buttonMatrix.show = true;
    buttonVector.show = true;
    buttonSettings.show = true;
    buttonLoadData.show = true;

    buttonBack.show = false;
}
void DrawSettingsScreen()
{
    setcolor(RGB(0, 170, 160));
    settextstyle(9, 0, 7);
    outtextxy(screenWidth / 2 - 140, 100, "Setari");

    setcolor(WHITE);
    settextstyle(9, 0, 4);

    rectangle(buttonBack.pozX, buttonBack.pozY, buttonBack.pozX + buttonBack.width, buttonBack.pozY + buttonBack.height);
    outtextxy(buttonBack.text.pozX, buttonBack.text.pozY, buttonBack.text.buttonText);

    setcolor(WHITE);
    outtextxy(50, 250, "Culoare Fundal:");

    setcolor(RED);
    outtextxy(backgroundColor_Red.pozX, backgroundColor_Red.pozY, backgroundColor_Red.text.buttonText);
    setcolor(GREEN);
    outtextxy(backgroundColor_Green.pozX, backgroundColor_Green.pozY, backgroundColor_Green.text.buttonText);
    setcolor(LIGHTBLUE);
    outtextxy(backgroundColor_Blue.pozX, backgroundColor_Blue.pozY, backgroundColor_Blue.text.buttonText);

    setcolor(WHITE);
    outtextxy(buttonSetBackgroundColor.text.pozX, buttonSetBackgroundColor.text.pozY, buttonSetBackgroundColor.text.buttonText);
    line(buttonSetBackgroundColor.pozX, buttonSetBackgroundColor.pozY + buttonSetBackgroundColor.height, buttonSetBackgroundColor.pozX + buttonSetBackgroundColor.width, buttonSetBackgroundColor.pozY + buttonSetBackgroundColor.height);

    setcolor(WHITE);
    outtextxy(50, 350, "Viteza Animatiilor:");

    setcolor(WHITE);
    if(speed_0.press == false) outtextxy(speed_0.pozX, speed_0.pozY, "0");
    if(speed_100.press == false) outtextxy(speed_100.pozX, speed_100.pozY, "100");
    if(speed_600.press == false) outtextxy(speed_600.pozX, speed_600.pozY, "600");
    if(speed_1000.press == false) outtextxy(speed_1000.pozX, speed_1000.pozY, "1000");

    setcolor(LIGHTBLUE);
    if(speed_0.press == true) outtextxy(speed_0.pozX, speed_0.pozY, "0");
    if(speed_100.press == true) outtextxy(speed_100.pozX, speed_100.pozY, "100");
    if(speed_600.press == true) outtextxy(speed_600.pozX, speed_600.pozY, "600");
    if(speed_1000.press == true) outtextxy(speed_1000.pozX, speed_1000.pozY, "1000");

    setcolor(WHITE);
    outtextxy(50, 450, "Sunete:");

    setcolor(WHITE);
    outtextxy(710, 450, "Pornite");
    outtextxy(910, 450, "Oprite");

    setcolor(LIGHTBLUE);
    if(settings.playFXSounds == true) outtextxy(710, 450, "Pornite");
    if(settings.playFXSounds == false) outtextxy(910, 450, "Oprite");

    setlinestyle(4, 0, 3);
    setcolor(WHITE);
    line(50, 285, buttonSetBackgroundColor.pozX - 50, 285);
    line(50, 385, buttonSetBackgroundColor.pozX - 50, 385);
    line(50, 485, buttonSetBackgroundColor.pozX - 50, 485);

    setlinestyle(0, 0, 3);
}
void SetNumberBoxData(int &x, int &y, Nod *p)
{

    p->width = 12 + strlen(p->value) * 21.5;

    if(x + p->width + 40 > screenWidth)
    {
        x = 40;
        y += 70;
    }

    p->text.pozX = x + 6;
    p->text.pozY = y + 10;
}
void DrawVector()
{

    int i, x = 40, y = 30;

    Nod *p = new Nod;
    p = vect->FirstElement;

    while(p != NULL)
    {
        SetNumberBoxData(x, y, p);

        p->pozX = x;
        p->pozY = y;

        setcolor(WHITE);
        settextstyle(9, 0, 4);
        outtextxy(p->text.pozX, p->text.pozY, p->value);

        if(p == vect->selectedElement)
        {
            setcolor(LIGHTRED);
        }
        else
        {
            setcolor(LIGHTBLUE);
        }

        rectangle(x, y, x + p->width, y + p->height);

        x += p->width + 20;

        p = p->nextElement;
    }

    if(x + buttonAddVector.width + 40 > screenWidth)
    {
        x = 40;
        y += 70;
    }

    if(y  <= 110)
    {
        buttonAddVector.pozX = x;
        buttonAddVector.pozY = y;

        setcolor(LIGHTCYAN);
        rectangle(x, y, x + buttonAddVector.width, y + buttonAddVector.height);

        setcolor(WHITE);
        line(x + buttonAddVector.width / 2, y + 10, x + buttonAddVector.width / 2, y + buttonAddVector.height - 10);;
        line(x + buttonAddVector.width / 2 - 20, y + buttonAddVector.height / 2, x + buttonAddVector.width / 2 + 20, y + buttonAddVector.height / 2);

        buttonAddVector.show = true;
    }
    else
    {
        buttonAddVector.show = false;
    }
}
void DrawVectorButtons()
{
    setcolor(WHITE);
    settextstyle(9, 0, 4);

    rectangle(buttonBack.pozX, buttonBack.pozY, buttonBack.pozX + buttonBack.width, buttonBack.pozY + buttonBack.height);
    outtextxy(buttonBack.text.pozX, buttonBack.text.pozY, buttonBack.text.buttonText);

    line(buttonSumVect.pozX, buttonSumVect.pozY + buttonSumVect.height, buttonSumVect.pozX + buttonSumVect.width, buttonSumVect.pozY + buttonSumVect.height);
    outtextxy(buttonSumVect.text.pozX, buttonSumVect.text.pozY, buttonSumVect.text.buttonText);

    line(buttonProductVect.pozX, buttonProductVect.pozY + buttonProductVect.height, buttonProductVect.pozX + buttonProductVect.width, buttonProductVect.pozY + buttonProductVect.height);
    outtextxy(buttonProductVect.text.pozX, buttonProductVect.text.pozY, buttonProductVect.text.buttonText);

    line(buttonSortVect.pozX, buttonSortVect.pozY + buttonSortVect.height, buttonSortVect.pozX + buttonSortVect.width, buttonSortVect.pozY + buttonSortVect.height);
    outtextxy(buttonSortVect.text.pozX, buttonSortVect.text.pozY, buttonSortVect.text.buttonText);

    line(buttonShiftVect.pozX, buttonShiftVect.pozY + buttonShiftVect.height, buttonShiftVect.pozX + buttonShiftVect.width, buttonShiftVect.pozY + buttonShiftVect.height);
    outtextxy(buttonShiftVect.text.pozX, buttonShiftVect.text.pozY, buttonShiftVect.text.buttonText);

    line(buttonProductScalarVect.pozX, buttonProductScalarVect.pozY + buttonProductScalarVect.height, buttonProductScalarVect.pozX + buttonProductScalarVect.width, buttonProductScalarVect.pozY + buttonProductScalarVect.height);
    outtextxy(buttonProductScalarVect.text.pozX, buttonProductScalarVect.text.pozY, buttonProductScalarVect.text.buttonText);

    rectangle(buttonNextElementVect.pozX, buttonNextElementVect.pozY, buttonNextElementVect.pozX + buttonNextElementVect.width, buttonNextElementVect.pozY + buttonNextElementVect.height);
    line(buttonNextElementVect.pozX + buttonNextElementVect.width / 4, buttonNextElementVect.pozY + 10, buttonNextElementVect.pozX + buttonNextElementVect.width - 10, buttonNextElementVect.pozY + buttonNextElementVect.height / 2);
    line(buttonNextElementVect.pozX + buttonNextElementVect.width / 4, buttonNextElementVect.pozY + buttonNextElementVect.height - 10, buttonNextElementVect.pozX + buttonNextElementVect.width - 10, buttonNextElementVect.pozY + buttonNextElementVect.height / 2);

    rectangle(buttonDeleteElementVect.pozX, buttonNextElementVect.pozY, buttonDeleteElementVect.pozX + buttonDeleteElementVect.width, buttonDeleteElementVect.pozY + buttonDeleteElementVect.height);
    line(buttonDeleteElementVect.pozX + 10, buttonDeleteElementVect.pozY + 10, buttonDeleteElementVect.pozX + buttonDeleteElementVect.width - 10, buttonDeleteElementVect.pozY + buttonDeleteElementVect.height - 10);
    line(buttonDeleteElementVect.pozX + buttonDeleteElementVect.width - 10, buttonDeleteElementVect.pozY + 10, buttonDeleteElementVect.pozX + 10, buttonDeleteElementVect.pozY + buttonDeleteElementVect.height - 10);

    rectangle(buttonPreviewElementVect.pozX, buttonPreviewElementVect.pozY, buttonPreviewElementVect.pozX + buttonPreviewElementVect.width, buttonPreviewElementVect.pozY + buttonPreviewElementVect.height);
    line(buttonPreviewElementVect.pozX + buttonPreviewElementVect.width - 10, buttonPreviewElementVect.pozY + 10, buttonPreviewElementVect.pozX + 10, buttonPreviewElementVect.pozY + buttonPreviewElementVect.height / 2);
    line(buttonPreviewElementVect.pozX + buttonPreviewElementVect.width - 10, buttonPreviewElementVect.pozY + buttonPreviewElementVect.height - 10, buttonPreviewElementVect.pozX + 10, buttonPreviewElementVect.pozY + buttonPreviewElementVect.height / 2);
}
void DrawMatrixButtons()
{
    setcolor(WHITE);

    rectangle(buttonBack.pozX, buttonBack.pozY, buttonBack.pozX + buttonBack.width, buttonBack.pozY + buttonBack.height);
    outtextxy(buttonBack.text.pozX, buttonBack.text.pozY, buttonBack.text.buttonText);

    settextstyle(9, 0, 4);
    outtextxy(buttonSumMatrix.text.pozX, buttonSumMatrix.text.pozY, buttonSumMatrix.text.buttonText);
    line(buttonSumMatrix.pozX, buttonSumMatrix.pozY + buttonSumMatrix.height, buttonSumMatrix.pozX + buttonSumMatrix.width, buttonSumMatrix.pozY + buttonSumMatrix.height);

    settextstyle(9, 0, 4);
    outtextxy(buttonProductMatrix.text.pozX, buttonProductMatrix.text.pozY, buttonProductMatrix.text.buttonText);
    line(buttonProductMatrix.pozX, buttonProductMatrix.pozY + buttonProductMatrix.height, buttonProductMatrix.pozX + buttonProductMatrix.width, buttonProductMatrix.pozY + buttonProductMatrix.height);

    settextstyle(9, 0, 4);
    outtextxy(buttonDecreaseMatrix.text.pozX, buttonDecreaseMatrix.text.pozY, buttonDecreaseMatrix.text.buttonText);
    line(buttonDecreaseMatrix.pozX, buttonDecreaseMatrix.pozY + buttonDecreaseMatrix.height, buttonDecreaseMatrix.pozX + buttonDecreaseMatrix.width, buttonDecreaseMatrix.pozY + buttonDecreaseMatrix.height);

    settextstyle(9, 0, 4);
    outtextxy(buttonDivisionMatrix.text.pozX, buttonDivisionMatrix.text.pozY, buttonDivisionMatrix.text.buttonText);
    line(buttonDivisionMatrix.pozX, buttonDivisionMatrix.pozY + buttonDivisionMatrix.height, buttonDivisionMatrix.pozX + buttonDivisionMatrix.width, buttonDivisionMatrix.pozY + buttonDivisionMatrix.height);

    settextstyle(9, 0, 4);
    outtextxy(buttonPowMatrix.text.pozX, buttonPowMatrix.text.pozY, buttonPowMatrix.text.buttonText);
    line(buttonPowMatrix.pozX, buttonPowMatrix.pozY + buttonPowMatrix.height, buttonPowMatrix.pozX + buttonPowMatrix.width, buttonPowMatrix.pozY + buttonPowMatrix.height);

    settextstyle(9, 0, 4);
    outtextxy(buttonTransposeMatrix.text.pozX, buttonTransposeMatrix.text.pozY, buttonTransposeMatrix.text.buttonText);
    line(buttonTransposeMatrix.pozX, buttonTransposeMatrix.pozY + buttonTransposeMatrix.height, buttonTransposeMatrix.pozX + buttonTransposeMatrix.width, buttonTransposeMatrix.pozY + buttonTransposeMatrix.height);

    settextstyle(9, 0, 4);
    outtextxy(buttonInverseMatrix.text.pozX, buttonInverseMatrix.text.pozY, buttonInverseMatrix.text.buttonText);
    line(buttonInverseMatrix.pozX, buttonInverseMatrix.pozY + buttonInverseMatrix.height, buttonInverseMatrix.pozX + buttonInverseMatrix.width, buttonInverseMatrix.pozY + buttonInverseMatrix.height);

    settextstyle(9, 0, 4);
    outtextxy(buttonDetMatrix.text.pozX, buttonDetMatrix.text.pozY, buttonDetMatrix.text.buttonText);
    line(buttonDetMatrix.pozX, buttonDetMatrix.pozY + buttonDetMatrix.height, buttonDetMatrix.pozX + buttonDetMatrix.width, buttonDetMatrix.pozY + buttonDetMatrix.height);

    line(buttonSumElem_BelowMainDiagonal.pozX, buttonSumElem_BelowMainDiagonal.pozY, buttonSumElem_BelowMainDiagonal.pozX, buttonSumElem_BelowMainDiagonal.pozY + buttonSumElem_BelowMainDiagonal.height);
    line(buttonSumElem_BelowMainDiagonal.pozX, buttonSumElem_BelowMainDiagonal.pozY + buttonSumElem_BelowMainDiagonal.height, buttonSumElem_BelowMainDiagonal.pozX + buttonSumElem_BelowMainDiagonal.width, buttonSumElem_BelowMainDiagonal.pozY + buttonSumElem_BelowMainDiagonal.height);
    line(buttonSumElem_BelowMainDiagonal.pozX + buttonSumElem_BelowMainDiagonal.width, buttonSumElem_BelowMainDiagonal.pozY + buttonSumElem_BelowMainDiagonal.height, buttonSumElem_BelowMainDiagonal.pozX, buttonSumElem_BelowMainDiagonal.pozY);

    line(buttonSumElem_MainDiagonal.pozX, buttonSumElem_MainDiagonal.pozY, buttonSumElem_MainDiagonal.pozX + buttonSumElem_MainDiagonal.width, buttonSumElem_MainDiagonal.pozY + buttonSumElem_MainDiagonal.height);

    line(buttonSumElem_OverMainDiagonal.pozX, buttonSumElem_OverMainDiagonal.pozY, buttonSumElem_OverMainDiagonal.pozX + buttonSumElem_OverMainDiagonal.width, buttonSumElem_OverMainDiagonal.pozY);
    line(buttonSumElem_OverMainDiagonal.pozX + buttonSumElem_OverMainDiagonal.width, buttonSumElem_OverMainDiagonal.pozY, buttonSumElem_OverMainDiagonal.pozX + buttonSumElem_OverMainDiagonal.width, buttonSumElem_OverMainDiagonal.pozY + buttonSumElem_OverMainDiagonal.height);
    line(buttonSumElem_OverMainDiagonal.pozX + buttonSumElem_OverMainDiagonal.width, buttonSumElem_OverMainDiagonal.pozY + buttonSumElem_OverMainDiagonal.height, buttonSumElem_OverMainDiagonal.pozX, buttonSumElem_OverMainDiagonal.pozY);

    line(buttonSumElem_BelowSecondDiagonal.pozX, buttonSumElem_BelowSecondDiagonal.pozY, buttonSumElem_BelowSecondDiagonal.pozX + buttonSumElem_BelowSecondDiagonal.width, buttonSumElem_BelowSecondDiagonal.pozY);
    line(buttonSumElem_BelowSecondDiagonal.pozX + buttonSumElem_BelowSecondDiagonal.width, buttonSumElem_BelowSecondDiagonal.pozY, buttonSumElem_BelowSecondDiagonal.pozX, buttonSumElem_BelowSecondDiagonal.pozY + buttonSumElem_BelowSecondDiagonal.height);
    line(buttonSumElem_BelowSecondDiagonal.pozX, buttonSumElem_BelowSecondDiagonal.pozY + buttonSumElem_BelowSecondDiagonal.height, buttonSumElem_BelowSecondDiagonal.pozX, buttonSumElem_BelowSecondDiagonal.pozY);

    line(buttonSumElem_SecondDiagonal.pozX + buttonSumElem_SecondDiagonal.width, buttonSumElem_SecondDiagonal.pozY, buttonSumElem_SecondDiagonal.pozX, buttonSumElem_SecondDiagonal.pozY + buttonSumElem_SecondDiagonal.height);

    line(buttonSumElem_OverSecondDiagonal.pozX + buttonSumElem_OverSecondDiagonal.height, buttonSumElem_OverSecondDiagonal.pozY, buttonSumElem_OverSecondDiagonal.pozX + buttonSumElem_OverSecondDiagonal.width, buttonSumElem_OverSecondDiagonal.pozY + buttonSumElem_OverSecondDiagonal.height);
    line(buttonSumElem_OverSecondDiagonal.pozX + buttonSumElem_OverSecondDiagonal.width, buttonSumElem_OverSecondDiagonal.pozY + buttonSumElem_OverSecondDiagonal.height, buttonSumElem_OverSecondDiagonal.pozX, buttonSumElem_OverSecondDiagonal.pozY + buttonSumElem_OverSecondDiagonal.height);
    line(buttonSumElem_OverSecondDiagonal.pozX, buttonSumElem_OverSecondDiagonal.pozY + buttonSumElem_OverSecondDiagonal.height, buttonSumElem_OverSecondDiagonal.pozX + buttonSumElem_OverSecondDiagonal.width, buttonSumElem_OverSecondDiagonal.pozY);

}
void DrawMainMatrix()
{

    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            if(i <= mainMatrix.height and j <= mainMatrix.width)
            {
                if(mainMatrix.selectedElement == mainMatrix.element[i][j])
                {
                    setcolor(LIGHTRED);
                }
                else
                {
                    setcolor(LIGHTBLUE);
                }
                rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);

                settextstyle(9, 0, 3);
                setcolor(WHITE);
                outtextxy(mainMatrix.element[i][j]->pozX + 10, mainMatrix.element[i][j]->pozY + 5, mainMatrix.element[i][j]->value);

                mainMatrix.element[i][j]->on = true;
            }
            else
            {
                setcolor(LIGHTGRAY);
                rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);

                strcpy(mainMatrix.element[i][j]->value, "");

                settextstyle(9, 0, 3);
                outtextxy(mainMatrix.element[i][j]->pozX + 10, mainMatrix.element[i][j]->pozY + 5, "    ");

                mainMatrix.element[i][j]->on = false;
            }
        }
    }

    setcolor(WHITE);
    settextstyle(9, 0, 4);
    outtextxy(mainMatrix.element[4][1]->pozX, mainMatrix.element[4][1]->pozY + mainMatrix.element[4][1]->height + 20, "Linii: ");
    outtextxy(mainMatrix.element[4][1]->pozX, 278, "Coloane: ");

    setcolor(GREEN);
    rectangle(buttonMainMatrix_LineIncrease.pozX, buttonMainMatrix_LineIncrease.pozY, buttonMainMatrix_LineIncrease.pozX + buttonMainMatrix_LineIncrease.width, buttonMainMatrix_LineIncrease.pozY + buttonMainMatrix_LineIncrease.height);
    setcolor(WHITE);
    line(buttonMainMatrix_LineIncrease.pozX + buttonMainMatrix_LineIncrease.width / 4, buttonMainMatrix_LineIncrease.pozY + 10, buttonMainMatrix_LineIncrease.pozX + buttonMainMatrix_LineIncrease.width - 10, buttonMainMatrix_LineIncrease.pozY + buttonMainMatrix_LineIncrease.height / 2);
    line(buttonMainMatrix_LineIncrease.pozX + buttonMainMatrix_LineIncrease.width / 4, buttonMainMatrix_LineIncrease.pozY + buttonMainMatrix_LineIncrease.height - 10, buttonMainMatrix_LineIncrease.pozX + buttonMainMatrix_LineIncrease.width - 10, buttonMainMatrix_LineIncrease.pozY + buttonMainMatrix_LineIncrease.height / 2);

    setcolor(GREEN);
    rectangle(buttonMainMatrix_LineDowncrease.pozX, buttonMainMatrix_LineDowncrease.pozY, buttonMainMatrix_LineDowncrease.pozX + buttonMainMatrix_LineDowncrease.width, buttonMainMatrix_LineDowncrease.pozY + buttonMainMatrix_LineDowncrease.height);
    setcolor(WHITE);
    line(buttonMainMatrix_LineDowncrease.pozX + buttonMainMatrix_LineDowncrease.width - 10, buttonMainMatrix_LineDowncrease.pozY + 10, buttonMainMatrix_LineDowncrease.pozX + 10, buttonMainMatrix_LineDowncrease.pozY + buttonMainMatrix_LineDowncrease.height / 2);
    line(buttonMainMatrix_LineDowncrease.pozX + buttonMainMatrix_LineDowncrease.width - 10, buttonMainMatrix_LineDowncrease.pozY + buttonMainMatrix_LineDowncrease.height - 10, buttonMainMatrix_LineDowncrease.pozX + 10, buttonMainMatrix_LineDowncrease.pozY + buttonMainMatrix_LineDowncrease.height / 2);

    setcolor(GREEN);
    rectangle(buttonMainMatrix_ColumnIncrease.pozX, buttonMainMatrix_ColumnIncrease.pozY, buttonMainMatrix_ColumnIncrease.pozX + buttonMainMatrix_ColumnIncrease.width, buttonMainMatrix_ColumnIncrease.pozY + buttonMainMatrix_ColumnIncrease.height);
    setcolor(WHITE);
    line(buttonMainMatrix_ColumnIncrease.pozX + buttonMainMatrix_ColumnIncrease.width / 4, buttonMainMatrix_ColumnIncrease.pozY + 10, buttonMainMatrix_ColumnIncrease.pozX + buttonMainMatrix_ColumnIncrease.width - 10, buttonMainMatrix_ColumnIncrease.pozY + buttonMainMatrix_ColumnIncrease.height / 2);
    line(buttonMainMatrix_ColumnIncrease.pozX + buttonMainMatrix_ColumnIncrease.width / 4, buttonMainMatrix_ColumnIncrease.pozY + buttonMainMatrix_ColumnIncrease.height - 10, buttonMainMatrix_ColumnIncrease.pozX + buttonMainMatrix_ColumnIncrease.width - 10, buttonMainMatrix_ColumnIncrease.pozY + buttonMainMatrix_ColumnIncrease.height / 2);

    setcolor(GREEN);
    rectangle(buttonMainMatrix_ColumnDowncrease.pozX, buttonMainMatrix_ColumnDowncrease.pozY, buttonMainMatrix_ColumnDowncrease.pozX + buttonMainMatrix_ColumnDowncrease.width, buttonMainMatrix_ColumnDowncrease.pozY + buttonMainMatrix_ColumnDowncrease.height);
    setcolor(WHITE);
    line(buttonMainMatrix_ColumnDowncrease.pozX + buttonMainMatrix_ColumnDowncrease.width - 10, buttonMainMatrix_ColumnDowncrease.pozY + 10, buttonMainMatrix_ColumnDowncrease.pozX + 10, buttonMainMatrix_ColumnDowncrease.pozY + buttonMainMatrix_ColumnDowncrease.height / 2);
    line(buttonMainMatrix_ColumnDowncrease.pozX + buttonMainMatrix_ColumnDowncrease.width - 10, buttonMainMatrix_ColumnDowncrease.pozY + buttonMainMatrix_ColumnDowncrease.height - 10, buttonMainMatrix_ColumnDowncrease.pozX + 10, buttonMainMatrix_ColumnDowncrease.pozY + buttonMainMatrix_ColumnDowncrease.height / 2);


    char cop[2];

    itoa(mainMatrix.height, cop, 10);
    settextstyle(9, 0, 5);
    outtextxy(buttonMainMatrix_LineDowncrease.pozX + buttonMainMatrix_LineDowncrease.width + 23, buttonMainMatrix_LineDowncrease.pozY, cop);

    itoa(mainMatrix.width, cop, 10);
    settextstyle(9, 0, 5);
    outtextxy(buttonMainMatrix_ColumnDowncrease.pozX + buttonMainMatrix_ColumnDowncrease.width + 23, buttonMainMatrix_ColumnDowncrease.pozY, cop);
}
void DrawSecondMatrix()
{
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {

            if(i <= secondMatrix.height and j <= secondMatrix.width)
            {
                if(secondMatrix.selectedElement == secondMatrix.element[i][j])
                {
                    setcolor(LIGHTRED);
                }
                else
                {
                    setcolor(LIGHTBLUE);
                }
                rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);

                secondMatrix.element[i][j]->on = true;

                setcolor(WHITE);
                settextstyle(9, 0, 3);
                outtextxy(secondMatrix.element[i][j]->pozX + 10, secondMatrix.element[i][j]->pozY + 5, secondMatrix.element[i][j]->value);

            }
            else
            {
                setcolor(LIGHTGRAY);
                rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);

                strcpy(secondMatrix.element[i][j]->value, "");

                settextstyle(9, 0, 3);
                outtextxy(secondMatrix.element[i][j]->pozX + 10, secondMatrix.element[i][j]->pozY + 5, "    ");

                secondMatrix.element[i][j]->on = false;
            }
        }
    }

    setfillstyle(SOLID_FILL, settings.backgroundColor);
    bar(455, 210, 825, 255);

    if(buttonProductMatrix.press)
    {
        setcolor(WHITE);
        settextstyle(9, 0, 4);
        outtextxy(secondMatrix.element[4][1]->pozX, secondMatrix.element[4][1]->pozY + secondMatrix.element[4][1]->height + 20, "Coloane: ");

        setcolor(GREEN);
        rectangle(buttonSecondMatrix_ColumnIncrease.pozX, buttonSecondMatrix_ColumnIncrease.pozY, buttonSecondMatrix_ColumnIncrease.pozX + buttonSecondMatrix_ColumnIncrease.width, buttonSecondMatrix_ColumnIncrease.pozY + buttonSecondMatrix_ColumnIncrease.height);
        setcolor(WHITE);
        line(buttonSecondMatrix_ColumnIncrease.pozX + buttonSecondMatrix_ColumnIncrease.width / 4, buttonSecondMatrix_ColumnIncrease.pozY + 10, buttonSecondMatrix_ColumnIncrease.pozX + buttonSecondMatrix_ColumnIncrease.width - 10, buttonSecondMatrix_ColumnIncrease.pozY + buttonSecondMatrix_ColumnIncrease.height / 2);
        line(buttonSecondMatrix_ColumnIncrease.pozX + buttonSecondMatrix_ColumnIncrease.width / 4, buttonSecondMatrix_ColumnIncrease.pozY + buttonSecondMatrix_ColumnIncrease.height - 10, buttonSecondMatrix_ColumnIncrease.pozX + buttonSecondMatrix_ColumnIncrease.width - 10, buttonSecondMatrix_ColumnIncrease.pozY + buttonSecondMatrix_ColumnIncrease.height / 2);

        setcolor(GREEN);
        rectangle(buttonSecondMatrix_ColumnDowncrease.pozX, buttonSecondMatrix_ColumnDowncrease.pozY, buttonSecondMatrix_ColumnDowncrease.pozX + buttonSecondMatrix_ColumnDowncrease.width, buttonSecondMatrix_ColumnDowncrease.pozY + buttonSecondMatrix_ColumnDowncrease.height);
        setcolor(WHITE);
        line(buttonSecondMatrix_ColumnDowncrease.pozX + buttonSecondMatrix_ColumnDowncrease.width - 10, buttonSecondMatrix_ColumnDowncrease.pozY + 10, buttonSecondMatrix_ColumnDowncrease.pozX + 10, buttonSecondMatrix_ColumnDowncrease.pozY + buttonSecondMatrix_ColumnDowncrease.height / 2);
        line(buttonSecondMatrix_ColumnDowncrease.pozX + buttonSecondMatrix_ColumnDowncrease.width - 10, buttonSecondMatrix_ColumnDowncrease.pozY + buttonSecondMatrix_ColumnDowncrease.height - 10, buttonSecondMatrix_ColumnDowncrease.pozX + 10, buttonSecondMatrix_ColumnDowncrease.pozY + buttonSecondMatrix_ColumnDowncrease.height / 2);

        char cop[2];

        itoa(secondMatrix.width, cop, 10);
        settextstyle(9, 0, 5);
        outtextxy(buttonSecondMatrix_ColumnDowncrease.pozX + buttonSecondMatrix_ColumnDowncrease.width + 23, buttonSecondMatrix_ColumnDowncrease.pozY, cop);
    }
}
void DrawResultMatrix()
{
    setfillstyle(SOLID_FILL, settings.backgroundColor);
    bar(890, 20, 1265, 205);

    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            strcpy(resultMatrix.element[i][j]->value, "");
            setcolor(LIGHTGRAY);
            rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);
        }
    }
}

/*
    Fuctille executate cand mouseul se afla deasupra unui buton
*/
void OverButtonLevel1(int pozX, int pozY, Button *button)
{

    if(pozX >= button->pozX and pozX <= button->pozX + button->width and pozY >= button->pozY and pozY <= button->pozY + button->height)
    {

        if(!button->mouseOver)
        {

            for(int i = 15; i >= 0; i -= 3)
            {

                setcolor(GREEN);
                rectangle(button->pozX - i, button->pozY - i, button->pozX + button->width + i, button->pozY + button->height + i);

                delay(20);

                setcolor(settings.backgroundColor);
                rectangle(button->pozX - i, button->pozY - i, button->pozX + button->width + i, button->pozY + button->height + i);
            }

            setcolor(GREEN);
            rectangle(button->pozX, button->pozY, button->pozX + button->width, button->pozY + button->height);
            setcolor(LIGHTGRAY);
            outtextxy(button->text.pozX, button->text.pozY, button->text.buttonText);

            button->mouseOver = true;
        }

    }
    else
    {

        if(button->mouseOver)
        {

            setcolor(WHITE);
            rectangle(button->pozX, button->pozY, button->pozX + button->width, button->pozY + button->height);
            outtextxy(button->text.pozX, button->text.pozY, button->text.buttonText);

            button->mouseOver = false;
        }
    }
}
void OverButtonLevel2(int pozX, int pozY, Button *button)
{

    if(pozX >= button->pozX and pozX <= button->pozX + button->width and pozY >= button->pozY and pozY <= button->pozY + button->height)
    {

        if(!button->mouseOver)
        {

            setcolor(settings.backgroundColor);
            line(button->pozX, button->pozY + button->height, button->pozX + button->width, button->pozY + button->height);
            outtextxy(button->text.pozX, button->text.pozY, button->text.buttonText);

            setcolor(BROWN);
            line(button->pozX, button->pozY + button->height, button->pozX + button->width, button->pozY + button->height);
            outtextxy(button->text.pozX, button->text.pozY, button->text.buttonText);

            button->mouseOver = true;
        }

    }
    else
    {

        if(button->mouseOver)
        {

            setcolor(WHITE);
            line(button->pozX, button->pozY + button->height, button->pozX + button->width, button->pozY + button->height);
            outtextxy(button->text.pozX, button->text.pozY, button->text.buttonText);

            button->mouseOver = false;
        }
    }
}
void OverButtonMatrix(int pozX, int pozY)
{

    settextstyle(9, 0, 5);

    OverButtonLevel1(pozX, pozY, &buttonMatrix);
}
void OverButtonVector(int pozX, int pozY)
{

    settextstyle(9, 0, 5);

    OverButtonLevel1(pozX, pozY, &buttonVector);
}
void OverButtonSettings(int pozX, int pozY)
{
    settextstyle(9, 0, 4);

    OverButtonLevel1(pozX, pozY, &buttonSettings);
}
void OverButtonLoadData(int pozX, int pozY)
{
    settextstyle(9, 0, 4);

    OverButtonLevel1(pozX, pozY, &buttonLoadData);
}
void OverButtonBack(int pozX, int pozY)
{

    settextstyle(9, 0, 4);

    OverButtonLevel1(pozX, pozY, &buttonBack);
}
void OverButtonsMatrix(int pozX, int pozY)
{
    settextstyle(9, 0, 4);

    OverButtonLevel2(pozX, pozY, &buttonSumMatrix);

    OverButtonLevel2(pozX, pozY, &buttonDecreaseMatrix);

    OverButtonLevel2(pozX, pozY, &buttonProductMatrix);

    OverButtonLevel2(pozX, pozY, &buttonDivisionMatrix);

    OverButtonLevel2(pozX, pozY, &buttonTransposeMatrix);

    OverButtonLevel2(pozX, pozY, &buttonInverseMatrix);

    OverButtonLevel2(pozX, pozY, &buttonDetMatrix);

    OverButtonLevel2(pozX, pozY, &buttonPowMatrix);
}
void OverButtonsVector(int pozX, int pozY)
{
    settextstyle(9, 0, 4);

    OverButtonLevel2(pozX, pozY, &buttonSumVect);

    OverButtonLevel2(pozX, pozY, &buttonProductVect);

    OverButtonLevel2(pozX, pozY, &buttonSortVect);

    OverButtonLevel2(pozX, pozY, &buttonShiftVect);

    OverButtonLevel2(pozX, pozY, &buttonProductScalarVect);

    OverButtonLevel1(pozX, pozY, &buttonNextElementVect);

    OverButtonLevel1(pozX, pozY, &buttonPreviewElementVect);

    OverButtonLevel1(pozX, pozY, &buttonDeleteElementVect);
}
void OverButtonsSettings(int pozX, int pozY)
{
    settextstyle(9, 0, 4);

    OverButtonLevel2(pozX, pozY, &buttonSetBackgroundColor);
}
void OverButtonQuit(int pozX, int pozY)
{
    settextstyle(9, 0, 4);

    OverButtonLevel1(pozX, pozY, &buttonQuit);
}

/*
    Fuctille executate la apasarea unui botton din menium Principal
*/
void PressButtonVector(int pozX, int pozY)
{

    if(pozX >= buttonVector.pozX and pozX <= buttonVector.pozX + buttonVector.width and pozY >= buttonVector.pozY and pozY <= buttonVector.pozY + buttonVector.height)
    {
        buttonVector.show = false;
        buttonMatrix.show = false;
        buttonSettings.show = false;

        showButtonsHome = false;
        showButtonsMatrix = false;
        showButtonsVector = true;
        showButtonsSettings = false;

        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        InitializationVectorHomeScreen();
    }
}
void PressButtonMatrix(int pozX, int pozY)
{

    if(pozX >= buttonMatrix.pozX and pozX <= buttonMatrix.pozX + buttonMatrix.width and pozY >= buttonMatrix.pozY and pozY <= buttonMatrix.pozY + buttonMatrix.height)
    {

        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        buttonVector.show = false;
        buttonMatrix.show = false;
        buttonSettings.show = false;

        showButtonsHome = false;
        showButtonsMatrix = true;
        showButtonsVector = false;
        showButtonsSettings = false;

        cleardevice();

        InitializationMatrixHomeScreen();
    }
}
void PressButtonSettings(int pozX, int pozY)
{
    if(pozX >= buttonSettings.pozX and pozX <= buttonSettings.pozX + buttonSettings.width and pozY >= buttonSettings.pozY and pozY <= buttonSettings.pozY + buttonSettings.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        cleardevice();

        showButtonsMatrix = false;
        showButtonsVector = false;
        showButtonsHome = false;
        showButtonsSettings = true;

        InitializationSettingsHomeScreen();
    }
}
void PressButtonLoadData(int pozX, int pozY)
{
    if(pozX >= buttonLoadData.pozX and pozX <= buttonLoadData.pozX + buttonLoadData.width and pozY >= buttonLoadData.pozY and pozY <= buttonLoadData.pozY + buttonLoadData.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        LoadData();
    }
}
void PressButtonQuit(int pozX, int pozY, bool &ok)
{
    if(pozX >= buttonQuit.pozX and pozX <= buttonQuit.pozX + buttonQuit.width and pozY >= buttonQuit.pozY and pozY <= buttonQuit.pozY + buttonQuit.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        SaveFile_Vector();

        SaveFile_Matrix();

        SaveFile_Settings();

        ok = false;
    }
}
void PressButtonBack(int pozX, int pozY)
{

    if(pozX >= buttonBack.pozX and pozX <= buttonBack.pozX + buttonBack.width and pozY >= buttonBack.pozY and pozY <= buttonBack.pozY + buttonBack.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        /*if(showButtonsVector)
            SaveFile_Vector();

        if(showButtonsMatrix)
            SaveFile_Matrix();

        if(showButtonsSettings)
            SaveFile_Settings();*/

        showButtonsMatrix = false;
        showButtonsVector = false;
        showButtonsHome = true;
        showButtonsSettings = false;

        secondMatrix.show = false;

        InitializationMatrixButtonsPress(NULL);

        cleardevice();
        DrawHomeScreen();
    }
}

/*
    Fuctille executate la apasarea unui botton din menium Vector
*/
void PressButtonAdd(int pozX, int pozY)
{
    if(pozX >= buttonAddVector.pozX and pozX <= buttonAddVector.pozX + buttonAddVector.width and pozY >= buttonAddVector.pozY and pozY <= buttonAddVector.pozY + buttonAddVector.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        Nod *p = new Nod;
        strcpy(p->value, "_");
        p->nextElement = NULL;

        if(vect->totalItems == 0)
        {
            p->PreviewElement = NULL;
            vect->FirstElement = p;
            vect->LastElement = p;
        }
        else
        {
            p->PreviewElement = vect->LastElement;
            vect->LastElement->nextElement = p;
            vect->LastElement = p;
        }

        vect->totalItems++;

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
        DrawVector();

        char sir[26];
        strcpy(sir, "_");
        int tasta, poz = 0;

        do
        {
            tasta = getch();

            if(tasta == 8 and poz > 0)
            {
                sir[poz] = '\0';
                poz--;
                sir[poz] = '_';
                strcpy(vect->LastElement->value, sir);
            }

            if(((tasta >= 48 and tasta <= 57) or (poz == 0 and tasta == 45)) and poz < 18)
            {
                sir[poz] = tasta;
                sir[poz + 1] = '_';
                poz++;
                sir[poz + 1] = '\0';
                strcpy(vect->LastElement->value, sir);
            }

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
            DrawVector();
        }
        while(tasta != 13);

        vect->LastElement->value[poz] = '\0';

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
        DrawVector();

        if(strlen(vect->LastElement->value) == 0)
        {
            if(vect->totalItems == 1)
            {
                vect->LastElement = NULL;
                vect->FirstElement = NULL;
                vect->totalItems = 0;
            }
            else
            {
                vect->LastElement = vect->LastElement->PreviewElement;
                vect->LastElement->nextElement = NULL;
                vect->totalItems--;
            }

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
            DrawVector();
        }
        else
        {
            settextstyle(9, 0, 6);
            outtextxy(buttonSumVect.pozX + buttonSumVect.width + 30, buttonSumVect.pozY + 10, "                             ");
            outtextxy(buttonProductVect.pozX + buttonProductVect.width + 30, buttonProductVect.pozY + 10, "                             ");
        }
    }
}
void PressButtonSumVect(int pozX, int pozY)
{

    if(pozX >= buttonSumVect.pozX and pozX <= buttonSumVect.pozX + buttonSumVect.width and pozY >= buttonSumVect.pozY and pozY <= buttonSumVect.pozY + buttonSumVect.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        if(vect->totalItems > 0)
        {
            setcolor(settings.backgroundColor);
            settextstyle(9, 0, 6);
            outtextxy(buttonSumVect.pozX + buttonSumVect.width + 30, buttonSumVect.pozY, "                      ");

            long long sum = 0;
            char cop[100];

            Nod *p = vect->FirstElement;

            while(p != NULL)
            {
                if(settings.playFXSounds) PlaySound(TEXT("crossing.wav"), NULL, SND_FILENAME|SND_ASYNC);

                setcolor(RED);
                settextstyle(9, 0, 4);
                rectangle(p->pozX, p->pozY, p->pozX + p->width, p->pozY + p->height);
                outtextxy(p->text.pozX, p->text.pozY, p->value);

                for(int i = 0; i <= 20; i++)
                    cop[i] = '\0';

                strcpy(cop, p->value);
                sum += atoi(cop);
                itoa(sum, cop, 10);

                settextstyle(9, 0, 6);
                outtextxy(buttonSumVect.pozX + buttonSumVect.width + 30, buttonSumVect.pozY + 10, cop);

                delay(settings.animationSpeed);

                setcolor(LIGHTBLUE);
                rectangle(p->pozX, p->pozY, p->pozX + p->width, p->pozY + p->height);
                settextstyle(9, 0, 4);
                setcolor(WHITE);
                outtextxy(p->text.pozX, p->text.pozY, p->value);

                p = p->nextElement;
            }
            setcolor(CYAN);
            settextstyle(9, 0, 6);
            outtextxy(buttonSumVect.pozX + buttonSumVect.width + 30, buttonSumVect.pozY + 10, "          ");
            outtextxy(buttonSumVect.pozX + buttonSumVect.width + 30, buttonSumVect.pozY + 10, cop);
            strcpy(vect->sumElements, cop);
        }
        else
        {
            setcolor(CYAN);
            settextstyle(9, 0, 6);
            outtextxy(buttonSumVect.pozX + buttonSumVect.width + 30, buttonSumVect.pozY + 10, "0");
            strcpy(vect->sumElements, "0");
        }
    }
}
void PressButtomProductVect(int pozX, int pozY)
{

    if(pozX >= buttonProductVect.pozX and pozX <= buttonProductVect.pozX + buttonProductVect.width and pozY >= buttonProductVect.pozY and pozY <= buttonProductVect.pozY + buttonProductVect.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        if(vect->totalItems > 0)
        {
            setcolor(settings.backgroundColor);
            settextstyle(9, 0, 6);
            outtextxy(buttonProductVect.pozX + buttonProductVect.width + 30, buttonProductVect.pozY, "                              ");

            long long prod = 1;
            char cop[100], produs[100];

            Nod *p = new Nod;
            p = vect->FirstElement;

            while(p != NULL)
            {
                if(settings.playFXSounds) PlaySound(TEXT("crossing.wav"), NULL, SND_FILENAME|SND_ASYNC);

                setcolor(RED);
                settextstyle(9, 0, 4);
                rectangle(p->pozX, p->pozY, p->pozX + p->width, p->pozY + p->height);
                outtextxy(p->text.pozX, p->text.pozY, p->value);

                for(int i = 0; i <= 20; i++) cop[i] = '\0';

                strcpy(cop, p->value);
                prod *= atoi(cop);
                itoa(prod, cop, 10);

                settextstyle(9, 0, 6);
                outtextxy(buttonProductVect.pozX + buttonProductVect.width + 30, buttonProductVect.pozY + 10, "                                  ");
                outtextxy(buttonProductVect.pozX + buttonProductVect.width + 30, buttonProductVect.pozY + 10, cop);

                delay(settings.animationSpeed);

                setcolor(LIGHTBLUE);
                rectangle(p->pozX, p->pozY, p->pozX + p->width, p->pozY + p->height);
                settextstyle(9, 0, 4);
                setcolor(WHITE);
                outtextxy(p->text.pozX, p->text.pozY, p->value);

                p = p->nextElement;
            }

            itoa(prod, cop, 10);

            setcolor(CYAN);
            settextstyle(9, 0, 6);
            outtextxy(buttonProductVect.pozX + buttonProductVect.width + 30, buttonProductVect.pozY + 10, cop);
            strcpy(vect->producElements, cop);
        }
        else
        {
            setcolor(CYAN);
            settextstyle(9, 0, 6);
            outtextxy(buttonProductVect.pozX + buttonProductVect.width + 30, buttonProductVect.pozY + 10, "                                  ");
            outtextxy(buttonProductVect.pozX + buttonProductVect.width + 30, buttonProductVect.pozY + 10, "0");
            strcpy(vect->producElements, "0");
        }
    }
}
void PressButtonSortVect(int pozX, int pozY)
{

    if(pozX >= buttonSortVect.pozX and pozX <= buttonSortVect.pozX + buttonSortVect.width and pozY >= buttonSortVect.pozY and pozY <= buttonSortVect.pozY + buttonSortVect.height)
    {

        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setcolor(LIGHTCYAN);
        line(buttonSelectionSortVect.pozX, buttonSelectionSortVect.pozY + buttonSelectionSortVect.height, buttonSelectionSortVect.pozX + buttonSelectionSortVect.width, buttonSelectionSortVect.pozY + buttonSelectionSortVect.height);
        outtextxy(buttonSelectionSortVect.text.pozX, buttonSelectionSortVect.text.pozY, buttonSelectionSortVect.text.buttonText);

        setcolor(LIGHTGREEN);
        line(buttonQuicksortVect.pozX, buttonQuicksortVect.pozY + buttonQuicksortVect.height, buttonQuicksortVect.pozX + buttonQuicksortVect.width, buttonQuicksortVect.pozY + buttonQuicksortVect.height);
        outtextxy(buttonQuicksortVect.text.pozX, buttonQuicksortVect.text.pozY, buttonQuicksortVect.text.buttonText);

        buttonSelectionSortVect.show = true;
        buttonQuicksortVect.show = true;
    }

}
void PressButtonSelectionSort(int pozX, int pozY)
{
    if(pozX >= buttonSelectionSortVect.pozX and pozX <= buttonSelectionSortVect.pozX + buttonSelectionSortVect.width and pozY >= buttonSelectionSortVect.pozY and pozY <= buttonSelectionSortVect.pozY + buttonSelectionSortVect.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        Nod *i_Nod = vect->FirstElement;
        Nod *j_Nod = new Nod;

        while(i_Nod->nextElement != NULL)
        {
            setcolor(YELLOW);
            rectangle(i_Nod->pozX - 5, i_Nod->pozY - 5, i_Nod->pozX + i_Nod->width + 5, i_Nod->pozY + i_Nod->height +5 );

            j_Nod = i_Nod->nextElement;

            delay(settings.animationSpeed);
            while(j_Nod != NULL)
            {
                if(settings.playFXSounds) PlaySound(TEXT("crossing.wav"), NULL, SND_FILENAME|SND_ASYNC);

                setcolor(LIGHTGREEN);
                rectangle(j_Nod->pozX - 5, j_Nod->pozY - 5, j_Nod->pozX + j_Nod->width + 5, j_Nod->pozY + j_Nod->height + 5);

                delay(settings.animationSpeed);
                if(atoi(j_Nod->value) < atoi(i_Nod->value))
                {
                    setcolor(LIGHTRED);
                    rectangle(i_Nod->pozX - 5, i_Nod->pozY - 5, i_Nod->pozX + i_Nod->width + 5, i_Nod->pozY + i_Nod->height +5 );
                    rectangle(j_Nod->pozX - 5, j_Nod->pozY - 5, j_Nod->pozX + j_Nod->width + 5, j_Nod->pozY + j_Nod->height + 5);

                    if(settings.playFXSounds) PlaySound(TEXT("swap.wav"), NULL, SND_FILENAME|SND_ASYNC);

                    delay(settings.animationSpeed);
                    swap(i_Nod->value, j_Nod->value);
                    swap(i_Nod->indice, j_Nod->indice);

                    setfillstyle(SOLID_FILL, settings.backgroundColor);
                    bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
                    DrawVector();

                    setcolor(YELLOW);
                    rectangle(i_Nod->pozX - 5, i_Nod->pozY - 5, i_Nod->pozX + i_Nod->width + 5, i_Nod->pozY + i_Nod->height +5 );
                    setcolor(LIGHTGREEN);
                    rectangle(j_Nod->pozX - 5, j_Nod->pozY - 5, j_Nod->pozX + j_Nod->width + 5, j_Nod->pozY + j_Nod->height + 5);

                    delay(settings.animationSpeed);
                }
                setcolor(settings.backgroundColor);
                rectangle(j_Nod->pozX - 5, j_Nod->pozY - 5, j_Nod->pozX + j_Nod->width + 5, j_Nod->pozY + j_Nod->height + 5);

                j_Nod = j_Nod->nextElement;
            }

            setcolor(settings.backgroundColor);
            rectangle(i_Nod->pozX - 5, i_Nod->pozY - 5, i_Nod->pozX + i_Nod->width + 5, i_Nod->pozY + i_Nod->height +5 );

            i_Nod = i_Nod->nextElement;
        }
        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(355, 425, screenWidth, 485);
        buttonSelectionSortVect.show = false;
        buttonQuicksortVect.show = false;
    }
}
void PressButtonQuickSort(int pozX, int pozY)
{
    if(pozX >= buttonQuicksortVect.pozX and pozX <= buttonQuicksortVect.pozX + buttonQuicksortVect.width and pozY >= buttonQuicksortVect.pozY and pozY <= buttonQuicksortVect.pozY + buttonQuicksortVect.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        int indice = 1;
        Nod *p = vect->FirstElement;

        while(p != NULL)
        {
            p->indice = indice++;
            p = p->nextElement;
        }

        QuickSort(vect->FirstElement, vect->LastElement);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
        DrawVector();
    }
}
void QuickSort(Nod *inf, Nod *sup)
{
    Nod *left = inf;
    Nod *right = sup;

    Nod *mid = left;
    while (mid->indice != ((left->indice + right->indice) / 2) and mid != NULL)
        mid = mid->nextElement;

    setfillstyle(SOLID_FILL, settings.backgroundColor);
    bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
    DrawVector();

    setcolor(YELLOW);
    rectangle(mid->pozX - 5, mid->pozY - 5, mid->pozX + mid->width + 5, mid->pozY + mid->height + 5);

    do
    {
        while (left->indice < sup->indice and atoi(left->value) < atoi(mid->value))
        {
            if(settings.playFXSounds) PlaySound(TEXT("crossing.wav"), NULL, SND_FILENAME|SND_ASYNC);
            setcolor(LIGHTGREEN);
            rectangle(left->pozX - 5, left->pozY - 5, left->pozX + left->width + 5, left->pozY + left->height + 5);

            left = left->nextElement;

            delay(settings.animationSpeed);
        }
        while (right->indice > inf->indice and atoi(right->value) > atoi(mid->value))
        {
            if(settings.playFXSounds) PlaySound(TEXT("crossing.wav"), NULL, SND_FILENAME|SND_ASYNC);
            setcolor(LIGHTGREEN);
            rectangle(right->pozX - 5, right->pozY - 5, right->pozX + right->width + 5, right->pozY + right->height + 5);

            right = right->PreviewElement;

            delay(settings.animationSpeed);
        }

        if (left->indice <= right->indice)
        {
            delay((settings.animationSpeed * 2) - (settings.animationSpeed / 2));

            setcolor(LIGHTRED);
            rectangle(left->pozX - 5, left->pozY - 5, left->pozX + left->width + 5, left->pozY + left->height + 5);
            rectangle(right->pozX - 5, right->pozY - 5, right->pozX + right->width + 5, right->pozY + right->height + 5);

            if(settings.playFXSounds) PlaySound(TEXT("swap.wav"), NULL, SND_FILENAME|SND_ASYNC);

            delay((settings.animationSpeed * 2) - (settings.animationSpeed / 2));

            swap(left->value, right->value);

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
            DrawVector();

            setcolor(YELLOW);
            rectangle(mid->pozX - 5, mid->pozY - 5, mid->pozX + mid->width + 5, mid->pozY + mid->height + 5);

            setcolor(settings.backgroundColor);
            rectangle(left->pozX - 5, left->pozY - 5, left->pozX + left->width + 5, left->pozY + left->height + 5);
            rectangle(right->pozX - 5, right->pozY - 5, right->pozX + right->width + 5, right->pozY + right->height + 5);

            if(left->nextElement != NULL) left = left->nextElement;
            if(right->PreviewElement != NULL) right = right->PreviewElement;

            setcolor(LIGHTGREEN);
            rectangle(left->pozX - 5, left->pozY - 5, left->pozX + left->width + 5, left->pozY + left->height + 5);
            rectangle(right->pozX - 5, right->pozY - 5, right->pozX + right->width + 5, right->pozY + right->height + 5);
        }
    }
    while (left->indice < right->indice);

    if (right->indice > inf->indice) QuickSort(inf, right);
    if (left->indice < sup->indice) QuickSort(left, sup);
}

void PressButtonShiftVect(int pozX, int pozY)
{

    if(pozX >= buttonShiftVect.pozX and pozX <= buttonShiftVect.pozX + buttonShiftVect.width and pozY >= buttonShiftVect.pozY and pozY <= buttonShiftVect.pozY + buttonShiftVect.height)
    {

        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        settextstyle(9, 0, 4);

        setcolor(LIGHTMAGENTA);

        line(buttonShiftLeftVect.pozX, buttonShiftLeftVect.pozY + buttonShiftLeftVect.height, buttonShiftLeftVect.pozX + buttonShiftLeftVect.width, buttonShiftLeftVect.pozY + buttonShiftLeftVect.height);
        outtextxy(buttonShiftLeftVect.text.pozX, buttonShiftLeftVect.text.pozY, buttonShiftLeftVect.text.buttonText);

        setcolor(LIGHTRED);

        line(buttonShiftRightVect.pozX, buttonShiftRightVect.pozY + buttonShiftRightVect.height, buttonShiftRightVect.pozX + buttonShiftRightVect.width, buttonShiftRightVect.pozY + buttonShiftRightVect.height);
        outtextxy(buttonShiftRightVect.text.pozX, buttonShiftRightVect.text.pozY, buttonShiftRightVect.text.buttonText);

        buttonShiftLeftVect.show = true;
        buttonShiftRightVect.show = true;
    }
}
void PressButtonShiftLeftVect(int pozX, int pozY)
{

    if(pozX >= buttonShiftLeftVect.pozX and pozX <= buttonShiftLeftVect.pozX + buttonShiftLeftVect.width and pozY >= buttonShiftLeftVect.pozY and pozY <= buttonShiftLeftVect.pozY + buttonShiftLeftVect.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("swap.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setcolor(RED);
        rectangle(vect->FirstElement->pozX, vect->FirstElement->pozY, vect->FirstElement->pozX + vect->FirstElement->width, vect->FirstElement->pozY + vect->FirstElement->height);
        outtextxy(vect->FirstElement->text.pozX, vect->FirstElement->text.pozY, vect->FirstElement->value);

        delay(settings.animationSpeed);

        Nod *p = new Nod;
        p = vect->FirstElement;

        cleardevice();

        DrawVectorButtons();

        if(vect->FirstElement == vect->LastElement)
        {
            vect->FirstElement = NULL;
            vect->LastElement = NULL;
            vect->totalItems = 0;
        }
        else
        {
            p->nextElement->PreviewElement = NULL;
            vect->FirstElement = p->nextElement;

            delete p;

            vect->totalItems--;
        }

        DrawVector();
    }
}
void PressButtonShiftRightVect(int pozX, int pozY)
{

    if(pozX >= buttonShiftRightVect.pozX and pozX <= buttonShiftRightVect.pozX + buttonShiftRightVect.width and pozY >= buttonShiftRightVect.pozY and pozY <= buttonShiftLeftVect.pozY + buttonShiftLeftVect.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("swap.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setcolor(RED);
        rectangle(vect->LastElement->pozX, vect->LastElement->pozY, vect->LastElement->pozX + vect->LastElement->width, vect->LastElement->pozY + vect->LastElement->height);
        outtextxy(vect->LastElement->text.pozX, vect->LastElement->text.pozY, vect->LastElement->value);

        delay(settings.animationSpeed);

        cleardevice();

        DrawVectorButtons();

        if(vect->FirstElement == vect->LastElement)
        {
            vect->FirstElement = NULL;
            vect->LastElement = NULL;
            vect->totalItems = 0;
        }
        else
        {
            Nod *p = vect->LastElement;

            vect->LastElement = p->PreviewElement;
            vect->LastElement->nextElement = NULL;

            vect->totalItems--;

            delete p;
        }
        DrawVector();
    }
}
void PressButtonProductScalarVect(int pozX, int pozY)
{

    if(pozX >= buttonProductScalarVect.pozX and pozX <= buttonProductScalarVect.pozX + buttonProductScalarVect.width and pozY >= buttonProductScalarVect.pozY and pozY <= buttonProductScalarVect.pozY + buttonProductScalarVect.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        settextstyle(9, 0, 6);
        setcolor(settings.backgroundColor);
        outtextxy(buttonProductScalarVect.pozX + buttonProductScalarVect.width + 30, buttonProductScalarVect.pozY + 10, "        ");

        char scalarChar[26];
        int tasta, scalar, poz = 0;

        do
        {
            tasta = getch();

            if(tasta == 8 and poz > 0)
            {
                poz--;
                scalarChar[poz] = '\0';

                setcolor(settings.backgroundColor);
                outtextxy(buttonProductScalarVect.pozX + buttonProductScalarVect.width + 30, buttonProductScalarVect.pozY + 10, "                         ");
                setcolor(CYAN);
                outtextxy(buttonProductScalarVect.pozX + buttonProductScalarVect.width + 30, buttonProductScalarVect.pozY + 10, scalarChar);
            }

            if(((tasta >= 48 and tasta <= 57) or (poz == 0 and tasta == 45)) and poz < 18)
            {
                scalarChar[poz] = tasta;
                scalarChar[poz + 1] = '\0';
                poz++;

                setcolor(CYAN);
                outtextxy(buttonProductScalarVect.pozX + buttonProductScalarVect.width + 30, buttonProductScalarVect.pozY + 10, scalarChar);
            }

        }
        while(tasta != 13);

        setcolor(settings.backgroundColor);
        settextstyle(9, 0, 6);
        outtextxy(buttonSumVect.pozX + buttonSumVect.width + 30, buttonSumVect.pozY + 10, "                             ");
        outtextxy(buttonProductVect.pozX + buttonProductVect.width + 30, buttonProductVect.pozY + 10, "                             ");

        scalar = atoi(scalarChar);
        Nod *p = vect->FirstElement;

        char cop[20];
        int numar, cont;

        while(p != NULL)
        {
            if(settings.playFXSounds) PlaySound(TEXT("crossing.wav"), NULL, SND_FILENAME|SND_ASYNC);

            strcpy(cop, p->value);
            numar = atoi(cop);

            itoa(scalar * numar, p->value, 10);

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
            DrawVector();

            setcolor(RED);
            settextstyle(9, 0, 4);
            rectangle(p->pozX, p->pozY, p->pozX + p->width, p->pozY + p->height);
            outtextxy(p->text.pozX, p->text.pozY, p->value);

            delay(settings.animationSpeed);

            setcolor(LIGHTBLUE);
            rectangle(p->pozX, p->pozY, p->pozX + p->width, p->pozY + p->height);
            settextstyle(9, 0, 4);
            setcolor(WHITE);
            outtextxy(p->text.pozX, p->text.pozY, p->value);

            p = p->nextElement;
        }

        settextstyle(9, 0, 6);
        setcolor(CYAN);
        outtextxy(buttonProductScalarVect.pozX + buttonProductScalarVect.width + 30, buttonProductScalarVect.pozY + 10, "                              ");
    }
}
void PressButtonNextElementVect(int pozX, int pozY)
{
    if(pozX >= buttonNextElementVect.pozX and pozX <= buttonNextElementVect.pozX + buttonNextElementVect.width and pozY >= buttonNextElementVect.pozY and pozY <= buttonNextElementVect.pozY + buttonNextElementVect.height)
    {
        if(vect->selectedElement != NULL and vect->selectedElement != vect->LastElement)
        {
            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

            Nod *element = vect->selectedElement;
            Nod *next = vect->selectedElement->nextElement;

            if(element->PreviewElement != NULL)
                element->PreviewElement->nextElement = next;
            next->PreviewElement = element->PreviewElement;

            element->nextElement = next->nextElement;
            if(next->nextElement != NULL)
                next->nextElement->PreviewElement = element;

            next->nextElement = element;
            element->PreviewElement = next;

            if(next == vect->LastElement)
                vect->LastElement = element;

            if(element == vect->FirstElement)
                vect->FirstElement = next;

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
            DrawVector();
        }
    }
}
void PressButtonPreviewElementVect(int pozX, int pozY)
{
    if(pozX >= buttonPreviewElementVect.pozX and pozX <= buttonPreviewElementVect.pozX + buttonPreviewElementVect.width and pozY >= buttonPreviewElementVect.pozY and pozY <= buttonPreviewElementVect.pozY + buttonPreviewElementVect.height)
    {
        if(vect->selectedElement != NULL and vect->selectedElement != vect->FirstElement)
        {

            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

            Nod *element = vect->selectedElement;
            Nod *preview = vect->selectedElement->PreviewElement;

            if(preview->PreviewElement != NULL)
                preview->PreviewElement->nextElement = element;
            element->PreviewElement = preview->PreviewElement;

            preview->nextElement = element->nextElement;
            if(element->nextElement != NULL)
                element->nextElement->PreviewElement = preview;

            element->nextElement = preview;
            preview->PreviewElement = element;

            if(element == vect->LastElement)
                vect->LastElement = preview;

            if(preview == vect->FirstElement)
                vect->FirstElement = element;

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
            DrawVector();
        }
    }
}
void PressButtonDeleteElementVect(int pozX, int pozY)
{
    if(pozX >= buttonDeleteElementVect.pozX and pozX <= buttonDeleteElementVect.pozX + buttonDeleteElementVect.width and pozY >= buttonDeleteElementVect.pozY and pozY <= buttonDeleteElementVect.pozY + buttonDeleteElementVect.height)
    {
        if(vect->selectedElement != NULL)
        {
            if(settings.playFXSounds) PlaySound(TEXT("swap.wav"), NULL, SND_FILENAME|SND_ASYNC);

            Nod *element = vect->selectedElement;

            setcolor(WHITE);
            settextstyle(9, 0, 6);
            outtextxy(buttonSumVect.pozX + buttonSumVect.width + 30, buttonSumVect.pozY + 10, "                             ");
            outtextxy(buttonProductVect.pozX + buttonProductVect.width + 30, buttonProductVect.pozY + 10, "                             ");

            if(element->nextElement != NULL)
                element->nextElement->PreviewElement = element->PreviewElement;

            if(element->PreviewElement != NULL)
                element->PreviewElement->nextElement = element->nextElement;

            if(element == vect->FirstElement)
                vect->FirstElement = element->nextElement;
            if(element == vect->LastElement)
                vect->LastElement = element->PreviewElement;

            vect->totalItems--;
            vect->selectedElement = NULL;

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
            DrawVector();
        }
    }
}
void SelectElementVector(int pozX, int pozY)
{
    if(pozY <= 210)
    {
        Nod *p = vect->FirstElement;
        bool ok = false;

        while(p != NULL and !ok)
        {
            if(pozX >= p->pozX and pozX <= p->pozX + p->width and pozY >= p->pozY and pozY <= p->pozY + p->height)
            {
                if(vect->selectedElement == p)
                {
                    vect->selectedElement = NULL;

                    if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);
                }
                else
                {
                    vect->selectedElement = p;

                    if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);
                }
                ok = true;

                setfillstyle(SOLID_FILL, settings.backgroundColor);
                bar(0, 0, screenWidth, buttonPreviewElementVect.pozY - 10);
                DrawVector();
            }
            p = p->nextElement;
        }
    }
}

/*
    Fuctille executate la apasarea unui botton din menium Matrix
*/
void PressButtonResizeMatrix(int pozX, int pozY)
{
    bool resizeMainMatrix = false;
    bool resizeSecondMatrix = false;

    if(pozX >= buttonMainMatrix_LineIncrease.pozX and pozX <= buttonMainMatrix_LineIncrease.pozX + buttonMainMatrix_LineIncrease.width and pozY >= buttonMainMatrix_LineIncrease.pozY and pozY <= buttonMainMatrix_LineIncrease.pozY + buttonMainMatrix_LineIncrease.height)
    {
        if(mainMatrix.height < 4)
        {
            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

            mainMatrix.height++;

            if(buttonSumMatrix.press or buttonDecreaseMatrix.press or buttonDivisionMatrix.press)
            {
                secondMatrix.height = mainMatrix.height;
                resizeSecondMatrix = true;
            }

            if(buttonDetMatrix.press or buttonPowMatrix.press) mainMatrix.width++;

            resizeMainMatrix = true;
        }
    }
    if(pozX >= buttonMainMatrix_LineDowncrease.pozX and pozX <= buttonMainMatrix_LineDowncrease.pozX + buttonMainMatrix_LineDowncrease.width and pozY >= buttonMainMatrix_LineDowncrease.pozY and pozY <= buttonMainMatrix_LineDowncrease.pozY + buttonMainMatrix_LineDowncrease.height)
    {
        if(mainMatrix.height > 1)
        {
            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

            mainMatrix.height--;

            if(buttonSumMatrix.press or buttonDecreaseMatrix.press or buttonDivisionMatrix.press)
            {
                secondMatrix.height = mainMatrix.height;
                resizeSecondMatrix = true;
            }

            if(buttonDetMatrix.press) mainMatrix.width--;

            resizeMainMatrix = true;
        }
    }
    if(pozX >= buttonMainMatrix_ColumnIncrease.pozX and pozX <= buttonMainMatrix_ColumnIncrease.pozX + buttonMainMatrix_ColumnIncrease.width and pozY >= buttonMainMatrix_ColumnIncrease.pozY and pozY <= buttonMainMatrix_ColumnIncrease.pozY + buttonMainMatrix_ColumnIncrease.height)
    {
        if(mainMatrix.width < 4)
        {
            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

            mainMatrix.width++;

            if(secondMatrix.show)
            {
                if(buttonProductMatrix.press) secondMatrix.height = mainMatrix.width;
                else secondMatrix.width = mainMatrix.width;

                resizeSecondMatrix = true;
            }

            if(buttonDetMatrix.press) mainMatrix.height++;

            resizeMainMatrix = true;
        }
    }
    if(pozX >= buttonMainMatrix_ColumnDowncrease.pozX and pozX <= buttonMainMatrix_ColumnDowncrease.pozX + buttonMainMatrix_ColumnDowncrease.width and pozY >= buttonMainMatrix_ColumnDowncrease.pozY and pozY <= buttonMainMatrix_ColumnDowncrease.pozY + buttonMainMatrix_ColumnDowncrease.height)
    {
        if(mainMatrix.width > 1)
        {
            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

            mainMatrix.width--;

            if(secondMatrix.show)
            {

                if(buttonProductMatrix.press) secondMatrix.height = mainMatrix.width;
                else secondMatrix.width = mainMatrix.width;

                resizeSecondMatrix = true;
            }

            if(buttonDetMatrix.press) mainMatrix.height--;

            resizeMainMatrix = true;
        }
    }

    if(buttonProductMatrix.press)
    {
        if(pozX >= buttonSecondMatrix_ColumnIncrease.pozX and pozX <= buttonSecondMatrix_ColumnIncrease.pozX + buttonSecondMatrix_ColumnIncrease.width and pozY >= buttonSecondMatrix_ColumnIncrease.pozY and pozY <= buttonSecondMatrix_ColumnIncrease.pozY + buttonSecondMatrix_ColumnIncrease.height)
        {
            if(secondMatrix.width < 4)
            {
                if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);
                secondMatrix.width++;
                resizeSecondMatrix = true;
            }
        }
        if(pozX >= buttonSecondMatrix_ColumnDowncrease.pozX and pozX <= buttonSecondMatrix_ColumnDowncrease.pozX + buttonSecondMatrix_ColumnDowncrease.width and pozY >= buttonSecondMatrix_ColumnDowncrease.pozY and pozY <= buttonSecondMatrix_ColumnDowncrease.pozY + buttonSecondMatrix_ColumnDowncrease.height)
        {
            if(secondMatrix.width > 1)
            {
                secondMatrix.width--;
                if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);
                resizeSecondMatrix = true;
            }
        }
    }

    if(resizeMainMatrix)
    {
        DrawMainMatrix();

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(890, 20, 1265, 205);
    }

    if(resizeSecondMatrix)
    {
        DrawSecondMatrix();

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(890, 20, 1265, 205);
    }
}
void SelectElementMatrix(int pozX, int pozY)
{
    if(pozY <= mainMatrix.element[4][4]->pozY + mainMatrix.element[4][4]->height)
    {
        bool ok = false;
        if(pozX < secondMatrix.element[1][1]->pozX)
        {
            for(int i = 1; i <= mainMatrix.height and !ok; i++)
            {
                for(int j = 1; j <= mainMatrix.width and !ok; j++)
                {
                    if(mainMatrix.element[i][j]->on)
                    {
                        if(pozX >= mainMatrix.element[i][j]->pozX and pozX <= mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width and pozY >= mainMatrix.element[i][j]->pozY and pozY <= mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height)
                        {
                            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

                            setcolor(LIGHTGREEN);
                            rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);

                            int tasta, poz = 0;
                            char sir[5];

                            do
                            {
                                tasta = getch();

                                if(tasta == 8 and poz > 0)
                                {
                                    poz--;
                                    sir[poz] = '\0';
                                    strcpy(mainMatrix.element[i][j]->value, sir);
                                }

                                if(((48 <= tasta and tasta <= 57) or (tasta == 45 and poz == 0)) and poz < 4)
                                {
                                    sir[poz] = tasta;
                                    sir[poz + 1] = '\0';
                                    poz++;
                                    strcpy(mainMatrix.element[i][j]->value, sir);
                                }

                                setcolor(settings.backgroundColor);
                                rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                settextstyle(9, 0, 3);
                                outtextxy(mainMatrix.element[i][j]->pozX + 10, mainMatrix.element[i][j]->pozY + 5, "0000");

                                setcolor(LIGHTGREEN);
                                rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                settextstyle(9, 0, 3);
                                setcolor(WHITE);
                                outtextxy(mainMatrix.element[i][j]->pozX + 10, mainMatrix.element[i][j]->pozY + 5, mainMatrix.element[i][j]->value);

                            }
                            while(tasta != 13);

                            mainMatrix.element[i][j]->valueInt = atoi(mainMatrix.element[i][j]->value);

                            setcolor(settings.backgroundColor);
                            rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                            settextstyle(9, 0, 3);
                            outtextxy(mainMatrix.element[i][j]->pozX + 10, mainMatrix.element[i][j]->pozY + 5, "0000");

                            setcolor(LIGHTBLUE);
                            rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                            settextstyle(9, 0, 3);
                            setcolor(WHITE);
                            outtextxy(mainMatrix.element[i][j]->pozX + 10, mainMatrix.element[i][j]->pozY + 5, mainMatrix.element[i][j]->value);

                            ok = true;
                        }
                    }
                }
            }

            DrawMainMatrix();
        }
        else if(pozX >= secondMatrix.element[1][1]->pozX and pozX <= resultMatrix.element[1][1]->pozX and secondMatrix.show)
        {
            for(int i = 1; i <= secondMatrix.height and !ok; i++)
            {
                for(int j = 1; j <= secondMatrix.width and !ok; j++)
                {
                    if(secondMatrix.element[i][j]->on)
                    {
                        if(pozX >= secondMatrix.element[i][j]->pozX and pozX <= secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width and pozY >= secondMatrix.element[i][j]->pozY and pozY <= secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height)
                        {
                            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

                            setcolor(LIGHTGREEN);
                            rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);

                            int tasta, poz = 0;
                            char sir[5];

                            do
                            {
                                tasta = getch();

                                if(tasta == 8 and poz > 0)
                                {
                                    poz--;
                                    sir[poz] = '\0';
                                    strcpy(secondMatrix.element[i][j]->value, sir);
                                    secondMatrix.element[i][j]->valueInt = atoi(sir);
                                }

                                if(((48 <= tasta and tasta <= 57) or (tasta == 45 and poz == 0)) and poz < 4)
                                {

                                    sir[poz] = tasta;
                                    sir[poz + 1] = '\0';
                                    poz++;
                                    strcpy(secondMatrix.element[i][j]->value, sir);
                                    secondMatrix.element[i][j]->valueInt = atoi(sir);
                                }

                                setcolor(settings.backgroundColor);
                                rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);
                                settextstyle(9, 0, 3);
                                outtextxy(secondMatrix.element[i][j]->pozX + 10, secondMatrix.element[i][j]->pozY + 5, "0000");

                                setcolor(LIGHTGREEN);
                                rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);
                                settextstyle(9, 0, 3);
                                setcolor(WHITE);
                                outtextxy(secondMatrix.element[i][j]->pozX + 10, secondMatrix.element[i][j]->pozY + 5, secondMatrix.element[i][j]->value);

                            }
                            while(tasta != 13);

                            setcolor(settings.backgroundColor);
                            rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);
                            settextstyle(9, 0, 3);
                            outtextxy(secondMatrix.element[i][j]->pozX + 10, secondMatrix.element[i][j]->pozY + 5, "0000");

                            setcolor(LIGHTBLUE);
                            rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);
                            settextstyle(9, 0, 3);
                            setcolor(WHITE);
                            outtextxy(secondMatrix.element[i][j]->pozX + 10, secondMatrix.element[i][j]->pozY + 5, secondMatrix.element[i][j]->value);

                            ok = true;
                        }
                    }
                }
            }

            DrawSecondMatrix();
        }
    }
}
void PressButtonSumMatrix(int pozX, int pozY)
{
    if(pozX >= buttonSumMatrix.pozX and pozX <= buttonSumMatrix.pozX + buttonSumMatrix.width and pozY >= buttonSumMatrix.pozY and pozY <= buttonSumMatrix.pozY + buttonSumMatrix.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 20, 1265, 260);
        bar(430, 20, 1265, 620);

        secondMatrix.width = mainMatrix.width;
        secondMatrix.height = mainMatrix.height;

        resultMatrix.width = mainMatrix.width;
        resultMatrix.height = mainMatrix.height;

        secondMatrix.show = true;
        resultMatrix.show = true;

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 85, 450, 145);

        setcolor(WHITE);
        line(395, 117, 445, 117); // +
        line(420, 92, 420, 142);

        line(832, 107, 882, 107); //=
        line(832, 127, 882, 127);

        InitializationMatrixButtonsPress(&buttonSumMatrix);

        DrawSecondMatrix();

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(890, 20, 1265, 205);
    }
}
void ButtonEqual_Sum(int pozX, int pozY)
{
    if(resultMatrix.show)
    {
        bool ok = true;

        if(pozX >= 832 and pozX <= 882 and pozY >= 107 and pozY <= 127)
        {
            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

            for(int i = 1; i <= mainMatrix.height and ok; i++)
            {
                for(int j = 1; j <= mainMatrix.width and ok; j++)
                {
                    if(mainMatrix.element[i][j]->value[0] == '\0' or secondMatrix.element[i][j]->value[0] == '\0')
                    {
                        MessageBox(0, "Matricile au elemente necompletate!", "Atentie!", MB_OK);
                        ok = false;
                    }
                }
            }

            if(ok)
            {
                DrawResultMatrix();

                for(int i = 1; i <= mainMatrix.height; i++)
                {
                    for(int j = 1; j <= mainMatrix.width; j++)
                    {
                        setcolor(RED);
                        rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                        rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);
                        rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);

                        char suma[20];
                        itoa(atoi(mainMatrix.element[i][j]->value) + atoi(secondMatrix.element[i][j]->value), suma, 10);

                        strcpy(resultMatrix.element[i][j]->value, suma);

                        setcolor(WHITE);
                        settextstyle(9, 0, 3);
                        outtextxy(resultMatrix.element[i][j]->pozX + 10, resultMatrix.element[i][j]->pozY + 5, resultMatrix.element[i][j]->value);

                        delay(settings.animationSpeed);

                        setcolor(LIGHTBLUE);
                        rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                        rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);
                        rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);
                    }
                }
            }
        }
    }
}
void PressButtonProductMatrix(int pozX, int pozY)
{
    if(pozX >= buttonProductMatrix.pozX and pozX <= buttonProductMatrix.pozX + buttonProductMatrix.width and pozY >= buttonProductMatrix.pozY and pozY <= buttonProductMatrix.pozY + buttonProductMatrix.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 20, 1265, 260);
        bar(430, 20, 1265, 620);

        secondMatrix.width = mainMatrix.width;
        secondMatrix.height = mainMatrix.height;

        resultMatrix.width = mainMatrix.width;
        resultMatrix.height = mainMatrix.height;

        secondMatrix.show = true;
        resultMatrix.show = true;

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 85, 450, 145);

        setcolor(WHITE);
        line(405, 102, 435, 132); // *
        line(405, 132, 435, 102);

        line(832, 107, 882, 107); //=
        line(832, 127, 882, 127);

        InitializationMatrixButtonsPress(&buttonProductMatrix);

        DrawSecondMatrix();

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(890, 20, 1265, 205);
    }
}
void ButtonEqual_Product(int pozX, int pozY)
{
    if(resultMatrix.show)
    {
        bool ok = true;

        if(pozX >= 832 and pozX <= 882 and pozY >= 107 and pozY <= 127)
        {
            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

            if(mainMatrix.width != secondMatrix.height)
            {
                MessageBox(0, "Matricile nu pot fi inmultite!", "Atentie!", MB_OK);
                ok = false;
            }

            for(int i = 1; i <= mainMatrix.height and ok; i++)
            {
                for(int j = 1; j <= mainMatrix.width and ok; j++)
                {
                    if(mainMatrix.element[i][j]->value[0] == '\0')
                    {
                        MessageBox(0, "Matricile au elemente necompletate!", "Atentie!", MB_OK);
                        ok = false;
                    }
                }
            }

            for(int i = 1; i <= secondMatrix.height and ok; i++)
            {
                for(int j = 1; j <= secondMatrix.width and ok; j++)
                {
                    if(secondMatrix.element[i][j]->value[0] == '\0')
                    {
                        MessageBox(0, "Matricile au elemente necompletate!", "Atentie!", MB_OK);
                        ok = false;
                    }
                }
            }

            if(ok)
            {
                DrawResultMatrix();

                for(int i = 1; i <= mainMatrix.height; i++)
                {
                    for(int k = 1; k <= secondMatrix.width; k++)
                    {
                        for(int j = 1; j <= mainMatrix.width; j++)
                        {
                            setcolor(RED);
                            rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                            rectangle(secondMatrix.element[j][k]->pozX, secondMatrix.element[j][k]->pozY, secondMatrix.element[j][k]->pozX + secondMatrix.element[j][k]->width, secondMatrix.element[j][k]->pozY + secondMatrix.element[j][k]->height);
                            rectangle(resultMatrix.element[i][k]->pozX, resultMatrix.element[i][k]->pozY, resultMatrix.element[i][k]->pozX + resultMatrix.element[i][k]->width, resultMatrix.element[i][k]->pozY + resultMatrix.element[i][k]->height);

                            char produc[20];
                            itoa(atoi(mainMatrix.element[i][j]->value) * atoi(secondMatrix.element[j][k]->value) + atoi(resultMatrix.element[i][k]->value), produc, 10);

                            strcpy(resultMatrix.element[i][k]->value, produc);

                            setcolor(WHITE);
                            settextstyle(9, 0, 3);

                            outtextxy(resultMatrix.element[i][k]->pozX + 10, resultMatrix.element[i][k]->pozY + 5, resultMatrix.element[i][k]->value);

                            delay((settings.animationSpeed * 2) - (settings.animationSpeed / 2));

                            setcolor(LIGHTBLUE);
                            rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                            rectangle(secondMatrix.element[j][k]->pozX, secondMatrix.element[j][k]->pozY, secondMatrix.element[j][k]->pozX + secondMatrix.element[j][k]->width, secondMatrix.element[j][k]->pozY + secondMatrix.element[j][k]->height);
                            rectangle(resultMatrix.element[i][k]->pozX, resultMatrix.element[i][k]->pozY, resultMatrix.element[i][k]->pozX + resultMatrix.element[i][k]->width, resultMatrix.element[i][k]->pozY + resultMatrix.element[i][k]->height);

                        }
                    }
                }
            }
        }
    }
}
void PressButtonDecreaseMatrix(int pozX, int pozY)
{
    if(pozX >= buttonDecreaseMatrix.pozX and pozX <= buttonDecreaseMatrix.pozX + buttonDecreaseMatrix.width and pozY >= buttonDecreaseMatrix.pozY and pozY <= buttonDecreaseMatrix.pozY + buttonDecreaseMatrix.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 20, 1265, 260);
        bar(430, 20, 1265, 620);

        secondMatrix.width = mainMatrix.width;
        secondMatrix.height = mainMatrix.height;

        resultMatrix.width = mainMatrix.width;
        resultMatrix.height = mainMatrix.height;

        secondMatrix.show = true;
        resultMatrix.show = true;

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 85, 450, 145);

        setcolor(WHITE);
        line(405, 117, 435, 117); // -

        line(832, 107, 882, 107); //=
        line(832, 127, 882, 127);

        InitializationMatrixButtonsPress(&buttonDecreaseMatrix);
        DrawSecondMatrix();

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(890, 20, 1265, 205);
    }
}
void ButtonEqual_Decrease(int pozX, int pozY)
{
    if(resultMatrix.show)
    {
        bool ok = true;

        if(pozX >= 832 and pozX <= 882 and pozY >= 107 and pozY <= 127)
        {
            if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

            for(int i = 1; i <= mainMatrix.height and ok; i++)
            {
                for(int j = 1; j <= mainMatrix.width and ok; j++)
                {
                    if(mainMatrix.element[i][j]->value[0] == '\0' or secondMatrix.element[i][j]->value[0] == '\0')
                    {
                        MessageBox(0, "Matricile au elemente necompletate!", "Atentie!", MB_OK);
                        ok = false;
                    }
                }
            }

            if(ok)
            {
                DrawResultMatrix();

                for(int i = 1; i <= mainMatrix.height; i++)
                {
                    for(int j = 1; j <= mainMatrix.width; j++)
                    {
                        setcolor(RED);
                        rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                        rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);
                        rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);

                        char suma[20];
                        itoa(atoi(mainMatrix.element[i][j]->value) - atoi(secondMatrix.element[i][j]->value), suma, 10);

                        strcpy(resultMatrix.element[i][j]->value, suma);

                        setcolor(WHITE);
                        settextstyle(9, 0, 3);
                        outtextxy(resultMatrix.element[i][j]->pozX + 10, resultMatrix.element[i][j]->pozY + 5, resultMatrix.element[i][j]->value);

                        delay(settings.animationSpeed);

                        setcolor(LIGHTBLUE);
                        rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                        rectangle(secondMatrix.element[i][j]->pozX, secondMatrix.element[i][j]->pozY, secondMatrix.element[i][j]->pozX + secondMatrix.element[i][j]->width, secondMatrix.element[i][j]->pozY + secondMatrix.element[i][j]->height);
                        rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);
                    }
                }
            }
        }
    }
}
void PressButtonTransposeMatrix(int pozX, int pozY)
{
    if(pozX >= buttonTransposeMatrix.pozX and pozX <= buttonTransposeMatrix.pozX + buttonTransposeMatrix.width and pozY >= buttonTransposeMatrix.pozY and pozY <= buttonTransposeMatrix.pozY + buttonTransposeMatrix.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 20, 1265, 260);
        bar(430, 20, 1265, 620);

        InitializationMatrixButtonsPress(&buttonTransposeMatrix);
        secondMatrix.show = false;

        bool ok = true;
        for(int i = 1; i <= mainMatrix.height and ok; i++)
        {
            for(int j = 1; j <= mainMatrix.width and ok; j++)
            {
                if(mainMatrix.element[i][j]->value[0] == '\0')
                {
                    MessageBox(0, "Matricea au elemente necompletate!", "Atentie!", MB_OK);
                    ok = false;
                }
            }
        }

        if(ok)
        {
            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(390, 20, 1265, 205);
            DrawResultMatrix();

            for(int i = 1; i <= mainMatrix.height; i++)
            {
                for(int j = 1; j <= mainMatrix.width; j++)
                {

                    strcpy(resultMatrix.element[j][i]->value, mainMatrix.element[i][j]->value);

                    setcolor(RED);
                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                    rectangle(resultMatrix.element[j][i]->pozX, resultMatrix.element[j][i]->pozY, resultMatrix.element[j][i]->pozX + resultMatrix.element[j][i]->width, resultMatrix.element[j][i]->pozY + resultMatrix.element[j][i]->height);

                    setcolor(WHITE);
                    settextstyle(9, 0, 3);
                    outtextxy(resultMatrix.element[j][i]->pozX + 10, resultMatrix.element[j][i]->pozY + 5, resultMatrix.element[j][i]->value);

                    delay(settings.animationSpeed);

                    setcolor(LIGHTBLUE);
                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                    rectangle(resultMatrix.element[j][i]->pozX, resultMatrix.element[j][i]->pozY, resultMatrix.element[j][i]->pozX + resultMatrix.element[j][i]->width, resultMatrix.element[j][i]->pozY + resultMatrix.element[j][i]->height);

                }
            }
        }
    }
}
void PressButtonDetMatrix(int pozX, int pozY)
{
    if(pozX >= buttonDetMatrix.pozX and pozX <= buttonDetMatrix.pozX + buttonDetMatrix.width and pozY >= buttonDetMatrix.pozY and pozY <= buttonDetMatrix.pozY + buttonDetMatrix.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 20, 1265, 260);
        bar(430, 20, 1265, 620);

        InitializationMatrixButtonsPress(&buttonDetMatrix);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(455, 20, screenWidth, screenHeight - 150);

        setcolor(WHITE);
        line(395, 107, 445, 107); //=
        line(395, 127, 445, 127);
    }
}
void ButtonEqual_Det(int pozX, int pozY)
{
    if(buttonDetMatrix.press)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        if(pozX >= 395 and pozX <= 445 and pozY >= 107 and pozY <= 127)
        {
            bool ok = true;

            for(int i = 1; i <= mainMatrix.height and ok; i++)
            {
                for(int j = 1; j <= mainMatrix.width and ok; j++)
                {
                    if(mainMatrix.element[i][j]->value[0] == '\0')
                    {
                        MessageBox(0, "Determinantul este incomplet!", "Atentie!", MB_OK);
                        ok = false;
                    }
                }
            }

            if(ok)
            {
                setfillstyle(SOLID_FILL, settings.backgroundColor);
                bar(455, 20, screenWidth, screenHeight - 150);

                for(int i = 1; i <= 5; i++)
                {
                    mainMatrix.det.frec_BK[i] = 0;
                    mainMatrix.det.vect_BK[i] = 0;
                }

                mainMatrix.det.cont = 1;
                mainMatrix.det.pozX = 460;
                mainMatrix.det.pozY = 100;

                mainMatrix.det.determinant = 0;
                mainMatrix.det.cont = 1;

                DeterminantMatrix_Backtracking(1, &mainMatrix);

                char sir[100], c[100];
                itoa(mainMatrix.det.determinant, c, 10);
                strcpy(sir, "= ");
                strcat(sir, c);

                if(mainMatrix.det.pozX + strlen(sir) * 22 >= screenWidth)
                {
                    mainMatrix.det.pozX = 460;
                    mainMatrix.det.pozY += 50;
                }

                setcolor(LIGHTRED);
                settextstyle(9, 0, 4);
                outtextxy(mainMatrix.det.pozX, mainMatrix.det.pozY, sir);

                delay(settings.animationSpeed);

                setcolor(LIGHTBLUE);
                outtextxy(mainMatrix.det.pozX, mainMatrix.det.pozY, sir);
            }
        }
    }

}
void PressButtonDivisionMatrix(int pozX, int pozY)
{
    if(pozX >= buttonDivisionMatrix.pozX and pozX <= buttonDivisionMatrix.pozX + buttonDivisionMatrix.width and pozY >= buttonDivisionMatrix.pozY and pozY <= buttonDivisionMatrix.pozY + buttonDivisionMatrix.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 20, 1265, 260);
        bar(430, 20, 1265, 620);

        secondMatrix.width = mainMatrix.width;
        secondMatrix.height = mainMatrix.height;

        secondMatrix.show = true;
        resultMatrix.show = true;

        setcolor(WHITE);
        line(415, 82, 425, 127); // /

        line(832, 107, 882, 107); //=
        line(832, 127, 882, 127);

        InitializationMatrixButtonsPress(&buttonDivisionMatrix);

        DrawSecondMatrix();
    }
}
void ButtonEqual_Division(int pozX, int pozY)
{
    if(pozX >= 832 and pozX <= 882 and pozY >= 107 and pozY <= 127)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        bool ok = true;

        for(int i = 1; i <= mainMatrix.height and ok; i++)
        {
            for(int j = 1; j <= mainMatrix.width and ok; j++)
            {
                if(mainMatrix.element[i][j]->value[0] == '\0' or secondMatrix.element[i][j]->value[0] == '\0')
                {
                    MessageBox(0, "Matricile au elemente necompletate!", "Atentie!", MB_OK);
                    ok = false;
                }
            }
        }

        if(ok)
        {
            int mat[5][5];

            for(int i = 1; i <= secondMatrix.height; i++)
            {
                for(int j = 1; j <= secondMatrix.width; j++)
                {
                    mat[i][j] = atoi(secondMatrix.element[i][j]->value);
                }
            }

            InverseMatrix(&secondMatrix);

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(890, 20, 1265, 205);

            setcolor(WHITE);
            line(405, 102, 435, 132); // *
            line(405, 132, 435, 102);

            line(832, 107, 882, 107); //=
            line(832, 127, 882, 127);

            DrawResultMatrix();

            for(int i = 1; i <= mainMatrix.height; i++)
            {
                for(int k = 1; k <= secondMatrix.width; k++)
                {
                    for(int j = 1; j <= mainMatrix.width; j++)
                    {
                        setcolor(RED);
                        settextstyle(9, 0, 4);
                        outtextxy(500, 300, "Calculam Produsul celor 2 matrici");
                        settextstyle(9, 0, 3);

                        setcolor(RED);
                        rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                        rectangle(secondMatrix.element[j][k]->pozX, secondMatrix.element[j][k]->pozY, secondMatrix.element[j][k]->pozX + secondMatrix.element[j][k]->width, secondMatrix.element[j][k]->pozY + secondMatrix.element[j][k]->height);
                        rectangle(resultMatrix.element[i][k]->pozX, resultMatrix.element[i][k]->pozY, resultMatrix.element[i][k]->pozX + resultMatrix.element[i][k]->width, resultMatrix.element[i][k]->pozY + resultMatrix.element[i][k]->height);

                        char produc[20];
                        itoa(atoi(mainMatrix.element[i][j]->value) * atoi(secondMatrix.element[j][k]->value) + atoi(resultMatrix.element[i][k]->value), produc, 10);

                        strcpy(resultMatrix.element[i][k]->value, produc);


                        settextstyle(9, 0, 3);
                        setcolor(settings.backgroundColor);
                        outtextxy(resultMatrix.element[i][k]->pozX + 10, resultMatrix.element[i][k]->pozY + 5, "0000");
                        setcolor(WHITE);
                        outtextxy(resultMatrix.element[i][k]->pozX + 10, resultMatrix.element[i][k]->pozY + 5, resultMatrix.element[i][k]->value);

                        delay((settings.animationSpeed * 2) - (settings.animationSpeed / 2));

                        setcolor(LIGHTBLUE);
                        rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                        rectangle(secondMatrix.element[j][k]->pozX, secondMatrix.element[j][k]->pozY, secondMatrix.element[j][k]->pozX + secondMatrix.element[j][k]->width, secondMatrix.element[j][k]->pozY + secondMatrix.element[j][k]->height);
                        rectangle(resultMatrix.element[i][k]->pozX, resultMatrix.element[i][k]->pozY, resultMatrix.element[i][k]->pozX + resultMatrix.element[i][k]->width, resultMatrix.element[i][k]->pozY + resultMatrix.element[i][k]->height);

                    }
                }
            }

            setcolor(RED);
            settextstyle(9, 0, 4);
            outtextxy(500, 300, "                                                                              ");
            settextstyle(9, 0, 3);

            char cop[20];
            for(int i = 1; i <= secondMatrix.height; i++)
            {
                for(int j = 1; j <= secondMatrix.width; j++)
                {
                    itoa(mat[i][j], cop, 10);
                    strcpy(secondMatrix.element[i][j]->value, cop);
                }
            }

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(455, 20, 825, 205);

            DrawSecondMatrix();

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(395, 20, 450, 205);

            setcolor(WHITE);
            line(415, 82, 425, 127); // /

            setcolor(WHITE);
            line(1007, 270, 1147, 270); // 1 / n

            settextstyle(9, 0, 6);
            outtextxy(1053, 215, "1");

            char sir[20];
            itoa(secondMatrix.det.determinant, sir, 10);

            outtextxy(1012, 275, sir);

            setcolor(RED);
            settextstyle(9, 0, 5);
            outtextxy(500, 300, "Afisam inversa");
            delay(3 * settings.animationSpeed);
            outtextxy(500, 300, "                                 ");
            settextstyle(9, 0, 3);
        }
    }
}
void PressButtonInverseMatrix(int pozX, int pozY)
{
    if(buttonInverseMatrix.pozX <= pozX and pozX <= buttonInverseMatrix.pozX +  buttonInverseMatrix.width and buttonInverseMatrix.pozY <= pozY and pozY <= buttonInverseMatrix.pozY+buttonInverseMatrix.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 20, 1265, 260);
        bar(430, 20, 1265, 620);

        InitializationMatrixButtonsPress(&buttonInverseMatrix);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(455, 20, screenWidth, screenHeight - 150);

        setcolor(WHITE);
        line(395, 107, 445, 107); //=
        line(395, 127, 445, 127);

        line(445, 97, 475, 117);
        line(445, 137, 475, 117);
    }

}
void ButtonEqual_Inverse(int pozX, int pozY)
{
    if(395 <= pozX and pozX <= 475 and 107 <= pozY and pozY <= 127)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(890, 210, 1265, 400);

        bool ok = true;

        for(int i = 1; i <= mainMatrix.height and ok; i++)
        {
            for(int j = 1; j <= mainMatrix.width and ok; j++)
            {
                if(mainMatrix.element[i][j]->value[0] == '\0')
                {
                    MessageBox(0, "Matricea au elemente necompletate!", "Atentie!", MB_OK);
                    ok = false;
                }
            }
        }

        if(ok) InverseMatrix(&mainMatrix);
    }
}
void PressButtonPow(int pozX, int pozY)
{
    if(buttonPowMatrix.pozX <= pozX and pozX <= buttonPowMatrix.pozX +  buttonPowMatrix.width and buttonPowMatrix.pozY <= pozY and pozY <= buttonPowMatrix.pozY+buttonPowMatrix.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(390, 20, 1265, 260);
        bar(430, 20, 1265, 620);

        bool ok = true;

        if(mainMatrix.width != mainMatrix.height)
            ok = false;

        for(int i = 1; i <= mainMatrix.height; i++)
        {
            for(int j = 1; j <= mainMatrix.width; j++)
            {
                if(mainMatrix.element[i][j]->value[0] == '\0')
                {
                    MessageBox(0, "Matricea are elemente necompletate!", "Atentie!", MB_OK);
                    ok = false;
                }
            }
        }

        if(ok)
        {

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(390, 20, 1265, 205);

            InitializationMatrixButtonsPress(&buttonPowMatrix);

            int putere, tasta, poz = 0;
            char sir[20];

            do
            {
                tasta = getch();

                if(tasta == 8 and poz > 0)
                {
                    poz--;
                    sir[poz] = '\0';
                    settextstyle(9, 0, 5);
                    setcolor(CYAN);
                    outtextxy(buttonPowMatrix.pozX + buttonPowMatrix.width + 20, buttonPowMatrix.pozY, "                         ");
                    outtextxy(buttonPowMatrix.pozX + buttonPowMatrix.width + 20, buttonPowMatrix.pozY, sir);
                }

                if(((tasta >= 48 and tasta <= 57) or (poz == 0 and tasta == 45)) and poz < 18)
                {
                    sir[poz] = tasta;
                    sir[poz + 1] = '\0';
                    poz++;
                    setcolor(CYAN);
                    settextstyle(9, 0, 5);
                    outtextxy(buttonPowMatrix.pozX + buttonPowMatrix.width + 20, buttonPowMatrix.pozY, sir);
                }
            }

            while(tasta != 13);

            if(sir[0] != '\0')
            {
                putere = atoi(sir);

                if(putere > 1)
                {
                    setfillstyle(SOLID_FILL, settings.backgroundColor);
                    bar(390, 20, 1265, 205);

                    setcolor(WHITE);
                    line(405, 102, 435, 132); // *
                    line(405, 132, 435, 102);

                    line(832, 107, 882, 107); //=
                    line(832, 127, 882, 127);

                    secondMatrix.width = mainMatrix.width;
                    secondMatrix.height = mainMatrix.height;

                    for(int i = 1; i <= mainMatrix.width; i++)
                    {
                        for(int j = 1; j <= mainMatrix.height; j++)
                        {
                            strcpy(secondMatrix.element[i][j]->value, mainMatrix.element[i][j]->value);
                        }
                    }

                    while(putere > 1)
                    {
                        DrawSecondMatrix();
                        DrawResultMatrix();

                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int k = 1; k <= secondMatrix.width; k++)
                            {
                                for(int j = 1; j <= mainMatrix.width; j++)
                                {
                                    setcolor(RED);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                    rectangle(secondMatrix.element[j][k]->pozX, secondMatrix.element[j][k]->pozY, secondMatrix.element[j][k]->pozX + secondMatrix.element[j][k]->width, secondMatrix.element[j][k]->pozY + secondMatrix.element[j][k]->height);
                                    rectangle(resultMatrix.element[i][k]->pozX, resultMatrix.element[i][k]->pozY, resultMatrix.element[i][k]->pozX + resultMatrix.element[i][k]->width, resultMatrix.element[i][k]->pozY + resultMatrix.element[i][k]->height);

                                    char produc[20];
                                    itoa(atoi(mainMatrix.element[i][j]->value) * atoi(secondMatrix.element[j][k]->value) + atoi(resultMatrix.element[i][k]->value), produc, 10);

                                    strcpy(resultMatrix.element[i][k]->value, produc);

                                    setcolor(WHITE);
                                    settextstyle(9, 0, 3);

                                    outtextxy(resultMatrix.element[i][k]->pozX + 10, resultMatrix.element[i][k]->pozY + 5, resultMatrix.element[i][k]->value);

                                    delay((settings.animationSpeed * 2) - (settings.animationSpeed / 2));

                                    setcolor(LIGHTBLUE);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                    rectangle(secondMatrix.element[j][k]->pozX, secondMatrix.element[j][k]->pozY, secondMatrix.element[j][k]->pozX + secondMatrix.element[j][k]->width, secondMatrix.element[j][k]->pozY + secondMatrix.element[j][k]->height);
                                    rectangle(resultMatrix.element[i][k]->pozX, resultMatrix.element[i][k]->pozY, resultMatrix.element[i][k]->pozX + resultMatrix.element[i][k]->width, resultMatrix.element[i][k]->pozY + resultMatrix.element[i][k]->height);

                                }
                            }
                        }

                        putere--;

                        if(putere == 1)
                        {
                            setfillstyle(SOLID_FILL, settings.backgroundColor);
                            bar(0, 0, 890, 205);
                            for(int i = 1; i <= mainMatrix.width; i++)
                            {
                                for(int j = 1; j <= mainMatrix.height; j++)
                                {
                                    strcpy(mainMatrix.element[i][j]->value, secondMatrix.element[i][j]->value);
                                }
                            }
                            DrawMainMatrix();

                            settextstyle(9, 0, 7);
                            char cop[30];
                            strcpy(cop, "^");
                            strcat(cop, sir);
                            strcat(cop, " =");
                            outtextxy(445, 87, cop);
                            settextstyle(9, 0, 5);
                            outtextxy(buttonPowMatrix.pozX + buttonPowMatrix.width + 20, buttonPowMatrix.pozY, "                         ");
                        }
                        else
                        {
                            for(int i = 1; i <= mainMatrix.width; i++)
                            {
                                for(int j = 1; j <= mainMatrix.height; j++)
                                {
                                    strcpy(mainMatrix.element[i][j]->value, resultMatrix.element[i][j]->value);
                                }
                            }
                            DrawMainMatrix();
                        }
                    }
                }
            }
        }
    }
}

void InverseMatrix(Matrix *matrix)
{
    matrix->det.determinant = 0;
    DeterminantMatrix_Backtracking_2(1, matrix, 0, 0, 1);

    int det = matrix->det.determinant;

    if(det == 0)
    {
        setcolor(RED);
        settextstyle(9, 0, 5);
        outtextxy(500, 300, "Determinantul este egal cu 0 !");
        settextstyle(9, 0, 3);
        delay(settings.animationSpeed);
        outtextxy(500, 300, "                                                               ");
    }
    else
    {
        setcolor(RED);
        settextstyle(9, 0, 5);
        outtextxy(500, 300, "Calculam transpusa");
        settextstyle(9, 0, 3);

        Transpusa(matrix);

        for(int i = 1; i <= matrix->height; i++)
        {
            for(int j = 1; j <= matrix->width; j++)
            {
                matrix->element[i][j]->valueInt = atoi(resultMatrix.element[i][j]->value);
                strcpy(matrix->element[i][j]->value, resultMatrix.element[i][j]->value);

                setcolor(WHITE);
                outtextxy(matrix->element[i][j]->pozX + 10, matrix->element[i][j]->pozY + 5, matrix->element[i][j]->value);

                setcolor(RED);
                rectangle(matrix->element[i][j]->pozX, matrix->element[i][j]->pozY, matrix->element[i][j]->pozX + matrix->element[i][j]->width, matrix->element[i][j]->pozY + matrix->element[i][j]->height);
                rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);

                delay(settings.animationSpeed / 2);

                setcolor(LIGHTBLUE);
                rectangle(matrix->element[i][j]->pozX, matrix->element[i][j]->pozY, matrix->element[i][j]->pozX + matrix->element[i][j]->width, matrix->element[i][j]->pozY + matrix->element[i][j]->height);
                rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);

            }
        }
        setfillstyle(SOLID_FILL, settings.backgroundColor);
        bar(455, 20, screenWidth, screenHeight - 150);

        if(matrix->tag == secondMatrix.tag)
            DrawSecondMatrix();

        DrawResultMatrix();

        setcolor(RED);
        settextstyle(9, 0, 5);
        outtextxy(500, 300, "Calculam A*");
        settextstyle(9, 0, 3);

        for(int i = 1; i <= matrix->height; i++)
        {
            for(int j = 1; j <= matrix->width; j++)
            {
                for(int i = 1; i < 5; i++)
                {
                    matrix->det.frec_BK[i] = 0;
                    matrix->det.vect_BK[i] = 0;
                }
                matrix->det.determinant = 0;
                matrix->det.cont = 1;

                DeterminantMatrix_Backtracking_2(1, matrix, i, j, 1);

                char sir[10];
                itoa(pow(-1, i + j) * matrix->det.determinant, sir, 10);

                strcpy(resultMatrix.element[i][j]->value, sir);
                resultMatrix.element[i][j]->valueInt = pow(-1, i + j) * matrix->det.determinant;

                setcolor(WHITE);
                outtextxy(resultMatrix.element[i][j]->pozX + 10, resultMatrix.element[i][j]->pozY + 5, resultMatrix.element[i][j]->value);


                for(int k = 1; k <= matrix->width; k++)
                {
                    setcolor(settings.backgroundColor);
                    rectangle(matrix->element[i][k]->pozX, matrix->element[i][k]->pozY, matrix->element[i][k]->pozX + matrix->element[i][k]->width, matrix->element[i][k]->pozY + matrix->element[i][k]->height);
                    rectangle(matrix->element[k][j]->pozX, matrix->element[k][j]->pozY, matrix->element[k][j]->pozX + matrix->element[k][j]->width, matrix->element[k][j]->pozY + matrix->element[k][j]->height);
                    setcolor(LIGHTGRAY);
                    rectangle(matrix->element[i][k]->pozX, matrix->element[i][k]->pozY, matrix->element[i][k]->pozX + matrix->element[i][k]->width, matrix->element[i][k]->pozY + matrix->element[i][k]->height);
                    rectangle(matrix->element[k][j]->pozX, matrix->element[k][j]->pozY, matrix->element[k][j]->pozX + matrix->element[k][j]->width, matrix->element[k][j]->pozY + matrix->element[k][j]->height);
                }

                setcolor(settings.backgroundColor);
                rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);
                setcolor(RED);
                rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);
                delay((settings.animationSpeed * 2) - (settings.animationSpeed / 2));

                setcolor(settings.backgroundColor);
                rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);
                setcolor(LIGHTBLUE);

                rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);
                for(int k = 1; k <= matrix->width; k++)
                {
                    setcolor(settings.backgroundColor);
                    rectangle(matrix->element[i][k]->pozX, matrix->element[i][k]->pozY, matrix->element[i][k]->pozX + matrix->element[i][k]->width, matrix->element[i][k]->pozY + matrix->element[i][k]->height);
                    rectangle(matrix->element[k][j]->pozX, matrix->element[k][j]->pozY, matrix->element[k][j]->pozX + matrix->element[k][j]->width, matrix->element[k][j]->pozY + matrix->element[k][j]->height);
                    setcolor(LIGHTBLUE);
                    rectangle(matrix->element[i][k]->pozX, matrix->element[i][k]->pozY, matrix->element[i][k]->pozX + matrix->element[i][k]->width, matrix->element[i][k]->pozY + matrix->element[i][k]->height);
                    rectangle(matrix->element[k][j]->pozX, matrix->element[k][j]->pozY, matrix->element[k][j]->pozX + matrix->element[k][j]->width, matrix->element[k][j]->pozY + matrix->element[k][j]->height);
                }
            }
        }

        //setcolor(RED);
        //delay(3 * settings.animationSpeed);
        settextstyle(9, 0, 5);
        outtextxy(500, 300, "                           ");
        settextstyle(9, 0, 3);

        if(matrix->tag == secondMatrix.tag)
        {
            for(int i = 1; i <= matrix->height; i++)
            {
                for(int j = 1; j <= matrix->width; j++)
                {
                    matrix->element[i][j]->valueInt = resultMatrix.element[i][j]->valueInt;
                    strcpy(matrix->element[i][j]->value, resultMatrix.element[i][j]->value);

                    setcolor(settings.backgroundColor);
                    outtextxy(matrix->element[i][j]->pozX + 10, matrix->element[i][j]->pozY + 5, "0000");
                    setcolor(WHITE);
                    outtextxy(matrix->element[i][j]->pozX + 10, matrix->element[i][j]->pozY + 5, matrix->element[i][j]->value);

                    setcolor(RED);
                    rectangle(matrix->element[i][j]->pozX, matrix->element[i][j]->pozY, matrix->element[i][j]->pozX + matrix->element[i][j]->width, matrix->element[i][j]->pozY + matrix->element[i][j]->height);
                    rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);

                    delay(settings.animationSpeed /2 );

                    setcolor(LIGHTBLUE);
                    rectangle(matrix->element[i][j]->pozX, matrix->element[i][j]->pozY, matrix->element[i][j]->pozX + matrix->element[i][j]->width, matrix->element[i][j]->pozY + matrix->element[i][j]->height);
                    rectangle(resultMatrix.element[i][j]->pozX, resultMatrix.element[i][j]->pozY, resultMatrix.element[i][j]->pozX + resultMatrix.element[i][j]->width, resultMatrix.element[i][j]->pozY + resultMatrix.element[i][j]->height);
                }
            }

            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(890, 20, screenWidth, screenHeight - 150);

            matrix->det.determinant = det;
        }
        else
        {
            for(int i = 1; i <= matrix->height; i++)
            {
                for(int j = 1; j < i; j++)
                {
                    swap(matrix->element[i][j]->valueInt, matrix->element[j][i]->valueInt);
                    swap(matrix->element[i][j]->value, matrix->element[j][i]->value);
                }
            }

            DrawMainMatrix();

            line(395, 107, 445, 107); //=
            line(395, 127, 445, 127);

            line(445, 97, 475, 117); // >
            line(445, 137, 475, 117);

            line(740, 117, 880, 117); // 1 / n

            settextstyle(9, 0, 6);
            outtextxy(785, 62, "1");

            char sir[20];
            itoa(det, sir, 10);

            outtextxy(745, 122, sir);

            setcolor(RED);
            settextstyle(9, 0, 5);
            outtextxy(500, 300, "Afisam inversa");
            delay(3 * settings.animationSpeed);
            outtextxy(500, 300, "                                          ");
            settextstyle(9, 0, 3);
        }
    }
}
void Transpusa(Matrix *matrix)
{
    setfillstyle(SOLID_FILL, settings.backgroundColor);
    bar(390, 20, 1265, 205);
    DrawResultMatrix();

    if(matrix->tag == secondMatrix.tag)
        DrawSecondMatrix();

    for(int i = 1; i <= matrix->height; i++)
    {
        for(int j = 1; j <= matrix->width; j++)
        {

            strcpy(resultMatrix.element[j][i]->value, matrix->element[i][j]->value);

            setcolor(RED);
            rectangle(matrix->element[i][j]->pozX, matrix->element[i][j]->pozY, matrix->element[i][j]->pozX + matrix->element[i][j]->width, matrix->element[i][j]->pozY + matrix->element[i][j]->height);
            rectangle(resultMatrix.element[j][i]->pozX, resultMatrix.element[j][i]->pozY, resultMatrix.element[j][i]->pozX + resultMatrix.element[j][i]->width, resultMatrix.element[j][i]->pozY + resultMatrix.element[j][i]->height);

            setcolor(WHITE);
            settextstyle(9, 0, 3);
            outtextxy(resultMatrix.element[j][i]->pozX + 10, resultMatrix.element[j][i]->pozY + 5, resultMatrix.element[j][i]->value);

            delay(settings.animationSpeed);

            setcolor(LIGHTBLUE);
            rectangle(matrix->element[i][j]->pozX, matrix->element[i][j]->pozY, matrix->element[i][j]->pozX + matrix->element[i][j]->width, matrix->element[i][j]->pozY + matrix->element[i][j]->height);
            rectangle(resultMatrix.element[j][i]->pozX, resultMatrix.element[j][i]->pozY, resultMatrix.element[j][i]->pozX + resultMatrix.element[j][i]->width, resultMatrix.element[j][i]->pozY + resultMatrix.element[j][i]->height);

        }
    }
}
void DeterminantMatrix_Backtracking_2(int row, Matrix *matrix, int line, int column, int cont) //Algoritmul lui Leibniz
{
    for(int i = 1; i <= matrix->width; i++)
    {
        if(row == line)
            row++;

        if(matrix->det.frec_BK[i] == 0 and i != column)
        {
            matrix->det.vect_BK[row] = i;
            matrix->det.frec_BK[i] = 1;
            if((cont == matrix->width - 1 and line != 0) or (cont == matrix->width and line == 0))
            {
                if(matrix->det.cont == -2) matrix->det.cont = 2;

                matrix->det.produs = 1;

                for(int j = 1; j <= matrix->width; j++)
                {
                    if(j != line)
                    {
                        matrix->det.produs *= matrix->element[j][matrix->det.vect_BK[j]]->valueInt;
                    }
                }
                if(matrix->det.cont > 0) matrix->det.determinant += matrix->det.produs;
                else matrix->det.determinant -= matrix->det.produs;

                matrix->det.cont--;
            }
            else
            {
                DeterminantMatrix_Backtracking_2(row + 1, matrix, line, column, cont + 1);
            }

            if(row == line)
                row--;

            matrix->det.frec_BK[i] = 0;
        }
    }
}
void DeterminantMatrix_Backtracking(int row, Matrix *matrix) //Algoritmul lui Leibniz
{
    for(int i = 1; i <= matrix->width; i++)
    {
        if(matrix->det.frec_BK[i] == 0)
        {
            matrix->det.vect_BK[row] = i;

            matrix->det.frec_BK[i] = 1;

            if(row == matrix->width)
            {
                char sir[100];

                if(matrix->det.cont == -2) matrix->det.cont = 2;

                if(matrix->det.cont > 0) strcpy(sir, "+(");
                else strcpy(sir, "-(");

                matrix->det.produs = 1;

                for(int j = 1; j <= matrix->width; j++)
                {
                    setfillstyle(SOLID_FILL, settings.backgroundColor);
                    bar(matrix->element[j][matrix->det.vect_BK[j]]->pozX - 5, matrix->element[j][matrix->det.vect_BK[j]]->pozY - 5, matrix->element[j][matrix->det.vect_BK[j]]->pozX + matrix->element[j][matrix->det.vect_BK[j]]->width + 5, matrix->element[j][matrix->det.vect_BK[j]]->pozY + matrix->element[j][matrix->det.vect_BK[j]]->height + 5);

                    setcolor(WHITE);
                    settextstyle(9, 0, 3);
                    outtextxy(matrix->element[j][matrix->det.vect_BK[j]]->pozX + 10, matrix->element[j][matrix->det.vect_BK[j]]->pozY + 5, matrix->element[j][matrix->det.vect_BK[j]]->value);

                    setlinestyle(0, 0, 3);
                    setcolor(LIGHTRED);
                    rectangle(matrix->element[j][matrix->det.vect_BK[j]]->pozX, matrix->element[j][matrix->det.vect_BK[j]]->pozY, matrix->element[j][matrix->det.vect_BK[j]]->pozX + matrix->element[j][matrix->det.vect_BK[j]]->width, matrix->element[j][matrix->det.vect_BK[j]]->pozY + matrix->element[j][matrix->det.vect_BK[j]]->height);

                    if(j != 1) strcat(sir, "*");
                    strcat(sir, matrix->element[j][matrix->det.vect_BK[j]]->value);

                    matrix->det.produs *= matrix->element[j][matrix->det.vect_BK[j]]->valueInt;

                    delay(settings.animationSpeed);
                }

                if(matrix->det.cont > 0) matrix->det.determinant += matrix->det.produs;
                else matrix->det.determinant -= matrix->det.produs;

                strcat(sir, ")");

                if(matrix->det.pozX + strlen(sir) * 22 >= screenWidth)
                {
                    matrix->det.pozX = 460;
                    matrix->det.pozY += 50;
                }

                setcolor(LIGHTRED);
                settextstyle(9, 0, 4);
                outtextxy(matrix->det.pozX, matrix->det.pozY, sir);

                delay((2 * settings.animationSpeed) + (settings.animationSpeed / 2));

                setcolor(LIGHTBLUE);
                outtextxy(matrix->det.pozX, matrix->det.pozY, sir);

                matrix->det.pozX += strlen(sir) * 22;

                for(int j = 1; j <= matrix->width; j++)
                {
                    setfillstyle(SOLID_FILL, settings.backgroundColor);
                    bar(matrix->element[j][matrix->det.vect_BK[j]]->pozX - 5, matrix->element[j][matrix->det.vect_BK[j]]->pozY - 5, matrix->element[j][matrix->det.vect_BK[j]]->pozX + matrix->element[j][matrix->det.vect_BK[j]]->width + 5, matrix->element[j][matrix->det.vect_BK[j]]->pozY + matrix->element[j][matrix->det.vect_BK[j]]->height + 5);

                    setcolor(WHITE);
                    settextstyle(9, 0, 3);
                    outtextxy(matrix->element[j][matrix->det.vect_BK[j]]->pozX + 10, matrix->element[j][matrix->det.vect_BK[j]]->pozY + 5, matrix->element[j][matrix->det.vect_BK[j]]->value);

                    setlinestyle(0, 0, 3);
                    setcolor(LIGHTBLUE);
                    rectangle(matrix->element[j][matrix->det.vect_BK[j]]->pozX, matrix->element[j][matrix->det.vect_BK[j]]->pozY, matrix->element[j][matrix->det.vect_BK[j]]->pozX + matrix->element[j][matrix->det.vect_BK[j]]->width, matrix->element[j][matrix->det.vect_BK[j]]->pozY + matrix->element[j][matrix->det.vect_BK[j]]->height);
                }
                matrix->det.cont--;
            }
            else
            {
                DeterminantMatrix_Backtracking(row + 1, matrix);
            }

            matrix->det.frec_BK[i] = 0;
        }
    }
}
void AreasSum(int pozX, int pozY)
{
    if(500 <= pozX and pozX <= 800 and 658 <= pozY and pozY <= 698)
    {
        bool ok = (mainMatrix.height == mainMatrix.width);

        for(int i = 1; i <= mainMatrix.height; i++)
            for(int j = 1; j <= mainMatrix.width; j++)
                if(mainMatrix.element[i][j]->value[0] == '\0') ok = false;

        if(ok)
        {
            setfillstyle(SOLID_FILL, settings.backgroundColor);
            bar(390, 20, 1265, 260);
            bar(430, 20, 1265, 620);

            InitializationMatrixButtonsPress(NULL);

            secondMatrix.show = false;

            int sum = 0;

            if(pozX <= 670)
            {
                if(pozX < buttonSumElem_BelowMainDiagonal.pozX + buttonSumElem_BelowMainDiagonal.width)
                {
                    if(pozY - buttonSumElem_BelowMainDiagonal.pozY >= pozX - buttonSumElem_BelowMainDiagonal.pozX)
                    {
                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if(j < i)
                                {
                                    sum += atoi(mainMatrix.element[i][j]->value);

                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTRED);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);

                                    delay(settings.animationSpeed / 2);
                                }
                            }
                        }

                        char cop[20];

                        itoa(sum, cop, 10);
                        settextstyle(9, 0, 5);
                        setcolor(LIGHTBLUE);
                        outtextxy(445, 87, "                               ");
                        outtextxy(445, 87, cop);

                        delay(settings.animationSpeed);

                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if(j < i)
                                {
                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTBLUE);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                }
                            }
                        }
                    }
                }
                else if(pozX < buttonSumElem_MainDiagonal.pozX + buttonSumElem_MainDiagonal.width)
                {
                    if(abs((pozX - buttonSumElem_MainDiagonal.pozX) - (pozY - buttonSumElem_MainDiagonal.pozY)) <= 10)
                    {
                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if(j == i)
                                {
                                    sum += atoi(mainMatrix.element[i][j]->value);

                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTRED);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);

                                    delay(settings.animationSpeed / 2);
                                }
                            }
                        }

                        char cop[20];

                        itoa(sum, cop, 10);
                        settextstyle(9, 0, 5);
                        setcolor(LIGHTBLUE);
                        outtextxy(445, 87, "                               ");
                        outtextxy(445, 87, cop);

                        delay(settings.animationSpeed);

                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if(j == i)
                                {
                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTBLUE);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                }
                            }
                        }
                    }
                }
                else if(pozX < buttonSumElem_OverMainDiagonal.pozX + buttonSumElem_OverMainDiagonal.width)
                {
                    if(pozY - buttonSumElem_OverMainDiagonal.pozY <= pozX - buttonSumElem_OverMainDiagonal.pozX)
                    {
                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if(j > i)
                                {
                                    sum += atoi(mainMatrix.element[i][j]->value);

                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTRED);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);

                                    delay(settings.animationSpeed / 2);
                                }
                            }
                        }

                        char cop[20];

                        itoa(sum, cop, 10);
                        settextstyle(9, 0, 5);
                        setcolor(LIGHTBLUE);
                        outtextxy(445, 87, "                               ");
                        outtextxy(445, 87, cop);

                        delay(settings.animationSpeed);

                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if(j > i)
                                {
                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTBLUE);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if(pozX < buttonSumElem_BelowSecondDiagonal.pozX + buttonSumElem_BelowSecondDiagonal.width)
                {
                    if((pozY - buttonSumElem_BelowSecondDiagonal.pozY + pozX - buttonSumElem_BelowSecondDiagonal.pozX) < 40)
                    {
                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if((j + i) - 1 < mainMatrix.height)
                                {
                                    sum += atoi(mainMatrix.element[i][j]->value);

                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTRED);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);

                                    delay(settings.animationSpeed / 2);
                                }
                            }
                        }

                        char cop[20];

                        itoa(sum, cop, 10);
                        settextstyle(9, 0, 5);
                        setcolor(LIGHTBLUE);
                        outtextxy(445, 87, "                               ");
                        outtextxy(445, 87, cop);

                        delay(settings.animationSpeed);

                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if((j + i) - 1 < mainMatrix.height)
                                {
                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTBLUE);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                }
                            }
                        }
                    }
                }
                else if(pozX < buttonSumElem_SecondDiagonal.pozX + buttonSumElem_SecondDiagonal.width)
                {
                    if(abs((pozX - buttonSumElem_SecondDiagonal.pozX) - (pozY - buttonSumElem_SecondDiagonal.pozY)) <= 10)
                    {
                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if((j + i) - 1 == mainMatrix.height)
                                {
                                    sum += atoi(mainMatrix.element[i][j]->value);

                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTRED);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);

                                    delay(settings.animationSpeed / 2);
                                }
                            }
                        }

                        char cop[20];

                        itoa(sum, cop, 10);
                        settextstyle(9, 0, 5);
                        setcolor(LIGHTBLUE);
                        outtextxy(445, 87, "                               ");
                        outtextxy(445, 87, cop);

                        delay(settings.animationSpeed);

                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if((j + i) - 1 == mainMatrix.height)
                                {
                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTBLUE);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                }
                            }
                        }
                    }
                }
                else if(pozX < buttonSumElem_OverSecondDiagonal.pozX + buttonSumElem_OverSecondDiagonal.width)
                {
                    if((pozY - buttonSumElem_OverSecondDiagonal.pozY + pozX - buttonSumElem_OverSecondDiagonal.pozX) > 40)
                    {
                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if((j + i) - 1 > mainMatrix.height)
                                {
                                    sum += atoi(mainMatrix.element[i][j]->value);

                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTRED);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);

                                    delay(settings.animationSpeed / 2);
                                }
                            }
                        }

                        char cop[20];

                        itoa(sum, cop, 10);
                        settextstyle(9, 0, 5);
                        setcolor(LIGHTBLUE);
                        outtextxy(445, 87, "                               ");
                        outtextxy(445, 87, cop);

                        delay(settings.animationSpeed);

                        for(int i = 1; i <= mainMatrix.height; i++)
                        {
                            for(int j = 1; j <= mainMatrix.width; j++)
                            {
                                if((j + i) - 1 > mainMatrix.height)
                                {
                                    setcolor(settings.backgroundColor);
                                    rectangle(mainMatrix.element[i][j]->pozX - 5, mainMatrix.element[i][j]->pozY - 5, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width + 5, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height + 5);

                                    setcolor(LIGHTBLUE);
                                    rectangle(mainMatrix.element[i][j]->pozX, mainMatrix.element[i][j]->pozY, mainMatrix.element[i][j]->pozX + mainMatrix.element[i][j]->width, mainMatrix.element[i][j]->pozY + mainMatrix.element[i][j]->height);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


double FromCharToDouble(char sir[30])
{
    int pozSir = 0, index;
    double power = 1, number = 0;

    while(sir[pozSir] != '.')
        pozSir++;

    for(index = pozSir - 1; index >= 0; index--)
    {
        number += power * int(sir[index] - '0');
        power *= 10;
    }
    power = 0.1;
    for(index = pozSir + 1; index < strlen(sir); index++)
    {
        number += power * int(sir[index] - '0');
        power /= 10;
    }

    return number;
}
void FromDoubleToChar(double number, char sir[])
{
    int pozPoint = 0;

    while((number) != (int)(number))
    {
        pozPoint++;
        number *= 10;
    }
    itoa(int(number), sir, 10);

    if(pozPoint > 0)
    {
        char cop[20];

        strcpy(cop, sir + (strlen(sir) - pozPoint));
        sir[(strlen(sir) - pozPoint)] = '.';
        strcpy(sir + (strlen(sir) - pozPoint) + 1, cop);
    }
}

void PressButton_Red(int pozX, int pozY)
{
    if(backgroundColor_Red.pozX <= pozX and pozX <= backgroundColor_Red.pozX + 115 and 255 <= pozY and pozY <= 275)
    {
        setcolor(RED);
        ReadColor(&backgroundColor_Red);
    }

}
void PressButton_Green(int pozX, int pozY)
{
    if(backgroundColor_Green.pozX <= pozX and pozX <= backgroundColor_Green.pozX + 115 and 255 <= pozY and pozY <= 275)
    {
        setcolor(GREEN);
        ReadColor(&backgroundColor_Green);
    }
}
void PressButton_Blue(int pozX, int pozY)
{
    if(950 <= pozX and pozX <= 1065 and 255 <= pozY and pozY <= 275)
    {
        setcolor(LIGHTBLUE);
        ReadColor(&backgroundColor_Blue);
    }
}
void PressButtonVolum(int pozX, int pozY)
{
    if(710 <= pozX and pozX <= 835 and 450 <= pozY and pozY <= 475)
    {
        PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        settings.playFXSounds = true;

        setcolor(LIGHTBLUE);
        outtextxy(710, 450, "Pornite");
        setcolor(WHITE);
        outtextxy(910, 450, "Oprite");
    }
    if(910 <= pozX and pozX <= 1020 and 450 <= pozY and pozY <= 475)
    {
        settings.playFXSounds = false;

        setcolor(WHITE);
        outtextxy(710, 450, "Pornite");
        setcolor(LIGHTBLUE);
        outtextxy(910, 450, "Oprite");
    }
}

void SelectSpeed(int pozX, int pozY)
{
    if(speed_0.pozX <= pozX and pozX <= speed_0.pozX + 20 and speed_0.pozY <= pozY and pozY <speed_0.pozY + 25)
    {

        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        settings.animationSpeed = 0;
        speed_0.press = true;
        speed_100.press = false;
        speed_600.press = false;
        speed_1000.press = false;

        settextstyle(9, 0, 4);
        outtextxy(speed_0.pozX, speed_0.pozY, "       ");
        setcolor(LIGHTBLUE);
        outtextxy(speed_0.pozX, speed_0.pozY, "0");
        setcolor(WHITE);
        outtextxy(speed_100.pozX, speed_100.pozY, "100");
        outtextxy(speed_600.pozX, speed_600.pozY, "600");
        outtextxy(speed_1000.pozX, speed_1000.pozY, "1000");
    }

    if(speed_100.pozX <= pozX and pozX <= speed_100.pozX + 60 and speed_100.pozY <= pozY and pozY <speed_100.pozY + 25)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        settings.animationSpeed = 100;
        speed_0.press = false;
        speed_100.press = true;
        speed_600.press = false;
        speed_1000.press = false;

        settextstyle(9, 0, 4);
        setcolor(LIGHTBLUE);
        outtextxy(speed_100.pozX, speed_100.pozY, "100");
        setcolor(WHITE);
        outtextxy(speed_0.pozX, speed_0.pozY, "0");
        outtextxy(speed_600.pozX, speed_600.pozY, "600");
        outtextxy(speed_1000.pozX, speed_1000.pozY, "1000");

    }

    if(speed_600.pozX <= pozX and pozX <= speed_600.pozX + 60 and speed_600.pozY <= pozY and pozY <speed_600.pozY + 25)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        settings.animationSpeed = 600;
        speed_0.press = false;
        speed_100.press = false;
        speed_600.press = true;
        speed_1000.press = false;

        settextstyle(9, 0, 4);
        setcolor(LIGHTBLUE);
        outtextxy(speed_600.pozX, speed_600.pozY, "600");
        setcolor(WHITE);
        outtextxy(speed_100.pozX, speed_100.pozY, "100");
        outtextxy(speed_0.pozX, speed_0.pozY, "0");
        outtextxy(speed_1000.pozX, speed_1000.pozY, "1000");
    }

    if(speed_1000.pozX <= pozX and pozX <= speed_1000.pozX + 80 and speed_1000.pozY <= pozY and pozY <speed_1000.pozY + 25)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        settings.animationSpeed = 1000;
        speed_0.press = false;
        speed_100.press = false;
        speed_600.press = false;
        speed_1000.press = true;

        settextstyle(9, 0, 4);
        setcolor(LIGHTBLUE);
        outtextxy(speed_1000.pozX, speed_1000.pozY, "1000");
        setcolor(WHITE);
        outtextxy(speed_100.pozX, speed_100.pozY, "100");
        outtextxy(speed_600.pozX, speed_600.pozY, "600");
        outtextxy(speed_0.pozX, speed_0.pozY, "0");
    }
}
void ReadColor(Button *button)
{
    if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

    int tasta, poz;
    char sir[10];

    strcpy(sir, button->text.buttonText);

    poz = strlen(sir);

    do
    {
        tasta = getch();

        if(tasta == 8 and poz > 3)
        {
            poz--;
            sir[poz] = '\0';
            strcpy(button->text.buttonText, sir);

            button->value /= 10;
        }

        if((tasta >= 48 and tasta <= 57) and poz < 6)
        {

            button->value = (button->value * 10) + (tasta - 48);

            if(button->value <= 255)
            {
                sir[poz] = tasta;
                sir[poz + 1] = '\0';
                poz++;
                strcpy(button->text.buttonText, sir);
            }
            else button->value /= 10;
        }

        setcolor(settings.backgroundColor);
        outtextxy(button->pozX, button->pozY, "000000");

        if(sir[0] == 'R') setcolor(RED);
        if(sir[0] == 'G') setcolor(GREEN);
        if(sir[0] == 'B') setcolor(LIGHTBLUE);

        outtextxy(button->pozX, button->pozY, button->text.buttonText);
    }
    while(tasta != 13);
}
void PressButtonSetBackgroundColor(int pozX, int pozY)
{
    if(buttonSetBackgroundColor.pozX <= pozX and pozX < buttonSetBackgroundColor.pozX + buttonSetBackgroundColor.width and buttonSetBackgroundColor.pozY <= pozY and pozY <= buttonSetBackgroundColor.pozY + buttonSetBackgroundColor.height)
    {
        if(settings.playFXSounds) PlaySound(TEXT("buttonsSound.wav"), NULL, SND_FILENAME|SND_ASYNC);

        settings.backgroundColor = RGB(backgroundColor_Red.value, backgroundColor_Green.value, backgroundColor_Blue.value);

        settings.backgroundColor_Red = backgroundColor_Red.value;
        settings.backgroundColor_Green = backgroundColor_Green.value;
        settings.backgroundColor_Blue = backgroundColor_Blue.value;

        setbkcolor(settings.backgroundColor);
        cleardevice();

        DrawSettingsScreen();
    }
}

int main()
{
    initwindow(screenWidth, screenHeight, "BibMat", 0, 0, false, false);

    setbkcolor(settings.backgroundColor);
    cleardevice();

    setlinestyle(0, 0, 3);

    InitializationData();

    DrawHomeScreen();

    showButtonsHome = true;

    bool ok = true;

    settings.animationSpeed = 400;

    while(ok == true)
    {
        int pozX = mousex();
        int pozY = mousey();

        //cout << pozX << " " << pozY << endl;

        if(showButtonsHome)
        {
            OverButtonVector(pozX, pozY);
            OverButtonMatrix(pozX, pozY);
            OverButtonSettings(pozX, pozY);
            OverButtonLoadData(pozX, pozY);
            OverButtonQuit(pozX, pozY);
        }

        if(showButtonsVector)
            OverButtonsVector(pozX, pozY);

        if(showButtonsMatrix)
            OverButtonsMatrix(pozX, pozY);

        if(showButtonsSettings)
            OverButtonsSettings(pozX, pozY);

        if(buttonBack.show)
            OverButtonBack(pozX, pozY);

        //MessageBox(0, "", "", MB_OK);

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);

            //setfillstyle(SOLID_FILL, settings.backgroundColor);
            //bar(0, 0, 390, 205);
            //bar(455, 20, 825, 205);
            //bar(890, 20, 1265, 205);

            if(showButtonsHome)
            {
                PressButtonVector(pozX, pozY);
                PressButtonMatrix(pozX, pozY);
                PressButtonSettings(pozX, pozY);
                PressButtonLoadData(pozX, pozY);
                PressButtonQuit(pozX, pozY, ok);
            }

            if(buttonBack.show)
                PressButtonBack(pozX, pozY);

            if(showButtonsVector)
            {
                SelectElementVector(pozX, pozY);

                PressButtonAdd(pozX, pozY);
                PressButtonSumVect(pozX, pozY);
                PressButtomProductVect(pozX, pozY);
                PressButtonSortVect(pozX, pozY);
                PressButtonShiftVect(pozX, pozY);
                PressButtonShiftLeftVect(pozX, pozY);
                PressButtonShiftRightVect(pozX, pozY);
                PressButtonProductScalarVect(pozX, pozY);

                PressButtonNextElementVect(pozX, pozY);
                PressButtonPreviewElementVect(pozX, pozY);
                PressButtonDeleteElementVect(pozX, pozY);

                if(buttonSelectionSortVect.show)
                    PressButtonSelectionSort(pozX, pozY);

                if(buttonQuicksortVect.show)
                    PressButtonQuickSort(pozX, pozY);
            }

            if(showButtonsMatrix)
            {
                SelectElementMatrix(pozX, pozY);
                PressButtonResizeMatrix(pozX, pozY);

                PressButtonSumMatrix(pozX, pozY);
                if(buttonSumMatrix.press)
                    ButtonEqual_Sum(pozX, pozY);

                PressButtonProductMatrix(pozX, pozY);
                if(buttonProductMatrix.press)
                    ButtonEqual_Product(pozX, pozY);

                PressButtonDecreaseMatrix(pozX, pozY);
                if(buttonDecreaseMatrix.press)
                    ButtonEqual_Decrease(pozX, pozY);

                PressButtonDetMatrix(pozX, pozY);
                if(buttonDetMatrix.press)
                    ButtonEqual_Det(pozX, pozY);

                PressButtonDivisionMatrix(pozX, pozY);
                if(buttonDivisionMatrix.press)
                    ButtonEqual_Division(pozX, pozY);

                PressButtonTransposeMatrix(pozX, pozY);

                PressButtonInverseMatrix(pozX, pozY);
                if(buttonInverseMatrix.press)
                    ButtonEqual_Inverse(pozX, pozY);

                PressButtonPow(pozX, pozY);

                AreasSum(pozX, pozY);
            }

            if(showButtonsSettings)
            {
                PressButton_Red(pozX, pozY);
                PressButton_Green(pozX, pozY);
                PressButton_Blue(pozX, pozY);

                PressButtonSetBackgroundColor(pozX, pozY);

                SelectSpeed(pozX, pozY);

                PressButtonVolum(pozX, pozY);
            }
        }
        delay(100);
    }
    closegraph();
}

#include "TXLib.h"
#include "WalleLib.h"

void draw_first_scene();
void draw_fon(  int x, int y, int fon);
void draw_second_scene();
void happy_end();

int main ()
{
    txCreateWindow(1200, 600);
    txSetFillColor(TX_BLACK);
    txClear();
    draw_first_scene();
    draw_second_scene();
    happy_end();
    return 0;
}
void draw_first_scene ()
{
    int xr;
    int xb;
    int xmax;
    int yb;
    int ymax;
    xmax = 600;
    xb = 730;
    ymax = 425;
    for (xr = 0; xr < xmax; xr += 3)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        draw_fon(600, 300, 1);
        draw_robot(xr, 475, 1.6, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 1, -1, 1, 1);
        draw_boot( xb, 510, 0.7, RGB(102,51,0) , TX_BLACK     , RGB(153,102,51) , 1, 1,  1, 1, 1);
        txSleep(30);
    }
    for (yb = 510; yb > ymax; yb -= 3)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        draw_fon(600, 300, 1);
        draw_robot(600, 475, 1.6, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 1, -1, 1, 1);
        draw_boot( xb , yb , 0.7, RGB(102,51,0) , TX_BLACK     , RGB(153,102,51) , 1, 0,  1, 1, 1);
        txSleep(30);
    }
    for (xr = 600; xr < 1200; xr += 3)
    {
        if(xr>600)
        {
            xb += 3;
            txSetFillColor(TX_BLACK);
            txClear();
            draw_fon(600, 300, 1);
            draw_boot(xb, 425, 0.7, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 1, 1, 1, 1);
        }
        draw_robot(xr, 475, 1.6, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 1, 1, -1, 1, 1);
        txSleep(30);
        txSetFillColor(TX_BLACK);
        txClear();
    }
}

void draw_second_scene()
{
    int xr;
    int xmaxr;
    int xb;
    int xn;
    int ye;
    int scalen;
    int xh;
    int yh;
    int xe;
    xmaxr = 700;
    scalen = 1;

    for (xr = 1200; xr > xmaxr; xr -= 3)
    {
        if(xr < 1200)
        {
            xb -= 3;
            xb = xr - 65;
            txSetFillColor(TX_BLACK);
            txClear();
            draw_fon(600, 300, 2);
            draw_boot(xb, 470, 0.4, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 1, -1, 1, 1);
        }
        draw_robot(xr, 500, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 1, 1, 1, 1, 1);
        txSleep(30);
        txSetFillColor(TX_BLACK);
        txClear();
    }
    for (xn = 0; xn < 400; xn += 3)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        draw_fon(600, 300, 2);
        draw_boot(xb, 470, 0.4, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 1, -1, 1, 1);
        draw_robot(xr, 500, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 1, 1, 1, 1, 1);
        draw_ufo(xn, 180, 0.9, TX_BLUE, RGB (51,51,153), 0, 0, 1, 1, -1);
        txSleep(30);
    }
    for (ye = 180; ye < 490; ye += 3)
    {
        if(xn <= 1200)
        {
            xn += 7;
            scalen ++;
            txSetFillColor(TX_BLACK);
            txClear();
            draw_fon(600, 300, 2);
            draw_eva(400, ye, 0.7, TX_WHITE, -1, -19, 1, 0, 0, 1);
            draw_ufo(xn, 180, 0.9/scalen, TX_BLUE, RGB (51,51,153), -35, 0, 1, 1, -1);
        }
        draw_boot(xb, 470, 0.4, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 1, -1, 1, 1);
        draw_robot(xr, 500, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 1, 1, 1, 1, 1);
        txSleep(30);
        txSetFillColor(TX_BLACK);
        txClear();
    }
    for (yh = -19; yh < -5; yh += 4)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        draw_fon(600, 300, 2);
        draw_eva(400, ye, 0.7, TX_WHITE, -1, yh, 1, 0, 0, 1);
        draw_boot(xb, 470, 0.4, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 1, -1, 1, 1);
        draw_robot(xr, 500, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 1, 1, 1, 1);
        txSleep(30);
    }
    for (xh = 0; xh < 15; xh += 3)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        draw_fon(600, 300, 2);
        draw_eva(400, ye, 0.7, TX_WHITE, -1, yh, 1, xh, 0, 1);
        draw_boot(xb, 470, 0.4, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 1, -1, 1, 1);
        draw_robot(xr, 500, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 1, 1, 1, 1);
        txSleep(30);
    }
    draw_eva(400, ye, 0.6, TX_WHITE, 1, yh, 1, xh, 0, 1);
    for (xe = 400; xe < 500; xe += 3)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        draw_fon(600, 300, 2);
        draw_eva(xe, ye, 0.7, TX_WHITE, 1, yh, 1, xh, 0, 1);
        draw_boot(xb, 470, 0.4, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 1, -1, 1, 1);
        draw_robot(xr, 500, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 1, 1, 1, 1);
        txSleep(30);
    }
}

void happy_end()
{
        draw_star(600, 120, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(600, 325, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(650, 80, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(550, 80, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(700, 80, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(500, 80, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(447, 140, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(753, 140, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(655, 275, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(545, 275, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(725, 200, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(475, 200, 0.25, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_fon(600, 300, 2);
        draw_eva(500, 490, 0.7, TX_WHITE, 1, -5, 1, 15, 0, 1);
        draw_boot(635, 470, 0.4, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 1, -1, 1, 1);
        draw_robot(700, 500, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 1, 1, 1, 1);
        txSetColor(RGB(255,255,51));
        txSetTextAlign (TA_CENTER);
        txSelectFont("playbill", 40, 30, 10, false, true);
        txTextOut(600, 180, "The End");
}

void draw_fon(int x, int y, int fon)  //фон
//fon - изменение фона: 1 - первая сцена, 2 - вторая сцена
{
    if (fon==1)
    {
        txSetFillColor(RGB(204,102,0));
        txSetColor(RGB(204,102,0));
        POINT a[4] = {{x - 600, y + 50},{x + 600, y + 50},{x + 600, y + 300},{x - 600, y + 300}};
        txPolygon(a,4);
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txCircle(100 , 50 , 2);
        txCircle(30  , 244, 2);
        txCircle(149 , 205, 2);
        txCircle(310 , 5  , 2);
        txCircle(268 , 156, 2);
        txCircle(279 , 150, 2);
        txCircle(290 , 90 , 2);
        txCircle(446 , 105, 2);
        txCircle(620 , 150, 2);
        txCircle(743 , 39 , 2);
        txCircle(300 , 225, 2);
        txCircle(506 , 230, 2);
        txCircle(525 , 270, 2);
        txCircle(503 , 300, 2);
        txCircle(556 , 305, 2);
        txCircle(725 , 150, 2);
        txCircle(750 , 120, 2);
        txCircle(760 , 148, 2);
        txCircle(756 , 170, 2);
        txCircle(690 , 175, 2);
        txCircle(838 , 46 , 2);
        txCircle(848 , 50 , 2);
        txCircle(1140, 53 , 2);
        txCircle(864 , 253, 2);
        txCircle(846 , 338, 2);
        txCircle(893 , 215, 2);
        txCircle(1100, 163, 2);
        txCircle(210 , 100, 3);
        txCircle(354 , 75 , 3);
        txCircle(550 , 97 , 3);
        txCircle(905 , 47 , 3);
        txCircle(1000, 50 , 3);
        txCircle(980 , 166, 3);
        txCircle(885 , 147, 3);
        txCircle(1058, 149, 3);
        txCircle(1050, 255, 3);
        txCircle(975 , 323, 3);
        txCircle(1145, 310, 3);
        txCircle(353 , 150, 3);
        txCircle(250 , 250, 3);
        txCircle(248 , 265, 3);
        txCircle(354 , 252, 3);
        txCircle(589 , 232, 3);
        txCircle(552 , 252, 3);
        txCircle(450 , 300, 3);
        txCircle(600 , 315, 3);
        txCircle(651 , 249, 3);
        txCircle(646 , 282, 3);
        txCircle(25  , 295, 3);
        txCircle(53  , 315, 3);
        draw_star(250 , 50 , 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(110 , 215, 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(700 , 155, 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(1000, 205, 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(638 , 10 , 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
    }
    else
    {
        txSetFillColor(RGB(204,102,0));
        txSetColor(RGB(204,102,0));
        POINT b[10] = {{x - 600, y + 150}, {x - 400, y + 110}, {x - 250, y + 85}, {x - 100, y + 75 },
                       {x + 100, y + 75 }, {x + 250, y + 85}, {x + 400, y + 110}, {x + 600, y + 150},
                       {x + 600, y + 325}, {x - 600, y + 325}};
        txPolygon(b,10);
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txCircle(100 , 50 , 2);
        txCircle(30  , 244, 2);
        txCircle(149 , 205, 2);
        txCircle(310 , 5  , 2);
        txCircle(268 , 156, 2);
        txCircle(279 , 150, 2);
        txCircle(290 , 90 , 2);
        txCircle(446 , 105, 2);
        txCircle(620 , 150, 2);
        txCircle(743 , 39 , 2);
        txCircle(300 , 225, 2);
        txCircle(506 , 230, 2);
        txCircle(525 , 270, 2);
        txCircle(503 , 300, 2);
        txCircle(556 , 305, 2);
        txCircle(725 , 150, 2);
        txCircle(750 , 120, 2);
        txCircle(760 , 148, 2);
        txCircle(756 , 170, 2);
        txCircle(690 , 175, 2);
        txCircle(838 , 46 , 2);
        txCircle(848 , 50 , 2);
        txCircle(1140, 53 , 2);
        txCircle(864 , 253, 2);
        txCircle(846 , 338, 2);
        txCircle(893 , 215, 2);
        txCircle(1100, 163, 2);
        txCircle(210 , 100, 3);
        txCircle(354 , 75 , 3);
        txCircle(550 , 97 , 3);
        txCircle(905 , 47 , 3);
        txCircle(1000, 50 , 3);
        txCircle(980 , 166, 3);
        txCircle(885 , 147, 3);
        txCircle(1058, 149, 3);
        txCircle(1050, 255, 3);
        txCircle(975 , 323, 3);
        txCircle(1145, 310, 3);
        txCircle(353 , 150, 3);
        txCircle(250 , 250, 3);
        txCircle(248 , 265, 3);
        txCircle(354 , 252, 3);
        txCircle(589 , 232, 3);
        txCircle(552 , 252, 3);
        txCircle(450 , 300, 3);
        txCircle(600 , 315, 3);
        txCircle(651 , 249, 3);
        txCircle(646 , 282, 3);
        txCircle(25  , 295, 3);
        txCircle(53  , 315, 3);
        draw_star(250 , 50 , 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(110 , 215, 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(700 , 155, 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(1000, 205, 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
        draw_star(638 , 10 , 0.19, RGB(255,255,51), RGB(255,255,51), 0, 0, 1, 0, 0);
    }
}


#include "TXLib.h"

void draw_star( int x, int y, double scale, COLORREF color1, COLORREF color2, int ray        , int ray2    , int dir      , int ray3    , int star1);
void draw_ufo(  int x, int y, double scale, COLORREF color1, COLORREF color2, int foot       , int height  , int dir      , int windows , int foots);
void draw_boot( int x, int y, double scale, COLORREF color1, COLORREF color2, COLORREF color3, double plant, double plant2, int dir     , int green, int dir2);
void draw_robot(int x, int y, double scale, COLORREF color1, COLORREF color2, COLORREF color3, double eyes , double hand  , int dir     , int circle, int kolesa);
void draw_eva(  int x, int y, double scale, COLORREF color1, int eyes       , int had        , int dir     , int hands    , int hands2  , int ogonek);

int main ()
{
    txCreateWindow(1550, 900);

    draw_star(200 , 100, 0.9, RGB(255,255,51), RGB(255,255,51), 20,  0,  1,  0, 0);
    draw_star(400 , 100, 0.9, RGB(255,255,51), RGB(255,255,51),  0, 20,  1,  0, 0);
    draw_star(600 , 100, 0.5, RGB(255,255,51), RGB(255,255,51),  0,  0,  1, 20, 0);
    draw_star(800 , 100, 0.9, RGB(255,255,51), RGB(255,255,51),  0,  0,  1,  0, 1);
    draw_star(1000, 140, 0.9, RGB(255,255,51), RGB(255,255,51),  0,  0, -1,  0, 0);

    draw_ufo(200 , 280, 0.8, TX_BLUE, RGB (51,51,153), -35,  0,  1,  1,  1);
    draw_ufo(450 , 280, 0.8, TX_BLUE, RGB (51,51,153),   0, 15,  1,  1,  1);
    draw_ufo(700 , 280, 0.6, TX_BLUE, RGB (51,51,153),   0,  0, -1,  1, -1);
    draw_ufo(950 , 280, 0.8, TX_BLUE, RGB (51,51,153),   0,  0,  1, -1,  1);
    draw_ufo(1200, 280,   1, TX_BLUE, RGB (51,51,153),   0,  0,  1,  1,  1);

    draw_boot(200 , 410,   1, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 1, 0,  1,  1,  1);
    draw_boot(400 , 410,   1, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 0, 1,  1,  1,  1);
    draw_boot(500 , 410,   1, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 0, 0, -1,  1,  1);
    draw_boot(800 , 410,   1, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 0, 0,  1, -1,  1);
    draw_boot(1000, 460, 0.5, RGB(102,51,0), TX_BLACK, RGB(153,102,51), 0, 0,  1,  1, -1);

    draw_robot(200 , 600, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 1, 0,  1,  1,  0);
    draw_robot(400 , 600, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 1,  1,  1,  0);
    draw_robot(600 , 600, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 0, -1,  1,  0);
    draw_robot(800 , 600, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 0,  1, -1,  0);
    draw_robot(1000, 600, 1, RGB(102,51,51), RGB(102,51,0), RGB(255,204,153), 0, 0,  1,  1, 20);

    draw_eva(400,  750, 0.7, TX_WHITE, -1,  1, 1,  0,  0, -1);
    draw_eva(600,  750, 0.7, TX_WHITE,  1, 10, 1,  0,  0, -1);
    draw_eva(800,  750, 0.7, TX_WHITE,  1,  1, 1, 20,  0, -1);
    draw_eva(1000, 750, 0.7, TX_WHITE,  1,  1, 1,  0, 20, -1);
    draw_eva(1200, 750,   1, TX_WHITE,  1,  1, 1,  0,  0,  1);

    return 0;
}

void draw_star( int x, int y, double scale, COLORREF color1, COLORREF color2, int ray, int ray2, int dir, int ray3, int star1) //������
//ray - ��������� ����� �������� ������ ����      //ray3 - ��������� ����� ������� ������ ����         //star1 - ������ ����
//ray2 - ��������� ����� ������� ������� ����     //dir - �������� ���������
{
    txSetFillColor(color1);
    txSetColor(color2, 5*scale);
    POINT star[5] = {{x-int(50*scale+ray3), y+int(75*scale*dir)}, {x              , y                  }, {x+int(50*scale), y+int(75*scale*dir+ray2)},
                     {x-int(50*scale+ray) , y+int(25*scale*dir)}, {x+int(50*scale), y+int(25*scale*dir)}};
    txPolygon(star, 5);

    if (star1==1)
    {
        txLine(x-int(25*scale), y+int(8*scale*dir) , x-int(40*scale), y-int(5*scale*dir  ));
        txLine(x+int(25*scale), y+int(8*scale*dir) , x+int(40*scale), y-int(5*scale*dir  ));
        txLine(x              , y+int(75*scale*dir), x              , y+int(100*scale*dir));
        txLine(x+int(47*scale), y+int(50*scale*dir), x+int(70*scale), y+int(61*scale*dir ));
        txLine(x-int(47*scale), y+int(50*scale*dir), x-int(70*scale), y+int(61*scale*dir ));
    }
}

void draw_ufo( int x, int y, double scale, COLORREF color1, COLORREF color2, int foot, int height, int dir, int windows, int foots) //�������� �������
//foot - ��������� ����� ��� , �� -75 �� 0   //dir  - �������� ���������           //foots - ��������� ���
//height - ��������� ������                  //windows - ��������� �������������
{
    txSetColor(color1, 3*scale);
    txSetFillColor(color2);
    POINT nlo[6] = {{x-int(125*scale), y}, {x-int(75*scale), y-int(50*scale*dir+height)}, {x+int(75*scale), y-int(50*scale*dir+height)}, //������
                    {x+int(125*scale), y}, {x+int(75*scale), y+int(25*scale*dir)       }, {x-int(75*scale), y+int(25*scale*dir       )}};
    txPolygon(nlo, 6);
    txSetFillColor(RGB (204,153,51));
    txLine(x-int(125*scale), y, x+int(125*scale), y); //������ �� �������
    txSetFillColor(TX_WHITE);
    txSetColor(TX_WHITE, 4*scale);
    txLine(x-int(25*scale), y-int(50*scale*dir+height), x              , y-int(75*scale*dir+height)); //������� �����
    txLine(x              , y-int(75*scale*dir+height), x+int(25*scale), y-int(50*scale*dir+height));

    if (windows==1)
    {
        txCircle (x-int(25*scale), y-int(25*scale*dir), 3*scale); //������������
        txCircle (x+int(25*scale), y-int(25*scale*dir), 3*scale);
    }
    else
    {
        txCircle (x-int(25*scale), y-int(25*scale*dir), 6*scale); //������������
        txCircle (x+int(25*scale), y-int(25*scale*dir), 6*scale);
    }

    if (foots==1)
    {
        txLine (x-int(75*scale), y+int(25*scale*dir), x-int(100*scale), y+int(100*scale*dir+foot)); //����
        txLine (x              , y+int(25*scale*dir), x               , y+int(100*scale*dir+foot));
        txLine (x+int(75*scale), y+int(25*scale*dir), x+int(100*scale), y+int(100*scale*dir+foot));
    }
}

void draw_boot( int x, int y, double scale, COLORREF color1, COLORREF color2, COLORREF color3, double plant, double plant2, int dir, int green, int dir2) //�������
//plant - ��������� ��������� �������� �� ��� x , �� 0 �� 1      //dir - �������� ��������� ����-�����     //dir2 - �������� ��������� ����-���
//plant2 - ��������� ��������� �������� �� ��� y , �� 0 �� 1     //green - ��������� ��������
{
    txSetFillColor(color1);
    txSetColor(color2, 3*scale);
    POINT a[19] = {{x-int(101*scale*dir), y+int(61*scale*dir2)}, {x-int(83*scale*dir), y+int(71*scale*dir2)}, {x-int(10*scale*dir), y+int(73*scale*dir2)}, //�������� �����
                   {x-int(2*scale*dir)  , y+int(61*scale*dir2)}, {x                  , y+int(47*scale*dir2)}, {x-int(32*scale*dir), y+int(48*scale*dir2)},
                   {x-int(34*scale*dir) , y+int(46*scale*dir2)}, {x-int(34*scale*dir), y+int(36*scale*dir2)}, {x-int(42*scale*dir), y+int(22*scale*dir2)},
                   {x-int(60*scale*dir) , y+int(21*scale*dir2)}, {x-int(63*scale*dir), y+int(21*scale*dir2)}, {x-int(65*scale*dir), y+int(28*scale*dir2)},
                   {x-int(63*scale*dir) , y+int(32*scale*dir2)}, {x-int(67*scale*dir), y+int(44*scale*dir2)}, {x-int(70*scale*dir), y+int(36*scale*dir2)},
                   {x-int(75*scale*dir) , y+int(40*scale*dir2)}, {x-int(91*scale*dir), y+int(34*scale*dir2)}, {x-int(93*scale*dir), y+int(35*scale*dir2)},
                   {x-int(107*scale*dir), y+int(44*scale*dir2)}};
    txPolygon(a, 19);
    txSetFillColor(color3);
    POINT b[11] = {{x                  , y+int(47*scale*dir2)}, {x-int(32*scale*dir), y+int(48*scale*dir2)}, {x-int(34*scale*dir), y+int(46*scale*dir2)},  //������������ �����
                   {x-int(34*scale*dir), y+int(36*scale*dir2)}, {x-int(42*scale*dir), y+int(22*scale*dir2)}, {x-int(32*scale*dir), y+int(20*scale*dir2)},
                   {x-int(1*scale*dir) , y+int(5*scale*dir2) }, {x                  , y                   }, {x+int(3*scale*dir) , y+int(2*scale*dir2) },
                   {x+int(10*scale*dir), y+int(22*scale*dir2)}, {x+int(13*scale*dir), y+int(42*scale*dir2)}};
    txPolygon(b,11);
    POINT c[7] = {{x-int(60*scale*dir), y+int(21*scale*dir2)}, {x-int(42*scale*dir), y+int(22*scale*dir2)}, {x-int(32*scale*dir), y+int(20*scale*dir2)}, //���������{x,y},
                  {x-int(1*scale*dir) , y+int(5*scale*dir2) }, {x                  , y                   }, {x-int(3*scale*dir) , y+int(2*scale*dir2)},
                  {x-int(57*scale*dir), y+int(17*scale*dir2)}};
    txPolygon(c, 7);
    txSetFillColor(RGB (51,153,51));
    txSetColor(RGB (51,102,0));

    if (green==1)
    {
        txLine(x-int(42*scale*dir),            y+int(22*scale*dir2)           , x-int((32-20*plant)*scale*dir), y-int(4*scale*dir2)            );  //��������
        txLine(x-int((32-20*plant)*scale*dir), y-int(4*scale*dir2)            , x-int((40-20*plant)*scale*dir), y-int((9+15*plant2)*scale*dir2));
        txLine(x-int((40-20*plant)*scale*dir), y-int((9+15*plant2)*scale*dir2), x-int((65-20*plant)*scale*dir), y-int((9+15*plant2)*scale*dir2));
        POINT d[7] = {{x-int((65-20*plant)*scale*dir), y-int((9+15*plant2)*scale*dir2)}, {x-int((72-20*plant)*scale*dir), y-int((9+15*plant2)*scale*dir2)},   //��������
                      {x-int((75-20*plant)*scale*dir), y-int((5+15*plant2)*scale*dir2)}, {x-int((76-20*plant)*scale*dir), y-int((1+15*plant2)*scale*dir2)},
                      {x-int((76-20*plant)*scale*dir), y+int((1-15*plant2)*scale*dir2)}, {x-int((67-20*plant)*scale*dir), y-int((4+15*plant2)*scale*dir2)},
                      {x-int((65-20*plant)*scale*dir), y-int((7+15*plant2)*scale*dir2)}};

        txPolygon(d, 7);
    }
}

void draw_robot( int x, int y, double scale, COLORREF color1, COLORREF color2, COLORREF color3, double eyes, double hand, int dir, int circle, int kolesa) //�����
//eyes - ��������� ���� , 1 - ������� , 0 - �������   //dir - �������� ���������  //kolesa - ��������� ��������� ����� �� y
//hand - ��������� ����� ���� , �� 0 �� 1             //circle - ��������� �����
{
    txSetFillColor(color1);
    txSetColor(TX_BLACK, 2*scale);
    POINT t[10] = {{x-int(45*scale*dir), y+int(25*scale)}, {x+int(15*scale*dir), y+int(25*scale)}, {x+int(25*scale*dir), y              }, //����
                   {x+int(25*scale*dir), y-int(25*scale)}, {x+int(13*scale*dir), y-int(37*scale)}, {x+int(2*scale*dir) , y-int(47*scale)},
                   {x-int(17*scale*dir), y-int(42*scale)}, {x-int(16*scale*dir), y-int(27*scale)}, {x-int(18*scale*dir), y-int(10*scale)},
                   {x-int(22*scale*dir), y+int(2*scale)}};
    txPolygon(t, 10);
    txSetFillColor(color2);
    POINT h[8] = {{x-int(45*scale*dir), y+int((25-kolesa)*scale)}, {x+int(15*scale*dir), y+int((25-kolesa)*scale)}, {x+int(25*scale*dir), y+int((34-kolesa)*scale)}, //��������
                  {x+int(25*scale*dir), y+int((41-kolesa)*scale)}, {x+int(15*scale*dir), y+int((50-kolesa)*scale)}, {x-int(50*scale*dir), y+int((50-kolesa)*scale)},
                  {x-int(57*scale*dir), y+int((41-kolesa)*scale)}, {x-int(57*scale*dir), y+int((34-kolesa)*scale)}};
    txPolygon(h, 8);
    POINT k[9] = {{x+int(2*scale*dir) , y-int(47*scale) }, {x-int(17*scale*dir), y-int(42*scale)}, {x-int(21*scale*dir), y-int(37*scale)}, //������
                  {x-int(13*scale*dir), y-int(50*scale) }, {x-int(12*scale*dir), y-int(70*scale)}, {x-int(20*scale*dir), y-int(74*scale)},
                  {x+int(2*scale*dir) , y-int(72*scale) }, {x+int(10*scale*dir), y-int(68*scale)}, {x+int(10*scale*dir), y-int(50*scale)}};
    txPolygon(k, 9);
    txSetFillColor(color3);
    txSetColor(RGB (102,51,0), 2*scale);
    POINT j[8] = {{x-int(17*scale*dir), y-int(42*scale)}, {x-int(13*scale*dir), y-int(50*scale)}, {x-int(12*scale*dir), y-int(70*scale)},  //����
                  {x-int(20*scale*dir), y-int(74*scale)}, {x-int(35*scale*dir), y-int(73*scale)}, {x-int(48*scale*dir), y-int(72*scale)},
                  {x-int(50*scale*dir), y-int(62*scale)}, {x-int(46*scale*dir), y-int(50*scale)}};
    txPolygon(j,8);
    POINT e[4] = {{x-int(25*scale*dir), y-int((50+20*eyes)*scale)}, {x-int(22*scale*dir), y-int(60*scale)}, {x-int(25*scale*dir), y-int(65*scale)},  //����
                  {x-int(28*scale*dir), y-int(59*scale)         }};
    txPolygon(e,4);
    POINT s[4] = {{x-int(42*scale*dir), y-int((53+20*eyes)*scale)}, {x-int(39*scale*dir), y-int(59*scale)}, {x-int(42*scale*dir), y-int(67*scale)},  //����
                  {x-int(45*scale*dir), y-int(61*scale)         }};
    txPolygon(s,4);

    if (circle==1)
    {
        txCircle(x-int(37*scale*dir), y+int((38-kolesa)*scale), 8*scale);
        txCircle(x-int(17*scale*dir), y+int((38-kolesa)*scale), 8*scale);
        txCircle(x+int(3*scale*dir) , y+int((38-kolesa)*scale), 8*scale);
    }

    POINT l[7] = {{x-int((32+10*hand)*scale*dir), y-int(21*scale)}, {x-int((49+10*hand)*scale*dir), y-int(23*scale)}, {x-int((51+10*hand)*scale*dir), y-int(18*scale)}, //�����
                  {x-int((42+10*hand)*scale*dir), y-int(9*scale) }, {x-int((39+10*hand)*scale*dir), y-int(15*scale)}, {x-int((43+10*hand)*scale*dir), y-int(19*scale)},
                  {x-int((37+10*hand)*scale*dir), y-int(23*scale)}};
    txPolygon(l,7);
    txSetColor(RGB (255,204,153), 2*scale);
    txLine(x-int((32+10*hand)*scale*dir), y-int(21*scale), x-int((25+10*hand)*scale*dir), y-int(10*scale)); //����
    txLine(x-int((25+10*hand)*scale*dir), y-int(10*scale), x-int(4*scale*dir)           , y-int(10*scale));
}

void draw_eva( int x, int y, double scale, COLORREF color1, int eyes, int had, int dir, int hands, int hands2, int ogonek)
//dir - �������� ���������                    //eyes - ��������� ����        //hands2 - ��������� ��� �� y
//had - ��������� ��������� ������ �� y       //hands - ��������� ��� �� x   //ogonek - ��������� ����� �������
{
    txSetFillColor(color1);
    txSetColor(color1);
    txPie(x-int(38*scale), y-int((100+had)*scale*dir), x+int(37*scale), y+int((5-had)*scale*dir), 0, 180);      //������
    POINT a[4] = {{x-int(33*scale), y-int(30*scale*dir)}, {x+int(32*scale), y-int(30*scale*dir)},
                  {x+int(32*scale), y+int(30*scale*dir)}, {x-int(33*scale), y+int(30*scale*dir)}};       //����
    txPolygon(a,4);
    txPie(x-int(33*scale), y-int(7*scale*dir), x+int(32*scale), y+int(68*scale*dir), 180, 180);
    POINT b[6] = {{x-int((33+hands)*scale), y-int((30+hands2)*scale*dir)}, {x-int((39+hands)*scale), y-int((30+hands2)*scale*dir)}, {x-int((43+hands)*scale), y-int((25+hands2)*scale*dir)},// ����� ����
                  {x-int((43+hands)*scale), y+int((10-hands2)*scale*dir)}, {x-int((39+hands)*scale), y+int((25-hands2)*scale*dir)}, {x-int((33+hands)*scale), y+int((40-hands2)*scale*dir)}};
    txPolygon(b,6);
    POINT c[6] = {{x+int((32+hands)*scale), y-int((30+hands2)*scale*dir)}, {x+int((36+hands)*scale), y-int((30+hands2)*scale*dir)}, {x+int((40+hands)*scale), y-int((25+hands2)*scale*dir)},
                  {x+int((40+hands)*scale), y+int((10-hands2)*scale*dir)}, {x+int((36+hands)*scale), y+int((25-hands2)*scale*dir)}, {x+int((31+hands)*scale), y+int((40-hands2)*scale*dir)}};  // ������ ����
    txPolygon(c, 6);
    txSetColor(TX_BLACK);

    if (ogonek==1)
    {
        txSetFillColor(TX_GREEN);
        txCircle(x+int(14*scale), y-int(16*scale*dir), 5*scale);
    }
    else
    {
        txCircle(x+int(14*scale), y-int(16*scale*dir), 5*scale);
    }

    txSetFillColor(TX_BLACK);
    txPie(x-int(28*scale), y-int((90+had)*scale*dir), x+int(27*scale), y-int((17+had)*scale*dir), 0, 180);
    txSetFillColor(TX_BLUE);

    if (eyes==1)
    {
        txEllipse(x-int(18*scale), y-int((78+had)*scale*dir), x-int(7*scale) , y-int((60+had)*scale*dir));     //�����
        txEllipse(x+int(4*scale) , y-int((78+had)*scale*dir), x+int(15*scale), y-int((60+had)*scale*dir));
    }

}

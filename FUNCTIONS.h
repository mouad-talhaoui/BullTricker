#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void piontodane(int *HorizPosition)
{
        int j = 0;
        for (int i = 0; i < 7; i++)
        {
                if ((*(HorizPosition + i * 8)) == 2)
                {
                        (*(HorizPosition + 8 * i)) = 4;
                }
        }
        j = 7;
        for (int i = 0; i < 7; i++)
        {
                if ((*(HorizPosition + i * 8 + j)) == 1)
                {
                        (*(HorizPosition + 8 * i + j)) = 3;
                }
        }
}

int ismat(int *KingPosition, int *HorizPosition, int *VertPosition)
{
        int ib, jb, iw, jw;
        for (int i = 0; i < 7; i++)
        {
                for (int j = 0; j < 7; j++)
                {
                        if ((*(KingPosition + i * 7 + j)) == 1)
                        {
                                ib = i;
                                jb = j;
                        }
                        else if ((*(KingPosition + i * 7 + j)) == 2)
                        {
                                iw = i;
                                jw = j;
                        }
                }
        }
        int nbb = 0, nbw = 0;
        // ismat white
        if ((*(HorizPosition + iw * 8 + jw)) == 4 || (*(HorizPosition + iw * 8 + jw)) == 2)
        {
                nbw++;
        }
        if ((*(HorizPosition + iw * 8 + jw)) == 1 || (*(HorizPosition + iw * 8 + jw)) == 3)
        {
                nbb++;
        }
        if ((*(HorizPosition + (iw)*8 + jw + 1)) == 4 || (*(HorizPosition + (iw)*8 + 1 + jw)) == 2)
        {
                nbw++;
        }
        if ((*(HorizPosition + (iw)*8 + 1 + jw)) == 1 || (*(HorizPosition + (iw)*8 + 1 + jw)) == 3)
        {
                nbb++;
        }
        if ((*(VertPosition + iw + 8 * jw)) == 4 || (*(VertPosition + iw + 8 * jw)) == 2)
        {
                nbw++;
        }
        if ((*(VertPosition + iw + 8 * jw)) == 1 || (*(VertPosition + iw + 8 * jw)) == 3)
        {
                nbb++;
        }
        if ((*(VertPosition + iw + 1 + (jw)*8)) == 4 || (*(VertPosition + iw + 1 + (jw)*8)) == 2)
        {
                nbw++;
        }
        if ((*(VertPosition + iw + 1 + (jw)*8)) == 1 || (*(VertPosition + iw + 1 + (jw)*8)) == 3)
        {
                nbb++;
        }
        if (nbb + nbw == 4 && nbb >= 1)
        {
                printf("players black win");
                return 1;
        }
        // ismat black
        nbb = 0;
        nbw = 0;
        if ((*(HorizPosition + ib * 8 + jb)) == 4 || (*(HorizPosition + ib * 8 + jb)) == 2)
        {
                nbw++;
        }
        if ((*(HorizPosition + ib * 8 + jb)) == 1 || (*(HorizPosition + ib * 8 + jb)) == 3)
        {
                nbb++;
        }
        if ((*(HorizPosition + (ib)*8 + jb + 1)) == 4 || (*(HorizPosition + (ib)*8 + 1 + jb)) == 2)
        {
                nbw++;
        }
        if ((*(HorizPosition + (ib)*8 + 1 + jb)) == 1 || (*(HorizPosition + (ib)*8 + 1 + jb)) == 3)
        {
                nbb++;
        }
        if ((*(VertPosition + ib + 8 * jb)) == 4 || (*(VertPosition + ib + 8 * jb)) == 2)
        {
                nbw++;
        }
        if ((*(VertPosition + ib + 8 * jb)) == 1 || (*(VertPosition + ib + 8 * jb)) == 3)
        {
                nbb++;
        }
        if ((*(VertPosition + ib + 1 + (jb)*8)) == 4 || (*(VertPosition + ib + 1 + (jb)*8)) == 2)
        {
                nbw++;
        }
        if ((*(VertPosition + ib + 1 + (jb)*8)) == 1 || (*(VertPosition + ib + 1 + (jb)*8)) == 3)
        {
                nbb++;
        }
        if (nbb + nbw == 4 && nbw >= 1)
        {
                printf("players white win");
                return -1;
        }
        return 0;
}

void moveking(int *KingPosition, int i1, int j1, int i2, int j2)
{
        (*(KingPosition + i2 * 7 + j2)) = (*(KingPosition + 7 * i1 + j1));
        (*(KingPosition + i1 * 7 + j1)) = 0;
}

void Horiz(int *HorizPosition, int i1, int j1, int i2, int j2)
{
        (*(HorizPosition + i2 * 8 + j2)) = (*(HorizPosition + 8 * i1 + j1));
        (*(HorizPosition + i1 * 8 + j1)) = 0;
}

void Vert(int *VertPosition, int i1, int j1, int i2, int j2)
{
        (*(VertPosition + i2 * 8 + j2)) = (*(VertPosition + 8 * i1 + j1));
        (*(VertPosition + i1 * 8 + j1)) = 0;
}

void VH(int *VertPosition, int *HorizPosition, int i1, int j1, int i2, int j2)
{
        (*(HorizPosition + i2 * 8 + j2)) = (*(VertPosition + 8 * i1 + j1));
        (*(VertPosition + i1 * 8 + j1)) = 0;
}

void HV(int *VertPosition, int *HorizPosition, int i1, int j1, int i2, int j2)
{
        (*(VertPosition + 8 * i2 + j2)) = (*(HorizPosition + i1 * 8 + j1));
        (*(HorizPosition + i1 * 8 + j1)) = 0;
}

int *ClickPositionDetection(int x, int y)
{

        int *detected = malloc(5 * sizeof(int)); // I J C V H
        (*(detected)) = -1;
        (*(detected + 1)) = -1;
        (*(detected + 2)) = -1;
        (*(detected + 3)) = -1;
        (*(detected + 4)) = -1;
        if (((y <= 30) && (y >= 10)))
        {
                if (((x >= 20) && (x <= 110)))
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
        }

        else if (30 < y && y < 120)
        {
                if (0 < x && x < 20)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (20 < x && x < 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (110 < x && x < 130)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (220 < x && x < 240)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (330 < x && x < 350)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (440 < x && x < 460)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (550 < x && x < 570)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (660 < x && x < 680)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (770 < x && x < 790)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
        }
        else if (((120 < y) && (y < 140)))
        {
                if ((x >= 20) && (x <= 110))
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
        }

        else if (140 < y && y < 230)
        {
                if (0 < x && x < 20)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (20 < x && x < 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (110 < x && x < 130)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (220 < x && x < 240)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (330 < x && x < 350)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (440 < x && x < 460)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (550 < x && x < 570)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (660 < x && x < 680)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (770 < x && x < 790)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
        }
        else if ((230 < y && (250 > y)))
        {
                if ((20 < x) && (x < 110))
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
        }

        else if (250 < y && y < 340)
        {
                if (0 < x && x < 20)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (20 < x && x < 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (110 < x && x < 130)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (220 < x && x < 240)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (330 < x && x < 350)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (440 < x && x < 460)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (550 < x && x < 570)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (660 < x && x < 680)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (770 < x && x < 790)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
        }
        else if (340 < y && 360 > y)
        {
                if (x >= 20 && x <= 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
        }

        else if (360 < y && y < 450)
        {
                if (0 < x && x < 20)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (20 < x && x < 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (110 < x && x < 130)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (220 < x && x < 240)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (330 < x && x < 350)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (440 < x && x < 460)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (550 < x && x < 570)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (660 < x && x < 680)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (770 < x && x < 790)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
        }
        else if (((450 < y) && (y < 470)))
        {
                if (((x >= 20) && (x <= 110)))
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
        }

        else if (470 < y && y < 560)
        {
                if (0 < x && x < 20)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (20 < x && x < 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (110 < x && x < 130)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (220 < x && x < 240)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (330 < x && x < 350)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (440 < x && x < 460)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (550 < x && x < 570)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (660 < x && x < 680)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (770 < x && x < 790)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
        }
        else if (((560 < y) && (y < 580)))
        {
                if (x >= 20 && x <= 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
        }

        else if (580 < y && y < 670)
        {
                if (0 < x && x < 20)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (20 < x && x < 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (110 < x && x < 130)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (220 < x && x < 240)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (330 < x && x < 350)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (440 < x && x < 460)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (550 < x && x < 570)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (660 < x && x < 680)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (770 < x && x < 790)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
        }
        else if (((670 < y) && (y < 690)))
        {
                if (((x >= 20) && (x <= 110)))
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
        }

        else if (690 < y && y < 780)
        {
                if (0 < x && x < 20)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 0;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (20 < x && x < 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (110 < x && x < 130)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 1;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (220 < x && x < 240)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 2;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (330 < x && x < 350)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 3;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (440 < x && x < 460)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 4;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (550 < x && x < 570)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 5;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (660 < x && x < 680)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 6;
                        (*(detected + 2)) = 1;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 0;
                }
                else if (770 < x && x < 790)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 1;
                        (*(detected + 4)) = 0;
                }
        }
        else if (((780 < y) && (y < 800)))
        {
                if (x > 20 && x < 110)
                {
                        (*(detected)) = 0;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (130 < x && x < 220)
                {
                        (*(detected)) = 1;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (240 < x && x < 330)
                {
                        (*(detected)) = 2;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (350 < x && x < 440)
                {
                        (*(detected)) = 3;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (460 < x && x < 550)
                {
                        (*(detected)) = 4;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (570 < x && x < 660)
                {
                        (*(detected)) = 5;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
                else if (680 < x && x < 770)
                {
                        (*(detected)) = 6;
                        (*(detected + 1)) = 7;
                        (*(detected + 2)) = 0;
                        (*(detected + 3)) = 0;
                        (*(detected + 4)) = 1;
                }
        }

        return detected;
}

void reinit(int *KingPosition, int *HorizPosition, int *VertPosition){

int KingPosition1[7][7] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}};
int HorizPosition1[7][8] = {
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0}};
int VertPosition1[7][8] = {
    {3, 3, 3, 3, 3, 3, 3, 3},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {2, 2, 2, 2, 2, 2, 2, 2},
    {4, 4, 4, 4, 4, 4, 4, 4}};
     *KingPosition = &KingPosition1;
     *HorizPosition = &HorizPosition1;
     *VertPosition = &VertPosition1;

}
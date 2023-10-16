#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "FUNCTIONS.h"
int KingPosition[7][7] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}};
int HorizPosition[7][8] = {
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0},
    {0, 1, 0, 0, 0, 0, 2, 0}};
int VertPosition[7][8] = {
    {3, 3, 3, 3, 3, 3, 3, 3},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {2, 2, 2, 2, 2, 2, 2, 2},
    {4, 4, 4, 4, 4, 4, 4, 4}};
int main(int argc, char *args[])
{
    int running = 1;

    const SDL_MessageBoxButtonData buttons[] = {
        {/* .flags, .buttonid, .text */ 0, 0, "Play"},
        {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Exit"}};
    const SDL_MessageBoxColorScheme colorScheme = {
        {/* .colors (.r, .g, .b) */
         /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
         {239, 156, 114},
         /* [SDL_MESSAGEBOX_COLOR_TEXT] */
         {0, 0, 0},
         /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
         {253, 206, 138},
         /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
         {253, 206, 138},
         /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
         {255, 0, 255}}};
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, /* .flags */
        NULL,                       /* .window */
        "BullTricker",              /* .title */
        "        Welcome",          /* .message */
        SDL_arraysize(buttons),     /* .numbuttons */
        buttons,                    /* .buttons */
        &colorScheme                /* .colorScheme */
    };
    int OpenGame = 0;
    int isYourTurn = 0;
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0)
    {
        SDL_Log("error displaying message box");
        return 1;
    }
    if (buttonid == -1)
    {
        SDL_Log("no selection");
    }
    else
    {
        SDL_Log("selection was %s", buttons[buttonid].text);
        const *ng = "Play";
        if (strcmp(buttons[buttonid].text, ng) == 0)
        {
            OpenGame = 1;
        }
    }
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *Window = SDL_CreateWindow("BULLTRICKER", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 810, SDL_WINDOW_OPENGL);
    // declaration des defferentes variables
    int *pKingPosition = &KingPosition;
    int *pHorizPosition = &HorizPosition;
    int *pVertPosition = &VertPosition;
    int x1, y1, x2, y2;
    int *detected1;
    int *detected2;

    SDL_Renderer *renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    while (running && OpenGame)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }
        SDL_Rect BoardSquareMatrix[7][7];
        SDL_Rect BoardHorizontalRectMatrix[7][8];
        SDL_Rect BoardVerticalRectMatrix[8][7];
        SDL_Rect SquareKingBlack;
        SDL_Rect SquareKingWhite;
        // Drawing the board
        SDL_SetRenderDrawColor(renderer, 239, 156, 114, 255);
        SDL_RenderClear(renderer);
        // Initialisation des Carr�es
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                int x = 20 + (i * 110);
                int y = 30 + (j * 110);
                SDL_SetRenderDrawColor(renderer, 239, 156, 114, 255);
                BoardSquareMatrix[i][j].x = x;
                BoardSquareMatrix[i][j].y = y;
                BoardSquareMatrix[i][j].w = 90;
                BoardSquareMatrix[i][j].h = 90;
                SDL_RenderFillRect(renderer, &BoardSquareMatrix[i][j]);
                switch (KingPosition[i][j])
                {
                case 1:
                {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SquareKingBlack.x = x + 5;
                    SquareKingBlack.y = y + 5;
                    SquareKingBlack.w = 80;
                    SquareKingBlack.h = 80;
                    SDL_RenderFillRect(renderer, &SquareKingBlack);
                }
                break;
                case 2:
                {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    SquareKingWhite.x = x + 5;
                    SquareKingWhite.y = y + 5;
                    SquareKingWhite.w = 80;
                    SquareKingWhite.h = 80;
                    SDL_RenderFillRect(renderer, &SquareKingWhite);
                }
                break;
                }
            }
        }
        // Initialisation des Rectangles Horizontaux
        {
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    int x = 20 + (i * 110);
                    int y = 10 + (j * 110);
                    switch (HorizPosition[i][j])
                    {
                    case 0:
                    {
                        SDL_SetRenderDrawColor(renderer, 253, 206, 138, 255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 90;
                        BoardHorizontalRectMatrix[i][j].h = 20;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    case 1:
                    {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 90;
                        BoardHorizontalRectMatrix[i][j].h = 20;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    case 2:
                    {
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 90;
                        BoardHorizontalRectMatrix[i][j].h = 20;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    case 3:
                    {
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 90;
                        BoardHorizontalRectMatrix[i][j].h = 20;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    case 4:
                    {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                        BoardHorizontalRectMatrix[i][j].x = x;
                        BoardHorizontalRectMatrix[i][j].y = y;
                        BoardHorizontalRectMatrix[i][j].w = 90;
                        BoardHorizontalRectMatrix[i][j].h = 20;
                        SDL_RenderFillRect(renderer, &BoardHorizontalRectMatrix[i][j]);
                    }
                    break;
                    }
                }
            }
        }
        // Initialisation des Rectangles Verticaux
        {
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    int x = (j * 110);
                    int y = 30 + (i * 110);
                    switch (VertPosition[i][j])
                    {
                    case 0:
                    {
                        SDL_SetRenderDrawColor(renderer, 253, 206, 138, 255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 20;
                        BoardVerticalRectMatrix[i][j].h = 90;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 1:
                    {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 20;
                        BoardVerticalRectMatrix[i][j].h = 90;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 2:
                    {
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 20;
                        BoardVerticalRectMatrix[i][j].h = 90;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 3:
                    {
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 20;
                        BoardVerticalRectMatrix[i][j].h = 90;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 4:
                    {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 20;
                        BoardVerticalRectMatrix[i][j].h = 90;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    case 5:
                    {
                        SDL_SetRenderDrawColor(renderer, 11, 252, 3, 255);
                        BoardVerticalRectMatrix[i][j].x = x;
                        BoardVerticalRectMatrix[i][j].y = y;
                        BoardVerticalRectMatrix[i][j].w = 20;
                        BoardVerticalRectMatrix[i][j].h = 90;
                        SDL_RenderFillRect(renderer, &BoardVerticalRectMatrix[i][j]);
                    }
                    break;
                    }
                }
            }
        }
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                switch (event.button.button)
                {
                case SDL_BUTTON_LEFT:
                {
                    x1 = event.button.x;
                    y1 = event.button.y;
                    detected1 = ClickPositionDetection(x1, y1);
                    printf("i1=%d j1=%d c1=%d v1=%d h1=%d \n", (*(detected1)), (*(detected1 + 1)), (*(detected1 + 2)), (*(detected1 + 3)), (*(detected1 + 4)));
                    break;
                }
                case SDL_BUTTON_RIGHT:
                {
                    x2 = event.button.x;
                    printf("x2=%d \n", x2);
                    y2 = event.button.y;
                    printf("y2=%d \n", y2);
                    detected2 = ClickPositionDetection(x2, y2);
                    int j1 = (*(detected1 + 1));
                    int j2 = (*(detected2 + 1));
                    int i1 = (*(detected1));
                    int i2 = (*(detected2));
                    if ((*(detected1 + 1)) != (*(detected2 + 1)) || (*(detected1)) != (*(detected2)))
                    {
                        // verticale to verticale

                        if ((*(detected1 + 3)) == 1 && (*(detected1 + 3)) == (*(detected2 + 3)) && (*(pVertPosition + 8 * i1 + j1)) != 0 && (*(pVertPosition + i2 * 8 + j2)) == 0)
                        {
                            printf("i2=%d j2=%d c2=%d v2=%d h2=%d \n", (*(detected2)), (*(detected2 + 1)), (*(detected2 + 2)), (*(detected2 + 3)), (*(detected2 + 4)));
                            Vert(pVertPosition, (*(detected1)), (*(detected1 + 1)), (*(detected2)), (*(detected2 + 1)));
                        }
                        // horizontale to horizontale

                        else if ((*(detected1 + 4)) == 1 && (*(detected1 + 4)) == (*(detected2 + 4)) && (*(pHorizPosition + 8 * i1 + j1)) != 0 && (*(pHorizPosition + i2 * 8 + j2)) == 0)
                        {
                            printf("i2=%d j2=%d c2=%d v2=%d h2=%d \n", (*(detected2)), (*(detected2 + 1)), (*(detected2 + 2)), (*(detected2 + 3)), (*(detected2 + 4)));
                            Horiz(pHorizPosition, (*(detected1)), (*(detected1 + 1)), (*(detected2)), (*(detected2 + 1)));

                        } // carre to carre

                        else if ((*(detected1 + 2)) == 1 && (*(detected1 + 2)) == (*(detected2 + 2)) && (*(pKingPosition + i1 * 7 + j1)) != 0 && (*(pKingPosition + i2 * 7 + j2)) == 0)
                        {
                            printf("i2=%d j2=%d c2=%d v2=%d h2=%d \n", (*(detected2)), (*(detected2 + 1)), (*(detected2 + 2)), (*(detected2 + 3)), (*(detected2 + 4)));
                            moveking(pKingPosition, (*(detected1)), (*(detected1 + 1)), (*(detected2)), (*(detected2 + 1)));
                        }
                        // verticale to horizontale

                        else if ((*(detected1 + 3)) == 1 && (*(detected1 + 3)) == (*(detected2 + 4)) && (*(pVertPosition + 8 * i1 + j1)) != 0 && (*(pHorizPosition + i2 * 8 + j2)) == 0)
                        {
                            VH(pVertPosition, pHorizPosition, (*(detected1)), (*(detected1 + 1)), (*(detected2)), (*(detected2 + 1)));
                        }
                        // horizontale to verticale

                        else if ((*(detected1 + 4)) == 1 && (*(detected1 + 4)) == (*(detected2 + 3)) && (*(pHorizPosition + 8 * i1 + j1)) != 0 && (*(pVertPosition + i2 * 8 + j2)) == 0)
                        {
                            HV(pVertPosition, pHorizPosition, (*(detected1)), (*(detected1 + 1)), (*(detected2)), (*(detected2 + 1)));
                        }
                    }
                    else
                    { // verticale to horizontale

                        if ((*(detected1 + 3)) == 1 && (*(detected1 + 3)) == (*(detected2 + 4)) && (*(pVertPosition + 8 * i1 + j1)) != 0 && (*(pHorizPosition + i2 * 8 + j2)) == 0)
                        {
                            VH(pVertPosition, pHorizPosition, (*(detected1)), (*(detected1 + 1)), (*(detected2)), (*(detected2 + 1))); // W  4  2  B  1  3
                        }
                        // horizontale to verticale
                        if ((*(detected1 + 4)) == 1 && (*(detected1 + 4)) == (*(detected2 + 3)) && (*(pHorizPosition + 8 * i1 + j1)) != 0 && (*(pVertPosition + i2 * 8 + j2)) == 0)
                        {
                            HV(pVertPosition, pHorizPosition, (*(detected1)), (*(detected1 + 1)), (*(detected2)), (*(detected2 + 1)));
                        }
                    }

                    if ((*(detected1 + 4)) == 1 && (*(detected1 + 4)) == (*(detected2 + 4)) && ((*(pHorizPosition + i1 * 8 + j1)) == 4 || (*(pHorizPosition + i1 * 8 + j1)) == 2) && ((*(pHorizPosition + 8 * i2 + j2)) != 4 && (*(pHorizPosition + 8 * i2 + j2)) != 2))
                    {
                        if (j1 == j2)
                        {
                            (*(pHorizPosition + i2 * 8 + j2)) = (*(pHorizPosition + 8 * i1 + j1));
                            (*(pHorizPosition + i1 * 8 + j1)) = 0;
                        }
                    }
                    if ((*(detected1 + 4)) == 1 && (*(detected1 + 4)) == (*(detected2 + 4)) && ((*(pHorizPosition + i1 * 8 + j1)) == 3 || (*(pHorizPosition + i1 * 8 + j1)) == 1) && ((*(pHorizPosition + 8 * i2 + j2)) != 3 && (*(pHorizPosition + 8 * i2 + j2)) != 1))
                    {
                        if (j1 == j2)
                        {
                            (*(pHorizPosition + i2 * 8 + j2)) = (*(pHorizPosition + 8 * i1 + j1));
                            (*(pHorizPosition + i1 * 8 + j1)) = 0;
                        }
                    }
                    if ((*(detected1 + 3)) == 1 && (*(detected1 + 3)) == (*(detected2 + 3)) && ((*(pVertPosition + i1 * 8 + j1)) == 4 || (*(pVertPosition + i1 * 8 + j1)) == 2) && ((*(pVertPosition + 8 * i2 + j2)) != 4 && (*(pVertPosition + 8 * i2 + j2)) != 2))
                    {
                        if (j1 == j2)
                        {
                            (*(pVertPosition + i2 * 8 + j2)) = (*(pVertPosition + 8 * i1 + j1));
                            (*(pVertPosition + i1 * 8 + j1)) = 0;
                        }
                    }
                    if ((*(detected1 + 3)) == 1 && (*(detected1 + 3)) == (*(detected2 + 3)) && ((*(pVertPosition + i1 * 8 + j1)) == 3 || (*(pVertPosition + i1 * 8 + j1)) == 1) && ((*(pVertPosition + 8 * i2 + j2)) != 3 && (*(pVertPosition + 8 * i2 + j2)) != 1))
                    {
                        if (j1 == j2)
                        {
                            (*(pVertPosition + i2 * 8 + j2)) = (*(pVertPosition + 8 * i1 + j1));
                            (*(pVertPosition + i1 * 8 + j1)) = 0;
                        }
                    }
                    if ((*(detected1 + 4)) == 1 && (*(detected1 + 4)) == (*(detected2 + 4)))
                    {
                        if (i1 == i2)
                        {
                            if (j1 < j2)
                            {
                                int bi = j1;
                                int bs = j2;
                                for (int j = bi + 1; j < bs; j++)
                                {
                                    (*(pHorizPosition + i1 * 8 + j)) = 0;
                                }
                            }
                            else if (j2 < j1)
                            {
                                int bi = j2;
                                int bs = j1;
                                for (int j = bi + 1; j < bs; j++)
                                {
                                    (*(pHorizPosition + i1 * 8 + j)) = 0;
                                }
                            }
                        }
                    }
                    else if ((*(detected1 + 3)) == 1 && (*(detected1 + 3)) == (*(detected2 + 3)))
                    {
                        if (i1 == i2)
                        {
                            if (j1 < j2)
                            {
                                int bi = j1;
                                int bs = j2;
                                for (int j = bi + 1; j < bs; j++)
                                {
                                    (*(pVertPosition + i1 * 8 + j)) = 0;
                                }
                            }
                            else if (j2 < j1)
                            {
                                int bi = j2;
                                int bs = j1;
                                for (int j = bi + 1; j < bs; j++)
                                {
                                    (*(pVertPosition + i1 * 8 + j)) = 0;
                                }
                            }
                        }
                    }
                }
                }
            }
        }
        piontodane(pHorizPosition);
        if (ismat(pKingPosition, pHorizPosition, pVertPosition) == 1)
        {
            running = 0;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                     "Black win",
                                     "",
                                     NULL);
        }
        else if (ismat(pKingPosition, pHorizPosition, pVertPosition) == -1)
        {
            running = 0;
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                     "White win",
                                     "",
                                     NULL);
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

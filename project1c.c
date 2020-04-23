#include <stdio.h>
#include <stdlib.h>
#include "project1c.h"

void initialisation(){
    char choice;
    title();
    printf("\nWelcome to Tetris\n\nEnter R if you want to read the rule\nEnter P if you want to play\n");
    do{
    scanf("%c",&choice);
        if( choice > 96)
        {
            choice -= 32;
        }
        if(choice != 80 && choice != 82)/*80 = P, 82  = R*/
        {
            printf("Incorrect input please try again\n");
        }
    }while(choice != 80 && choice != 82);
    if( choice == 82)
    {
        printf("Tetris is a game where the objective is to have the biggest score\nYour score begin at 0\nIn Order to gain point and to increase your score you will have to complete line and column of the board with block\n Each block has a different shape and when you run out of space to store your block on the board the game is over\nYou can't place a block in a place where there is already one and the block cannot be outside the board\nYou will have to choose between three different shape of board:\n    one triangular\n    one circular\n    one with a diamond shape\nEach shape of board has different shape of block to place\n The board will have a coordinate system with capital and regular letter, you will have to use them to place your block\nKeep in mind that in order to place a block you will have to enter the coordinate where you want to put the bottom left corner of the block\nWhen you will fill a column it'll increase your score and the column will become empty\nThe same thing will happen if you fill a line but the line above with also be shift toward the bottom\nYou'll to configure your parameter of the game This include the number of column of the board(the number of line will be based on your nulber of column)\nYou'll also have to choose if you want to be able to place every block possible in function of you shape of board or if you want to place only three random block\n\nThat all you need to know to play the game, don't worry the rest is pretty self explanatory\n\nNow the game will begin\n");
    }
}
void title(){
    printf("  _______ ______ _______ _____  _____  _____ \n |__   __|  ____|__   __|  __ \\|_   _|/ ____|\n    | |  | |__     | |  | |__) | | | | (___  \n    | |  |  __|    | |  |  _  /  | |  \\___ \\ \n    | |  | |____   | |  | | \\ \\ _| |_ ____) |\n    |_|  |______|  |_|  |_|  \\_\\_____|_____/ \n");

}
int ** create_2D_dyn(int line, int column){
    int **p;
    int i;
    p = (int **)malloc(line*sizeof(int*));
    for(i = 0; i < line; i ++)
    {
        p[i] = (int *)malloc(column*sizeof(int));
    }
    return p;
}
void display_board(int line, int column,int ** p,int score){
    int i , j;

    printf("\n\n\n   ");


    for(i = 0 ; i < column; i ++)
    {
        printf(" %c",i+97);
    }

    printf("\n  %c",201);

    for(i = 0 ; i < column*2; i ++)
    {
        printf("%c",205);
    }
    printf("%c%c\n",205,187);
    for(i = 0; i < line ; i ++)
    {
        printf("%c %c",i+65,186);
        for(j = 0 ; j < column ; j ++)
        {
                switch(p[i][j])
                {
                case 0:
                    printf(" %c",249);
                    break;
                case 1:
                    printf(" %c",254);
                    break;
                case 2:
                    printf("  ");
                    break;
                default:
                    printf("error in the board array: unrecognised value: %d\n",p[i][j]);
                    break;
                }

        }
        if(i == line/2)
        {
            printf(" %c            score: %d\n",186,score);
        }
        else
        {
        printf(" %c\n",186);
        }
    }
    printf("  %c",200);
    for(i = 0 ; i < column*2; i ++)
    {
        printf("%c",205);
    }
    printf("%c%c\n",205,188);


}
int ** fill_location_tab(int line , int column,int ** p, int i){
    switch(i)
    {
        default :
            printf("the index doesn't correspond to any block\n");
            break;
        case 0:
            p = create_block_A0(line,column);
            break;
        case 1:
            p = create_block_A1(line,column);
            break;
        case 2:
            p = create_block_A2(line,column);
            break;
        case 3:
            p = create_block_A3(line,column);
            break;
        case 4:
            p = create_block_A4(line,column);
            break;
        case 5:
            p = create_block_A5(line,column);
            break;
        case 6:
            p = create_block_A6(line,column);
            break;
        case 7:
            p = create_block_A7(line,column);
            break;
        case 8:
            p = create_block_A8(line,column);
            break;
        case 9:
            p = create_block_A9(line,column);
            break;
        case 10:
            p = create_block_A10(line,column);
            break;
        case 11:
            p = create_block_A11(line,column);
            break;
        case 12:
            p = create_block_A12(line,column);
            break;
        case 13:
            p = create_block_A13(line,column);
            break;
        case 14:
            p = create_block_A14(line,column);
            break;
        case 15:
            p = create_block_A15(line,column);
            break;
        case 16:
            p = create_block_A16(line,column);
            break;
        case 17:
            p = create_block_A17(line,column);
            break;
        case 18:
            p = create_block_A18(line,column);
            break;
        case 19:
            p = create_block_A19(line,column);
            break;
        case 20:
            p = create_block_C0(line,column);
            break;
        case 21:
            p = create_block_C1(line,column);
            break;
        case 22:
            p = create_block_C2(line,column);
            break;
        case 23:
            p = create_block_C3(line,column);
            break;
        case 24:
            p = create_block_C4(line,column);
            break;
        case 25:
            p = create_block_C5(line,column);
            break;
        case 26:
            p = create_block_C6(line,column);
            break;
        case 27:
            p = create_block_C7(line,column);
            break;
        case 28:
            p = create_block_C8(line,column);
            break;
        case 29:
            p = create_block_C9(line,column);
            break;
        case 30:
            p = create_block_C10(line,column);
            break;
        case 31:
            p = create_block_C11(line,column);
            break;
        case 32:
            p = create_block_D0(line,column);
            break;
        case 33:
            p = create_block_D1(line,column);
            break;
        case 34:
            p = create_block_D2(line,column);
            break;
        case 35:
            p = create_block_D3(line,column);
            break;
        case 36:
            p = create_block_D4(line,column);
            break;
        case 37:
            p = create_block_D5(line,column);
            break;
        case 38:
            p = create_block_D6(line,column);
            break;
        case 39:
            p = create_block_D7(line,column);
            break;
        case 40:
            p = create_block_D8(line,column);
            break;
        case 41:
            p = create_block_D9(line,column);
            break;
        case 42:
            p = create_block_D10(line,column);
            break;
        case 43:
            p = create_block_D11(line,column);
            break;
        case 44:
            p = create_block_D12(line,column);
            break;
        case 45:
            p = create_block_D13(line,column);
            break;
        case 46:
            p = create_block_T0(line,column);
            break;
        case 47:
            p = create_block_T1(line,column);
            break;
        case 48:
            p = create_block_T2(line,column);
            break;
        case 49:
            p = create_block_T3(line,column);
            break;
        case 50:
            p = create_block_T4(line,column);
            break;
        case 51:
            p = create_block_T5(line,column);
            break;
        case 52:
            p = create_block_T6(line,column);
            break;
        case 53:
            p = create_block_T7(line,column);
            break;
        case 54:
            p = create_block_T8(line,column);
            break;
        case 55:
            p = create_block_T9(line,column);
            break;
        case 56:
            p = create_block_T10(line,column);
            break;

            }
    return p;
}
void display_line_pretty(int Cell,int Max,int position){
    int i ,j;
    /*position; 0 -> up , 1 -> center , 2 -> bottom*/
    switch(position)
    {
        case 0:
            printf("%c",201);
            break;
        case 1:
            printf("%c",204);
            break;
        case 2:
            printf("%c",200);
            break;
        default:
            printf("error the position of the line isn't recognised\n");
            break;
    }
    for(i = 0 ; i < Max; i ++)
    {
        for(j = 0 ; j < Cell ; j ++)
        {
            printf("%c",205);
        }
        switch(position)
        {
            case 0:
                if(i < Max-1)
                {
                printf("%c",203);
                }
                else
                {
                    printf("%c\n",187);
                }
                break;
            case 1:
                if(i < Max-1)
                {
                    printf("%c",206);
                }
                else
                {
                    printf("%c\n",185);
                }
                break;
            case 2:
                if(i < Max-1)
                {
                printf("%c",202);
                }
                else
                {
                    printf("%c\n",188);
                }
                break;
            default:
                printf("error the position of the line isn't recognised\n");
                break;
        }
    }
}
void display_blocks(int line,int column, int * shape, int x){
    int ** c = create_2D_dyn(line+1,(column+2)*x);
    int ** block;
    int i,j,k,l,m,cell,row;
    cell = 12-(2*(column-3));
    row = x/cell+1;
    if(x < 10)
    {
        cell = x;
        row = 1;
    }
    for(i = 0 ;i < line+1 ;i ++)
    {
        for(j = 0 ; j < (column+2)*x ; j ++)
        {
            c[i][j] = -2;
        }
    }
    for(k = 0 ; k < x ; k ++)
    {
        block = fill_location_tab(line,column,block,shape[k]);
        for(i = 0 ; i < line ; i ++)
        {
            for(j = 0 ; j < column ; j ++)
            {
                c[i][j+k*(column+1)] = block[i][j] -2;
            }
        }
        c[0][(column+1)*k+column/2] = k;
    }
    display_line_pretty((column+1)*2,cell,0);
    printf("%c",186);
    for(l = 0 ; l < row ; l ++)
    {
        if(l!= 0)
        {
            display_line_pretty((column+1)*2,cell,1);
            printf("%c",186);
        }
        for(i = 0 ; i < line+1 ; i ++)
            {
                for(k = 0 ; k < cell ; k ++)
                {
                    for(j = 0 ; j < column+1 ; j ++)
                    {
                        if((l*cell+k) < x+1)
                        {

                            switch(c[i][j+(l*cell+k)*(column+1)])
                            {
                                case -2:
                                    printf("  ");
                                    break;
                                case -1:
                                    printf(" %c",254);
                                    break;
                                default:
                                    if("%d",c[i][j+(l*cell+k)*(column+1)] > 9)
                                    {
                                        printf("%d",c[i][j+(l*cell+k)*(column+1)]);
                                    }
                                    else
                                    {
                                        printf("%d ",c[i][j+(l*cell+k)*(column+1)]);
                                    }
                                    break;
                            }
                        }
                    }
                    if(l*cell+k <= x)
                    {
                        printf("%c",186);
                    }
                    else
                    {
                        for(m = 0 ; m < (column+1)*2; m ++)
                        {
                            printf(" ");
                        }
                        printf("%c",186);
                    }
                }
                if( i != line)
                {
                    printf("\n%c",186);
                }
                else
                {
                    printf("\n");
                }
            }
    }
    display_line_pretty((column+1)*2,cell,2);

}
int ** select_blocks(int line, int column,int i){
    int ** block = fill_location_tab(line,column,block,i);
    return block;
}
void free_2D(int line, int ** c){
    int i;
    for(i = 0 ; i < line ; i ++)
    {
        free(c[i]);
    }
    free(c);
}
int check_validity(int x, int y,int n,int m, int line,int column,int ** board,int ** block){
    int i,j,k;
    int ** pawn_coord = create_2D_dyn(n*m,2);
    k = 0;
    for(i = 0 ; i < n; i ++)
    {
        for(j = 0 ; j < m ; j ++)
        {
            if(block[i][j] == 1)
            {
                pawn_coord[k][0] = i;
                pawn_coord[k][1] = j;
                k ++;

            }
        }
    }
    for(i = 0 ; i < k ; i ++){
        if(y-n+pawn_coord[i][0] < 0 || x+pawn_coord[i][1] >= column )
        {
            free_2D(k,pawn_coord);
            return 0;
        }
        else
        {
            if(board[y-n+pawn_coord[i][0]][x+pawn_coord[i][1]] != 0)
            {
                free_2D(k,pawn_coord);
                return 0;
            }
        }
    }
    free_2D(n,pawn_coord);
    return 1;
}
void place_block(int x, int y , int n, int m , int ** board , int ** block){
    int i , j;
    for(i = 0 ; i < n ; i ++)
    {
        for(j = 0 ; j < m; j ++)
        {
            if(block[i][j] == 1)
            {
            board[y-n+i+1][x+j] = block[i][j];
            }
        }
    }
}
int state_line( int line , int Size,int ** board){
    int i;
    for(i = 0 ; i < Size; i ++)
    {
        if(board[line][i] == 0)
        {
            return 0;
        }
    }
    return 1;
}
int state_column( int column , int Size,int ** board){
    int i;
    for(i = 0 ; i < Size; i ++)
    {
        if(board[i][column] == 0)
        {
            return 0;
        }
    }
    return 1;
}
void eliminate_line(int line, int Size,int ** board ){
    int i;
    for ( i = 0 ; i < Size ; i++){
        if(board[line][i] != 2)
        {
            board[line][i] = 0;
        }
    }
}
void eliminate_column(int column, int Size,int ** board ){
    int i;
    for ( i = 0 ; i < Size ; i++){
        if(board[i][column] != 2)
        {
            board[i][column] = 0;
        }
    }
}

void Score(int * score){
    *score = *score + 1;
}
void state_board(int y_coord,int x_coord,int n,int m,int column,int line,int ** board,int * score){
    int i,j;
    j = 0;
    for(i = 0 ; i < n ; i ++)
    {
        if(y_coord-i+j >= 0)
        {
            if(state_line(y_coord-i,column,board) == 1)
            {
                printf("%c is full\n",y_coord-i+65);
                eliminate_line(y_coord-i,column,board);
                Score(score);
                shift_lines(y_coord,column,board);
                j++;
            }
        }
    }
    for(i = 0 ;i < m ; i ++)
    {
        if(x_coord+i < column)
        {
            if(state_column(x_coord+i,line,board) == 1)
            {
                printf("%c is full\n",x_coord+i+97);
                eliminate_column(x_coord+i,line,board);
                Score(score);


            }
        }
    }
}
void shift_lines(int y_coord, int column,int ** board){
    int i,j;
    for(i = y_coord; i > 0; i --)
    {
        for(j = 0 ; j < column ; j ++)
        {
            board[i][j] = board[i-1][j];
        }
    }
}
int ** create_block_B0(int line, int column){/*cercle*/
    int i,j;
    int ** p = create_2D_dyn(line,column);
    for( i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column; j ++)
        {

                if( (i+j < 4 && j < 4  ) || (j-i > column-5 && i < 5  ) || (i-j > line-5 && j < 4) || (i + j > line+column-6))
                {
                    p[i][j] = 2;
                }else{
                    p[i][j] = 0;
            }

        }

    }
    return p;

}
int ** create_block_B1(int line, int column){/*triangle*/
    int ** p = create_2D_dyn(line,column);
    int i,j;

    for( i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column; j ++)
        {
                if( (i+j <= column/2+2*i) && (j+i >= column/2))
                {
                    p[i][j] = 0;
                }else{
                    p[i][j] = 2;
            }
        }
    }
    return p;

}
int ** create_block_B2(int line, int column){/*diamond*/


    int ** p = create_2D_dyn(line,column);
    int i,j;
    for( i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column; j ++)
        {
                if( ((i+j <= column/2+2*i) && (j+i >= column/2) && (i <= line/2) ) || (  (j+1 > i-line/2 ) && (j+i+1 <= column+line/2) && (i > line/2) ) )
                {
                    p[i][j] = 0;
                }else{
                    p[i][j] = 2;
            }
        }
    }
    return p;
}

int ** create_block_A0(int line, int column){/*id: 0*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][0] = 1;
    p[line-1][0] = 1;
    p[line-1][1] = 1;
    return p;
}
int ** create_block_A1(int line, int column){/*id: 1*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][1] = 1;
    p[line-1][1] = 1;
    p[line-1][0] = 1;
    return p;
}
int ** create_block_A2(int line, int column){/*id: 2*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][0] = 1;
    p[line-1][0] = 1;
    p[line-1][1] = 1;
    p[line-1][2] = 1;
    return p;
}
int ** create_block_A3(int line, int column){/*id: 3*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-3][0] = 1;
    p[line-3][1] = 1;
    p[line-2][1] = 1;
    p[line-1][1] = 1;
    return p;
}
int ** create_block_A4(int line, int column){/*id: 4*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-3][0] = 1;
    p[line-2][0] = 1;
    p[line-1][0] = 1;
    p[line-2][1] = 1;
    return p;
}
int ** create_block_A5(int line, int column){/*id: 5*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-1][0] = 1;
    p[line-1][1] = 1;
    p[line-1][2] = 1;
    p[line-2][1] = 1;
    return p;
}
int ** create_block_A6(int line, int column){/*id: 6*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][0] = 1;
    p[line-2][1] = 1;
    p[line-1][1] = 1;
    p[line-1][2] = 1;
    return p;
}
int ** create_block_A7(int line, int column){/*id: 7*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-3][0] = 1;
    p[line-2][0] = 1;
    p[line-2][1] = 1;
    p[line-1][1] = 1;
    return p;
}
int ** create_block_A8(int line, int column){/*id: 8*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4 ;i ++)
    {
        p[line-i-1][0] = 1;
    }
    return p;
}
int ** create_block_A9(int line, int column){/*id: 9*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][0] = 1;
    p[line-2][1] = 1;
    p[line-1][1] = 1;
    p[line-1][0] = 1;

    return p;
}
int ** create_block_A10(int line, int column){/*id: 10*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-1][0] = 1;

    return p;
}
int ** create_block_A11(int line, int column){/*id: 11*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][0] = 1;
    p[line-2][1] = 1;
    p[line-1][0] = 1;

    return p;
}
int ** create_block_A12(int line, int column){/*id: 12*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][0] = 1;
    p[line-2][1] = 1;
    p[line-1][1] = 1;


    return p;
}
int ** create_block_A13(int line, int column){/*id: 13*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][2] = 1;
    p[line-1][0] = 1;
    p[line-1][1] = 1;
    p[line-1][2] = 1;

    return p;
}
int ** create_block_A14(int line, int column){/*id: 14*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-3][0] = 1;
    p[line-2][0] = 1;
    p[line-1][0] = 1;
    p[line-1][1] = 1;

    return p;
}
int ** create_block_A15(int line, int column){/*id: 15*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][0] = 1;
    p[line-3][1] = 1;
    p[line-2][1] = 1;
    p[line-1][1] = 1;

    return p;
}
int ** create_block_A16(int line, int column){/*id: 16*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][0] = 1;
    p[line-2][1] = 1;
    p[line-2][2] = 1;
    p[line-1][1] = 1;

    return p;
}
int ** create_block_A17(int line, int column){/*id: 17*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-1][0] = 1;
    p[line-1][1] = 1;
    p[line-2][1] = 1;
    p[line-2][2] = 1;

    return p;
}
int ** create_block_A18(int line, int column){/*id: 18*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    p[line-2][0] = 1;
    p[line-1][0] = 1;
    p[line-2][1] = 1;
    p[line-3][1] = 1;

    return p;
}
int ** create_block_A19(int line, int column){/*id: 19*/

    int ** p = create_2D_dyn(line,column);
    int i , j ;
    for(i = 0 ; i < line ;i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j] = 0;
        }
    }
    for(i = 0; i < 4 ; i ++)
    {
        p[line-1][i] = 1;
    }
    return p;
}

int ** create_block_C0(int line, int column){/*id: 20*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4; i ++)
    {
        for(j = 0 ; j < 4; j++)
        {
            p[line-i-1][j] = 1;
        }
    }
    return p;
}
int ** create_block_C1(int line, int column){/*id: 21*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4; i ++)
    {
        for(j = 0 ; j < 4; j++)
        {
            if( (i != 0 || j != 3) && (i != 3 || j != 3) && (i != 0 || j != 0) && (i != 3 || j != 0))
            {
            p[line-i-1][j] = 1;
            }
        }
    }
    return p;
}
int ** create_block_C2(int line, int column){/*id: 22*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4; i += 3)
    {
        for(j = 0 ; j < 4 ; j ++)
        {
            p[line-j-1][i] = 1;
        }
    }
    p[line-1][1] = 1;
    p[line-1][2] = 1;
    return p;
}
int ** create_block_C3(int line, int column){/*id: 23*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4 ; i ++)
    {
        p[line-4][i] =1;
    }
    for(i = 0 ; i < 3 ; i ++ )
    {
            p[line-1-i][3] = 1;
    }
    return p;
}
int ** create_block_C4(int line, int column){/*id: 24*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 2 ; i ++)
    {
        for(j = 0 ; j < 4 ; j ++)
        {
            if( i != 0 || j != 3)
            {
            p[line-i-1][j] = 1;
            }
        }
    }
    return p;
}
int ** create_block_C5(int line, int column){/*id: 25*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4 ; i ++)
    {
        for(j = 0 ; j < 3 ; j ++)
        {
            if( (i != 1 || j != 0) && (i != 1 || j != 1) && (i != 2 || j != 0) && (i != 2 || j != 1) )
            {
            p[line-i-1][j] = 1;
            }
        }
    }
    return p;
}
int ** create_block_C6(int line, int column){/*id: 26*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4 ; i ++)
    {
        for(j = 0 ; j < 2 ; j ++)
        {
            p[line-1-i][j] = 1;
        }
    }
    return p;
}
int ** create_block_C7(int line, int column){/*id: 27*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 2 ; i ++)
    {
        for(j = 0 ; j < 4 ; j ++)
        {
            p[line-1-i][j] = 1;
        }
    }
    return p;
}
int ** create_block_C8(int line, int column){/*id: 28*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4 ;i ++)
    {
        p[line-i-1][0] = 1;
    }
    return p;
}
int ** create_block_C9(int line, int column){/*id: 29*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for( i = 0 ; i < 5 ; i ++)
    {
        p[line-2][i] = 1;
    }
    p[line-1][0] = 1;
    p[line -1][4] = 1;

    return p;
}
int ** create_block_C10(int line, int column){/*id: 30*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }

    for(i = 0 ; i < 5 ; i ++)
    {
       p[line-1][i] = 1;
    }


    return p;
}
int ** create_block_C11(int line, int column){/*id: 31*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < 2 ; j ++)
        {
            p[i][j]= 0;
        }
    }

    for(i = 0 ; i < 3 ; i ++)
    {
     p[line-2-i][0] = 1;
    }

    for(i = 0; i < 4 ; i ++)
    {
        p[line-1][i] = 1;
    }

    p[line-2][3] = 1;
    return p;
}

int ** create_block_D0(int line, int column){/*id: 32*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(j = 0 ; j < 2 ; j ++)
    {
        for(i = 0 ; i < 3+j; i ++)
        {
            p[line-2+j-i][i] = 1;
        }
    }
    return p;
}
int ** create_block_D1(int line, int column){/*id: 33*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
   for(j = 0 ; j < 2; j ++)
    {
        for(i = 0 ; i < 3+j; i ++)
            {
                p[line-4+i][i+1-j] = 1;
            }
    }


    return p;
}
int ** create_block_D2(int line, int column){/*id: 34*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 1 ; i < 3; i ++ )
    {
        for(j = 0 ; j < 4 ; j ++)
        {
            p[line-j-1][i] = 1;
        }
    }
    p[line-4][0] = 1;
    p[line-4][3] = 1;
    return p;
}
int ** create_block_D3(int line, int column){/*id: 35*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(j = 0 ;j < 2 ; j ++)
    {
        for(i = 0 ; i < 3+j ; i ++)
        {
            p[line-3+i-j][i] =1;
        }
    }
    return p;
}
int ** create_block_D4(int line, int column){/*id: 36*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(j = 0 ; j < 2 ; j++)
    {
        for(i = 0 ; i < j+3 ; i ++)
        {
            p[line-1-i][i+1-j] = 1;
        }
    }
    return p;
}
int ** create_block_D5(int line, int column){/*id: 37*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 5 ; i ++)
    {
        p[line-1-i][0] = 1;
    }
    return p;
}
int ** create_block_D6(int line, int column){/*id: 38*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4 ; i ++)
    {
        p[line-1-i][0] = 1;
    }
    p[line-1][1] = 1;
    return p;
}
int ** create_block_D7(int line, int column){/*id: 39*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4 ; i ++)
    {
        p[line-2][i] = 1;
    }
    p[line-1][3] = 1;
    p[line-3][3] = 1;
    return p;
}
int ** create_block_D8(int line, int column){/*id: 40*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4 ;i ++)
    {
        p[line-2][i] = 1;
    }
    p[line-1][3] = 1;
    return p;
}
int ** create_block_D9(int line, int column){/*id: 41*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(j = 0 ; j < 2 ; j ++)
    {
        for( i = 0 ; i < 2 ; i ++)
        {
            p[line-2-j][1+i] = 1;
        }
    }
    p[line-1][0] = 1;
    p[line -1][3] = 1;
    p[line-4][0] = 1;
    p[line -4][3] = 1;
    return p;
}
int ** create_block_D10(int line, int column){/*id: 42*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }

    for(i = 0 ; i < 3 ; i ++)
    {
        for(j = 3-i ; j < i+4 ; j ++)
        {
            p[line-1-i][j-1] = 1;
        }
    }


    return p;
}
int ** create_block_D11(int line, int column){/*id: 43*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 4 ; i ++)
    {
        for(j = 0 ; j < 4 ; j ++)
        {
            p[line-1-i][j] = 1;
        }
    }


    return p;
}
int ** create_block_D12(int line, int column){/*id: 44*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }

    for(i = 0 ; i < 4 ; i ++)
    {
        p[line-i-1][1] = 1;
    }
    p[line-4][0] = 1;

    return p;
}
int ** create_block_D13(int line, int column){/*id: 45*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 5 ; i ++)
    {
        p[line-1][i] = 1;
    }

    return p;
}

int ** create_block_T0(int line, int column){/*id: 46*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(j = 0 ; j < 3 ; j ++)
    {
        p[line-2][j] = 1;
    }
    p[line-3][0] = 1;
    p[line-1][2] = 1;
    return p;
}
int ** create_block_T1(int line, int column){/*id: 47*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
   for(i = 0 ; i < 3; i ++)
    {
        p[line-1-i][1] = 1;
    }
    p[line-3][0] = 1;
    p[line-1][2] =1;


    return p;
}
int ** create_block_T2(int line, int column){/*id: 48*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 3; i ++ )
    {
        p[line-2][i] = 1;
    }
    p[line-1][0] = 1;
    p[line-3][2] = 1;
    return p;
}
int ** create_block_T3(int line, int column){/*id: 49*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(j = 0 ;j < 3 ; j ++)
    {
        p[line-j-1][1] =1;
    }
    p[line-1][0] = 1;
    p[line-3][2] = 1;
    return p;
}
int ** create_block_T4(int line, int column){/*id: 50*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(j = 0 ; j < 3 ; j++)
    {
        p[line-1-j][j] = 1;
    }
    return p;
}
int ** create_block_T5(int line, int column){/*id: 51*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 3 ; i ++)
    {
        p[line-3+i][i] = 1;
    }
    return p;
}
int ** create_block_T6(int line, int column){/*id: 52*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 3 ; i ++)
    {
        p[line-1-i][0] = 1;
    }
    return p;
}
int ** create_block_T7(int line, int column){/*id: 53*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 3 ; i ++)
    {
        p[line-1][i] = 1;
    }
    return p;
}
int ** create_block_T8(int line, int column){/*id: 54*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(i = 0 ; i < 2 ;i ++)
    {
        p[line-i-1][0] = 1;
    }

    return p;
}
int ** create_block_T9(int line, int column){/*id: 55*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }
    for(j = 0 ; j < 3 ; j ++)
    {
        for( i = 0 ; i < 3 ; i ++)
        {
            if( i == 1 || j == 1)
            {
                p[line-1-j][i] = 1;
            }
        }
    }

    return p;
}
int ** create_block_T10(int line, int column){/*id: 56*/
    int ** p = create_2D_dyn(line,column);
    int i,j;
    for(i = 0 ; i < line ; i ++)
    {
        for(j = 0 ; j < column ; j ++)
        {
            p[i][j]= 0;
        }
    }

    for(i = 0 ; i < 2 ; i ++)
    {
        p[line-1][i] = 1;
    }
    return p;
}

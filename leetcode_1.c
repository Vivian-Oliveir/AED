//There is a robot starting at the position (0, 0), the origin, on a 2D plane. 
//Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes 
//its moves.

//You are given a string moves that represents the move sequence of the robot where moves[i] 
//represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).

//Return true if the robot returns to the origin after it finishes all of its moves, or false 
//otherwise.

//Note: The way that the robot is "facing" is irrelevant. 'R' will always make the robot move 
//to the right once, 'L' will always make it move left, etc. Also, assume that the magnitude 
//of the robot's movement is the same for each move.

#include <stdio.h>
#include <stdbool.h>

bool judgeCircle(char* moves);

int main(){
    char moves[100];
    printf("Enter the move sequence of the robot (U/D/R/L): ");
    scanf("%[^\n]",moves);
    if(judgeCircle(moves)){
        printf("True.");
    }else{
        printf("False.");
    }

    return 0;
}

bool judgeCircle(char* moves) {
    int up=0, down=0, left=0, right=0, i=0;

    while(moves[i]!='\0'){
        if(moves[i]=='R'){
            right++;
        }else if(moves[i]=='L'){
            left++;
        }else if(moves[i]=='U'){
            up++;
        }else if(moves[i]=='D'){
            down++;
        }
        i++;
    }

    if(right==left && up==down){
        return true;
    }else{
        return false;
    }
}
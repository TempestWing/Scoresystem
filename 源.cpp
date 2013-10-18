#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define MAX 200
int size = 0 ;
using namespace std ;

struct
{
    char name[10] ;
    int     id ;
    int     sex ;
    int score ;
}stu[MAX];

void  list();
void addclass();
void delclass();
void getScore();

int main()
{
    int action , f = 0 ;
    while(1)
    {
        cout << "Enter your Action( 1 ~ 5): " ;
        cin >> action ;
        switch( action )
        {
            case 1 : list() ;   break ;
            case 2 : addclass() ;    break ;
            case 3 : delclass() ;    break ;
            case 4 : getScore() ;   break ;
            case 5 :  f = 1 ;break ;
        }
        if(f) break;
    }
    return 0 ;
}


void  list()
{
    int i = 0 ;
    if( size == 0 ) { cout << "error :no student !" ; exit(EXIT_FAILURE);}
    printf( "NAME       ID      SEX     SCORE\n") ;
    while( i < size )
    {
        printf("%7s    %3d     %3d     %d\n",stu[i].name , stu[i].id , stu[i].sex , stu[i].score ) ;
        i++;
    }
}

void addclass()
{
    int i = size ;
    cout << "student's name:" ;
    cin >> stu[i].name ;
    cout << "\nstudent's id:" ;
    cin >> stu[i].id ;
    cout << "student's sex:" ;
    cin >> stu[i].sex ;
    cout << "student's score:" ;
    cin >> stu[i].score ;
    size++ ;
    cout << "SUCCESS!\n" ;
}

void delclass()
{
    int i  , yid ,f=0;
    cout << "Enter your id:"<<endl ;
    cin >> yid ;
    for(  i = 0 ; i < size ;i++)
        if( stu[i].id == yid )
            {f = 1 ;break ;}
    if(!f) {cout << "your id is wrong" ; exit(EXIT_FAILURE);}
    if( i < size-1 )
        for( int j = i+1 ; j < size ; j++ ) { stu[i] = stu[j] ;}
    size-- ;
}

void getScore()
{
    int wid ,sco;
    char ask ;
    while(1)
    {
        cout << "which id to start?";
        cin >> wid ;
        cout << "score is :" ;
        cin >> sco ;
        stu[wid-1].score = sco ;
        cout << "\nnext? y or n\n" ;
        cin >> ask ;
        if(ask== 'n') break ;
    }

}




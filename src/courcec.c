#include <stdio.h>
#include <stdlib.h>

int main()
{

  //this is just a test cuz im learning C, later C++
    /*first
    char character[] = "adrian";
    char letter = 'F';
    const int characteage = 14;
    double charactexactage = 14.7;

    int aa = 12;
    char hi[] = "";
    printf("Hellonon %s, u are %d years old :\n", character, characteage); // jijijijij 

    printf("or u are %f years old?\n", charactexactage);

    printf("enter a shit: ");
 
    fgets(hi, 30, stdin);

    //scanf("%s", $hi);

     return printf("your shit is: %s", hi);

    */

   /*calculator
   double num1;
   double num2;
   char op;

  

   printf("enter number: ");
   scanf("%lf", &num1);
   printf("enter numerator (/,+,*,-): ");
   scanf(" %c", &op);
   printf("enter another number: ");
   scanf("%lf", &num2);
   
   if(op == '+'){
        printf("answer: %f", num1 + num2);
   }else if(op == '/'){
     printf("answer: %f", num1 / num2);
   }
   else if(op == '-'){
     printf("answer: %f", num1 - num2);
   }else if(op == '*'){
     printf("answer: %f", num1 * num2);
   }else{
    printf("invalid operator");
   }*/

   /*switch

   char grade = 'a';
printf("tpe a letter: ");
   scanf(" %c", &grade);

 switch (grade)
 {
case 'a':
    printf("fuck u");
    break;
case 'b':
    printf("yeah");
    break;
case 'c':
    printf("meh");
    break;
case 'd':
    printf("bruh");
    break;
    case 'e':
    printf("huhbruhhuh");
    break;
    case 'f':
    printf("u r a noob");
    break;
   
   
   default:
   printf("dont be a fukin idiot and type the corerct wordd");
    break;
   }*/

   /*ostest

char grade = "";

    printf("+------------------------------------------------------------------------------+\n");
	  printf("|  Welcome to KolarOS Coralriff                                                |\n");
	  printf("|                                                                              |\n");
    printf("|  Version Alpha 0.0.29 - Build 03062023                                       |\n");
    printf("|  Codename 'ASM Edition'                                                      |\n");
	  printf("|  (C)2023 The Kolar Project Organization. All rights reserved.                |\n");
	  printf("|  This is a alpha version, you should be aware of the errors.                 |\n");
    printf("|                                                                              |\n");
	  printf("|  CHANGELOG: (GreenSoupDev)                                                   |\n");
	  printf("|  idk what to do, im learnin, well im going to decorate this message thingie  |\n");
	  printf("|  and hello there fella.                                                      |\n");
    printf("+------------------------------------------------------------------------------+\n");
    printf("\n");
    printf("[CALL] Calling 'ReadDisk' sector...\n");
    printf("[OK] 'ReadDisk' Sector successfully called\n");
	
scanf("Exit %c", &grade);*/

/*install*/

char ver[] = "0.0.28";
char os[] = "KolarOS Coralriff";
char q1 = "";


  printf("%s - %s Setup\n\n",&os, &ver);   

  printf("You want to install %s - %s? (Y/N): ", &os, &ver);  
  scanf(" %c", &q1); 

  switch (q1)
  {
  case 'y':
  printf("Installing %s - %s...", &os, &ver);  
    break;

    case 'n':
  printf("Ok");  
    break;
  
  default:
  printf("Invalid command, please try again");  
    break;
  }


   




    

    

    return 0;
}

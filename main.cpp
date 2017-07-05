#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
int ucgen(int x1,int y1,int x2,int y2,int x3,int y3)
{

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x1,y1,x3,y3);

    return 1;
}
main()

{
 DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN); //ekran genisligi
 DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN); //ekran yuksekligi
 initwindow(screenWidth, screenHeight, "SelinEsra",0,0); //blgisayarin ekrani boyutunda cizim penceresi acar
setactivepage(0); //yeni sayfanin degeri icin aktif sayfayi ayarla ***************
 setbkcolor(WHITE);
 cleardevice();

 POINT cursorPosition;
 int mX,mY;
 int num;
 int selected=0;
setcolor(BLACK);
 int basx,basy;
 BYTE keyState[256];

     printf("\n\n");
     printf("PAINT UYGULAMAMIZA HOSGELDINIZ... \n\n");
     printf("Ilk olarak kalemin rengini seciniz : \n\n");
     printf("Siyah renk kalem icin : 5 e basiniz. \n");
     printf("Mavi renk kalem icin :  6 ya basiniz. \n");
     printf("Kirmizi renk kalem icin :  7 ye basiniz. \n");
     printf("Yesil renk kalem icin :   8 e basiniz. \n");
     printf("Sari renk kalem icin : 9 a basiniz. \n\n\n");
     printf("Kalemi kullanmak icin : 0 a basiniz. \n");
     printf("Duz cizgi icin : 1 e basiniz. \n");
     printf("Dikdortgen icin : 2 ye basiniz. \n" );
     printf("Daire icin : 3 e basiniz. \n");
     printf("Ucgen icin : 4 e basiniz. \n\n\n");
     printf("Dosyayi kaydetmek icin S ' e basiniz. \n");
     printf("Dosyayi okumak icin R ' e basiniz. \n\n");
     printf("PROGRAMIMIZI KULLANDIGINIZ ICIN TESEKKUR EDERIZ...\n\n");


 while(1)
 {

 if(GetAsyncKeyState(48)){
        selected = 0;
       }
        if(GetAsyncKeyState(49)){
        selected = 1;
       }

       if(GetAsyncKeyState(50)){
        selected = 2;
       }

       if(GetAsyncKeyState(51)){
        selected = 3;
       }

      if(GetAsyncKeyState(52)){
        selected = 4;
       }

        if(GetAsyncKeyState(53)){
        setfillstyle(SOLID_FILL,BLACK);
        setcolor(BLACK);
       }

       if(GetAsyncKeyState(54)){
         setfillstyle(SOLID_FILL,BLUE);
         setcolor(BLUE);
       }

      if(GetAsyncKeyState(55)){
        setfillstyle(SOLID_FILL,RED); //dolgu desenini ve dolgu rengini ayarlar
        setcolor(RED);
       }
        if(GetAsyncKeyState(56)){
        setfillstyle(SOLID_FILL,GREEN);
        setcolor(GREEN);
       }
        if(GetAsyncKeyState(57)){
        setfillstyle(SOLID_FILL,YELLOW);
        setcolor(YELLOW);
       }

       if(GetAsyncKeyState(83) || GetAsyncKeyState(115)){ // S veya kucuk s basıldı ise
        writeimagefile(NULL,0,0,screenWidth,screenHeight);
       }

       if(GetAsyncKeyState(82) || GetAsyncKeyState(114)){ // R veya kucuk r basıldı ise
       readimagefile(NULL,0,0,screenWidth,screenHeight);
       }


      GetCursorPos(&cursorPosition);
      mX = cursorPosition.x;
      mY = cursorPosition.y;


          if(GetAsyncKeyState(VK_LBUTTON)&&selected==0) //kalem
          bar(mX,mY,mX+5,mY+5);
        //fare imleci hassasiyeti


        if(ismouseclick(WM_LBUTTONDOWN)&&selected==1) //duzcizgi
        {
            basx = mousex();
            basy = mousey();
           clearmouseclick(WM_LBUTTONDOWN);
        }

         if(ismouseclick(WM_LBUTTONUP)&&selected==1  )
            {
                line(basx,basy,mousex(),mousey());
                clearmouseclick(WM_LBUTTONUP);

            }


        if(ismouseclick(WM_LBUTTONDOWN)&&selected==2) //dikdortgen
        {

            basx = mousex();
            basy = mousey();
           clearmouseclick(WM_LBUTTONDOWN); //hafizadaki mouse tiklamalarini icinde aldigi parametreye gore temizler
        }


         if(ismouseclick(WM_LBUTTONUP)&&selected==2  )
            {
                rectangle(basx,basy,mousex(),mousey());
                clearmouseclick(WM_LBUTTONUP);

            }

             if(ismouseclick(WM_LBUTTONDOWN)&&selected==3) //daire
        {

            basx = mousex();
            basy = mousey();
           clearmouseclick(WM_LBUTTONDOWN);
        }


         if(ismouseclick(WM_LBUTTONUP)&&selected==3  )
            {

                int yaricap = basx-mousex();
                if(yaricap<0)
                    yaricap = yaricap*-1;

               circle(mousex(),mousey(),yaricap);
                clearmouseclick(WM_LBUTTONUP);

            }


             if(ismouseclick(WM_LBUTTONDOWN)&&selected==4) //ucgen
        {

            basx = mousex();
            basy = mousey();
           clearmouseclick(WM_LBUTTONDOWN);
        }


         if(ismouseclick(WM_LBUTTONUP)&&selected==4)
            {

                 double h;
                 h = sqrt(pow((mX-basx),2.0)+pow((mY-basy),2.0));
              line(mX,mY-24,(basx-((h/(pow(3.0,(0.5)))))),basy);
              line(mX,mY-24,(basx+((h/(pow(3.0,(0.5)))))),basy);
              line((basx-((h/(pow(3.0,(0.5)))))),basy,(basx+((h/(pow(3.0,(0.5)))))),basy);

              clearmouseclick(WM_LBUTTONUP);

            }


 }
 getch();
 closegraph();


}


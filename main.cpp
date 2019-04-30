/// FCI – Programming 1 – 2018 - Assignment 3
/// Program Name: Bouns
/// Last Modification Date: 13/4/2018
/// Author1 and ID and Group: Muhammad Bakr Abdel Hafez / 20170224 / G9
/// Author2 and ID and Group: Muhammad Abdel Fattah / 20170242 / G9
/// Author3 and ID and Group: Muhammad Ashraf Badwy Moussa / 20170219 / G9
/// Teaching Assistant: Eng. Khadiga Khaled and Eng. Omar Khaled
/// Purpose:..........
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][3];
unsigned char image2[SIZE][SIZE][3];
unsigned char new_image[SIZE][SIZE][3];
unsigned char Large_image[SIZE][SIZE][3];
int x=SIZE-1;
void BW_image();
void Invert_image ();
void Merge_images();
void Filp_image();
void Rotate_image();
void DL_image();
void Detec_image();
void Enlarge_image();
void Shrink_image();


int main()
{
    char imageFileName[80] , imageFileName1[80] , imageFileName2[80];
    cout<<"Ahlan ya user ya habibi.\n";
    cout << "Please enter file name of the image to process:";
    cin >> imageFileName;
    readRGBBMP(imageFileName,image);
    while (true)
    {
        cout<<endl;
        cout<<"Please select a filter to apply or 0 to exit :\n"
            <<"1- Black & White Filter.\n"
            <<"2- Invert Filter.\n"
            <<"3- Merge Filter.\n"
            <<"4- Flip Image.\n"
            <<"5- Rotate Image.\n"
            <<"6- Darken and Lighten Image.\n"
            <<"7- Detect Image Edges.\n"
            <<"8- Enlarge Image.\n"
            <<"9- Shrink Image.\n"
            <<"s- Save the image to a file.\n"
            <<"0- Exit.\n";
        char choice;
        cout<<">>> ";
        cin>>choice;
        if (choice=='1')
        {
            BW_image();
        }
        else if (choice=='2')
        {
            Invert_image();
        }
        else if (choice=='3')
        {
            cout << "Please enter file name of the second image : ";
            cin >> imageFileName2;
            readRGBBMP(imageFileName2,image2);
            Merge_images();
        }
        else if (choice=='4')
        {
            Filp_image();
        }
        else if (choice=='5')
        {
            int num;
            cout<<"1-Rotate 90.\n"
                <<"2-Rotate 180.\n"
                <<"3-Rotate 270.\n";
            cout<<">>> ";
            cin>>num;
            if (num==1)
            {
                Rotate_image();
            }
            else if (num==2)
            {
                Rotate_image();
                Rotate_image();
            }
            else if (num==3)
            {
                Rotate_image();
                Rotate_image();
                Rotate_image();
            }
        }
        else if (choice=='6')
        {
            DL_image();
        }
        else if (choice=='7')
        {
            Detec_image();
        }
        else if (choice=='8')
        {
            Enlarge_image();
        }
        else if (choice=='9')
        {
            Shrink_image();
        }
        else if (choice=='0')
            break;
        else if (choice=='s' || choice=='S')
        {
            cout << "Enter the target image file name: ";
            cin >> imageFileName1;
            writeRGBBMP(imageFileName1,image);

        }
        else
            cout<<"Please enter a right number.\n";
    }
    return 0;
}


void BW_image()
{
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            if ((image[i][j][0]+image[i][j][1]+image[i][j][2])/3 > 127)
            {
                image[i][j][0]=255;
                image[i][j][1]=255;
                image[i][j][2]=255;
            }
            else
            {
                image[i][j][0]=0;
                image[i][j][1]=0;
                image[i][j][2]=0;
            }
        }
    }
}



void Invert_image()
{
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            image[i][j][0]=255-image[i][j][0];
            image[i][j][1]=255-image[i][j][1];
            image[i][j][2]=255-image[i][j][2];

        }
    }
}




void Merge_images()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j][2]=(image[i][j][2] + image2[i][j][2])/2;
            image[i][j][1]=(image[i][j][1] + image2[i][j][1])/2;
            image[i][j][0]=(image[i][j][0] + image2[i][j][0])/2;
        }
    }
}

void Filp_image()
{
    int choice;
    cout<<"1-Horizontal.\n"
        <<"2-Vertical.\n"
        <<">>> ";
    cin>>choice;
    if (choice==2)
    {
        for (int i=0; i<SIZE; i++)
        {
            for (int j=0; j<SIZE; j++)
            {
                new_image[i][j][0]=image[255-i][j][0];
                new_image[i][j][1]=image[255-i][j][1];
                new_image[i][j][2]=image[255-i][j][2];
            }
        }
    }
    else if (choice==1)
    {
         for (int i=0; i<SIZE; i++)
        {
            for (int j=0; j<SIZE; j++)
            {
                new_image[i][j][0]=image[i][255-j][0];
                new_image[i][j][1]=image[i][255-j][1];
                new_image[i][j][2]=image[i][255-j][2];
            }
        }
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE; j++)
        {
            image[i][j][0]=new_image[i][j][0];
            image[i][j][1]=new_image[i][j][1];
            image[i][j][2]=new_image[i][j][2];
        }
    }
}



void  Rotate_image()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            new_image[i][j][0]=image[j][x][0];
            new_image[i][j][1]=image[j][x][1];
            new_image[i][j][2]=image[j][x][2];
        }
        x--;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            image[i][j][0]=new_image[i][j][0];
            image[i][j][1]=new_image[i][j][1];
            image[i][j][2]=new_image[i][j][2];
        }
    }
}




void DL_image()
{
    int num;
    cout <<"1-Darken Image.\n"
         <<"2-Lighten Image.\n"
         <<">>> ";
    cin >> num;
    if (num==1)
    {
        for (int i = 0 ; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE ; j++)
            {
                image[i][j][0]/=2;
                image[i][j][1]/=2;
                image[i][j][2]/=2;
            }
        }
    }
    else if (num==2)
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE ; j++)
            {
                int Index_Red=image[i][j][0] + 0.5*image[i][j][0];
                int Index_Green=image[i][j][1] + 0.5*image[i][j][1];
                int Index_Blue=image[i][j][2] + 0.5*image[i][j][2];
                if ( Index_Red > 255)
                {
                    Index_Red=255;
                }
                if ( Index_Green > 255)
                {
                    Index_Green=255;
                }
                if ( Index_Blue > 255)
                {
                    Index_Blue=255;
                }
                image[i][j][0] = Index_Red ;
                image[i][j][1] = Index_Green ;
                image[i][j][2] = Index_Blue ;
            }
        }
    }
}



void Detec_image()
{
    BW_image();
    for (int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            if (image[i][j][0]==0 && image[i][j][1]==0 && image[i][j][2]==0)
            {
                if (image[i][j-1][0]==0 && image[i-1][j-1][0]==0 && image[i-1][j][0]==0 && image[i-1][j+1][0]==0 && image[i][j+1][0]==0 && image[i+1][j+1][0]==0 && image[i+1][j][0]==0 && image[i+1][j-1][0]==0)
                {
                    if(image[i][j-1][1]==0 && image[i-1][j-1][1]==0 && image[i-1][j][1]==0 && image[i-1][j+1][1]==0 && image[i][j+1][1]==0 && image[i+1][j+1][1]==0 && image[i+1][j][1]==0 && image[i+1][j-1][1]==0)
                    {
                        if(image[i][j-1][2]==0 && image[i-1][j-1][2]==0 && image[i-1][j][2]==0 && image[i-1][j+1][2]==0 && image[i][j+1][2]==0 && image[i+1][j+1][2]==0 && image[i+1][j][2]==0 && image[i+1][j-1][2]==0)
                        {
                            new_image[i][j][0]=1;
                            new_image[i][j][1]=1;
                            new_image[i][j][2]=1;
                        }
                    }
                }
            }
        }
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE; j++)
        {
            if(new_image[i][j][0]==1 && new_image[i][j][1]==1 && new_image[i][j][2]==1)
            {

                image[i][j][0]=255;
                image[i][j][1]=255;
                image[i][j][2]=255;

            }
        }
    }
}


void Enlarge_image()
{
    int  choice;
    cout<<"1-First quarter.\n"
        <<"2-Second quarter.\n"
        <<"3-Third quarter.\n"
        <<"4-Forth quarter.\n"
        <<">>> ";
    cin >> choice;
    if(choice==1)
    {
        int num1=0 , num2=0 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i][j][0]=image[num1][num2][0];
                Large_image[i+1][j][0]=image[num1][num2][0];
                Large_image[i][j+1][0]=image[num1][num2][0];
                Large_image[i+1][j+1][0]=image[num1][num2][0];

                Large_image[i][j][1]=image[num1][num2][1];
                Large_image[i+1][j][1]=image[num1][num2][1];
                Large_image[i][j+1][1]=image[num1][num2][1];
                Large_image[i+1][j+1][1]=image[num1][num2][1];

                Large_image[i][j][2]=image[num1][num2][2];
                Large_image[i+1][j][2]=image[num1][num2][2];
                Large_image[i][j+1][2]=image[num1][num2][2];
                Large_image[i+1][j+1][2]=image[num1][num2][2];
                num2++;
            }
            num2=0;
            num1++;
        }
    }
    else if (choice==2)
    {
        int num1=0 , num2=SIZE/2 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i+1][j][0]=image[num1][num2][0];
                Large_image[i][j+1][0]=image[num1][num2][0];
                Large_image[i+1][j+1][0]=image[num1][num2][0];

                Large_image[i][j][1]=image[num1][num2][1];
                Large_image[i+1][j][1]=image[num1][num2][1];
                Large_image[i][j+1][1]=image[num1][num2][1];
                Large_image[i+1][j+1][1]=image[num1][num2][1];

                Large_image[i][j][2]=image[num1][num2][2];
                Large_image[i+1][j][2]=image[num1][num2][2];
                Large_image[i][j+1][2]=image[num1][num2][2];
                Large_image[i+1][j+1][2]=image[num1][num2][2];
                num2++;
            }
            num2=SIZE/2;
            num1++;
        }
    }
    else if (choice==3)
    {
        int num1=SIZE/2 , num2=0 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i+1][j][0]=image[num1][num2][0];
                Large_image[i][j+1][0]=image[num1][num2][0];
                Large_image[i+1][j+1][0]=image[num1][num2][0];

                Large_image[i][j][1]=image[num1][num2][1];
                Large_image[i+1][j][1]=image[num1][num2][1];
                Large_image[i][j+1][1]=image[num1][num2][1];
                Large_image[i+1][j+1][1]=image[num1][num2][1];

                Large_image[i][j][2]=image[num1][num2][2];
                Large_image[i+1][j][2]=image[num1][num2][2];
                Large_image[i][j+1][2]=image[num1][num2][2];
                Large_image[i+1][j+1][2]=image[num1][num2][2];
                num2++;
            }
            num2=0;
            num1++;
        }
    }
    else if (choice==4)
    {
        int num1=SIZE/2 , num2=SIZE/2 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i+1][j][0]=image[num1][num2][0];
                Large_image[i][j+1][0]=image[num1][num2][0];
                Large_image[i+1][j+1][0]=image[num1][num2][0];

                Large_image[i][j][1]=image[num1][num2][1];
                Large_image[i+1][j][1]=image[num1][num2][1];
                Large_image[i][j+1][1]=image[num1][num2][1];
                Large_image[i+1][j+1][1]=image[num1][num2][1];

                Large_image[i][j][2]=image[num1][num2][2];
                Large_image[i+1][j][2]=image[num1][num2][2];
                Large_image[i][j+1][2]=image[num1][num2][2];
                Large_image[i+1][j+1][2]=image[num1][num2][2];
                num2++;
            }
            num2=SIZE/2;
            num1++;
        }
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE; j++)
        {
            image[i][j][0]=Large_image[i][j][0];
            image[i][j][1]=Large_image[i][j][1];
            image[i][j][2]=Large_image[i][j][2];
        }
    }
}




void Shrink_image()
{
    int choice , num;
    cout<<"1-shrink the image dimensions to 1/2 the original dimensions.\n"
        <<"2-shrink the image dimensions to 1/3 the original dimensions.\n"
        <<"3-shrink the image dimensions to 1/4 the original dimensions.\n"
        <<">>> ";
    cin>>choice;
    if(choice==1)
        num=2;
    else if (choice==2)
        num=3;
    else if(choice==3)
        num=4;
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            new_image[i/num][j/num][0]=image[i][j][0];
            new_image[i/num][j/num][1]=image[i][j][1];
            new_image[i/num][j/num][2]=image[i][j][2];
        }
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
            image[i][j][0]=new_image[i][j][0];
            image[i][j][1]=new_image[i][j][1];
            image[i][j][2]=new_image[i][j][2];
        }
    }
}

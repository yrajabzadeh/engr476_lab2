//engr 476 lab 2
//yousef rajabzadeh
//916371162

#include<stdio.h>
#include<conio.h>
struct HDLC
{
    char validinput[64]; //store valid inputs
};

void displayinfo(struct HDLC fa_HDLC,int fc)
{
    int i=1;
    printf("\n the end of the flag detected.");
    printf("\n the information sent was:\n");
    for(i;i<fc;i++)
    {
        printf("%c",fa_HDLC.validinput[i]);
    }
}

main()
{
    struct HDLC a_HDLC;
    char ip;
    int flag=0; //for detecting two flags,if flag=1 first flag detected , flag=2 second flag detected.
    int c=1; //counts number of characters
    int j=0; // to track flag state
    printf("this program exists upon entering'!'\n");
    while(ip !='!' && flag !=2 && c<64)
    {
        if(j==0) // check if part of flag detected or not
        {
            ip=getche();
        }
        if(ip=='0')
        {
            ip=getche(); //state1 detected.
            j++;
            if(ip=='1')
            {
                ip=getche(); //state2 detected.
                j++;
                if(ip=='1')
                {
                    ip=getche();//state3 detected.
                    j++;
                    if(ip=='1')
                    {
                        ip=getche();//state4 detected.
                        j++;
                        if(ip=='1')
                        {
                            ip=getche();//state 5 detected.
                            j++;
                            if(ip=='1')
                            {
                                ip=getche();//state6 detected.
                                j++;
                                if(ip=='1')
                                {
                                    ip=getche();//state7 detected.
                                    j++;
                                    if(ip=='0')
                                    {//state8 detected.
                                        if(flag==0)
                                        {
                                            printf("\n the flag has been detected\n\n");
                                        }
                                        j=0;
                                        flag++;
                                        ip=' '; //after flag buffer clearing
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(flag==1)
        {
            a_HDLC.validinput[c]=ip;
            c++;
        }
    }
    if(ip=='!')
    {
        printf("\nthe exit command was used");
    }
    else
    {
        displayinfo(a_HDLC,c);
    }
}
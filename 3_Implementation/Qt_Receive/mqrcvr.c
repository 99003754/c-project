#include"receiver.h"

int16_t receieve_message()
//int main()
{
    int ret,nbytes;
    struct mq_attr attr;
    attr.mq_msgsize=256;
    attr.mq_maxmsg=10;
    mqd_t mqid;
    mqid=mq_open("/mque",O_RDONLY|O_CREAT,0666,&attr);
    if(mqid<0)
    {
        perror("mq_open");
        exit(1);
    }
    char buf[8192];
    int maxlen=256,prio;
    nbytes=mq_receive(mqid,buf,maxlen,&prio);
    int i;
    int lent=strlen(buf);
    //printf("receive msg:%s,nbytes=%d,prio=%d\n",buf,nbytes,prio);
    /*int8_t answer=atoi(buf);
    printf("sdfvsdgsdsdg %d\n",answer);

    */
    //printf("string is %s \n",buf);

//char a[100]="11111111";
int k;
int sums=0;
int n_c=15;
for(k=0;k<16;k++)
{
    //printf("%c \n",buf[k]);
if(buf[k]==48) //0
{
sums+= 0;
//printf("in 0 %d\n",sums);
}
else
{
sums+= 1*pow(2,n_c);
//printf("in 1 %d \n",sums);
}
n_c--;
}
//printf("value is %d\n",sums);
//printf("sums is \n",sums)
int16_t answer=sums;




    if(nbytes<0)
    {
        perror("mq_recv");
        exit(2);
    }
    buf[nbytes]='\0';

    //write(1,buf,nbytes);
    mq_close(mqid);
    return answer;

}
void send_message(char no[100] )
{
    //printf("reached in mqsender too\n");
    //printf("char is %s \n",no);
    int ret;
    mqd_t mqid1;
    struct mq_attr attr;
    attr.mq_msgsize=256;
    attr.mq_maxmsg=10;
    mqid1=mq_open("/mque1",O_WRONLY|O_CREAT,0666,&attr);
    //mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,NULL);
    if(mqid1<0)
    {
        perror("mq_open");
        exit(1);
    }
    char str[]="Hello Message queue";
    int len=strlen(no);
    printf("her here herherehrhebrherh %s",no);
    ret=mq_send(mqid1,no,len+1,5);
    if(ret<0)
    {
        perror("mq_send");
        exit(2);
    }
//#if 1
    /*char str1[]="Message with pri =10";
    len=strlen(str1);
    ret=mq_send(mqid,str1,len,10);
    if(ret<0)
    {
        perror("mq_send");
        exit(2);
    }
    */
    //#endif
    mq_close(mqid1);

}

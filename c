										CN
						1
(i)Character Stuffing

#include<stdio.h>
#include<string.h>
#define FLAG '$'
#define ESC '&'
void charStuff(char data[])
{
        char stuff[100];
        int i, j=0;
        stuff[j++]=FLAG;
        for (i=0;i<strlen(data);i++)
        {
                if(data[i]==FLAG || data[i]==ESC )
                {
                        stuff[j++]=ESC;
                }
                stuff[j++]=data[i];
        }
        stuff[j++]=FLAG;
        stuff[j]='\0';
        printf("Stuffed Frsme: %s\n", stuff);
}
void main()
{
        char data[100];
        printf("Enter Input data(eg:ABCD):");
        scanf("%s", data);
        charStuff(data);
}

(ii)Bit Stuffing

#include<stdio.h>
#include<string.h>
void bitStuffing(char data[])
{
        char stuffed[100];
        int i, j, count=0;
        for(i=0;i<strlen(data);i++)
        {
                stuffed[j++]=data[i];
                if(data[i]=='1')
                {
                        count++;
                        if(count==5)
                        {
                                stuffed[j++]='0';
                                count=0;
                        }
                }
                else
                {
                        count=0;
                }
        }
        stuffed[j]='\0';
        printf("stuffed data: %s\n", stuffed);
}
void main()
{
        char data[50];
        printf("Enter binary data(ex:1011110):");
        scanf("%s", data);
        bitStuffing(data);
}
__________________________________________________________________________________________________________________
						2
Program to implement data link layer framing method checksum.

#include<stdio.h>
#include<math.h>
int sender(int arr[10], int n) {
        int checkSum, sum=0, i;
        printf("\n****SENDER SIDE****\n");
        for(i=0; i<n; i++)
                sum+=arr[i];
        printf("Sum is: %d", sum);
        checkSum=~sum;
        printf("\nCheckSum is: %d", checkSum);
        return checkSum;
}
void receiver(int arr[10], int n, int sch)  {
        int checkSum, sum=0, i;
        printf("\n\n****RECEIVER SIDE****\n");
        for(i=0; i<n; i++)
                sum+=arr[i];
        printf("Sum is:%d", sum);
        sum+=sch;
        checkSum=~sum;
        printf("\nCheckSum is:%d", checkSum);
}
void main() {
        int n, sch, rch;
        printf("\nEnter size of the string:");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the elements of the array to calculate checksum:\n");
        for(int i=0; i<n; i++)
                scanf("%d", &arr[i]);
        sch=sender(arr, n);
        receiver(arr, n, sch);
}
__________________________________________________________________________________________________________________	
						3
Program for Hamming Code generation for error detection and correction.

#include <stdio.h>
int main() {
    int d[10], r[10], p1, p2, p4, p, i;

    printf("Enter 4-bit data: ");
    for (i = 3; i >= 0; i--)
        scanf("%d", &d[i]);

    p1 = d[0] ^ d[1] ^ d[3];
    p2 = d[0] ^ d[2] ^ d[3];
    p4 = d[1] ^ d[2] ^ d[3];

    printf("Transmitted: %d%d%d%d%d%d%d\n", p1, p2, d[0], p4, d[1], d[2], d[3]);

    printf("Enter received: ");
    for (i = 6; i >= 0; i--)
        scanf("%d", &r[i]);

    p1 = r[6] ^ r[4] ^ r[2] ^ r[0];  
    p2 = r[5] ^ r[4] ^ r[1] ^ r[0];  
    p4 = r[3] ^ r[2] ^ r[1] ^ r[0];

    p = p4 * 4 + p2 * 2 + p1;

    if (p) {
        printf("Error at: %d\nCorrected: ", p);
        r[7 - p] ^= 1;  
        for (i = 6; i >= 0; i--)
            printf("%d", r[i]);
    } else
        printf("No error\n");

    return 0;
}
__________________________________________________________________________________________________________________
						4
Program to implement a dataset of characters the three CRC polynomials - CRC 12, CRC 16, CRC CCIP.

#include <stdio.h>
#include <string.h>

unsigned int crc(const char *data)
{
    unsigned int poly = 0x180F;
    unsigned int crc = 0x0005;

    for (i = 0; i < strlen(data); i++)
    {
        unsigned char byte = data[i];

        for (j = 0; j < 8; j++)
        {
            int bit = ((byte >> (7 - j)) & 1) ^ ((crc >> 11) & 1);
            crc <<= 1;
            if (bit)
                crc ^= poly;
            crc &= 0x0FFF;
        }
    }
    return crc;
}

int main()
{
    char data[100];

    printf("Enter a string:");
    scanf("%s", data);

    printf("CRC12 = %03X\n", crc(data));
}

#include <stdio.h>
#include <string.h>

unsigned int crc16(const char *data)
{
    unsigned int poly = 0x8005;
    unsigned int crc  = 0x0000;

    for (i = 0; i < strlen(data); i++)
    {
        unsigned char byte = data[i];

        for (j = 0; j < 8; j++)
        {
            int bit = ((byte >> (7 - j)) & 1) ^ ((crc >> 15) & 1);
            crc <<= 1;
            if (bit)
                crc ^= poly;
            crc &= 0xFFFF;
        }
    }
    return crc;
}

int main()
{
    char data[100];

    printf("Enter a string:");
    scanf("%s", data);

    printf("CRC-16 = %04X\n", crc16(data));
}

#include <stdio.h>
#include <string.h>

unsigned int crc_ccitt(const char *data)
{
    unsigned int poly = 0x1021;   // CRC-CCITT polynomial
    unsigned int crc  = 0xFFFF;   // Initial value

    int i, j;
    for (i = 0; i < strlen(data); i++)
    {
        unsigned char byte = data[i];

        for (j = 0; j < 8; j++)
        {
            int bit = ((byte >> (7 - j)) & 1) ^ ((crc >> 15) & 1);
            crc <<= 1;
            if (bit)
                crc ^= poly;
            crc &= 0xFFFF; // Keep CRC 16-bit
        }
    }
    return crc;
}

int main()
{
    char data[100];

    printf("Enter a string: ");
    scanf("%s", data);

    printf("CRC-CCITT = %04X\n", crc_ccitt(data));
}

__________________________________________________________________________________________________________________
						5
Program to implement Sliding Window protocol for GO back N.

#include<stdio.h>
void main()
{
        int total_frames, window_size;
        int sent = 0, lost_frame, i;
        printf("Enter total number of frsmes to send: ");
        scanf("%d", &total_frames);
        printf("Enter window size: ");
        scanf("%d", &window_size);
        printf("\n--- GO-Back-N Sliding Window Protocol Simulation ---\n\n");
        while(sent < total_frames)
        {
                printf("Sender: Sending frame ");
                for(i = sent; i<sent + window_size && i<total_frames; i++)
                        printf("%d ", i);
                printf("\n");
                printf("Enter the frame number to be lost (or -1 if none lost): ");
                scanf("%d", &lost_frame);
                if(lost_frame >= sent && lost_frame < sent + window_size && lost_frame < total_frames)
                {
                        printf("Receiver: Frame %d lost! Go back and resend from %d\n\n", lost_frame, lost_frame);
                        sent = lost_frame;
                }
                else
                {
                        int ack = sent + window_size;
                        if(ack > total_frames)
                                ack = total_frames;
                        printf("Receriver: Acknowledged up to frame %d\n\n", ack-1);
                        sent = ack;
                }
        }
        printf("All frames sent successfully using Go-Back-N!\n");
}
__________________________________________________________________________________________________________________
						6
Program to implement Sliding Window protocol for Selective Repeat.

#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void main()
{
        int totalFrames,windowSize;
        int frameStatus[MAX];
        int i,choice,resend;
        printf("\n --- Selective Repeat ARQ Simulation ---\n");
        printf("Enter total number of frames to send: ");
        scanf("%d",&totalFrames);
        printf("Enter window size: ");
        scanf("%d",&windowSize);
        for(i=0;i<totalFrames;i++)
                frameStatus[i]=0;
        int sent=0;
        while(sent<totalFrames){
                printf("\n---Sending Window of Frames ---\n");
                for(i=sent; i<sent+windowSize && i<totalFrames; i++){
                        if(frameStatus[i]==0)
                                printf("Frame %d sent.\n",i);
                }
                for(i=sent; i<sent+windowSize && i<totalFrames; i++){
                        if(frameStatus[i]==0){
                                printf("Did frame %d get ACK? (1=yes,0=lost); ",i);
                                scanf("%d",&choice);
                                if(choice==1){
                                        printf("ACK for frame %d received.\n",i);
                                        frameStatus[i]=1;
                                }
                                else
                                        printf("Frame %d lost / not acknowledged.\n",i);
                        }
                }
                printf("\n DO you want to resend any lost frame? (Enter frame number, -1 to stop): ");
                scanf("%d",&resend);
                while(resend!=-1){
                        if(resend>=sent && resend<totalFrames && frameStatus[resend]==0)
                        {
                                printf("Resending frame %d...\n",resend);
                                printf("ACK for frame %d received now.\n",resend);
                                frameStatus[resend]=1;
                        }
                        else
                                printf("Invalid frame number or already ACKed.\n");
                        printf("Enter next frame to resend (-1 to stop): ");
                        scanf("%d",&resend);
                } 
                while(sent<totalFrames && frameStatus[sent]==1)
                        sent++;
        }
        printf("\nAll frames sent and acknowledged successfully!\n");
}
__________________________________________________________________________________________________________________
						7
Program to implement Stop and Wait Protocol.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sender(int totalFrames);
void receiver(int frame);

void main(){
        int totalFrames;
        printf("===Stop-and-Wait Protocol Simulation ===\n");
        printf("Enter total number of frames to send: ");
        scanf("%d",&totalFrames);
        sender(totalFrames);
}
void sender(int totalFrames)
{
        int i,ack,choice;
        srand(time(NULL));
        for(i=1;i<=totalFrames;i++){
                printf("\nSender: Sending Frame %d",i);
                printf("\nReceiver: Do you want to ACK Frame %d? 1=yes, 0=No): ",i);
                scanf("%d",&choice);
                if(choice==1){
                        receiver(i);
                        printf("Sender: ACK %d Received \n",i);
                }
                else{
                        printf("Sender: ACK %d lost. Retransmitting... \n",i);
                        i--;
                }
        }
        printf("\nAll %d frames sent successfully!\n",totalFrames);
}
void receiver(int frame){
        printf("Receiver:Frame %d received. Sending ACK %d...\n",frame,frame);
}
__________________________________________________________________________________________________________________	
						8
Program for Congestion control using leaky bucket algorithm.

#include<stdio.h>
#include<stdlib.h>
void main(){
        int bucketSize,outputRate,n,incoming;
        int stored=0;
        printf("=== Leaky Bucket Algorithm Simulation ===\n");
        printf("Enter bucket capacity (in packets): ");
        scanf("%d",&bucketSize);
        printf("Enter output rate(packets per second): ");
        scanf("%d",&outputRate);
        printf("Enter number of incoming packets (time slots): ");
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
                printf("\nTime %d: Enter number of incoming packets: ",i);
                scanf("%d",&incoming);
                printf("Incoming Packets: %d\n",incoming);
                if(incoming +stored>bucketSize){
                        int dropped=(incoming+stored)-bucketSize;
                        stored=bucketSize;
                        printf("Bucket overflow! Dropped packets: %d\n",dropped);
                }
                else
                        stored=stored+incoming;
                if(stored>outputRate){
                        stored=stored-outputRate;
                        printf("Transmitted: %d | Packets left in bucket:%d\n",outputRate,stored);
                }
                else{
                        printf("Transmitted: %d |Packets left in bucket: 0\n",stored);
                        stored=0;
                }
        }
        while(stored>0){
                if(stored>outputRate){
                        stored=stored-outputRate;
                        printf("\nTransmitted: %d |packets left in bucket :%d\n",outputRate,stored);
                }
                else{
                        printf("Transmitted: %d |packets left in bucket : 0\n",stored);
                        stored=0;
                }
        }
        printf("\nAll packets transmitted successfully!\n");
}
__________________________________________________________________________________________________________________
						9
Program to implement Dijkstra's algorithm to compute the Shortest path through a graph.

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int minDistance(int dist[],bool visited[],int V){
        int min=INT_MAX, min_index=-1;
        for(int i=0;i<V;i++){
                if(!visited[i]&&dist[i]<=min){
                        min=dist[i];
                        min_index=i;
                }
        }
        return min_index;
}
void printPath(int parent[],int j){
        if(parent[j]==-1){
                printf("%d ",j);
                return;
        }
        printPath(parent,parent[j]);
        printf("-> %d ",j);
}
void dijkstra(int graph[20][20],int V,int src){
        int dist[20];
        bool visited[20];
        int parent[20];
        for(int i=0;i< V;i++){
                dist[i]= INT_MAX;
                visited[i]=false;
                parent[i]=-1;
        }
        dist[src]=0;
        for(int count=0;count<V-1;count++){
                int u=minDistance(dist,visited,V);
                visited[u]=true;
                for(int v=0;v<V;v++){
                        if(!visited[v]&&graph[u][v] && dist[u]!=INT_MAX &&dist[u] +graph[u][v] < dist[v]){
                                dist[v]=dist[u]+graph[u][v];
                                parent[v]=u;
                        }
                }
        }
        printf("\nVertex\tDistance\tPath\n");
        for(int i=0;i< V;i++){
                if(dist[i]==INT_MAX)
                        printf("%d\tINF\t\tNo path\n",i);
                else{
                        printf("%d\t%d\t\t",i,dist[i]);
                        printPath(parent,i);
                        printf("\n");
                }
        }
}
void main(){
        int V,src;
        int graph[20][20];
        printf("Enter number of vertices(max 20): ");
        scanf("%d",&V);
        printf("\nEnter the adjacency matrix (use 0 for no edge):\n");
        for(int i=0;i<V;i++){
                for(int j=0;j<V;j++)
                        scanf("%d",&graph[i][j]);
        }
        printf("\nEnter the source vertex (0 to %d): ",V-1);
        scanf("%d",&src);
        dijkstra(graph,V,src);
}
__________________________________________________________________________________________________________________
						10
Program to implement Distance vector routing algorithm by obtaining routing table at each node.

#include<stdio.h>
#define INF 999
#define MAX 20
struct RoutingTable{
        int dist[MAX];
        int nextHop[MAX];
};
void main(){
        int n; int cost[MAX][MAX];
        char nodes[MAX][20];
        struct RoutingTable rt[MAX];
        printf("Enter number of nodes (hosts/roters): ");
        scanf("%d",&n);
        printf("Enter node names (e.g., H1, H2, ...):\n");
        for(int i=0;i<n;i++){
                printf("Node %d: ",i+1);
                scanf("%s",nodes[i]);
        }
        printf("\nEnter adjacency matrix (delay cost, INF=999, 0 for self):\n");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                        scanf("%d",&cost[i][j]);
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        rt[i].dist[j]=cost[i][j];
                        if(cost[i][j]!=INF && i!=j)
                                rt[i].nextHop[j]=j;
                        else
                                rt[i].nextHop[j]=-1;
                }
        }
        int updated;
        do{
                updated=0;
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                for(int k=0;k<n;k++){
                                        if(rt[i].dist[j]> cost[i][k] +rt[k].dist[j]){
                                                rt[i].dist[j]=cost[i][k]+rt[k].dist[j];
                                                updated=1;
                                        }
                                }
                        }
                }
        }while(updated);
        for(int i=0;i<n;i++){
                printf("\nRouting Table for Node %s:\n",nodes[i]);
                printf("Destination\tNextHop\t\tCost\n");
                for(int j=0;j<n;j++){
                        if(i==j) continue;
                        printf("%s\t\t",nodes[j]);
                        if(rt[i].nextHop[j]!=-1)
                                printf("%s\t\t",nodes[rt[i].nextHop[j]]);
                        else
                                printf("-\t\t");
                        if(rt[i].dist[j]==INF)
                                printf("INF\n");
                        else
                                printf("%d\n",rt[i].dist[j]);
                }
        }
}

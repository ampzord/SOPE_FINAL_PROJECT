
typedef struct {
    unsigned int serial_number;
    char gender;
    unsigned int time_spent;
    unsigned int rejected;
} Order;

int readOrder(int fd, Order *ord) {
    int n;
    n = read(fd,ord,sizeof(Order));
    //printf("READORDER : %d\n",n);
    return n > 0;
}

struct timeval tv;

/* Get number of digits of number */
int findn(int num)
{
    char snum[100];
    sprintf(snum, "%d", num);
    return strlen(snum);
}

typedef struct {
    pthread_t pth;
    int idx;
} SeatThread;

typedef struct {
    int idx;
    unsigned int time_ms;
} ThreadArg;

double getCurrentTime() {
    gettimeofday(&tv, NULL);
    double curr_time = (tv.tv_sec) * 1000000 + (tv.tv_usec);
    return curr_time;
}
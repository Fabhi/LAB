void SJFPreemptive(){
    Process* p =Entry();
    int n=0;
    while(p[n].pid!=-1)
        n++;
    //Function to sort based on Burst Time( if process has arrived)
    qsort(p, n, sizeof(Process), comparator);
    int timer=0;
    float TAT=0;
    float WAT=0;
    int done=0;
    while(done!=n){
        int i = min(p,n,timer);
        if(i!=-1){
            WAT+=(timer-p[i].arrival_time);
            printf("%d -> (%d %d)\n", p[i].pid, timer ,timer+p[i].burst_time);
            timer+=p[i].burst_time;
            TAT+=(timer-p[i].arrival_time);
            done++;
            p[i].rem_time=0;
            continue;
        }
        timer++;
    }
    TAT=TAT/n;
    WAT=WAT/n;
    printf("Turnaround Time = %0.2f ms \n", TAT);
    printf("Waiting Time = %0.2f ms\n\n\n", WAT);
}
// Write a program to print current time periodically (Hint:- alarm, time, ctime)

#include  <sys/types.h>
   #include  <sys/timers.h>
   #include  <pthread.h>
   #include  <stdlib.h>

   #define THREADSCOUNT 3
   #define TOTALRUN   16
   #define TMIN 1.0
   #define TMAX 3.0
   #define TIMLEN 60

   int shrd;
   struct state {
     pthread_t t;          /* A thread */
     int who;              /* It identifies a thread */
     int seed;             /* The seed used for random number generator*/
     int val;              /* Value returned by random number generator */
     char buffer[TIMLEN];  /* String represnting current time */
   } states[THREADSCOUNT];

   void moo(struct state *s);

   int main(void)
   {
      int    i;
      struct timespec maintime;

      /* Initialize states */
      states[0].seed = 1507; states[1].seed = 1511; states[2].seed = 1577;
      for (i=0; i<THREADSCOUNT; i++) {
        states[i].who = i;
        if (pthread_create(&(states[i].t), pthread_attr_default, 
	                   (void *)moo, &(states[i])) != 0){
	     perror("pthread_create");
	     exit(1);}}
      /* Wait a while then exit: all existing threads will die */
      maintime.tv_sec = TOTALRUN;
      maintime.tv_nsec =0;
      pthread_delay_np(&maintime);
    }

   void getTime(struct timespec *ts, char buffer[], int len)
   /* It places the current time in ts and puts in buffer (of length len) */
   /* as a string the current time as a string */
   {
     getclock((timer_t)TIMEOFDAY, ts);
     ctime_r(&(ts->tv_sec), buffer, len);
     sprintf(&buffer[24], " and %d microseconds", (ts->tv_nsec)/1000);
   }

   void moo(struct state *s) {
     /* We assume that a thread sleeps in each loop, from a minimum of */
     /* TMIN to a maximum of TMAX, at random.                          */

     struct timespec tspec;
     struct timespec interval;
     float r;          /* random number in interval 0.0 .. 1.0 */

     while (1){
         getTime(&tspec, s->buffer, TIMLEN);
         rand_r(&(s->seed), &(s->val));
         r = (s->val)/((float)RAND_MAX); 
         shrd = s->who;
         printf("Thread %d with shrd = %d sleeps %f at time %s\n", s->who,
	        shrd, TMIN+(r*(TMAX-TMIN)), s->buffer);
         /* sleep for an a time between TMIN and TMAX */
         interval.tv_sec = TMIN + (int)(r*(TMAX-TMIN));
         interval.tv_nsec = (int)(r*1000000000);
         pthread_delay_np(&interval);
         getTime(&tspec, s->buffer, TIMLEN);
         printf("Thread %d with shrd = %d after sleep at time %s\n", 
		s->who, shrd, s->buffer);}
   }
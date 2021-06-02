#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int n)
	{
	double pro=1.00;
	int counter=0;
	for(int i=1;i<=n;i++)
		{if(n==2999){
		double q=(double)4*i*i;
		//printf("%d\t%f\t\t%.10f\n",i,q-1,q/(q-1));
		}
		pro*=((double)(4*i*i))/((4*i*i)-1);
		counter++;
		//printf("**%d \t%.20f**\t%i\n",i,(float)4*i*i/((4*i*i)-1),4*i*i);
		}printf("%d   %d  %.20f\n------------------\n",counter,n,pro*2);
	return 2*pro;
	}
int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    //printf("%f",pi);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}


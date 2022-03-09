#include <iostream>
using namespace std;

struct  process
{
	int cake_no;
	int arrival_time;
	int prep_time;
	int start_time;
	int completion_time;
	int delivery_time;
};

int main() {
	int T, n;
    cin>>T;
    while(T--){
        cin>>n;
        struct process P[n];
	    int is_complete[n],time=0;
	    int no_p_done=0,max_waiting_time=0;

        for(int i=0; i<n; i++)
            cin>>P[i].arrival_time;
        for(int i=0; i<n; i++) {
            cin>>P[i].prep_time;
            is_complete[i]=0;
        }

        while(no_p_done != n)
        {
            int id_choosen = -1;
            int min = 10000000;
            for(int i=0; i<n; i++)
            {
                if(P[i].arrival_time <= time && is_complete[i]==0)
                {
                    if(P[i].prep_time<min)
                    {
                        min = P[i].prep_time;
                        id_choosen= i;
                    }
                    else if(P[i].prep_time == min)
                    {
                        if(P[i].arrival_time < P[id_choosen].arrival_time)
                        {
                            min = P[i].prep_time;
                            id_choosen= i;
                        }
                    }
                }
            }
            if(id_choosen!=-1)
            {
                P[id_choosen].start_time = time;
                P[id_choosen].completion_time = P[id_choosen].start_time + P[id_choosen].prep_time;
                P[id_choosen].delivery_time = P[id_choosen].completion_time - P[id_choosen].arrival_time;
                time = P[id_choosen].completion_time;
                
                is_complete[id_choosen]=1;
                no_p_done++;
            }
            else
                time++;
	    }
        for(int i = 1;i < n; ++i)
        {
            if(P[0].delivery_time < P[i].delivery_time) {
               P[0].delivery_time = P[i].delivery_time;
            }
        }
        cout<<P[0].delivery_time<<endl;
    }
}
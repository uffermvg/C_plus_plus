#include <iostream>
# include <vector>
using namespace std;

int randomSample(int bound){
    int N;
    N = rand() % (bound + 1);
    return N;
}

int Sum (vector<int> count, int samplesize){
    int sum = 0;
    for(int i = 0 ; i < samplesize; i++ ){
        sum = count.at(i) + sum;
    }
    return sum;
}
int Mean(vector<int> count, int samplesize){
    int mean;
    mean = Sum(count, samplesize) / samplesize;
    return mean;
}
int Maximum(vector<int> count, int bound){
    int max = 0;
    for(int i = 0; i < bound; i++){
        if (count.at(i) > max){
            max = count.at(i);
        }
    }
    return max;
}
int Minimum(vector<int> count, int bound){
    int min = 9999;
    for(int i = 0; i < bound; i++){
        if(count.at(i) < min){
           min = count.at(i);
        }
    }
    return min;
}

int main()
{
    int bound;
    int samplesize;

    cout << "Enter End Range: "<<endl;
    cin >> bound;
    cout << "Enter number of Samples: "<<endl;
    if (bound > 100){
        bound = 100;
    }


    cin >> samplesize;
    if (samplesize < 10000){
        samplesize = 10000;
    }
    cout <<endl;
    vector<int> count;
    count.resize(bound + 1);
    int rand, m;

    int max, scale;

    for (int i = 0; i < samplesize; i++){
        rand = randomSample(bound);
        for (int i = 0; i <= bound; i++){
            if(rand == i)
                count.at(i) = 1 + count.at(i);
        }
    }
    max = Maximum(count,bound);
    scale = (max / 60);
    cout << "Index"<< "     "<< "Value Bar"<<endl;
    for(int i = 0; i <= bound; i++){
        if (i > 99){
            cout << i << "    "<<count.at(i)<<" ";
        }
        else if(i > 9){
            cout << i << "     "<<count.at(i)<<" ";
        }
        else{
            cout << i << "      "<<count.at(i)<<" ";
        }
        m = count.at(i) / scale;
        for(int i= 0; i < m; i++){
            cout << "*";
        }
        cout << endl;
    }
    cout << "Scale: "<<scale << " per *"<<endl<< endl;
    cout << "Range: 0 to "<<bound <<endl;
    cout << "Sample Count: "<<samplesize<<endl;
    cout << "Min value: "<<Minimum(count,bound)<<endl;
    cout << "Max value: "<<max<<endl;
    cout << "Sum value: "<<Sum(count,bound)<<endl;
    cout << "Mean value: "<<Mean(count, bound)<<endl<<endl;



    return 0;
}

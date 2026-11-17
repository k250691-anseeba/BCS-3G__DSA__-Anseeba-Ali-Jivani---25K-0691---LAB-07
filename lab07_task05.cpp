
#include <iostream>

using namespace std;

int N;
int swaps = 0;
int skipped = 0;

void printArray(int arr[]){
    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(i <= j){

        while(i <= high && arr[i] > pivot){
            i++;
        }

        while(j > low && arr[j] <= pivot){
            j--;
        }

        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            swaps++;

            i++;
            j--;
        }
    }

    if(low != j){
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        swaps++;
    }

    cout<<endl<<"Array after placing reference student: ";
    printArray(arr);

    cout<<"Final position: "<<j + 1<<endl;

    return j;
}

void quickSelect(int arr[], int low, int high, int K){
    if(low > high){
        return;
    }

    if(low >= K){
        skipped++;
        return;
    }

    int pos = partition(arr, low, high);

    if(pos + 1 < K){
        if(pos > low){
            skipped++;
        }

        quickSelect(arr, pos + 1, high, K);
    }
    else if(pos + 1 > K){
        if(pos < high){
            skipped++;
        }

        quickSelect(arr, low, pos - 1, K);
    }
}


int main(){
    int K;

    cout<<"Enter number of students: ";
    cin>>N;

    if(N <= 0 || N > 100){
        cout<<"Invalid number of students!"<<endl;
        return 0;
    }

    int arr[100];

    cout<<"Enter students marks: "<<endl;

    for(int i = 0; i < N; i++){
        cin>>arr[i];

        if(arr[i] < 0 || arr[i] > 100){
            cout<<"Invalid marks!"<<endl;
            return 0;
        }
    }

    cout<<"Enter K: ";
    cin>>K;

    if(K < 1 || K > N){
        cout<<"Invalid value of K!"<<endl;
        return 0;
    }

    quickSelect(arr, 0, N - 1, K);

    cout<<"\nTop "<<K<<" Marks: ";

    for(int i = 0; i < K; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Total Swaps: "<<swaps<<endl;

    cout<<"Groups Skipped: "<<skipped<<endl;

    return 0;
}

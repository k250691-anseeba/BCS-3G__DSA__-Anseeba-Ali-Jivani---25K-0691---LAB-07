
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
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;

            if(i != j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swaps++;
            }
        }
    }

    if(i + 1 != high){
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        swaps++;
    }

    int pos = i + 1;

    cout<<"\nArray after placing reference parcel: ";
    printArray(arr);

    cout<<"Final position: "<<pos + 1<<endl;

    return pos;
}

int quickSelect(int arr[], int low, int high, int K){
    if(low > high){
        return -1;
    }

    int pos = partition(arr, low, high);
    
if(pos == K - 1){
    if(pos < high){
        skipped++;
    }

    return arr[pos];
}

    if(pos > K - 1){
        if(pos < high){
            skipped++;
        }

        return quickSelect(arr, low, pos - 1, K);
    }
    else{
        if(pos > low){
            skipped++;
        }

        return quickSelect(arr, pos + 1, high, K);
    }
}

int main(){
    int K;

    cout<<"Enter number of parcels: ";
    cin>>N;

    if(N <= 0 || N > 100){
        cout<<"Invalid number of parcels!"<<endl;
        return 0;
    }

    int arr[100];

    cout<<"Enter parcel weights: "<<endl;

    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    cout<<"Enter K: ";
    cin>>K;

    if(K < 1 || K > N){
        cout<<"Invalid value of K!"<<endl;
        return 0;
    }

    int answer = quickSelect(arr, 0, N - 1, K);

    cout<<"\nK-th Lightest Parcel: "<<answer<<endl;

    cout<<"Total Swaps: "<<swaps<<endl;

    cout<<"Groups Skipped: "<<skipped<<endl;

    return 0;
}

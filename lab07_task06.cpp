#include <iostream>
using namespace std;

int getMax(int arr[], int N){
    int max = arr[0];

    for(int i = 1; i < N; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

void radixSort(int arr[], int N){
    int output[100];
    int max = getMax(arr, N);

    for(int exp = 1; max / exp > 0; exp *= 10){

        int tray[10][100];
        int count[10] = {0};

        for(int i = 0; i < N; i++){
            int digit = (arr[i] / exp) % 10;

            tray[digit][count[digit]] = arr[i];
            count[digit]++;
        }

        cout<<"\nTrays after round ("<<exp<<"):\n";

        for(int i = 9; i >= 0; i--){
            cout<<"Tray "<<i<<": ";

            for(int j = 0; j < count[i]; j++){
                cout<<tray[i][j]<<" ";
            }

            cout<<endl;
        }

        int index = 0;

        for(int i = 9; i >= 0; i--){
            for(int j = 0; j < count[i]; j++){
                output[index] = tray[i][j];
                index++;
            }
        }

        for(int i = 0; i < N; i++){
            arr[i] = output[i];
        }

        cout<<"Array after round: ";

        for(int i = 0; i < N; i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }
}

int main(){
    int N;

    cout<<"Enter number of tickets: ";
    cin>>N;

    if(N <= 0 || N > 100){
        cout<<"Invalid number of tickets!"<<endl;
        return 0;
    }

    int arr[100];

    cout<<"Enter ticket numbers: "<<endl;

    for(int i = 0; i < N; i++){
        cin>>arr[i];

        if(arr[i] < 100 || arr[i] > 999999){
            cout<<"Invalid ticket number!"<<endl;
            return 0;
        }
    }

    radixSort(arr, N);

    cout<<"\nFinal sorted list: ";

    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<endl;
    cout<<"Duplicate ticket numbers: ";

    bool found = false;

    for(int i = 0; i < N; i++){
        if(i > 0 && arr[i] == arr[i - 1]){
            if(i == 1 || arr[i] != arr[i - 2]){
                cout<<arr[i]<<" ";
                found = true;
            }
        }
    }

    if(!found){
        cout<<"None";
    }

    cout<<endl;

    return 0;
}

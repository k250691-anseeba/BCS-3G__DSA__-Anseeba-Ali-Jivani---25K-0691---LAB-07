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

        int box[10][100];
        int count[10] = {0};

        for(int i = 0; i < N; i++){
            int digit = (arr[i] / exp) % 10;

            box[digit][count[digit]] = arr[i];
            count[digit]++;
        }

        cout<<"\nBoxes after round ("<<exp<<"):\n";

        for(int i = 0; i < 10; i++){
            cout<<"Box "<<i<<": ";

            for(int j = 0; j < count[i]; j++){
                cout<<box[i][j]<<" ";
            }

            cout<<endl;
        }

        int index = 0;

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < count[i]; j++){
                output[index] = box[i][j];
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

    cout<<"Enter number of codes: ";
    cin>>N;

    if(N <= 0 || N > 100){
        cout<<"Invalid number of codes!"<<endl;
        return 0;
    }

    int arr[100];

    cout<<"Enter tracking codes: "<<endl;

    for(int i = 0; i < N; i++){
        cin>>arr[i];

        if(arr[i] <= 0 || arr[i] > 99999){
            cout<<"Invalid tracking code!"<<endl;
            return 0;
        }
    }

    radixSort(arr, N);

    cout<<"\nFinal sorted list: ";

    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n\nDuplicate codes: ";

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

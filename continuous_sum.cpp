#include <iostream>
#include <sys/time.h>
#include <math.h>
using namespace std;

void continous_sum(int n)
{
    int left, right;
    left = 1;
    right = 2;
    int middle = n/2;
    int sum = left + right;
    while (left <= middle) {
        if (sum == n) {
            //for (int i = left; i <= right; i++) {
                //cout << i <<' ';
            //}
            cout << left << "--" << right;
            cout << endl;
        }
        while (sum > n) {
            sum -= left;
            left++;
            if (sum == n) {
                //for (int i = left; i <= right; i++) {
                    //cout << i << ' ';
                //}
                cout << left << "--" << right;
                cout << endl;
            }
        }
        right++;
        sum += right;
    }
}

void continous_sum2(int n)
{
    int max = (int)sqrt(2*n);
    //cout << max << endl;
    int left, right;
    for (int i = 2; i <= max+1; i++) {
        if ((n<<1) % i == 0) {
            int temp = 2*n/i - i + 1;
            if (temp > 0 && (temp & 1) == 0) {
                left = temp / 2;
                right = left + i - 1;
                cout << left << "--" << right << endl;
            }
        }
    }
    
}

int main(int argc, char *argv[])
{
    struct timeval start, end;
    int n;
    while (cin >> n) {
        gettimeofday(&start, NULL);
        continous_sum2(n);
        gettimeofday(&end, NULL);
        int interval = 1000000*(end.tv_sec - start.tv_sec) + 
            (end.tv_usec - start.tv_usec);
        cout << (float)interval/1000000 << "s"<< endl;
    }

    return 0;
}

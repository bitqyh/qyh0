#include <iostream>
#include <vector>
#include <random>

using namespace std;
typedef vector<vector<int>> Matrix;// �������

// �������������
vector<int> generateRandomVector(int size) {
    vector<int> vec(size);
    random_device rd;//׼���
    mt19937 gen(rd());//����Ϊrd
    uniform_int_distribution<int> dis(0, 1);//�趨��Χ0��1
    for (int i = 0; i < size; i++) {
        vec[i] = (dis(gen) == 0) ? -1 : 1;
    }
    return vec;
}

// �жϾ����ʽ�Ƿ����
bool checkMatrixEquality(const Matrix& A, const Matrix& B, const Matrix& C) {
    int n1 = A.size();
    int n2 = B.size();
    int n3 = B[0].size();

    for (int k = 0; k < 100; k++) {
        vector<int> x = generateRandomVector(n2);
        vector<int> ABx(n1, 0);
        vector<int> Cx(n1, 0);

        vector<int> Bx(n2);
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < n2; j++) {
                Bx[i] += B[i][j] * x[j];
            }
        }
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                ABx[i] += A[i][j] * Bx[j];
            }
        }
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n3; j++) {
                Cx[i] += C[i][j] * x[j];
            }
        }

        // ��� ABx �� Cx �Ƿ����
        for (int i = 0; i < n1; i++) {
            if (ABx[i] != Cx[i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    Matrix A(n1, vector<int>(n2));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            cin >> A[i][j];
        }
    }

    Matrix B(n2, vector<int>(n3));
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n3; j++) {
            cin >> B[i][j];
        }
    }

    Matrix C(n1, vector<int>(n3));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n3; j++) {
            cin >> C[i][j];
        }
    }

    
    if (checkMatrixEquality(A, B, C)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
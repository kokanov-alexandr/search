int Binary_Search(vector<int>& a, int x, int i, int j) {
    int r = i, l = j;
    while (r < l) {
        if (i >= j) return -1;
        int m = i + (j - i) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) l = m;
        else r = m + 1;
    }
}

int Binary_SearchR(vector<int>& a, int x, int i, int j) {
    if (i >= j) return -1;
    int m = i + (j - i) / 2;
    if (a[m] == x) return m;
    if (a[m] < x) return Binary_SearchR(a, x, m + 1, j);
    else return Binary_SearchR(a, x, i, m);
}

int InterpolSearch(vector<int> &MyArray, int WhatFind) {
    int L = 0, R = MyArray.size() - 1, x = 0; //Текущая позиция массива, с которым сравнивается искомое;


    while ((MyArray[L] < WhatFind) && (MyArray[R] > WhatFind)) {
        x = L + ((WhatFind - MyArray[L]) * (R - L)) / (MyArray[R] - MyArray[L]);
        if (MyArray[x] < WhatFind)
            L = x + 1;
        else if (MyArray[x] > WhatFind)
            R = x - 1;
        else
            break;
    }

    if (MyArray[L] == WhatFind)
        return L;
    else if (MyArray[R] == WhatFind)
        return R;
    else
        return -1;


}
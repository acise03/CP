#include <bits/stdc++.h>
using namespace std;
#define int long long
int XR, YR, XJ, YJ;
int n;

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> XR >> YR >> XJ >> YJ;

    cin >> n;
    if (XR == XJ) {
        int countt = 0;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            int prevX, prevY;
            int nextX, nextY;
            cin >> nextX >> nextY;
            bool add = false;
            for (int j = 1; j < c; j++) {
                prevX = nextX;
                prevY = nextY;
                cin >> nextX >> nextY;
                if (nextX - prevX == 0) {
                    if (nextX != XJ) {
                        continue;
                    } else {
                        if ((nextY >= YJ && nextY <= YR) || (nextY <= YJ && nextY >= YR)) {
                            add = true;
                        }
                        if ((prevY >= YJ && prevY <= YR) || (prevY <= YJ && prevY >= YR)) {
                            add = true;
                        }
                    }
                } else {
                    double m2 = (nextY - prevY) / (nextX - prevX);
                    double b2 = nextY - ((nextY - prevY) * nextX / (nextX - prevX));
                    double YV = m2 * XJ + b2;

                    if ((YV <= max(nextY, prevY) && YV >= min(nextY, prevY) &&
                         XR >= min(nextX, prevX) && XR <= max(nextX, prevX)) && (
                            YV <= max(YJ, YR) && YV >= min(YJ, YR) &&
                            XR >= min(XJ, XR) && XR <= max(XJ, XR))) {
                        add = true;
                    }
                }
            }
            if (add) {
                countt++;
            }
        }
        cout << countt << "\n";
    } else {
        int countt = 0;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            int prevX, prevY;
            int nextX, nextY;
            cin >> nextX >> nextY;
            bool add = false;
            for (int j = 1; j < c; j++) {
                prevX = nextX;
                prevY = nextY;
                cin >> nextX >> nextY;
                if (nextX - prevX == 0) {
                    double YV = (YR - YJ) / (XR - XJ) * nextX + (YR - (YR - YJ) * XR / (XR - XJ));
                    if ((YV <= nextY && YV >= prevY) || (YV >= nextY && YV <= prevY)) {
                        if ((YV <= YR && YV >= YJ) || (YV >= YR && YV <= YJ)) {
                            add = true;
                        }
                    }
                } else {
                    double m1 = (YR - YJ) / (XR - XJ);
                    double m2 = (nextY - prevY) / (nextX - prevX);
                    double b1 = (YR - (YR - YJ) * XR / (XR - XJ));
                    double b2 = nextY - ((nextY - prevY) * nextX / (nextX - prevX));
                    double XV = (b2 - b1) / (m1 - m2);
                    double YV = m1 * (XV) + b1;

                    if (m1 == m2) {
                        bool a = min(XJ, XR) <= nextX && max(XJ, XR) >= nextX;
                        bool b = (min(XJ, XR) <= prevX && max(XJ, XR) >= prevX);
                        if (b1 == b2 && (a || b)) {
                            add = true;
                        } else {
                            continue;
                        }
                    } else {
                        bool x1 = XV >= min(nextX, prevX) && XV <= max(nextX, prevX);
                        bool y1 = YV >= min(nextY, prevY) && YV <= max(nextY, prevY);
                        bool x2 = XV <= max(XJ, XR) && XV >= min(XJ, XR);
                        bool y2 = YV <= max(YJ, YR) && YV >= min(YJ, YR);
                        if (x1 && y1 && x2 && y2) {
                            add = true;
                            break;
                        }
                    }
                }
            }
            if (add) {
                countt++;
            }
        }
        cout << countt << "\n";
    }
}

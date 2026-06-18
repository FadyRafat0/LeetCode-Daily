class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 360 / 60 = 6
        // minutes * 6
        // hour

        double a = (hour + (minutes / 60.0)) * (360.0 / 12);
        double b = minutes * (360.0 / 60);
        return min(abs(a - b), 360 - max(a, b) + min(a, b));
    }
};